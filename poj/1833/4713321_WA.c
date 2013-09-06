#include<stdio.h>
#include<string.h>

int temp[1025];

int mycompare(const void *e1,const void *e2)
{
    return *((int *)e1-*(int *)e2);
}

void determine(int n,int k)
{
     int i,j;
     for(i=0;i<k;i++){
          int t,m,min;
          for(j=n-1;j>0;j--)
             if(temp[j]>temp[j-1])break;
          if(j>0){
               for(m=j,min=j;m<n;m++){
                   if(temp[m]>temp[j-1]&&temp[m]<temp[min])min=m;
                }
                t=temp[j-1];temp[j-1]=temp[min];temp[min]=t;
                qsort(&temp[j],n-j+1,sizeof(int),mycompare);
          }
          else{
               for(j=0;j<n;j++)
               temp[j]=j+1;
          }
     }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
               int n,k,i;
               scanf("%d%d",&n,&k);
               for(i=0;i<n;i++)
                   scanf("%d",&temp[i]);
               determine(n,k);
               for(i=0;i<n;i++)
                   printf("%d ",temp[i]);
               printf("\n");
    }
    return 0;
}
