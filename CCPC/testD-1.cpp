#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define ll long long
using namespace std;
const int N=300005;
int n,m;
#define pii pair<int,int>
#define fi first
#define se second
vector<pii > e[N];
int dfn[N],low[N];
int inq[N],stk[N];
int con[N];
void tarjan(int x,int fid){
	dfn[x]=++*dfn;
	low[x]=*dfn;
	inq[x]=1; stk[++*stk]=x;
	//cout<<x<<' '<<fid<<endl;
	for (auto i:e[x])
		if (i.se!=fid){
			if (!dfn[i.fi]){
				int p=*stk;
				tarjan(i.fi,i.se);
				if (low[i.fi]>=dfn[x]){
					for (;*stk>p;--*stk)
						++con[stk[*stk]];
					++con[x];
				}
				low[x]=min(low[x],low[i.fi]);
			}
			else if (inq[i.fi])
				low[x]=min(low[x],dfn[i.fi]);
		}
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(pii(y,i));
		e[y].push_back(pii(x,i));
	}
	int sum=0;
	For(i,1,n)
		if (!dfn[i]){
			tarjan(i,-1);
			++sum;
			if (*stk!=1){
				for (;*stk;--*stk)
					++con[stk[*stk]];
			}
			*stk=0;
		}
	For(i,1,n){
		int ans=sum;
		if (!e[i].size()) --ans;
		else ans=ans+con[i]-1;
		printf("%d ",ans);
	}
}
