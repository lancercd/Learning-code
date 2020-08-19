#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll nums[1023] = {0}, ans;
int _i = 0;
void dfs(ll num)
{

    if(num > 1e9 || _i == 1023) return;
    if(num != 0){
        nums[_i++] = num;
    }
    dfs(num * 10 + 4);
    dfs(num * 10 + 7);
}

int main() {
    ios::sync_with_stdio(0);
    int l,r; cin >> l >> r;
    dfs(0);
    nums[1022] = 4444444444;
    sort(nums, nums + 1023);

    int cur = l-1;
    for(int i=0; i < 1023; ++i){
        if(l > nums[i]) continue;
        if(nums[i] > r) { ans += (r - cur) * nums[i];break;}
        ans += (nums[i] - cur) * nums[i];

        cur = nums[i];
    }
    cout << ans << endl;

    return 0;
}
