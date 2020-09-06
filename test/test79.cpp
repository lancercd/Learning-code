#include "iostream"
#include "algorithm"

using namespace std;
typedef long long ll;
int M, N, len, start, is_div = 1;
const int MAXN = 1e3 + 10;
ll up[MAXN] = {0}, down[MAXN] = {0};
void merge_plus(int index, int flag)
{
    if(flag){
        up[index] += up[index - 1] + down[index - 1];
    }else{
        down[index] += down[index - 1] + up[index];
    }
}
int main() {
    cin >> M >> N; ++M, ++N;len = N + 1 / 2 + 1;
    if(M % 2 == 0){
        is_div = 0;
        down[M/2] = 1;
    }else{
        is_div = 1;
        down[M  + 1/2] = 1;
    }
    int i=M;
    for(; i < len; ++i)
    {
        int target = is_div? (i + 1) / 2 : i / 2;
        merge_plus(target, is_div);
        is_div = !is_div;
    }
    int ans = (N%2 == 0)? down[N/2] : up[(N+1)/2];
    cout << ans << endl;
    for(int i=M-1; i<len; ++i)
    {
        cout << up[i] << "\t" ;
    }
    cout << endl;
    for(int i=M-1; i<len; ++i)
    {
        cout << down[i] << "\t" ;
    }

    return 0;
}
