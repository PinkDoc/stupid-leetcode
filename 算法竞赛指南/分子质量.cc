#include <vector>
#include <iostream>

using namespace std;

// 原题是不包括括号，我这里包括括号

constexpr int C = 100;
constexpr int H = 200;
constexpr int O = 300;

void fuck(char ch, int& c, int& h, int& o)
{
	switch (ch)
	{
	case 'C':
		c++;
		break;
	case 'H':
		h++;
		break;
	case 'O':
		o++;
		break;
	}
}


// 没有括号的
std::size_t NonSol(std::string& s)
{
	
	enum 
	{
		CharState = 0,
		NumberState
	};
	
	auto state = CharState;
	
	auto c = 0, h = 0, o = 0;
	
	
	s.push_back('#');

	char ch = 0;
	auto number = 0;
	
	for (auto i = 0; i < s.size(); ++i)
	{
		char temp = s[i];
		switch (state)
		{
		case CharState:
			switch (temp)
			{
			case '1'...'9':
				state = NumberState;
				number += number * 10 + temp - '0';
				break;
			default:
				if (ch != 0);
					fuck(ch , c, h, o);
				ch = temp;	
				number = 0;
			}	
			break;
		case NumberState:
			switch(temp)
			{
			case '1'...'9':
				number += (number * 10 + temp - '0');
				break;
			default:
				switch (ch)
				{
				case 'C':
					c += number;
					break;
				case 'H':
					h += number;
					break;
				case 'O':
					o += number;
					break;
				}	
				ch = temp;
				number = 0;
				state = CharState;
			}
			break;
		}
	}
	cout << 'C' << c << 'H' << h << 'O' << o << endl;
	
	return h * H + c * C + o * O;
	
}

// Example (CH2O)2H2
std::size_t Solution(std::string& s)
{
	std::string temp;
	
	enum 
	{
		inCharState = 0,
		inNumberState,
		CharState,
		NumberState
	}
	
	auto c = 0, h = 0, o = 0;
	auto number = 0, inNumber = 0;
	state = CharState;
	
	for (auto i = s.size() - 1; i >= 0; --i)
	{
		switch (state)
		{
		//case 
		}
	}
	
	
	
	return NonSol(temp);
}

int main()
{
	std::string s = "CH2O2HHOOOOO";	// 100 + 400 + 600 + 400 + 300
	cout << NonSol(s) << endl;

} 
