/*
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<int> seq;
        if(root)
            construct(root, seq, expectNumber);
        //排序
        
        for(int count = 0; count < vec.size(); count++){
            //找到最长的放在后面
            vector<vector<int>>::iterator temp = vec.begin();
            vector<vector<int>>::iterator it = vec.begin();
            for(int i = 0; i < vec.size() - count; i++){
                if((it+i)->size() > temp->size()){
                    temp = it+i;
                }
            }
            vector<int> tempVec = *temp;
            vec.erase(temp);
            vec.push_back(tempVec);
        }
        return vec;
    }
private:
    vector<vector<int>> vec;
    void construct(TreeNode* pNode, vector<int> seq, int number){
        number = number - pNode->val;
        seq.push_back(pNode->val);
        if(number > 0){
            if(pNode->left){
                construct(pNode->left, seq, number);
            }
            if(pNode->right){
                construct(pNode->right, seq, number);
            }
        }
        else if(number == 0 && !pNode->left && !pNode->right){
            vec.push_back(seq);
        }
    }
};