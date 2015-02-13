// Container with most water
#include <vector>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int maxArea(vector<int> &height)
{
	const size_t n = height.size();
	size_t i, j, x1, x2;
	int ret;

	ret = 0;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (min(height[i], height[j]) * (int) (j - i) > ret) {
				ret = min(height[i], height[j]) * (j - i);
				x1 = i;
				x2 = j;
			}
	cout << "(x1, x2) = " << x1 << ' ' << x2 << '\n';
	return ret;
}

int main()
{
	vector<int> height;

	srand(time(NULL));
	for (int i = 0; i < 1000; i++) {
		height.push_back(rand() % 10000);
		cout << height[i] << ' ';
	}
	cout << '\n';
	cout << maxArea(height);
	return 0;
}
