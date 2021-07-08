#include "iostream"
#include "algorithm"
#include "set"
#include "map"
#include "utility"

using namespace std;

int T, N;


int main(){
    cin >> T;
    map<int, string> table;
    string str = table[2];
    set<int> list;
    while(T--){
        cin >> N;
        int tmp = 0;
        for(int i=0; i<N; ++i) cin >> tmp;
        list.insert(tmp);

        cout << list.size() << endl;
        list.clear();
    }
    return 0;
}
