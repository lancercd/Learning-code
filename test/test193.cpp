#include "iostream"
#include "algorithm"

using namespace std;

int arr[] = {1,2,2,2,4,5,5,6};

//查找某个数 是否存在

int binary(int arr[], int len, int target){
  int l = 0, r = len - 1, mid = 0;
  while(l <= r){
    mid = l + ((r - l) >> 1);
    if(arr[mid] == target) return mid;
    else if(arr[mid] > target){
      r = mid - 1;
    }else if(arr[mid] < target){
      l = mid + 1;
    }
  }

  return -1;
}


int main(){
  int index = binary(arr, 8, 6);
  cout << index << endl;
  return 0;
}
