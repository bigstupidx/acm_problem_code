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
        ListNode *reverseBetween(ListNode *head, int m, int n)
        {
            ListNode *result = NULL, *result_tail = NULL, *p = head;
            ListNode *tail = NULL, *tail_temp = NULL;

            while(p)
            {
                ListNode *temp = p;
                p = p->next;
                temp->next = NULL;

                if(m > 1)
                {
                    if(result == NULL)result  = temp;
                    else result_tail->next = temp;

                    result_tail = temp;
                }
                else if(n >= 1)
                {
                    temp->next = tail;
                    tail = temp;

                    if(tail_temp == NULL)tail_temp = temp;

                    if(result_tail != NULL)result_tail->next = tail;
                    else result = tail;
                }
                else
                {
                    tail_temp->next = temp;
                    tail_temp = temp;
                }

                --m;
                --n;
            }

            return result;
        }
};
