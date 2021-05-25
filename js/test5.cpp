#include "iostream"
#include "algorithm"

using namespace std;

bool cmp(int num1, int num2){
  if(num1 < num2) return 1;
  return 0;
}

int main(){
  const int MAXN = 3;
  int arr[MAXN] = {2,5,3};
  sort(arr, arr + 3, cmp);

  for(int i=0; i<MAXN; ++i){
    cout << arr[i] << " ";
  }



  return 0;
}
