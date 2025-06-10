//#include <stdio.h>
//#include <limits.h>
//
//#define N 4
//
//// 定义城市之间的距离
//int distanceGraph[N][N] = {
//    {0, 30, 4, 6},
//    {30, 0, 10, 5},
//    {4, 10, 0, 20},
//    {6, 5, 20, 0}
//};
//
//int minDistance = INT_MAX;
//int minPath[N + 1];
//
//// 记录已经访问过的城市
//int visited[N] = { 0 };
//
//// 回溯函数
//void tsp(int current, int count, int path[N + 1]) {
//    if (count == N) {
//        // 已经访问过所有城市，回到起始城市
//        path[count] = path[0];
//        int totalDistance = 0;
//
//        // 计算路径总距离
//        for (int i = 0; i < N; i++) {
//            totalDistance += distanceGraph[path[i]][path[i + 1]];
//        }
//
//        // 更新最小距离和路径
//        if (totalDistance < minDistance) {
//            minDistance = totalDistance;
//            for (int i = 0; i <= N; i++) {
//                minPath[i] = path[i];
//            }
//        }
//        return;
//    }
//
//    // 尝试访问每个城市
//    for (int i = 0; i < N; i++) {
//        if (!visited[i]) {
//            visited[i] = 1;
//            path[count] = i;
//            tsp(i, count + 1, path);
//            visited[i] = 0; // 回溯
//        }
//    }
//}
//
//int main() {
//    int path[N + 1] = { 0 }; // 保存最终路径
//
//    // 从城市0开始
//    visited[0] = 1;
//    path[0] = 0;
//
//    // 开始搜索
//    tsp(0, 1, path);
//
//    // 打印最短路径和总距离
//    printf("最短路径: ");
//    for (int i = 0; i <= N; i++) {
//        printf("%d ", minPath[i]+1);
//    }
//    printf("\n总距离: %d\n", minDistance);
//    getchar();
//    return 0;
//}
