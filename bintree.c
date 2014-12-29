#include <stdlib.h>
#include <stdio.h>

typedef struct node_s
{
    int value;
    struct node_s* left;
    struct node_s* right;
} *node;

node tree(int v, node l, node r)
{
    node n = malloc(sizeof(struct node_s));
    n->value = v;
    n->left  = l;
    n->right = r;
    return n;
}

void destroy_tree(node n)
{
    if (n->left)
        destroy_tree(n->left);
    if (n->right)
        destroy_tree(n->right);
    free(n);
}

void preorder(node n)
{
    printf("%d ", n->value);
    if (n->left)
        preorder(n->left);
    if (n->right)
        preorder(n->right);
}

void inorder(node n)
{
    if (n->left)
        inorder(n->left);
    printf("%d ", n->value);
    if (n->right)
        inorder(n->right);
}

void postorder(node n)
{
    if (n->left)
        postorder(n->left);
    if (n->right)
        postorder(n->right);
    printf("%d ", n->value);
}

int depth(node n)
{
    int l, r;
    if (!n) return 0;
    l = depth(n->left); 
    r = depth(n->right);
    return (l > r ? l:r) + 1;
}

int numleaf(node n)
{
    if (!n) return 0;
    if (!n->left && !n->right) return 1;
    return numleaf(n->left) + numleaf(n->right);
}

typedef struct qnode_s
{
    struct qnode_s* next;
    node value;
} *qnode;

typedef struct { qnode begin, end; } queue;

void enqueue(queue* q, node n)
{
    qnode node = malloc(sizeof(struct qnode_s));
    node->value = n;
    node->next = 0;
    if (q->end)
        q->end->next = node;
    else
        q->begin = node;
    q->end = node;
}

node dequeue(queue* q)
{
    node tmp = q->begin->value;
    qnode second = q->begin->next;
    free(q->begin);
    q->begin = second;
    if (!q->begin)
        q->end = 0;
    return tmp;
}

int queue_empty(queue* q)
{
    return !q->begin;
}

void levelorder(node n)
{
    queue nodequeue = {};
    enqueue(&nodequeue, n);
    while (!queue_empty(&nodequeue))
    {
        node next = dequeue(&nodequeue);
        printf("%d ", next->value);
        if (next->left)
            enqueue(&nodequeue, next->left);
        if (next->right)
            enqueue(&nodequeue, next->right);
    }
}

int main()
{
    node n = tree(1,
                    tree(2,
                            tree(4,
                                    tree(7, 0, 0),
                                    0),
                            tree(5, 0, 0)),
                    tree(3,
                            tree(6,
                                    tree(8, 0, 0),
                                    tree(9, 0, 0)),
                            0));
/*
                 1

              /     \

            2          3

          /   \      /

        4      5    6

      /           /   \
        
     7           8     9
*/

    printf("preorder:    ");
    preorder(n);
    printf("\n");

    printf("inorder:     ");
    inorder(n);
    printf("\n");

    printf("postorder:   ");
    postorder(n);
    printf("\n");

    printf("level-order: ");
    levelorder(n);
    printf("\n");

    printf("depth: ");
    printf("%d", depth(n));
    printf("\n");

    printf("numleaf: ");
    printf("%d", numleaf(n));
    printf("\n");

    destroy_tree(n);

    return 0;
}
