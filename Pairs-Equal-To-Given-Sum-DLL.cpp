vector<vector<int>> sum2NodesDLL(ListNode* head,int sum){
    vector<vector<int>>res;
    ListNode* tail=head;
    ListNode* temp=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }

    while(temp->val < tail->val){
        if(temp->val + tail->val == sum){
            res.push_back({temp->val,tail->val});
            temp=temp->next;
            tail=tail->prev;
        }
        else if(temp->val + tail->val < sum){
            temp=temp->next;
        }
        else{
            tail=tail->prev;
        }
    }
    return res;
}
