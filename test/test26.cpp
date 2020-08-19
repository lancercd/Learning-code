#include "iostream"
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        int arr[3] = {0,1,1},count=0;
        if(n < 3) return arr[n];
        while(n>2){
            count = arr[0] + arr[1] + arr[2];
            arr[0] = arr[1]; arr[1] = arr[2];arr[2] = count;
            --n;
        }

        return count;
    }
};

int main(){
    Solution * s = new Solution;
    cout << s->tribonacci(2);

    return 0;
}
