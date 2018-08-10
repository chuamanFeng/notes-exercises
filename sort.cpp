#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void corebb(vector<int>& co,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(co[j]<co[i])
				swap(co[j],co[i]);
		}
	}
}

int coreq(vector<int> &co,int bg,int ed)
{
   int num=co[(bg+ed)/2];
   swap(co[(bg+ed)/2],co[ed]);
   int id1=bg;
	int id2=ed;
	while(id1<id2)
	{
		while(id1<id2&&co[id1]<=num)
			id1++;
		while(id1<id2&&co[id2]>=num)
			id2--;
		swap(co[id1],co[id2]);
	}
    swap(co[id1],co[ed]);
	return id1;
}
void qs(vector<int>& co,int bg,int ed)
{
	if(bg<ed)
	{
		int mid=coreq(co,bg,ed);
		qs(co,bg,mid-1);
		qs(co,mid+1,ed);
	}
}
void merge(vector<int>& co,int bg,int mid,int ed)
{
	vector<int> temp(ed-bg+1);
	int idx1=bg;
	int idx2=mid+1;
	int j=0;
	while(idx1<=mid&&idx2<=ed)
	{
		if(co[idx1]<co[idx2])
			temp[j++]=co[idx1++];
		else
			temp[j++]=co[idx2++];
	}
	while(idx1<=mid)
		temp[j++]=co[idx1++];
	while(idx2<=ed)
	    temp[j++]=co[idx2++];
	for(int i=0;i<ed-bg+1;i++)
	      co[bg+i]=temp[i];
}
void mg(vector<int>& co,int bg,int ed)
{
	if(bg<ed)
	{
		int mid=(ed+bg)/2;
		mg(co,bg,mid);
		mg(co,mid+1,ed);
		merge(co,bg,mid,ed);
	}
}
int main()
{
    int n;
    while(cin>>n)
    {
    	vector<int> co(n);
    	for(int i=0;i<n;i++)
    		cin>>co[i];
    	mg(co,0,n-1);
    	for(int i=0;i<n;i++)
    		cout<<co[i]<<' ';
    }

}
