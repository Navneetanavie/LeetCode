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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL|| k==1) return head;
        int cnt=0;
        ListNode* dummy= new ListNode(-1);
         dummy->next=head;
        ListNode* temp=dummy;
       ListNode* prev=dummy; 
       ListNode* curr=dummy;
       ListNode* next=dummy;
        while(temp->next!=NULL){
            cnt++;
            temp=temp->next;
            
        }
       
        while(cnt>=k){
        curr=prev->next;
        next=curr->next;
        for(int i=1;i<k;i++){
           curr->next=next->next;
           next->next=prev->next;
           prev->next=next;
           next=curr->next;
        }
        prev=curr;
        cnt-=k;

        }
        return dummy->next;
    }
};