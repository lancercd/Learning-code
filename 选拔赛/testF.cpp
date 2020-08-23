#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
typedef long long ll;
// const int MAXN = 5e3 + 10;
vector<ll> arr;

int main(int argc, char const* argv[]) {

    int N, M; cin >> N >> M;
    if (N < 4) {
        arr.push_back(1); arr.push_back(2); arr.push_back(3);
    }
    else {
        for (int i = 1; i <= N; i += 2) arr.push_back(i);
        int flag = 3;
        while (arr.size() > 3) {
            vector<ll> save;
            for (unsigned int i = 0; i < arr.size(); ++i) {
                if ((i + 1) % flag != 0) save.push_back(arr[i]);
            }

            flag == 3 ? flag = 2 : flag = 3;
            arr = save;
        }
    }

    ll count = 0;
    for(unsigned int i=0; i<arr.size(); ++i){
        count += arr[i];
    }
    if(count > M){
        for(unsigned int i=0; i<arr.size(); ++i){
            cout << arr[i] << " ";
        }
    }else{
        cout << abs(M - count);
    }

    return 0;
}
