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
				while (lo < hi && num[lo] == tuple[1])
					lo++;
				while (lo < hi && num[hi] == tuple[2])
					hi--;
			}
		}
		while (i + 1 < n && num[i + 1] == num[i])
			i++;
	}
	return ret;
}

int main()
{
	vector<int> vec{0};// -4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
	vector<vector<int> > ret;
	size_t i, j, n;

	cout << sizeof(size_t) << endl;
	ret = threeSum(vec);
	n = ret.size();
	for (i = 0; i < n; i++, cout << endl)
		for (j = 0; j < ret[i].size(); j++)
			cout << ret[i][j] << ' ';
	return 0;
}
