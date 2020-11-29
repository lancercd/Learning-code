#include "iostream"
#include "algorithm"
#include "vector"
#include "iomanip"

using namespace std;

typedef struct stu{
    char id[10];
    int score1;
    int score2;
    int score3;
    double avg;
}Node;

bool cmp(Node a, Node b){
    return a.avg > b.avg;
}

const int MAXN = 510;
int N;
Node arr[MAXN];

int main() {
    // freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> N;
    for(int i=0; i<N; ++i)
    {
        cin >> arr[i].id >> arr[i].score1 >> arr[i].score2 >> arr[i].score3;
        arr[i].avg = arr[i].score1 * 0.4 + arr[i].score2 * 0.35 + arr[i].score3 * 0.25;
    }

    sort(arr, arr + N, cmp);

    for(int i=0; i<3; ++i)
    {
        cout << arr[i].id << " " << setiosflags(ios::fixed) << setprecision(1) << arr[i].avg << endl;
    }

    return 0;
}
