#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

// first val
// second num;

const int MAXN = 51;
pair<int, int> noe;
int n, m;
int aa[MAXN] = {0};
int bb[MAXN] = {0};
int cc[MAXN] = {0};
int a, b, c;

int cnt_time = 0;
int MyfindMax(int* arr){
// void MyfindMax(int* arr, int& person){
    int target = noe.first, num = noe.second;


    //出相同数量的牌
    for(int i=target + 1; i<MAXN; ++i){
        if(arr[i] >= num){
            arr[i] -= num;
            // person -= num;
            noe.first = i;
            noe.second = num;
            cnt_time = 0;
            // cout << "chu:" << i << " " << num << " zhang" << endl;
            return num;
        }
    }

    //出比他数量多的牌
    for(int i=num + 1; i<MAXN; ++i){
        // 从值为0的开始找
        for(int j=0; j<MAXN; ++j){
            if(arr[j] >= i){
                // person -= i;
                arr[j] -= i;
                noe.first = j;
                noe.second = i;
                cnt_time = 0;
                // cout << "chu:" << j << " " << i << " zhang" << endl;
                return i;
            }
        }
    }

    //两次要不起   重新开始
    ++cnt_time;
    if(cnt_time >= 2){
        noe.first = 0;   //初始化牌 0
        noe.second = 1; //1张
    }
    // cout << "guo" << endl;
    return 0;
}

int main() {
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    int tmp = 0;
    cin >> n >> m;
    a = n, b = n, c = n;
    for(int i=0; i<n; ++i){
        cin >> tmp;
        ++aa[tmp];
    }
    for(int i=0; i<n; ++i){
        cin >> tmp;
        ++bb[tmp];
    }
    for(int i=0; i<n; ++i){
        cin >> tmp;
        ++cc[tmp];
    }

    noe.first = 0;  //初始化牌
    noe.second = 1; //1张

    while(!(a==0 || b ==0 || c == 0)){
        a -= MyfindMax(aa);
        b -= MyfindMax(bb);
        c -= MyfindMax(cc);
    }

    cout << (a==0? 1 : (b==0? 2 : 3)) << endl;


    return 0;
}
