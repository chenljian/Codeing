/*

题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        if(!root){
            return result;
        }
        result.push_back(root->val);
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        
        while(!treeQueue.empty()){
            queue<TreeNode*> temp;
            while(!treeQueue.empty()){
               
                TreeNode* leftCh = treeQueue.front()->left;
                TreeNode* rightCh = treeQueue.front()->right;
                if(leftCh){
                    temp.push(leftCh);
                    result.push_back(leftCh->val);
                }
                if(rightCh){
                    temp.push(rightCh);
                    result.push_back(rightCh->val);
                }
                treeQueue.pop();
            }
            treeQueue = temp;
        }//while
        return result;
    }
};