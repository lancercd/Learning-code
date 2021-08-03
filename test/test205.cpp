#include <iostream>
#include "algorithm"
#include "string"
using namespace std;

int _x[4] = {1, -1, 0, 0};
int _y[4] = {0, 0, 1, -1};
int maxn = 4;
int maxm = 3;
char target[] = {'z', 'o', 'o'};
int target_maxn = 3;

bool flag = false;

char str[3][4] = {
    {'a', 'c', 'd', 'z'},
    {'x', 't', 'r', 'o'},
    {'f', 'i', 'o','o'}
};

void dfs(char str[][4], int x, int y, int cur_index) {

    if(x > maxm || x < 0 || y >maxn || y < 0) return;
    if(cur_index >= target_maxn){
        flag = true;
        return;
    }

    for(int i=0; i<4; ++i){
        int cur_x = x + _x[i];
        int cur_y = y + _y[i];

        if(cur_x > maxm || cur_x < 0 || cur_y >maxn || cur_y < 0) continue;
        if(str[cur_x][cur_y] == target[cur_index]){
            dfs(str, cur_x, cur_y, cur_index + 1);
        }

    }

}


bool handle(char str[][4], int x, int y){

    for(int i=0; i<maxn; ++i){
        for(int j=0; j<maxm ; ++j){
            if(str[j][i] == target[0]){
                dfs(str, i, j, 1);
            }
        }
    }

    return flag;
}

int main() {


    cout << handle(str, 0, 0) << endl;


    cout << "Hello World!" << endl;
}
