#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable: 4996)	//添加的定义排除警告

/**

该游戏可以由两个或两个以上的玩家进行。 它由一个棋盘（棋盘）和一些棋子（棋子）组成，
所有棋子都用正整数或“开始”或“结束”标记。 玩家从起点开始，最终必须跳到终点。
 在跳跃的过程中，玩家将会在路途中访问棋手，但是每个人都必须从一个棋子跳到另一个棋手，
 这个棋子绝对更大（你可以假定起点是最小值，终点是最大值）。 所有玩家都不能倒退。
 一个跳棋可以从棋子到下一个，也可以穿过很多棋手，甚至可以直接从起点到达终点。 
 当然，在这种情况下你会得到零点。 当且仅当他可以根据他的跳跃解决方案获得更大的分数时，
 玩家才是获胜者。 请注意，您的分数来自跳棋的棋子的价值之和。

根据给定的棋子列表输出最大值。输入包含多个测试用例。 每个测试用例如下所示：
N value_1 value_2 ... value_N
保证N不超过1000，所有的value_i都在32-int范围内。
以0开头的测试用例终止输入，而不测试该测试用例。

根据规则打印最大值，一行一例。

**/
int main()
{
	int N;
	long num[1000];
	while (scanf("%d", &N) != EOF && N != 0)
	{
		long sum = 0;
		for (int i = 0; i < N; i++)
		{
			scanf("%ld", &num[i]);
//			printf("%ld\t", num[i]);
		}

		sum = num[0];			//这语句如果放进循环则会输出错误
		for (int i = 1; i <= N; i++)
		{
			
		//	sum = 0;
			if (num[i-1] < num[i])
				sum += num[i];	//累加相关元素的值
			else
				i = N+1;		//强制退出累加循环
		}
		printf("%ld\n", sum);
	}
	return 0;
}