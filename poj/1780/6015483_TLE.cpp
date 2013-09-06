#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
int map[10000010][10],n,nsta,k;
char ans[10000010];
/*void euler(int s)
{
    for(int i=0;i<10;i++)
    {
        if(map[s][i])
        {
            map[s][i]--;
            euler((s*10+i)%nsta);
            ans[k--]=i+'0';
        }
    }
}/*/
void euler(int s)
{
    stack<int>S;S.push(s);
    while(!S.empty())
    {
        int j,i=S.top();
        for(j=0;j<10;j++)
        {
            if(map[i][j])
            {
                map[i][j]=0;
                ans[k++]=j+'0';
                S.push((i*10+j)%nsta);
                break;
            }
        }
        if(j==10)S.pop();
    }
}
int main()
{
    while(scanf("%d",&n),n)
    {
        nsta=1;
        for(int i=1;i<n;i++)nsta*=10;
        for(int i=0;i<nsta;i++)
            for(int j=0;j<10;j++)
                map[i][j]=1;
        ans[nsta*10]=0;
        k=0;  euler(0);
        for(int i=1;i<n;i++)printf("0");
        printf("%s\n",ans);
    }
    return 0;
}
