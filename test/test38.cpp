#include "iostream"
#include "algorithm"
#include "climits"

using namespace std;
const int MAXN = 1e3 + 5;
int arr[MAXN] = {0}, N;
int find_max(){
    int index = 1, Min = INT_MAX;
    for(int i=1 ; i < N; ++i ){
        if(arr[i-1] + arr[i] < Min){
            Min = arr[i-1] + arr[i];
            index = i;
        }
    }
    return index;
}
void move(int index){
    for(int i=index; i<N; ++i){
        arr[i-1] = arr[i];
    }
}
int main(int argc, char const *argv[]) {
    int index, cost = 0, sum; cin >> N; for(int i=0; i<N; ++i) cin >> arr[i];
    while(N > 1){
        index = find_max();
        sum = arr[index] + arr[index - 1];
        arr[index] = sum;
        cost += sum;
        move(index);
        --N;
    }
    cout << cost << endl;
    return 0;
}
