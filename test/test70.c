#include "stdio.h"
#include "stdlib.h"

#define MAXN 2000010
int arr[MAXN];
int N, M;

int main() {
    scanf("%d%d", &N, &M);
    for(int i=0; i < N; ++i) scanf("%d", arr + i);
    for(int i=0; i < M; ++i){
        int query; scanf("%d", &query);
        printf("%d\n", arr[query - 1]);
    }

    return 0;
}
