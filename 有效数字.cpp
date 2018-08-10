public class Solution {
    public boolean isNumber(String s) {
      
        if(s==null || s.length()==0) return false;
        int sz = s.length();
        int i=0;
        
        while(i<sz && s.charAt(i)==' ') ++i;
        
        boolean space = false;
        boolean exp = false;
        boolean dot = false;
        boolean number = false;
        boolean neg = false;
        
        for(; i<sz; i++) {
            char c = s.charAt(i);
            if(c==' ') {
                space = true;
            } else if(space==true) {
                return false;
            } else if( (c=='e' || c=='E') && exp==false && number==true) {
                exp = true;
                number = false;
                dot = true;
                neg = false;
            } else if( c=='.' && dot==false) {
                dot = true;
                neg = true;
               // number = false;
            } else if( c>='0' && c<='9') {
                number = true;
            } else if((c=='+' || c=='-') && neg==false && number==false ) {
                neg = true;
            } else {
                return false;
            }
        }
        return number;
    }
}

