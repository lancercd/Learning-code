#include <iostream>
#include "list"
using namespace std;

// list 成员函数
// push_back();
// push_front();
// empty();
// front();
// back();
// pop_front();

int main(){

    list<string> lis;
    lis.push_front("lan");
    lis.push_front("cer");
    lis.push_front("cd");
    // cout << lis.back() << endl;
    while(!lis.empty()){
        cout  << lis.front() << endl;
        // cout <<  << endl;
        lis.pop_front();
    }

    return 0;
}
