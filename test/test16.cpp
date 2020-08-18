#include "iostream"

using namespace std;

int arr[9] = {0}, used[9] = {0};

void dfs(int count){
    if(count == 8){
        cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << " " << arr[5] << " " << arr[6] << " " << arr[7] << endl;
    }else{
        for(int i=0; i<8; ++i){
            if(used[i] == 0){
                used[i] = 1;
                arr[count] = i+1;
                dfs(count + 1);
                used[i] = 0;
            }
        }
    }
}

int main(){
    dfs(0);

    return 0;
}
