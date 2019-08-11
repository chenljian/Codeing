#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		int flg = 0;
		int i = 0;
		int j = 0;
		vector<int> vec;
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return vec;

		while (true) {
			vec.push_back(matrix[i][j]);
			switch (flg) {
			case 0:
				//→
				if (i + j + 1 == matrix[0].size()) {
					if (matrix.size() - i != matrix[0].size() - j) {
						flg = 1;
						i = i + 1;
						continue;
					}
					return vec;
				}
				j = j + 1;
				break;
			case 1:
				//向下
				if (matrix.size() - i == matrix[0].size() - j) {
					if (i + j + 1 != matrix.size()) {
						flg = 2;
						j = j - 1;
						continue;
					}
					return vec;
				}
				i = i + 1;
				break;
			case 2:
				//向左
				if (i + j + 1 == matrix.size()) {
					if (i != j + 1) {
						flg = 3;
						i = i - 1;
						continue;
					}
					return vec;
				}
				j = j - 1;
				break;
			case 3:
				//向上
				if (i == j + 1) {
					if (i + j + 1 != matrix[0].size()) {
						flg = 0;
						j = j + 1;
						continue;
					}
					return vec;
				}
				i = i - 1;
			default:
				return vec;
			}

		}
	}
};

int main()
{
	Solution sol;
	vector<vector<int>> vec = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}} ;
	vector<int> result = sol.printMatrix(vec);
	return 0;
}