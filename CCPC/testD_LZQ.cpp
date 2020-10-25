#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>

#define ll long long

using namespace std;

#include <limits.h>
#include <math.h>

inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)) {if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}


int main() {
	freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	// MI Routers , bidirectional connections

	vector<int> route(n+1, 0);
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;

		route[a]++;
		route[b]++;
	}

	int connected_sum = m*2;

//	for(int i=1; i<n+1; i++) cout << route[i] << ' ';
//	cout << endl;

	for(int i=1; i<n+1; i++){
		int res = n-1 - (connected_sum - route[i]*2)/2;
		cout << res << ' ';

	}

	return 0;
}

/*
4 2
1 2
1 3
*/
