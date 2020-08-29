#include "iostream"
#include "algorithm"
/*
    二分查找 测试
 */
using namespace std;
int arr[11] = {0,1,2,4,4,5,6,7,8,9,10};
/**
 * binarySearch 二分查找
 * @param  int left
 * @param  int right
 * @param  int target
 * @return int
 */
int binarySearch(int left, int right, int target){
    while(left < right)
    {
        int mid = (left + right) >> 1;
        if(arr[mid] < target)left = mid + 1;
        else right = mid;
    }
    return left;
}

int main() {
    while(1){
        int target; cin >> target;
        cout << binarySearch(1, 10, target) << endl;
    }
    return 0;
}
