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
        ListNode *partition(ListNode *head, int x)
        {
            ListNode *head_ll = NULL, *head_rr = NULL;
            ListNode *ll = NULL, *rr = NULL;
            ListNode *p = head;

            while(p != NULL)
            {
                if(p->val < x)
                {
                    if(head_ll == NULL)head_ll = p;
                    else ll->next = p;

                    ll = p;
                }
                else
                {
                    if(head_rr == NULL)head_rr = p;
                    else rr->next = p;

                    rr = p;
                }

                p = p->next;
            }

            if(ll != NULL)
            {
                ll->next = head_rr;
            }
            else
            {
                head_ll = head_rr;
            }

            if(rr != NULL)
            {
                rr->next = NULL;
            }

            return head_ll;
        }
};
