#include<stdio.h>
char tel[100000][9];
char map[]="2223334445556667777888999";
int n;

int compare(const void *elem1,const void *elem2){
    return(strcmp((char *)elem1,(char *)elem2));
}
void standard(char *str,int k)
{
     int i,j;
     i=j=-1;
     while(i<8){
                j++;
                if(str[j]=='-')
                   continue;
                i++;
                if(i==3){
                   tel[k][i]='-';
                   i++;}
                if(str[j]>='A'&&str[j]<='Z')
                   tel[k][i]=map[str[j]-'A'];
                else 
                   tel[k][i]=str[j];
     }
     tel[k][8]='\0';
     return;
}
                
                
int main()
{
    int flag=1;
    char *str;
    int i;
    scanf("%d",&n);
    i=0;
    while(i<n)
    {
              gets(str);
              standard(str,i);
              i++;
    }
    qsort(tel,n,9,compare);
    i=0;
    while(i<n){
               int k;
               k=i;
               while(i<n&&strcmp(tel[i],tel[k])==0)i++;
               if(i-k>1){
                         printf("%s %d",tel[k],i-k);
                         flag=0;
               }
    }
    if(flag)
            printf("No duplicates.\n");
}
               
    
    
    
