const arr = [1,2,3];


/**
 * 获取数组所有子串  (子序列没有顺序， 子串有顺序)
 *    子串:
 *        [
            [],       [ 3 ],
            [ 2 ],    [ 2, 3 ],
            [ 1 ],    [ 1, 3 ],
            [ 1, 2 ], [ 1, 2, 3 ]
          ]
 * @param  {Array} target   目标数组
 * @param  {Array} ans      记录答案
 * @param  {Array} selected 已选择过的元素数组
 * @param  {int}   index    选择的元素下标
 * @return {Array}          答案结果集
 */
function getAllSubstring (target, ans, selected, index) {
  if(index >= target.length) {
    ans.push([].concat(selected));
    return;
  }

  getAllSubstring(target, ans, selected, index + 1);

  selected.push(target[index]);
  getAllSubstring(target, ans, selected, index + 1);
  selected.pop();

  return ans;
}

console.log(getAllSubstring(arr, [], [], 0));
