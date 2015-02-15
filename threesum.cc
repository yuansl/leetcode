// 3 sum
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int> > threeSum(vector<int> &num)
{
	vector<vector<int> > ret;
	vector<int> tuple(3, 0);
	int n, i, lo, hi, sum, target;

	sort(num.begin(), num.end());
	n = num.size();
	for (i = 0; i < n - 2; i++) {
		target = -num[i];
		lo = i + 1;
		hi = n - 1;
		while (lo < hi) {
			sum = num[lo] + num[hi];
			if (sum < target) {
				lo++;
			} else if (sum > target) {
				hi--;
			} else {
				tuple[0] = num[i];
				tuple[1] = num[lo];
				tuple[2] = num[hi];
				ret.push_back(tuple);
				while (lo + 1 < hi && num[lo + 1] == num[lo])
					lo++;
				while (hi - 1 > lo && num[hi - 1] == num[hi])
					hi--;
			}
		}
		while (i + 1 < n && num[i + 1] == num[i])
			i++;
	}
	return ret;
}
