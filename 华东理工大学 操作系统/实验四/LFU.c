#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10 // 最大页面帧数
#define MAX_PAGES 50  // 最大页面数

// 页面结构体，包含页面号和使用次数
typedef struct {
    int page;
    int count;
} PageEntry;

// 初始化页面队列
void initializeQueue(PageEntry queue[], int frames) {
    for (int i = 0; i < frames; ++i) {
        queue[i].page = -1; // -1表示页面帧为空
        queue[i].count = 0; // 初始化使用次数为0
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

// 执行LFU页面置换算法
int lfuPageReplacement(int pages[], int n, int frames) {
    PageEntry queue[MAX_FRAMES];
    initializeQueue(queue, frames);

    int pageFaults = 0;

    for (int i = 0; i < n; ++i) {
        printf("访问页面 %d: ", pages[i]);

        if (!isPageInMemory(pages[i], queue, frames)) {
            // 页面未命中，进行页面置换
            ++pageFaults;

            if (queue[0].page != -1) {
                // 队列未满时，直接将新页面加入队列
                int minCountIndex = 0;
                for (int j = 1; j < frames; ++j) {
                    if (queue[j].count < queue[minCountIndex].count ||
                        (queue[j].count == queue[minCountIndex].count && queue[j].page < queue[minCountIndex].page)) {
                        minCountIndex = j;
                    }
                }
                queue[minCountIndex].page = pages[i];
                queue[minCountIndex].count = 1;
            } else {
                // 队列已满时，将使用次数最少的页面替换为新页面
                int minCountIndex = 0;
                for (int j = 1; j < frames; ++j) {
                    if (queue[j].count < queue[minCountIndex].count ||
                        (queue[j].count == queue[minCountIndex].count && queue[j].page < queue[minCountIndex].page)) {
                        minCountIndex = j;
                    }
                }
                queue[minCountIndex].page = pages[i];
                queue[minCountIndex].count = 1;
            }

            // 输出页面置换信息
            printf("页面置换\n");
        } else {
            // 页面命中，增加页面使用次数
            for (int j = 0; j < frames; ++j) {
                if (queue[j].page == pages[i]) {
                    ++queue[j].count;
                    break;
                }
            }
            printf("页面命中\n");
        }

        // 输出当前页面队列
        printf("当前页面队列: ");
        for (int j = 0; j < frames; ++j) {
            if (queue[j].page == -1) {
                printf("[ ] ");
            } else {
                printf("[%d,%d] ", queue[j].page, queue[j].count);
            }
        }
        printf("\n\n");
    }

    return pageFaults;
}

int main() {
    int pages[MAX_PAGES];
    int n, frames;

    // 输入页面访问序列
    printf("输入页面访问序列的长度: ");
    scanf("%d", &n);

    printf("输入页面访问序列:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pages[i]);
    }

    // 输入内存容量
    printf("输入内存容量: ");
    scanf("%d", &frames);

    // 执行LFU页面置换算法
    int pageFaults = lfuPageReplacement(pages, n, frames);

    // 输出结果
    printf("\nLFU页面置换算法的页面缺页次数: %d\n", pageFaults);
    printf("LFU页面置换算法的命中率: %.2f%%\n", ((float)(n - pageFaults) / n) * 100);

    return 0;
}
