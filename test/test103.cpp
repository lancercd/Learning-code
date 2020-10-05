#include "iostream"
#include "algorithm"
#include "utility"

//线段树
//https://www.luogu.com.cn/problem/P4715

using namespace std;
const int MAXN = 128;
pair<int, int> arr[MAXN];
pair<int, int> tree[300];
int N;
int LEN = 1;

void init(){
    while(N--) LEN <<= 1;

    for(int i=0; i<LEN; ++i){
        cin >> arr[i].first;
        arr[i].second = i;
    }
}

inline int getLeft(int node){
    return (node << 1) + 1;
}

inline int getRight(int node){
    return (node << 1) + 2;
}

inline int getMid(int start, int end){
    return (start + end) >> 1;
}

void build_tree(int node, int start, int end){
    if(start == end){
        tree[node] = arr[start];
        return;
    }
    int left_node = getLeft(node);
    int right_node = getRight(node);
    int mid = getMid(start, end);

    build_tree(left_node, start, mid);
    build_tree(right_node, mid + 1, end);

    tree[node] = (tree[left_node] > tree[right_node])? tree[left_node] : tree[right_node];

}

void show(){
    // cout << "show" << endl;
    // for(int i=0; i<20; ++i)
    // {
    //     printf("%2d ", tree[i].first);
    // }
    // cout << endl;
    // for(int i=0; i<20; ++i)
    // {
    //     printf("%2d ", tree[i].second);
    //
    // }
    // cout << endl;
}

int main(){
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> N;
    init();
    build_tree(0, 0, LEN - 1);

    // show();
    int ans = (tree[1] > tree[2])? tree[2].second : tree[1].second;
    cout << ans + 1 << endl;



    return 0;
}
