#include "iostream"
#include "algorithm"
#include "vector"
#include "string"

using namespace std;

string str1, str2;

void deal(string str, int& a, int&b, int&c){
    a = (str[0] - '0') * 10 + (str[1] - '0');
    b = (str[3] - '0') * 10 + (str[4] - '0');
    c = (str[6] - '0') * 10 + (str[7] - '0');

}

int main() {
    cin >> str1 >> str2;
    int s1,s2,s3;
    int t1,t2,t3;

    deal(str1, s1, s2, s3);
    deal(str1, t1, t2, t3);

    int res1 = s3 + s2*60 + s1 * 60 * 60;
    int res2 = t3 + t2*60 + t1 * 60 * 60;

    if(res2 > res1){
        cout << res1 - res2;
    }else{

        cout << res2 + (60 * 60 * 60 - res1);
    }

    return 0;
}
