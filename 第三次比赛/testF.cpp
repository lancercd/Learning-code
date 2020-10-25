#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>

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

const int Mod_int = 998244353;

int N, M;

int main() {
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
	cin >> N >> M;
    register int i=0;
	long long int res = 0;

	long long int dp[M+1];

	for(i=0; i<=M; i++) dp[i] = 0;

	for(i=1; i<=N; i++){
		for(int j=M; j>1; j--){
			dp[j] = (i*dp[j-1] % Mod_int + dp[j-2] % Mod_int) % Mod_int;
		}
		dp[1] = i;
	}

	// for(int i=0; i<=M; i++) cout << dp[i] << ' ';
	// cout << endl;

	res = dp[M]%Mod_int;

	cout << res;

	return 0;
}
