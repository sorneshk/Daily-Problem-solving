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
    ListNode* sortList(ListNode* head) {
        ListNode* temp=head;
        vector<int> v;
        while(temp!=nullptr){
            v.push_back(temp->val);
            temp=temp->next;
        }
        sort(v.begin(),v.end());
        ListNode* dummy=new ListNode(INT_MIN);
        ListNode* trav=dummy;
        for(int it : v){
            trav->next=new ListNode(it);
            trav=trav->next;
        }
        return dummy->next;
    }
};