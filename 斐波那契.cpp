/*
��Ŀ����
��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n���0��ʼ����0��Ϊ0����
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