#include<stdio.h>
#include<stdlib.h>
//color= 'r' for red and 'b' for black
struct rbtN
{
    int key;
    struct rbtN *left, *right, *parent;
    char col;
};

struct rbtN* newNode(int item,struct rbtN * root)
{
    struct rbtN* temp=(struct rbtN*)malloc(sizeof(struct rbtN));
    temp->key=item;
    temp->left=temp->right=NULL;
    temp->col='r';
    temp->parent=NULL;
    return temp;

}
struct rbtN* bstIn(struct rbtN * root,struct rbtN * ptr)
{
    if(root==NULL)
        return ptr;
    if (ptr->key <= root->key)
	{
		root->left = bstIn(root->left, ptr);
		root->left->parent = root;
	}
	else if (ptr->key > root->key)
	{
		root->right = bstIn(root->right, ptr);
		root->right->parent = root;
	}
	return root;

}
void rotateLeft(struct rbtN * root, struct rbtN * pt)
{
	struct rbtN *pt_right = pt->right;

	pt->right = pt_right->left;

	if (pt->right != NULL)
		pt->right->parent = pt;

	pt_right->parent = pt->parent;

	if (pt->parent == NULL)
		root = pt_right;

	else if (pt == pt->parent->left)
		pt->parent->left = pt_right;

	else
		pt->parent->right = pt_right;

	pt_right->left = pt;
	pt->parent = pt_right;
}
void rotateRight(struct rbtN *root, struct rbtN *pt)
{
	struct rbtN *pt_left = pt->left;

	pt->left = pt_left->right;

	if (pt->left != NULL)
		pt->left->parent = pt;

	pt_left->parent = pt->parent;

	if (pt->parent == NULL)
		root = pt_left;

	else if (pt == pt->parent->left)
		pt->parent->left = pt_left;

	else
		pt->parent->right = pt_left;

	pt_left->right = pt;
	pt->parent = pt_left;
}
void fixV(struct rbtN * root,struct rbtN * pt)
{
    struct rbtN *p_pt = NULL;
    struct rbtN *gp_pt = NULL;
    while ((pt != root) && (pt->col != 'b') &&(pt->parent->col == 'r'))
    {
        p_pt = pt->parent;
		gp_pt = pt->parent->parent;
        /* Case : A
        Parent of pt is left child of Grand-parent of pt */
		if (p_pt == gp_pt->left)
		{
		    struct rbtN *u_pt =gp_pt->right;
		    //case 1 : uncle is red too
		    //only coloring is required
		    if(u_pt!=NULL && u_pt->col=='r')
            {
                u_pt->col='b';
                gp_pt->col='r';
                p_pt->col='b';
                pt=gp_pt;
            }
			else
			{
				/* Case : 2
				pt is right child of its parent
				Left-rotation required */
				if (pt == p_pt->right)
				{
					rotateLeft(root, p_pt);
					pt = p_pt;
					p_pt = pt->parent;
				}
                /* Case : 3
				pt is left child of its parent
				Right-rotation required */
				rotateRight(root, gp_pt);
				char c;
				c=p_pt->col;
				p_pt->col=gp_pt->col;
				gp_pt->col=c;
				pt = p_pt;
			}
		}
		else
		{
			struct rbtN *uncle_pt = gp_pt->left;

			/* Case : 1
				The uncle of pt is also red
				Only Recoloring required */
			if ((uncle_pt != NULL) && (uncle_pt->col == 'r'))
			{
				gp_pt->col = 'r';
				p_pt->col = 'b';
				uncle_pt->col = 'b';
				pt = gp_pt;
			}
			else
			{
				/* Case : 2
				pt is left child of its parent
				Right-rotation required */
				if (pt == p_pt->left)
				{
					rotateRight(root, p_pt);
					pt = p_pt;
					p_pt = pt->parent;
				}

				/* Case : 3
				pt is right child of its parent
				Left-rotation required */
				rotateLeft(root, gp_pt);
				char c;
				c=p_pt->col;
				p_pt->col=gp_pt->col;
				gp_pt->col=c;
				pt = p_pt;
			}
		}
    }
    root->col='b';
}
struct rbtN* insertr (struct rbtN * root, int a)
{
    struct rbtN* ptr=newNode(a,ptr);
    root=bstIn(root,ptr);
    fixV(root, ptr);

}
void printTree(struct rbtN* root)
{
    if(root==NULL)
        return;
    printTree(root->left);
    printf("%d ",root->key);
    if(root->col=='r')
        printf("red\n");
    else
        printf("black\n");
    printTree(root->right);
}
int main()
{
    struct rbtN* root=NULL;
    /*int a=1,b;
	while(a)
    {
        printf("Enter the number to be entered\n");
        scanf("%d",&b);
        root=insertr(root,b);
        printf("Enter 1 to keep inserting and 0 to exit\n");
        scanf("%d",&a);
    }*/
    root=insertr(root,20);
    root=insertr(root,5);
    root=insertr(root,32);
    root=insertr(root,7);
    root=insertr(root,9);
    root=insertr(root,64);
    root=insertr(root,33);
    root=insertr(root,99);
    root=insertr(root,25);
    printTree(root);

}
