#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FRAMES 32 // 最大页面帧数
#define INSTRUCTION_COUNT 320 // 指令总数
#define PAGE_SIZE 10 // 页面大小
#define MAX_PAGES 32 // 最大页数

// 页面结构体，包含页面号和其他可能需要的信息
typedef struct {
    int page;
    // 可以根据需要添加其他信息，比如使用次数等
} PageEntry;

// 初始化页面队列
void initializeQueue(PageEntry queue[], int frames) {
    for (int i = 0; i < frames; ++i) {
        queue[i].page = -1; // -1表示页面帧为空
        // 可以根据需要初始化其他信息
    }
}

// 检查页面是否在页面队列中
int isPageInMemory(int page, PageEntry queue[], int frames) {
    for (int i = 0; i < frames; ++i) {
        if (queue[i].page == page) {
            return 1; // 页面命中
        }
    }
    return 0; // 页面未命中
}

// 生成指令序列
void generateInstructions(int instructions[]) {
    // 50%的指令是顺序执行的
    int start = rand() % (INSTRUCTION_COUNT / 2);
    for (int i = 0; i < INSTRUCTION_COUNT / 2; ++i) {
        instructions[i] = (start + i) % INSTRUCTION_COUNT;
    }

    // 25%的指令均匀分布在前地址部分
    for (int i = INSTRUCTION_COUNT / 2; i < INSTRUCTION_COUNT * 3 / 4; ++i) {
        instructions[i] = rand() % (start + 1);
    }

    // 25%的指令均匀分布在后地址部分
    for (int i = INSTRUCTION_COUNT * 3 / 4; i < INSTRUCTION_COUNT; ++i) {
        instructions[i] = rand() % (INSTRUCTION_COUNT - start - 1) + start + 1;
    }

    // 打乱指令序列
    for (int i = INSTRUCTION_COUNT - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        int temp = instructions[i];
        instructions[i] = instructions[j];
        instructions[j] = temp;
    }
}

// 执行指令序列并计算页面命中率
float executeAndCalculateHitRate(int instructions[], int n, int frames, int (*pageReplacementAlgorithm)(int[], int, int)) {
    PageEntry queue[MAX_FRAMES];
    initializeQueue(queue, frames);

    int pageFaults = 0;

    for (int i = 0; i < n; ++i) {
        int page = instructions[i] / PAGE_SIZE;

        if (!isPageInMemory(page, queue, frames)) {
            // 页面未命中，进行页面置换
            int replacedPage = queue[0].page;
            pageReplacementAlgorithm(queue, frames, page);

            ++pageFaults;
        } else {
            // 页面命中
        }
    }

    return 1 - ((float)pageFaults / n);
}

// 执行FIFO页面置换算法
int fifoPageReplacement(int pages[], int n, int frames) {
    printf("-------- FIFO 页面置换算法 --------\n");
    PageEntry queue[MAX_FRAMES];
    initializeQueue(queue, frames);

    int pageFaults = 0;
    int front = 0; // 页面队列的前端索引

    for (int i = 0; i < n; ++i) {
        if (!isPageInMemory(pages[i], queue, frames)) {
            // 页面未命中，进行页面置换
            int replacedPage = queue[front].page;
            queue[front].page = pages[i];
            front = (front + 1) % frames; // 更新队列前端索引
            ++pageFaults;

            // 输出页面置换信息
            printf("页面置换:  页%d 替换 页%d\n", replacedPage, pages[i]);
        } else {
            // 页面命中
            printf("页面命中\n");
        }
    }

    return pageFaults;
}

// 执行LRU页面置换算法
int lruPageReplacement(int pages[], int n, int frames) {
    printf("-------- LRU 页面置换算法 --------\n");
    PageEntry queue[MAX_FRAMES];
    initializeQueue(queue, frames);

    int pageFaults = 0;

    for (int i = 0; i < n; ++i) {
        if (!isPageInMemory(pages[i], queue, frames)) {
            // 页面未命中，进行页面置换
            int replacedPage = queue[0].page;
            // 更新页面队列，将最近使用的页面移到队列尾部
            for (int j = 0; j < frames - 1; ++j) {
                queue[j] = queue[j + 1];
            }
            queue[frames - 1].page = pages[i];

            ++pageFaults;

            // 输出页面置换信息
            printf("页面置换:  页%d 替换 页%d\n", replacedPage, pages[i]);
        } else {
            // 页面命中，更新页面队列
            for (int j = 0; j < frames; ++j) {
                if (queue[j].page == pages[i]) {
                    // 将命中的页面移到队列尾部
                    PageEntry temp = queue[j];
                    for (int k = j; k < frames - 1; ++k) {
                        queue[k] = queue[k + 1];
                    }
                    queue[frames - 1] = temp;
                    break;
                }
            }
            printf("页面命中\n");
        }
    }

    return pageFaults;
}

// 执行OPT页面置换算法
int optPageReplacement(int pages[], int n, int frames) {
    printf("-------- OPT 页面置换算法 --------\n");
    PageEntry queue[MAX_FRAMES];
    initializeQueue(queue, frames);

    int pageFaults = 0;

    for (int i = 0; i < n; ++i) {
        if (!isPageInMemory(pages[i], queue, frames)) {
            // 页面未命中，进行页面置换
            int replacedPage = queue[0].page;

            // 查找未来最长时间不被访问的页面
            int index = 0;
            int farthest = i;
            for (int j = 0; j < frames; ++j) {
                int k;
                for (k = i; k < n; ++k) {
                    if (queue[j].page == pages[k]) {
                        if (k > farthest) {
                            farthest = k;
                            index = j;
                        }
                        break;
                    }
                }

                // 如果页面未在未来的访问中出现，直接选择该页面
                if (k == n) {
                    index = j;
                    break;
                }
            }

            queue[index].page = pages[i];

            ++pageFaults;

            // 输出页面置换信息
            printf("页面置换:  页%d 替换 页%d\n", replacedPage, pages[i]);
        } else {
            // 页面命中
            printf("页面命中\n");
        }
    }

    return pageFaults;
}

// 执行LFU页面置换算法
int lfuPageReplacement(int pages[], int n, int frames) {
    printf("-------- LFU 页面置换算法 --------\n");
    PageEntry queue[MAX_FRAMES];
    initializeQueue(queue, frames);

    int pageFaults = 0;

    for (int i = 0; i < n; ++i) {
        if (!isPageInMemory(pages[i], queue, frames)) {
            // 页面未命中，进行页面置换
            int replacedPage = queue[0].page;

            // 查找使用次数最少的页面
            int minCountIndex = 0;
            for (int j = 1; j < frames; ++j) {
                if (queue[j].referenced < queue[minCountIndex].referenced ||
                    (queue[j].referenced == queue[minCountIndex].referenced && queue[j].page < queue[minCountIndex].page)) {
                    minCountIndex = j;
                }
            }

            queue[minCountIndex].page = pages[i];
            queue[minCountIndex].referenced = 1; // 重置使用次数

            ++pageFaults;

            // 输出页面置换信息
            printf("页面置换:  页%d 替换 页%d\n", replacedPage, pages[i]);
        } else {
            // 页面命中，增加页面使用次数
            for (int j = 0; j < frames; ++j) {
                if (queue[j].page == pages[i]) {
                    ++queue[j].referenced;
                    break;
                }
            }
            printf("页面命中\n");
        }
    }

    return pageFaults;
}

// 执行CLOCK页面置换算法
int clockPageReplacement(int pages[], int n, int frames) {
    printf("-------- CLOCK 页面置换算法 --------\n");
    PageEntry queue[MAX_FRAMES];
    initializeQueue(queue, frames);

    int pageFaults = 0;
    int hand = 0; // 时钟指针，指向当前检查的页面

    for (int i = 0; i < n; ++i) {
        if (!isPageInMemory(pages[i], queue, frames)) {
            // 页面未命中，进行页面置换
            int replacedPage = queue[hand].page;
            // 查找未被引用的页面，替换为新页面
            while (queue[hand].referenced == 1) {
                queue[hand].referenced = 0;
                hand = (hand + 1) % frames;
            }
            queue[hand].page = pages[i];
            queue[hand].referenced = 1;

            ++pageFaults;

            // 输出页面置换信息
            printf("页面置换:  页%d 替换 页%d\n", replacedPage, pages[i]);
        } else {
            // 页面命中，设置使用位为1
            for (int j = 0; j < frames; ++j) {
                if (queue[j].page == pages[i]) {
                    queue[j].referenced = 1;
                    break;
                }
            }
            printf("页面命中\n");
        }
    }

    return pageFaults;
}

int main() {
    srand(time(NULL)); // 使用当前时间作为随机数种子

    int instructions[INSTRUCTION_COUNT];
    generateInstructions(instructions);

    for (int frames = 4; frames <= MAX_FRAMES; frames *= 2) {
        printf("\n----- 内存容量：%d 页 -----\n", frames);

        float fifoHitRate = executeAndCalculateHitRate(instructions, INSTRUCTION_COUNT, frames, fifoPageReplacement);
        printf("FIFO页面置换算法的命中率: %.2f%%\n", fifoHitRate * 100);

        float lruHitRate = executeAndCalculateHitRate(instructions, INSTRUCTION_COUNT, frames, lruPageReplacement);
        printf("LRU页面置换算法的命中率: %.2f%%\n", lruHitRate * 100);

        float optHitRate = executeAndCalculateHitRate(instructions, INSTRUCTION_COUNT, frames, optPageReplacement);
        printf("OPT页面置换算法的命中率: %.2f%%\n", optHitRate * 100);

        float lfuHitRate = executeAndCalculateHitRate(instructions, INSTRUCTION_COUNT, frames, lfuPageReplacement);
        printf("LFU页面置换算法的命中率: %.2f%%\n", lfuHitRate * 100);

        float clockHitRate = executeAndCalculateHitRate(instructions, INSTRUCTION_COUNT, frames, clockPageReplacement);
        printf("CLOCK页面置换算法的命中率: %.2f%%\n", clockHitRate * 100);
    }

    return 0;
}
