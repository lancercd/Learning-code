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
