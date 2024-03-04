class Solution {
public:
    struct comparator {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comparator> pq;

        for(int i = 0;i<lists.size();i++){
            if (lists[i] != nullptr) {
            pq.push(lists[i]);
            }    
        }
        
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;

        while (!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();

            tail->next = temp;
            tail = tail->next;

            if (temp->next != nullptr) {
                pq.push(temp->next);
            }
        }

        ListNode* mergedHead = dummyHead->next;
        delete dummyHead; // Prevent memory leak
        return mergedHead;
    }
};
