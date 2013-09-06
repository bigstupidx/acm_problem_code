#include <cstdio>
#include <cstring>
char str[30],map[100]="01SE Z  8        A   3  HIL JM O   2TUVWXY5";
int main()
{
    //for(int i=0;i<strlen(map);i++)
    //    printf("%c %c\n",i+'0',map[i]);
    while(scanf("%s",str)!=EOF)
    {
        int len=strlen(str);
        bool flag1=true,flag2=true;
        for(int i=0;i<=len/2;i++)
        {
            int j=len-i-1;
            //printf("%d %d %c %c\n",i,j,str[i],str[j]);
            //printf("%d %d ",flag1,flag2);
            if(str[i]!=str[j])
            {
                flag1=false;
                //printf("%c %c\n",str[i],str[j]);
                if((str[i]=='0'||str[i]=='O')&&(str[j]=='O'||str[j]=='0'))
                    continue;
                if(str[j]==map[str[i]-'0']||str[i]==map[str[j]-'0'])
                    continue;
                flag2=false;
            }
            else{
                if(str[i]!=map[str[j]-'0']&&str[j]!=map[str[i]-'0'])
                    flag2=false;
            }
            //printf("%d %d\n",flag1,flag2);
        }
        //printf("%d %d\n",flag1,flag2);
        if(flag1&&flag2)
            printf("%s -- is a mirrored palindrome.\n",str);
        else if(!flag1&&flag2)
            printf("%s -- is a mirrored string.\n",str);
        else if(!flag1&&!flag2)
            printf("%s -- is not a palindrome.\n",str);
        else
            printf("%s -- is a regular palindrome.\n",str);
        puts("");
    }
    return 0;
}
