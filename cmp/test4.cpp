#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long LL;

const int N = 1e5+100;
int n;
int a[N];
int b[N];
bool st[N];
map<int,int> h;
int main()
{
    IO;
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        b[i] = a[i];
    }
    sort(b+1,b+1+n);
    for(int i = 1; i<=n; i++) h[b[i]] = i;
    int ans = 0;

    for(int i = 1; i<=n; i++){
        if(st[i]) continue;
        //cout<<i<<endl;
        int j = i;
        //if(a[i]==b[i])continue;
        while(!st[j]){
            st[j] = true;
            j = h[a[j]];
        }
        ans ++;
    }
    //cout<<ans<<endl;
    cout<<n-ans<<endl;
    return 0;
}
