#include<stdio.h>
#define MAX 100010

int aa[MAX];
int main()
{
    int n,f;
    while(scanf("%d%d",&n,&f)!=EOF)
    {
        int i;
        double max;
        long long sum = 0;
        for(i=0;i<n;i++)
            scanf("%d",aa+i);
        for(i=0;i<f;i++)
            sum += aa[i];
        max = sum/(f*1.0);
        for(;i<n;i++)
        {
            double temp;
            sum +=aa[i]-aa[i-f];
            temp = sum/(f*1.0);
            if(temp > max)max = temp;
        }
        printf("%d\n",(int)(1000*(max+0.0001)));
    }
    return 0;
}
