#include "iostream"
#include "algorithm"
#include "utility"
// #include "set"
#include "vector"

using namespace std;

void show(vector<pair<int , int> > arr){
    for(unsigned int i=0; i<arr.size(); ++i)
    {
        cout << arr[i].first << "  " << arr[i].second << endl;
    }
}


int main() {
    vector<pair<int , int> > arr;
    arr.push_back({3, 1});
    arr.push_back({1, 9});
    arr.push_back({5, 5});
    arr.push_back({4, 4});

    show(arr);
    sort(arr.begin(), arr.end());
    cout << " sorted" << endl;
    show(arr);
    return 0;
}
