#include "iostream"
#include "algorithm"

using namespace std;

const int LEN = 3;
char arr[LEN] = {'a', 'b', 'c'};

void dfs(int index)
{
    if(index == LEN - 1){
        cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
    }
    for(int i=index; i<LEN; ++i)
    {
        // dfs(index + 1);
        swap(arr[i], arr[index]);
        dfs(index + 1);
        swap(arr[i], arr[index]);
    }
}

int main()
{


    dfs(0);
    return 0;
}
