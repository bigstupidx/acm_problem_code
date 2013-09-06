#include<stdio.h>
#include<string.h>

char show[7][11]={"- -- -----","|   ||| ||","|||||  |||",
             "  ----- --","| |   | | ","|| |||||||","- -- -- --"};

int main()
{
    int s;
    char str[9];
    while(scanf("%d%s",&s,str)&&s!=0&&str[0]!='0'){
             int i,len,j,k;
             len=strlen(str);
             for(i=0;i<len;i++){
                                printf(" ");
                                for(j=0;j<s;j++)
                                    printf("%c",show[0][str[i]-'0']);
                                printf(" ");
             }
             printf("\n");
             for(i=0;i<s;i++){
                              for(j=0;j<len;j++){
                                     printf("%c",show[1][str[j]-'0']);
                                     for(k=0;k<s;k++)printf(" ");
                                     printf("%c",show[2][str[j]-'0']);
                              }
                              printf("\n");
             }
             for(i=0;i<len;i++){
                                printf(" ");
                                for(j=0;j<s;j++)
                                    printf("%c",show[3][str[i]-'0']);
                                printf(" ");
             }
             printf("\n");
             for(i=0;i<s;i++){
                              for(j=0;j<len;j++){
                                     printf("%c",show[4][str[j]-'0']);
                                     for(k=0;k<s;k++)printf(" ");
                                     printf("%c",show[5][str[j]-'0']);
                              }
                              printf("\n");
             }
             for(i=0;i<len;i++){
                                printf(" ");
                                for(j=0;j<s;j++)
                                    printf("%c",show[6][str[i]-'0']);
                                printf(" ");
             }
             printf("\n");
    }
    return 0;
}
