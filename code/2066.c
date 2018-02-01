#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
输入:	数据有多组，每组的第一行是三个整数T，S和D，表示有T条路，和草儿家相邻的城市的有S个，草儿想去的地方有D个；
		接着有T行，每行有三个整数a，b，time,表示a,b城市之间的车程是time小时；(1=<(a,b)<=1000;a,b 之间可能有多条路)
		接着的第T+1行有S个数，表示和草儿家相连的城市；接着的第T+2行有D个数，表示草儿想去地方。
6 2 3
1 3 5
1 4 7
2 8 12
3 8 4
4 9 12
9 10 2
1 2
8 9 10

输出:	草儿能去某个喜欢的城市的最短时间。
9

**/
#define N 1000
#define Max 10000
int a[N][N],n,T,s,d;

void Init()
{
	int x,y,z,i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			a[i][j]=Max;
	n=0;
	for(i=1;i<=T;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(z<a[x][y])
			a[y][x]=a[x][y]=z;
		if(x>n)
			n=x;
		if(y>n)
			n=y;
	}
	n++;				//自加 1 ！！！
	for(i=1;i<=s;i++)	//初始化相邻的城市s个数据
	{
		scanf("%d",&x);
		a[0][x]=0;
	}
	for(i=1;i<=d;i++)	//初始化想去的地方d个数据
	{
		scanf("%d",&x);
		a[x][n]=0;
	}
}

/*
Dijkstra(迪杰斯特拉)算法是典型的单源最短路径算法，用于计算一个节点到其他所有节点的最短路径。
主要特点是以起始点为中心向外层层扩展，直到扩展到终点为止。Dijkstra算法是很有代表性的最短路径算法，
在很多专业课程中都作为基本内容有详细的介绍，如数据结构，图论，运筹学等等。注意该算法要求图中不存在负权边。

问题描述：在无向图 G=(V,E) 中，假设每条边 E[i] 的长度为 w[i]，找到由顶点 V0 到其余各点的最短路径。（单源最短路径）

算法思想：设G=(V,E)是一个带权有向图，把图中顶点集合V分成两组，第一组为已求出最短路径的顶点集合
（用S表示，初始时S中只有一个源点，以后每求得一条最短路径 , 就将加入到集合S中，直到全部顶点都加入到S中，算法就结束了），
第二组为其余未确定最短路径的顶点集合（用U表示），按最短路径长度的递增次序依次把第二组的顶点加入S中。在加入的过程中，
总保持从源点v到S中各顶点的最短路径长度不大于从源点v到U中任何顶点的最短路径长度。
此外，每个顶点对应一个距离，S中的顶点的距离就是从v到此顶点的最短路径长度，U中的顶点的距离，
是从v到此顶点只包括S中的顶点为中间顶点的当前最短路径长度。

算法步骤：

a.初始时，S只包含源点，即S＝{v}，v的距离为0。U包含除v外的其他顶点，即:U={其余顶点}，
	若v与U中顶点u有边，则<u,v>正常有权值，若u不是v的出边邻接点，则<u,v>权值为∞。

b.从U中选取一个距离v最小的顶点k，把k，加入S中（该选定的距离就是v到k的最短路径长度）。

c.以k为新考虑的中间点，修改U中各顶点的距离；若从源点v到顶点u的距离（经过顶点k）比原来距离（不经过顶点k）短，
	则修改顶点u的距离值，修改后的距离值的顶点k的距离加上边上的权。

d.重复步骤b和c直到所有顶点都包含在S中。

*/
void Dijkstra()
{
	int min,p,s[N]={0},i,j;
	for(j=1;j<=n;j++)			// n 经过初始化后的值为输入的 n+1
	{
		min=Max;
		for(i=1;i<=n;i++)
			if(a[0][i]<min && !s[i])
			{
				min=a[0][i];
				p=i;			//以p为中转站比较计算距离a[0][p]+a[p][i]与a[0][i]的大小关系
			}
		s[p]=1;		
		for(i=1;i<=n;i++)
			if(a[0][p]+a[p][i]<a[0][i])//会通过 p 计算相邻的元素的路程，而且是最短路程
				a[0][i]=a[0][p]+a[p][i];
	}
	
}


int main()
{
	while(scanf("%d%d%d",&T,&s,&d)!=EOF)
	{
		Init();
		Dijkstra();
		printf("%d\n",a[0][n]);
	}
	
	return 0;
}