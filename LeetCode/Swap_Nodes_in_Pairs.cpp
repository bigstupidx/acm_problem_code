/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution
{
    public:
        ListNode *swapPairs(ListNode *head)
        {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            ListNode *tail = head, *pre = NULL;
            int cnt = 0;

            while (tail != NULL)
            {
                ListNode *p = tail, *q = NULL;

                if (tail->next == NULL)break;

                q = tail->next;
                tail = q->next;
                q->next = p;
                p->next = tail;

                //cout << q->val << "  " << p->val << endl;

                cnt += 2;

                if (pre != NULL)pre->next = q;

                if (cnt == 2)head = q;

                pre = p;
            }

            return head;
        }
};
