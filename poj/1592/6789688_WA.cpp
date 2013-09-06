#include <cstdio>
#include <cstring>
#include <cstdlib>

char ans[80][80];
char map[28][6][8] = {
    {".***..", "*...*.", "*****.", "*...*.", "*...*."},
    {"****..", "*...*.", "****..", "*...*.", "****.."},
    {".****.", "*...*.", "*.....", "*.....", ".****."},
    {"****..", "*...*.", "*...*.", "*...*.", "****.."},
    {"*****.", "*.....", "***...", "*.....", "*****."},
    {"*****.", "*.....", "***...", "*.....", "*....."},
    {".****.", "*.....", "*..**.", "*...*.", ".***.."},
    {"*...*.", "*...*.", "*****.", "*...*.", "*...*."},
    {"*****.", "..*...", "..*...", "..*...", "*****."},
    {"..***.", "...*..", "...*..", "*..*..", ".**..."},
    {"*...*.", "*..*..", "***...", "*..*..", "*...*."},
    {"*.....", "*.....", "*.....", "*.....", "*****."},
    {"*...*.", "**.**.", "*.*.*.", "*...*.", "*...*."},
    {"*...*.", "**..*.", "*.*.*.", "*..**.", "*...*."},
    {".***..", "*...*.", "*...*.", "*...*.", ".***.."},
    {"****..", "*...*.", "****..", "*.....", "*....."},
    {".***..", "*...*.", "*...*.", "*..**.", ".****."},
    {"****..", "*...*.", "****..", "*..*..", "*...*."},
    {".****.", "*.....", ".***..", "....*.", "****.."},
    {"*****.", "*.*.*.", "..*...", "..*...", ".***.."},
    {"*...*.", "*...*.", "*...*.", "*...*.", ".***.."},
    {"*...*.", "*...*.", ".*.*..", ".*.*..", "..*..."},
    {"*...*.", "*...*.", "*.*.*.", "**.**.", "*...*."},
    {"*...*.", ".*.*..", "..*...", ".*.*..", "*...*."},
    {"*...*.", ".*.*..", "..*...", "..*...", "..*..."},
    {"*****.", "...*..", "..*...", ".*....", "*****."},
};

char op[10], str[300], font[10];
void my_init(){
    for(int i=0;i<60;i++){
        for(int j=0;j<60;j++){
            ans[i][j]='.';
        }
    }
}
int get_col(int len, int &start){
    int ans=0;
    if(strcmp(op,".C")==0){
        if(strcmp(font,"C1")==0){
            ans=30-len/2;
            if(ans<0){
                ans=0;
                start=len/2-30;
            }
        }
        else{
            ans=30-3*len;
            if(ans<0){
                ans=0;
                start=(3*len-30)/6;
            }
        }
    }
    else if(strcmp(op, ".R")==0){
        if(strcmp(font,"C1")==0){
            ans=60-len;
            if(ans<0){
                ans=0;
                start=len-60;
            }
        }
        else{
            ans=60-6*len;
            if(ans<0){
                ans=0;
                start=len-10;
            }
        }
    }
    return ans;
}

void solve(){
    char ch;
    int row, col=0, start=0;
    
    scanf("%s%d",font,&row);
    row--;
    if(strcmp(op,".P")==0){
        scanf("%d",&col);
        col--;
    }
    
    while((ch=getchar())!='|');
    gets(str);
    int len = strlen(str)-1;
    while(str[len]!='|')len--;
    if(strcmp(op,".P")!=0){
        col=get_col(len, start);
    }
    //printf("%d %d %s\n",len,start,str);
    if(strcmp(font,"C1")==0){
        for(int i=start; i<len&&col<60; i++, col++){
            if(str[i]!=' '){
                ans[row][col]=str[i];
            }
        }
    }
    else{
        for(int i=start; i<len&&col<60; i++, col+=6){
            if(str[i]==' ')continue;
            int x=str[i]-'A';
            for(int k=0; k<6;k++){
                for(int j=0;j<5;j++){
                    if(map[x][j][k]=='*'){
                        ans[row+j][col+k]='*';
                    }
                }
            }
        }
    }
}

void my_print(){
    for(int i=0;i<60;i++){
        for(int j=0;j<60;j++){
            putchar(ans[i][j]);
        }
        puts("");
    }
    puts("");
    for(int i=0;i<60;i++)
        putchar('-');
    puts("\n");
}

int main()
{
    while(scanf("%s",op)!=EOF){
        my_init();
        solve();
        while(scanf("%s",op), strcmp(op,".EOP")){
            solve();
        }
        my_print();
    }
    return 0;
}
