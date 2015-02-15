// Remove Nth Node From End of List
#include <iostream>
#include <cstdlib>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(NULL) {}
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
	ListNode *ret, *cur;
	static int count = 0;

	ret = NULL;
	if (head->next != NULL)
		ret = removeNthFromEnd(head->next, n);
	head->next = ret;
	if (++count == n) {
		delete head;
		return ret;
	}
	return head;
}
