/*
��Ŀ��
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� 
����һ���Ǽ�����������һ����ת�������ת�������СԪ�ء� 
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� 
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
*/
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() < 1)
			return 0;
		int pre = 0;
		for (int i = 0; i < rotateArray.size(); i++) {
			if (rotateArray[i] < pre) {
				return rotateArray[i];
			}
			pre = rotateArray[i];
		}
		return rotateArray[0];
	}
};