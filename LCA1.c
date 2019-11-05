#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0 
struct node {
    int data;
    struct node *left;
    struct node *right;
}; 
struct node* getNewNode(int data) 
{ 
  struct node* newNode = (struct node*)malloc(sizeof(struct node)); 
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;   
  return newNode;
}
 

struct node* generateBTree()
{
    // Root Node
    struct node* root =  getNewNode(7);
 
    root->left = getNewNode(5);
    root->right = getNewNode(12);
     
    root->left->left = getNewNode(4);
    root->left->right = getNewNode(50);
    root->right->right = getNewNode(8);
  
    root->left->left->left = getNewNode(18);
    root->left->left->right = getNewNode(9);
     
    return root;
}
 
/* Returns the Least Common Ancestor of n1 and n2 */
struct node* findLCA(struct node* root, int n1, int n2) {
 
    /* Base Condition */
    if(root == NULL) {
        return NULL;
    }
 
    /* if root is equal to either n1 and n2 then root is LCA. */
    if(root->data == n1 || root->data == n2) {
        return root;
    } else {
        /* Search for LCA in left sub tree  */
        struct node  *left = findLCA(root->left , n1 , n2);
        /* Search for LCA in right sub tree  */
        struct node *right = findLCA(root->right , n1, n2);
 
        /* If one node is found in left sub tree and another in 
         right sub tree than root is Least common ancestor */
        if(left && right) {
            return root;
        }
        /* If both nodes are in left sub tree 
         that left is the lca  otherwise right */
        if(left) {
            return left;
        } else {
            return right;
        }
    }
}
 
int main() 
{
/*
This function returns below tree
            7
           / \
         5    12
        / \    \
       4  50    8
      / \
     18  9
*/
    struct node *root = generateBTree();    
    int t1,t2;
    printf("Enter the two numbers for which Lowest Common ancestor is to be found\n");
    scanf("%d",&t1);	
    scanf("%d",&t2);
    printf("Least Common Ancestor of %d and %d: %d\n",t1,t2,findLCA(root, t1, t2)->data);

    return 0; 
}
