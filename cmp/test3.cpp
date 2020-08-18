#include "iostream"
#include "algorithm"
#include "set"
#include "map"
#include "vector"
#include "string"

using namespace std;
const int MAXN = 1e5 + 10;
int arr[MAXN];


int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int N, i, total = 0; cin >> N;
    for(i=1; i<=N; ++i){ cin >> arr[i]; total += arr[i];}

    int count=0, half=total/2, index=1, ans = 0;
    for(int i=1;i<=N;++i)
    {
        while(count<half)
        {
            count+=arr[index];
            ++index;
            if(index==N+1)index=1;
        }
        ans=max(ans,min(count,total-count));
        count-=arr[i];
    }
    cout << ans;

    return 0;
}
