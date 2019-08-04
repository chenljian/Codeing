/*
题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39
*/
class Solution {
public:
	int Fibonacci(int n) {
		if (n <= 1)
			return n;
		int pre1 = 0;
		int pre2 = 1;
		int result = 0;
		for (int i = 2; i <= n; i++) {
			result = pre1 + pre2;
			pre1 = pre2;
			pre2 = result;
		}
		return result;
	}
};

//3ms
//480k