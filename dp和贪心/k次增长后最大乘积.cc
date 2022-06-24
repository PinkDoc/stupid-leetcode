// lc 2233
inline constexpr int mod = 1e9 + 7;

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        bool done = false;

        while (k && !done)
        {
            done = true;
            for (auto i = 1; i < nums.size(); ++i)
            {
                if (nums[i] > nums[i-1])
                {
                    nums[i-1]++;
                    k--;
                    done = false;
                    break;
                }
            }
        }

        size_t index = 0;
        size_t size = nums.size();

        while (k)
        {
            nums[index % size]++;
            index++;
            k--;
        }

        std::size_t ret =1;

        for (auto i : nums)
        {
            ret = (ret * i) % mod;
        }

        return (int)ret;
    }
};
inline constexpr int mod = 1e9 + 7;

class Solution {
public:
  int maximumProduct(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());

    bool done = false;

    while (k && !done) {
      done = true;
      for (auto i = 1; i < nums.size(); ++i) {
        if (nums[i] > nums[i - 1]) {
          nums[i - 1]++;
          k--;
          done = false;
          break;
        }
      }
    }

    size_t index = 0;
    size_t size = nums.size();

    while (k) {
      nums[index % size]++;
      index++;
      k--;
    }

    std::size_t ret = 1;

    for (auto i : nums) {
      ret = (ret * i) % mod;
    }

    return (int)ret;
  }
};