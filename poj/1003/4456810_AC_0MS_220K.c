#include<stdio.h>
#include<math.h>
int cards(double x)
{
    double sum=0;
    int i;
    for(i=2;;i++)
    {
                  sum+=1.0/i;
                  if(sum>x||fabs(sum-x)<1e-4)
                    return i-1;
    }
}
int main()
{
    double x,a;
    int t;
    scanf("%lf",&x);
    while(fabs(x)>1e-5){
                t=cards(x);
                printf("%d %s\n",t,"card(s)");
                scanf("%lf",&x);
    }
    return 0;
}
