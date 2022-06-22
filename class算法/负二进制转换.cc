// lc 1017
class Solution {
public:
  string baseNeg2(int n) {
    if (n == 0)
      return "0";

    string ret;

    // I am sb

    while (n) {
      int temp = n & 1;
      ret.push_back(temp + '0');
      n = (n - temp) / -2;
    }

    reverse(ret.begin(), ret.end());

    return ret;
  }
};