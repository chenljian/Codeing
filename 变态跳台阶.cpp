/*
��Ŀ����
һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
�����������һ��n����̨���ܹ��ж�����������
*/
class Solution {
public:
	int jumpFloorII(int number) {
		if (number <= 2) {
			return number;
		}
		int total = 0;
		for (int i = 1; i < number; i++) {
			total += jumpFloorII(number - i);
		}
		return total + 1;
	}
};
//5ms
//364k