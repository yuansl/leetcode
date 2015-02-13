// Lonset Common prefix
#include <vector>
#include <utility>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
	string ret;
	size_t minlen, i, j;
	
	if (strs.size() == 0)
		return ret;

	minlen = strs[0].size();
	for (i = 1, j = 0; i < strs.size(); i++)
		if (minlen > strs[i].size()) {
			minlen = strs[i].size();
			j = i;
		}
	swap(strs[0], strs[j]);
	for (i = 0; i < strs[0].size(); i++) {
		for (j = 1; j < strs.size(); j++) 
			if (strs[0][i] != strs[j][i])
				return ret;
		ret += strs[0][i];		
	}
	return ret;
}
