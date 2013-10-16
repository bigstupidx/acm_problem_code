class Solution
{
    public:

        void copy(RandomListNode *head)
        {
            RandomListNode *p, *phead = head;

            while (phead != NULL)
            {
                p = new RandomListNode(phead->label);
                p->next = phead->next;
                phead->next = p;
                phead = p->next;
            }
        }

        void setRandom(RandomListNode *head)
        {
            if (head == NULL)return;

            RandomListNode *head1 = head, *head2 = head->next;

            while (head1 != NULL)
            {
                if (head1->random != NULL)
                {
                    head2->random = head1->random->next;
                }
                else
                {
                    head2->random = NULL;
                }

                head1 = head2->next;

                if (head1)
                {
                    head2 = head1->next;
                }
            }
        }

        RandomListNode *separate(RandomListNode *head)
        {
            if (head == NULL)return NULL;

            RandomListNode *head1 = head, *result = head->next, *head2 = result;

            while (head1 != NULL)
            {
                head1->next = head2->next;
                head1 = head2->next;

                if (head1 != NULL)
                {
                    head2->next = head1->next;
                    head2 = head1->next;
                }
            }

            return result;
        }


        RandomListNode *copyRandomList(RandomListNode *head)
        {
            copy(head);
            setRandom(head);
            return separate(head);
        }
};
