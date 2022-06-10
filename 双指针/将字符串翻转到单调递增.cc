// lc 926
//

class Solution {
public:
    int minFlipsMonoIncr(string &s) {
        // dp i 0 = dp i - 1 0 + !is_zero
        // dp i 1 = dp i - 1 1 + is_zero
        vector<vector<int>> a(s.size() , vector<int>(2, 0));
        a[0][0] = s[0] == '0' ? 0 : 1;
        a[0][1] = s[0] == '0' ? 1 : 0;
        for (int i = 1; i < s.size(); ++i) 
        {
            int temp = s[i] == '0' ? 1 : 0;
            int temp2 = s[i] == '0' ? 0 : 1;
            a[i][0] = a[i - 1][0] + temp2;
            a[i][1] = min(a[i-1][1], a[i-1][0]) + temp  ;
        }

        return min(a[s.size() - 1][0], a[s.size() - 1][1]);
    }
};
