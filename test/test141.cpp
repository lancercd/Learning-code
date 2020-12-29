#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int height = 0;
        while(l1 || l2)
        {
            int num1 = l1? l1->val : 0;
            int num2 = l2? l2->val : 0;
            int sum = num1 + num2 + height;
            if(!head){
                head = tail = new ListNode(sum % 10);
            }else{
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            height = sum / 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(height) tail->next = new ListNode(height);

        return head;

    }
};
int main() {
    ListNode* l1, * l2;
    l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    l2->next->next->next = new ListNode(1);

    Solution* solu = new Solution();
    ListNode* ans = solu->addTwoNumbers(l1, l2);
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}
