#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
假设有x1个字母A， x2个字母B,..... x26个字母Z，同时假设字母A的价值为1，字母B的价值为2,..... 字母Z的价值为26。
那么，对于给定的字母，可以找到多少价值<=50的单词呢？单词的价值就是组成一个单词的所有字母的价值之和，
比如，单词ACM的价值是1+3+14=18，单词HDU的价值是8+4+21=33。(组成的单词与排列顺序无关，比如ACM与CMA认为是同一个单词)


输入首先是一个整数N，代表测试实例的个数。
然后包括N行数据，每行包括26个<=20的整数x1,x2,.....x26.
输出能找到的总价值<=50的单词数,每个实例的输出占一行
2
1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
9 2 6 2 10 2 2 5 6 1 0 2 7 0 2 2 7 5 10 6 10 2 10 6 1 9
---------------------------------------------------------
7
379297

**/
int main()
{
	int N,i,j,k,sum;
	int num[27],c1[51],c2[51];	//c1 存放系数	c2 为中间变量
	while(scanf("%d",&N)==1)
	while(N--)
	{
		for(i=1;i<27;i++)
			scanf("%d",&num[i]);
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		
		c1[0]=1;
		for(i=1;i<=26;i++)		//一共有多少个多项式，即几个多项式相乘 
		{
			for(j=0;j<=50;j++)	//最大只能到50，上面说了指数代表单词的价值
				for(k=0;k<=num[i]&&j+k*i<=50;k++)	//k*i表示被乘多项式的指数，j+k*i表示指数相加，系数取决于c1[j]
					c2[j+k*i]+=c1[j];
				
			for(j=0;j<=50;j++)		//复制c2到c1，并初始化c2
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
		}	
		sum=0;
		for(i=1;i<=50;i++)
			sum+=c1[i];
		printf("%d\n",sum);
		
	}
	return 0;
}