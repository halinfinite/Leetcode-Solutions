struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* p1 = head;
        ListNode* p2 = head;

        while (p2 != nullptr && p2->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        
        return p1;
    }

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

    bool isPalindrome(ListNode* head) {
        ListNode* backList = middleNode(head);
        ListNode* reversed = reverseList(backList);

        while (reversed != nullptr) {
            if (head->val != reversed->val) {
                return false;
            }
            head = head->next;
            reversed = reversed->next;
        }

        return true;
    }
};