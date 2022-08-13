class Solution {
public:
    unordered_set<TreeNode*> set_;

    TreeNode* ret;

    bool FindNode(TreeNode* root, TreeNode* node)
    {
        if (root == nullptr) return false;
        if (root == node) { set_.emplace(root); return true; }

        auto on_left = FindNode(root->left, node);
        auto on_right = FindNode(root->right, node);

        if (on_right || on_left) set_.emplace(root);

        return on_left || on_right;
    }

    bool dfs(TreeNode* root, TreeNode* q)
    {
        if (root == nullptr) return false;
        if (root == q) { if (!ret && set_.count(root)) ret = root ;return true; }

        auto on_left = dfs(root->left, q);
        auto on_right = dfs(root->right, q);

        if (on_left || on_right) {
            if (!ret && set_.count(root) > 0) ret = root;
        } 
        
        return on_left || on_right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ret = nullptr;
        FindNode(root, p);
        dfs(root, q);
        
        return ret;
    }
};