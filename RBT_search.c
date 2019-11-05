/*
Adarsh Kumar
18MA20003
*/

#include <stdio.h>
#include <stdlib.h>

int BLACK = 1,RED = 0;

struct node{
    int data;
    struct node* left,*right,*parent;
    int color;
};

typedef struct node Node;


void BST_insert(struct node*newNode,struct node**Node)
{
    //printf("hehaheha\n");
    if ((*Node)->data>(newNode)->data)
    {
        //printf("left\n");
        if ((*Node)->left == NULL){
            (*Node)->left = newNode;
            (*Node)->left->parent = *Node;
            //printf("blehbleh\n");
            return;
        }
        else
            BST_insert(newNode,&((*Node)->left));
    }
    else
    {
        //printf("right\n");
        if ((*Node)->right == NULL){
            (*Node)->right = newNode;
            (*Node)->right->parent = *Node;
            //printf("blehbleh\n");
            return;
        }
        else
            BST_insert(newNode,&((*Node)->right));
    }
    //printf("bleh\n");
}

void rotateLeft(Node **root, Node **ptr)
{
    Node *ptr_right = (*ptr)->right;

    (*ptr)->right = ptr_right->left;

    if ((*ptr)->right != NULL)
        (*ptr)->right->parent = *ptr;

    ptr_right->parent = (*ptr)->parent;

    if ((*ptr)->parent == NULL)
        *root = ptr_right;

    else if (*ptr == (*ptr)->parent->left)
        (*ptr)->parent->left = ptr_right;

    else
        (*ptr)->parent->right = ptr_right;

    ptr_right->left = *ptr;
    (*ptr)->parent = ptr_right;
}

void rotateRight(Node **root, Node **ptr)
{
    Node *ptr_left = (*ptr)->left;

    (*ptr)->left = ptr_left->right;

    if ((*ptr)->left != NULL)
        (*ptr)->left->parent = (*ptr);

    ptr_left->parent = (*ptr)->parent;

    if ((*ptr)->parent == NULL)
        *root = ptr_left;

    else if ((*ptr) == (*ptr)->parent->left)
        (*ptr)->parent->left = ptr_left;

    else
        (*ptr)->parent->right = ptr_left;

    ptr_left->right = (*ptr);
    (*ptr)->parent = ptr_left;
}

struct node* new_node(int data)
{
  struct node* nod = (struct node*)malloc(sizeof(struct node));
  nod->data = data;
  nod->left = NULL;
  nod->right = NULL;
  nod->parent = NULL;
  nod->color = RED;
  return nod;
}

void check_violation(Node **root, Node **ptr)
{
    Node *parent_ptr = NULL;
    Node *gp_ptr = NULL;         //Pointer to Grandparent

    while ((*ptr != *root) && ((*ptr)->color != BLACK) &&
           ((*ptr)->parent->color == RED))
    {

        parent_ptr = (*ptr)->parent;
        gp_ptr = (*ptr)->parent->parent;
        if (parent_ptr == gp_ptr->left)
        {

            Node *uncle_ptr = gp_ptr->right;
            if (uncle_ptr != NULL && uncle_ptr->color == RED)
            {
                gp_ptr->color = RED;
                parent_ptr->color = BLACK;
                uncle_ptr->color = BLACK;
                *ptr = gp_ptr;
            }

            else
            {
                if (*ptr == parent_ptr->right)
                {
                    rotateLeft(root, &parent_ptr);
                    *ptr = parent_ptr;
                    parent_ptr = (*ptr)->parent;
                }
                rotateRight(root, &gp_ptr);
                int temp1 = parent_ptr->color;
                parent_ptr->color = gp_ptr->color;
                gp_ptr->color = temp1;
                *ptr = parent_ptr;
            }
        }
        else
        {
            Node *uncle_ptr = gp_ptr->left;
            if ((uncle_ptr != NULL) && (uncle_ptr->color == RED))
            {
                gp_ptr->color = RED;
                parent_ptr->color = BLACK;
                uncle_ptr->color = BLACK;
                *ptr = gp_ptr;
            }
            else
            {
                if (*ptr == parent_ptr->left)
                {
                    rotateRight(root, &parent_ptr);
                    *ptr = parent_ptr;
                    parent_ptr = (*ptr)->parent;
                }
                rotateLeft(root, &gp_ptr);
                int temp1 = parent_ptr->color;
                parent_ptr->color = gp_ptr->color;
                gp_ptr->color = temp1;
                *ptr = parent_ptr;
            }
        }
    }

    (*root)->color = BLACK;
}

Node* RBT_insert(Node**root,int data)
{
    Node* newNode = new_node(data);
    if (*root == NULL)
        {
            *root = newNode;
        }
        else
        BST_insert(newNode,root);
    check_violation(root,&newNode);
    return *root;
}

void RBT_search(struct node* root,int x)
{
    if (root == NULL)
    {printf("Sorry, Not found!!!\n");return;}
    else if (root->data == x)
    {
        printf("Found!!!!\n");
    }
    else if (root->data<x)
    {
        RBT_search(root->right,x);
    }
    else
        RBT_search(root->left,x);
}

int main()
{
    int n,i=0;
    printf("Enter the number of elements in Tree: ");
    scanf("%d",&n);
    printf("Enter the elements: \n");
    int a[n];
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    Node* root;
    root = NULL;
    for(i=0;i<n;i++)
    {
        root = RBT_insert(&root,a[i]);
    }
    int x;
    printf("Enter the Element to search: ");
    scanf("%d",&x);
    RBT_search(root,x);
}
