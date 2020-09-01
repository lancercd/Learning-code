#include "iostream"
#include "algorithm"

const int MAXN = 1e3 + 10;
int save[MAXN][10];
int arr[10];
int ans[10] = {0};
int N;

int main() {
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    std::cin >> N; for(int i=0; i<7; ++i) std::cin >> arr[i];
    std::sort(arr, arr + 7);
    for(int i=0; i<N; ++i){
        for(int j=0; j<7; ++j){
            std::cin >> save[i][j];
        }
    }
    for(int i=0; i<N; ++i){
        int count = 0;
        for(int n=0; n<7; ++n){

            for(int j=0; j<7; ++j){
                if(save[i][n] == arr[j]){
                    ++count; break;
                }else if(save[i][n] < arr[j]){
                    break;
                }
            }
        }
        count  = 8-count;
        ++ans[count];
    }
    for(int i=1; i<8; ++i){
        std::cout << ans[i] << " ";
    }
    return 0;
}
