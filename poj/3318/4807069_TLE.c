#include<stdio.h>
int a[500][500],b[500][500],c[500][500],answer[500][500];
int n;
int solve()
{
     int i,j,k;
    
    for(i=0;i<n;i++)
              for(j=0;j<n;j++)
              scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)
              for(j=0;j<n;j++)
              scanf("%d",&b[i][j]);
    for(i=0;i<n;i++)
              for(j=0;j<n;j++)
              scanf("%d",&c[i][j]);
    for(i=0;i<n;i++)
           for(j=0;j<n;j++){
              answer[i][j]=0;
              for(k=0;k<n;k++)
                 answer[i][j]+=a[i][k]*b[k][j];
              if(answer[i][j]!=c[i][j])return 0;
    }
    return 1;
}
          
int main()
{
    while(scanf("%d",&n)!=EOF)
        if(solve())
                   printf("YES\n");
        else printf("NO\n");
    return 0;
}
    
