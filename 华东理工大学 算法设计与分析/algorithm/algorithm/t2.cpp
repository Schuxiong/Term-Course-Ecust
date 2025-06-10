//#include <iostream>
//#include <climits>
//
//using namespace std;
//
//// ����ṹ�壬��ʾĳһ�����ڵ����ֺ�ֵ
//struct Status {
//    int lSum;  // ��ʾ����������߽�Ϊ��������������
//    int rSum;  // ��ʾ���������ұ߽�Ϊ�յ������������
//    int mSum;  // ��ʾ�����ڵ�����������
//    int iSum;  // ��ʾ�����ڵ��ܺ�
//};
//
//// �ϲ�����������Ľ��
//struct Status pushUp(struct Status l, struct Status r) {
//    int iSum = l.iSum + r.iSum;  // �ܺ�Ϊ�����������ܺ�֮��
//    int lSum = max(l.lSum, l.iSum + r.lSum);  // ��߽����������Ϳ������������䣬Ҳ���ܿ�Խ����������
//    int rSum = max(r.rSum, r.iSum + l.rSum);  // �ұ߽����������Ϳ������������䣬Ҳ���ܿ�Խ����������
//    int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);  // �����ڵ����������Ϳ������������䡢�������䣬Ҳ���ܿ�Խ����������
//    struct Status result = { lSum, rSum, mSum, iSum };
//    return result;
//}
//
//// �ݹ��������������
//struct Status get(int* a, int l, int r) {
//    // �����䳤��Ϊ1ʱ��ֱ�ӷ��ص�ǰԪ�ع��ɵĽ��
//    if (l == r) {
//        struct Status result = { a[l], a[l], a[l], a[l] };
//        return result;
//    }
//    // ��Ϊ�����������������
//    int m = (l + r) >> 1;
//    struct Status lSub = get(a, l, m);
//    struct Status rSub = get(a, m + 1, r);
//    // �ϲ�����������Ľ��
//    return pushUp(lSub, rSub);
//}
//
//// ���������������������е�����������
//int maxSubArray(int* nums, int numsSize) {
//    return get(nums, 0, numsSize - 1).mSum;
//}
//
//int main() {
//    // ��ʾ�û���������Ԫ��
//    cout << "������Ԫ�ظ����������������������飬�Կո�ָ���" << endl;
//
//    // ��̬���������ڴ�
//    int numsSize;
//    cin >> numsSize;
//    int* nums = new int[numsSize];
//
//    // ��������Ԫ��
//    for (int i = 0; i < numsSize; ++i) {
//        cin >> nums[i];
//    }
//
//    // ��������������
//    int result = maxSubArray(nums, numsSize);
//
//    // ��������
//    cout << "����������Ϊ��" << result << endl;
//
//    // ������뻺�����еĻس���
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    // �ȴ��û����룬�Ա�鿴������
//    getchar();
//
//    // �ͷŶ�̬����������ڴ�
//    delete[] nums;
//
//    return 0;
//}
