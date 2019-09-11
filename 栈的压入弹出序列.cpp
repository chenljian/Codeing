/*
题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
*/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> simuStack;
		vector<int>::iterator it;
        if(popV.empty()){
            return true;
        }
		it = popV.begin();
		while (it != popV.end()) {
			//在未压入栈和栈顶寻找
            
			vector<int>::iterator tempIt;
			tempIt = find(pushV.begin(), pushV.end(), *it);
			if (tempIt != pushV.end()) {
				//找到了，把之前的元素压入栈
				while ( *(pushV.begin()) != *it) {
					simuStack.push(pushV[0]);
					pushV.erase(pushV.begin());
				}
				pushV.erase(pushV.begin());
			}
			else {
				//没找到
				if (simuStack.empty() || simuStack.top() != *it) {
					return false;
				}
				else {
					simuStack.pop();
				}
			}
			it++;
		}
		return true;
    }
};