#include "iostream"
#include "queue"

using namespace std;

int main(){
    queue<string> str;
    str.push("1");
    str.push("2");
    str.push("3");
    str.push("4");
    while(!str.empty())
    {
        cout << str.front() << endl;
        str.pop();
    }
    return 0;
}
