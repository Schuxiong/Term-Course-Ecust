# Git Batch Push Script - Solve GitHub 2GB Push Limit
# Reference: https://blog.axiaoxin.com/post/git-batch-push/

param(
    [string]$Remote = "origin",
    [string]$Branch = "main",
    [int]$BatchSize = 50,
    [switch]$DryRun,
    [switch]$Force
)

# Color output function
function Write-ColorOutput {
    param([string]$Message, [string]$Color = "White")
    Write-Host $Message -ForegroundColor $Color
}

# Check if in git repository
if (-not (Test-Path ".git")) {
    Write-ColorOutput "Error: Current directory is not a Git repository!" "Red"
    exit 1
}

Write-ColorOutput "=== Git Batch Push Script ===" "Cyan"
Write-ColorOutput "Remote: $Remote" "Yellow"
Write-ColorOutput "Branch: $Branch" "Yellow"
Write-ColorOutput "Batch Size: $BatchSize commits" "Yellow"

# Check if remote branch exists
try {
    git ls-remote --heads $Remote $Branch | Out-Null
    if ($LASTEXITCODE -ne 0) {
        Write-ColorOutput "Warning: Remote branch $Remote/$Branch does not exist, will create new branch" "Yellow"
    }
} catch {
    Write-ColorOutput "Warning: Cannot check remote branch status" "Yellow"
}

# Get unpushed commits
try {
    $unpushedCommits = git log --oneline $Remote/$Branch..HEAD 2>$null
    if ($LASTEXITCODE -ne 0) {
        # If remote branch doesn't exist, get all local commits
        $unpushedCommits = git log --oneline HEAD
    }
} catch {
    $unpushedCommits = git log --oneline HEAD
}

$totalCommits = ($unpushedCommits | Measure-Object).Count

if ($totalCommits -eq 0) {
    Write-ColorOutput "No commits to push" "Green"
    exit 0
}

Write-ColorOutput "Found $totalCommits unpushed commits" "Green"

if ($DryRun) {
    Write-ColorOutput "[DRY RUN] Will push in $([Math]::Ceiling($totalCommits / $BatchSize)) batches" "Magenta"
    exit 0
}

# Confirm push
if (-not $Force) {
    $confirmation = Read-Host "Continue with batch push? (y/N)"
    if ($confirmation -ne 'y' -and $confirmation -ne 'Y') {
        Write-ColorOutput "Operation cancelled" "Yellow"
        exit 0
    }
}

# Get all unpushed commit hashes (in chronological order)
$commitHashes = git log --reverse --format=%H $Remote/$Branch..HEAD 2>$null
if ($LASTEXITCODE -ne 0) {
    $commitHashes = git log --reverse --format=%H HEAD
}

$batchCount = [Math]::Ceiling($totalCommits / $BatchSize)
Write-ColorOutput "Starting batch push, total $batchCount batches..." "Cyan"

# Batch push
$currentBatch = 1
$processedCommits = 0

for ($i = 0; $i -lt $totalCommits; $i += $BatchSize) {
    $endIndex = [Math]::Min($i + $BatchSize - 1, $totalCommits - 1)
    $targetCommit = ($commitHashes)[$endIndex]
    
    Write-ColorOutput "" "White"
    Write-ColorOutput "[Batch $currentBatch/$batchCount] Pushing to commit: $($targetCommit.Substring(0,8))..." "Yellow"
    
    try {
        # Push to specific commit
        git push $Remote $targetCommit:refs/heads/$Branch --force-with-lease
        
        if ($LASTEXITCODE -eq 0) {
            $processedCommits = $endIndex + 1
            $progress = [Math]::Round(($processedCommits / $totalCommits) * 100, 1)
            Write-ColorOutput "Batch $currentBatch push successful (Progress: $progress%)" "Green"
        } else {
            Write-ColorOutput "Batch $currentBatch push failed" "Red"
            break
        }
    } catch {
        Write-ColorOutput "Error during push: $($_.Exception.Message)" "Red"
        break
    }
    
    $currentBatch++
    
    # Brief delay to avoid frequent requests
    Start-Sleep -Seconds 1
}

# Final push HEAD to ensure complete sync
if ($processedCommits -eq $totalCommits) {
    Write-ColorOutput "" "White"
    Write-ColorOutput "Final sync push..." "Cyan"
    try {
        git push $Remote "HEAD:${Branch}"
        if ($LASTEXITCODE -eq 0) {
            Write-ColorOutput "" "White"
            Write-ColorOutput "All batch push completed!" "Green"
            Write-ColorOutput "Total pushed $totalCommits commits" "Green"
        } else {
            Write-ColorOutput "" "White"
            Write-ColorOutput "Final push failed, but most commits were successfully pushed" "Yellow"
        }
    } catch {
        Write-ColorOutput "" "White"
        Write-ColorOutput "Final push error: $($_.Exception.Message)" "Yellow"
    }
} else {
    Write-ColorOutput "" "White"
    Write-ColorOutput "Push not fully completed, pushed $processedCommits/$totalCommits commits" "Yellow"
}

Write-ColorOutput "" "White"
Write-ColorOutput "Usage:" "Cyan"
Write-ColorOutput "  -Remote <name>    Specify remote repository name (default: origin)" "Gray"
Write-ColorOutput "  -Branch <name>    Specify target branch (default: main)" "Gray"
Write-ColorOutput "  -BatchSize <num>  Number of commits per batch (default: 50)" "Gray"
Write-ColorOutput "  -DryRun           Simulate run without actual push" "Gray"
Write-ColorOutput "  -Force            Skip confirmation prompt" "Gray"