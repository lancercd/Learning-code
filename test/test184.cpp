#include "iostream"
#include "algorithm"

using namespace std;
const int MAXN = 1e7 + 5;
int arr[MAXN] = {0};
int L, N, K;

int findMaxIndex(int arr[], int len){
    int index = 0;
    for(int i=1; i<len; ++i){
        if(arr[index] < arr[i]) index = i;
    }

    return index;
}


void show(int arr[], int len){
    for(int i=0; i<len; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> L >> N >> K;
    int tmp = 0, pre = 0;
    for(int i=0; i<N; ++i)
    {
        cin >> arr[i];
        tmp = arr[i];
        arr[i] -= pre;
        pre = tmp;
    }

    if(0 == K){
        cout << arr[findMaxIndex(arr, N)];
        return 0;
    }

    int expor[K] = {0};
    pre = 0;

    for(int i=0; i<K; ++i)
    {
        int a = findMaxIndex(arr, N);
        int b = findMaxIndex(expor, K);
        if(arr[a] > expor[b]){
            tmp = arr[a];
            arr[a] >>= 1;
            expor[pre++] = tmp - arr[a];
        }else{
            tmp = expor[b];
            expor[b] >>= 1;
            expor[pre++] = tmp - expor[b];
        }
    }


    int a = findMaxIndex(arr, N);
    int b = findMaxIndex(expor, K);
    cout << ((arr[a] > expor[b])? arr[a] : expor[b]);


    // cout << endl;
    // show(arr, N);
    // show(expor, K);
    return 0;
}
