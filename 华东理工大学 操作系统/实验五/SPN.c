#include <stdio.h>
#include <limits.h>

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

// SPN调度算法
void spn(struct ProcessControlBlock processes[], int numProcesses) {
    int currentTime = 0;

    // 遍历所有进程
    for (int i = 0; i < numProcesses; i++) {
        // 查找下一个到达时间小于等于当前时间的进程
        int shortestProcessIndex = -1;
        int shortestBurstTime = INT_MAX;

        for (int j = 0; j < numProcesses; j++) {
            if (processes[j].status == WAIT && processes[j].arrivalTime <= currentTime) {
                if (processes[j].burstTime < shortestBurstTime) {
                    shortestBurstTime = processes[j].burstTime;
                    shortestProcessIndex = j;
                }
            }
        }

        // 如果找到符合条件的进程
        if (shortestProcessIndex != -1) {
            // 设置进程状态为运行
            processes[shortestProcessIndex].status = RUN;

            // 执行进程
            while (processes[shortestProcessIndex].executedTime < processes[shortestProcessIndex].burstTime) {
                processes[shortestProcessIndex].executedTime++;
                currentTime++;
            }

            // 设置进程状态为完成
            processes[shortestProcessIndex].status = FINISH;

            // 计算周转时间和带权周转时间
            calculateTurnaroundTime(&processes[shortestProcessIndex], currentTime);
        } else {
            // 如果没有符合条件的进程，当前时间加一
            currentTime++;
        }
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

    // 使用SPN算法调度进程
    spn(processes, numProcesses);

    // 打印进程信息
    printProcesses(processes, numProcesses);

    return 0;
}
