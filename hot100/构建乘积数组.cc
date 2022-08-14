class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		vector<int> front;
		vector<int> back(a.size(), 0);

		for (auto i : a)
		{
			if (front.empty()) {
				front.push_back(i);
			} else {
				front.push_back(front.back() * i);
			}
		}


		for (int i = a.size() - 1; i >= 0; --i) 
		{
				if (i == a.size() - 1) {
					back[i] = a[i];	
				} else {
					back[i] = back[i + 1] * a[i];
				}
		}

		vector<int> ret;

		if (a.size() == 1) {
			ret.push_back(0);
			return ret;
		}

		for (auto i = 0; i < a.size(); ++i) {
			int left = i == 0 ? 1 : front[i - 1];
			int right = i == a.size() - 1 ? 1 : back[i + 1];

			ret.push_back(left * right);
		}
		return ret;
	}
	
};
