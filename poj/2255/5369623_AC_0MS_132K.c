//ÒÑÖª¶þ²æÊ÷µÄÇ°Ðò£¬ÖÐÐò£¬ÇóºóÐòÐòÁÐ 
#include<stdio.h>
#include<string.h>
char s1[50],s2[50],s3[50];
int tryy(int p,int w1,int w2,int a1,int a2)
{
    char key=s1[p];
    int pos=strchr(s2,key)-s2,l1=pos-w1,l2=w2-pos;
    s3[a2]=key;
    if (l1>0) tryy(p+1,w1,pos-1,a1,a1+l1-1);
    if (l2>0) tryy(p+l1+1,pos+1,w2,a1+l1,a2-1);
	return 1;
}
int main()
{
    int i,j,l;
    while (scanf("%s %s",s1,s2)!=EOF)
    {
        l=strlen(s1);s3[l]='\0';  
        tryy(0,0,l-1,0,l-1); 
        printf("%s\n",s3); 
    }
	return 0;
}
