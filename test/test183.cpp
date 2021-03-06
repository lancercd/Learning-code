#include "iostream"
#include "algorithm"

const int MAXN = 1e3 + 10;
int M, N;
int arr[MAXN] = {0};
int node[MAXN] = {0};

void init(int len){
    std::fill(arr, arr + len + 3, 0);
    std::fill(node, node + len + 3, 0);
}

int find_parent(int target){
    if(arr[target]) return find_parent(arr[target]);
    return target;
}

void merge(int left, int right){
    int left_root = find_parent(left);
    int right_root = find_parent(right);
    if(left_root == right_root) return;

    if(node[left_root] > node[right_root]) arr[right_root] = left_root;
    else if(node[left_root] < node[right_root]) arr[left_root] = right_root;
    else{
        arr[left_root] = right_root;
        ++node[right_root];
    }

}

int get_size(){
    int cnt = 0;
    for(int i=1; i<=N; ++i){
        if(arr[i] == 0) ++cnt;
    }
    return cnt - 1;
}


int main() {
    int x, y;
    while(std::cin >> N >> M){
        init(N);
        if(M == 0){
            std::cin >> x;
        }else{
            while(M--){
                std::cin >> x >> y;
                merge(x, y);
            }
        }
        // show();
        std::cout << get_size() << std::endl;
    }

    return 0;
}
