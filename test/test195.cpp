#include "iostream"
#include "algorithm"

using namespace std;

int arr[] = {1,2,2,2,4,5,5,6};

//有序数组中 找<=某个数最右边的位置
// <= 某个数的最大值

int binary(int arr[], int len, int target){
  int l = 0, r = len - 1, mid = 0, ans = 0;
  while( l <= r){
    mid = l + ((r - l) >> 1);
    if(arr[mid] > target){
      r = mid - 1;
    }else{
      ans = mid;
      l = mid + 1;
    }
  }

  return ans;
}


int main(){
  int index = binary(arr, sizeof(arr) / 4, 5);
  cout << index << endl;
  return 0;
}
