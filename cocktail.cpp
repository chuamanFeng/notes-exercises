#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bub(vector<int>& a,int n)
{
	bool chang=false;
	int i=0;	
	while(i<n)
	{
		for(int j=i;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
			     swap(a[j],a[j+1]);
			     chang=true;
			}
		}
		for(int j=n-i-1;j>i;j--)
		{
			if(a[j]<a[j-1])
			{
				swap(a[j],a[j-1]);
				chang=true;
			}
		}
		if(!chang)
			break;
		i++;
		chang=false;
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
		bub(co,n);
		for(int i=0;i<n;i++)
			cout<<co[i]<<' ';
                cout<<endl;
	}
}

