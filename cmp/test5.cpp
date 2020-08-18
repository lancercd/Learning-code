#include "iostream"
#include "algorithm"
#include "set"
#include "map"
#include "vector"
#include "string"
#include "climits"

using namespace std;
map<int,int> obj;
int main()
{
    int n,a, count = 0;cin>>n; char b;
    for(int i = 1; i<=n; i++){
        cin>>a>>b;
        if(b == '.'){
            obj[a] ++; obj[a+1]--;
        }
        else if(b == '+'){
            obj[INT_MIN]++; obj[a]--;
        }
        else{
             obj[a+1]++;
        }
    }
    int Max = 0;
    for(auto x: obj){
        count += x.second;
        Max = max(Max,count);
    }
    cout<<Max<<endl;
    return 0;
}
