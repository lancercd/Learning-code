#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> qujian[6];

int main(){
	int L, M;
	cin >> L >> M;

	int *zhuangtai = new int [M];

	for(int i=0;i<M;i++){
		cin >> qujian[i].first >> qujian[i].second;
		zhuangtai[i] = 1;
	}

	sort(qujian, qujian+M);


    //合并区间   区间与别人有交集  则合并
	for(int i=M-1;i>=0;i--){ //我觉得应该 i>-1  || i >= 0
		if(qujian[i].first>qujian[i-1].second) continue;
		if(qujian[i].second<=qujian[i-1].second){
			zhuangtai[i] = 0;
		}else{
			qujian[i-1].second = qujian[i].second;
			zhuangtai[i] = 0;
		}
	}
    cout << "show  int  (inc  merged)" << endl;
    for(int i=0; i<M; ++i){
        cout << qujian[i].first << "   " << qujian[i].second;
        if(zhuangtai[i] == 0) cout << " < --- merged" ;
        cout << endl;
    }

    //
	// // if(){  //有可能  zhuangtai[0] = 0
    //     int sum = qujian[0].first;
    // 	int rear = qujian[0].second;
    // // }
	// for(int i=1;i<M;i++){
	// 	if(!zhuangtai[i]) continue;
	// 	sum += qujian[i].first-rear-1;
	// 	rear = qujian[i].second;
	// }
    //
	// sum += (L-rear);
	// cout << sum;

	return 0;
}
