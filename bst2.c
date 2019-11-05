#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node *left,*right;
};
struct node* NewNode(int item)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node*));
	temp->key=item;
	temp->left=temp->right=NULL;
	return temp;
}

struct node* insert(struct node* node,int key)
{
	if(node==NULL)
	return NewNode(key);
	else if(key<node->key)
	node->left=insert(node->left,key);
	else if(key>node->key)
	node->right=insert(node->right,key);
	return node;
}
int main()
{
	int i,n,x;
	struct node* root=NULL;
    	printf("Enter \n1. To Insert New Elements \n2. To Finish\n");
    	char a;
    	scanf("%d",&i);
    	while(a!='b')
	{
		
		printf("Enter new element\n");
		scanf("%d",&x);
		insert(root,x);
		printf("Enter \n1. To Insert New Elements \nb. To Finish\n");
		scanf("%d",&i);
	
	}

}
