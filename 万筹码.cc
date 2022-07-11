class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int cost = 0;
        for (auto i : position)
        {
            if (i % 2 == 0)
            {
                cost++;
            }
             
        }

        if (cost == position.size()) return 0;
        else {
            return min(cost, (int)position.size() - cost);
        }

        return -1;
        
    }
};
