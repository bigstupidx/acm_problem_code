#include<stdio.h>
#include<string.h>
int n,min;
char str[12][22];
int used[12];    
int ibeforej[12][12];
void mysearch(int total,int k,int ii)
{
     int i;
     if(total>min)return ;
     if(ii==n-1){
               min=total;
               return ;
     }
     for(i=0;i<n;i++){
                     if(used[i])continue;
                     used[i]=1;
                     mysearch(total+strlen(str[i])-ibeforej[k][i],i,ii+1);
                     used[i]=0;
     }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
               int i,j,flag;
               scanf("%d",&n);
               for(i=0;i<n;i++)
                  scanf("%s",str[i]);
               memset(ibeforej,0,sizeof(ibeforej));
               memset(used,0,sizeof(used));
               min=10000000;
               for(i=0;i<n;i++){
                      for(j=0;j<n;j++){
                            int len,len1,len2,k,l;
                            if(i==j)continue;
							
                            len1=strlen(str[i]);
                            len2=strlen(str[j]);
                            len=len1<len2?len1:len2;
                            for(k=len;k>0;k--){
								flag=0;
								for(l=0;l<k;l++)
                                    if(str[j][l]!=str[i][len1-k+l])
									{flag=1;break;}
								if(!flag){
									ibeforej[i][j]=k;
									break;
								}
                            }
                      }
               }
               for(i=0;i<n;i++){
                       used[i]=1;
                       mysearch(strlen(str[i]),i,0);
                       used[i]=0;
               }
               printf("%d\n",min);
    }
    return 0;
}
