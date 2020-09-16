#include "iostream"
#include "algorithm"
#include "climits"

const int MAXN = 1e3;
int arr[MAXN][MAXN] = {0};
int N;

int main() {
    std::cin >>N;
    N = 4;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            std::cin >> arr[i][j];
        }
    }

    for(int i=0; i<N; ++i)
    {
        int min_1 = INT_MAX, index_j1 = 0, index_i1 = 0;
        for(int j=0; j<N; ++j)  //行找
        {
            if(arr[i][j] < min_1){
                min_1 = arr[i][j];
                index_j1 = j;
                index_i1 = i;
            }
        }
        int min_2 = INT_MAX, index_j2 = 0, index_i2 = 0;
        for(int j=0; j<N; ++j){ //列找
            if(arr[j][index_j1] < min_2){
                min_2 = arr[j][index_j1];
                index_j2 = index_j1;
                index_i2 = j;
            }
        }
        if(index_i1 == index_i2 && index_j1 == index_j2){
            std::cout << arr[index_i1][index_j1] << " ";
        }
    }

    return 0;
}
/**
4
5 3 4 1
9 7 5 3
4 1 2 4
9 6 3 5



 */
