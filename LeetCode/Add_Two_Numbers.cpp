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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		int carry = 0;
		ListNode *head = NULL, *tail = NULL;
		while (l1 || l2 || carry != 0) {
			int data = carry;
			if (l1 != NULL) {
				data += l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL) {
				data += l2->val;
				l2 = l2->next;
			}
			ListNode *p = new ListNode(data % 10);
			carry = data / 10;
			if (head == NULL) {
				head = tail = p;
			} else {
				tail->next = p;
				tail = p;
			}
		}
		return head;
	}
};
