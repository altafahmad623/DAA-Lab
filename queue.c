#include<stdio.h>
#include<stdlib.h>			//library used for dynamic memory allocation functions
#include<string.h>			//library used for functions used for string 
typedef struct node
{
    ;
    int data;
    struct node *next;
}Node;
Node *headA = NULL,*tailA= NULL;	
int enqueue( int id);
int display(struct node *head);
int isEmpty();
int dequeue();
int main()
{
	int tempid;
    while(1)			//Displaying the menu oriented program
    {
    printf("1.Enqueue\n");
	printf("2.DeQueue\n");
	printf("3.isEmpty\n");
	printf("4.Display\n");
	printf("5.Exit.\n");
        int i;
        scanf("%d", &i);		//Scanning the particular number to running that particular function
        if(i==1)			//running for i==1
            {
                printf("Enter the new number \n");
                	scanf("%d", &tempid);
					enqueue(tempid);
            }

       	if(i==2)			
            {
                dequeue();	
            }

        if(i==3)			
            {
               if(isEmpty())
				{printf("Queue is Empty\n");}
            }

         if(i==4)				
            {
				display(headA);

            }

        if(i==5)			//running for i==5
                exit(-1);		//Hence exiting the program 
        }

    }
int display(struct node *head)			//function to display the particular info of person's in the queue 
{
	if(head == NULL)			//if no info entered
        	printf("No element in this queue!\n");
    	while(head != NULL)			//running till the pointer comes null
    	{
        	printf("%d\n",head->data);	//hence printing info
        	head = head->next;				//changing the pointer position
    	}
    	return 0;
}
int enqueue( int id)		//function for enqueuing in a particular queue
{
    Node *temp = (struct node*)malloc(sizeof(struct node));		//dynamically allocating memory for person's in the queue
    temp->next = NULL;
    temp->data = id;				//saving the particular info for the person in the queue
   
   
       				//increasing the number in that particular queue
       if(headA == NULL)			//if not entered any then starting from first	
       {
           headA = temp;
           tailA = temp;
       }
       else					//if already entered then continuing from next pointer and then pointing to next
       {
           tailA->next = temp;
           tailA = temp;
       }
   
     
    
	return 0;
}
int isEmpty() 
{ 
    return headA == NULL; 
} 
int dequeue()			
{

	headA = headA->next;	//changing pointer to next
				
        
	return 0;
}
