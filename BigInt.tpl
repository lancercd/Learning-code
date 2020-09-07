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
    int get_length(char target[]);


    /**
     * 长度比较
     * @param  target char[] 被比较的char数组
     * @return int           this长度大于被比较长度 返回1   小于返回-1  等于返回0
     */
    int cmp_length(char target[]);

    /**
     * 比较否与目标数相等
     * @param  target char[] || self 被比较数 或 自身对象
     * @return bool
     */
    bool is_equal(char target[]);
    bool is_equal(const BigUnsignedInt target);


    /**
     * 相加
     * @param current 当前的数
     * @param target  需要相加的数
     */
    void plus(BigUnsignedInt& current, const BigUnsignedInt target);


    /**
     * 数字转换成 "char"   (此 char 存数值  非字符)
     * @param str         char[] 转换后的"char" 赋值到 str
     * @param len         int&   转换后的"char" 的长度 赋值到 len
     * @param target_num  int    需要转换的数
     * @return void
     */
    void num_to_char(char str[], int& len, int target_num);

    /**
     * 与int类型做大小比较
     * @param  num int 比较数
     * @return bool
     */
    bool operator < (const int num);

    /**
     * 与int类型做大小比较
     * @param  num int 比较数
     * @return bool
     */
    bool operator > (const int num);

    /**
     * 做等于比较
     * @param  int self 比较数
     * @return bool
     */
    bool operator == (const int num);
    bool operator == (const BigUnsignedInt right);

    /**
     * 与self类型赋值
     * @param  right self 相加的对象
     * @return self
     */
    BigUnsignedInt operator = (const BigUnsignedInt right);

    /**
     * 与self类型相加
     * @param  right self 相加的对象
     * @return self
     */
    BigUnsignedInt operator + (const BigUnsignedInt right);

    /**
     * 与self类型相加
     * @param  right self 相加的对象
     * @return self
     */
    BigUnsignedInt operator += (const BigUnsignedInt right);


    /**
     * 输入输出
     */
    friend ostream& operator << (ostream&, const BigUnsignedInt self);
    friend istream& operator >> (istream&, BigUnsignedInt& self);

}BigUnsignedInt;


int BigUnsignedInt::get_length(char target[]) {
    int length = MAXBIT;
    while (length > 0){
        if(target[length-1] != '\0'){
            break;
        }
        --length;
    }
    return length;
}
int BigUnsignedInt::cmp_length(char target[]) {
    int length = this->get_length(target);
    if (this->length > length)
        return 1;
    else if (this->length < length)
        return -1;
    else
        return 0;
}
bool BigUnsignedInt::is_equal(char target[]) {
    if (this->cmp_length(target) != 0) return 0;  //比较位数是否相等
    for (int i = 0; i < this->length; ++i) {
        if (this->num[i] != target[i]) {
            return 0;
        }
    }
    return 1;
}
bool BigUnsignedInt::is_equal(const BigUnsignedInt target) {
    if (this->length != target.length) return 0;  //比较位数是否相等
    for (int i = 0; i < this->length; ++i) {
        if (this->num[i] != target.num[i]) {
            return 0;
        }
    }
    return 1;
}
void plus(BigUnsignedInt& current, const BigUnsignedInt target){
    int len = target.length; if (len < current.length) len = current.length; //选取长度最大的  length最大的
    for (int i = 0; i < len; ++i) {             //相同length位 相加     不会超出char(-128 ~ 127)  最大为 9 + 9 = 18
        current.num[i] += target.num[i];
    }
    int index = 0, pre = 0;                   //index: 当前在哪一位   pre:进多少
    while (index < len) {                     //跳出循环时  index == len
        current.num[index] += pre;              //当前位加上一位进上来的
        if (current.num[index] < 10) {          //如果没有超出10  则不用进位  pre = 0; continue;
            ++index;
            pre = 0;
            continue;
        }
        pre = current.num[index] / 10;          //提取 需要进位的数
        current.num[index] %= 10;               //保存当前 个位

        ++index;
        if (MAXBIT == index) {                //检测是否超出最大位数   超出了请修改 MAXBIT
            std::cout << "***** BigUnsignedInt length overflow !!! *****" << std::endl;
            break;
        }
    }

    if (pre != 0 && MAXBIT > index) {         //检测len位是否还需要进位  (在不超出的情况下)
        current.num[index] = pre;
        ++index;
    }
    current.length = index;                     //修改为新的length长度
}
void BigUnsignedInt::num_to_char(char str[], int& len, int target_num) {
    sprintf(str, "%d", target_num);
    len = 0;
    while (str[len] != '\0') {
        str[len] -= '0';
        ++len;
    }
}
bool BigUnsignedInt::operator < (const int num) {
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
bool BigUnsignedInt::operator > (const int num) {
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
bool BigUnsignedInt::operator == (const int num) {
    char str[MAXBIT] = { 0 };
    int str_len = 0;
    num_to_char(str, str_len, num);
    return this->is_equal(str);
}
bool BigUnsignedInt::operator == (const BigUnsignedInt right) {
    return this->is_equal(right);
}
BigUnsignedInt BigUnsignedInt::operator = (const BigUnsignedInt right) {
    // fill(this->num, this->num + this->length, 0);
    for (int i = 0; i < this->length; ++i) this->num[i] = 0;
    this->length = right.length;
    for (int i = 0; i < right.length; ++i)
    {
        this->num[i] = right.num[i];
    }
    return *this;
}
BigUnsignedInt BigUnsignedInt::operator + (const BigUnsignedInt right) {
    BigUnsignedInt tmp = *this;
    this->plus(tmp, right);
    return tmp;
}

BigUnsignedInt BigUnsignedInt::operator += (const BigUnsignedInt right) {
    this->plus(*this, right);
    return *this;
}

ostream& operator << (ostream&, const BigUnsignedInt self) {
    for (int i = self.length - 1; i > -1; --i) {
        cout << (int)self.num[i];
    }
    return cout;
}

istream& operator >> (istream&, BigUnsignedInt& self) {
    char num[MAXBIT];
    cin >> num;
    int length = 0;
    while (num[length] != '\0') ++length;
    int i = 0, j = length - 1;
    while (i < length) {
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
