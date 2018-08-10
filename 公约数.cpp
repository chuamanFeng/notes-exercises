int GCD(int m,int n)
{
int a,b;

cin>>a;

cin>>b;

int c=a%b;
while(c!=0)
{
a=b;
b=c;
c=a%b;
}
return b;
}
