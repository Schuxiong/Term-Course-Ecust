#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10 // 最大页面帧数
#define MAX_PAGES 50  // 最大页面数
#define INFINITY 9999 // 代表无穷大

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

// 查找未来最长时间不被访问的页面
int findOptimalPage(int pages[], int start, int n, int queue[], int frames) {
    int index = -1;
    int farthest = start;

    for (int i = 0; i < frames; ++i) {
        int j;
        for (j = start; j < n; ++j) {
            if (queue[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }

        // 如果页面未在未来的访问中出现，直接选择该页面
        if (j == n) {
            return i;
        }
    }

    // 如果所有页面在未来都有访问，选择最长时间不被访问的页面
    return (index == -1) ? 0 : index;
}

// 执行OPT页面置换算法
int optPageReplacement(int pages[], int n, int frames) {
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
                int index = findOptimalPage(pages, i + 1, n, queue, frames);
                queue[index] = pages[i];
            } else {
                // 队列已满时，将队列头部页面替换为新页面
                queue[0] = pages[i];
            }

            // 输出页面置换信息
            printf("页面置换\n");
        } else {
            // 页面命中
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

    // 执行OPT页面置换算法
    int pageFaults = optPageReplacement(pages, n, frames);

    // 输出结果
    printf("\nOPT页面置换算法的页面缺页次数: %d\n", pageFaults);
    printf("OPT页面置换算法的命中率: %.2f%%\n", ((float)(n - pageFaults) / n) * 100);

    return 0;
}
