#include <algorithm>
#include <deque>
#include <iostream>
#include <limits.h>
using namespace std;
typedef long long ll;
const int N = 300000;
deque<pair<int, ll>> q; //双端队列
pair<int, ll> p[N];

int main()
{
    int n, m;
    cin >> n >> m;
    p[0] = {0, 0};
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].second;
        p[i].first = i;                 //编号
        p[i].second += p[i - 1].second; //前缀和
    }
    ll ans = INT_MIN;

    //    for(int i=1;i<=n;i++) cout<<p[i].second<<" "; cout<<endl;
    q.push_back(p[0]);
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && i - q.front().first > m)
        { //维护只包含当前前m个
            q.pop_front();
        }
        ans = max(p[i].second - q.front().second, ans); //更新结果
                                                        //		cout<<ans<<" ";
        while (!q.empty() && q.back().second >= p[i].second)
        { //队尾大于当前sum的全部出队
            q.pop_back();
        }
        q.push_back(p[i]);
    }
    cout << ans << endl;
    return 0;
}
