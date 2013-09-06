#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

int n, arr[1010], flag[1010];

int main(){
    int x=0;
    while(scanf("%d", &n), n){
        if(x)puts("");
        else x=1;

        while(scanf("%d", &arr[0]), arr[0]){
            stack<int>S;
            memset(flag,0,sizeof(flag));
            for(int i=1;i<n;i++){
                scanf("%d", &arr[i]);
            }
            int ans = 1, tem, j=1;
            for(int i=0;i<n;i++){
                tem = j;
                if(!S.empty()){
                    tem=S.top();
                    S.pop();
                }
                if(tem>arr[i])S.push(tem);
                while(tem <= arr[i]){
                    if(!flag[tem])
                        S.push(tem);
                    tem++;
                }
                tem=S.top();
                //printf("%d ",tem);
                if(tem > arr[i]){
                    ans=0;break;
                }
                flag[tem]=1;
                S.pop();
            }
            if(ans)puts("Yes");
            else puts("No");
        }
    }
    return 0;
}