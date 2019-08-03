/*
题目：
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() < 1) {
			return NULL;
		}
		TreeNode* pNode = new TreeNode(pre[0]);
		vector<int> preLeft, preRight;
		vector<int> vinLeft, vinRight;
		int frount = 1;
		for (int i = 0; i < vin.size(); i++) {
			if (vin[i] == pNode->val) {
				frount = 0;
				continue;
			}
			if (frount) {
				vinLeft.push_back(vin[i]);
			}
			else {
				vinRight.push_back(vin[i]);
			}
		}//for
		for (int i = 1; i < pre.size(); i++) {
			if (i <= vinLeft.size()) {
				preLeft.push_back(pre[i]);
			}
			else {
				preRight.push_back(pre[i]);
			}
		}
		//
		pNode->left = reConstructBinaryTree(preLeft, vinLeft);
		pNode->right = reConstructBinaryTree(preRight, vinRight);
		return pNode;
	}
};
//
//5ms
//492k