#include "iostream"
#include "algorithm"
#include "cstring"
using namespace std;
char str[255];

int k;
void move(int index){
    while(str[index] !='\0'){
        str[index] = str[index + 1];
        ++index;
    }
}
int main() {
    cin >> str >> k;
    int a = 0, time = 0;
    while(time < k && str[a + 1] != '\0'){
        if(str[a] > str[a + 1]){
            move(a);
            ++time ;
            if(a>0) --a;
        }else{
            ++a;
        }

    }
    if(time >= k){ cout << atoi(str) << endl; }
    else{
        int len = strlen(str);
        while(time < k && len > 0){
            --len;
            str[len] = '\0';
            ++time;
        }
        cout << atoi(str) << endl;
    }



    return 0;
}
