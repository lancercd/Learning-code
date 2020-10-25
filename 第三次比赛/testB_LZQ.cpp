#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>

#define ll long long int

using namespace std;

#include <limits.h>
#include <math.h>

typedef struct boat{
	string name;
	ll v;
}boat;

inline bool cmp(boat a, boat b){
	if(a.v < b.v) return true;
	else return false;
}


int main() {
	std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
	ll n, L;
	cin >> n >> L;
	vector<boat> bt(n);
	for(int i=0; i<n; i++) cin >> bt[i].name >> bt[i].v;

	sort(bt.begin(), bt.begin()+n, cmp);

//	for(int i=0; i<n; i++) cout << bt[i].name << endl;

	for(int i=0; i<n-1; i++){
		// 第i+1分钟淘汰第i只船
		cout << bt[i].name << ' ';
		// 跑了几圈
		ll circle = (bt[i].v * (i+1)) / L;
		ll sh;
		if(circle*L == bt[i].v * (i+1)) sh = 0;
		else sh = L - (bt[i].v*(i+1)-L*circle);
		cout << circle << ' ' << sh << endl;
	}

	cout << bt[n-1].name;

	return 0;
}
