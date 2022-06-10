#include "bits.hpp"

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        string ret;
        
        int s_p = s.size() - 1, t_p = t.size() - 1;
        int offset = 0;
        
        while (s_p >= 0 || t_p >= 0)
        {
            int temp1 = s_p < 0 ? 0 : s[s_p] - '0';
            int temp2 = t_p < 0 ? 0 : t[t_p] - '0'; 
            int temp = temp1 + temp2 + offset;
            offset = temp / 10;
            ret.push_back((temp % 10 + '0'));
            s_p = s_p- 1;
            t_p = t_p - 1;
        }
        
        return string(ret.rbegin(), ret.rend());
        
    }
};

int main()
{

	Solution s;
	auto ret = s.solve("", "2");
	cout << ret << endl;

}
