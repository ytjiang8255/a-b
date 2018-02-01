include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/*
***************************************************

输入数据包含多个测试实例，每个测试实例占一行，
每行的开始是一个整数n(3<=n<=100)，它表示多边形的边数（当然也是顶点数），
然后是按照逆时针顺序给出的n个顶点的坐标（x1, y1, x2, y2... xn, yn）,
为了简化问题，这里的所有坐标都用整数表示。
输入数据中所有的整数都在32位整数范围内，n=0表示数据的结束，不做处理。

对于每个测试实例，请输出对应的多边形面积，结果精确到小数点后一位小数。

边形公式：0.5*|x1*y2-y1*x2+x2*y3-y2*x3+……+xn*y1-yn*x1|
绝对值函数：int型：abs（int x），float型 fabs（float x）
多边形求面积公式：S = 0.5 * ( (x0*y1-x1*y0) + (x1*y2-x2*y1) + ... + (xn*y0-x0*yn)
假设只有两个点的话，那么最后相乘为a[2][0]*a[0][1]-a[0][0]*a[2][1]
这一项多出来了，因为根本不存在a[2][0],a[2][1],但是只要a[2][0]=a[0][0],a[2][1]=a[0][1],那么上式的差为0，不影响结果！
***************************************************
*/
int main()
{
	int n;
	float x[3], y[3], square;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)	break;
		if (n >= 3 && n <= 100)
		{
			square = 0;
			scanf("%f%f", &x[0], &y[0]);
			x[2] = x[0];
			y[2] = y[0];

			while (--n)
			{
				scanf("%f%f", &x[1], &y[1]);
				square += x[0] * y[1] - x[1] * y[0];
				x[0] = x[1];
				y[0] = y[1];
				
			}
			square += x[0] * y[2] - x[2] * y[0];
			printf("%.1lf\n", square / 2);

		}
	}
	return 0;
}