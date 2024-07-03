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
    int remainingBurstTime;  // 剩余需要运行的时间
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

// RR调度算法
void rr(struct ProcessControlBlock processes[], int numProcesses, int timeQuantum) {
    int currentTime = 0;
    int remainingProcesses = numProcesses;

    // 遍历所有进程
    while (remainingProcesses > 0) {
        for (int i = 0; i < numProcesses; i++) {
            // 跳过已完成的进程
            if (processes[i].status == FINISH) {
                continue;
            }

            // 设置进程状态为运行
            processes[i].status = RUN;

            // 执行进程
            int timeSlice = processes[i].remainingBurstTime < timeQuantum
                                ? processes[i].remainingBurstTime
                                : timeQuantum;

            for (int j = 0; j < timeSlice; j++) {
                processes[i].executedTime++;
                currentTime++;
                processes[i].remainingBurstTime--;
            }

            // 设置进程状态为就绪或完成
            if (processes[i].remainingBurstTime == 0) {
                processes[i].status = FINISH;

                // 计算周转时间和带权周转时间
                calculateTurnaroundTime(&processes[i], currentTime);

                remainingProcesses--;
            } else {
                processes[i].status = WAIT;
            }
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
    // 假设有三个进程，时间片为2
    struct ProcessControlBlock processes[] = {
        {'A', 0, 8, 8, 0, 0, WAIT},
        {'B', 1, 6, 6, 0, 0, WAIT},
        {'C', 2, 4, 4, 0, 0, WAIT}
    };

    int numProcesses = sizeof(processes) / sizeof(processes[0]);
    int timeQuantum = 2;

    // 使用RR算法调度进程
    rr(processes, numProcesses, timeQuantum);

    // 打印进程信息
    printProcesses(processes, numProcesses);

    return 0;
}
