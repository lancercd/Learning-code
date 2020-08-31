#include "iostream"
#include "algorithm"
#include "cstdlib"
#include "cstdio"

const int MAXN = 5e3 + 10;
int arr[MAXN] = { 0 }, deep[MAXN] = { 0 };
int eg[MAXN][2] = { 0 };
int N, M, P;

void init() {
    for (int i = 0; i < N; ++i) arr[i] = -1;
}

int find_root(int target) {
    int root = target;
    while (arr[root] != -1) {
        root = arr[root];
    }
    return root;
}

void union_ele(int left, int right)
{
    int left_root = find_root(left);
    int right_root = find_root(right);
    if (left_root == right_root) return;
    if (deep[left_root] < deep[right_root]) {
        arr[left_root] = right_root;
    }
    else if (deep[left_root] > deep[right_root]) {
        arr[right_root] = left_root;
    }
    else {
        ++deep[right_root];
        arr[left_root] = right_root;
    }
}

int main() {
    int x, y;
    scanf("%d%d%d", &N, &M, &P);
    // init();
    ++N;
    std::fill(arr, arr + N + 5, -1);
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &x, &y);
        union_ele(x, y);
    }
    for (int i = 0; i < P; ++i) {
        scanf("%d%d", &x, &y);
        int x_root = find_root(x);
        int y_root = find_root(y);
        (x_root == y_root) ? printf("Yes\n") : printf("No\n");
    }


    return 0;
}
