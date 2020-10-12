#include "iostream"
#include "algorithm"
#include "cstdlib"

using namespace std;

const int LEN = 5;

void change(int a[LEN][LEN])
{
    int b[LEN][LEN];
    int x,y;
    for(x=0;x<LEN;x++)
    {
        for(y=0;y<LEN;y++)
        {
            a[x][y]=a[y][x];
        }
    }
}

int main()
{
	int i,j;
    int a[LEN][LEN]={0};
    for(i=0;i<LEN;i++)
    {
        for(j=0;j<LEN;j++)
        {
            a[i][j] = rand() % 10;
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    change(a);
    for(i=0;i<LEN;i++)
    {
        for(j=0;j<LEN;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
