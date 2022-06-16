// lc 378
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        map<int, int> s;
        size_t count = 0;

        for (auto& i : matrix)
        for (auto j : i)
        {
            auto cand = j;

            if (count == k)
            {
                auto temp = *s.rbegin();
                if (cand < temp.first) 
                {
                    auto tn = temp.first;
                    s[temp.first]--;
                    if (s[tn] == 0) s.erase(tn);
                    s[cand]++;
                }
            }
            else
            {
                s[cand]++;
                count++;
            }

        }

        return (*s.rbegin()).first;
    }
};

// 2

class Solution {
public:

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto cmp = [](int m, int n)
        {
            return m > n;
        };
       
        priority_queue<int,vector<int>, decltype(cmp)> pq(cmp);
        for (auto& i : matrix)
        {
            for (auto j : i)
            {
                pq.push(j);
            }
        }
        int temp = 0;
        while (--k)
        {
            pq.pop();
        }

        temp = pq.top();
        return temp;
    }
};
