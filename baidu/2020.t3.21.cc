/*
	度度熊请你找出两个数，满足且尽量大。输出最大的.
	其中表示和的最小公倍数，表示和的最大公约数。
*/
// https://www.nowcoder.com/question/next?pid=30544864&qid=1701577&tid=56409504

// 公倍数大， 公约数小， 则是 n 和 n-1
#include <iostream>

int main()
{
    long long n;
    std::cin >> n;
    std::cout << (n - 1) * n - 1;
}
