#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

const int MAXN = 1e6 + 2;

char arr[MAXN];


int calc(int L, int R, int len) {

    int ans = 0;

    int l, r;
    int flag = 0;

    while (1) {
        if (R == len) return len - 1;
        l = L; r = R;
        flag = 0;
        while (arr[l] == arr[r] && l > -1) {
            --l;  ++r;
            if (r >= len) {
                flag = 1;

            }
            if (flag == 1) {
                ++ans;
                r = l;
            }
        }

        if (l == -1) return ans - 1;

        if (L == R) ++R;
        else ++L;

    }
}

int main() {
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);

    cin >> arr;

    int len = 0;
    while (arr[len] != '\0') ++len;

    int R = len / 2;
    int L = ((len % 2) == 0) ? R - 1 : R;

    cout << calc(L, R, len) << endl;

    return 0;
}
