struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr; // to be the head of reversed list
        ListNode* curr = head;
        ListNode* next;
        while (curr != nullptr) {
            next = curr->next; //temporarily store
            curr->next = prev; // reverse
            prev = curr; // move
            curr = next; // move
        }
        return prev;
    }
};