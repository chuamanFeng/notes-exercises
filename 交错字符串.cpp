class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1=s1.length();
        int l2=s2.length();
        int l3=s3.length();
        if(l1+l2!=l3)
            return false;
        if(l3==0)
            return true;
        vector<vector<int>> co(l1+1,vector<int>(l2+1,0)); 
        for(int i=1;i<=l1&&s1[i-1]==s3[i-1];i++)       
                co[i][0]=1;        
          for(int i=1;i<=l2&&s2[i-1]==s3[i-1];i++)      
                co[0][i]=1;
       
        for(int i=1;i<=l1;i++)
        {
            for(int j=1;j<=l2;j++)
            {
                if(s1[i-1]==s3[i+j-1]&&co[i-1][j])
                {
                    co[i][j]=1;
                    continue;
                }                   
                if(s2[j-1]==s3[i+j-1]&&co[i][j-1])
                    co[i][j]=1;
            }
        }
        return co[l1][l2];
      
    }
};
