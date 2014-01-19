#include <cstdio>
#include <cstring>
#include <algorithm>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode* slow = head, *fast = head;
		while (fast != NULL) {
			fast = fast->next;
			if (fast == NULL)
				break;
			fast = fast->next;
			slow = slow->next;

			if (slow == fast)
				break;
		}

		if (fast != NULL && fast == slow) {
			slow = head;
			while (fast != slow) {
				slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
		return NULL;
	}
};

int main() {
	return 0;
}
