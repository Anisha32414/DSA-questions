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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* s=dummy;
        ListNode* f=dummy;
        while(f->next!=NULL && f->next->next!=NULL){
            s=s->next;
            f=f->next->next;
        }
        ListNode* del=s->next;
        s->next=s->next->next;
        del->next=NULL;
        delete del;

        ListNode* newHead=dummy->next;
        delete dummy;
        return newHead;
    }
};
