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
    ListNode* reverse(ListNode* node){
        if(node==NULL || node->next==NULL){
            return node;
        }
        ListNode* newHead=reverse(node->next);
        ListNode* front=node->next;
        front->next=node;
        node->next=NULL;
        return newHead;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* s=head;
        ListNode* f=head;
        while(f->next!=NULL && f->next->next!=NULL){
            s=s->next;
            f=f->next->next;
        }
        ListNode* newHead=reverse(s->next);
        ListNode* first=head;
        ListNode* second=newHead;
        while(second!=NULL){
            if(first->val!=second->val){
                reverse(newHead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverse(newHead);
        return true;
    }
};
