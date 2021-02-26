#include "iostream"
#include "algorithm"
#include "vector"
#include "map"
#include "string"

using namespace std;
char firstUniqChar(string s) {
    map<char, int> table;
    for(char ch : s)
    {
        ++table[ch];
    }
    for(char ch : s)
    {
        if(table[ch] == 1) return ch;
    }
    return ' ';

}
int main() {
    string str = "abaccdeff";
    cout << firstUniqChar(str) << endl;
    return 0;
}
