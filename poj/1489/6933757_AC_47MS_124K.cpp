#include <cstdio>
#include <cstring>

char str[2][100];
int aa, bb, cc, arr[100], m, num[12];

int get_num(int ii){
    int len = strlen(str[ii]), ans=0;
    for(int i=0;i<len;i++){
        if(str[ii][i]=='|')
            ans++;
        else if(str[ii][i]=='n')
            ans+=10;
        else if(str[ii][i]=='9')
            ans+=100;
        else if(str[ii][i]=='8')
            ans+=1000;
        else if(str[ii][i]=='r')
            ans+=10000;
    }
    return ans;
}

void printf_char(int num, int k){
    if(k==0){
        for(int i=0;i<num;i++){
            putchar('|');
        }
    }
    else if(k==1){
        for(int i=0;i<num;i++){
            putchar('n');
        }
    }
    else if(k==2){
        for(int i=0;i<num;i++){
            putchar('9');
        }
    }
    else if(k==3){
        for(int i=0;i<num;i++){
            putchar('8');
        }
    }
    else if(k==4){
        for(int i=0;i<num;i++){
            putchar('r');
        }
    }
    else{
        for(int i=0;i<num;i++){
            putchar(' ');
        }
    }
}

int printf_num(int n){
    int k = 0, cnt = 0;;
    memset(num, 0, sizeof(num));
    while(n){
        num[k++]=n%10;
        n/=10;
    }
    for(int i=0;i<k;i++){
        if(num[i]){
            cnt+=num[i]+1;
            printf_char(num[i], i);
            putchar(' ');
        }
    }
    return cnt;
}

void solve(){
    int tem, fi = 1;
    tem = bb, m = 0;
    while(tem){
        arr[m++]=tem%2;
        tem/=2;
    }
    m = 0;
    while(fi <= bb){
        int len;
        len = printf_num(fi);
        if(arr[m]){
            len+=1;
            printf("*");
        }
        len = 34 - len;
        printf_char(len, -1);
        printf_num(aa);
        aa*=2;
        fi*=2;
        puts("");
        m++;
    }
    printf("The solution is: ");
    printf_num(cc);
    puts("");
    return ;
}

int main(){
    while(gets(str[0])){
        if(strcmp("", str[0])==0)break;
        gets(str[1]);
        aa = get_num(0);
        bb = get_num(1);
        cc = aa * bb;
        solve();
    }
    return 0;
}