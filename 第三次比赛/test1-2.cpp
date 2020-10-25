#include "iostream"
#include "algorithm"
#include "cmath"


using namespace std;
const int MAXN = 1e5 + 3;
int M, N;
int arr[MAXN] = {0};

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

int main() {
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> N >> M;
    int tmp;
    for(int i=0; i<N; ++i){
        cin >> tmp;
        arr[i] = tmp;
    }
    sort(arr, arr + N);
    for(int i=0; i<N; ++i)
    {
        for(int j=i + 1; j < N; ++j)
        {
            if(is_prime(arr[i] + arr[j])){
                cout << arr[i] + arr[j] << endl;
                return 0;
            }
        }
    }

    return 0;
}
