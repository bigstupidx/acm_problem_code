#include <cstdio>
int arr[10000010];
void pre_done()
{
    arr[1]=1;
    int two=1,thr=1,k=2;
    while(k<10000001)
    {
        if(arr[two]*2<arr[thr]*3)
        {
            arr[k++]=arr[two]*2+1;
            two++;
        }
        else if(arr[two]*2>arr[thr]*3){
            arr[k++]=arr[thr]*3+1;
            thr++;
        }
        else{
            arr[k++]=arr[thr]*3+1;
            thr++;two++;
        }
    }
}
int main()
{
    int n;
    pre_done();
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",arr[n]);
    return 0;
}
