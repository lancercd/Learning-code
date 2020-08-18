#include "iostream"

using namespace std;

const int MAXN = 1e6+3;
int arr[MAXN];
int main(){
    int N, i, total = 0;cin >> N;
    for(int i=0; i<N; ++i) {cin >> arr[i]; total += arr[i];}

    int half = total/N, Max = 0, count=0, index = 0;
    for(i=0; i<N; ++i)
    {
        index = i;
        while(count < half){
            count += arr[index++];
            Max = max(Max, min(count, half - count));
        }
    }

    return 0;
}
