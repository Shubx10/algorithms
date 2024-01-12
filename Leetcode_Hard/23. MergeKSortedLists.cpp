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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for(auto first: lists){
            if(first != NULL) pq.push({first->val, first});
        }
        while(!pq.empty()){
            ListNode* mini = pq.top().second;
            pq.pop();
            if(mini->next != NULL) pq.push({mini->next->val, mini->next});
            curr->next = mini;
            curr = curr->next;
        }
        return head->next;
    }
};
