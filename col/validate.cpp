#include "iostream"
#include "algorithm"
#include "vector"
#include "string"
#include "utility"
typedef unsigned int ui;
typedef std::pair<int, int> pii;
typedef std::vector<int> array;

const int
        //基础
        DAY = 30,                   //最大生存天数
        MAXN = 5,                   //地图最大 下标

        //地点
        END = 4,                    //终点  地点
        VILLAGE = 2,                //村庄  地点    例:位于2
        MINE = 3,                   //矿区  地点

        //重量
        MAX_WEIGHT = 1200,          //最大携带重量
        WATER_WEIGHT = 3,           //水重量
        FOOD_WEIGHT = 2,            //食物重量

        //钱
        INIT_MONEY = 1e4,           //初始钱  10000
        WATER_PRICE = 5,            //水价格
        FOOD_PRICE = 10,            //食物价格
        SALARY = 1e3,               //挖矿基础收益

        //config  优化配置  剪枝配置
        MAX_STEP = 20,              //最大步数
        //MIN_STEP = 3;             //最小步数
        MAX_VIEITE_VILLAGE_CNT = 2, //最大经过村庄次数    为2 则不允许在工作途中补给

        //配置结束  为了添加配置的时候输入' , '而特意设置的   (没有实际意义)
        CONST_CONFIG_END = 1;
int Test_ver = 0;


const int weather[50] = { 0,    //初始  占个 0
//1  2  3  4  5  6  7  8  9  10
  2, 2, 1, 3, 1, 2, 3, 1, 2, 2,
  3, 2, 1, 2, 2, 2, 3, 3, 2, 2,
  1, 1, 2, 1, 3, 2, 1, 1, 2, 2,
};
const int consum[3][2] = {
    {5 , 7  },
    {8 , 6  },
    {10, 10 },
};
int map[MAXN + 1][MAXN + 1] = { 0 };


void map_init() {
    map[1][2] = 6;
    map[1][4] = 3;
    map[2][3] = 2; map[3][2] = 2;  //双通路
    map[3][3] = 1;
    map[2][4] = 3;
}

//路径
int way[50] = { 0 };

int work_arr[DAY] = { 0 };



int main() {
    freopen("../data/validate.txt", "w", stdout);
    map_init();

    // todo();

    return 0;
}
