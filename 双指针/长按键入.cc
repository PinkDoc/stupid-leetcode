// lc 925

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int p1 = 0, p2 = 0;
        char ch1, ch2;
        while (p1 < name.size() && p2 < typed.size())
        {
            if (name[p1] == typed[p2])
            {
                ch1 = name[p1];
                ch2 = typed[p2];
                p1++;
                p2++;
            }
            else
            {
                if (typed[p2++] != ch2) return false;
            }
        }

        while (p2 < typed.size())
        {
            if (typed[p2] != ch1) return false;
            p2++;
        }

        if (p1 != name.size() || ch1 != ch2)
        {
            return false;
        }
        
        return true;
    }
};
