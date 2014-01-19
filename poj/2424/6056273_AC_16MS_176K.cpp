#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int main()
{
    int n1,n2,n3;
    while(scanf("%d%d%d",&n1,&n2,&n3),n1||n2||n3)
    {
        char str[20];
        int ans=0,t1,t2,n;
        priority_queue<int>Q1,Q2,Q3;
        while(scanf("%s",str),str[0]!='#')
        {
            scanf("%d",&n);
            t1=(str[0]-'0')*10+str[1]-'0';
            t2=(str[3]-'0')*10+str[4]-'0';
           // printf("%d %d\n",t1,t2);
            t1=-(t1*60+t2);
            if(n==1||n==2)
            {
                if(n1==0)continue;
                while(!Q1.empty())
                {
                    int tt=Q1.top();
                    if(tt>=t1)Q1.pop();
                    else break;
                }
                if(Q1.size()<n1){
                    ans+=n;
                    Q1.push(t1-30);
                }
                else if(Q1.size()==n1){
                    int tt=Q1.top();
                    if(tt>=t1-30){
                        ans+=n;
                        Q1.pop();
                        Q1.push(tt-30);
                    }
                }
            }
            else if(n==3||n==4)
            {
                if(n2==0)continue;
                while(!Q2.empty())
                {
                    int tt=Q2.top();
                    if(tt>=t1)Q2.pop();
                    else break;
                }
                if(Q2.size()<n2){
                    ans+=n;
                    Q2.push(t1-30);
                }
                else if(Q2.size()==n2){
                    int tt=Q2.top();
                    if(tt>=t1-30){
                        ans+=n;
                        Q2.pop();
                        Q2.push(tt-30);
                    }
                }
            }
            else if(n==5||n==6){
                if(n3==0)continue;
                while(!Q3.empty())
                {
                    int tt=Q3.top();
                    if(tt>=t1)Q3.pop();
                    else break;
                }
                if(Q3.size()<n3){
                    ans+=n;
                    Q3.push(t1-30);
                }
                else if(Q3.size()==n3){
                    int tt=Q3.top();
                    if(tt>=t1-30){
                        ans+=n;
                        Q3.pop();
                        Q3.push(tt-30);
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
