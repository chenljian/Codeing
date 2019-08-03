/*
��Ŀ��
����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
���������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�
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