#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXN 2000
#define MAXM 4000000
struct edgetype
{
	int to;
	edgetype *next;
} edge1[MAXM],edge2[MAXM];
edgetype *front[MAXN];
edgetype *back[MAXN];

struct ceretype
{
	int a,b;
} cere[1000][2];
int fa[MAXN];
bool color[MAXN];
int nextorder[MAXN];
int choose[MAXN];
int finishtime,n,m;
int zero(int x)
{
	return 2 * x;
}
int one(int x)
{
	return 2 * x + 1;
}
bool intersect(ceretype i, ceretype j)
{
	ceretype w;
	if (i.a > j.a || i.a == j.a && i.b > j.b)
	{
		w = i; i = j; j = w;
	}
	return i.b > j.a;
	
}
void add(int x, int y, int &tot)
{
	edge1[tot].to = y; edge1[tot].next = front[x]; front[x] = edge1 + tot;
	edge2[tot].to = x; edge2[tot].next = back[y]; back[y] = edge2 + tot;
	++tot;
}

void readdata()
{
	int tot = 0;
	scanf("%d",&n);
	int a1,a2,b1,b2,a,b,c;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d:%d %d:%d %d",&a1,&b1,&a2,&b2,&c);
		a = a1 * 60 + b1; b = a2 * 60 + b2;
		cere[i][0].a = a; cere[i][0].b = a + c;
		cere[i][1].a = b - c; cere[i][1].b = b;
	}		
	for (int i = 0 ; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
		{
			if (intersect(cere[i][0], cere[j][0]))
			{
				add(zero(i), one(j), tot);
				add(zero(j), one(i), tot);
			}
			if (intersect(cere[i][0], cere[j][1]))
			{
				add(zero(i), zero(j), tot);
				add(one(j) , one(i) , tot);
			}
			if (intersect(cere[i][1], cere[j][0]))
			{
				add(one(i),one(j),tot);
				add(zero(j), zero(i) , tot);
			}
			if (intersect(cere[i][1], cere[j][1]))
			{
				add(one(i) ,zero(j), tot);
				add(one(j) ,zero(i), tot);
			}
		}
}

void DFS1(int now)
{
	color[now] = false;
	for (edgetype *e = front[now]; e ; e = e -> next)
		if (color[e -> to]){
			DFS1(e -> to);}
	nextorder[finishtime++] = now;
}
void DFS2(int now, int root)
{
	color[now] = true;
	fa[now] = root;
	for (edgetype *e = back[now]; e ; e = e -> next)
		if (!color[e -> to])
			DFS2(e -> to, root);
}

bool ok()
{
	memset(color, true , sizeof(color));
	for (int i = 0; i < n + n; ++i)
		if (color[i])
			DFS1(i);
	for (int i = 0; i < n + n; ++i) fa[i] = i;
	for (int i = n + n - 1; i >= 0; --i)
		if (!color[nextorder[i]])
			DFS2(nextorder[i],nextorder[i]);
	for (int i = 0; i < n; ++i)
		if (fa[zero(i)] == fa[one(i)]) return false;
	return true;
	
}
int main()
{
	readdata();
	if (ok())
	{
		puts("YES"); 
		memset( front , 0 , sizeof(front));
		int tot = 0;
		for (int i = 0; i < n + n; ++i)
			if (fa[i] == i)
				for (int j = 0; j < n + n; ++j)
					if (fa[j] == i)
						for (edgetype * e = back[j] ; e; e = e -> next)
						{
							edge1[tot].to = fa[e -> to]; edge1[tot].next = front[i]; front[i] = edge1 + tot;
							++tot;
						}
		memset(color, true , sizeof(color));
		memset(choose , -1 ,sizeof(choose));
		finishtime = 0;
		for (int i = 0; i < n + n; ++i)
			if (fa[i] == i && color[i]) DFS1(i);
		for (int i = finishtime - 1; i >=0 ; --i)
			if (choose[nextorder[i] / 2] == -1)
				for (int j = 0; j < n + n; ++j)
					if (fa[j] == nextorder[i])
						choose[j / 2] =  j & 1;
		int a,b;
		for (int i = 0; i < n; ++i)
		{
			a = cere[i][choose[i]].a; b = cere[i][choose[i]].b;
			printf("%02d:%02d %02d:%02d\n",a / 60 , a % 60, b / 60 , b % 60);
		}
	} else puts("NO");
	system("pause");
}
