
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
vector<string> S;
void PermutationS2(char* pStr, char* pBegin)
{
    char * tmp = new char[strlen(pStr)];
	if(*pBegin == '\0'){
        cout << pStr<< "    ";
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
        cout << pStr<<"   ";
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
	/*int index = 0;
	while(pStr[index]!='\0')
		index++;*/
	cout << "Solution1: ";
	PermutationS1(pStr, 0, strlen(pStr));
	// cout <<endl << "Solution2: ";
	// PermutationS2(pStr, pStr);
}

void Test(char* str)
{
	if(str == NULL)
		cout << "Test for NULL begins";
	else
		cout << "Test for " << str <<endl;
	Permutation(str);
	cout<<endl;
}
int main()
{
	// Test(NULL);
	// char str1[] = "";
	// Test(str1);
    //
	// char str2[] = "a";
	// Test(str2);
    //
	// char str3[] = "ab";
	// Test(str3);

	char str4[] = "aab";
	Test(str4);
    int j=0;
    for(j=0; j<S.size(); ++j){
        // if((S[j]) == T[i]) ++count;
        cout << S[j] << endl;
    }
	return 0;
}
