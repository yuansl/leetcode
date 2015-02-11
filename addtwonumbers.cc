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

int main()
{
	ListNode head(0), *l1, *l2;

	l1 = &head;
	l1->next = new ListNode(2);
	l1 = l1->next;
	l1->next = new ListNode(4);
	l1 = l1->next;
	l1->next = new ListNode(3);
	l1 = l1->next;
	l1 = head.next;
	head.next = NULL;
	l2 = &head;
	l2->next = new ListNode(5);
	l2 = l2->next;
	l2->next = new ListNode(6);
	l2 = l2->next;
	l2->next = new ListNode(4);
	l2 = l2->next;
	l2 = head.next;
	head.next = NULL;
	l1 = addTwoNumbers(l1, l2);
	while (l1) {
		cout << ' ' << l1->val;
		l1 = l1->next;
	}
	cout << '\n';
	return 0;
}
