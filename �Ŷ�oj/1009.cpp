#include <cstdio>
#include <cstring>

struct Node
{
    int value;
    Node *left, *right;
} aa[12], bb[12];

void create_tree(char str[], Node list[], int n)
{
    for (int i = 0; i < n; i++)
    {
        list[i].left = NULL;
        list[i].right = NULL;
        list[i].value = -1;
    }

    int top = 0;

    for (int i = 0, m = strlen(str); i < m; i++)
    {
        int value = str[i] - '0';

        Node *p = &list[top++];
        Node *head = &list[0];

        while (head->value != -1)
        {
            if (head->value > value)
            {
                if (head->left == NULL)
                {
                    head->left = p;
                    break;
                }

                head = head->left;
            }
            else
            {
                if (head->right == NULL)
                {
                    head->right = p;
                    break;
                }

                head = head->right;
            }
        }

        p->value = value;
    }
}

bool compare_tree(Node *head_a, Node *head_b)
{
    if (head_a == NULL && head_b == NULL)return true;

    if (head_a == NULL || head_b == NULL)return false;

    if (head_a->value != head_b->value)
    {
        return false;
    }

    if (compare_tree(head_a->left, head_b->left))
    {
        if (compare_tree(head_a->right, head_b->right))
        {
            return true;
        }
    }

    return false;
}

char str[12];
int n;
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)break;

        scanf("%s", str);
        create_tree(str, aa, 12);

        for (int i = 0; i < n; i++)
        {
            scanf("%s", str);
            create_tree(str, bb, 12);
            compare_tree(&aa[0], &bb[0]) ? puts("YES") : puts("NO");
        }
    }

    return 0;
}
