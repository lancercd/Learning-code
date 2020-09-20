#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;
string lagestcommonsubset(const string &a,const string &b){
	   int m=a.length(),n=b.length();
       vector<vector<int>>dp(m+1,vector<int>(n+1,0));
       int max_len=0,pos=-1;
       for(int i=0;i<a.length();i++){
       	for(int j=0;j<b.length();j++){
       		if(a[i]==b[j]){
       			dp[i+1][j+1]=dp[i][j]+1;
       			if(dp[i+1][j+1]>max_len){
       				max_len=dp[i+1][j+1];
       				pos=i;
				   }
			   }
		   }
	   }//for
	   return a.substr(pos-max_len+1,max_len);
}
int main(){
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
	string a,b;
	cout<<"输入两个字符串,可以包含空格:"<<endl;
	getline(cin,a);
	getline(cin,b);
	cout<<lagestcommonsubset(a,b);
}
