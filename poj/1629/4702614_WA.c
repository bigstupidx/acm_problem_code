#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,n,m,p;
    int al[26];
    char bl[11];
    memset(al,0,sizeof(al));
    scanf("%d%d%d",&m,&n,&p);
    for(i=0;i<m;i++){
                     scanf("%s",bl);
                     for(j=0;bl[j]!='\0';j++)
                          al[bl[j]-'A']++;
    }
    for(i=0;i<p;i++){
                     scanf("%s",bl);
                     for(j=0;bl[j]!='\0';j++)
                          al[bl[j]-'A']--;
    }
    for(i=0;i<26;i++)
       for(j=i;al[i];al[i]--)
         printf("%c",'A'+i);
    printf("\n");
    return 0;
}
