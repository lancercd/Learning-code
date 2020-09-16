#include "iostream"
#include "algorithm"


const int MAXN = 1e2;
int arr[MAXN][MAXN] = {0};
int ROW;
int COL;


void rot()
{
	int tmp[COL][ROW];
	int dst=ROW-1;

	for(int i=0;i<ROW;i++,dst--)
		for(int j=0;j<COL;j++)
			tmp[j][dst]=arr[i][j];

	for(int i=0;i<COL;i++)
		for(int j=0;j<ROW;j++)
			arr[i][j]=tmp[i][j];
}

int main()
{
    std::cin >> COL >> ROW;

	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COL;j++)
            std::cin >> arr[i][j];
	}

	rot();

	for(int i=0;i<COL;i++)
	{
		for(int j=0;j<ROW;j++)
            std::cout << arr[i][j] << "\t";
		std::cout<<std::endl;
	}

    return 0;
}
/**
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

 */
