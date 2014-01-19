/*
看了discuss，其实可以自己推出来的，呵呵
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int a[108],b[108];

int main()
{
	int i,n;
	long sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	for(i=2;i<n;i++){
		int temp,x,y,z;
		x=b[i-1],y=a[i],z=b[i+1];
		if(x>y)
			temp=x,x=y,y=temp;
		if(z<x&&z<y)
			b[i]=x;
		else if(z>x&&z<y)
			b[i]=z;
		else if(z>x&&z>y)
			b[i]=y;
	}
	sum=fabs(a[n]-b[n]);
	for(i=1;i<n;i++)
		sum+=fabs(a[i]-b[i])+fabs(b[i]-b[i+1]);
	printf("%ld\n",sum);
	system("pause");
	return 0;
}
