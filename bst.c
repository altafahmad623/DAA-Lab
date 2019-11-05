#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int key;
    struct node *left,*right;
}Node;

Node* New_Node(int value)
{
    Node *temp =(Node*)malloc(sizeof(Node));
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert_node(Node *root,int value)
{
    if(root==NULL)
        return New_Node(value);
    if(root->key>value)
        root->left = insert_node(root->left,value);
    else
        root->right = insert_node(root->right,value);
}

int main()
{
    int i;
    Node *head =NULL;
    printf("Enter \na. To Insert New Elements \nb. To Finish\n");
    char a;
    scanf("%c",&a);
    while(a!='b')
    {
        scanf("%d",&i);
	insert_node(head,i);	
    }
    
      	
}
