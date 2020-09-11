#include "iostream"
#include "algorithm"
#include "vector"
#include "string"
#include "utility"
typedef unsigned int ui;

const int
        DAY = 30,               //最大生存天数
        MAXN = 5,               //地图最大 下标
        END = 4,                //终点
        VILLAGE = 2,            //村庄  地点
        MINE = 3,               //矿区
        MAX_STEP = 7;           //最大步数

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
std::vector< std::vector<int> > path;
std::vector< std::pair<int, int> > used_res;
// std::vector< std::string > infos;
std::pair<int, std::pair<int, int> > pre_used_infos[10];
std::vector< std::vector< std::pair<int, std::pair<int, int> > > > save_pre_used_infos;

void map_init() {
    map[1][2] = 6;
    map[1][4] = 3;
    map[2][3] = 2; map[3][2] = 2;  //双通路
    map[2][4] = 3;
}


void show_result() {

    ui len = path.size();
    for (ui i = 0; i < len; ++i)
    {
        std::cout << "   all_water:" << used_res[i].first << "\t all_food:" << used_res[i].second << "\t" << std::endl;
        for (ui j = 0; j < path[i].size(); ++j)
        {
            std::cout << path[i][j];
            if (j + 1 != path[i].size()) std::cout << " -> ";
        }

        std::cout << std::endl;

        for(ui j=0; j<save_pre_used_infos[i].size(); ++j)
        {

            std::cout << ">_ pos" << save_pre_used_infos[i][j].first << " water:" << save_pre_used_infos[i][j].second.first << " food:" << save_pre_used_infos[i][j].second.second << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }


}

void save_info(int way[], int all_water, int all_food, int pre_info_length) {
    std::vector<int> tmp_path;
    for (int i = 0; i <= MAX_STEP; ++i) {
        tmp_path.push_back(way[i]);
        if (way[i] == END) break;
    }
    path.push_back(tmp_path);
    used_res.push_back({all_water, all_food});


    std::vector< std::pair<int, std::pair<int, int> > > tmp_info;
    for(int i=0; i<pre_info_length; ++i)
    {
        tmp_info.push_back(pre_used_infos[i]);
    }
    save_pre_used_infos.push_back(tmp_info);
}

void handl_weather(int start, int& end, int& water, int& food) {
    for (int i = start; i <= end; ++i) {
        if (weather[i] == 3) {
            water += consum[3 - 1][0];
            food += consum[3 - 1][1];
            ++end;
        }
        else if (weather[i] == 2) {
            water += consum[2 - 1][0] * 2;
            food += consum[2 - 1][1] * 2;
        }
        else if (weather[i] == 1) {
            water += consum[1 - 1][0] * 2;
            food += consum[1 - 1][1] * 2;
        }
    }
}

void dfs(int index, int day_cnt, int cur_pos, int way[], int water, int food, int pre_info_length) {
    way[index] = cur_pos;

    //步数超过
    if (index > MAX_STEP) { return; }

    //天数超过
    if (day_cnt > DAY) { return; }

    if(cur_pos == VILLAGE){
        pre_used_infos[pre_info_length] = {
            cur_pos,
            {
                water - pre_used_infos[pre_info_length-1].second.first,
                food - pre_used_infos[pre_info_length-1].second.second
            }
        };
        ++pre_info_length;
    }

    //到达终点
    if (cur_pos == END) {
        save_info(way, water, food, pre_info_length);
        return;
    }


    for (int i = 1; i < MAXN; ++i)
    // for (int i = MAXN; i > 0; --i)
    {
        if (map[cur_pos][i] == 0) continue;
        int next_day_cnt = day_cnt + map[cur_pos][i];

        int cur_food = food, cur_water = water;
        // 处理天气
        handl_weather(day_cnt + 1, next_day_cnt, cur_water, cur_food);


        dfs(index + 1, next_day_cnt, i, way, cur_water, cur_food, pre_info_length);
    }

}

int main() {
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    map_init();
    int cur_pos = 1;
    int way[50] = { 0 };
    pre_used_infos[0] = {0, {0, 0}};   int pre_info_len = 0;
    dfs(0, 0, cur_pos, way, 0, 0, pre_info_len + 1);



    show_result();
    return 0;
}
