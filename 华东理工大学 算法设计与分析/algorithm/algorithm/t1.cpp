//#include <iostream>
//
//using namespace std;
//
//int count_in_range(int* nums, int target, int lo, int hi)
//{
//    int count = 0;
//    for (int i = lo; i <= hi; ++i)
//    {
//        if (nums[i] == target)
//            ++count;
//    }
//    return count;
//}
//
//
//
//int majority_element_rec(int* nums, int lo, int hi)
//{
//    if (lo == hi) return nums[lo];
//    int mid = (lo + hi) / 2;
//    int left_majority = majority_element_rec(nums, lo, mid);
//    int right_majority = majority_element_rec(nums, mid + 1, hi);
//
//    int left_count = count_in_range(nums, left_majority, lo, hi);
//    int right_count = count_in_range(nums, right_majority, lo, hi);
//
//    if (left_count > (hi - lo + 1) / 2)
//        return left_majority;
//    if (right_count > (hi - lo + 1) / 2)
//        return right_majority;
//    return -1;
//}
//
//int majorityElement(int* nums, int numSize)
//{
//    return majority_element_rec(nums, 0, numSize - 1);
//}
//
//int main()
//{
//    int size1, size2;
//
//    cout << "Enter the size of the first array: ";
//    cin >> size1;
//    int* nums1 = new int[size1];
//    cout << "Enter elements of the first array: ";
//    for (int i = 0; i < size1; ++i)
//    {
//        cin >> nums1[i];
//    }
//
//    cout << "Enter the size of the second array: ";
//    cin >> size2;
//    int* nums2 = new int[size2];
//    cout << "Enter elements of the second array: ";
//    for (int i = 0; i < size2; ++i)
//    {
//        cin >> nums2[i];
//    }
//
//    int result1 = majorityElement(nums1, size1);
//    int result2 = majorityElement(nums2, size2);
//
//    cout << "Array 1 majority element: " << result1 << endl;
//    cout << "Array 2 majority element: " << result2 << endl;
//
//    // Keep console window open
//    cin.ignore(); // Ignore any remaining newline characters
//    cout << "Press Enter to exit...";
//    cin.get();
//
//    // Don't forget to free the allocated memory
//    delete[] nums1;
//    delete[] nums2;
//
//    return 0;
//}
