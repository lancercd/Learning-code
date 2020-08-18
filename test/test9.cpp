#include "iostream"
#include "string"
#include "vector"
using namespace std;

int main(){
    string str = "hello";
    vector<char> s;
    // cout << str[str.length()-1] << endl;
    // for(int i=str.length()-1; i >= 0; --i){
        // cout << str[i];
        // s.push_back(str[i]);
    // }
    for(string::iterator it = str.begin(); it!=str.end(); ++it){
        cout << *it << endl;
    }

    return 0;
}
