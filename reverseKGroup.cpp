class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       if(head==nullptr||head->next==nullptr||k<=1)
            return head;
        ListNode* cur=head;
        ListNode* dum=new ListNode(0);
        dum->next=head;
        int cnt=0;
        while(cur)
        {  
            cur=cur->next;
            cnt++;
        }
        int times=cnt/k;
        if(times==0)
            return head;
        ListNode* pre,*nex;
        pre=dum;       
        cur=head;
        for(int i=0;i<times;i++)
        {
            for(int j=0;j<k-1;j++)
            {
                nex=cur->next;
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
            }
            pre = cur;
            cur = cur->next;
            
        }
        return dum->next;
    }
};
