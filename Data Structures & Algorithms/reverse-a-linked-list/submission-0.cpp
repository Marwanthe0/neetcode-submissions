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
        ListNode* x = head;
        vector<int> v;
        if(x == NULL)
        return x;
        ListNode* cur = head;
        while(x->next != NULL){
            x = x->next;
            ListNode* t = new ListNode(x->val);
            t->next = cur;
            cur = t;
        }
        head->next = NULL;
        return cur;

    }
};
 