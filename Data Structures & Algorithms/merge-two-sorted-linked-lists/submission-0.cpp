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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* c1 = list1;
        ListNode* c2 = list2;
        ListNode* ans = new ListNode();
        if(c1 == NULL){
            ans = c2;
            return ans;
        }
        else if(c2 == NULL){
            ans = c1;
            return ans;
        }
        if(c1->val < c2->val){
            ans->val = c1->val;
            c1 = c1->next;
        }
        else {
            ans->val = c2->val;
            c2 = c2->next;
        }
        ListNode* head = ans;
        while(c1 && c2){
            int x = c1->val,y = c2->val;
            ListNode* t = new ListNode();
            if(x < y){
                t->val = x;
                c1 = c1->next;
            }
            else {
                t->val = y;
                c2 = c2->next;
            }
            ans->next = t;
            ans = ans->next;
        }
        while(c1){
            ListNode* t = new ListNode(c1->val);
            ans->next = t;
            ans = ans->next;
            c1 = c1->next;
        }
        while(c2){
            ListNode* t = new ListNode(c2->val);
            ans->next = t;
            ans = ans->next;
            c2 = c2->next;
        }
        return head;
    }
};
