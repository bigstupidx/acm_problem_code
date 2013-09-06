#include <cstdio>
#include <map>
#include <string>
#include <cstring>
using namespace std;
struct records{
    char rec[12][100];
    int value[12];
}recd[10002];
int n,m,k,isint[12],maxLen[100],id[100],flag[10002];
char name[12][100],type[12][100],tem[100],str[2][1000],head[100][100];
int get_value(int i,int j){
    int len=strlen(recd[i].rec[j]),ans=0;
    for(int ii=0;ii<len;ii++){
        ans*=10;
        ans+=recd[i].rec[j][ii]-'0';
    }
    return ans;
}
int get_head(){
    int j=0,top=0;
    int len=strlen(str[0])+1;
    str[0][len-1]=',';    str[0][len]=0;
    for(int i=0;i<len;i++){
        if(str[0][i]==','){
            for(int x=j;x<i;x++)
                head[top][x-j]=str[0][x];
            head[top][i-j]=0;
            top++;  j=i+1;
        }
    }
    return top;
}
void select(int op,int num,int x,int top){
    memset(flag,0,sizeof(flag));
    if(isint[x]){
        if(op==0){
            for(int i=0;i<m;i++){
                if(recd[i].value[x]==num){
                    flag[i]=1;
                    for(int j=0;j<top;j++){
                        int len=strlen(recd[i].rec[id[j]]);
                        if(maxLen[j]<len)
                            maxLen[j]=len;
                    }
                }
            }
        }
        else if(op==1){
            for(int i=0;i<m;i++){
                if(recd[i].value[x]>num){
                    flag[i]=1;
                    for(int j=0;j<top;j++){
                        int len=strlen(recd[i].rec[id[j]]);
                        if(maxLen[j]<len)
                            maxLen[j]=len;
                    }
                }
            }
        }
        else {
            for(int i=0;i<m;i++){
                if(recd[i].value[x]<num){
                    flag[i]=1;
                    for(int j=0;j<top;j++){
                        int len=strlen(recd[i].rec[id[j]]);
                        if(maxLen[j]<len)
                            maxLen[j]=len;
                    }
                }
            }
        }
    }
    else{
        for(int i=0;i<m;i++){
            if(strcmp(recd[i].rec[x],str[0])==0){
                flag[i]=1;
                for(int j=0;j<top;j++){
                    int len=strlen(recd[i].rec[id[j]]);
                    if(maxLen[j]<len)
                        maxLen[j]=len;
                }
            }
        }
    }
    return ;
}
void print_char(int len,char ch){
    for(int i=0;i<len;i++)
        printf("%c",ch);
    return ;
}
void print_head(int top){
    for(int i=0;i<top;i++){
        print_char(maxLen[i],'-');
        if(i!=top-1)printf("-");
    }
    return ;
}
void print_str(int len,char *s){
    int xlen=strlen(s);
    int x=(len-xlen)/2;
    int y=len-xlen-x;
    printf("|");
    print_char(x,' ');
    printf("%s",s);
    print_char(y,' ');
    return ;
}
void my_print(int top){
    printf("+");print_head(top);puts("+");
    for(int i=0;i<top;i++)
        print_str(maxLen[i],head[i]);
    puts("|");
    for(int i=0;i<top;i++){
        printf("|");
        print_char(maxLen[i],'-');
    }
    puts("|");
    for(int i=0;i<m;i++){
        if(!flag[i])continue;
        for(int j=0;j<top;j++){
            print_str(maxLen[j],recd[i].rec[id[j]]);
        }
        puts("|");
    }
    printf("+");print_head(top);puts("+");
    return ;
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        map<string,int>mp;
        memset(isint,0,sizeof(isint));
        for(int i=0;i<n;i++){
            scanf("%s%s",name[i],type[i]);
            mp[name[i]]=i;
            if(strcmp(type[i],"INT")==0)
                isint[i]=1;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%s",recd[i].rec[j]);
                if(isint[j])
                    recd[i].value[j]=get_value(i,j);
            }
        }
        for(int ii=0;ii<k;ii++){
            scanf("%s%s%s%s",tem,str[0],tem,str[1]);
            
            int top=get_head();
            for(int i=0;i<top;i++)
                id[i]=(mp.find(head[i]))->second;
            memset(maxLen,0,sizeof(maxLen));
            for(int i=0;i<top;i++)
                maxLen[i]=strlen(name[id[i]]);
            
            int op,num=0;
            int len=strlen(str[1]);
            for(int i=0;i<len;i++){
                if(str[1][i]=='='){
                    op=0;
                    str[1][i]=0;
                    if(str[1][i+1]=='"'){
                        for(int j=i+2;j<len-1;j++){
                            str[0][j-i-2]=str[1][j];
                        }
                        str[0][len-i-3]=0;
                    }
                    else{
                        i++;
                        while(i<len){
                            num*=10;
                            num+=str[1][i]-'0';
                            i++;
                        }
                    }
                    break;
                }
                else if(str[1][i]=='>'||str[1][i]=='<'){
                    if(str[1][i]=='>')op=1;
                    else if(str[1][i]=='<')op=2;
                    str[1][i]=0;
                    while(i<len){
                        num*=10;
                        num+=str[1][i]-'0';
                        i++;
                    }
                    break;
                }
            }
            select(op,num,(mp.find(str[1]))->second,top);
            for(int i=0;i<m;i++)
                maxLen[i]+=2;
            my_print(top);
            puts("");
        }
    }
    return 0;
}

