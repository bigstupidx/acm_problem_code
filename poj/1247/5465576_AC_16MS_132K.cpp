#include<stdio.h>
int aa[32];
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        int sum1=0,sum2=0,ii,jj;
        for(int i=0;i<n;i++)
            scanf("%d",aa+i);
        int i=0,j=n-1;
        while(i<=j)
        {
            if(sum1<=sum2)
            {
                sum1+=aa[i];
                ii=i;
                i++;
            }
            else
            {
                sum2+=aa[j];
                jj=j;
                j--;
            }
        }
        ii++;jj++;
        if(sum1==sum2)
            printf("Sam stops at position %d and Ella stops at position %d.\n",ii,jj);
        else
            printf("No equal partitioning.\n");
    }
    return 0;
}
