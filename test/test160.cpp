#include "iostream"
#include "algorithm"
#include "vector"
#include "stack"

using namespace std;
class CQueue {
    stack<int> front;
    stack<int> end;
public:
    CQueue() {
        while(!front.empty()) front.pop();
        while(!end.empty()) end.pop();
    }

    void appendTail(int value) {
        while(!front.empty()){
            end.push(front.top());
            front.pop();
        }
        end.push(value);
    }

    int deleteHead() {
        while(!end.empty()){
            front.push(end.top());
            end.pop();
        }
        int val = front.top();
        front.pop();
        return val;
    }
};
int main() {
    CQueue* que = new CQueue();
    vector<int> arr;
    que->appendTail(1);
    arr.push_back(que->deleteHead());
    que->appendTail(2);
    que->appendTail(3);
    arr.push_back(que->deleteHead());
    arr.push_back(que->deleteHead());


    for(int i=0; i<arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
