#include <stdio.h>
#include <cmath>

int main() {
	printf("A:\n");
	printf("integer min = %d, max = %d\n", ~((unsigned int)(-1) >> 1), (unsigned int)(-1) >> 1);
	
	printf("B:\n");
	/*
	C语言里面，默认%f是小数点后6位，如果想小数点后面16位，写成%.16lf
	不会自动四舍五入的，double是一个近似值，通常没有办法做的很精确.
	通常能精确到小数点后面5，6位，也就是说超过5,6位了可能就不准了。
	
	不知用什么合适的方式探索double能精确到多少位小数。
	*/
	double pi = acos(-1.0);
	double dd = 1.0 / 3 + 0.0000001; 
	double bb = 1.0 / 3 + 0.0000009;
	printf("%lf\n%lf\n", pi, dd+bb);
	printf("%lf\n%.8lf\n", pi, dd+bb);

	/*
	printf("C:\n");
	double i=0.0000000000000001;  
    	for(;i>0;i+=0.0000000000000001);
    	printf("%.100lf\n%.100lf\n",i,i-1);  
	
	from baidu.com
	只能迭代一个个试吗？感觉不靠谱。
	但位操作只能用于整型。
	*/

	printf("D:\n");
	printf("%d\n", false&&true||true);//(false&&true)||true = 1, false&&(true||true) = 0
	// output : 1 是(false && true) || true 还是从左到右的顺序呢？
	printf("%d\n", true || true && false);
	// output : 1 是(false && true) || true.
	
	printf("E:\n");
	int a, b, n = 1, x = 0, y = 0;
	while(n != 0) {
		scanf("%d", &n);
		scanf("%d%d", &a, &b);
		if(a) if(b) x++; else y++;
		printf("x = %d, y = %d\n", x, y);
	}
	// 1 1 : x = 1, y = 0
	// 1 0 : x = 1, y = 1
	// 0 1 : x = 1, y = 1
	/*
	所以else与if(b)配套。最近原则
	*/

}
