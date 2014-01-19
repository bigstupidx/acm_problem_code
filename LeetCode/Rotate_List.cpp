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
        ListNode *rotateRight(ListNode *head, int k)
        {
            ListNode *tail = head, *p = head;

            int cnt = 0;

            while (tail != NULL)
            {
                tail = tail->next;
                ++cnt;
            }

            if (cnt <= 1)return head;

            k %= cnt;

            tail = head;

            while (k > 0 && tail != NULL)
            {
                tail = tail->next;
                --k;
            }

            while (tail != NULL && tail->next != NULL)
            {
                tail = tail->next;
                p = p->next;
            }

            if (tail != NULL)
            {
                tail->next = head;
                head = p->next;
                p->next = NULL;
            }

            return head;
        }
};
