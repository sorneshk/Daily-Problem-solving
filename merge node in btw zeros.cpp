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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* t1=head->next;
        ListNode* dummy=new ListNode(-1);
        ListNode* trav=dummy;
        int sum=0;
        while(t1){
            if(t1->val==0){
                trav->next=new ListNode(sum);
                trav=trav->next;
                sum=0;
            }
            sum+=t1->val;
            t1=t1->next;
        }
        return dummy->next;
    }
};
