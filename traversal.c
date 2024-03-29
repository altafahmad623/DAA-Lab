#include <stdio.h>

 typedef struct node
 {
   int value;
   struct node *right;
   struct node *left;
 }mynode;

 mynode *root;

 add_node(int value);
 void postorder(mynode *root);
 void inorder(mynode *root);
 void preorder(mynode *root);

 void iterativePreorder(mynode *root);
 void iterativeInorder (mynode *root);
 void iterativePostorder(mynode *root);


 int main(int argc, char* argv[])
 {
   root = NULL;
   int i,x;
   printf("Enter \n1. To Insert New Elements \n2. To Finish\n");
   scanf("%d",&i);
   while(i!=2)
   {		
      printf("Enter new element\n");
      scanf("%d",&x);
      add_node(x);
      printf("Enter \n1. To Insert New Elements \n2. To Finish\n");
      scanf("%d",&i);	
   }

   printf("\nPre-Order Traversal (recursive) is :");
   preorder(root);
   printf("\nPre-Order Traversal (iterative) is :");
   iterativePreorder(root);

   printf("\n\nPost-Order Traversal (recursive) is :");
   postorder(root);
   printf("\nPost-Order Traversal (iterative) is :");
   iterativePostorder(root);


   printf("\n\nIn-Order Traversal (recursive) is :");
   inorder(root);
   printf("\nIn-Order Traversal (iterative) is :");
   iterativeInorder(root);
   printf("\n");
 }

 // Function to add a new node to the BST
 add_node(int value)
 {
    mynode *prev, *cur, *temp;

    temp        = (mynode *) malloc(sizeof(mynode));
    temp->value = value;
    temp->right = NULL;
    temp->left  = NULL;

    if(root==NULL)
    {
      printf("\nCreating the root..\n");
      root = temp;
      return;
    }

    prev=NULL;
    cur=root;

    while(cur!=NULL)
    {
       prev=cur;
       cur=(value<cur->value)?cur->left:cur->right;
    }

    if(value < prev->value)
      prev->left=temp;
    else
      prev->right=temp;
 }


 // Recursive Preorder
 void preorder(mynode *root)
 {
   if(root)
   {
     printf("%d ", root->value);
     preorder(root->left);
     preorder(root->right);
   }
 }

 // Iterative Preorder
 void iterativePreorder(mynode *root)
 {
   mynode *save[100];
   int top = 0;

   if (root == NULL)
   {
     return;
   }

   save[top++] = root;
   while (top != 0)
   {
     root = save[--top];

     printf("%d ", root->value);

     if (root->right != NULL)
       save[top++] = root->right;
     if (root->left != NULL)
       save[top++] = root->left;
   }
 }

 // Recursive Postorder
 void postorder(mynode *root)
 {
   if(root)
   {
     postorder(root->left);
     postorder(root->right);
     printf("%d ", root->value);
   }
 }

 // Iterative Postorder
 void iterativePostorder(mynode *root)
 {
   struct
   {
     mynode *node;
     unsigned vleft :1;   // Visited left?
     unsigned vright :1;  // Visited right?
   }save[100];

   int top = 0;

   save[top++].node = root;

   while ( top != 0 )
   {
       /* Move to the left subtree if present and not visited */
       if(root->left != NULL && !save[top].vleft)
       {
           save[top].vleft = 1;
           save[top++].node = root;
           root = root->left;
           continue;
       }

       /* Move to the right subtree if present and not visited */
       if(root->right != NULL && !save[top].vright )
       {
           save[top].vright = 1;
           save[top++].node = root;
           root = root->right;
           continue;
       }

       printf("%d ", root->value);

       /* Clean up the stack */
       save[top].vleft = 0;
       save[top].vright = 0;

       /* Move up */
       root = save[--top].node;
    }
 }


 // Recursive Inorder
 void inorder(mynode *root)
 {
   if(root)
   {
     inorder(root->left);
     printf("%d ", root->value);
     inorder(root->right);
   }
 }


 // Iterative Inorder..
 void iterativeInorder (mynode *root)
 {
   mynode *save[100];
   int top = 0;

   while(root != NULL)
   {
       while (root != NULL)
       {
            if (root->right != NULL)
            {
              save[top++] = root->right;
            }
            save[top++] = root;
            root = root->left;
       }

       root = save[--top];
       while(top != 0 && root->right == NULL)
       {
           printf("%d ", root->value);
           root = save[--top];
       }

       printf("%d ", root->value);
       root = (top != 0) ? save[--top] : (mynode *) NULL;
   }
 }


