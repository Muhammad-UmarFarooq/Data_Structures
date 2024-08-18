#include<stdio.h>
#include<stdlib.h>
// Defining the node
struct node
{
	struct node *lchild;
	int data;
	struct node *rchild;
}*root = NULL;

// Insert function
void Insert(int key)
{
	// t1 - for pointing to root node
    // r - follows the p node
    // p - used for creating a newnode
	struct node *t1=root;
	struct node *r=NULL,*p;
	// If it is the 1st node then this if state. is executed
	if(root == NULL)
	{
		p = (struct node *)malloc(sizeof(struct node));
		p->data =key;
		p->lchild = p->rchild = NULL;
		root = p;
		return;
	}
	// If it is not the 1st node then below loop is executed
	while(t1 != NULL)
	{
		r = t1;
		if(key < t1->data)
		{
			t1 = t1->lchild;
		}
		else if(key > t1->data)
		{
			t1 = t1->rchild;
		}
		else
		{
			return;
		}
		
	}
    // Below 3 lines is used to create a node which is not first node
	p = (struct node *)malloc(sizeof(struct node));
		p->data =key;
		p->lchild = p->rchild = NULL;
	// We check whether the newnode to be inserted is towards right or left
	if(key < r->data)
	{
		r->lchild = p;
	}
	else
	{
		r->rchild = p;
	}
}
// Inorder function
void Inorder(struct node *p)
{
	// Here p is pointing to root node
	if(p)
	{
		Inorder(p->lchild);
		printf("%d ",p->data);
		Inorder(p->rchild);
	}
}
// Search function
struct node *Search(int key)
{
  // temp1 again local variable to indicate root node
	struct node *temp1=root;
	while(temp1 != NULL)
	{
		if(key == temp1->data)
		{
			return temp1;
		}
		else if(key < temp1->data)
		{
			temp1 = temp1->lchild;
		}
		else
		{
			temp1 = temp1->rchild;
		}
	}
	return NULL;
}

// Main function
int main()
{
  // To store the value returned by Search function
	struct node *temp2;
	Insert(10);
	Insert(5);
	Insert(20);
	Insert(8);
	Insert(30);
	
	Inorder(root);
		
	temp2 = Search(30);
	if(temp2 != NULL)
	printf("\nElement %d is found",temp2->data);
	else
	printf("\nElement is not found");
	
	return 0;
}
