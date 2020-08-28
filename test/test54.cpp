#include "iostream"
#include "algorithm"
#include "cstdio"

using namespace std;
int N, R;

int arr[30] = { 0 };

void dfs(int count) {
    if (count == R) {
        for (int i = 0; i < R; ++i) {
            printf("%3d", arr[i]);
        }
        printf("\n");
    }
    else {
        int i = 0;
        if (count != 0) i = arr[count - 1];
        for (; i < N; ++i) {
            arr[count] = i + 1;
            dfs(count + 1);

        }
    }


}

int main() {
    scanf("%d%d", &N, &R);
    // N = 5; R = 3;
    dfs(0);
    return 0;
}
