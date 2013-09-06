/*
求取最大值
*/

#include<stdio.h>
#include<stdlib.h>

int arrey[1010];
int mycompare(const void *e1,const void *e2)
{
    return *(int *)e1-*(int *)e2;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
               int n,i,max=0;
               scanf("%d",&n);
               for(i=0;i<n;i++)
               scanf("%d",&arrey[i]);
               qsort(arrey,n,sizeof(int),mycompare);
               for(i=0;i<n;i++)
                               if(arrey[i]*(n-i)>max)
                               max=arrey[i]*(n-i);
               printf("%d\n",max);
    }
    system("pause");
    return 0;
}
