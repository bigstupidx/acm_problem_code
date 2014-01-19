
class Solution
{
    public:
        ListNode *deleteDuplicates(ListNode *head)
        {
            ListNode *result = NULL, *result_tail, *pre = NULL, *q = head;

            bool flag = false;

            while(q != NULL)
            {
                if(pre == NULL)
                {
                    pre = q;
                    flag = false;
                }
                else if(pre->val == q->val)
                {
                    flag = true;
                }
                else
                {
                    if(!flag)
                    {
                        if(result == NULL)result =  pre;
                        else result_tail->next = pre;

                        result_tail = pre;
                        result_tail->next = NULL;
                    }

                    pre = q;
                    flag = false;
                }

                q = q->next;
            }

            if(!flag && pre)
            {
                if(result == NULL)result = result_tail = pre;
                else result_tail->next = pre;

                result_tail = pre;
                result_tail->next = NULL;
            }

            return result;
        }
};
