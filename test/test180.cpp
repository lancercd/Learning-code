#include "iostream"
#include "algorithm"

using namespace std;
const int MAXN = 5e3 + 2;
int n, m, p;
int arr[MAXN] = {0};


void union_ele(int a, int b)
{
    int pa = a, pb = b;
    while(arr[pa] != -1) pa = arr[pa];
    while(arr[pb] != -1) pb = arr[pb];
    if(pa != pb) arr[pa] = pb;
}


bool find(int a, int b){
    int pa = a, pb = b;
    while(arr[pa] != -1) pa = arr[pa];
    while(arr[pb] != -1) pb = arr[pb];
    if(pa != pb) return false;
    return true;
}

int main(){
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> n >> m >> p;
    fill(arr, arr + n + 1, -1);
    int a, b;
    for(int i=0; i<m; ++i)
    {
        cin >> a >> b;
        union_ele(a, b);
    }
    for(int i=0; i<p; ++i)
    {
        cin >> a >> b;
        cout << (find(a, b)? "Yes" : "No") << endl;
    }

    for(int i=0; i<n; ++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
