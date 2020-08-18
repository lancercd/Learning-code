#include <iostream>

using namespace std;

template <typename t>
t Max(t a, t b)
{
    return (a>b)? a:b;
}

template <typename T>
class Cmax{
public:
    Cmax(){
        // cout << a << endl;
    }
    T max(T a, T b)
    {
        return a>b? a:b;
    }
};

int main(){
    Cmax<int> *a = new Cmax<int>();
    cout << a->max(89, 5) << endl;
    // cout << Max(1.111f, 2.111f) << endl;
    // cout << Max<int>('a', 'c') << endl;
    return 0;
}
