#include <stdio.h>
#include <stdlib.h>
struct node
{
	long int val;
	struct node* next;
};

int main()
{
	//long int arr[1000];
	//printf("%d ",arr[0]);
	char ab;
	long int a=5,i,j;
	int pos;
	struct node* head[1000];
	struct node* temp,*newNode;
	for(i=0;i<1000;i++)
	{
		head[i] = (struct node*)malloc(sizeof(struct node)); //create a array of header files

	}
	printf("Enter \na)To insert new values\nb)To search for values \nd)To Exit\ne)To view\n");	
	scanf("%c",&ab);
	while(ab!='d')
	{
		
		if(ab=='a')
		{
			printf("Enter the large values\n");
			scanf("%ld",&a);
			pos=a%1000;//hash function is mod 1000
			if(head[pos]->val==0)
			{
				//arr[pos]=a;
				head[pos]->val=a;
				head[pos]->next=NULL;
			}
			else
			{
				temp=head[pos];
				while(temp != NULL)
    				{
        				
        				temp = temp->next;                 // Move to next node
    				}
				newNode = (struct node*)malloc(sizeof(struct node)); 
        			newNode->val = a; // Link data field of newNode
        			newNode->next = NULL; // Make sure new node points to NULL 
        			temp = newNode; // Link previous node with newNode
        			printf(" %ld ",temp->val);
			}
		}
		else if(ab=='b')
		{
			printf("Enter the value to search\n");
			scanf("%ld",&a);	
			pos=a%1000;
			temp=head[pos];
			while(temp != NULL)
    			{
       				if(temp->val==a)
				{
					printf("Number found at %d\n",pos);
					break;
				}
       				temp = temp->next;                 // Move to next node
    			}
			if(temp==NULL)
				printf("Not found\n"); 
			
		}

		else if(ab=='e')
		{

			for(i=0;i<1000;i++)
			{
				temp=head[i];
				if(head[i]->val!=0)
				{
					while(temp!= NULL)
    					{					
						printf("%ld ",temp->val);					
       						temp = temp->next;                 // Move to next node
    					}
					printf("\n");
				}
			}
		}
		//printf("Enter \na)To insert new values\nb)To search for values \nd)To Exit\ne)To view\n");
		scanf("%c",&ab);
	}
	
}
