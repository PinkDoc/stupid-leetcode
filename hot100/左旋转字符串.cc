class Solution {
	public:
		string reverseLeftWords(string s, int n) {
			string ret;
			for (auto i = n; i < s.size(); ++i) ret.push_back(s[i]);
			
			for (auto i = 0; i < n; ++i) ret.push_back(s[i]);

			return ret;
		}	
};
