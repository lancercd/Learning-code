#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

int N;
const int MAXN = 110;
int arr[MAXN] = {0};

int main() {
    int ans = 1;
    cin >> N;
    for(int i=0; i<N; ++i)
    {
        cin >> arr[i];
    }

    for(int i=0;i < N; ++i)
    {
        for(int j=i + 1; j<N; ++j)
        {
            ans *= __gcd(arr[i], arr[j]);
        }
    }

    cout << ans;

    return 0;
}
