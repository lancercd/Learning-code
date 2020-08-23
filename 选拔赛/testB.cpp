#include "iostream"
#include "algorithm"

using namespace std;

const int MAXN = 24;
int arr[MAXN];
void dfs(int count){
    if(count == N){

    }else{
        for(int i=0; i<N; ++i){
            if(used[i]) continue;
            int flag = true;
            for(int j=0; j<count; ++j){
                if(abs(j - count) == abs(result[j] - (i + 1))){ flag=false;break;}
                // if(abs(i + 1 - result[j]) == abs(j - count))  {flag = false;break;}
            }
            if(flag){
                used[i] = 1;
                result[count] = i + 1;
                dfs( count + 1 );
                used[i] = 0;
            }
        }
    }
}
int main(int argc, char const* argv[]) {
    int M, N; cin >> M; for(int i=0; i< M-1; ++i) cin >> arr[i];
    cin >> N;
    dfs(0);

    return 0;
}
