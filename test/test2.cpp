#include "iostream"
#include "vector"
using namespace std;


int main(){
    // int flag=0, a=0, b=0, max=-1;
    // for(int i=1; i<8; ++i)
    // {
    //     scanf("%d %d", &a, &b);
    //     int count = a + b;
    //     if(count > 8 && count > max){
    //         max = count;
    //         flag = i;
    //     }
    // }

    // printf("%d", flag);

    vector<int> n;
    n.push_back(0);
    n[0] = 1;
    n.push_back(0);
    n[1] = 2;
    cout << n[0] << n[1] << endl;

    return 0;
}
