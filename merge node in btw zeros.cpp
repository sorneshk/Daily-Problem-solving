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

int main() {
    Solution sol;
    
    // Test case: Create linked list 0->1->2->3->0->4->5->0
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(0);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next->next = new ListNode(0);
    
    // Call mergeNodes
    ListNode* result = sol.mergeNodes(head);
    
    // Print result
    cout << "Result: ";
    ListNode* current = result;
    while(current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
    
    return 0;
}