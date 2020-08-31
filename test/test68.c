#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#define MAXN  1010
int arr[MAXN];
int N, M, x, y;
void init(){
    int len = N + 5; ++N;
    for(int i=0; i < len; ++i)
    {
        arr[i] = -1;
    }
}
int find_root(int target){
    int root = target;
    while(arr[root] != -1){
        root = arr[root];
    }
    return root;
}

void merge(int left, int right){
    int left_root = find_root(left);
    int right_root = find_root(right);
    if(left_root == right_root) return;
    arr[left_root] = right_root;
}
int count_set(){
    int count = 0;
    for(int i=1; i < N; ++i){
        if(arr[i] == -1) ++count;
    }
    return count - 1;
}

int main(){
    while(1){
    // while(scanf("%d%d", &N, &M) != EOF){
        scanf("%d", &N);
        if(N == 0) exit(0);
        scanf("%d", &M);
        init();
        for(int i=0; i<M; ++i){
            scanf("%d%d", &x, &y);
            merge(x, y);
        }
        printf("%d\n", count_set());

    }
    return 0;
}
