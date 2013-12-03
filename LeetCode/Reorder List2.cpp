#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:

	ListNode* reverseList(ListNode *head) {
		ListNode* tail = NULL, *p;
		while (head != NULL) {
			p = head;
			head = head->next;
			cout << p->val << endl;
			p->next = tail;
			tail = p;
		}
		return tail;
	}

	void reorderList(ListNode *head) {
		ListNode *p1 = head, *p2 = NULL;

		if (head != NULL)
			p2 = head->next;

		ListNode *fast = p2, *slow = p1;

		while (fast != NULL) {
			slow->next = fast->next;
			slow = slow->next;

			if (slow != NULL) {
				fast->next = slow->next;
				fast = fast->next;
			} else {
				fast = NULL;
			}
		}

		fast = p2;
		while (fast) {
			cout << fast->val << endl;
			fast = fast->next;
		}

		fast = p1;
		while (fast) {
			cout << fast->val << endl;
			fast = fast->next;
		}

		p2 = reverseList(p2);

		fast = p2;
		while (fast) {
			cout << fast->val << endl;
			fast = fast->next;
		}

		int flag = 1;
		slow = p1;
		fast = p2;
		head = NULL;
		p1 = NULL;
		while (slow || fast) {
			if (flag) {
				p2 = slow;
				slow = slow->next;
			} else {
				p2 = fast;
				fast = fast->next;
			}
			if (head == NULL) {
				head = p1 = p2;
				head->next = NULL;
			} else {
				p1->next = p2;
				p1 = p2;
				p2->next = NULL;
			}
			flag = 1 - flag;
		}
	}
};

int main() {
	ListNode *head = new ListNode(1), *p = head, *q;
	p->next = q = new ListNode(2);
	p = q;
	p->next = q = new ListNode(3);
	p = q;
	p->next = q = new ListNode(4);
	p = q;
	p->next = q = new ListNode(5);
	p = q;

	Solution a;
	a.reorderList(head);

	while (head) {
		cout << head->val << endl;
		head = head->next;
	}

	return 0;
}
