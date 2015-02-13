// 3Sum Closest
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int threeSumClosest(vector<int> &num, int target)
{
	int ret, i, lo, hi, n, sum;

	sort(num.begin(), num.end());
	n = num.size();
	ret = INT_MAX - 1;
	for (i = 0; i < n - 2; i++) {
		lo = i + 1;
		hi = n - 1;
		while (lo < hi) {
			sum = num[i] + num[lo] + num[hi];
			if (sum == target)
				return target;
			ret = abs(sum - target) < abs(ret-target) ? sum : ret;	
			if (sum > target)
				hi--;
			else
				lo++;
		}
		while (i + 1 < n && num[i + 1] == num[i])
			i++;
	}
	return ret;
}
