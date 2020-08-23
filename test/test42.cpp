#include "iostream"
#include "algorithm"
using namespace std;

class Solution {
public:
    bool divisorGame(int N) {
        int count = 0;
        while(1){
            ++count;int x;

            for(x=1; x< N; ++x){
                if(N%x == 0) break;
            }
            if(x >= N) break;  //没有找到
            N = N - x;
        }

        return (count %2 == 0);
    }
};

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    Solution * a = new Solution;
    cout << a->divisorGame(n) << endl;
    return 0;
}
