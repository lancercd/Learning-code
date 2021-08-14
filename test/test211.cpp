#include "iostream"
#include "algorithm"
#include "cmath"

/**
  题目:
      N个点中  用rest步从start 走到 end有多少种方法
        走到第一个点后 只能往右走
        走到最后一个点 只能往前走
        非第一个点、最后一个点 可以往两边任意走
 */


using namespace std;

int f(const int len, const int end, int cur, int rest) {
  //剩余的步数为 0 判断一下是否走到终点
  if(rest == 0) return (cur == end)? 1 : 0;

  if(abs(cur - end) > rest) return 0;

  //已经在头部了  只能向右走了
  if(cur == 0){
    return f(len, end, cur + 1, rest - 1);
  }

  //已经在末尾了  只能向左走了
  if(cur == len - 1){
    return f(len, end, cur - 1, rest - 1);
  }

  //返回向左走的步数 + 向右走的步数
  return f(len, end, cur - 1, rest - 1) + f(len, end, cur + 1, rest - 1);
}

int main() {

  const int len = 60,
            start = 3,
            end = 2,
            rest = 31;

  int res = f(len, end, start, rest);

  cout << res << endl;

  return 0;
}
