/**
* Definition for a binary tree node.
*/
#include "h.h"
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		pair<int, int> big_small;
		return isValidBST(root, big_small);
	}

	bool isValidBST(TreeNode* root, pair<int, int>& big_small){
		if (root == NULL)  return true;
		big_small.first = root->val;
		big_small.second = root->val;
		bool lvld = true, rvld = true;
		if (root->left != NULL){
			if (root->left->val<root->val){
				big_small.second = root->left->val;
				pair<int, int> left_big_small;
				lvld = isValidBST(root->left, left_big_small);
				if (lvld){
					lvld = left_big_small.first<root->val;
					if (lvld)
					{
						big_small.first = max(big_small.first, left_big_small.first);
						big_small.second = min(big_small.second, left_big_small.second);
					}
					else    return false;

				}

				else return false;
				//还要检查左子树中所含的元素都小于跟，找到左子树中最大的元素即可
			}
			else    return false;
		}
		if (root->right != NULL){
			if (root->right->val>root->val)  {
				big_small.first = root->right->val;
				pair<int, int> right_big_small;

				rvld = isValidBST(root->right, right_big_small);
				if (rvld){
					rvld = right_big_small.second>root->val;
					if (rvld){
						big_small.first = max(big_small.first, right_big_small.first);
						big_small.second = min(big_small.second, right_big_small.second);
					}
					else    return false;
				}
				else   return false;

			}
			else    return false;
		}
		return lvld&&rvld;
	}
};