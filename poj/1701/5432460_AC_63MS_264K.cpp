#include<stdio.h>
#define MAX 10010
int aa[MAX],bb[MAX];
int person[MAX];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m,n1,n3,a,b,sum=0;
        double y=0,min;
        scanf("%d%d%d",&m,&a,&b);
        for(int i=1;i<=m;i++)
        {
            scanf("%d",person+i);
            sum+=person[i];
            y+=((i-1)*a+(i-1)*(i-2))*person[i];
        }
        aa[1]=aa[2]=0;
        n1=0;
        for(int i=3;i<=m;i++){
            n1+=person[i-2];
            aa[i]=n1+aa[i-1];
        }
        bb[m]=0;n3=0;
        for(int i=m-1;i>=0;i--)
        {
            n3+=person[i+1];
            bb[i]=bb[i+1]+n3;
        }
        int k=1;
        min=y;
        n1=0;n3=sum;
        for(int i=2;i<=m;i++)
        {
            n1+=person[i-1];
            n3-=person[i-1];
            y-=n3*a+bb[i];
            y+=b*n1+aa[i];
            if(y<min)
            {
                min=y;k=i;
            }
        }
        printf("%d\n",k);
    }
    return 0;
}
