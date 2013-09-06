#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

char name[120], pro[120];

struct node{
    char name[120];
    int cnt;
    bool operator <(const node &a)const{
        if(a.cnt==cnt)
            return strcmp(a.name, name)>0;
        return a.cnt < cnt;
    }
}nod[120];
vector<int>arr[10002];
int main(){
    while(1){
        gets(name);
        if(strcmp(name, "0")==0)break;
        if(strcmp(name, "1")==0)continue;
        int user_id = 0, pro_id = 0, i, j;
        map<string,int>proj, user;
        map<string,int>::iterator p;
        for(int i=0;i<10002;i++)arr[i].clear();
        strcpy(pro, name);
        strcpy(nod[0].name, name);
        nod[0].cnt=0;
        proj[name]=pro_id++;
        while(1){
            gets(name);
            if(strcmp(name, "1")==0)break;
            if(name[0]>='A'&&name[0]<='Z'){
                strcpy(pro, name);
                if(proj.find(name)==proj.end()){
                    proj[name]=pro_id;
                    strcpy(nod[pro_id].name,name);
                    nod[pro_id].cnt=0;
                    pro_id++;
                }
            }
            else{
                p=user.find(name);
                if(p==user.end()){
                    user[name]=user_id;
                    i=user_id++;
                }
                else i=p->second;
                j=proj.find(pro)->second;
                arr[i].push_back(j);
            }
        }
        for(int i=0;i<user_id;i++){
            if(arr[i].size()>1){
                sort(arr[i].begin(), arr[i].end());
                int flag=0;
                for(int j=1;j<arr[i].size();j++){
                    if(arr[i][j]!=arr[i][j-1]){
                        flag=1;
                        break;
                    }
                }
                if(!flag){
                    nod[arr[i][0]].cnt++;
                }
            }
            else{
                nod[arr[i][0]].cnt++;
            }
        }
        sort(nod, nod+pro_id);
        for(int i=0;i<pro_id;i++){
            printf("%s %d\n", nod[i].name, nod[i].cnt);
        }
    }
    return 0;
}