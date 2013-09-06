#include <cstdio>
#include <cstring>

char sta[100];
int k, arr[100];

int main()
{
    int nca;
    scanf("%d",&nca);
    while(nca--){
        __int64 n;
        scanf("%d%s%I64d",&k, sta, &n);
        int j=k-1;
        memset(arr,0,sizeof(arr));
        while(j>=0&&n){
            if(n%2){
                arr[j]=1;
                if(sta[j]=='n'){
                    n++;
                }
            }
            //printf("%d %c\n", n, sta[j]);
            j--; n/=2;
        }
        if(n)puts("Impossible");
        else{
            for(int i=0;i<k;i++)
                printf("%d",arr[i]);
            puts("");
        }
    }
    return 0;
}
