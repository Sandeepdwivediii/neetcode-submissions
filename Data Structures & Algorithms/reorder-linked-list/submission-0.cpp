/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {

        if(!head) return ;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        ListNode* left = head;
        ListNode* right = prev;

        while(right->next){
            ListNode* rn = right->next;
            ListNode* ln = left->next;

            left->next = right;
            right->next = ln;

            left = ln;
            right = rn;
        }
    }
};
