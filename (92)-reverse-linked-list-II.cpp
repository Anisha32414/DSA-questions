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
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* newhead=reverse(head->next);

        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newhead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        if(head==NULL) return NULL;

        ListNode* prev=NULL;
        ListNode* temp=head;
        int cnt=1;
        while(cnt<left){
            cnt++;
            prev=temp;
            temp=temp->next;
        }
        if(prev!=NULL) prev->next=NULL;
        ListNode* curr=temp;
        
        ListNode* front=temp;
        while(cnt<right){
            cnt++;
            temp=temp->next;
            front=temp;
        }
        ListNode* next_node=front->next;
        front->next=NULL;

        ListNode* newhead=reverse(curr);
        if(prev!=NULL) prev->next=newhead;
        else head=newhead;

        curr->next=next_node;

        return head;

    }
};
