#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
               int len1,len2;
               char al[100],bl[100];
               int i,j,a[100],b[100];
               memset(a,0,sizeof(a));
               memset(b,0,sizeof(b));
               scanf("%s%s",al,bl);
               
               i=0;len1=len2=0;
               while(al[i++]=='0');
               if(i>0)i--;
               for(j=0;al[i];i++){
                   a[j++]=al[i]-'0';len1++;}
               
               i=0;
               while(bl[i++]=='0');
               if(i>0)i--;
               for(j=0;bl[i];i++){
                   b[j++]=bl[i]-'0';len2++;}
                   
               if(len2>len1)len1=len2;
               for(i=0;i<=len1;i++){
                   a[i]+=b[i];
                   if(a[i]>=10){
                   a[i+1]+=1;
                   a[i]-=10;}
               }
              /* for(i=0;i<=len1;i++)
                   al[i]=a[i]+'0';*/
              i=0;while(!a[i++]);
              if(i>0)i--;
              for(j=len1+3;!a[j];j--);
              for(;i<j;i++)
                   printf("%d",a[i]);
              printf("%d\n",a[i]);
    }
    return 0;
}
                  
                   
