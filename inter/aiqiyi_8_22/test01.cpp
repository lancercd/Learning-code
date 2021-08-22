#include "iostream"
#include "algorithm"
#include "vector"
#include "string"

using namespace std;
const int MAXN = 1e7 + 10;
char arr[MAXN];
int m, n;

int main() {
    freopen("../../data/in.txt", "r", stdin); freopen("../../data/out.txt", "w", stdout);
    scanf("%s%d,%d", arr, &m, &n);

    int len = 0;
    while(arr[len] != '\0') ++ len;
    arr[--len] = '\0';

    if(len < 2) { cout << arr; return 0; }

    int index = 0;
    while(index < m) cout << arr[index++];
    index = n;
    while(index >= m) cout << arr[index--];
    index = n + 1;
    while(index < len) cout << arr[index++];


    return 0;
}
