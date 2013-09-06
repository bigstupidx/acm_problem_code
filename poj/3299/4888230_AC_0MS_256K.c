#include<stdio.h>
#include<math.h>
#define E 2.718281828
double t,h,d;
double hi;

void get_hi()
{
	double e;
	e=6.11*pow(E,5417.753*((1/273.16)-(1/(d+273.16))));
	hi=0.5555*(e-10.0);
}

void get_h()
{
	get_hi();
	h=t+hi;
}

void get_t()
{
	get_hi();
	t=h-hi;
}

void get_d()
{
	double e;
	
	/*hi=h-t;
	e=hi*(1/0.5555)+10.0;
	e/=6.11;
	d=5417.753*(1/273.16)-log(e);
	d=1.0/d;
	d-=273.16;*/

	e = ((h-t)/0.5555 + 10.0)/6.11;
    d = 1/(1/273.16 - log(e)/log(2.718281828)/5417.7530) - 273.16;
}

int main()
{
	int flag1,flag2,flag3;
	char xx,yy;
	while(scanf("%c",&xx),xx!='E'){
		double x,y;
		getchar();
		scanf("%lf %c %lf",&x,&yy,&y);
		getchar();
		flag1=flag2=flag3=0;
		if(xx=='T'){t=x;flag1=1;}
		if(yy=='T'){t=y;flag1=1;}
		if(xx=='D'){d=x;flag2=1;}
		if(yy=='D'){d=y;flag2=1;}
		if(xx=='H'){h=x;flag3=1;}
		if(yy=='H'){h=y;flag3=1;}
		if(flag1&&flag2)
			get_h();
		else if(flag2&&flag3)
			get_t();
		else
			get_d();
		printf("T %.1lf D %.1lf H %.1lf\n",t,d,h);
	}
	return 0;
}
