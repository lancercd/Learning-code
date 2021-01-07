#include "iostream"
#include "algorithm"
#include "queue"
using namespace std;

int N, M, K;
queue<int> male;
queue<int> female;

int main() {
    cin >> N >> M >> K;
    for(int i=1; i<= N; ++i) male.push(i);
    for(int i=1; i<= M; ++i) female.push(i);

    while(K--){
        int m = male.front(); male.pop();
        int f = female.front(); female.pop();
        cout << m << " " << f << endl;
        male.push(m);
        female.push(m);

    }
    return 0;
}
