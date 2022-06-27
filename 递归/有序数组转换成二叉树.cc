// lc 108
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return fucker(nums, 0, nums.size() - 1);
    }

    TreeNode* fucker(vector<int>& nums, int left, int right)
    {
        if (left > right) return nullptr;
        int mid = (left + right) / 2;
        auto r = new TreeNode(nums[mid]);
        r->left = fucker(nums, left, mid - 1);
        r->right = fucker(nums, mid + 1, right);
        return r;
    }
};
