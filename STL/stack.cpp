#include "iostream"
#include "stack"

using namespace std;

int main(){
    stack<string> str;
    str.push("1");
    str.push("2");
    str.push("3");
    while(!str.empty()){
        cout << str.top() << endl;
        str.pop();
    }


    return 0;
}
