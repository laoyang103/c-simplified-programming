#include <stdlib.h>
#include <stdio.h>

typedef struct node_s
{
    int value;
    struct node_s* left;
    struct node_s* right;
} *node;
typedef struct qnode_s
{
    struct qnode_s* next;
    node value;
} *qnode;

typedef struct { qnode begin, end; } queue;

void enqueue(queue* q, node n)
{
    qnode node = (qnode )malloc(sizeof(struct qnode_s));
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

class Tree
{
    public:
        Tree() {
            this->root = _newtree(1,
                            _newtree(2,
                                    _newtree(4,
                                            _newtree(7, 0, 0),
                                            0),
                                    _newtree(5, 0, 0)),
                            _newtree(3,
                                    _newtree(6,
                                            _newtree(8, 0, 0),
                                            _newtree(9, 0, 0)),
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
        }
        ~Tree() { if (root) _destroy_tree(root); }
    private:
        node root;
    public:
        void destroy_tree() { _destroy_tree(root); }
        void preorder() { _preorder(root); }
        void inorder() { _inorder(root); }
        void postorder() { _postorder(root); }
        void levelorder() { _levelorder(root); }
        int depth() { return _depth(root); }
        int numleaf() { return _numleaf(root); }
    private:
        static node _newtree(int v, node l, node r);
        static void _destroy_tree(node n);
        static void _preorder(node n);
        static void _inorder(node n);
        static void _postorder(node n);
        static void _levelorder(node n);
        static int _depth(node n);
        static int _numleaf(node n);
};

node Tree::_newtree(int v, node l, node r)
{
    node n = (node )malloc(sizeof(struct node_s));
    n->value = v;
    n->left  = l;
    n->right = r;
    return n;
}

void Tree::_destroy_tree(node n)
{
    if (n->left)
        _destroy_tree(n->left);
    if (n->right)
        _destroy_tree(n->right);
    free(n);
}

void Tree::_preorder(node n)
{
    printf("%d ", n->value);
    if (n->left)
        _preorder(n->left);
    if (n->right)
        _preorder(n->right);
}

void Tree::_inorder(node n)
{
    if (n->left)
        _inorder(n->left);
    printf("%d ", n->value);
    if (n->right)
        _inorder(n->right);
}

void Tree::_postorder(node n)
{
    if (n->left)
        _postorder(n->left);
    if (n->right)
        _postorder(n->right);
    printf("%d ", n->value);
}

int Tree::_depth(node n)
{
    int l, r;
    if (!n) return 0;
    l = _depth(n->left); 
    r = _depth(n->right);
    return (l > r ? l:r) + 1;
}

int Tree::_numleaf(node n)
{
    if (!n) return 0;
    if (!n->left && !n->right) return 1;
    return _numleaf(n->left) + _numleaf(n->right);
}

void Tree::_levelorder(node n)
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

    Tree tree;

    printf("preorder:    ");
    tree.preorder();
    printf("\n");

    printf("inorder:     ");
    tree.inorder();
    printf("\n");

    printf("postorder:   ");
    tree.postorder();
    printf("\n");

    printf("level-order: ");
    tree.levelorder();
    printf("\n");

    printf("depth: ");
    printf("%d", tree.depth());
    printf("\n");

    printf("numleaf: ");
    printf("%d", tree.numleaf());
    printf("\n");

    return 0;
}
