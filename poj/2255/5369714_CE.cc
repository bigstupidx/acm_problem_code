#include<stdio.h>
#include<malloc.h>
#include<string.h>
char str[2][28];
struct tnode{
       char ch;
       tnode *lchild,*rchild;
};
int i,len,used[28];
int myfind(char ch)
{
    int i;
    for(i=0;i<len;i++)
    if(str[1][i]==ch)return i;
}
void create(struct tnode **T)
{
     char c;
	 int j;
     c=str[0][i++];
     (*T)=(struct tnode *)malloc(sizeof(struct tnode));
     (*T)->ch=c;
     j=myfind(c);
     used[j]=1;
     if(j==0||used[j-1])(*T)->lchild=NULL;
     else create(&((*T)->lchild));
     if(used[j+1])(*T)->rchild=NULL;
     else create(&((*T)->rchild));
}
void output(struct tnode *T)
{
     if(!T)return ;
     if(T->lchild)output(T->lchild);
     if(T->rchild)output(T->rchild);
     printf("%c",T->ch);
     return ;
}
int main()
{
    while(scanf("%s%s",str[0],str[1])!=EOF){
          struct tnode *T;
          memset(used,0,sizeof(used));
          i=0;
          len=strlen(str[0]);
          used[len]=1;
          create(&T);
          output(T);
          printf("\n");
    }
    return 0;
}

