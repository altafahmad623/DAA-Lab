#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef    struct node		//Defining the required linked list with their respective members
	{
   	 	char info;
   	 	struct node *next;		//pointer for pointing to next element in the list
	}Node;
	
Node *push(Node *start,char value);	//Using prototype functions
	char c;	
Node *pop(Node *start);
char top(Node *start);
int isEmpty(Node *start) ;
int main()
{
	Node *start=NULL;
	
	char ch;
	int a = -1;
	char temp;
	while(a!=5)
	{	
		printf("1- Push a character into it\n2- pop a character out of the stack\n3- Top of the stack\n4-Check if it is empty\n");
		scanf("%d",&a);
		switch (a)
		{
			case 1:
			{		
					printf("Enter character\n");
					scanf("%c", &temp);
				   scanf("%c",&ch);
				   start=push(start,ch);
					break;
			}			
			case 2:
			{		start=pop(start);
					break;
			}		
			case 3:
			{
					ch=top(start);
					printf("%c\n",ch);
					break;
			}			
			case 4:
			{	if(isEmpty(start))
					{printf("Stack is Empty\n");}
					break;
			}		
		}
	}
}
	int isEmpty(Node *start) 
{ 
    return start == NULL; 
} 
  
// Utility function to return top element in a stack 
char top(Node *start) 
{ 
    // check for empty stack 
    if (!isEmpty(start)) 
        return start->info; 
    else
        exit(1); 
} 
Node *push(Node *start,char value)		//passing the required parameters to the function
{
   		Node *temp;
   		temp=(Node *)malloc(sizeof(Node));	//Dynamically allocating memory to temp for saving the required characters
   		temp->info=value;			//Stroring each element to the list
		if(start == NULL)
		{
			start = temp;
			return start;		
		}   		
		temp->next=start;			//Moving to the next element in the list 
   		start=temp;				//Continue to save new characters
   		return start;				//lastly returning the pointer
}

	Node *pop(Node *start)				//function for poping the charaters from stack
	{
    		Node *temp;				//popping and hence checking the charaters
    		temp=start;
    		c=temp->info;
    		start=temp->next;			
    		free(temp);				//freeing the defined memory
    		return start;
	}

