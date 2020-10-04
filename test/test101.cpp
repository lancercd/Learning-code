#include "iostream"
#include "algorithm"

using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 10;
const int MAXTREE = 1e6 + 10;
int arr[MAXN] = {0};
ll tree[MAXTREE] = {0};

int N, M;

void build_tree(int node, int start, int end){
    if(start == end){
        tree[node] = arr[start];
    }else{
        int mid = (start + end) >> 1;
        int left_node  = (node << 1) + 1;
        int right_node = (node << 1) + 2;
        build_tree(left_node, start, mid);
        build_tree(right_node, mid + 1, end);
        tree[node] = tree[left_node] + tree[right_node];
    }
}


void tree_plus(int node, int start, int end, int val){

}

ll sum(int node, int start, int end, int L, int R){
    cout << "L:" << start << "  R" << end << endl;
    if(start == end){
        return tree[node];
    }
    if((end < L) || (start > R)){
        return 0;
    }

    if(L <= start && R >= end){
        return tree[node];
    }


    int mid = (start + end) >> 1;
    int left_node  = (node << 1) + 1;
    int right_node = (node << 1) + 2;

    return sum(left_node, start, mid, L, R) + sum(right_node, mid + 1, end, L, R);


    return 0;
}


void show(){
    cout << "show" << endl;
    for(int i=0; i<9; ++i)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
}

int main() {
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    int op, x, y, k;
    cin >> N >> M;
    for(int i=0; i<N; ++i)
    {
        cin >> arr[i];
    }
    build_tree(0, 0, N - 1);
    show();
    cout << sum(0, 0, 9, 1, N - 2) << endl;
    // while(M--)
    // {
    //     cin >> op >> x >> y;
    //     if(op == 1){
    //         cin >> k;
    //         tree_plus(0, x, y, k);
    //     }else{
    //         cout << sum(0, 0, 14, x, y) << endl;
    //
    //     }
    // }

    return 0;
}
