#include "iostream"
#include "algorithm"

typedef unsigned long long ull;
const int MAXN = 1e4 + 5;
ull arr[MAXN];
int n;
void sort(int index){
    register int i=index,j;
    if(arr[i] < arr[i+1]) return;
        j = i + 1;
        while(1){
            if(j>=n || arr[i] <= arr[j]) break;
            ++j;
        }
        int tmp = arr[i], cnt = j-i - 1;
        while(cnt--){
            arr[i] = arr[i + 1];
            ++i;
        }
        arr[j-1] = tmp;
}
int main(int argc, char const *argv[]) {
    register int i; ull count=0;
    std::cin >> n;for(i=0; i<n; ++i) std::cin >> arr[i];
    std::sort(arr, arr + n);
    for(i=1; i<n; ++i)
    {
        arr[i] = arr[i] + arr[i-1];
        count += arr[i];
        // std::sort(arr + i, arr + n);
        sort(i);
    }
    std::cout << count << std::endl;
    return 0;
}
