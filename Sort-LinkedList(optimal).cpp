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
    ListNode* middle(ListNode* head){
        ListNode* s=head;
        ListNode* f=head->next;
        while(f!=NULL && f->next!=NULL){
            s=s->next;
            f=f->next->next;
        }
        return s;
    }

    ListNode* mergeSortedList(ListNode* left,ListNode* right){
        if(!left) return right;
        if(!right) return left;

        ListNode* dummy=new ListNode(0);
        ListNode* start=dummy;
        while(left!=NULL && right!=NULL){
            if(left->val<right->val){
                start->next=left;
                left=left->next;
            }
            else{
                start->next=right;
                right=right->next;
            }
            start=start->next;
        }
        if(left) start->next=left;
        if(right) start->next=right;

        ListNode* head=dummy->next;
        delete dummy;
        return head;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* mid=middle(head);

        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;

        left=sortList(left);
        right=sortList(right);

        return mergeSortedList(left,right);
    }
};
