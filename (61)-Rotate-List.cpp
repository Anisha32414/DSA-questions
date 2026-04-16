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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        int n=0;
        ListNode* temp=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        k=k%n;
        if(k==0) return head;

        int cnt=0;
        temp=head;
        ListNode* prev;
        ListNode* next_node;
        while(temp!=NULL && cnt<(n-k)){
            cnt++;
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        ListNode* newhead=temp;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;
        return newhead;

    }
};
