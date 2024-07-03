#include <stdio.h>

// 进程状态枚举
enum ProcessStatus {
    WAIT,
    RUN,
    FINISH
};

// 进程控制块结构体
struct ProcessControlBlock {
    char name;               // 进程名
    int arrivalTime;         // 到达时间
    int burstTime;           // 需要运行的时间
    int executedTime;        // 已用CPU时间
    int turnaroundTime;      // 周转时间
    float weightedTurnaround; // 带权周转时间
    enum ProcessStatus status; // 进程状态
};

// 计算进程的周转时间和带权周转时间
void calculateTurnaroundTime(struct ProcessControlBlock *process, int completionTime) {
    process->turnaroundTime = completionTime - process->arrivalTime;
    process->weightedTurnaround = (float) process->turnaroundTime / process->burstTime;
}

// FCFS调度算法
void fcfs(struct ProcessControlBlock processes[], int numProcesses) {
    int currentTime = 0;

    // 遍历所有进程
    for (int i = 0; i < numProcesses; i++) {
        // 进程到达前空闲时间
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }

        // 设置进程状态为运行
        processes[i].status = RUN;

        // 执行进程
        while (processes[i].executedTime < processes[i].burstTime) {
            processes[i].executedTime++;
            currentTime++;
        }

        // 设置进程状态为完成
        processes[i].status = FINISH;

        // 计算周转时间和带权周转时间
        calculateTurnaroundTime(&processes[i], currentTime);
    }
}

// 打印进程信息
void printProcesses(struct ProcessControlBlock processes[], int numProcesses) {
    printf("进程\t到达时间\t完成时间\t周转时间\t带权周转时间\n");

    for (int i = 0; i < numProcesses; i++) {
        printf("%c\t%d\t\t%d\t\t%d\t\t%.2f\n", processes[i].name, processes[i].arrivalTime,
               processes[i].arrivalTime + processes[i].turnaroundTime,
               processes[i].turnaroundTime, processes[i].weightedTurnaround);
    }
}

int main() {
    // 假设有三个进程
    struct ProcessControlBlock processes[] = {
        {'A', 0, 5, 0, 0, 0, WAIT},
        {'B', 2, 4, 0, 0, 0, WAIT},
        {'C', 4, 3, 0, 0, 0, WAIT}
    };

    int numProcesses = sizeof(processes) / sizeof(processes[0]);

    // 使用FCFS算法调度进程
    fcfs(processes, numProcesses);

    // 打印进程信息
    printProcesses(processes, numProcesses);

    return 0;
}
