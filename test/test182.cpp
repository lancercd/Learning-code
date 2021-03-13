#include "iostream"
#include "algorithm"
#include "vector"
#include "string"

using namespace std;

bool cmp(string a, string b) {
    int lena = a.size();
    int lenb = b.size();
    if (lena < lenb) return true;
    if (lena == lenb) {
        int la = 0;
        while (la < lena) {
            if((a[la] - '0') < (b[la++] - '0')) return true;
        }
    }
    return false;
}


char str[1011];
int main() {
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    vector<string> arr;
    cin >> str;

    int index = 0;
    while(str[index] != '\0' && index < 1011)
    {
        if(str[index] > '0' && str[index] <= '9'){
            char tmp[1011];
            int i = 0;
            tmp[i++] = str[index++];
            while(str[index] >= '0' && str[index] <= '9'){
                tmp[i++] = str[index];
                ++index;
            }
            tmp[i] = '\0';
            string s = tmp;
            arr.push_back(s);
        }else if(str[index] == '0'){
            if(str[index + 1] == '\0'|| (str[index + 1] >= 'a' && str[index + 1] <= 'z')){
                arr.push_back("0");
            }
        }

        ++index;
    }

    sort(arr.begin(), arr.end(), cmp);
    int len = arr.size();
    for(int i=0; i<len; ++i)
    {
        cout << arr[i] << endl;
    }
    return 0;
}
