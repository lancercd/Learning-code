#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

vector<int> arr;
int num = 0;

int maxProfit() {
    int len = arr.size();
    if(len ==0 || len == 1) return 0;

    int lowestPrice = arr[0];

    int mon = 0;
    for(int i=0; i<len; ++i){
        if(arr[i] - lowestPrice > 0) {
            mon = max(arr[i] - lowestPrice, mon);
        }else {
            lowestPrice = arr[i];
        }
    }
    return mon;
}

int main() {
    // freopen("../../data/in.txt", "r", stdin); freopen("../../data/out.txt", "w", stdout);
    while(cin >> num) arr.push_back(num);

    cout << maxProfit() << endl;
    return 0;
}
