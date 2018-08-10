vector<int> out;
    map<string,int> book;
    vector<int> findSubstring(string S, vector<string> &L) {

        out.clear();
        book.clear();

        if(S.empty()||L.empty())
            return out;
        int sz=L.size();
        int l1=S.length();
        int l2=L[0].length();
        int l=sz*l2;
        for(int i=0;i<sz;i++)
        {
            if(book.find(L[i])==book.end())
                book[L[i]]=0;
             book[L[i]]++;
        }

        for(int i=0;i<=l1-l;i++)
        {
            map<string,int> bookt=book;
            string tm=S.substr(i,l);
            int cnt=0;
            for(int j=0;j<l;)
            {
                string tp=tm.substr(j,l2);
                j+=l2;
                if(bookt.find(tp)==bookt.end())
                    break;
                bookt[tp]--;
                if(bookt[tp]<0)
                    break;
                cnt++;
            }
            if(cnt==sz)
                out.push_back(i);
        }
        return out;
    }
