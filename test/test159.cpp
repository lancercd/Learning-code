#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1,p2 = n - 1,p3 = nums1.size() - 1;
        while (p2 >= 0) {
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p3--] = nums1[p1--];
            }
            else nums1[p3--] = nums2[p2--];
        }
    }
};


int main() {
    Solution* solu = new Solution();
    vector<int> arr = { 0 };
    vector<int> num = { 1 };

    solu->merge(arr, arr.size() - num.size(), num, num.size());

    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
