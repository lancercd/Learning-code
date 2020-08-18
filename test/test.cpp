#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int a[110],b[maxn];
int n,t,m;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i%a[j]==0)
				b[i]=1;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(b[i]==0)
			cnt++;
	cout<<cnt;
	return 0;
}
