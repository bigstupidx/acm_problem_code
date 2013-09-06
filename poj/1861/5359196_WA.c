#include<stdio.h>
#include<stdlib.h>
struct node{
       int x,y;
       int len;
}nodes[15010];
int n,m;
int xx[1010],yy[1010];
int par[1010],rank[1010];
int cmp(const void *e1,const void *e2)
{
    struct node *p1,*p2;
    p1=(struct node *)e1;
    p2=(struct node *)e2;
    return p1->len-p2->len;
}
void inti()
{
     int i;
     for(i=0;i<n;i++){
                      par[i]=-1;rank[i]=0;
     }
     return ;
}
int find(int x)
{
    int t=par[x];
    if(t==-1)return x;
    par[x]=find(t);
    return par[x];
}
void unionij(int i,int j)
{
     if(rank[i]<rank[j])
     par[i]=j;
     else{
          par[j]=i;
          if(rank[i]==rank[j])rank[i]++;
     }
}
int kruskal()
{
    int k=0,i,j,ii;
    inti();
    for(ii=0;ii<m;ii++){
           if(k==n-1)break;
           i=find(nodes[ii].x);
           j=find(nodes[ii].y);
           if(i!=j){
                    xx[k]=nodes[ii].x;
                    yy[k++]=nodes[ii].y;
                    unionij(i,j);
           }                   
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
            int i;
            for(i=0;i<m;i++)
               scanf("%d%d%d",&nodes[i].x,&nodes[i].y,&nodes[i].len);
            qsort(nodes,m,sizeof(nodes[0]),cmp);
            printf("%d\n%d\n",kruskal(),n-1);
            for(i=0;i<n-1;i++)
                printf("%d %d\n",xx[i],yy[i]);
    }
    return 0;
}
