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
        if(head==NULL) return head;
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        n=cnt-n+1;
        
        if(n==1){
            ListNode* del=head;
            head=head->next;
            del->next=NULL;
            delete del;
            return head;
        }
       
        temp=head;
        cnt=1;
        ListNode* prev=NULL;
        while(cnt<n-1 && temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        if(temp!=NULL && temp->next!=NULL){
            ListNode* del=temp->next;
            temp->next=temp->next->next;
            del->next=NULL;
            delete del;
        }
        return head;
    }
};
