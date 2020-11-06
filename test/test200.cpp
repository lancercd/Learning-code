#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        if(height.size()<=1)
            return 0;
        for(int i=1;  i<height.size(); ++i)
        {
            int  left_max = find_left_max(i, height);
            int  right_max = find_right_max(i, height);
            int num = min(left_max, right_max);
            int res=num-height[i];
            if(res>0)
            {
                ans+=res;
            }
        }

        return ans;
    }

    int find_left_max(int index, vector<int>& height){
        int Max = 0;
        for(int i=0;i<index;i++)
        {
            if(height[i]>Max)
            Max=height[i];
        }
        return Max;
    }
    int find_right_max(int index, vector<int>& height){
        int Max = 0;
        for(int i=index+1;i<height.size();i++)
        {
            if(height[i]>Max)
            Max=height[i];
        }
        return Max;
    }
};


int main() {
    vector<int> arr = {4,2,0,3,2,5};
    Solution* solu = new Solution();

    cout<<solu->trap(arr);
    return 0;
}
