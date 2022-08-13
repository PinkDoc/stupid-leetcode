class Solution {
public:

	Node* pre;
	Node* head;
	
	void fuck(Node* n)
	{
		if (n == nullptr) return;
		if (n->left) fuck(n->left);

		if (pre == nullptr) {
			head = n;
		} else {
			n->left = pre;
			pre->right = n;
		}

		pre = n;

		fuck(n->right);

	}
	
	Node* treeToDoublyList(Node* root) {
		fuck(root);
		if (root == nullptr) return nullptr;
		head->left = pre;
		pre->right = head;
		return head;
	}
};
