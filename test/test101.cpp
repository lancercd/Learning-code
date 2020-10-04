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


void tree_plus(int node, int start, int end, int L, int R, int val){
    if((end < L) || (start > R)) return;

    if((start == end) && (start >= L) && (start <= R)){
        tree[node] += val;
        return;
    }

    int mid = (start + end) >> 1;
    int left_node  = (node << 1) + 1;
    int right_node = (node << 1) + 2;

    tree_plus(left_node, start, mid, L, R, val);
    tree_plus(right_node, mid + 1, end, L, R, val);
    tree[node] = tree[left_node] + tree[right_node];

}

ll query(int node, int start, int end, int L, int R){
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
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    int op, x, y, k;
    cin >> N >> M;
    for(int i=0; i<N; ++i)
    {
        cin >> arr[i];
    }
    build_tree(0, 0, N - 1);
    while(M--)
    {
        cin >> op >> x >> y;
        if(op == 1){
            cin >> k;
            tree_plus(0, 0, N - 1, x - 1, y  -1, k);
        }else{
            cout << query(0, 0, N - 1, x - 1, y - 1) << endl;

        }
    }

    return 0;
}
