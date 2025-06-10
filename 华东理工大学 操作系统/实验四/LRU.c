#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10 // 最大页面帧数
#define MAX_PAGES 50  // 最大页面数

// 初始化页面队列
void initializeQueue(int queue[], int frames) {
    for (int i = 0; i < frames; ++i) {
        queue[i] = -1; // -1表示页面帧为空
    }
}

// 检查页面是否在页面队列中
int isPageInMemory(int page, int queue[], int frames) {
    for (int i = 0; i < frames; ++i) {
        if (queue[i] == page) {
            return 1; // 页面命中
        }
    }
    return 0; // 页面未命中
}

// 更新页面队列，将最近使用的页面移到队列尾部
void updateQueue(int page, int queue[], int frames) {
    for (int i = 0; i < frames; ++i) {
        if (queue[i] == page) {
            // 将页面移到队列尾部
            for (int j = i; j < frames - 1; ++j) {
                queue[j] = queue[j + 1];
            }
            queue[frames - 1] = page; // 将页面放到队列尾部
            break;
        }
    }
}

// 执行LRU页面置换算法
int lruPageReplacement(int pages[], int n, int frames) {
    int queue[MAX_FRAMES];
    initializeQueue(queue, frames);

    int pageFaults = 0;

    for (int i = 0; i < n; ++i) {
        printf("访问页面 %d: ", pages[i]);

        if (!isPageInMemory(pages[i], queue, frames)) {
            // 页面未命中，进行页面置换
            ++pageFaults;
            if (queue[0] != -1) {
                // 队列未满时，直接将新页面加入队列尾部
                updateQueue(pages[i], queue, frames);
            } else {
                // 队列已满时，将队列头部页面替换为新页面
                for (int j = 0; j < frames - 1; ++j) {
                    queue[j] = queue[j + 1];
                }
                queue[frames - 1] = pages[i];
            }

            // 输出页面置换信息
            printf("页面置换\n");
        } else {
            // 页面命中，更新页面队列
            updateQueue(pages[i], queue, frames);
            printf("页面命中\n");
        }

        // 输出当前页面队列
        printf("当前页面队列: ");
        for (int j = 0; j < frames; ++j) {
            if (queue[j] == -1) {
                printf("[ ] ");
            } else {
                printf("[%d] ", queue[j]);
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

    // 执行LRU页面置换算法
    int pageFaults = lruPageReplacement(pages, n, frames);

    // 输出结果
    printf("\nLRU页面置换算法的页面缺页次数: %d\n", pageFaults);
    printf("LRU页面置换算法的命中率: %.2f%%\n", ((float)(n - pageFaults) / n) * 100);

    return 0;
}
