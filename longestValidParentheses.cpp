class Solution {
public:
    int longestValidParentheses(string s) {
         
        int l=s.length();
        if(l<=1)
            return 0;
        stack<int> co;
        int res=0;
        int ed=-1;
        for(int i=0;i<l;i++)
        {
           if(s[i]=='(')
           {
               co.push(i);
               continue;
           }
           else
           {
               if(co.empty())
                   ed=i;
               else
               {  
                   co.pop();
                   if(!co.empty())
                      res=max(res,i-co.top());
                   else
                       res=max(res,i-ed);
               }
                
           }
                
        }
        
        return res;
    }
};
