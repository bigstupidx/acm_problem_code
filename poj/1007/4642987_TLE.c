#include<stdio.h>

int main()
{
    char string[100][51];
    int i,j,m,n,k;
    int order[100],min[100],flag[100];
    memset(order,0,sizeof(order));
    memset(min,0,sizeof(min));
    memset(flag,1,sizeof(flag));
    freopen("F:\\poj\\input1.txt","r",stdin);
    scanf("%d%d",&m,&n);
    for(i=0;i<n;i++)
          scanf("%s",string[i]);
    for(i=0;i<n;i++)
         for(j=0;j<m;j++)
              for(k=j;k<m;k++)
               if(string[i][k]<string[i][j])order[i]++;
    for(i=0;i<n;i++){
         for(k=0;k<n;k++)
         if(flag[k]){m=k;break;}
         for(j=0;j<n;j++)
           if(flag[j]&&order[j]<order[m])m=j;
         min[i]=m;flag[m]=0;
    }
    for(i=0;i<n;i++){
        printf("%s\n",string[min[i]]);
    }
    return 0;
}
       
