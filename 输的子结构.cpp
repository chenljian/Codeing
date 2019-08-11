/*
题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。
（ps：我们约定空树不是任意一个树的子结构）
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool CampareTree(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot2 == NULL){
            return true;
        }
        else if(pRoot1 && pRoot2){
            if(pRoot1->val == pRoot2->val){
                if(CampareTree(pRoot1->left, pRoot2->left)&&
                  CampareTree(pRoot1->right, pRoot2->right))
                    return true;
            }
            return false;
        }
        return false;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2 == NULL || pRoot1 == NULL)
            return false;
        if(CampareTree(pRoot1, pRoot2)){
            return true;
        }
        else if(HasSubtree(pRoot1->left, pRoot2)){
            return true;
        }
        else if(HasSubtree(pRoot1->right, pRoot2)){
            return true;
        }
        return false;
    }
};