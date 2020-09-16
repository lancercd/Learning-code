#include "iostream"
#include "algorithm"
#include "string"
typedef unsigned int ui;

int main() {
    std::string a,b; std::cin >> a;
    b = a;

    std::reverse(b.begin(), b.end());

    for(ui i=0; i<b.length(); ++i){
        if(a[i] == b[i]) continue;
        std::cout << "false" << std::endl;
        return 0;
    }
    std::cout << "true" << std::endl;

    return 0;
}


#include "iostream"
#include "algorithm"
#include "string"


int main() {
    // cin 不能录入空格  我直接录入了
    std::string str = "i am a student of Peking University.";
    int index = 0, max_length = 0, cur_length = 0, i = 0;
    while (1) {
        if (str[i] != ' ') {
            ++cur_length;
        }
        else {
            if (max_length < cur_length) {
                index = i - cur_length;
                max_length = cur_length;
            }
            cur_length = 0;
        }

        ++i;
        if(str[i] == '.'){
            if (max_length < cur_length) {
                index = i - cur_length;
                max_length = cur_length;
            }
            break;
        }
    }
    // index;
    while (str[index] != ' ' && str[index] != '.') {
        std::cout << str[index++];
    }
    std::cout << "\nlength:" << max_length << std::endl;

    return 0;
}







#include "iostream"
#include "algorithm"
#include "climits"

const int MAXN = 1e3;
int arr[MAXN][MAXN] = {0};
int N;

int main() {
    std::cin >>N;
    N = 4;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j)
        {
            std::cin >> arr[i][j];
        }
    }

    for(int i=0; i<N; ++i)
    {
        int min_1 = INT_MAX, index_j1 = 0, index_i1 = 0;
        for(int j=0; j<N; ++j)  //行找
        {
            if(arr[i][j] < min_1){
                min_1 = arr[i][j];
                index_j1 = j;
                index_i1 = i;
            }
        }
        int min_2 = INT_MAX, index_j2 = 0, index_i2 = 0;
        for(int j=0; j<N; ++j){ //列找
            if(arr[j][index_j1] < min_2){
                min_2 = arr[j][index_j1];
                index_j2 = index_j1;
                index_i2 = j;
            }
        }
        if(index_i1 == index_i2 && index_j1 == index_j2){
            std::cout << arr[index_i1][index_j1] << " ";
        }
    }

    return 0;
}
/**
4
5 3 4 1
9 7 5 3
4 1 2 4
9 6 3 5



 */


 #include "iostream"
 #include "algorithm"


 const int MAXN = 1e2;
 int arr[MAXN][MAXN] = {0};
 int ROW;
 int COL;


 void rot()
 {
 	int tmp[COL][ROW];
 	int dst=ROW-1;

 	for(int i=0;i<ROW;i++,dst--)
 		for(int j=0;j<COL;j++)
 			tmp[j][dst]=arr[i][j];

 	for(int i=0;i<COL;i++)
 		for(int j=0;j<ROW;j++)
 			arr[i][j]=tmp[i][j];
 }

 int main()
 {
     std::cin >> COL >> ROW;

 	for(int i=0;i<ROW;i++)
 	{
 		for(int j=0;j<COL;j++)
             std::cin >> arr[i][j];
 	}

 	rot();

 	for(int i=0;i<COL;i++)
 	{
 		for(int j=0;j<ROW;j++)
             std::cout << arr[i][j] << "\t";
 		std::cout<<std::endl;
 	}

     return 0;
 }
 /**
 4 4
 1 2 3 4
 5 6 7 8
 9 10 11 12
 13 14 15 16

  */





  #include "iostream"
  #include "algorithm"

  class Student{
  public:
      double a;
      double b;
      double c;
      Student(){}
      Student(int a, int b, int c):a(a), b(b), c(c){}
      void show(){
          std::cout << this->a << " " << this->b << " " << this->c << std::endl;
      }
      double avg(){
          return (this->a + this->b + this->c)/3.0;
      }
  };

  
  int main() {
      double a, b, c; std::cin >> a >> b >> c;
      Student* stu = new Student(a, b, c);
      stu->show();
      std::cout << stu->avg() << std::endl;
      return 0;
  }
