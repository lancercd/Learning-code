#include "iostream"
#include "algorithm"
#include "vector"

//寻找两个正序数组的中位数
//https://leetcode-cn.com/problems/median-of-two-sorted-arrays/

using namespace std;
class Solution {
    int posA = 0;
    int posB = 0;
    double ans = 0.0;

    void check(int i, int &n, vector<int> &nums) {
        if (i == this->posA) this->ans += nums[n];
        if (i == this->posB) this->ans += nums[n];
        ++n;
    }
 public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int lenA = nums1.size(),
            lenB = nums2.size(),
            len = lenA + lenB;
        this->posA = len / 2;
        this->posB = posA;
        if (len % 2 == 0) {
            this->posA -= 1;
            this->posB = this->posA + 1;
        }

        int i = 0, iA = 0, iB = 0;
        while (i < len) {
            if (iA == lenA) this->check(i, iB, nums2);
            else if (iB == lenB) this->check(i, iA, nums1);
            else {
                if (nums1[iA] < nums2[iB]) this->check(i, iA, nums1);

                else this->check(i, iB, nums2);
            }
            ++i;
        }
        return this->ans / 2.0;
    }

};
int main() {
    Solution *solu = new Solution();
    vector<int> num1 = {}, num2 = {3};

    double ans = solu->findMedianSortedArrays(num1, num2);

    cout << ans << endl;
    return 0;
}
