ListNode* deleteKeyOccurrencesDLL(ListNode* head,int key){
    ListNode* temp=head;
    while(temp!=NULL){
        if(temp->val==key){
            if(temp==head)
                head=head->next;
           
            ListNode* prevNode=temp->prev;
            ListNode* nextNode=temp->next;

            if(prevNode) prevNode->next=nextNode;
            if(nextNode) nextNode->prev=prevNode;

            ListNode* newTemp=temp->next;

            delete temp;
            
            temp=newTemp;
        }
        else
        temp=temp->next;
    }
    return head;
}
