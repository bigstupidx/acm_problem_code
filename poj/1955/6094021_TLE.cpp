#include <cstdio>
#include <cstring>
char str[60];
int ch[6][5][4]={
    1,13,46,45,
    4,25,49,33,
    7,37,52,21,
    10,12,36,34,
    11,24,35,22,
    
    13,15,39,37,
    14,27,38,25,
    12,9,40,46,
    24,8,28,47,
    36,7,16,48,
    
    16,18,42,40,
    17,30,41,28,
    15,3,43,48,
    27,6,31,51,
    39,9,19,54,
    
    19,21,45,43,
    20,33,44,31,
    18,1,34,54,
    30,2,22,53,
    42,3,10,52,
    
    1,3,9,7,
    2,6,8,4,
    15,12,21,18,
    14,11,20,17,
    13,10,19,16,
    
    46,48,54,52,
    47,51,53,49,
    37,40,43,34,
    38,41,44,35,
    39,42,45,36
};
void change(int k)
{
    for(int i=0;i<5;i++)
    {
        char tem=str[ch[k][i][0]-1];
        for(int j=0;j<3;j++)
            str[ch[k][i][j]-1]=str[ch[k][i][j+1]-1];
        str[ch[k][i][3]-1]=tem;
    }
}
void changeback(int k)
{
    for(int i=0;i<5;i++)
    {
        char tem=str[ch[k][i][3]-1];
        for(int j=3;j>0;j--)
            str[ch[k][i][j]-1]=str[ch[k][i][j-1]-1];
        str[ch[k][i][0]-1]=tem;
    }
}
int main()
{
    int nca;
    scanf("%d",&nca);
    for(int ii=1;ii<=nca;ii++)
    {
        for(int i=0;i<54;i++)
        {
            char tem;
            do{
                scanf("%c",&tem);
            }while(tem>'z'||tem<'a');
            str[i]=tem;
        }
        str[54]=0;
        //puts(str);
        int q;
        scanf("%d",&q);
        while(q--){
            int x,y;
            scanf("%d%d",&x,&y);
            if(y==-1)change(x);
            else changeback(x);
        }
        printf("Scenario #%d:\n",ii);
        for(int i=0;i<3;i++)
        {
            printf("     ");
            for(int j=0;j<3;j++)
                printf(" %c",str[i*3+j]);
            puts("");
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<12;j++)
                printf("%c ",str[9+i*12+j]);
            puts("");
        }
        for(int i=0;i<3;i++)
        {
            printf("     ");
            for(int j=0;j<3;j++)
                printf(" %c",str[45+i*3+j]);
            puts("");
        }
    }
    return 0;
}
