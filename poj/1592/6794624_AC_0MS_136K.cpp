#include <cstdio>
#include <cstring>

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

char op[8], font[8], str[200];

void my_init(){
    for(int i=0;i<60;i++){
        for(int j=0;j<60;j++){
            ans[i][j]='.';
        }
    }
}

int get_col(int len, int &start, int &flag){
    int ans=0;
    if(strcmp(font, "C1")==0){
        if(strcmp(op, ".C")==0){
            ans = 30-len/2;
            if(ans<0){
                ans=0;
                start=len/2-30;
            }
        }
        else if(strcmp(op, ".R")==0){
            ans=60-len;
            if(ans<0){
                ans=0;
                start=len-60;
            }
        }
    }
    else{
        if(strcmp(op, ".C")==0){
            ans = 30 - 3 * len;
            if(ans < 0){
                ans = 0;
                start = len / 2 - 5;
                if(len % 2)flag = 1;
            }
        }
        else if(strcmp(op, ".R")==0){
            ans = 60 - 6*len;
            if(ans < 0){
                ans = 0;
                start = len - 10;
            }
        }
    }
    return ans;
}

void my_solve(){
    char ch;
    int row, col=0;
    scanf("%s%d", font, &row);
    row--;
    
    if(strcmp(op, ".P")==0){
        scanf("%d",&col);
        col--;
    }
    
    while((ch=getchar())!='|');
    gets(str);
    int len=strlen(str)-1;
    while(str[len]!='|')len--;
    
    int start=0, flag=0;
    if(strcmp(op, ".P")!=0){
        col=get_col(len, start, flag);
    }
    
    //printf("%d %d %s\n", len, start, str);
    if(strcmp(font, "C1")==0){
        for(int i = start; i < len && col < 60; i++, col++){
            if(str[i]!=' '){
                ans[row][col] = str[i];
            }
        }
    }
    else{
        if(flag){
            int x = str[start]-'A';
            for(int i=0;i<5;i++){
                for(int j=3;j<6;j++){
                    if(map[x][i][j]=='*'){
                        ans[row+i][j-3] = '*';
                    }
                }
            }
            start++;    col += 3;
        }
        for(int i = start; i < len && col < 60; i++, col += 6){
            if(str[i]==' ')continue;
            int x = str[i] - 'A';
            for(int j=0;j<5;j++){
                for(int k=0;k<6;k++){
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
    //freopen("out.txt", "w", stdout);
    while(scanf("%s",op)!=EOF){
        my_init();
        my_solve();
        while(scanf("%s",op), strcmp(op,".EOP")){
            my_solve();
        }
        my_print();
    }
    return 0;
}
