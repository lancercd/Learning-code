#include "iostream"
#include "algorithm"
#include "vector"
#include "string"
#include "utility"
typedef unsigned int ui;
typedef std::pair<int, int> pii;
typedef std::vector<int> array;

const int

        DAY = 30,
        MAXN = 5,


        END = 4,
        VILLAGE = 2,
        MINE = 3,


        MAX_WEIGHT = 1200,
        WATER_WEIGHT = 3,
        FOOD_WEIGHT = 2,


        INIT_MONEY = 1e4,
        WATER_PRICE = 5,
        FOOD_PRICE = 10,
        SALARY = 1e3,

        //config
        MAX_STEP = 20,
        //MIN_STEP = 3;
        MAX_VIEITE_VILLAGE_CNT = 2,


        CONST_CONFIG_END = 1;
int Test_ver = 0;

const std::string palce[10] = {"0.0", "起点", "村庄", "矿区", "终点"};

const int weather[50] = { 0,
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
std::vector< std::vector<int> > path;
std::vector< std::pair<int, int> > used_res;
// std::vector< std::string > infos;

std::pair<int, std::pair<int, int> > pre_used_infos[10];

/*   save_pre_used_infos
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
std::vector< std::vector< std::pair<int, std::pair<int, int> > > > save_pre_used_infos;
std::vector< std::vector<int > > work_day_info;
std::vector< int > work_days_array;
std::vector< std::pair<int, int> > Moneys_;
std::vector< int > save_validate_money;

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

        // used_res[i].first;
        // used_res[i].second;

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
        std::cout << "\t ------ 方法: " << i + 1 << " ------" << std::endl;
        // std::cout << "\t\t\t method:" << i+1 << std::endl;
        std::cout << "   整个过程所需 水:" << used_res[i].first << "\t 食物:" << used_res[i].second << "\t" << std::endl;
        std::cout << "路径:";
        for (ui j = 0; j < path[i].size(); ++j)
        {
            std::cout << palce[path[i][j]];
            if (j + 1 != path[i].size()) std::cout << " -> ";
        }

        std::cout << std::endl;
        // cout <<
        std::cout << ">_ 位置:" << 0 << " 所需水:" << 0 << " 食物:" << 0 << std::endl;
        for (ui j = 1; j < save_pre_used_infos[i].size(); ++j)
        {
            std::cout
            << ">_ 位置:" << save_pre_used_infos[i][j].first
            <<  " 所需水:" << save_pre_used_infos[i][j].second.first - save_pre_used_infos[i][j-1].second.first
            << " 食物:" << save_pre_used_infos[i][j].second.second - save_pre_used_infos[i][j-1].second.second
            << std::endl;
        }
        std::cout << "工作天数: " << work_days_array[i] << " 天" << std::endl;
        std::cout << "详细工作日期:" << std::endl;
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
        std::cout << "\t ------ 方法: " << i + 1 << " ------" << std::endl;
        std::cout << Moneys_[index].first << "￥" << std::endl;
        // std::cout << "\t\t\t method锛�" << i+1 << std::endl;
        std::cout << "   整个过程所需 水:" << used_res[i].first << "\t 食物:" << used_res[i].second << "\t" << std::endl;
        std::cout << "路径:";
        for (ui j = 0; j < path[i].size(); ++j)
        {
            std::cout << palce[path[i][j]];
            if (j + 1 != path[i].size()) std::cout << " -> ";
        }

        std::cout << std::endl;
        std::cout << ">_ 位置:" << 0 << " 所需水:" << 0 << " 食物:" << 0 << std::endl;
        for (ui j = 1; j < save_pre_used_infos[i].size(); ++j)
        {
            std::cout
            << ">_ 位置:" << save_pre_used_infos[i][j].first
            <<  " 所需水:" << save_pre_used_infos[i][j].second.first - save_pre_used_infos[i][j-1].second.first
            << " 食物:" << save_pre_used_infos[i][j].second.second - save_pre_used_infos[i][j-1].second.second
            << std::endl;
        }
        std::cout << "工作天数: " << work_days_array[i] << " 天" << std::endl;
        std::cout << "详细工作日期:" << std::endl;
        for (ui j = 0; j < work_day_info[i].size(); ++j)
        {
            std::cout << work_day_info[i][j] << " ";
        }


        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }


}



void save_info(int way[], const int all_water, const int all_food, const int pre_info_length, const int word_day, const int work_arr[])
{

    std::vector<int> tmp_path;
    for (int i = 0; i <= MAX_STEP; ++i) {
        tmp_path.push_back(way[i]);
        if (way[i] == END) break;
    }
    path.push_back(tmp_path);
    used_res.push_back({ all_water, all_food });


    std::vector< std::pair<int, std::pair<int, int> > > tmp_info;
    for (int i = 0; i < pre_info_length; ++i)
    {
        tmp_info.push_back(pre_used_infos[i]);
    }
    save_pre_used_infos.push_back(tmp_info);


    std::vector< int > tmp_work_arr;
    for (int i = 0; i < word_day; ++i)
    {
        tmp_work_arr.push_back(work_arr[i]);
    }
    work_day_info.push_back(tmp_work_arr);

    work_days_array.push_back(word_day);
}



void handl_weather(const int start, int& end, int& water, int& food, int rate, bool is_working = false) {
    for (int i = start; i <= end; ++i) {


        if (weather[i] == 3) {
            if (is_working) {
                water += consum[3 - 1][0] * 3;
                food += consum[3 - 1][1] * 3;
            }
            else {
                water += consum[3 - 1][0];
                food += consum[3 - 1][1];
                ++end;
            }
        }

        else if (weather[i] == 2) {
            water += consum[2 - 1][0] * rate;
            food += consum[2 - 1][1] * rate;
        }

        else if (weather[i] == 1) {
            water += consum[1 - 1][0] * rate;
            food += consum[1 - 1][1] * rate;
        }
    }
}

void save_pre_(int& pre_info_length, const int cur_pos, const int water, const int food) {


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


    if (index > MAX_STEP) { return; }


    if (day_cnt > DAY) { return; }


    if (cur_pos == VILLAGE) {
        ++visite_village_cnt;
        if (visite_village_cnt > MAX_VIEITE_VILLAGE_CNT) return;
        if (is_overweight(pre_info_length, water, food)) return;
        save_pre_(pre_info_length, cur_pos, water, food);
    }


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


        int next_day_cnt = day_cnt + map[cur_pos][i];

        int cur_food = food, cur_water = water;


        if (cur_pos == MINE && i == MINE) {

            int tmp2_water = cur_water, tmp2_food = cur_food;
            work_arr[work_day] = next_day_cnt;
            handl_weather(day_cnt + 1, next_day_cnt, tmp2_water, tmp2_food, 3, true);
            dfs(index + 1, next_day_cnt, i, way, tmp2_water, tmp2_food, pre_info_length, work_day + 1, work_arr, visite_village_cnt);



            int tmp1_water = cur_water, tmp1_food = cur_food;
            handl_weather(day_cnt + 1, next_day_cnt, tmp1_water, tmp1_food, 1);
            dfs(index + 1, next_day_cnt, i, way, tmp1_water, tmp1_food, pre_info_length, work_day, work_arr, visite_village_cnt);


        }
        else {


            handl_weather(day_cnt + 1, next_day_cnt, cur_water, cur_food, 2);

            dfs(index + 1, next_day_cnt, i, way, cur_water, cur_food, pre_info_length, work_day, work_arr, visite_village_cnt);
        }

    }

}




int main() {
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    map_init();


    int cur_pos = 1;


    int way[50] = { 0 };


    pre_used_infos[0] = { 0, {0, 0} };   int pre_info_len = 0;

    int work_arr[DAY] = { 0 };
    dfs(0, 0, cur_pos, way, 0, 0, pre_info_len + 1, 0, work_arr, 0);


    // show_result();
    calculate_money();
    show_item_by_money();
    return 0;
}
