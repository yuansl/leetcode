// Roman to Integer
#include <string>
#include <iostream>
using namespace std;

int romanToInt(string s)
{
	int ret;
	size_t i, n;
	
	n = s.size();
	if (n == 0)
		return 0;
	ret = 0;
	i = n - 1;
	if (i >= 0 && s[i] == 'I')
		while (i >= 0 && s[i] == 'I') {
			ret += 1;
			i--;
		}
	if (i >= 0 && s[i] == 'V') {
		ret += 5;
		i--;
		if (i >= 0 && s[i] == 'I') {
			ret -= 1;
			i--;
		}
	}
	if (i >= 0 && s[i] == 'X') {
		ret += 10;
		i--;
		if (i >= 0 && s[i] == 'I') {
			ret -= 1;
			i--;
		}
	}
	while (i >= 0 && s[i] == 'X') {
		ret += 10;
		i--;
	}
	if (i >= 0 && s[i] == 'L') {
		ret += 50;
		i--;
		if (i >= 0 && s[i] == 'X') {
			ret -= 10;
			i--;
		}
	}
	if (i >= 0 && s[i] == 'C') {
		ret += 100;
		i--;
		if (i >= 0 && s[i] == 'X') {
			ret -= 10;
			i--;
		}
	}
	while (i >= 0 && s[i] == 'C') {
		ret += 100;
		i--;
	}
	if (i >= 0 && s[i] == 'D') {
		ret += 500;
		i--;
		if (i >= 0 && s[i] == 'C') {
			ret -= 100;
			i--;
		}
	}
	if (i >= 0 && s[i] == 'M') {
		ret += 1000;
		i--;
		if (i >= 0 && s[i] == 'C') {
			ret -= 100;
			i--;
		}
	}
	while (i >= 0 && s[i] == 'M') {
		ret += 1000;
		i--;
	}
	return ret;
}
