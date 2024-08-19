// Recursive BST
/* Operations -- Insert,
		 Inorder,
	         Search,
		 Height,
	         Inorder predecessor,
		 Inorder successor,
		 Delete
*/
#include<stdio.h>
#include<stdlib.h>

// Defining the node structure
struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
} *root = NULL;

// Insert function
struct node *Insert(struct node *p,int key)
{
// p indicates root
// t used for creating the new node
struct node *t=NULL;

if(p==NULL)
{
   t=(struct node *)malloc(sizeof(struct node));
   t->data=key;
   t->lchild=t->rchild=NULL;
   return t;
}
	
if(key < p->data)
   p->lchild = Insert(p->lchild,key);
	
else if(key > p->data)
   p->rchild = Insert(p->rchild,key);
	
return p;
}

// Inorder traversal function
void Inorder(struct node *p)
{
    if (p)
    // if(p) (or) if(p != NULL)
    {
        // p indicates the root node
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

// Search function
struct node* Search(int key)
{
    // Again t indicates root node
    struct node *t = root;
    while (t != NULL) 
    {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    // If t is NULL then this return function will return NULL
    return NULL;
}

// Height function
int Height(struct node *p)
{
    int x,y;
    if(p == NULL)
    return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x>y?x+1:y+1;
}

// Inorder predecessor function
struct node *InPre(struct node *p)
{
    while(p && p->rchild != NULL)
       p = p->rchild;
    return p;
}

// Inorder successor function
struct node *InSucc (struct node *p)
{
    while(p && p->lchild != NULL)
       p = p->lchild;
    return p;
}

// Delete function
struct node *Delete(struct node *p,int key)
{
    // Here p pionts to root
    // q pointer stores the address returned by the InPre function
    struct node *q;
	// If the tree is empty below if condition
	if(p == NULL)
	    return NULL;
	// If it is leaf node	     	
    if(p->lchild == NULL && p->rchild == NULL)
    	{
    	    if(p == root)
    		    root = NULL;
    	    free(p);
    	    return NULL;
		}
    // If key is less than root   
	if (key < p->data)
        p->lchild = Delete(p->lchild, key);
    // If key is greater than root
    else if (key > p->data)
        p->rchild = Delete(p->rchild, key);
    // This else is executed when the key == p->data for deleting that particular node
    else
    {
      // Based on height we will decide whether to read
	  // (the predecessor or successor)
	  // from the left side or right side
	  if(Height(p->lchild)>Height(p->rchild))
	    {
	       q=InPre(p->lchild);
	       p->data = q->data;
	       p->lchild = Delete(p->lchild,q->data);
	    }
	  else
	    {
	       q = InSucc(p->rchild);
	       p->data = q->data;
	       p->rchild=Delete(p->rchild,q->data);
	    }
    }
    return p;
}
// Main function
int main()
{
    // temp used for storing return node of Search function
    struct node *temp;
    root = Insert(root,50);
    Insert(root,30);
    Insert(root,20);
    Insert(root,40);
    Insert(root,70);
    Insert(root,60);
    Insert(root,80);

    printf("\nInorder traversal: ");
    Inorder(root);
    
    Delete(root,84);
    
    printf("\nInorder traversal: ");
    Inorder(root);
    
    temp = Search(40);
    if (temp != NULL)
        printf("\nElement %d found", temp->data);
    else
        printf("\nElement not found");
        
    return 0;
}			
