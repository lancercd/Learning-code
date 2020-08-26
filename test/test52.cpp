#include "iostream"
#include "algorithm"
#include "string"
#include "cstring"

using namespace std;
const int MAXN = 25;
string arr[MAXN];

bool cmp(string a, string b){
    if(a + b > b + a) return true;
    return false;
}

int main() {
    int N; cin >> N;for(int i=0; i<N; ++i) {cin >> arr[i];}
    sort(arr, arr + N, cmp);
    for(int i=0; i<N; ++i)
    {
        cout << arr[i];
    }
    cout << endl;
    return 0;
}
