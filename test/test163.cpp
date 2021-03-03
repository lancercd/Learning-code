#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        digits[i] += 1;
        while(digits[i] == 10 && i > -1){
            digits[i] = 0;
            if(0 == i){
                digits.insert(digits.begin(), 1, 1);
                break;
            }
            ++digits[--i];
        }

        return digits;
    }
};
int main() {
    Solution* solu = new Solution();
    vector<int> arr = {9,9,9};
    solu->plusOne(arr);
    for(int i=0; i < arr.size();++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
