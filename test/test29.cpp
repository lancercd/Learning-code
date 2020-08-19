#include "iostream"
#include "algorithm"
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        n -= 1;
        unsigned long long arr[2] = {1,2}, count = 0;
        if(n < 2) return arr[n];
        while(n > 1){
            count = arr[1] + arr[0];
            arr[0] = arr[1];
            arr[1] = count;

            --n;
        }
        return count;
    }

};
int main(int argc, char const *argv[]) {
    Solution * a = new Solution;
    cout << a->climbStairs(4) << endl;
    return 0;
}
