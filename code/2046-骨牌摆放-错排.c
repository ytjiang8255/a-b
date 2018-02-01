#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

输入数据由多行组成，每行包含一个整数n,
表示该测试实例的长方形方格的规格是2×n (0<n<=50)。
请输出铺放方案的总数，每个实例的输出占一行。
f(n)=f(n-1)+f(n-2)+f(n-3);

首先来对递归公式进行解释：
n个不同的元素的一个错排公式可以分作两步完成：
第一步：假设我们错排第一个元素，那么它可以从2~n的位置任意选择其中的一个，一共是有n-1种选择。
第二步：错排其余n-1个元素，也是需要分情况和种类的。因为这需要看第一步的结果，如果第一个元素落在第k个位置上，
	第二步就需要把k号元素进行错排，k号元素错排位置的不同将导致不同的情况会发生：
	1.假设k号元素正好落在了第一个元素的位置，那么就可以将第一个元素和第k个元素完全剔除出去，
	因为相当于只是他们两者互换了位置，其他元素暂时还没有发生变动。留下来的n-2元素进行错排的话，
	那么我们就可以得到了D(n-2)种 的错排方式。

	2.若k号元素不排到第一个元素的位置，我们可以暂时将现在排在k号位置的第一个元素剔除出去，
	生下来的就只包含k号元素和原来n-2个的元素了。这时，我们可以将原来的第一个元素的位置看做是现在k号元素的原本位置，
	因为k号元素不能够放在原来的位置上，所以就相当于是原来的n-2个元素和k共计n-1个元素进行完全的错排。那么一共就有D(n-1)种方法。
	
	据加法原理，完成第二步共有 f(n - 2)+f(n - 1) 种方法。 根据乘法原理， n 个不同元素的错排种数 
		f(n) = (n-1)[f(n-2)+f(n-1)] (n>2)  
***************************************************
*/
int main()
{
	int n;
	long long int a[52];
	while(scanf("%lld",&n) != EOF)
	{
		a[1]=1;
		a[2]=2;
		a[3]=4;
		for(int i=4;i<=50;i++)
			a[i] =a[i-1] +a[i-2];
		
		printf("%lld",a[n]);
		
	}
	
	return 0;
}