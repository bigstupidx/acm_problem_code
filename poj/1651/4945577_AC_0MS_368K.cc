#include<stdio.h>
#include<stdlib.h>
#define MAX 102
int arrey[MAX];
int m[MAX][MAX];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
                               int i,j,r,k,temp;
                               for(i=0;i<n;i++)
                                               scanf("%d",&arrey[i]);
                               for(i=1;i<n;i++)
                                               m[i][i]=0;
                               for(r=1;r<n;r++)
                                               for(i=1;i<n-r;i++){
                                               j=i+r;
                                               m[i][j]=arrey[i-1]*arrey[i]*arrey[j]+m[i+1][j];
                                               for(k=i+1;k<j;k++){
                                                  temp=m[i][k]+m[k+1][j]+arrey[i-1]*arrey[k]*arrey[j];
                                                  if(temp<m[i][j])
                                                                  m[i][j]=temp; 
                                               }
                               }
                               printf("%d\n",m[1][n-1]);
    }
    system("pause");
    return 0;
}
    
