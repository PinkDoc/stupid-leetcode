// lc 513
class Solution {
public:
  vector<int> temp;

  void do_it(TreeNode *root) {
    queue<TreeNode *> nodes;
    nodes.push(root);
    temp.push_back(root->val);
    while (!nodes.empty()) {
      temp.clear();
      auto size = nodes.size();
      for (auto i = 0; i < size; ++i) {
        auto n = nodes.front();
        nodes.pop();
        if (n->left) {
          nodes.push(n->left);
          temp.push_back(n->left->val);
        }
        if (n->right) {
          nodes.push(n->right);
          temp.push_back(n->right->val);
        }
      }
    }
  }

  int findBottomLeftValue(TreeNode *root) {
    if (!root)
      return 0;
    do_it(root);
    return temp[0];
  }
};