#include "iostream"
#include "algorithm"
#include "vector"
// #include "../utils/ListNode/ListNode.h"

using namespace std;

// leetcode
// 合并两个有序链表
// https://leetcode-cn.com/problems/merge-two-sorted-lists/
class ListNode {
 public:
    int val;
    ListNode *next;

    ListNode();
    ListNode(int x);
    ListNode(int x, ListNode *next);

    /**
     * 构建链表
     * @param arr target数组
     * @param len 数组长度
     * @return ListNode*
     */
    static ListNode *build(const int arr[], int len);
    /**
     * 构建链表
     * @param arr target数组
     * @return ListNode*
     */
    static ListNode *build(std::vector<int> &arr);
};

ListNode::ListNode() : val(0), next(nullptr) {}
ListNode::ListNode(int x) : val(x), next(nullptr) {}
ListNode::ListNode(int x, ListNode *next) : val(x), next(next) {}

ListNode *ListNode::build(const int arr[], int len) {
    ListNode *h = new ListNode(), *cur = h;
    for (int i = 0; i < len; ++i) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return h->next;
}
ListNode *ListNode::build(std::vector<int> &arr) {
    ListNode *h = new ListNode(), *cur = h;
    unsigned int len = arr.size();
    for (unsigned int i = 0; i < len; ++i) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return h->next;
}

class Solution {
 public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *h = new ListNode(), *cur = h;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
            cur->next = nullptr;
        }

        if (l1 == nullptr) cur->next = l2;
        if (l2 == nullptr) cur->next = l1;

        return h->next;
    }
};

int main() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {0, 5};

    ListNode *nodeA = ListNode::build(arr1, sizeof(arr1) / 4),
        *nodeB = ListNode::build(arr2, sizeof(arr2) / 4);

    Solution *solu = new Solution();

    ListNode *ans = solu->mergeTwoLists(nodeA, nodeB);

    while (ans != nullptr) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}
