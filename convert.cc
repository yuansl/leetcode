// ZigZag Conversion

string convert(string s, int nrows)
{
	string ret;
	string::iterator it;
	int i, j;
	char tmp[nrows][40];

	memset(tmp, '\0', sizeof(tmp));
	it = s.begin();
	for (i = 0; i < 40; i++) {
		if (i % 2 != 0) {
			j = nrows / 2;
			if (it != s.end())
				tmp[j][i] = *it++;
			else
				break;
			continue;
		}
		for (j = 0; j < nrows; j++) {
			if (it != s.end())
				tmp[j][i] = *it++;
			else
				break;
		}
	}	
	for (i = 0; i < nrows; i++)
		for (j = 0; j < 40; j++)
			if (tmp[i][j])
				ret += tmp[i][j];
	return ret;
}
