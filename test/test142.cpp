#include "iostream"
#include "algorithm"
#include "vector"
#include "unordered_map"
#include "map"


/**
 * unordered_map test
 * 测试 比较map
 */


using namespace std;

int main() {
    unordered_map<int, int> unordered;
    map<int, int> order;

    unordered.insert({1,-1});
    unordered.insert({2,-2});
    unordered.insert({3,-4});
    order.insert({1,-1});
    order.insert({2,-2});
    order.insert({3,-4});

    auto it = unordered.begin();
    while(it != unordered.end()){
        cout << it->first << " " << it->second << endl;
        ++it;
    }

    // for(auto ele : unordered){
    //     cout << ele.first << " " << ele.second << endl;
    // }
    //
    // for(auto it : order){
    //     cout << it.first << "  " << it.first << endl;
    // }

    return 0;
}
