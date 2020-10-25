#include "iostream"
#include "algorithm"
#include "vector"
#include "cmath"

using namespace std;
const int MAXTABLE = 1e7 + 10;
const int MAXN = 2e5 + 10;

bool table[MAXTABLE] = {0};
int arr[MAXN] = {0};
int ele[3] = {2,3,5};
int ans_table[6] = {0};
int N;




int main() {
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    int i=0;
    cin >> N;
    int MAXLEN = -1, tmp = 0;
    for(i = 0;  i < N; ++i){
        cin >> tmp;
        table[tmp] = true;
        if(tmp > MAXLEN) MAXLEN = tmp;
    }
    for(i=0; i<3; ++i)
    {
        int flag = 1;
        int mul = 1;
        while(mul <= MAXLEN){
            mul = ele[i] * flag++;
            if(mul <= MAXLEN && table[mul]){
                ++ans_table[ele[i]];
            }
        }

    }
    int ans = *max_element(ans_table, ans_table + 6);


    //素数 判断



    if(table[1]) ++ans;
    cout << ans << endl;

    return 0;
}



int is_prime(int num)
{
	if (num < 2) return 0;
	if (num == 3 || num == 2) return 1;
	if (num % 6 != 1 && num % 6 != 5) return 0;
	int sq = (int)sqrt(num);
	for (int i = 5; i <= sq; i += 6) {
		if (num % i == 0 || num % (i + 2) == 0) return 0;
	}
	return 1;
}
