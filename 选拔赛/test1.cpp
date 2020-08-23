#include "iostream"
#include "algorithm"
#include "map"
#include "set"

using namespace std;
map<char, bool> arr;
set<char> se;

int main(int argc, char const* argv[]) {
    int N; cin >> N; char a,b;
    for(int i=0 ;i<N; ++i)
    {
        cin >> a >> b;
        se.insert(a);
        se.insert(b);
        arr[b] = true;
    }
    int flag = 1;

    for(auto ch : se){
        if(arr[ch] == false) {
            flag = 0;
            break;
        }
    }
    cout << flag;

    return 0;
}
// 6
// A B
// B C
// C D
// D E
// E C
// D A
