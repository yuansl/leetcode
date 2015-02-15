#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > twoSum(vector<int> &num, int target)
{
	int front, rear, sum, n;
	vector<vector<int> > ret;
	
	sort(num.begin(), num.end());
	n = num.size();
	front = 0;
	rear = n - 1;
	while (front < rear) {
		sum = num[front] + num[rear];
		if (sum == target) {
			vector<int> vec { num[front], num[rear] };
			ret.push_back(vec);
			while (front + 1 < rear && num[front + 1] == num[front])
				front++;
			while (rear - 1 > front && num[rear - 1] == num[rear])
				rear--;
			front++;
		} else if (sum < target) {
			front++;
		} else {
			rear--;
		}
	}
	return ret;
}
