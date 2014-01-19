#include<stdio.h>
#include<string.h>
void main()
{
	int t;
	scanf("%d",&t);
	while(t--){
        int i,j,k,len1,len2;
		char a[110],b[110],c[110];
		scanf("%s%s",a,b);
		len1=strlen(a);len2=strlen(b);
		strcpy(c,b);
		strrev(c);j=0;k=0;
		for(i=0;i<len1;i++){
                           if(!b[j]||!c[k])break;
                           if(b[j]==a[i])j++;
                           if(c[k]==a[i])k++;
       }
       if(j>=len2||k>=len2)printf("YES\n");
       else printf("NO\n");
   }
   return 0;
}
                           

