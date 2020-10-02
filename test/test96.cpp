#include "iostream"
#include "algorithm"
// #include "utility"
// #include "set"

using namespace std;

typedef struct Node{
    int num;
    struct Node *next;
    struct Node *front;
}Node;
Node* head = new Node;
int N, M;
// set<pair<int, pair<bool, Node*>>> arr;

Node* find(int num){
    Node * cur = head->next;
    while(cur){
        if(cur->num == num){
            return cur;
        }
        cur = cur->next;
    }
    return 0;
}

void insert(Node* current, Node* target){
    current->next = target->next;
    current->front = target;
    if(target->next){
        target->next->front = current;
    }
    target->next = current;


}

void add(int num, int pos, int is_right){
    Node * tmp = new Node();
    tmp->num = num;
    tmp->next = 0;
    Node * target = find(pos);
    insert(tmp, is_right? target:target->front);

}

void init(){
    head->num = -1;
    head->front = 0;
    head->next = new Node;
    head->next->num = 1;
    head->next->front = head;
    head->next->next = 0;
}

void del(int num){
    Node* cur = find(num);
    if(!cur) return;
    if(cur->next){
        cur->front->next = cur->next;
        cur->next->front = cur->front;
    }else{
        cur->front->next = 0;
    }
    delete cur;
}

void show(){
    Node* cur = head->next;
    while(cur){
        cout << cur->num << " ";
        cur = cur->next;
    }
}

int main() {
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    init();
    cin >> N;
    for(int i=1; i<N; ++i){
        int index, is_right;
        cin >> index >> is_right;
        add(i + 1, index, is_right);
    }
    cin >> M;
    // show();
    // cout << " " << endl;
    for(int i=0; i<M; ++i)
    {
        int tmp;
        cin >> tmp;
        del(tmp);
    }

    show();

    return 0;
}
