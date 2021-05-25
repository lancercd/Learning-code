#include "iostream"
#include "algorithm"
#include "vector"
#include "cstdio"
#include "cstring"

using namespace std;

const int MAXN = 1e3 + 5;
char a[MAXN] = {0};
char b[MAXN] = {0};
int T;
int n, m;
int cnt = 0;

void preKmp(char *src, int m, int *rule){
  int i=0,j=-1;
  rule[0]=j;
  while(i<m){
      while(j!=-1 && src[j] != src[i])
          j=rule[j];
      i++,j++;
      if(j>=m)
          rule[i]=rule[j-1];
      else
          rule[i]=j;
  }
}

void kmp(char *src, int m, char *dest, int n)
{
    int rule[MAXN];
    preKmp(src,m,rule);
    int i=0, j=0;
    while(i<n){
        while(j!=-1 && src[j] != dest[i]){
            j = rule[j];
        }
        i++,j++;
        if(j==m){
            cnt++;
            j=rule[j];
        }
    }
}


int main() {
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> T;
    while(T--){
        cnt = 0;
        cin >> n >> m;
        cin >> a >> b;
        for(int i=0; i<n; ++i){
            if(a[i] >= 'A' && a[i] <= 'Z') a[i] = (a[i] + 'a' - 'A');
        }
        for(int i=0; i<m; ++i){
            if(b[i] >= 'A' && b[i] <= 'Z') b[i] = (b[i] + 'a' - 'A');
        }
        kmp(a,n,b,m);
        cout << cnt << endl;
    }
    return 0;
}
