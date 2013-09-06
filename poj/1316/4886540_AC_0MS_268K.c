#include<stdio.h>
int arrey[20000];
int main()
{
    int i;
    memset(arrey,0,sizeof(arrey));
    for(i=1;i<10000;i++){
        int a,b,c,t;
        t=i;
        a=t/1000;
        t=t-a*1000;
        b=t/100;
        t=t-b*100;
        c=t/10;
        t=t-c*10;
        arrey[t+a+b+c+i]=1;
    }
    for(i=1;i<10000;i++)
        if(!arrey[i])
            printf("%d\n",i);
    return 0;
}
