class Solution
{
    public:
        ListNode *deleteDuplicates(ListNode *head)
        {
            ListNode *p = head, *q = NULL;

            if(head)q = head->next;

            while(q != NULL)
            {
                if(q->val != p->val)
                {
                    p->next = q;
                    p = q;
                }

                q = q->next;
            }

            if(p)p->next = NULL;

            return head;
        }
};
