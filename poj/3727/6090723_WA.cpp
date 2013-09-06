#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
char str[1010];
struct node{int u, ex;}nod[60];
struct node2{ int u, ex;}nod2[60];
inline int ABS(int a){return a>0?a:-a;}
double x_ex(double x,int n)
{
    double ans=1;
    for(int i=0;i<ABS(n);i++)ans*=x;
    if(n<0)return 1/ans;
    return ans;
}
double get_fn(double x0,int k)
{
    double ans=0;
    for(int i=0;i<=k;i++)
        ans+=nod[i].u*x_ex(x0,nod[i].ex);
    return ans;
}
double get_fn1(double x0,int k)
{
    double ans=0;
    for(int i=0;i<=k;i++)
        ans+=nod2[i].u*x_ex(x0,nod2[i].ex);
    return ans;
}
int main()
{
    while(gets(str))
    {
        if(strcmp(str,"")==0)continue;
        int k=-1,sign=1,len=strlen(str);
        bool flag1=false,flag2=false;
        for(int i=0;i<60;i++){nod[i].u=0;nod[i].ex=0;}
        for(int i=0;i<len;i++)
        {
            if(str[i]=='=')
            {
                if(!flag1)
                    nod[k].u*=sign;
                else if(flag1&&nod[k].ex!=0)
                    nod[k].ex*=sign;
                else nod[k].ex=1;
                break;
            }
            else if(str[i]=='x')
            {
                if(k==-1)k++;
                if(nod[k].u==0)nod[k].u=1;
                nod[k].u*=sign;
                flag1=true; sign=1;
            }
            else if(str[i]=='^')flag2=true;
            else if(str[i]==' ')continue;
            else if(str[i]=='-')
            {
                if(k==-1)k++;
                if(!flag2){
                    if(flag1&&nod[k].ex==0){
                        nod[k].ex=1;
                        k++;flag1=false;
                    }
                    else if(!flag1){
                        if(k>0)
                            nod[k].u*=sign,k++;
                    }
                }
                if(flag2&&nod[k].ex!=0){
                    nod[k].ex*=sign;
                    flag2=false;
                    k++;    flag1=false;
                }
                sign=-1;
            }
            else if(str[i]=='+')
            {
                if(k==-1)k++;
                if(!flag2){
                    if(flag1&&nod[k].ex==0){
                        nod[k].ex=1;
                        k++;flag1=false;
                    }
                    else if(!flag1){
                        if(k>=0)
                            nod[k].u*=sign,k++;
                    }
                }
                if(flag2&&nod[k].ex!=0){
                    nod[k].ex*=sign;
                    flag2=false;
                    k++;    flag1=false;
                }
                sign=1;
            }
            else
            {
                if(k==-1)k++;
                if(flag2){
                    //flag2=false;
                    nod[k].ex=nod[k].ex*10+str[i]-'0';
                }
                else{
                    if(!flag1)nod[k].u=nod[k].u*10+str[i]-'0';
                    else nod[k].u=nod[k].u*10+str[i]-'0';
                }
            }
        }
        //sort(nod,nod+k+1);
        //for(int i=0;i<=k;i++)
        //    printf("%d %d\n",nod[i].u,nod[i].ex);
        for(int i=0;i<=k;i++){
            if(nod[i].ex==0)
                nod2[i].u=0,nod2[i].ex=0;
            else
                nod2[i].u=nod[i].u*nod[i].ex,nod2[i].ex=nod[i].ex-1;;
        }
        int cnt=-1;
        double x0,x1,x2,t1,t2;
        scanf("%lf",&x0);getchar();
        do{
            t1=get_fn(x0,k);
            t2=get_fn1(x0,k);
            x1=x0-t1/t2;
            //printf("%lf %lf %lf %lf\n",t1,t2,x0,x1);
            x2=x0;  x0=x1;  x1=x2;  cnt++;
        }while(cnt<=1000&&fabs(x0-x1)>1e-6&&fabs(t1)>1e-6);
        if(cnt>1000)
            puts("Bad x0 or bad equation!");
        else printf("%d\n",cnt);
    }
    return 0;
}
