#include "iostream"
#include "algorithm"

using namespace std;


int jumpStep(int arr[], const int len) {
  if(arr == NULL || len == 0) return 0;

  int jump = 0;
  int next = 0;
  int cur = 0;

  for(int i=0; i<len; ++i){
    if(cur < i){
      cur = next;
      ++jump;
    }
    next = max(next, i + arr[i]);
  }

  return jump;


}

int main() {
  int arr[] = {2,1,1,1,1};

  cout << jumpStep(arr, sizeof(arr) / 4) << endl;

  return 0;
}
