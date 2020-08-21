#include "iostream"
#include "algorithm"
using namespace std;
const int MAXN = 2e5 + 5;
bool arr[MAXN] = {0};
const int MAXW = 32;
int w[MAXN];
int main(int argc, char const *argv[]) {
    int V,N; cin >> V >> N; arr[0] = true;
    for(int i=0; i<N; ++i) cin >> w[i];
    arr[w[0]] = true;
    for(int i=1; i<N; ++i)
    {
        for(int j=V; j>-1; --j)
        {
            if(arr[j]){
                // cout << j << " " << j + w[i] << endl;
                arr[j + w[i]] = true;
            }
        }
    }
    // cout << "************" << endl;
    // for(int i=1; i<= V; ++i)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << "************" << endl;
    // cout << "V:" << V << "   v-1:" << V-1 << endl;
    for(int i=V; i > -1; --i)
    {
        if(arr[i]){
            // cout << "i:" << i << endl;
            cout << (V - i) << endl;
            break;
        }
    }
    return 0;
}
