#include "map"
#include "algorithm"
#include "iostream"

using namespace std;

pair<map<string, int>::iterator, bool> pair1;
map<int, string>::iterator iter1;
pair<map<int, string>::iterator, bool> pair2;
map<string, int>::iterator iter;
int n;
map<string, int> table1;
map<int, string> table2;
int main() {
	cin >> n;

	char com1[2000];
	char com2[2000];

	int my_flag = 0;


	while(n--){
		string order;
        cin >> order;
		if(order == "ls"){
			for(iter1 = table2.begin();iter1!=table2.end();iter1++) cout << iter1->second << endl;
		}else if(order == "touch"){
			cin >> com1;
			string filename(com1);

			pair1 = table1.insert(map<string, int>::value_type(filename, my_flag));
			if(pair1.second){
				table2.insert(map<int, string>::value_type(my_flag, filename));
			}
		}else if(order == "rm"){
			cin >> com1;
			string filename(com1);

		    iter = table1.find(com1);
		    if(iter != table1.end()){
		    	iter1 = table2.find(iter->second);
		    	table1.erase(iter);
		    	table2.erase(iter1);
			}
		}else if(order == "rename"){
			cin >> com1;
			string filename1(com1);
			cin >> com2;
			string filename2(com2);

			iter = table1.find(com1);

		    if(iter != table1.end()){
		    	int my_flag_tmp = iter->second;
				iter1 = table2.find(my_flag_tmp);
		    	iter1->second = com2;
				table1.insert(map<string,int>::value_type(com2, my_flag_tmp));
		    	table1.erase(iter);
			}
		}

		++my_flag;
	}


    return 0;
}
