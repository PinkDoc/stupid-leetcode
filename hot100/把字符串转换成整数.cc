class Solution {
public:

	bool isSymbol(char ch) {
		return ch == '+' || ch == '-';
	}

	bool isDigit(char a) {
		return a <= '9' && a >= '0';
	}

	bool isBlankSpace(char ch) {
		return ch == ' ';
	}
	
	int strToInt(string str) {
		long ret = 0;
		long sign = 1;
		int index = 0;
		
		while (index < str.size() && isBlankSpace(str[index++])) {}

		bool ok = true;
		while ((ok && isSymbol(str[index])) || isDigit(str[index])) {
			if (isSymbol(str[index]) && ok) {
				sign = str[index] == '+' ? 1 : -1;
			} 

			ok = false;

			if (isDigit(str[index])) {
				long temp = str[index] - '0';
				ret = ret * 10 + temp;
				if (ret >= INT_MAX && sign) return INT_MAX;
				if (-ret <= INT_MIN && sign < 0) return INT_MIN;
			
			}	
		}

		return ret * sign;	
	}
};
