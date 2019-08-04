/*
��Ŀ��
������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
*/
#include <stack>
#include <iostream>
using namespace std;
class Solution
{
public:
	void push(int node) {
		//ֱ��push��stack1
		stack1.push(node);
	}

	int pop() {
		//���stack2û��Ԫ�أ�����stack1Ҫ
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