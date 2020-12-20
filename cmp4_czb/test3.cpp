#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
int N;
// const int MAXN = 5e5 + 10;
typedef struct node{int no,x,y;}Node;
Node arr[500005];

int cmp(Node a, Node b){
    int num1 = a.x * a.y;
    int num2 = b.x * b.y;
    if(num1 > num2) return 1;
    if(num1 == num2){
        if(a.x > b.x) return 1;
        if(a.x == b.x){
            if(a.no < b.no) return 1;
            return 0;
        }
        return 0;
    }
    return 0;
}

int main() {
    cin >> N;
    for(int i=0; i<N; ++i)
    {
        cin >> arr[i].x >> arr[i].y;
        arr[i].no = i + 1;
    }
    sort(arr, arr + N, cmp);
    for(int i=0; i<N; ++i)
    {
        cout << arr[i].no << " ";
    }
    return 0;
}
