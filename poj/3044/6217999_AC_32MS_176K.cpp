#include <cstdio>
#include <stack>
using namespace std;
int main()
{
    int n,w;
    while(scanf("%d%d",&n,&w)!=EOF)
    {
        int ans=0;
        stack<int>S;
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(y==0){
                while(!S.empty())S.pop();
                continue;
            }
            if(!S.empty())
            {
                while(!S.empty()&&S.top()>y)S.pop();
                if(S.empty()){
                    ans++;
                    S.push(y);
                    continue;
                }
                int yy=S.top();
                if(yy<y){ans++;S.push(y);}
            }
            else
            {
                ans++;
                S.push(y);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
