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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        int mid=cnt/2;
        temp=head;
        cnt=0;
        while(temp!=NULL){
            
            if(cnt==mid){
                return temp;
            }

            temp=temp->next;
            cnt++;
        }
        return NULL;
    }
};
