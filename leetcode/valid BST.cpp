#include "h.h"
using namespace std;
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return IsValidBST(root, INT_MIN, INT_MAX);
	}
	bool IsValidBST(TreeNode* root, int MIN, int MAX) //root������СΪMIN�����ΪMAX
	{
		if (root == NULL) return true;
		if (root->val>MIN
			&&root->val<MAX
			&&IsValidBST(root->left, MIN, root->val)
			&& IsValidBST(root->right, root->val, MAX))   return true;
		else   return false;
	}
};