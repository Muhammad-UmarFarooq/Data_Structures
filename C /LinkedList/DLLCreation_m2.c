#include<stdio.h>
#include<stdlib.h>
// Define the structutre
struct node
{
	int data;
	struct node *next;
	struct node *prev;
}*newnode,*temp;
struct node *head = NULL;
// Create function
void Create()
{
	newnode=(struct node *)malloc(sizeof(struct node));
	 if (newnode == NULL) 
	 {
        printf("Memory allocation failed\n");
        return;
	 }
	printf("Enter data:");
	scanf("%d",&newnode -> data);
	newnode -> next = NULL;
	newnode -> prev = NULL;
	if(head == NULL)
	{
		head = temp = newnode;
	} 
	else
	{
		temp -> next =newnode;
		newnode -> prev =temp;
		temp = newnode;
	}
}
// Display function
void Display()
{
    struct node* temp1;
    if (head == NULL) 
    {
        printf("The list is empty.\n");
        return;
    }
    temp1=head;
    printf("The elements in the linked list are:\n");
	while(temp1 != NULL)
	{
		printf("%d\n",temp1 -> data);
		temp1 = temp1 -> next;
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


