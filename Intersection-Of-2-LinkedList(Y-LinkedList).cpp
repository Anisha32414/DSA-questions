/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        int cnt1=0;
        int cnt2=0;
        while(temp1!=NULL){
            cnt1++;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            cnt2++;
            temp2=temp2->next;
        }

        int diff;
        if(cnt1>cnt2){
            diff=cnt1-cnt2;
            temp1=headA;
            temp2=headB;
            while(diff){
                temp1=temp1->next;
                diff--;
            }
        }
        else{
            diff=cnt2-cnt1;
            temp2=headB;
            temp1=headA;
            while(diff){
                temp2=temp2->next;
                diff--;
            }
        }

        while(temp1!=NULL && temp2!=NULL){
            if(temp1==temp2){
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};
