/*
	小丑题
        描述
        编写一个函数来验证输入的字符串是否是有效的 IPv4 或 IPv6 地址

        IPv4 地址由十进制数和点来表示，每个地址包含4个十进制数，其范围为 0 -
   255， 用(".")分割。比如，172.16.254.1； 同时，IPv4 地址内的数不会以 0
   开头。比如，地址 172.16.254.01 是不合法的。

        IPv6 地址由8组16进制的数字来表示，每组表示 16 比特。这些组数字通过
   (":")分割。比如,  2001:0db8:85a3:0000:0000:8a2e:0370:7334
   是一个有效的地址。而且，我们可以加入一些以 0
   开头的数字，字母可以使用大写，也可以是小写。所以，
   2001:db8:85a3:0:0:8A2E:0370:7334 也是一个有效的 IPv6 address地址 (即，忽略 0
   开头，忽略大小写)。

        然而，我们不能因为某个组的值为 0，而使用一个空的组，以至于出现 (::)
   的情况。 比如， 2001:0db8:85a3::8A2E:0370:7334 是无效的 IPv6 地址。 同时，在
   IPv6 地址中，多余的 0 也是不被允许的。比如，
   02001:0db8:85a3:0000:0000:8a2e:0370:7334 是无效的。

        说明: 你可以认为给定的字符串里没有空格或者其他特殊字符。

        数据范围：字符串长度满足 5 \le n \le 505≤n≤50
        进阶：空间复杂度 O(n)O(n)，时间复杂度 O(n)O(n)
*/

#include "bits.hpp"

class Solution {
public:
  bool check4(const string &ip, int begin, int end) {
    if (end - begin > 3 || end - begin <= 0)
      return false;

    int temp = 0;
    bool firstZero = false;
    int i = begin;
    for (; i < end; ++i) {
      // a10
      if (ip[i] < '0' || ip[i] > '9')
        return false;

      temp = temp * 10 + ip[i] - '0';

      // 010
      if (firstZero)
        return false;

      if (temp == 0)
        firstZero = true;
    }

    if ((temp <= 255 && temp >= 0 && !firstZero) || (temp == 0 && firstZero))
      return true;
    else
      return false;
  }

  string checkIP4(string &ip) {
    int dot = 0;
    int p = 0;
    while (p < ip.size()) {
      if (dot > 3)
        return "Neither";
      int end = p;

      for (; end < ip.size(); ++end) {
        if (ip[end] == '.')
          break;
      }

      if (end != ip.size())
        dot++;

      if (!check4(ip, p, end))
        return "Neither";

      p = end + 1;

      if (p == ip.size() && ip[end] == '.')
        return "Neither";
    }

    if (dot != 3)
      return "Neither";

    return "IPv4";
  }

  bool check6(string &ip, int begin, int end) {
    if (end - begin > 4 || end - begin <= 0)
      return false;

    int i = begin;
    int temp = 0;
    bool firstZero = false;

    for (; i < end; ++i) {
      switch (ip[i]) {
      case 'a' ... 'f':
      case 'A' ... 'F':
      case '0' ... '9':
        temp += ip[i] - '0';
        break;
      default:
        return false;
      }
    }

    return true;
  }

  string checkIP6(string &ip) {
    int dot = 0;
    int p = 0;
    while (p < ip.size()) {
      if (dot > 8)
        return "Neither";
      int end = p;

      for (; end < ip.size(); ++end) {
        if (ip[end] == ':')
          break;
      }

      dot++;

      if (!check6(ip, p, end))
        return "Neither";

      p = end + 1;
      if (p == ip.size() && ip[end] == ':')
        return "Neither";
    }

    if (dot != 8)
      return "Neither";

    return "IPv6";
  }

  string solve(string IP) {
    // write code here
    // if (IP == "20EE:FGb8:85a3:0:0:8A2E:0370:7334" || IP ==
    // "2001:0db8:85a3:0000:0000:8a2g:0370:7334") return "Neither";
    if (IP.find('.') != IP.npos) {
      return checkIP4(IP);
    } else {
      return checkIP6(IP);
    }
  }
};

void test4(string s) {
  cout << "TEST ipv4 : " << Solution().checkIP4(s) << endl;
}

void test6(string s) {
  cout << "TEST ipv6 : " << Solution().checkIP6(s) << endl;
}
void test(string s)
{
	cout << "TEST : " << Solution().solve(s) << endl;
}

int main() {
	test("192.6.6.");
	test("192.102.123:123");
	test("192.169.12.1");
	test("a01a:1234:1234:1234:2134:123:123:123");
	test("2001:db8:85a3:0:0:8A2E:0370:7334");
	test("2001:db8:85a3:0:0:8A2E:0370:7334");
	test("02001:0db8:85a3:0000:0000:8a2e:0370:7334");
}
