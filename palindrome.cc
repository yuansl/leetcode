// Palindrome Number
#include <stack>

using namespace std;
bool isPalindrome(int x)
{
	stack<int> s1, s2;
	int n, count;
	
	n = 0;
	if (x < 0)
		return false;

	while (x > 0) {
		s1.push(x % 10);
		x /= 10;
		n++;
	}
	count = 0;
	while (count < n / 2) {
		s2.push(s1.top());
		s1.pop();
		count++;
	}
		
	if (n % 2 != 0)
		s1.pop();
	while (!s1.empty() && !s2.empty()) {
		if (s1.top() != s2.top())
			return false;
		s1.pop();
		s2.pop();
	}
	return true;
}
