#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
    int is_thread;
} TreeNode;

TreeNode n1 = {'A', NULL, NULL, 1};
TreeNode n2 = {'B', NULL, NULL, 1};
TreeNode n3 = {'C', &n1, &n2, 0};
TreeNode n4 = {'D', NULL, NULL, 1};
TreeNode n5 = {'E', NULL, NULL, 0};
TreeNode n6 = {'F', &n4, &n5, 0};
TreeNode n7 = {'G', &n3, &n6, 0};
TreeNode *ex = &n7;

TreeNode *find_successor(TreeNode *p)
{
    // q는 p의 오른쪽 포인터
    TreeNode *q = p->right;

    // 만약 오른쪽 포인터가 NULL이거나 스레드이면 오른쪽 포인터를 반환
    if (q == NULL || p->is_thread == TRUE)
        return q;

    while (q->left != NULL)
        q = q->left;
    return q;
}

void thread_inorder(TreeNode *t)
{
    TreeNode *q;
    q = t;
    while (q->left != NULL)
        q = q->left;
    do
    {
        printf("%c", q->data);
        q = find_successor(q);
    } while (q != NULL);
}

int main()
{

    // 스레드 설정
    n1.right = &n3;
    n2.right = &n7;
    n4.right = &n6;

    // 중위 순회
    thread_inorder(ex);
}