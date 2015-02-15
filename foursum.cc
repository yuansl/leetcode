// 4Sum
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int> > foursum(vector<int> &num, int target)
{
	vector<vector<int> > ret;

	int i, j, front, rear, sum, n;

	sort(num.begin(), num.end());
	n = num.size();
	for (i = 0; i < n - 3; i++) {
		for (j = i + 1; j < n - 2; j++) {
			front = j + 1;
			rear = n - 1;
			while (front < rear) {
				sum = num[i] + num[j] + num[front] + num[rear];
				if (sum == target) {
					vector<int> vec {num[i], num[j], num[front], num[rear]};
					ret.push_back(vec);
					while (front + 1 < rear &&
					       num[front + 1] == num[front])
						front++;
					while (rear - 1 > front &&
					       num[rear - 1] == num[rear])
						rear--;
					front++;
				} else if (sum < target) {
					front++;
				} else {
					rear--;
				}
			}
			while (j + 1 < n && num[j + 1] == num[j])
				j++;
		}
		while (i + 1 < n && num[i + 1] == num[i])
			i++;
	}
	return ret;
}
