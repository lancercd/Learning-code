#include "iostream"
#include "algorithm"
#include "string"

using namespace std;

typedef struct node{
    string name;
    struct node* next;
    struct node* pre;
}Node;



int N;

int main() {
    freopen("../data/in.txt", "r", stdin); freopen("../data/out.txt", "w", stdout);
    cin >> N;
    Node * head = new Node;
    head->next = 0;
    head->pre = 0;
    Node * end = head;
    char order[10];
    for(int i = 0;  i < N; ++i){
        cin >> order;
        if(order[0] == 't' || order[0] == 'T'){
            //touch
            string str; cin >> str;
            Node * tmp = head->next;
            while(tmp){
                if(tmp->name == str) break;
                tmp = tmp->next;
            }
            if(!tmp){
                tmp = new Node;
                tmp->name = str;
                tmp->next = 0;
                end->next = tmp;
                tmp->pre = end;
                end = tmp;
            }
        }
        if(order[0] == 'r' || order[0] == 'R'){
            if(order[1] == 'm' || order[1] == 'M'){
            //rm
                string flag; cin >> flag;
                Node* tmp = head->next;
                while(tmp){
                    if(tmp->name == flag){
                        tmp->pre->next = tmp->next;
                        if(tmp->next){
                            tmp->next->pre = tmp->pre;
                        }
                        delete tmp;
                        break;
                    }
                    tmp = tmp->next;
                }
            }else{
            //rname
                string flag, rename; cin >> flag >> rename;
                Node* tmp = head->next;
                int is_ok = 0;
                while(tmp){
                    if(tmp->name == rename){
                        is_ok = 1;
                        break;
                    }
                    tmp = tmp->next;
                }
                if(!is_ok){
                    tmp = head->next;
                    while(tmp){
                        if(tmp->name == flag){
                            tmp->name = rename;
                            break;
                        }

                        tmp = tmp->next;
                    }
                }
            }
        }
        if(order[0] == 'l' || order[0] == 'L'){
            // ls
            Node* tmp = head->next;
            while(tmp){
                cout << tmp->name << endl;
                tmp = tmp->next;
            }
        }
    }

    return 0;
}
