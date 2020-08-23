#include "iostream"
#include "algorithm"

using namespace std;
typedef long long ull;
const int MAXN = 1e6 + 10;
ull arr[MAXN];

int main(int argc, char const* argv[]) {
    int N, K; cin >> N >> K;
    ull tmp;
    for (int i = 1; i < N; ++i) {
        cin >> tmp;
        arr[i] = tmp + arr[i - 1];
    }
    ull Max = arr[K];
    // for (int i = 1 + K; i < N; ++i) {
    //     plus = arr[i] - arr[i - K];
    //     if (Max < plus) Max = plus;
    // }
    for(int i=2;i<=N-K;i++)
	{
		Max=max(Max,arr[i+K-1]-arr[i-1]);//i->i+k-1
	}
    cout << arr[N-1] - Max << endl;

    return 0;
}
