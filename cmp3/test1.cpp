#include "iostream"
#include "algorithm"
#include "map"

using namespace std;

map<int, int> arr;
int N;
int main() {
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> N;
    int tmp;
    for(int i=0; i<N; ++i)
    {
        cin >> tmp;
        ++arr[tmp];
    }

    int ans=-1;
    map<int, int>::iterator iter;
    iter = arr.begin();
    while(iter != arr.end()) {
        if(iter->first == iter->second){
            if(iter->first > ans){
                ans = iter->first;
            }
        }
        iter++;
    }

    cout << ans << endl;


    return 0;
}
