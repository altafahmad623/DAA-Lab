#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
typedef struct Node
{
	int key;
	char color;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
} Node;

			
struct Node  T_Nil_Node;
       Node* T_Nil = &T_Nil_Node;

Node* Root = NULL;

// A utility function to create a new BST node
Node* newNode(int key)
{
	Node *temp   = (Node*) malloc(sizeof(Node));
	temp->key    = key;
	temp->color  = 'R';
	temp->left   = NULL;
	temp->right  = NULL;
	temp->parent = NULL;
	return temp;
}
void rotateLeft( Node** T, Node* x)
{
	Node *y  = x->right;    // set y
    	x->right = y->left;     // turn y's left subtree into x's right subtree{
   	if (y->left != T_Nil)
        	y->left->parent = x;
    	y->parent = x->parent;  // link x's parent to y
    	if (x->parent == T_Nil)
       		*T = y;
    	else if (x == x->parent->left)
       		x->parent->left = y;
    	else
       		x->parent->right = y;
    	y->left   = x;            // put x on y's left
    	x->parent = y;
}

void rotateRight(Node** T, Node* y)
{
    	Node *x  = y->left;     // set x
    	y->left  = x->right;    // turn x's right subtree into y's left subtree{
    	if (x->right != T_Nil)
        	x->right->parent = y;
    	x->parent = y->parent;  // link y's parent to x
    	if (y->parent == T_Nil)
       		*T = x;
    	else if (y == y->parent->right)
       		y->parent->right = x;
    	else
       		y->parent->left  = x;
    	x->right  = y;         // put y on x's right
    	y->parent = x;
}
void redBlackInsertFixup(Node** Root, Node* New)
{
Node* temp;
    	while(New->parent->color == 'R')
    	{
        	if(New->parent->key == New->parent->parent->key)
        	{
            		temp = New->parent->parent->right;
            		if(temp->color == 'R')
            		{
                		New->parent->color = 'B';
                		temp->color = 'B';
                		New->parent->parent->color = 'R';
                		New = New->parent->parent;
           		}
            		else if(New->key == New->parent->right->key)
            		{
                		New = New->parent;
                		rotateLeft(Root,New);
            		}
            		New->parent->color = 'B';
            		New->parent->parent->color = 'R';
            		rotateRight(Root,New->parent->parent);
       		}
        	else
        	{
            		temp = New->parent->parent->left;
            		if(temp->color == 'R')
            		{
                		New->parent->color = 'B';
                		New->color = 'B';
                		New->parent->parent->color = 'R';
                		New = New->parent->parent;
            		}
            		else if(New->key == New->parent->left->key)
            		{
                		New = New->parent;
                		rotateRight(Root,New);
            		}
            		New->parent->color = 'B';
            		New->parent->parent->color = 'R';
            		rotateLeft(Root, New->parent->parent);
       		}
    	}
    	Root[0]->color = 'B';
}
void redBlackInsert(Node** T, int key)
{
    	Node* z =  newNode(key);
    	Node* y =  T_Nil;
    	Node* x = *T;

    	// Find where to Insert new node Z into the binary search tree
    	while (x != T_Nil) 
	{
       		y = x;
       		if (z->key < x->key)
          		x = x->left;
       		else
          		x = x->right;
    	}

    	z->parent = y;
    	if (y == T_Nil)
       		*T = z;
    	else if (z->key < y->key)
        	y->left  = z;
    	else
        	y->right = z;

    	// Init z as a red leaf
    	z->left  = T_Nil;
    	z->right = T_Nil;
    	z->color = 'R';

    	// Ensure the Red-Black property is maintained
    	redBlackInsertFixup(T,z);
}



int height(Node* Root)
{
 	int h = 0;

 	if (Root != NULL) 
	{
    		if (Root == T_Nil)
       			h = 1;
    		else
      		{
      	 		int leftHeight  = height(Root->left);
       			int rightHeight = height(Root->right);
       			h = MAX(leftHeight, rightHeight) + 1;
      		}
   	}

 	return h;
}


int blackHeight(Node* Root)
{
 	int height = 0;

 	while (Root) 
	{
    		if ((Root == T_Nil) || (Root->color == 'B'))
       			height++;
    		Root = Root->left;
 	}
 	return height;
}

void PrintHelper(Node* Root)
{
    	Node* temp = Root;
    	if (temp != NULL)
    	{
        	PrintHelper(temp->left);
        	printf(" %d%c(h=%d,bh=%d) ", temp->key, (temp->color == 'B' ? 'B' : 'R'), height(temp), blackHeight(temp));
       	 	PrintHelper(temp->right);
    	}
}
void redBlackTreePrint(Node* Root)
{
    	printf("Tree Height=%d, Black-Height=%d\n", height(Root), blackHeight(Root));
    	PrintHelper(Root);
    	printf("\n");
}

int main()
{
    	Node* Root = T_Nil;

    	printf("Enter \n1 To Insert New Elements \n2 To Finish\n");

	int x,i;
    	scanf("%d",&i);
    	while(i!=2)
	{

		printf("Enter new element\n");
		scanf("%d",&x);
		redBlackInsert(&Root,x);
		printf("Enter \na. To Insert New Elements \nb. To Finish\n");
		printf("Enter 1 or 2\n");
		scanf("%d",&i);

		
	}
    	
    	redBlackTreePrint(Root);
}
