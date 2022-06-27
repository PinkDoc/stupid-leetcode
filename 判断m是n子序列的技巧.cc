#include <iostream>
#include <cassert>

using namespace std;

bool is_son(string& m,string& n)
    {
        auto p = 0;
        for (auto i = 0;i < n.size() ; ++i)
        {
            if (m[p] ==  n[i]) p++;
            if (p == m.size()) return true;
        }

        return false;
    }

void test()
{
	string s1 = "abc";
	string s2 = "asdhfhsfbjashdfohewsgopshgc";
	assert(is_son(s1, s2));
}


int main() {
	test();
}
