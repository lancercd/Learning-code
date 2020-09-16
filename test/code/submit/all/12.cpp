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
