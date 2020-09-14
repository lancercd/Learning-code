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
std::vector< std::vector<int> > path;                                                   //每个方法对应的  路径
std::vector< std::pair<int, int> > used_res;                                            //每个方法对应的  使用资源数
// std::vector< std::string > infos;
//记录当前节点信息  {位置,   {已经使用的水, 已经使用的食物} }
std::pair<int, std::pair<int, int> > pre_used_infos[10];                                //单个方法对应的 节点信息

/*   save_pre_used_infos格式
[
    [
        { ,{ , } },
        { ,{ , } }
    ],
    [
        { ,{ , } },
        { ,{ , } },
        { ,{ , } },
        { ,{ , } }
    ]
]
*/
std::vector< std::vector< std::pair<int, std::pair<int, int> > > > save_pre_used_infos; //每个方案对应的 节点信息
std::vector< std::vector<int > > work_day_info;                                         //每个方案对应的 工作了多少天
std::vector< int > work_days_array;                                                     //每个方案对应的 工作的具体日期
std::vector< std::pair<int, int> > Moneys_;                                              //每个方案对应的 钱 {money, index}
std::vector< std::pair<int, int> > save_validate_money;

// std::pair<int, int> get_begin_resources(){
//
//
//     return {0, 0};
// }

void calculate_money(){
    // Moneys
    ui len = path.size();
    for (ui i = 0; i < len; ++i)
    {
        if(work_days_array[i] != 7) continue;
        int money = 0;
        money += used_res[i].first * WATER_PRICE;
        money += used_res[i].second * FOOD_PRICE;
        // money -= used_res[i].second * FOOD_PRICE;
        // need_water = (MAX_WEIGHT - used_res[i].second * FOOD_WEIGHT) / WATER_WEIGHT;
        // if(need_water < save_pre_used_infos[i][1].second.first){
        //     continue;
        // }

        // used_res[i].first;  水
        // used_res[i].second; 食物

        Moneys_.push_back({money, i});
    }

    sort(Moneys_.begin(), Moneys_.end());
}



// bool my_judege_method(const int water,const int food, pii Node){
    // int left_water = ((MAX_WEIGHT - food * FOOD_WEIGHT) + 1) / WATER_WEIGHT;
    //
    // if(left_water > Node.first) return true;
    // return false;
    // return true;
// }


void map_init() {
    map[1][2] = 6;
    map[1][4] = 3;
    map[2][3] = 2; map[3][2] = 2;
    map[3][3] = 1;
    map[2][4] = 3;
}


void show_result() {

    ui len = path.size();
    for (ui i = 0; i < len; ++i)
    {
        std::cout << "\t ------ method：" << i + 1 << " ------" << std::endl;
        // std::cout << "\t\t\t method：" << i+1 << std::endl;
        std::cout << "   all_water:" << used_res[i].first << "\t all_food:" << used_res[i].second << "\t" << std::endl;
        for (ui j = 0; j < path[i].size(); ++j)
        {
            std::cout << path[i][j];
            if (j + 1 != path[i].size()) std::cout << " -> ";
        }

        std::cout << std::endl;
        // cout <<
        std::cout << ">_ position:" << 0 << " water:" << 0 << " food:" << 0 << std::endl;
        for (ui j = 1; j < save_pre_used_infos[i].size(); ++j)
        {
            std::cout
            << ">_ position:" << save_pre_used_infos[i][j].first
            <<  " water:" << save_pre_used_infos[i][j].second.first - save_pre_used_infos[i][j-1].second.first
            << " food:" << save_pre_used_infos[i][j].second.second - save_pre_used_infos[i][j-1].second.second
            << std::endl;
        }
        std::cout << "total(work): " << work_days_array[i] << " day     (detail date)" << std::endl;
        for (ui j = 0; j < work_day_info[i].size(); ++j)
        {
            std::cout << work_day_info[i][j] << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }

}
void show_item_by_money() {

    ui len = Moneys_.size();
    for (ui index = 0; index < len; ++index)
    {
        int i = Moneys_[index].second;
        std::cout << "\t ------ method：" << i + 1 << " ------" << std::endl;
        std::cout << Moneys_[index].first << "￥" << std::endl;
        // std::cout << "\t\t\t method：" << i+1 << std::endl;
        std::cout << "   all_water:" << used_res[i].first << "\t all_food:" << used_res[i].second << "\t" << std::endl;
        for (ui j = 0; j < path[i].size(); ++j)
        {
            std::cout << path[i][j];
            if (j + 1 != path[i].size()) std::cout << " -> ";
        }

        std::cout << std::endl;
        // cout <<
        std::cout << ">_ position:" << 0 << " water:" << 0 << " food:" << 0 << std::endl;
        for (ui j = 1; j < save_pre_used_infos[i].size(); ++j)
        {
            std::cout
            << ">_ position:" << save_pre_used_infos[i][j].first
            <<  " water:" << save_pre_used_infos[i][j].second.first - save_pre_used_infos[i][j-1].second.first
            << " food:" << save_pre_used_infos[i][j].second.second - save_pre_used_infos[i][j-1].second.second
            << std::endl;
        }
        std::cout << "total(work): " << work_days_array[i] << " day     (detail date)" << std::endl;
        for (ui j = 0; j < work_day_info[i].size(); ++j)
        {
            std::cout << work_day_info[i][j] << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }


}


/**
 * 保存信息
 * @param way             int[] 路径
 * @param all_water       int   总消耗水
 * @param all_food        int   总消耗食物
 * @param pre_info_length int   最短路径的节点记录的长度
 * @param word_day        int   工作了几天
 * @param work_arr        int[] 工作的具体日期
 */
void save_info(int way[], const int all_water, const int all_food, const int pre_info_length, const int word_day, const int work_arr[])
{
    //保存路径
    std::vector<int> tmp_path;
    for (int i = 0; i <= MAX_STEP; ++i) {
        tmp_path.push_back(way[i]);
        if (way[i] == END) break;
    }
    path.push_back(tmp_path);
    used_res.push_back({ all_water, all_food });

    //保存每个节点信息
    std::vector< std::pair<int, std::pair<int, int> > > tmp_info;
    for (int i = 0; i < pre_info_length; ++i)
    {
        tmp_info.push_back(pre_used_infos[i]);
    }
    save_pre_used_infos.push_back(tmp_info);

    //保存工作信息
    std::vector< int > tmp_work_arr;
    for (int i = 0; i < word_day; ++i)
    {
        tmp_work_arr.push_back(work_arr[i]);
    }
    work_day_info.push_back(tmp_work_arr);
    //保存  工作多少天
    work_days_array.push_back(word_day);
}


/**
 * 处理天气影响    水 食物消耗
 * @param start int 起点
 * @param end   int 终点
 * @param water int 水
 * @param food  int 食物
 * @param rate  int 倍率
 */
void handl_weather(const int start, int& end, int& water, int& food, int rate, bool is_working = false) {
    for (int i = start; i <= end; ++i) {

        //沙暴
        if (weather[i] == 3) {
            if (is_working) {   //工作中  沙暴 不影响  end 不 ++
                water += consum[3 - 1][0] * 3;
                food += consum[3 - 1][1] * 3;
            }
            else {
                water += consum[3 - 1][0];
                food += consum[3 - 1][1];
                ++end;
            }
        }

        //高温
        else if (weather[i] == 2) {
            water += consum[2 - 1][0] * rate;
            food += consum[2 - 1][1] * rate;
        }
        //晴朗
        else if (weather[i] == 1) {
            water += consum[1 - 1][0] * rate;
            food += consum[1 - 1][1] * rate;
        }
    }
}

void save_pre_(int& pre_info_length, const int cur_pos, const int water, const int food) {

    //记录当前节点信息  {位置,   {已经使用的水, 已经使用的食物} }
    pre_used_infos[pre_info_length] = {
        cur_pos,
        {
            // water - pre_used_infos[pre_info_length - 1].second.first,
            water,
            // food - pre_used_infos[pre_info_length - 1].second.second
            food
        }
    };
    ++pre_info_length;
}

bool is_overweight(const int pre_info_length, const int water, const int food) {
    int total_weight = (water - pre_used_infos[pre_info_length - 1].second.first) * WATER_WEIGHT +
                       (food - pre_used_infos[pre_info_length - 1].second.second) * FOOD_WEIGHT;
    if (total_weight > MAX_WEIGHT)
        return true;
    return false;
}


void dfs(int index, int day_cnt, int cur_pos, int way[],
         int water, int food, int pre_info_length,
         int work_day, int work_arr[],
         int visite_village_cnt
     ){
    way[index] = cur_pos;

    //步数超过
    if (index > MAX_STEP) { return; }

    //天数超过
    if (day_cnt > DAY) { return; }

    //经过村庄
    if (cur_pos == VILLAGE) {
        ++visite_village_cnt;
        if (visite_village_cnt > MAX_VIEITE_VILLAGE_CNT) return;
        if (is_overweight(pre_info_length, water, food)) return;
        save_pre_(pre_info_length, cur_pos, water, food);
    }

    //到达终点
    if (cur_pos == END) {
        save_pre_(pre_info_length, cur_pos, water, food);
        // if(!my_judege_method(water, food, pre_used_infos[1].second)) return;
        save_info(way, water, food, pre_info_length, work_day, work_arr);
        return;
    }


    for (int i = 1; i < MAXN; ++i)
        // for (int i = MAXN; i > 0; --i)
    {
        if (map[cur_pos][i] == 0) continue;

        //移动到下一个点  需要的天数 + 已经使用的天数
        int next_day_cnt = day_cnt + map[cur_pos][i];

        int cur_food = food, cur_water = water;

        //在矿区  并且下一步也在矿区
        if (cur_pos == MINE && i == MINE) {

            //  干活  TODO  消耗的资源计算  倍率 3  ---- DONE
            int tmp2_water = cur_water, tmp2_food = cur_food;
            work_arr[work_day] = next_day_cnt;
            handl_weather(day_cnt + 1, next_day_cnt, tmp2_water, tmp2_food, 3, true);
            dfs(index + 1, next_day_cnt, i, way, tmp2_water, tmp2_food, pre_info_length, work_day + 1, work_arr, visite_village_cnt);


            // 不干活  TODO 消耗的资源计算  倍率 1  ---- DONE
            int tmp1_water = cur_water, tmp1_food = cur_food;
            handl_weather(day_cnt + 1, next_day_cnt, tmp1_water, tmp1_food, 1);
            dfs(index + 1, next_day_cnt, i, way, tmp1_water, tmp1_food, pre_info_length, work_day, work_arr, visite_village_cnt);


        }
        else {

            // 处理天气
            handl_weather(day_cnt + 1, next_day_cnt, cur_water, cur_food, 2);

            dfs(index + 1, next_day_cnt, i, way, cur_water, cur_food, pre_info_length, work_day, work_arr, visite_village_cnt);
        }

    }

}

bool weight_validate(int water, int food){
    if((water * WATER_WEIGHT + food * FOOD_WEIGHT) > MAX_WEIGHT) return false;
    return true;
}
int buy(int water, int food, int cur_money){
    cur_money -= water * WATER_PRICE + food * FOOD_PRICE;
    return cur_money;
}

int validate(int water, int food, int index){
    if(!weight_validate(water, food)) return 0;
    int money = INIT_MONEY;
    money = buy(water, food, money);
    
    if(money < 0) return 0;
    return 0;
}
bool cmp(std::pair<int, int>a, std::pair<int, int> b){
    if(a.first > b.first) return true;
    else return false;
}
void pre_validate(int index){
    int water = MAX_WEIGHT / WATER_WEIGHT, food = 0;
    std::vector<std::pair<int, int>> tmp_arr;
    while(water){
        int tmp_money = validate(water, food, index);
        if(tmp_money != 0) tmp_arr.push_back({tmp_money, index});

        --water;
        food = (MAX_WEIGHT - water * WATER_WEIGHT) / FOOD_WEIGHT;
    }
    if(tmp_arr.size() > 0){
        sort(tmp_arr.begin(), tmp_arr.end(), cmp);

        save_validate_money.push_back(tmp_arr[0]);
    }


}
void show_validate_result(){
    for(ui i=0; i<save_validate_money.size(); ++i)
    {
        // 输出第0个
        // if(save_validate_money[i].size() > 0){
        //
        // }
    }
}

void todo_validate(){
    for(ui i=0; i<Moneys_.size(); ++i)
    {
        pre_validate(Moneys_[i].second);
    }
}

int main() {
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    map_init();

    //当前位置
    int cur_pos = 1;

    //路径
    int way[50] = { 0 };

    //初始节点信息                            初始节点长度
    pre_used_infos[0] = { 0, {0, 0} };   int pre_info_len = 0;

    int work_arr[DAY] = { 0 };
    dfs(0, 0, cur_pos, way, 0, 0, pre_info_len + 1, 0, work_arr, 0);


    // show_result();
    // calculate_money();
    // show_item_by_money();
    return 0;
}
