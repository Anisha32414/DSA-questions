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
        if (!head || !head->next || k == 0) return head;

        ListNode* temp=head;
        int cnt=1;
        while(temp->next!=NULL){
            cnt++;
            temp=temp->next;
        }

        k=k%cnt;
        if (k == 0) return head;
        int nodesStart=cnt-k;

        ListNode* prev=NULL;
        ListNode* curr=head;

        for(int i=0;i<nodesStart;i++){
            prev=curr;
            curr=curr->next;
        }

        prev->next=NULL;
        temp->next=head;
        head=curr;

        return head;
    }
};
