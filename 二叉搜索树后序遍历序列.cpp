/*
题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

恶心的地方：
空序列竟然不是，非得单独列出来
*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;
        if(sequence.size() <= 3)
            return true;
        stack<int> min;
        stack<int> midle;
        stack<int> max;
        min.push(INT_MIN);
        midle.push(sequence.back());
        max.push(INT_MAX);
        for(int idx = sequence.size()-2; idx >=0;idx--){
            if(sequence[idx] > sequence[idx+1]){
                //右子树
                if(sequence[idx] > max.top())
                    return false;
                min.push(midle.top());
                midle.push(sequence[idx]);
                max.push(max.top());
            }
            else{
                //左子树
                while(min.top() > sequence[idx]){
                    min.pop();
                    midle.pop();
                    max.pop();
                }
                min.push(min.top());
                max.push(midle.top());
                midle.push(sequence[idx]);
            }
        }
        return true;
    }
};