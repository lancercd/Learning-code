#include "iostream"
#include "algorithm"

using namespace std;

int E[10];
pair<int , int> arr[20003], tmp_pair;
bool cmp(pair<int , int> a, pair<int , int> b) {
    if(a.second > b.second) return true;
    if(a.second == b.second && a.first < b.first){return true;}
    return false;
}
int main(int argc, char const *argv[]) {
    int n,k,i, tmp_int; cin >> n >> k;

    for(i=0; i<10; ++i){
        cin >> E[i];
    }
    for(i=0; i<n; ++i){
        cin >> tmp_int;
        tmp_pair = pair<int ,int >(i+1, tmp_int);
        arr[i] = tmp_pair;
    }
    sort(arr, arr + n, cmp);


    for(i=0; i<n; ++i){
        arr[i].second += E[i%10];
    }
    sort(arr, arr + n, cmp);
    for(i=0; i<k; ++i){
        cout << arr[i].first << " ";
    }


    return 0;
}
