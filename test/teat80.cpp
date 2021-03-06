#include "iostream"
#include "algorithm"
#include "cstdio"

using namespace std;
// #define MAXBIT 520
const int MAXBIT = 520;

/**
 * Author       lancercd 1311282756@qq.com
 * Description  自定义位数高精度    使用时先 define MAXNBIT 最多存储位数
 */
typedef struct BigUnsignedInt {

    /**
     * 长度  位  (当前存放的数 包含多少位)
     */
    int length = 0;

    /**
     * 存储的数  char中每一个元素代表抽象成一个bit位 (此 char 存数值  非字符   每一位 -'0')
     */
    char num[MAXBIT] = { 0 };

    /**
     * 获取长度 位
     * @param  target char[]
     * @return int
     */
    int get_length(char target[]) {     //<----------------这个函数有问题
        int length = 0;
        while (target[length] != '\0') ++length;   // <--------这里有问题  保存0时  0对应 \0
        return length;
    }

    /**
     * 长度比较
     * @param  target char[] 被比较的char数组
     * @return int           this长度大于被比较长度 返回1   小于返回-1  等于返回0
     */
    int cmp_length(char target[]) {
        int length = this->get_length(target);
        if (this->length > length)
            return 1;
        else if (this->length < length)
            return -1;
        else
            return 0;
    }

    /**
     * 比较this是否与目标数相等
     * @param  target char[] || self 被比较数 或 自身对象
     * @return bool
     */
    bool is_equal(char target[]) {
        if (this->cmp_length(target) != 0) return 0;  //比较位数是否相等
        for (int i = 0; i < this->length; ++i) {
            if (this->num[i] != target[i]) {
                return 0;
            }
        }
        return 1;
    }
    bool is_equal(const BigUnsignedInt target) {
        if (this->length != target.length) return 0;  //比较位数是否相等
        for (int i = 0; i < this->length; ++i) {
            if (this->num[i] != target.num[i]) {
                return 0;
            }
        }
        return 1;
    }


    /**
     * 数字转换成 "char"   (此 char 存数值  非字符)
     * @param str         char[] 转换后的"char" 赋值到 str
     * @param len         int&   转换后的"char" 的长度 赋值到 len
     * @param target_num  int    需要转换的数
     * @return void
     */
    void num_to_char(char str[], int& len, int target_num) {
        sprintf(str, "%d", target_num);
        len = 0;
        while (str[len] != '\0') {
            str[len] -= '0';
            ++len;
        }
    }

    /**
     * 与int类型做大小比较
     * @param  num int 比较数
     * @return bool
     */
    bool operator < (const int num) {
        char str[MAXBIT] = { 0 };
        int str_len = 0;
        num_to_char(str, str_len, num);
        if (this->length > str_len) return 0;
        if (this->length < str_len) return 1;

        if (this->is_equal(str)) return 0;

        for (int i = str_len - 1; i > -1; --i) {
            if (this->num[i] > str[i]) return 0;
        }
        return 1;
    }

    /**
     * 与int类型做大小比较
     * @param  num int 比较数
     * @return bool
     */
    bool operator > (const int num) {
        char str[MAXBIT] = { 0 };
        int str_len = 0;
        num_to_char(str, str_len, num);
        if (this->length > str_len) return 1;
        if (this->length < str_len) return 0;

        if (this->is_equal(str)) return 0;

        for (int i = str_len - 1; i > -1; --i) {
            if (this->num[i] < str[i]) return 0;
        }
        return 1;
    }

    /**
     * 与int类型做等于比较
     * @param  num int 比较数
     * @return bool
     */
    bool operator == (const int num) {
        char str[MAXBIT] = { 0 };
        int str_len = 0;
        num_to_char(str, str_len, num);
        return this->is_equal(str);
    }

    /**
     * 与self类型做等于比较
     * @param  right self 比较的对象
     * @return bool
     */
    bool operator == (const BigUnsignedInt right) {
        return this->is_equal(right);
    }

    /**
     * 与self类型赋值
     * @param  right self 相加的对象
     * @return self
     */
    BigUnsignedInt operator = (const BigUnsignedInt right) {
        // fill(this->num, this->num + this->length, 0);
        for (int i = 0; i < this->length; ++i) this->num[i] = 0;
        this->length = right.length;
        for (int i = 0; i < right.length; ++i)
        {
            this->num[i] = right.num[i];
        }
        return *this;
    }

    /**
     * 与self类型相加
     * @param  right self 相加的对象
     * @return self
     */
    BigUnsignedInt operator + (const BigUnsignedInt right) {
        BigUnsignedInt tmp = *this;                  //零时变量
        int len = right.length; if (len < tmp.length) len = tmp.length; //选取长度最大的  length最大的
        for (int i = 0; i < len; ++i) {             //相同length位 相加     不会超出char(-128 ~ 127)  最大为 9 + 9 = 18
            tmp.num[i] += right.num[i];
        }
        // tmp.length = len;
        int current = 0, pre = 0;                   //current: 当前在哪一位   pre:进多少
        while (current < len) {                     //跳出循环时  current == len
            tmp.num[current] += pre;                //当前位加上一位进上来的
            if (tmp.num[current] < 10) {            //如果没有超出10  则不用进位  pre = 0; continue;
                ++current;
                pre = 0;
                continue;
            }
            pre = tmp.num[current] / 10;            //提取 需要进位的数
            tmp.num[current] %= 10;                 //保存当前 个位

            ++current;
            if (MAXBIT == current) {                //检测是否超出最大位数   超出了请修改 MAXBIT
                std::cout << "***** BigUnsignedInt length overflow !!! *****" << std::endl;
                break;
            }
        }

        if (pre != 0 && MAXBIT > current) {         //检测len位是否还需要进位  (在不超出的情况下)
            tmp.num[current] = pre;
            ++current;
        }
        tmp.length = current;                       //修改为新的length长度

        return tmp;
    }

    /**
     * 与self类型相加
     * @param  right self 相加的对象
     * @return self
     */
    BigUnsignedInt operator += (const BigUnsignedInt right) {
        int len = right.length; if (len < this->length) len = this->length; //选取长度最大的  length最大的
        for (int i = 0; i < len; ++i) {             //相同length位 相加     不会超出char(-128 ~ 127)  最大为 9 + 9 = 18
            this->num[i] += right.num[i];
        }
        // this->length = len;
        int current = 0, pre = 0;                   //current: 当前在哪一位   pre:进多少
        while (current < len) {                     //跳出循环时  current == len
            this->num[current] += pre;              //当前位加上一位进上来的
            if (this->num[current] < 10) {          //如果没有超出10  则不用进位  pre = 0; continue;
                ++current;
                pre = 0;
                continue;
            }
            pre = this->num[current] / 10;          //提取 需要进位的数
            this->num[current] %= 10;               //保存当前 个位

            ++current;
            if (MAXBIT == current) {                //检测是否超出最大位数   超出了请修改 MAXBIT
                std::cout << "***** BigUnsignedInt length overflow !!! *****" << std::endl;
                break;
            }
        }

        if (pre != 0 && MAXBIT > current) {         //检测len位是否还需要进位  (在不超出的情况下)
            this->num[current] = pre;
            ++current;
        }
        this->length = current;                     //修改为新的length长度

        return *this;
    }


    friend ostream& operator << (ostream&, const BigUnsignedInt self) {
        for (int i = self.length - 1; i > -1; --i) {
            cout << (int)self.num[i];
        }
        return cout;
    }

    friend istream& operator >> (istream&, BigUnsignedInt& self) {
        char num[MAXBIT];
        cin >> num;
        int length = 0;
        while (num[length] != '\0') ++length;
        int i = 0, j = length - 1;
        while (i < length) {
            //if(num[i] != '\0') self.num[i] = num[i] - '0';
            self.num[j] = num[i] - '0';
            ++i,--j;
            if (i == MAXBIT) {
                std::cout << "***** BigUnsignedInt input overflow !!! *****" << std::endl;
                break;
            }
        }
        self.length = length;
        return cin;
    }

}BigUnsignedInt;


int M, N, my_time;
BigUnsignedInt arr[4];
int main() {
    cin >> N;M = 1; my_time = N - M + 1;
    arr[0].length = 0;arr[0].num[0] = 0;
    arr[1].length = 1;arr[1].num[0] = 1;
    arr[2].length = 1;arr[2].num[0] = 1;
    arr[3].length = 1;arr[3].num[0] = 2;
    if(my_time < 4){
        cout << arr[my_time] << endl;
        return 0;
    }
    while(my_time-- > 3)
    {
        arr[1] = arr[2];
        arr[2] = arr[3];
        // arr[3] += arr[1];
        arr[3] = arr[3] + arr[1];
    }
    cout << arr[3] << endl;

    return 0;
}
