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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp=head;
        ListNode* n1=new ListNode();
        ListNode* t1=n1;
        ListNode* n2=new ListNode();
        ListNode* t2=n2;
        while(temp!=nullptr){
            if(temp->val<x){
                t1->next=new ListNode(temp->val);
                t1=t1->next;
            }
            else{
                t2->next=new ListNode(temp->val);
                t2=t2->next;
            }
            temp=temp->next;
        }

        t2->next = nullptr;
        t1->next = n2->next;

        return n1->next;
    }
};
