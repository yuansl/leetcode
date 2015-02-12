// String to Integer
#include <climits>
#include <string>
using namespace std;

int atoi_r(string str)
{
	int ret, i, sign;
	
	ret = 0;
	i = 0;
	sign = 1;
	while (str[i] && isspace(str[i]))
		i++;

	if (str[i] && !isdigit(str[i])) {
		if (str[i] == '+') {
			sign = 1;
			i++;
		} else if (str[i] == '-') {
			sign = -1;
			i++;
		} else
			return 0;
	}
	while (str[i] && isdigit(str[i])) {
		ret = 10 * ret + str[i] - '0';
		i++;
	}
	if (ret + INT_MAX == -1 && sign != -1)
		ret = INT_MAX;
	return ret * sign;
}
