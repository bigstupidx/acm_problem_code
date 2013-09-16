#include <cstdio>
#include <cstring>

int k, arr[100];
char sta[100];
__int64 n;

int main()
{
    int nca;
    scanf("%d",&nca);
    while(nca--){
        int k;
        scanf("%d%s%I64d", &k, sta, &n);
        memset(arr, 0, sizeof(arr));
        int j=k-1;
        while(n&&j>=0){
            if(n%2){
                arr[j]=1;
                if(sta[j]=='n')
                    n++;
                else
                    n--;
            }
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
