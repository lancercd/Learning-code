#include "iostream"
#include "algorithm"
#include "stack"
#include "string"
using namespace std;

int main() {
    string str;
    while (cin >> str) {
        stack<char> arr;
        for (unsigned int i = 0; i < str.size(); ++i)
        {
            if (arr.empty()) { arr.push(str[i]); }
            else {
                char top = arr.top();
                if (top == 'o' && str[i] == 'o') {
                    arr.pop();
                    if (!arr.empty() && arr.top() == 'O') arr.pop();
                    else arr.push('O');
                }
                else if (top == 'O' && str[i] == 'O') { arr.pop(); }
                else { arr.push(str[i]); }
            }
        }
        string ans;
        if(arr.size() < 2){
            arr.empty()? cout << endl: cout << arr.top() << endl;
        }else{
            stack<char> tmp;
            while (!arr.empty()) { tmp.push(arr.top()); arr.pop(); }
            while (!tmp.empty()) { ans += tmp.top(); tmp.pop(); }
            cout << ans << endl;
        }
    }
    return 0;
}
