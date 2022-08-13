/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<int> pre;
    vector<int> in;
    map<int, int> map;

    int nn;
    TreeNode* solution(int pre_left, int pre_right,  int in_left, int in_right)
    {
        //std::cout << pre_left << " " << pre_right << " " << in_left << " " << in_right << std::endl;
        if (pre_left > pre_right) {
            return nullptr;
        }

        auto root = new TreeNode(pre[pre_left]);

        auto left_size = map[pre[pre_left]] - in_left;

        root->left = solution(pre_left + 1, pre_left + left_size, in_left, map[pre[pre_left]] - 1);
        root->right = solution(pre_left + left_size + 1, pre_right, map[pre[pre_left]] + 1, in_right );

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (auto i = 0; i < preorder.size(); ++i)
        {
            map.emplace(inorder[i], i);
        }

        auto n = preorder.size();
        pre = std::move(preorder);
        in = std::move(inorder);
        nn = n ;
        return solution(0, n - 1, 0, n - 1);
    }
};
