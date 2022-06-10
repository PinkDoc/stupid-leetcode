/*

		薯队长写了一篇笔记草稿，请你帮忙输出最后内容。
		 1.输入字符包括，"("    ,    ")"    和    "<"和其他字符。 
		 2.其他字符表示笔记内容。
		 3.()之间表示注释内容，任何字符都无效。    括号保证成对出现。
		 4."<"表示退格,    删去前面一个笔记内容字符。括号不受"<"影响    。 
???有问题

*/

#include <cassert>
#include <iostream>

using namespace std;

enum {
	normal = 0,
	ignore,
	back
};

std::string Solution(const std::string& inPut)
{
	std::string ret;
	auto state = normal;
	auto p = 0;
	for (auto i = 0; i < inPut.size(); ++i)
	{
		char ch = inPut[i];
		switch (state)
		{
		case normal:
		
			switch(ch)
			{
			case '(':
				state = ignore;
				break;
			case '<':
				if (!ret.empty())
					ret.pop_back();
				state = back;
				break;
			default:
				ret.push_back(ch);
			}
		
			break;
			
		case ignore:
			if (ch == ')')
				state = normal;
			break;
			
		case back:
			switch (ch)
			{
			case '<':
				if (!ret.empty()) ret.pop_back();
				break;
			case '(':
				state = ignore;
				break;
			default:
				state = normal;
				ret.push_back(ch);
			}
			break;
		default:
			assert(true);
		}
	}
	
	return ret;
}

void test(std::string s, std::string expect)
{

	cout <<  "TESTING : "; 
	auto ans = Solution(s);
	if (ans != expect)
	{
		cout << " [expect : " << expect << "] [ans: " << ans << " ]";
	}
	else
	{
		cout << " passing "; 
	}
	
	cout << endl;
}

int main() 
{
	test("Corona(Trump)USA<<<Virus", "CoronaVirus");
	
}
