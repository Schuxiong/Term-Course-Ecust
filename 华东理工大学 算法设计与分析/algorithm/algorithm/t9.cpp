//#include <iostream>
//#include <vector>
//#include <tuple> // Add this line
//using namespace std;
//
//tuple<int, int, int> max_subsequence_sum(const vector<int>& nums) {
//    int max_sum = INT_MIN;
//    int current_sum = 0;
//    int start_position = 1;
//    int end_position = 1;
//    int current_start = 1;
//
//    for (int i = 0; i < nums.size(); ++i) {
//        current_sum += nums[i];
//
//        if (current_sum > max_sum) {
//            max_sum = current_sum;
//            start_position = current_start;
//            end_position = i + 1;
//        }
//
//        if (current_sum < 0) {
//            current_sum = 0;
//            current_start = i + 2;
//        }
//    }
//
//    return make_tuple(max_sum, start_position, end_position);
//}
//
//int main() {
//    int t;
//    cin >> t;
//
//    for (int case_num = 1; case_num <= t+1; ++case_num) {
//        int n;
//        cin >> n;
//        vector<int> sequence(n);
//        for (int i = 0; i < n; ++i) {
//            cin >> sequence[i];
//        }
//
//        auto result = max_subsequence_sum(sequence);
//        int max_sum, start_position, end_position;
//        tie(max_sum, start_position, end_position) = result;
//
//        cout << "Case " << case_num << ":" << max_sum << " " << start_position << " " << end_position << endl;
//
//        if (case_num <= t+1) {
//            cout << endl;  // Output a blank line between two cases
//        }
//    }
//    getchar();
//    return 0;
//}
//
