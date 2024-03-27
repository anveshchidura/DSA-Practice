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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        if (head->next == NULL && n == 1) return NULL;
        int size = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp!=NULL){
            size++;
            temp = temp->next;
        }
        if (size == n) { // If the first node needs to be removed
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        int k = size - n ;
        int pos =1;
        while(curr != NULL && pos <= k){
            prev = curr;
            curr = curr->next;
            pos++;
        }
        prev->next = curr->next;
        delete curr;
        return head;
        
    }
};