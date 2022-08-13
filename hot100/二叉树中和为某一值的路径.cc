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
    vector<int> temp;
	vector<vector<int>> ret;
    int t;
    void fuck(TreeNode* node, int sum) {
        if (node == nullptr) return;
        int ss = sum + node->val;
        if (ss == t) {
            if (node->left == nullptr && node->right == nullptr) {
                temp.push_back(node->val);
                ret.emplace_back(temp);
                temp.pop_back();
            }
        } 

        temp.push_back(node->val);
        fuck(node->left, ss);
        fuck(node->right, ss);
        temp.pop_back();
        

    }   

    vector<vector<int>> pathSum(TreeNode* root, int target) {
		t = target;
		fuck(root, 0);
		return ret;
    }
};