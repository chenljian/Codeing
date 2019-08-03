#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool Find(int target, vector<vector<int> > array) {
	if (array.size() == 0)
		return false;
	if (array[0].size() == 0)
		return false;
	int minIndex = 0;
	int maxIndex = array.size() - 1;
	for (int i = 0; i < array.size(); i = i + 1) {
		//for row binnary insearch
		int curMin = minIndex;
		int curMax = maxIndex;
		while (curMin <= curMax) {
			int middle = (curMin + curMax) / 2;
			int number = array[i][middle];
			if (number == target)
				return true;
			if (number > target)
				curMax = middle - 1;
			else
				curMin = middle + 1;
		}//while
		maxIndex = curMax;
	}
	return false;
}
int main() {
	vector<vector<int>> array = { {1, 2, 8, 9},{2, 4, 9, 12},{4, 7, 10, 13},{6, 8, 11, 15}};
	Find(7, array);
	return 0;
}