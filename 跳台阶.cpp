/*
��Ŀ����
һֻ����һ�ο�������1��̨�ף�Ҳ��������2����
�����������һ��n����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������
*/
class Solution {
public:
	int jumpFloor(int number) {
		if (number <= 2) {
			return number;
		}
		return jumpFloor(number - 1) + jumpFloor(number - 2);
	}
};
//561ms
//608k