#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> S;
vector<string> T;
void PermutationS2(char* pStr, char* pBegin)
{
    char * tmp = new char[strlen(pStr)];
	if(*pBegin == '\0'){
        strcpy(tmp, pStr);
        S.push_back(tmp);
    }

	else
	{
		char *pTemp = pBegin;
		while(*pTemp != '\0')
		{
			swap(*pTemp,*pBegin);
			PermutationS2(pStr,pBegin+1);
			swap(*pTemp,*pBegin);
			pTemp ++;
		}
	}
}
void PermutationS1(char *pStr, int begin, int end)
{
    char * tmp = new char[strlen(pStr)];
	if(end - begin == 1){
        strcpy(tmp, pStr);
        S.push_back(tmp);
    }
	else{
		for(int i = begin; i < end; i++)
		{
			swap(pStr[begin],pStr[i]);
			PermutationS1(pStr, begin+1,end);
			swap(pStr[begin],pStr[i]);
		}
	}
}
void swap(char& a, char& b)
{
	char temp = b;
	b = a;
	a = temp;
}
void Permutation(char *pStr)
{
	if(pStr == NULL)
		return;
	PermutationS1(pStr, 0, strlen(pStr));
}

void Test(char* str)
{
	if(str == NULL)
		return;
	Permutation(str);
	// cout<<endl;
}


void Substring(string str){
    for(int i=0;i<str.size();i++)
        for(int j=1;j<=((str.substr(i)).size());j++)
            T.push_back(str.substr(i,j));
}
int main()
{
    string t;
    char s[100];
    scanf("%s", s);
    // cout << "ok" << endl;
    // cin >> t;
	Test(s);
    // Substring(t);
    int i,j,count=0;
    S.erase(unique(S.begin(), S.end()), S.end());
    for(j=0; j<S.size(); ++j){
        // if((S[j]) == T[i]) ++count;
        cout << S[j] << endl;
    }
    // for(i=0; i<T.size(); ++i){
    //     for(j=0; j<S.size(); ++j){
    //         if((S[j]) == T[i]) ++count;
    //         // cout << S[j] << endl;
    //     }
    //     // cout << T[i] << endl;
    // }
    cout << count << endl;

	return 0;
}
