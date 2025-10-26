class Solution {
public:
    int countNodesCycle(ListNode *head) {
       ListNode* s=head;
       ListNode* f=head;
       while(f!=NULL && f->next!=NULL){
          s=s->next;
          f=f->next->next;
          if(s==f){
            f=f->next;
            int cnt=1;
            while(s!=f){
                f=f->next;
                cnt++;
            }
            return cnt;
          }
       }
       
    }
    return 0;
};
