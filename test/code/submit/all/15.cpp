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
