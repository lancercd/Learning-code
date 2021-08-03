#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> arr, int k) {
        vector<int> res;
        if(k == 0) return res;

        this->quick(arr, 0, arr.size() - 1, k);


        return vector<int>({arr.begin(), arr.begin()+k});
    }

    void quick(vector<int> arr, int L, int R, int k){
        if(L >= R) return ;
        int l = L, r = R;
        int flag = arr[r];
        while(l < r){

            while(l < r && arr[l] < flag) {++l;}
            if(l < r) arr[r--] = arr[l];
            while(l < r && arr[r] > flag) {--r;}
            if(l < r) arr[l++] = arr[r];
        }
        arr[l] = flag;

        if(k > l) this->quick(arr, l + 1, R, k);
        this->quick(arr, L, l - 1, k);
    }
};
int main() {

    return 0;
}
