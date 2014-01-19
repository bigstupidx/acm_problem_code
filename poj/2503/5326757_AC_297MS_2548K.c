#include<stdio.h>
#include<string.h>
struct node{
       char s1[12],s2[12];
}nodes[100002];
int k;
int cmp(const void *e1,const void *e2)
{
    struct node *p1,*p2;
    p1=(struct node *)e1;
    p2=(struct node *)e2;
    return strcmp(p1->s2,p2->s2);
}
int find(char ss[])
{
    int low=0,high=k-1,middle,aa;
    while(low<=high){
                     middle=(low+high)/2;
                     aa=strcmp(nodes[middle].s2,ss);
                     if(!aa)return middle;
                     if(aa<0)low=middle+1;
                     else high=middle-1;
    }
    return -1;
}
int main()
{
    char ss[30];
    k=0;
    while(gets(ss)&&ss[0])
    {
          int i,len;
          len=strlen(ss);
          for(i=0;i<len;i++)
                            if(ss[i]==' ')break;
          strcpy(nodes[k].s2,ss+i+1);
          ss[i]='\0';
          strcpy(nodes[k].s1,ss);
          k++;
    }
    qsort(nodes,k,sizeof(nodes[0]),cmp);
    while(gets(ss)&&ss[0]){
                           int aa=find(ss);
                           if(aa==-1)printf("eh\n");
                           else printf("%s\n",nodes[aa].s1);
    }
    return 0;
}
