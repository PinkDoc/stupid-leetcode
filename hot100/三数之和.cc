class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;

        sort(nums.begin(), nums.end());

        for (auto i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] > 0) {
                return ret;
            }

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            auto left = i + 1;
            auto right = nums.size() - 1;

            while (left < right)
            {
                auto val = nums[i] + nums[left] + nums[right];
                if (val > 0)
                {
                    right--;
                }
                else if (val < 0)
                {
                    left++;
                }
                else 
                {
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    ret.emplace_back(std::move(temp));

                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    right--;
                    left++;
                }
            }
        }


        return ret;
    }
};
