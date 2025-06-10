//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//class Solution {
//private:
//    int partition(vector<int>& nums, int l, int r) {
//        int pivot = nums[r];
//        int i = l - 1;
//        for (int j = l; j <= r - 1; ++j) {  // 修正此行，j 的起始值应为 l
//            if (nums[j] <= pivot) {
//                i = i + 1;
//                swap(nums[i], nums[j]);
//            }
//        }
//        swap(nums[i + 1], nums[r]);
//        return i + 1;
//    }
//
//    int randomized_partition(vector<int>& nums, int l, int r) {
//        int i = rand() % (r - l + 1) + l;
//        swap(nums[r], nums[i]);
//        return partition(nums, l, r);
//    }
//
//    void randomized_selected(vector<int>& stock, int l, int r, int cnt) {
//        if (l >= r) {
//            return;
//        }
//        int pos = randomized_partition(stock, l, r);
//        int num = pos - l + 1;
//        if (cnt == num) {
//            return;
//        }
//        else if (cnt < num) {
//            randomized_selected(stock, l, pos - 1, cnt);
//        }
//        else {
//            randomized_selected(stock, pos + 1, r, cnt - num);
//        }
//    }
//
//public:
//    vector<int> inventoryManagement(vector<int>& stock, int cnt) {
//        srand((unsigned)time(NULL));
//        randomized_selected(stock, 0, (int)stock.size() - 1, cnt);  // 修正此行，去掉分号
//        vector<int> vec;
//        for (int i = 0; i < cnt; ++i) {
//            vec.push_back(stock[i]);
//        }
//        return vec;
//    }
//};
//
//int main() {
//    // 示例输入
//    vector<int> stock = { 5, 2, 1, 3, 4 };
//    int cnt = 3;
//
//    // 创建 Solution 对象
//    Solution solution;
//
//    // 调用 inventoryManagement 函数
//    vector<int> result = solution.inventoryManagement(stock, cnt);
//
//    // 输出结果
//    cout << "Selected items: ";
//    for (int item : result) {
//        cout << item << " ";
//    }
//    cout << endl;
//    getchar();
//    return 0;
//}
