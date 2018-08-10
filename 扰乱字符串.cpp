class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1==s2)
            return true;
        int l1=s1.length();    
        if(l1!=s2.length())
            return false;
       string tp1=s1,tp2=s2;
        sort(tp1.begin(),tp1.end());
        sort(tp2.begin(),tp2.end());
        if(tp1!=tp2)       
               return false;    
         
        for(int i=1;i<l1;i++)
        {
            string s11=s1.substr(0,i);
            string s21=s2.substr(0,i);
            string s12=s1.substr(i);
            string s22=s2.substr(i);
            if(isScramble(s11,s21)&&isScramble(s12,s22))
                return true;         
            s22=s2.substr(0,l1-i);           
            s21=s2.substr(l1-i);
             if(isScramble(s11,s21)&&isScramble(s12,s22))
                return true;
        }
        return false;
    }
};
 // DP 
 class Solution {
 public:
    bool isScramble(string s1, string s2) {
         if (s1.size() != s2.size()) return false;
          if (s1 == s2) return true;
          int n = s1.size();
          vector<vector<vector<bool> > > dp (n, vector<vector<bool> >(n, vector<bool>(n + 1, false)));
          for (int i = 0; i < n; ++i) {
             for (int j = 0; j < n; ++j) {
                 dp[i][j][1] = s1[i] == s2[j];
             }
         }
         for (int len = 2; len <= n; ++len) {
             for (int i = 0; i <= n - len; ++i) {
                 for (int j = 0; j <= n - len; ++j) {
                     for (int k = 1; k < len; ++k) {
                         if ((dp[i][j][k] && dp[i + k][j + k][len - k]) || (dp[i + k][j][len - k] && dp[i][j + len - k][k])) {
                             dp[i][j][len] = true;
                         }
                     }
                 }
             }
         }
         return dp[0][0][n];
     }
 };
