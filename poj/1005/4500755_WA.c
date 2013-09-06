#include<stdio.h>
#include<math.h>
int main()
{
    int t,i,year;
    double x,y,area;
    scanf("%d",&t);
    for(i=0;i<t;i++){
                     x=y=area=0;
                     scanf("%lf%lf",&x,&y);
                     x=x*x+y*y;
                     year=(int)(x*3.14/100)+1;
                     printf("Property %d: This property will begin eroding in year %d.\n",i+1,year);
    }
    return 0;
}

                     
          
    
