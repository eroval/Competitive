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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        int val1, val2=0;
        
        ListNode* newList = new ListNode(0);
        ListNode* curr = newList;
        int tmp=0;
        
        while(l1!=NULL || l2!=NULL){
            val1 = l1 == NULL? 0 : l1->val;
            val2 = l2 == NULL? 0 : l2->val;
            
            curr->next = new ListNode((tmp+val1+val2)%10);
            tmp = (tmp+val1+val2)/10;
            
            curr = curr->next;
            l1 = l1 == NULL ? NULL : l1->next;
            l2 = l2 == NULL ? NULL : l2->next;
        }
        if(tmp!=0){
            curr->next = new ListNode(tmp);
        }
        return newList->next;
    }
};