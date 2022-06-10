#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 村子里面有n个龙，你有m个骑士，能力为x的骑士可以杀死能力不超过x的头，需要支付x个金币，如何支付金币最少?

int Solution(vector<int>& d, vector<int>& m)
{
	sort(d.begin(), d.end());
	sort(m.begin(), m.end());
	
	auto killed = 0;
	auto cost = 0;
	auto m_p = 0;
	for (auto i = 0; i < d.size(); ++i)
	{
		while (m_p < m.size() && m[m_p] < d[i]) m_p++;
		if (m_p >= m.size()) break;
		cost += m[m_p++];
		killed++;
	}
	
	return killed == d.size() ? (int)cost : -1;
}

void test(vector<int>& d, vector<int>& m)
{
	cout << "TESTING : " << Solution(d, m) << endl;
}

int main() {
	vector<int> d = {5,4};
	vector<int> m = {7,8,4};
	test(d, m);
	d = {5,5};
	m = {10};
	test(d, m);
}
