#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

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
			p->next = tail;
			tail = p;
		}
		return tail;
	}

	void printListNode(ListNode *head) {
		ListNode *p = head;
		cout << "List:  ";
		while (p != NULL) {
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}

	void reorderList(ListNode *head) {
		ListNode *slow = head, *fast = NULL, *tail = NULL;
		if (head != NULL)
			fast = head->next;

		while (fast != NULL) {
			fast = fast->next;
			if (fast != NULL)
				fast = fast->next;
			else
				break;
			slow = slow->next;
		}

		if (slow != NULL) {
			fast = slow->next;
			slow->next = NULL;
			slow = head;
			fast = reverseList(fast);

//			printListNode(fast);
//			printListNode(slow);

			head = NULL;
			int flag = 1;
			while (slow || fast) {
				ListNode* temp = NULL;
				if (flag) {
					temp = slow;
					slow = slow->next;
				} else {
					temp = fast;
					fast = fast->next;
				}

				flag = 1 - flag;
				if (head == NULL) {
					head = tail = temp;
					temp->next = NULL;
				} else {
					tail->next = temp;
					tail = temp;
					temp->next = NULL;
				}
			}
//			printListNode(head);

		} else {
			fast = NULL;
		}

	}
};

int main() {
	ListNode *head = new ListNode(1), *p = head, *q;
	p->next = q = new ListNode(2);
	p = q;
//	p->next = q = new ListNode(3);
//	p = q;
//	p->next = q = new ListNode(4);
//	p = q;
//	p->next = q = new ListNode(5);
//	p = q;

	Solution a;
	a.reorderList(head);

	return 0;
}
