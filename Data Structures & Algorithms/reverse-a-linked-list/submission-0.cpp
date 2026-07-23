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
    ListNode* reverseList(ListNode* head) {

        ListNode* t = head;
        int cnt = 0;
        ListNode * res = nullptr;
        while (t != nullptr) {
            res = new ListNode(t->val , res);
            t = t->next;
        }

        return res;
        
    }
};
