#include "iostream"
#include "algorithm"
#include "cstring"

using namespace std;
#define MaxBit 1100
typedef struct BigInt{
    int bit = 0;
    char num[MaxBit] = {0};
    friend ostream & operator << (ostream &, BigInt Node){
        for(int i=Node.bit - 1; i > -1; --i){
            cout << (int)Node.num[i];
        }
        return cout;
    }

    BigInt operator = (const BigInt right){
        fill(this->num, this->num + this->bit, 0);
        this->bit = right.bit;
        for(int i=0; i<right.bit; ++i)
        {
            this->num[i] = right.num[i];
        }
        return *this;
    }
    BigInt operator + (const BigInt right){
        int len = right.bit; if(len < this->bit) len = this->bit; //选取长度最大的  bit最大的
        for(int i=0; i<len; ++i){   //相同bit位 相加     不会超出char(-128 ~ 127)  最大为 9 + 9 = 18
            this->num[i] += right.num[i];
        }
        // this->bit = len;
        int current = 0,pre = 0;  //current: 当前在哪一位   pre:上一位进制 这一位的数
        while(current < len){ //跳出循环时  current == len
        // while(this->num[current] != 0){
            this->num[current] += pre;  //当前位加上一位进上来的
            if(this->num[current] < 10){ //如果没有超出10  则不用进位  pre = 0; continue;
                ++current;
                pre = 0;
                continue;
            }
            pre = this->num[current] / 10; //提取 需要进位的数
            this->num[current] %= 10;      //保存当前 个位





            ++current;
            if(MaxBit <= current){  //检测是否超出最大位数   超出了请修改 MaxBit
                std::cout << "***** Bigint bit overflow !!! *****" << endl;
                break;
            }
        }

        if(pre != 0 && MaxBit > current){  //检测len位是否还需要进位  (在不超出的情况下)
            this->num[current] = pre;
            ++current;
        }
        this->bit = current; //修改为新的bit长度

        return *this;
    }

}BigInt;
BigInt arr[3];
int N;
int main() {
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> N;
    if(N == 0){cout << 0 << endl; return 0;}
    arr[0].bit = 1; arr[0].num[0] = 1;
    arr[1].bit = 1; arr[1].num[0] = 2;
    arr[2].bit = 1; arr[2].num[0] = 3;

    if(N < 4){
        cout << arr[N-1] << endl; return 0;
    }
    int count = N - 3;
    while(count--){
        arr[0] = arr[1];
        arr[1] = arr[2];
        arr[2] = arr[0] + arr[1];
    }
    cout << arr[2] << endl;
    // cout <<"bit:" <<  arr[2].bit << endl;

    return 0;
}
