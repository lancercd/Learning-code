#include "iostream"
#include "algorithm"
#include "cstdbool"
#include "cstring"
#include "map"

using namespace std;

const int MAXN = 1e4 + 10;

int main() {
    map<char, bool> table;
    char str1[MAXN], str2[MAXN], tmp;
    cin >> str1 >> str2;

    for(int i=0; i<strlen(str1); ++i)
    {
        table[str1[i]] = 1;
    }
    for(int i=0; i<strlen(str2); ++i)
    {
        if(table[str2[i]]){
            cout << 'Y';
        }else{
            cout << 'N';
        }
    }

    return 0;
}
