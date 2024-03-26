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
        
        if (list1 == NULL && list2 == NULL) {
            return NULL;
        }
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
        
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode* headf = new ListNode();
        ListNode* currf = headf;
        while(curr1 != NULL && curr2 != NULL){
            
        if(curr2->val >= curr1->val){
            currf -> next = curr1;
            curr1 = curr1->next;
            currf = currf->next;
        }
        else{
            currf -> next  = curr2;
            curr2 = curr2->next;
            currf = currf->next;
        }
        }
        
        if(curr1!= NULL){
            currf ->next = curr1;
        }
        
        if(curr2!= NULL){
            currf ->next = curr2;
        }
        
        ListNode* ans = headf -> next;
        delete headf;
        return ans;
        
        
    
};
};