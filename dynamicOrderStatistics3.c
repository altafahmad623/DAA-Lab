#include <stdio.h>
#include <stdlib.h>
#define RED		1
#define BLACK	2
struct node
{
	int key;
	struct node *left, *right, *p;
	int color;
	int size;
};
typedef struct node *NODEPTR;
struct node NIL;
NODEPTR NILPTR = &NIL;

NODEPTR search(NODEPTR root, int k)
{
	if (root == NILPTR || root->key == k)
		return root;
	if (k < root->key)
		return search(root->left, k);
	else
		return search(root->right, k);
}

NODEPTR minimum(NODEPTR root)
{
	while (root->left != NILPTR)
		root = root->left;
	return root;
}

NODEPTR maximum(NODEPTR root)
{
	while (root->right != NILPTR)
		root = root->right;
	return root;
}

void leftrotate(NODEPTR *treeroot, NODEPTR x)
{
	NODEPTR y = x->right;
	x->right = y->left;
	if (y->left != NILPTR)
		y->left->p = x;
	y->p = x->p;
	if (x->p == NILPTR)
		*treeroot = y;
	else if (x->p->left == x)
		x->p->left = y;
	else
		x->p->right = y;
	y->left = x;
	x->p = y;
	y->size = x->size;
	x->size = x->left->size + x->right->size +1;
}

void rightrotate(NODEPTR *treeroot, NODEPTR y)
{
	NODEPTR x = y->left;
	y->left = x->right;
	if (x->right != NILPTR)
		x->right->p = y;
	x->p = y->p;
	if (y->p == NILPTR)
		*treeroot = x;
	else if (y->p->left == y)
		y->p->left = x;
	else
		y->p->right = x;
	x->right = y;
	y->p = x;

	x->size = y->size;
	y->size = y->left->size + y->right->size + 1;

}

void rbinsertfixup(NODEPTR *treeroot, NODEPTR z)
{
	while (z->p->color == RED) {
		if (z->p == z->p->p->left) {
			NODEPTR y = z->p->p->right;
			if (y->color == RED) {
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else {
				if (z == z->p->right) {
					z = z->p;
					leftrotate(treeroot,z);
				}
				z->p->color = BLACK;
				z->p->p->color = RED;
				rightrotate(treeroot,z->p->p);
			}
		}
		else {
			NODEPTR y = z->p->p->left;
			if (y->color == RED) {
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else {
				if (z == z->p->left) {
					z = z->p;
					rightrotate(treeroot,z);
				}
				z->p->color = BLACK;
				z->p->p->color = RED;
				leftrotate(treeroot,z->p->p);
			}
		}
	}
	(*treeroot)->color = BLACK;
}

void rbinsert(NODEPTR *treeroot, int z) {
	NODEPTR Z = (NODEPTR) malloc(sizeof(struct node));
	Z->key = z;
	NODEPTR y = NILPTR;
	NODEPTR x = *treeroot;
	while (x != NILPTR) {
		y = x;

		y->size++;

		if (Z->key < x->key)
			x = x->left;
		else if (Z->key > x->key)
			x = x->right;
		else {
			/* if the value to be inserted is already in the tree, undo the changes */

			NODEPTR temp = x;
			while (x != *treeroot) {
				x->size--;
				x = x->p;
			}
			x->size--;
			free(Z);
			return;

		}
	}
	Z->p = y;
	if (y == NILPTR)
		*treeroot = Z;
	else if (Z->key < y->key)
		y->left = Z;
	else
		y->right = Z;
	Z->left = NILPTR;
	Z->right = NILPTR;
	Z->color = RED;
	Z->size = 1;
	rbinsertfixup(treeroot,Z);
}
NODEPTR kth(NODEPTR treeroot, int K) {
	int currrank = treeroot->left->size + 1;
	NODEPTR y = treeroot;
	while (y != NILPTR && currrank != K) {
		if (K < currrank)
			y = y->left;
		else {
			K = K - currrank;
			y = y->right;
		}
		if (y == NILPTR)
			return NILPTR;
		currrank = y->left->size + 1;
	}
	return y;
}

int cnt(NODEPTR treeroot, int x) {
	int ans = 0;
	NODEPTR y = treeroot;
	while (y != NILPTR) {
		if (y->key > x)
			y = y->left;
		else if (y->key < x) {
			ans += y->left->size + 1;
			y = y->right;
		}
		else
			return ans + y->left->size;
	}
	return ans;
}

int main()
{
	NIL.left = NIL.right = NIL.p = NILPTR;
	NIL.color = BLACK;
	NIL.size = 0;
	NODEPTR tree = NILPTR;
	int Q=1;
	int x, k;
	NODEPTR temp;
	while (Q!=3)
	{
        printf("Press 1 for Insertion\n");
        printf("Press 2 for finding Kth smallest\n");
        printf("Press 3 to exit\n");
		scanf("%d",&Q);
		switch (Q)
        {
			case 1:
			{
                printf("Enter value to insert:\n");
                scanf("%d", &x);
				rbinsert(&tree, x);
				break;
			}

			case 2:
			{
                printf("Enter value of 'i' to find 'i'th smallest \n");
                scanf("%d", &k);
				temp = kth(tree, k);
				if (temp != NILPTR)
					printf("The number at %dth value is %d\n",k, temp->key);
				else
					printf("The number of items inserted is less than %d\n",k);
				break;
			}
			default:
				exit(0);
		}
	}
	return 0;
}
