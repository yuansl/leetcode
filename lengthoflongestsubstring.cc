#include <string>
#include <set>
using namespace std;

int lengthofLongestSubstring(string s)
{
	set<char> cset;
	set<char>::iterator it;
	size_t i, j, maxlen;
	const size_t n = s.size();

	maxlen = 0;
	for (i = 0; i < n; i++) {
		j = i;
		cset.clear();
		while (j < n && (it = cset.find(s[j])) == cset.end()) {
			cset.insert(s[j]);
			j++;
		}
		if (cset.size() > maxlen)
			maxlen = cset.size();
	}
	return maxlen;
}
