
//In this we have 1.create 2.display 3.exit(which frees  memory and exit the program) functions of linked list.
// We are getting segmentation fault here -- Pointer Misuse : If any of the pointers (head, temp, newnode) are somehow altered or 
// if there’s an attempt to dereference a NULL or invalid pointer, it could cause a segmentation fault.
// This error has been resolved by not altering temp pointer variable but creating another pointer variable i.e.temp2 in display function.
#include<stdio.h>
#include<stdlib.h>
// Define the structutre
struct node
{
	int data;
	struct node *next;
}*head = NULL,*newnode,*temp;
// Create function
void Create()
{
    int data;
	newnode=(struct node *)malloc(sizeof(struct node));
	 if (newnode == NULL) 
	 {
        printf("Memory allocation failed\n");
        return;
	 }
	printf("Enter data:");
	scanf("%d",&data);
	newnode->data=data;
	newnode -> next = NULL;
	if(head == NULL)
	{
		head = temp = newnode;
	} 
	else
	{
		temp -> next =newnode;
		temp = newnode;
	}
}
// Display function
void Display()
{  
    struct node *temp2;
    if (head == NULL) 
    {
        printf("The list is empty.\n");
        return;
    }
    temp2=head;
    printf("The elements in the linked list are:\n");
	while(temp2 != NULL)
	{
		printf("%d\n",temp2 -> data);
		temp2 = temp2 -> next;
	}
}
// Free function
void Free()
{
    struct node *current=head;
    struct node *next;
    while(current != NULL)
    {
        next = current -> next;
        free(current);
        current = next;
    }
    head = NULL;
}
// Main function
int main()
{
	int choice;
	while(1)
	{
		printf("1.Create 2.Display 3.Exit\n");
		printf("Enter choice:\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				Create();
				break;
			case 2:
				Display();
				break;
		        case 3:
		               Free();
		               exit(0);
	               default:
				printf("Enter a valid option\n");
	       }
	}
	return 0;
}
