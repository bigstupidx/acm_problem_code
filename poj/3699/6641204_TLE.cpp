#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
int n,m,k,flag[10002],maxLen[16],id[16];
char name[12][80],type[12][5],rec[10002][10][80],sel[16][80],tem[200],str[2][200];
int get_head(){
    int j=0,k=0,len=strlen(str[0])+1;
    str[0][len-1]=',';str[0][len]=0;
    for(int i=0;i<len;i++){
        if(str[0][i]==','){
            for(int ii=j;ii<i;ii++)
                sel[k][ii-j]=str[0][ii];
            sel[k][i-j]=0;
            k++;j=i+1;
        }
    }
    return k;
}
int get_value(int i,int j){
    int len=strlen(rec[i][j]),ans=0;
    for(int ii=0;ii<len;ii++){
        ans*=10;
        ans+=rec[i][j][ii]-'0';
    }
    return ans;
}
void select(int j,int op,int num){
    if(strcmp(type[j],"STR")==0){
        for(int i=0;i<m;i++){
            if(strcmp(rec[i][j],str[1])==0){
                flag[i]=1;
            }
        }
    }
    else{
        if(op==0){
            for(int i=0;i<m;i++){
                if(get_value(i,j)==num)
                    flag[i]=1;
            }
        }
        else if(op==1){
            for(int i=0;i<m;i++){
                if(get_value(i,j)<num)
                    flag[i]=1;
            }
        }
        else if(op==2){
            for(int i=0;i<m;i++){
                if(get_value(i,j)>num)
                    flag[i]=1;
            }
        }
    }
}
void print_head(int top){
    for(int i=0;i<top;i++){
        for(int j=0;j<maxLen[i];j++){
            printf("-");
        }
        if(i!=top-1)printf("-");
    }
}
void print_str(int len,char *str){
    printf("|");
    int xlen=strlen(str);
    int x=(len-xlen)/2,y=len-x-xlen;
    for(int i=0;i<x;i++)
        printf(" ");
    printf("%s",str);
    for(int i=0;i<y;i++)
        printf(" ");
}
void my_print(int top){
    printf("+");print_head(top);puts("+");
    for(int i=0;i<top;i++)
        print_str(maxLen[i],sel[i]);
    printf("|\n|");
    for(int i=0;i<top;i++){
        for(int j=0;j<maxLen[i];j++){
            printf("-");
        }
        if(i!=top-1)printf("|");
    }
    puts("|");
    for(int i=0;i<m;i++){
        if(!flag[i])continue;
        for(int j=0;j<top;j++){
            print_str(maxLen[j],rec[i][id[j]]);
        }
        puts("|");
    }
    printf("+");print_head(top);puts("+");
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        map<string,int>mp;
        for(int i=0;i<n;i++){
            scanf("%s%s",name[i],type[i]);
            mp[name[i]]=i;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%s",rec[i][j]);
            }
        }
        for(int ii=0;ii<k;ii++){
            scanf("%s%s%s%s",tem,str[0],tem,str[1]);

            memset(flag,0,sizeof(flag));
            memset(maxLen,0,sizeof(maxLen));

            int top=get_head();
            int j=0,len=strlen(str[1]),op,num=0;
            for(int i=0;i<len;i++){
                if(str[1][i]=='='){
                    op=0;
                    for(int k=0;k<i;k++)
                        str[0][k]=str[1][k];
                    str[0][i]=0;
                    if(str[1][i+1]=='"'){
                        for(int k=i+2;k<len-1;k++)
                            str[1][k-i-2]=str[1][k];
                        str[1][len-i-3]=0;
                    }
                    else{
                        i++;
                        while(i<len){
                            num*=10;
                            num+=str[1][i]-'0';
                        }
                    }
                    break;
                }
                else if(str[1][i]=='<'||str[1][i]=='>'){
                    if(str[1][i]=='<')op=1;
                    else if(str[1][i]=='>')op=2;
                    
                    for(int k=0;k<i;k++)
                        str[0][k]=str[1][k];
                    str[0][i]=0;

                    i++;
                    while(i<len){
                        num*=10;
                        num+=str[1][i]-'0';
                        i++;
                    }
                    break;
                }
            }
            //printf("%s %s %d %d\n",str[0],str[1],op,num);
            j=(mp.find(str[0]))->second;
            select(j,op,num);
            for(int i=0;i<top;i++)
                id[i]=(mp.find(sel[i]))->second;
            for(int i=0;i<top;i++)
                maxLen[i]=strlen(name[id[i]]);
            for(int i=0;i<m;i++){
                if(!flag[i])continue;
                for(int j=0;j<top;j++){
                    if(maxLen[j]<strlen(rec[i][id[j]]))
                        maxLen[j]=strlen(rec[i][id[j]]);
                }
            }
            for(int i=0;i<top;i++)
                maxLen[i]+=2;
            /*for(int i=0;i<m;i++)
                printf("%d ",flag[i]);
            puts("");
            for(int i=0;i<top;i++)
                printf("%d ",maxLen[i]);
            puts("");*/
            my_print(top);
        }
    }
    return 0;
}
