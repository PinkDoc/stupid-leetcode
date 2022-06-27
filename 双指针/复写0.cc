// lc 1089
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> temp;
        
        for (auto i : arr)
        {
            if (temp.size() == arr.size()) goto end;

            if (i == 0)
            {
                temp.push_back(0);
                if (temp.size() == arr.size()) goto end;
                temp.push_back(0);
            }
            else
            {
                temp.push_back(i);
            }
        }
end:
        arr = std::move(temp);

    }
};
