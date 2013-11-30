#include <cstdio>
#include <cstring>
#include <vector>

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
	void reorderList(ListNode *head) {
		vector<ListNode*> arr;
		while (head != NULL) {
			arr.push_back(head);
			head = head->next;
		}
		int flag = 1;
		ListNode* result = NULL, *temp;
		head = NULL;
		for (int i = 0, n = arr.size(); i < n; i++, flag = 1 - flag) {
			if (flag == 1) {
				temp = arr[i / 2];
			} else {
				temp = arr[n - 1 - i / 2];
			}
			//printf("%d\n", temp->val);
			if (head == NULL) {
				head = result = temp;
				temp->next = NULL;
			} else {
				result->next = temp;
				result = temp;
				temp->next = NULL;
			}
		}
	}
};

int main() {
	ListNode *head = new ListNode(1), *q;
	head->next = q = new ListNode(2);
	q->next = new ListNode(3);
	Solution a;
	a.reorderList(head);
	return 0;
}
