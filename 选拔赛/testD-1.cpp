#include "iostream"
#include "algorithm"
#include "climits"
using namespace std;

int main(int argc, char const* argv[]) {
    int M, N, a, b, step1, step2, ans; cin >> M >> N; ans = a = b = step1 = step2 = INT_MAX;
    if (N > M) M = N + (N - M);
    if (N == M) {
        cout << 0 << endl;
        return 0;
    }
    //走
    a = M - N;

    // 条 + 走
    if (M % N == 0) {
        b = M / N - 1;
        ans = min(a, b);
    }
    else {
        int tmp = (M - N) / N;
        step1 = tmp + 1;
        step1 += (N + N * (tmp + 1)) - M;
        step2 = M - (N + N * tmp);
        step2 += tmp;
        ans = min(a, b);
        ans = min(ans, step1);
        ans = min(ans, step2);
    }

    cout << ans << endl;
    return 0;
}
