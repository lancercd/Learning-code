#include "iostream"
#include "algorithm"
#include "vector"

typedef unsigned long long ll;
using namespace std;
char str[14];

void read(ll& pre, ll& end, char& ch1, char& ch2){
    int index = 0;
    while(1){
        pre += str[index++] - '0';
        if(str[index] < '0' || str[index] > '9') break;
        pre *= 10;
    }
    ch1 = str[index];
    while(1){
        if(str[index++] == '=') break;
    }
    ch2 = str[++index];
}

int main() {
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> str;
    ll pre = 0;
    ll end = 0;
    char ch1, ch2;
    double ans = 0;
    read(pre, end, ch1, ch2);

    switch (ch1) {
        case 'G':
            pre *= 1024 * 1024 * 1024;
            break;
        case 'M':
            pre *= 1024 * 1024;
            break;
        case 'K':
            pre *= 1024;
            break;
    }
    cout << "pre" << pre << endl;
    switch (ch2) {
        case 'G':
            cout << pre / (1024 * 1024 * 1024) << endl;
            return 0;
        case 'M':
            cout << pre / (1024 * 1024) << endl;
            return 0;
        case 'K':
            cout << pre / (1024) << endl;
            return 0;
    }




    // cout << "pre:" << pre << " ch1:" << ch1 << " ch2:" << ch2 << " end:" << end << endl;
    return 0;
}
