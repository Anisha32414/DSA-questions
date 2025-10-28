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

    ListNode* kthNodeLL(ListNode* temp,int k){
        while(k>1 && temp!=NULL){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseLL(ListNode* node){
        if(node==NULL || node->next==NULL) return node;

        ListNode* newHead=reverseLL(node->next);
        ListNode* front=node->next;
        front->next=node;
        node->next=NULL;

        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* kthNode=kthNodeLL(temp,k);
            if(kthNode==NULL){
                if(prev){
                    prev->next=temp;
                    break;
                }
            }
            ListNode* nextNode=kthNode->next;
            kthNode->next=NULL;
            reverseLL(temp);
            if(temp==head){
                head=kthNode;
            }
            else{
                prev->next=kthNode;
            }
            prev=temp;
            temp=nextNode;
        }
        return head;
    }
};
