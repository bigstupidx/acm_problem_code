#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

int main(){
    char ch[4];
    int maxn, n, tem;
    while(scanf("%d", &maxn)!=EOF){
        map<int,int>list;
        map<int,int>rise;
        map<int,int,greater<int> > down;
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d", &tem);
            list[tem]=1;
        }
        int cnt=0, flag=1;
        while(scanf("%s", ch), ch[0]!='e'){
            if(ch[0]=='a'){
                scanf("%d", &tem);
                rise[tem]=1;
                down[tem]=1;
            }
            else if(ch[0]=='p'){
                scanf("%d", &flag);
            }
            else{
                cnt++;
                tem = -1;
                if(!rise.empty()){
                    if(flag==1){
                        tem=rise.begin()->first;
                        rise.erase(rise.begin());
                        down.erase(down.find(tem));
                    }
                    else{
                        tem=down.begin()->first;
                        down.erase(down.begin());
                        rise.erase(rise.find(tem));
                    }
                }
                if(list.find(cnt)!=list.end()){
                    printf("%d\n", tem);
                }
            }
        }
    }
    return 0;
}
