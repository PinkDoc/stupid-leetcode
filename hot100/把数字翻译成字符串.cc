class Solution {
public:
	int ret;

	void sol(std::string& s, int l)
	{
		if (l == s.size()) return;
		ret++;
		sol(s, l + 1);
		int temp = 0;
		
		for (auto i = l; i < 2; ++i)
		{
			temp += (i - '0');
		}

		if (temp < 26) {
			ret++;
			sol(s, l + 2);
		}
	}

	int translateNum(int num) {
		ret = 0;
		auto s = to_string(num);
		sol(s, 0);

		return ret;
	}
};
