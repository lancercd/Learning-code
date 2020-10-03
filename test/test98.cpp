#include "iostream"
#include "algorithm"

using namespace std;

const int LEN = 6;
const int MAXN =  1000;

int arr[LEN] = {1, 3, 5, 7, 9, 11};
int tree[MAXN] = {0};

void build_tree(int start, int end, int node){
    if(start == end){
        tree[node] = arr[start];
    }else{
        int mid = (start + end) >> 1;
        int left_node = (node << 1) + 1;
        int right_node = (node << 1) + 2;

        build_tree(start, mid, left_node);
        build_tree(mid + 1, end, right_node);
        tree[node] = tree[left_node] + tree[right_node];
    }
}

void update_tree(int node, int start, int end, int idx, int val){

    if(start == end){
        arr[idx] = val;
        tree[node] = val;
    }else{
        int mid = (start + end) >> 1;
        int left_node = (node << 1) + 1;
        int right_node = (node << 1) + 2;

        // 在左边
        if(start <= idx && mid >= idx){
            update_tree(left_node, start, mid, idx, val);
        }else{
        // 在右边
            update_tree(right_node, mid + 1, end, idx, val);
        }
        tree[node] = tree[left_node] + tree[right_node];

    }

}

int query(int node, int start, int end, int L, int R){
    if(end < L || start > R) return 0;

    if((L <= start && R >= end) || (start == end)){
        return tree[node];
    }


    int mid = (start + end) >> 1;
    int left_node  = (node << 1) + 1;
    int right_node = (node << 1) + 2;


    int left_sum  = query(left_node, start, mid, L, R);
    int right_sum = query(right_node, mid+1, end, L, R);

    return left_sum + right_sum;
}



int main() {
    build_tree(0, LEN-1, 0);
    for(int i=0; i<=14; ++i)
    {
        cout << tree[i] << " ";
    }
    update_tree(0, 0, LEN - 1, 4, 6);
    cout << endl;
    for(int i=0; i<=14; ++i)
    {
        cout << tree[i] << " ";
    }

    cout << endl;
     // query(0, 0, LEN - 1, 2, 5);
    cout << "sum:" << query(0, 0, LEN - 1, 2, 5) << endl;


    return 0;
}
