#include "iostream"
#include "algorithm"

using namespace std;
typedef struct Node{
    int left;
    int right;
    int is_del;
}Node;
const int MAXN = 1e5 + 10;
Node arr[MAXN];
int N, M;

void insert(int current, int target, int is_right){
    arr[current].is_del = 0;

    if(is_right){
        arr[current].right = arr[target].right;
        arr[current].left = target;
        arr[target].right = current;
        arr[arr[current].right].left = current;
    }else{
        arr[current].right = target;
        arr[current].left = arr[target].left;
        arr[target].left = current;
        arr[arr[current].left].right = current;
    }
}

void init(){
    arr[0].right = 1;
    insert(1, 0, 1);
}


int main() {
    cin >> N;

    for(int i=1; i<N; ++i)
    {
        int target, is_right;
        cin >> target >> is_right;
        insert(i+1, target, is_right);
    }
    cin >> M;
    while(M--)
    {
        int target;
        cin >> target;
        arr[target].is_del = 1;
    }
    int i = arr[0].right;
    while(i){
        if(!arr[i].is_del){
            cout << i << " ";
        }

        i = arr[i].right;
    }

    return 0;
}
