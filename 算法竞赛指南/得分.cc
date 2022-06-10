#include <vector>
#include <iostream>

using namespace std;


// 给一个O和X组成的字符串，X得0分，O的得分是每个连续出现的O个个数
auto Solution(const string& s)
{
	auto res = 0;
	auto temp = 0;
	for (auto i : s)
	{
		switch (i)
		{
		case 'O':
			++temp;
			res += temp;
			break;
		case 'X':
			temp = 0;
			break;
		}
	}
	
	return res;
}

int main()
{
	cout << Solution("OXXXXOOOOO");
}
