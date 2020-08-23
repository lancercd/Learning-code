#include "iostream"
#include "algorithm"

using namespace std;

int main(int argc, char const* argv[]) {
    int T; cin >> T;
    while (T--) {
        int total, woman, man, count2 = 0, i; cin >> total >> man;
        woman = total - man;



        if ((woman) % 2 == 0) {
            count2 += woman / 2;
            for (i = 3; i <= man; i += 2) {
                count2 += i;
            }
            count2 += 1;
            if (man % 2 == 0) count2 += i - 1;
        }
        else {
            count2 += (woman + 1) / 2;

            for (i = 3; i <=man; i += 2) {
                count2 += i;
            }
            if (man % 2 == 0){
                count2 += i - 1;
            }
        }

        // cout << min(count1, count2) << endl;
        cout<< count2 << endl;
    }


    return 0;
}
