#include "iostream"
#include "algorithm"

using namespace std;
const int MAXN = 5e6 + 1;
int arr[MAXN];
int main(int argc, char const *argv[]) {
    // register int i=0;
    // int n,k;
    // cin >> n >> k;
    // int* arr = new int[n];
    // for(; i<n; ++i) cin >> arr[i];
    // sort(arr, arr + n);
    // int pre = arr[0] -1;
    // for(i=0; i<n; i++){
    //     if(pre == arr[i]){ continue; }else{ --k; pre = arr[i]; }
    //     if(k == 0){ cout << arr[i]; break; }
    // }
    // if(k != 0) cout << "NO RESULT" << endl;
    // return 0;



    register int i=0;
    int n,k;
    cin >> n >> k;
    for(i=0; i<n; ++i) cin >> arr[i];
    sort(arr, arr + n);
    cout << arr[k-1] << endl;

}
