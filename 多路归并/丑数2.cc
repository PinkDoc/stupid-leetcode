class Solution {
public:
    long nthUglyNumber(int n) {
        auto cmp = [](int n, int m)
        {
            return n > m;
        };
        priority_queue<long, vector<long>, decltype(cmp)> pq(cmp);
        set<long> s;
        s.insert(1);
        pq.push(1);
        vector<long> v = {2,3,5};
        int ret;
        while (n--)
        {
            ret = (int)pq.top();
            pq.pop();
            for (int i : v)
            {
                long temp = ret * i;
                if (s.find(temp) == s.end())
                {
                    s.insert(temp);
                    pq.push(temp);
                }
            }
        }
        return (int)ret;
    }
};
