#include "map"
#include "iostream"
#include "algorithm"

using namespace std;
map<string, int> table1;
map<int, string> table2;
map<string, int>::iterator iter;
map<int, string>::iterator iter1;
pair<map<int, string>::iterator, bool> pair2;
pair<map<string, int>::iterator, bool> pair1;

int main() {
	int n;
	cin >> n;

	int my_flag = 0;

	while(n--){
		string command;
        cin >> command;

		if(command == "ls"){
			for(iter1 = table2.begin();iter1!=table2.end();iter1++){
				cout << iter1->second << endl;
			}
		}else if(command == "touch"){
            string filename;
			cin >> filename;

			pair1 = table1.insert(map<string, int>::value_type(filename, my_flag));
			if(pair1.second){
				table2.insert(map<int, string>::value_type(my_flag, filename));
			}
		}else if(command == "rm"){
            string filename;
			cin >> filename;

		    iter = table1.find(filename);
		    if(iter != table1.end()){
		    	iter1 = table2.find(iter->second);
		    	table1.erase(iter);
		    	table2.erase(iter1);
			}
		}else if(command == "rename"){
            string filename1;
			cin >> filename1;
            string filename2;
			cin >> filename2;

			iter = table1.find(filename1);

		    if(iter != table1.end()){
		    	int my_flag_tmp = iter->second;
				iter1 = table2.find(my_flag_tmp);
		    	iter1->second = filename2;
				table1.insert(map<string,int>::value_type(filename2, my_flag_tmp));
		    	table1.erase(iter);
			}
		}

		++my_flag;
	}


    return 0;
}
