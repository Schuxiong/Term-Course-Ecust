//#include <iostream>
//#include <climits>
//
//using namespace std;
//
//// 定义结构体，表示某一区间内的四种和值
//struct Status {
//    int lSum;  // 表示区间内以左边界为起点的最大子数组和
//    int rSum;  // 表示区间内以右边界为终点的最大子数组和
//    int mSum;  // 表示区间内的最大子数组和
//    int iSum;  // 表示区间内的总和
//};
//
//// 合并左右子区间的结果
//struct Status pushUp(struct Status l, struct Status r) {
//    int iSum = l.iSum + r.iSum;  // 总和为左右子区间总和之和
//    int lSum = max(l.lSum, l.iSum + r.lSum);  // 左边界最大子数组和可能在左子区间，也可能跨越左右子区间
//    int rSum = max(r.rSum, r.iSum + l.rSum);  // 右边界最大子数组和可能在右子区间，也可能跨越左右子区间
//    int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);  // 区间内的最大子数组和可能在左子区间、右子区间，也可能跨越左右子区间
//    struct Status result = { lSum, rSum, mSum, iSum };
//    return result;
//}
//
//// 递归求解最大子数组和
//struct Status get(int* a, int l, int r) {
//    // 当区间长度为1时，直接返回当前元素构成的结果
//    if (l == r) {
//        struct Status result = { a[l], a[l], a[l], a[l] };
//        return result;
//    }
//    // 分为左右两个子区间求解
//    int m = (l + r) >> 1;
//    struct Status lSub = get(a, l, m);
//    struct Status rSub = get(a, m + 1, r);
//    // 合并左右子区间的结果
//    return pushUp(lSub, rSub);
//}
//
//// 主函数，返回整数数组中的最大子数组和
//int maxSubArray(int* nums, int numsSize) {
//    return get(nums, 0, numsSize - 1).mSum;
//}
//
//int main() {
//    // 提示用户输入数组元素
//    cout << "请输数元素个数后，再依次输入整数数组，以空格分隔：" << endl;
//
//    // 动态分配数组内存
//    int numsSize;
//    cin >> numsSize;
//    int* nums = new int[numsSize];
//
//    // 输入数组元素
//    for (int i = 0; i < numsSize; ++i) {
//        cin >> nums[i];
//    }
//
//    // 计算最大子数组和
//    int result = maxSubArray(nums, numsSize);
//
//    // 输出结果阿
//    cout << "最大子数组和为：" << result << endl;
//
//    // 清除输入缓冲区中的回车符
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    // 等待用户输入，以便查看输出结果
//    getchar();
//
//    // 释放动态分配的数组内存
//    delete[] nums;
//
//    return 0;
//}
