#include<stdio.h>
#include<string.h>

void trans()
{
     int i;
     char al[27]="VWXYZABCDEFGHIJKLMNOPQRSTU";
     char str[300];
     gets(str);
     for(i=0;str[i]!='\0';i++)
         if(str[i]>='A'&&str[i]<='Z')str[i]=al[str[i]-'A'];
     printf("%s\n",str);
}
int main()
{
    while(1){
             char str1[20];
             gets(str1);
             if(!strcmp(str1,"ENDOFINPUT"))break;
             trans();
             gets(str1);
    }
    return 0;
}
