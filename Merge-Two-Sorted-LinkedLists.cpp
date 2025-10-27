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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)return list2;
        if(!list2)return list1;

        ListNode* dummy=new ListNode(0);
        ListNode* start=dummy;
        
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                start->next=list1;
                list1=list1->next;
            }
            else{
                start->next=list2;
                list2=list2->next;
            }
            start=start->next;
        }
        if(list1) start->next=list1;
        else start->next=list2;

        start=dummy->next;
        delete dummy;
        return start;
    }
};
