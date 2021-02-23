#include "iostream"
#include "algorithm"
#include "vector"
#include "map"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> table;
        for(int num : nums){
            ++table[num];
        }
        for(auto &ele : table){
            if(ele.second == 1){
                return ele.first;
            }
        }
        return 0;
    }
};


int main() {

    return 0;
}
