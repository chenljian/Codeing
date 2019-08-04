/*
题目：
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/
#include <stack>
#include <iostream>
using namespace std;
class Solution
{
public:
	void push(int node) {
		//直接push到stack1
		stack1.push(node);
	}

	int pop() {
		//如果stack2没有元素，则找stack1要
		int topValue = 0;
		if (stack2.size() > 0) {
			topValue = stack2.top();
			stack2.pop();
			return topValue;
		}
		else if (stack1.size() > 0) {
			while( stack1.size() > 1) {
				stack2.push(stack1.top());
				stack1.pop();
			}
			topValue = stack1.top();
			stack1.pop();
			return topValue;
		}
		else {
			return 0;
		}
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
//4ms
//476k

//int main() {
//	Solution sol;
//	sol.push(1);
//	sol.push(2);
//	sol.push(3);
//	cout << sol.pop();
//	cout << sol.pop();
//	sol.push(4);
//	cout << sol.pop();
//	sol.push(5);
//	cout << sol.pop();
//	cout << sol.pop();
//}