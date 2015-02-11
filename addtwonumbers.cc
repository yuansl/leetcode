#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
	int val1, val2;
	ListNode *cur, *t, head(0);
	stack<int> s;
	
	cur = l1;
	val1 = 0;
	while (cur) {
		val1 = 10 * val1 + cur->val;
		cur = cur->next;
	}
	cur = l2;
	while (cur) {
		s.push(cur->val);
		cur = cur->next;
	}

	val2 = 0;
	while (!s.empty()) {
		val2 = 10 * val2 + s.top();
		s.pop();
	}
	val1 = val1 + val2;

	while (val1 > 0) {
		s.push(val1 % 10);
		val1 /= 10;
	}

	t = &head;
	while (!s.empty()) {
		t->next = new ListNode(s.top());
		t = t->next;
		s.pop();		
	}
	t = head.next;
	return t;
}
