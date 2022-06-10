#include <iostream>
#include <vector>

using namespace std;


// 圆桌旁边坐着N个人，每个人都有一定数量的金币，金币总能被n整除，每个人可以给
// 他左右的相邻的人一些金币，最后使得每个人的金币相等

int Solution(vector<int>& inPut)
{
	// 1,2,5,4
	auto sum = 0;
	for (auto i : inPut) sum += i;
	
	auto basic = sum / inPut.size();
	
	
}

int main() {
	
}
