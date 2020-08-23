#include "iostream"
#include "algorithm"
#include "string"
using namespace std;

int main(int argc, char const *argv[]) {
    string str; cin >> str; int count = 0;
    for(unsigned int i=2; i<str.size(); ++i){
        if(str[i-2] == 'o' && str[i - 1] == 'r' && str[i] == 'a') ++count;
    }
    count ? cout << count: cout << "yare yare daze" << endl;
    return 0;
}
