#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#define VERTICES 6
#define HEADER 6

void init(int parent[]){
    for(int i=0; i<VERTICES; ++i) parent[i] = -1;
}
int find_root(int parent[], int target){
    int root = target;
    while(parent[root] != -1){
        root = parent[root];
    }
    return root;
}

bool union_vertices(int parent[], int left, int right){
    int left_root = find_root(parent, left);
    int right_root = find_root(parent, right);
    if(left_root == right_root){
        return false;
    }else{
        parent[left_root] = right_root;
    }
    return true;
}

int main(){
    int parent[VERTICES] = {0};
    int eg[HEADER][2] = {
        {0, 1}, {1, 3}, {1, 2}, {3, 4}, {2, 5}, {2, 4}
    };
    init(parent);

    bool flag = false;
    for(int i=0; i<HEADER; ++i)
    {
        if(!union_vertices(parent, eg[i][0], eg[i][1])){
            flag = true;
            break;
        }
    }
    flag? printf("have\n"): printf("not have\n");


    return 0;
}
