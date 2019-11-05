#include <stdio.h>
#include <stdlib.h>
struct node //structure of the node to create the linked list 
{
	int d;  // data variable for the linked list
	struct node* next; //pointer for the next element
};
 void reverse(struct node** head_ref) //function to reverse the list
{ 
    struct node* prev   = NULL; 
    struct node* current = *head_ref; 
    struct node* next = NULL; 
    while (current != NULL) 
    { 
        next  = current->next;  //store the next pointer
        current->next = prev;      //reverse the previous pointer
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
} 
int main()
{
	struct node* head=0;// creating the head of the list
	int a,data,pos,i;
	struct node* m;
	struct node* n;
	
	do
	{
	struct node* newhd=(struct node*)malloc(sizeof(struct node));// allocating size for the new elemnt to be added
	printf("Enter \"1\" to insert at the beginning\n");    // Menu to navigate the various things
	printf("Enter \"2\" to insert at the end\n");
	printf("Enter \"3\" to insert at the kth position\n");
	printf("Enter \"4\" to delete a node with given data\n");
	printf("Enter \"5\" to reverse all nodesw in the linked list\n");
	printf("Enter \"6\" to quit\n");
	printf("Enter \"7\" to print the linked list\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1 : printf("Enter data\n");//case to insert at the beginning
			scanf("%d",&data);
			
			newhd->d=data; //adding new data
			newhd->next= head;//pointing to the head			
			head=newhd;// ponting back
			
			break; 
		case 2 :printf("Enter data\n");
			scanf("%d",&data);
			m=head;
			if(m==0)//case if list is empty
			{newhd->d=data;
			newhd->next= head;//creating a new element
			
			head=newhd;}
			else
			{
			while(m->next!=NULL)//traversing to the end of the list
			{
				m=m->next;	
			}

			newhd->d=data;//inserting data at the end
			newhd->next= NULL;
			m->next=newhd;
			}
			break;
		case 3 :printf("Enter data\n");
			scanf("%d",&data);
			printf("Enter position\n");
			scanf("%d",&pos);
			m=head;
			for(i=0;i<pos;i++)//finding the position the position starts from 0,1,2 ..and so on
			{m=m->next;}
			newhd->d=data;//inserting data at the required position
			newhd->next=m->next;
			m->next=newhd;
			break;
		case 4 :printf("Enter data in the position");
			scanf("%d",&data);
			i=0;
			m = head;
			while( (m!=NULL)&&(m->d!=data) )//finding the required data to be deleted
			{
				n=m;
				m=m->next;
				i++;
			}
			if(m!=NULL)
			{
				n->next = m->next;free(m); 
			}
			
			
			break;
		case 5 :reverse(&head);
			break;
		case 7 :			
			m=head;
			while(m!=NULL)//Case to print the linked list
			{
				printf("%d",m->d);
				printf("\n");
				m=m->next;				
			}
			break;

			
	}
	}while(a!=6);
	
}

