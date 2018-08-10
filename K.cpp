class Solution {
public:
    ListNode* mergecore(ListNode*l1,ListNode* l2)
    {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        ListNode* head=new ListNode(-1);
        ListNode* cur=head;
        while(l1&&l2)
        {
            if(l1->val<l2->val)
            {
                cur->next=l1;
                l1=l1->next;
            }
            else
            {
                cur->next=l2;
                l2=l2->next;
            }            
            cur=cur->next;
        }
        while(l1)
        {
            cur->next=l1;
            l1=l1->next;
            cur=cur->next;
        }
        while(l2)
        {
            cur->next=l2;
            l2=l2->next;
            cur=cur->next;
        }
        return head->next;
    }
    ListNode* helper(vector<ListNode*>& lists,int idx1,int idx2)
    {
        if(idx1<idx2)
        {
            int mid=idx1+(idx2-idx1)/2;
            ListNode* left=helper(lists,idx1,mid);
            ListNode* right=helper(lists,mid+1,idx2);
            return mergecore(left,right);
        }
        return lists[idx1];
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
           if(lists.empty())
               return nullptr;
           return helper(lists,0,int(lists.size())-1);
        
    }
};
