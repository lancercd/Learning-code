#include "iostream"
#include "algorithm"
#include "cstdio"

using namespace std;
int N;
bool used[10] = {0};
int arr[10] = {0};
void dfs(int count){
    if(count == N){
        for(int i=0; i<N; ++i) printf("%5d", arr[i]);
        printf("\n");
    }else{
        for(int i=0; i<N; ++i)
        {
            if(used[i]) continue;
            used[i] = 1;
            arr[count] = i + 1;
            dfs(count + 1);
            used[i] = 0;
        }
    }
}
int main() {
    scanf("%d", &N);
    dfs(0);
    return 0;
}
