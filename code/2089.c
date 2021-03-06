#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/**
不吉利的数字为所有含有4或62的号码。例如：
62315 73418 88914
都属于不吉利号码。但是，61152虽然含有6和2，但不是62连号，所以不属于不吉利数字之列。

输入的都是整数对n、m（0<n≤m<1000000），如果遇到都是0的整数对，则输入结束。
输出一个不含有不吉利数字的统计个数，该数值占一行位置。

1 100
0 0
----------
80

  注意：需要先将所有的结果先算出来，然后输入一个区间，就能直接得出一个结果，不用重复判断，节省时间，否则会超时！
		先判断在1到1000001之间的数看看谁符合要求，如果符合要求，则给以其为下标的数组c赋值为一，否则保存为0；
		然后再通过for循环将所有的以i（就是a,b之间的数）为下标的数加起来，用a,b之间的总数减去它输出，就行了！
**/
#define N 1000001  
int c[N];  
int main()  
{  
    int i,j;  
    int a,b,sum;  
    for(i=1;i<=N;i++)  
    {  
        c[i]=0;  
        j=i;  
        while(j)  
        {  
            if(j%10==4||j%100==62)  	//对包含4和62的数标记为 1
            {  
              c[i]=1;  
              break;  				//跳出最内层while循环，跳回到外部的for(i=1;i<=N;i++)循环中  
            }  
            j=j/10;  				//用以十进制数中一位位判断比较
        }  
    }  
	
	
    while(scanf("%d%d",&a,&b)&&(a||b))  
    {  
        for(i=a,sum=0;i<=b;i++)  			//sum初始化可以放进for语句的第一个初始化中
        {  
            sum+=c[i];  
        }  
        printf("%d\n",(b-a+1)-sum);  		//b-a+1 表示两个数字之间的差值
    }  
      
    return 0;  
 }   