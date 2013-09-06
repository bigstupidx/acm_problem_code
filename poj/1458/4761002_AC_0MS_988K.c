#include<stdio.h>
#include<string.h>
#define MAX 1000
char str1[MAX],str2[MAX];
int max[MAX][MAX];
int main()
{
    while(scanf("%s%s",str1+1,str2+1)>0){
          int len1,len2,i,j;
          len1=strlen(str1+1);
          len2=strlen(str2+1);
          for(i=0;i<=len1;i++)
             max[i][0]=0;
          for(i=1;i<=len2;i++)
             max[0][i]=0;
          for(i=1;i<=len1;i++)
             for(j=1;j<=len2;j++){
                       if(str1[i]==str2[j])
                           max[i][j]=max[i-1][j-1]+1;
                       else{
                            int nlen1=max[i-1][j];
                            int nlen2=max[i][j-1];
                            if(nlen1<nlen2)nlen1=nlen2;
                            max[i][j]=nlen1;
                       }
          }
          printf("%d\n",max[len1][len2]);
    }
    return 0;
}
            
