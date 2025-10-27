class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head){
        if(head==NULL || head->next==NULL) return head;

        ListNode* start0=new ListNode(0);
        ListNode* start1=new ListNode(0);
        ListNode* start2=new ListNode(0); 

        ListNode* zero=start0;
        ListNode* one=start1;
        ListNode* two=start2;

        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->val==0){
                start0->next=temp;
                start0=start->next;
            }
            else if(temp->val==1){
                start1->next=temp;
                start1=start1->next;
            }
            else{
                start2->next=temp;
                start2=start2->next;
            }
            temp=temp->next;
        }
        start0->next=one->next?one->next:two->next;
        start1->next=two->next;
        two->next=NULL;

        return zero->next;
    }
};
