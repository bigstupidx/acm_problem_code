#include <cstdio>
__int64 arrey[120];
void pre_done()
{
    arrey[0]=1;
    arrey[1]=1;
    arrey[2]=2;
    for(int i=3;i<120;i++){
        arrey[i]=0;
        for(int j=0;j<i;j++)
            arrey[i]+=arrey[j]*arrey[i-j-1];
    }
    return ;
}
int main()
{
    int n;
    pre_done();arrey[0]=0;
    while(scanf("%d",&n),n!=-1)
        printf("%d\n",arrey[n]);
    return 0;
}
