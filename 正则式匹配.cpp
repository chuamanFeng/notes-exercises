class Solution {
public:   
    bool isMatch(string s, string p) {
        
        int l1=s.length();
        int l2=p.length();
      
        vector<vector<bool>> co(l1+1,vector<bool>(l2+1,0));
        co[0][0]=1;
        for(int i=1;i<=l2;i++)
        {
            if(p[i-1]=='*'&&i>=2)
                co[0][i]=co[0][i-2];//delete： to fit an empty string
        }
        for(int i=1;i<=l1;i++)
        {
            for(int j=1;j<=l2;j++)
            {                
                if(s[i-1]==p[j-1]||p[j-1]=='.')
                    co[i][j]=co[i-1][j-1];
                else if(p[j-1]=='*')
                {
                    if(j>=2&&(s[i-1]!=p[j-2]&&p[j-2]!='.'))//can only delete it
                       co[i][j]=co[i][j-2];
                    else//use it to:add one and stay * or normal match with *(use once and keep forward) or delete                 
                      j>=2? co[i][j]=co[i-1][j]||co[i][j-1]||co[i][j-2]:co[i][j]=co[i-1][j]||co[i][j-1];                   
                }
            }
        }
        return co[l1][l2];
    }
};
