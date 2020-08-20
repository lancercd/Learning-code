#include "iostream"
#include "algorithm"
// if(abs(i + 1 - result[j]) == abs(j - count))  {flag = false;break;}
using namespace std;
const int LEN = 14;
bool used[LEN] = {0};
int result[LEN] = {0};
int cnt = 0, N;

void dfs(int count){
    if(count == N){
        ++cnt;
        if(cnt < 4){
            for(int i=0; i<N; ++i){
                cout << result[i] << " ";
            }
            cout << endl;
        }
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
int main(int argc, char const *argv[]) {
    cin >> N;

    dfs(0);
    cout << cnt << endl;
    return 0;
}
