// const arr = [4, 1, 9, 1];
const arr = [4, 1, 9, 1, 1, 1, 1, 4, 1, 1, 1];

//https://www.bilibili.com/video/BV1zv411j7QX?p=35
//time: 25:51

function handle(target) {
  const len = target.length;

  let cur = 0,  //当前能到达的位置
      next = 0, //下一次能到达的位置
      step = 0; //用了多少步

  for(let i=0; i<len; ++i){

    if(cur < i){ //当前已经到不了 位置i了
      ++step;
      cur = next;
    }
    next = Math.max(next, i + arr[i]);
  }

  return step;
}


console.log(handle(arr));
