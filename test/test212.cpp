#include "iostream"
#include "algorithm"

using namespace std;

int arr[] = {1,3,5,7,9,11};
int len = sizeof(arr) / 4;
int *tree = NULL;
int tree_len = 0;


/**
 * 计算树状数组的容量
 * @param  arr_len 需要转换的数组的容量
 * @return         树状数组的容量
 */
int calcTreeSize(int arr_len) {
  if(arr_len == 0 || arr_len == 1) return arr_len;
  int h = 1;
  int size = 1;
  while(h < arr_len){
    h <<= 1;
    size += h;
  }
  return size;
}

int buildTree(int target[], int tree[], int start, int end, int node) {
  if(start == end){
    tree[node] = target[start];
    return tree[node];
  }

  int left_node = (node << 1) + 1;
  int right_node = (node << 1) + 2;
  int mid = ((end - start) >> 1) + start;
  int left_sum = buildTree(target, tree, start, mid, left_node);
  int right_sum = buildTree(target, tree, mid + 1, end, right_node);
  tree[node] = left_sum + right_sum;
  return tree[node];
}

int main() {
  tree_len = calcTreeSize(len);

  tree = new int[tree_len];
  fill(tree, tree + tree_len, 0);

  buildTree(arr, tree, 0, len - 1, 0);


  for(int i=0; i<tree_len; ++i){
    cout << tree[i] << " ";
  }


  return 0;
}
