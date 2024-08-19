// Binary tree 
/* Operations -- Create,
                 Preorder,
	         Inorder,
		 Postorder
*/
#include<stdio.h>
#include<stdlib.h>
//Node structure
struct node
{
	int data;
	struct node *left,*right;
};
//Create function
struct node *Create()
{
	int data;
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter data(-1 for no node):");
	scanf("%d",&data);
	if(data == -1)
	{
		return 0;
	}
	newnode -> data =data;
	printf("\nEnter left child of %d",data);
	newnode -> left = Create();
	printf("\nEnter right child of %d",data);
	newnode -> right = Create();
	return newnode;
}
//Preorder function
void Preorder(struct node *root)// The argument can be given any variable name 
{
	if(root == 0)
	{
		return;
	}
	printf("%d ",root -> data);
	Preorder(root -> left);
	Preorder(root -> right);
}
//Inorder function
void Inorder(struct node *root)
{
	if(root == NULL)
	{
		return;
	}
	Inorder(root -> left);
	printf("%d ",root -> data);
	Inorder(root -> right);
	
}
//Postorder function
void Postorder(struct node *root)
{
	if(root == NULL)
	{
		return;
	}
	Postorder(root -> left);
	Postorder(root -> right);
	printf("%d ",root -> data);
}
//Main function
void main()
{
	struct node *root;
	root = NULL;
	root = Create();
	printf("\nPre-order is:");
	Preorder(root);
	printf("\nInorder is:");
	Inorder(root);
	printf("\nPostorder is:");
	Postorder(root);
}
