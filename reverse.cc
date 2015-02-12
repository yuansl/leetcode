// reverse integer
int reverse(int x)
{
	int sign = x < 0 ? -1 : 1;
	int ret = 0;
	if (sign == -1)
		x *= -1;
	while (x > 0) {
		ret = 10 * ret + (x % 10);
		x /= 10;
	}
	return sign * ret;
}
