
/**
*Definition for singly - linked list.
* struct ListNode {
	*int val;
	*ListNode *next;
	*ListNode(int x) : val(x), next(NULL) {}
	*
};
*/
class Solution
{
    public:
        ListNode *reverseKGroup(ListNode *head, int k)
        {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            ListNode *tail = head, *pre = NULL;

            bool flag = false;

            while (tail != NULL)
            {
                vector<ListNode *>nodes;
                int j = k;

                while (j > 0 && tail != NULL)
                {
                    nodes.push_back(tail);
                    tail = tail->next;
                    --j;
                }

                if (j > 0)break;

                if (pre != NULL)pre->next = nodes[k - 1];

                for (int i = k - 1; i > 0; i--)
                {
                    nodes[i]->next = nodes[i - 1];
                }

                nodes[0]->next = tail;

                if (!flag) { flag = true; head = nodes[k - 1]; }

                pre = nodes[0];
            }

            return head;
        }
};
