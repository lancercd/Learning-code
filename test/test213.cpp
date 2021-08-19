#include<bits/stdc++.h>

using namespace std;
const int MAXN = 1e3 + 3;
int arr[MAXN] = { 0 };
int w[MAXN] = { 0 };
int n, m;
int total = n - 1;

inline int read()
{
	int x = 0 , f = 1 ;
	char ch = getchar() ;
	while(ch > '9' or ch < '0')
	{
		if(ch == '-') f = -1 ;
		ch = getchar() ;
	}
	while(ch >= '0' and ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48) ;
		ch = getchar() ;
	}
	return x * f ;
}


int findRoot(int target) {
  while(arr[target] != 0){
    target = arr[target];
  }
  return target;
}

void init() {
  fill(arr, arr + n + 2, 0);
  fill(w, w + n + 2, 0);
}

void insert(int a, int b) {
  int root_a = findRoot(a),
      root_b = findRoot(b);
  if(root_a == root_b) return;
  --total;

  if(w[root_a] > w[root_b]) {
    arr[root_b] = root_a;
  } else {
    arr[root_a] = root_b;

    if(w[root_a] == w[root_b]){
      ++w[root_b];
    }
  }
}

int main() {
  // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
  int a, b;
  while(cin >> n >> m){
    total = n - 1;
    if(m == 0) { cout << total << endl; continue; }

    init();

    while(m --) { a = read(); b = read(); insert(a, b); }

    cout << total << endl;

  }

  return 0;
}
