#include "iostream"
#include "algorithm"
using namespace std;
const int MAXN = 5e3 + 5;
pair<int , int > arr[MAXN];
int N,M, a, b;
unsigned long long price = 0;

int main(int argc, char const *argv[]) {
    cin >> N >> M;
    for(int i=0; i<M; ++i) {cin >> a >> b;  arr[i].first = a;  arr[i].second = b;}
    sort(arr, arr + M);

    for(int i=0; i<M; ++i)
    {
        if(arr[i].second > N){ price += N * arr[i].first; break; }
        else { price += arr[i].second * arr[i].first; N -= arr[i].second;}
    }
    cout << price;
    return 0;
}
