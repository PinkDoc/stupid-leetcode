#include <iostream>
#include <vector>

using namespace std;

// 1 求最大公约数的方法
/*
	 欧几里德算法又称辗转相除法，用于计算两个整数a,b的最大公约数。其计算原理依赖于下面的定理：
	定理：gcd(a,b) = gcd(b,a mod b)
	证明：a可以表示成a = kb + r，则r = a mod b
	假设d是a,b的一个公约数，则有
	d|a, d|b，而r = a - kb，因此d|r
	因此d是(b,a mod b)的公约数
	假设d 是(b,a mod b)的公约数，则
	d | b , d |r ，但是a = kb +r
	因此d也是(a,b)的公约数
	因此(a,b)和(b,a mod b)的公约数是一样的，其最大公约数也必然相等，得证
	
	https://zhuanlan.zhihu.com/p/338809271

*/
int gcd_1(int a, int b)
{
	if (b == 0)
		return a;
	return gcd_1(b, a%b);
}

// 2 求最小公倍数
/*

	最小公倍数 = 两数的乘 / 最大公约数
	
	r = gcd a, b
	a = a1 * r
	b = b1 * r
	a * b = b * a
	a1 * r *b = b1 * r * a
	a1 * b = b1 * a
	a1 *b or b1 * a 是我们想要的结果
	a1 * b = a1 * r * b1 
	b1 * a = b1 * r * a1
	
*/

int lcm(int a, int b)
{
	return a * b / gcd_1(a, b);
}


int main()
{

}
