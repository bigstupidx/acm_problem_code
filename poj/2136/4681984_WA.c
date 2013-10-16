#include<stdio.h>
int main()
{
    int al[26];
    int i,j,temp1,k,temp2;
    char c;
    memset(al,0,sizeof(al));
    for(i=0;i<4;i++){
                     while((c=getchar())!='\n'){
                                               if(c==' ')
                                                  continue;
                                               else
                                                  al[c-'A']++;
                     }
    }
    for(i=1,temp1=0;i<26;i++)
        if(al[temp1]<al[i])temp1=i;
    for(i=1,temp2=0;i<26;i++)
        if(al[temp2]>al[i])temp2=i;
    for(i=al[temp1];i>=al[temp2];i--){
        int flag=0;
        if(i==0)break;
        for(j=0;j<26;j++){
           if(j==0){
                    if(al[j]>=i)printf("*");
                    else printf(" ");
           }
           else if(al[j]>=i){
                printf(" *");
                for(k=j;k<26;k++)
                    if(al[k]<al[j])flag++;
                if(flag==25-j)break;
           }
           else if(al[j]<i)printf("  ");
        }
        printf("\n");
    }
    puts("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
    return 0;    
}
                     
