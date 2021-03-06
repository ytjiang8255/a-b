#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
高能质点碰击核子时，质点被吸收，放出3个高能质点和1个低能质点；
低能质点碰击核子时，质点被吸收，放出2个高能质点和1个低能质点。
假定开始的时候（0微秒）只有一个高能质点射入核反应堆，
每一微秒引起一个事件发生(对于一个事件，当前存在的所有质点都会撞击核子)，
试确定n微秒时高能质点和低能质点的数目。

输入含有一些整数n(0≤n≤33)，以微秒为单位，若n为-1表示处理结束
分别输出n微秒时刻高能质点和低能质点的数量，高能质点与低能质点数量之间以逗号空格分隔
5 2
-1
------
571, 209
11, 4
a[i][0] = 3*a[i-1][0]+2*a[i-1][1];
a[i][1] = a[i-1][0]+a[i-1][1];
**/
int main()
{
	int n,i,j;
	long long sum[35][2];
	while(scanf("%d",&n)==1 && n!=-1)
	{
		sum[0][0]=1;
		sum[0][1]=0;
		sum[1][0]=3;
		sum[1][1]=1;
		for(i=2;i<=n;i++)
		{
			sum[i][0]=3*sum[i-1][0]+2*sum[i-1][1];
			sum[i][1]=sum[i-1][0]+sum[i-1][1];
		}
		printf("%lld,%lld\n",sum[n][0],sum[n][1]);//注意输出要求--高能质点与低能质点数量之间以逗号空格分隔
	}
	return 0;
}

