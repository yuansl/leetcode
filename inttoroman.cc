// Integer to Roman
#include <vector>
#include <cstdlib>
using namespace std;

string intToRoman(int num)
{
	string ret;
	vector<string> dict(1001, "");
	
	if (num < 1 || num >= 4000)
		return ret;
	dict[1] = "I";
	dict[2] = "II";
	dict[3] = "III";
	dict[4] = "IV";
	dict[5] = "V";
	dict[6] = "VI";
	dict[7] = "VII";
	dict[8] = "VIII";
	dict[9] = "IX";
	dict[10] = "X";
	dict[50] = "L";
	dict[100] = "C";
	dict[500] = "D";
	dict[1000] = "M";

	int thousand, hundred, tens, sing, i;

	thousand = num / 1000;
	for (i = 0; i < thousand; i++)
		ret += dict[1000];
	hundred = num % 1000 / 100;
	if (hundred >= 1 && hundred < 4)
		for (i = 0; i < hundred; i++)
			ret += dict[100];
	else if (hundred == 4)
		ret += dict[100] + dict[500];
	else if (hundred >= 5 && hundred < 9) {
		ret += dict[500];
		hundred -= 5;
		for (i = 0; i < hundred; i++)
			ret += dict[100];
	} else if (hundred == 9)
		ret += dict[100] + dict[1000];

	tens = num % 100 / 10;
	if (tens >= 1 && tens < 4)
		for (i = 0; i < tens; i++)
			ret += dict[10];
	else if (tens == 4)
		ret += dict[10] + dict[50];
	else if (tens >= 5 && tens < 9) {
		ret += dict[50];
		tens -= 5;
		for (i = 0; i < tens; i++)
			ret += dict[10];
	} else if (tens == 9)
		ret += dict[10] + dict[100];
	sing = num % 10;
	ret += dict[sing];
	return ret;
}
