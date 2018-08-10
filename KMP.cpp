vector<int> getnext(string &s,int l)
{
	vector<int> out(l);
	out[0]=-1;
	out[1]=0;
	int idx1=0;int idx2=1;
	while(idx2<l-1)
	{
		if(s[idx1]==s[idx2])
		{
		    out[++idx2]=++idx1;
		}
		else
		{
			if(idx1==0)
				out[++idx2]=0;
			else
				idx1=out[idx1];
		}
		return out;
	}
}
bool kmp(string s1,string s2)
{
	int l1=s1.length();
	int l2=s2.length();
	vector<int> next=getnext(s1,l1);
	int idx1=0;
	int idx2=0;
	while(idx1<l1&&idx2<l2)
	{
		if(s1[idx1]==s2[idx2])
		{
			idx1++;
			idx2++;
		}
		else if(idx2==0)
			idx1++;
		else
			idx2=next[idx2];
	}
	return idx2==l2;
}
