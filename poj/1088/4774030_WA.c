#include<stdio.h>

typedef struct node{
        int i,j;
        int h;
        int step;
}node;
node nodes[10010];

int m,n;
int xue[200][200];

int mycompare(const void *e1,const void *e2)
{
    node *p1,*p2;
    p1=(node*)e1;
    p2=(node*)e2;
    return p1->h-p2->h;
}

int main()
{
    int i,j,k;
    scanf("%d%d",&n,&m);
    for(i=1,k=0;i<=n;i++)
        for(j=1;j<=m;j++){
           scanf("%d",&xue[i][j]);
           nodes[k].i=i;nodes[k].j=j;
           nodes[k].step=1;
           nodes[k++].h=xue[i][j];
    }
    qsort(nodes,m*n,sizeof(node),mycompare);
    for(k=0;k<m*n;k++){
                       int a,b,c,d;
                       a=nodes[k].i-1;
                       b=nodes[k].i+1;
                       c=nodes[k].j-1;
                       d=nodes[k].j+1;
                       if(a>0&&xue[a][nodes[k].j]>nodes[k].h&&nodes[xue[a][nodes[k].j]-1].step<nodes[k].step+1)
                                 nodes[xue[a][nodes[k].j]-1].step=nodes[k].step+1;
                       if(b<=n&&xue[b][nodes[k].j]>nodes[k].h&&nodes[xue[b][nodes[k].j]-1].step<nodes[k].step+1)
                                 nodes[xue[b][nodes[k].j]-1].step=nodes[k].step+1;
                       if(c>0&&xue[nodes[k].i][c]>nodes[k].h&&nodes[xue[nodes[k].i][c]-1].step<nodes[k].step+1)
                                 nodes[xue[nodes[k].i][c]-1].step=nodes[k].step+1;
                       if(d<=m&&xue[nodes[k].i][d]>nodes[k].h&&nodes[xue[nodes[k].i][d]-1].step<nodes[k].step+1)
                                 nodes[xue[nodes[k].i][d]-1].step=nodes[k].step+1;
    }
    i=nodes[0].step;
    for(k=1;k<m*n;k++)
       if(i<nodes[k].step)i=nodes[k].step;
    printf("%d\n",i);
    return 0;
}
                       
                       
                       
                       
    
