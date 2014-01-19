
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
        ListNode *removeNthFromEnd(ListNode *head, int n)
        {
            ListNode *tail = head, *pre = NULL;

            while (n > 0 && tail != NULL)
            {
                tail = tail->next;
                --n;
            }

            if (n == 0 && tail == NULL)
            {
                return head->next;
            }

            ListNode *p = head;

            while (tail != NULL && tail->next != NULL)
            {
                p = p->next;
                tail = tail->next;
            }

            if (p != NULL && p->next != NULL)
            {
                p->next = p->next->next;
            }

            return head;
        }
};
