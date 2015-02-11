#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;
class solution {
public:
	int findMedianSortedArrays(int A[], int m, int B[], int n) {
		int size = m + n;
		int tmp[size];
		int mid = (double) size / 2 + 0.5;
		cout << "mid =" << mid << endl;
		int i, j, k;

		i = j = k = 0;
		while (i < m && j < n && k < mid)
			if (A[i] < B[j])
				tmp[k++] = A[i++];
			else
				tmp[k++] = B[j++];
		while (i < m && k < mid)
			tmp[k++] = A[i++];
		while (j < n && k < mid)
			tmp[k++] = A[j++];
		return tmp[k - 1];
	}
};
