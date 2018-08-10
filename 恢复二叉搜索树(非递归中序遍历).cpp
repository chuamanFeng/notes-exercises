class Solution {
public:
    void recoverTree(TreeNode* root) {
        
        if(root==nullptr)
            return;
        stack<TreeNode*> pt;
        TreeNode* cur=root;
        TreeNode *tmp = NULL;
        TreeNode *big = NULL;
        TreeNode *small = NULL;
        bool flag = false;
        while(cur||!pt.empty())
        {
             if(cur)//not null ,go left;
             {
                   pt.push(cur);
                   cur=cur->left;
             }
            else //left=null,go right,save it int tmp first
            {
                cur=pt.top();
                pt.pop();
                if(tmp==nullptr)
                {
                    tmp=cur;
                    cur=cur->right;  //if cur->right==null,cur will return to upper father in the next round,then tmp will be its left child
                    continue;
                }
                if(!flag)
                {
                    if(tmp->val>cur->val)//find it now
                    {
                         big=tmp;  //tmp if faild big one
                        small=cur; //
                        flag=true;
                    }
                }
                else 
                {
                   if(tmp->val>cur->val)
                    {
                       small=cur;
                       break;
                    }
                }
                 tmp = cur;//go right further, until right==nullptr
                 cur = cur->right;
            }
        }
        int tp=small->val;       
        small->val=big->val;
         big->val=tp;
    }
};
