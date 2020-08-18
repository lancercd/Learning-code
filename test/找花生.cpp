#include "iostream"
#include "cmath"

using namespace std;

int m, n;
int arr[21][21];


//找到现存的  田中最大的数  的下标   若全为0已经采摘完了 返回 -1 -1
int* find_max(int max[2]) {
	int i, j, tmp = -1;
	max[0] = -1;
	max[1] = -1;
	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			if (arr[i][j] != 0 && tmp < arr[i][j])
			{
				max[0] = i;
				max[1] = j;
				tmp = arr[i][j];
			}
		}
	}
	//cout << "tmp = " << tmp << "; i=" << max[0] << "; j=" << max[1] << "; arr[i][j] = " << arr[max[0]][max[1]] <<endl;
	return max;
}


int main() {
	//<数据输入>
	int k, count=0, next_step; cin >> m >> n >> k;
	//  时间小于2  都 不够进田  出田；  采摘数 则为  0
	if (k < 2) { cout << "0" << endl;return 0;}
	int i, j;
	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
		}
	}
	//</数据输入>

	//c_x, c_y 当前所在的地点     is_first  如果为第一次  x坐标直接转移到相应的x
	int c_x=0, c_y=0, is_first = 1;
	k -= 2;//进入农田了  然后出农田时间
	int* a_tmp = new int[2]; //记录找到的最大值的  下标
	while (1) {
		a_tmp = find_max(a_tmp);
		if (a_tmp[0] == -1 || a_tmp[1] == -1) break;//没有东西可以摘了
		if (is_first) { c_x = a_tmp[1];is_first = 0;}
		//cout << "start x=" << c_x << ";y = " << c_y << endl;
		next_step = abs(c_x - a_tmp[1]) + abs(c_y - a_tmp[0]) + 1;//采摘下一次的地方 需要的时间
		//cout << "need step = " << next_step << ";now time=" << k << endl;
		if ((next_step + a_tmp[1]) > k) {     //采摘时间 + 回去时间 大于了剩余的时间不能继续了
			break;
		}
		else {//继续 //到下一次
			count += arr[a_tmp[0]][a_tmp[1]];  //采摘总数 ++
			arr[a_tmp[0]][a_tmp[1]] = 0;       //采摘完成
			k -= next_step;						//时间减少
		}
	}
	cout << count << endl;



	return 0;
}
