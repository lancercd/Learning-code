#include "iostream"
#include "algorithm"
#include "cstdio"
#include "cstring"

using namespace std;
int n,m;
char s[1005][1005];
int vi[1005][1005];
int JUD(int x,int y){
	if (vi[x][y]!=-1)
		return vi[x][y];
	if (x<1||y<1||x>n||y>m)
		return 1;
	vi[x][y]=0;
	if (s[x][y]=='W') vi[x][y]=JUD(x-1,y);
	if (s[x][y]=='A') vi[x][y]=JUD(x,y-1);
	if (s[x][y]=='S') vi[x][y]=JUD(x+1,y);
	if (s[x][y]=='D') vi[x][y]=JUD(x,y+1);
	return vi[x][y];
}
int main(){
	scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i)
    {
        scanf("%s",s[i]+1);
    }
	memset(vi,-1,sizeof(vi));
	int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;i<=m;j++){
            if (JUD(i,j)) ++ans;
        }
    }

	cout<<ans<<endl;
}
