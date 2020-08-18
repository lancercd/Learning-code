#include<bits/stdc++.h>
using namespace std;
const int maxn=2e2;
pair<double,double>p[maxn+5];
set<double>m;
int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i].first>>p[i].second;
    }
    int cnt=0,flag=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].first==p[j].first)flag=1;
            else{
                m.insert((p[i].second-p[j].second)/(p[i].first-p[j].first));
            }
            }
        }
    cout<<m.size()+flag<<endl;
    return 0;
}
