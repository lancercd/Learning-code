#include "iostream"
#include "algorithm"

#include <math.h>
using namespace std;

int main(){
//     int a = 1;
//     int flag = -1;
//     int n = 2008;
//     long long count = 0;
//     while(1){
//         count = a*n*flag;
//         ++a;
//         --n;
//         flag = -1 * flag;
//
//         if(a == 1004) break;
//     }
// cout << count << endl;


    int x = 13;
    cout << (int)(pow(x, 2010)-pow(x, 2007) + pow(x, 2005) - pow(x, 4) + x -7)%(x-1) << endl;


    return 0;
}
