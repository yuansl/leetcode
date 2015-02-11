#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
	int i, j, n;
	vector<int> ret;
	
	n = numbers.size();
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (numbers[i] + numbers[j] == target) {
				ret.push_back(i);
				ret.push_back(j);
				goto succ_exit;
			}
succ_exit:
	return ret;
}
