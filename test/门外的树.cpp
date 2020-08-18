#include "iostream"

using namespace std;
int box[5001][5001];
int r;


int main() {
	register int x, y, v, tmp_v=0,j=0;
	int n, i = 0;
	cin >> n >> r;
	for (; i < n; ++i)
	{
		cin >> x >> y >> v;
		box[x][y] = v;
	}


	return 0;
}
