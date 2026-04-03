#include <iostream>
#include <stack>
using namespace std;

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* rev(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        stack<int> st;
        ListNode* t1=head;
        while(t1){
            while(!st.empty() && st.top()<t1->val){
                st.pop();
            }
            st.push(t1->val);
            t1=t1->next;
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* trav=dummy;
        while(!st.empty()){
            trav->next=new ListNode(st.top());
            trav=trav->next;
            st.pop();
        }
        ListNode* ans=rev(dummy->next);
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test case: Create linked list 5->2->13->3->8
    ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(8);
    
    // Call removeNodes
    ListNode* result = sol.removeNodes(head);
    
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