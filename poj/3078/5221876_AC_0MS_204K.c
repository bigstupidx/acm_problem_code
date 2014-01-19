#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
       char str[10];
       int number;
}nodes[22];

int cmp(const void *e1,const void *e2)
{
    struct Node *p1,*p2;
    p1=(struct Node *)e1;
    p2=(struct Node *)e2;
    return p1->number-p2->number;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
              int m,n,x,i;
              int flag[2][21];
              
              memset(flag,0,sizeof(flag));
              scanf("%d%d",&m,&n);
              for(i=1;i<=m;i++)scanf("%s",nodes[i].str);
              for(i=0;i<n;i++){
                               int j,temp;
                               scanf("%d",&j);
                               flag[0][j]=1;
                               scanf("%d",&temp);
                               flag[1][temp]=1;
                               nodes[j].number=temp;
              }
              x=1;
              for(i=1;i<=m;i++){
							  int j=x;
                              if(!flag[0][i]){
								  while(flag[1][j]&&j<=m)j++;
								  nodes[i].number=j;x=j+1;
							  }
              }
              qsort(nodes+1,m,sizeof(nodes[0]),cmp);
              for(i=1;i<=m;i++)
              printf("%s ",nodes[i].str);
              printf("\n");             
    }
    return 0;
}
              
