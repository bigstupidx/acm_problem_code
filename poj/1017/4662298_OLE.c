#include<stdio.h>
void main()
{
	int n,a,b,c,d,e,f,x,y;
	int m[4]={0,5,3,1};
	while(1){
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		if(a==0&&b==0&&c==0&&d==0&&e==0&&f==0)
			break;
		n=f+e+d+(c+3)/4;
		y=5*d+m[c%4];
		if(b>y)   n+=(b-y+8)/9;
		x=36*n-36*f-25*e-16*d-9*c-4*b;
		if(a>x)   n+=(a-x+35)/36;
		printf("%d\n",n);
	}
}
