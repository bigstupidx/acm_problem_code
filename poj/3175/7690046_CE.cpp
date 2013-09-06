#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
int n,m,b,t,i;
double a,d,c;
while(scanf("%d",&n)!=EOF)
{
scanf("%d",&m);
t=1;
for(i=0;i<n;i++)
t*=10;
a=(double)m/t;
while(1)
{
c=int(a*a+0.2);
c=sqrt(c);
b=(int)c;
d=double(c-b);
if(int(d*t)==m)
{
printf("%d\n",int(a*a+0.2));
break;
}
a+=1;
}
}
}

