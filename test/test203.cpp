#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if(len < 3) return 0;

        int left[len] = {0};
        int right[len] = {0};

        int Max = height[0];
        for(int i=1 ;i<len; ++i){
            Max = max(height[i-1], Max);
            left[i] = Max;
        }

        Max = height[len - 1];
        for(int i=len - 2 ;i > 0; --i){
            Max = max(height[i + 1], Max);
            right[i] = Max;
        }


        int ans = 0;
        --len;
        for(int i=1; i<len; ++i){

            int cnt = min(right[i], left[i]) - height[i];
            if(cnt > 0){
                ans += cnt;
            }
        }

        return ans;
    }

};
int main() {
    vector<int> arr = {9,0,1};
    Solution* solu = new Solution();
    int ans = solu->trap(arr);
    cout << ans << endl;
    return 0;
}
