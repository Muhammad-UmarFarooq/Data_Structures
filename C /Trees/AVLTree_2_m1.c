// AVL Trees
/* Operations -- NodeHeight,
                 BalanceFactor,
                 LLrotation,
                 RRrotation,
                 LRrotation,
                 RLrotation,
                 Insert,
		 Inorder,
                 Preorder,   
                 Main
*/
#include<stdio.h>
#include<stdlib.h>
// Node structure
struct node 
{
    struct node *lchild;
    int data;
    int height;
    struct node *rchild;
}*root = NULL;

// NodeHeight function
int NodeHeight(struct node *p)
{
     if (p == NULL)
        return 0;
     int hl,hr;
     hl =p->lchild ? p->lchild->height :0;
     hr =p->rchild ? p->rchild->height :0;
     return (hl>hr?hl:hr)+1;
}

// BalanceFactor function
int BalanceFactor(struct node *p)
{
    if (p == NULL)
        return 0;
    int hl,hr;
    hl =p->lchild?p->lchild->height:0;
    hr =p->rchild?p->rchild->height:0;
    return hl - hr;
}

// Right rotation
struct node *LLRotation(struct node *p)
{
    struct node *pl=p->lchild;
    struct node *plr=pl->rchild;
    
    pl->rchild = p;
    p->lchild = plr;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    
    return pl;
}

// Left rotation
struct node *RRRotation(struct node *p)
{
    struct node *pr=p->rchild;
    struct node *prl=pr->lchild;
    
    pr->lchild = p;
    p->rchild = prl;
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    
    return pr;
}

// Left-Right rotation
struct node *LRRotation(struct node *p)
{
    p->lchild = RRRotation(p->lchild);
    return LLRotation(p);
}


// Right-Left rotation
struct node *RLRotation(struct node *p)
{
    p->rchild = LLRotation(p->rchild);
    return RRRotation(p);
}
 
//Insert function
struct node *Insert(struct node *p,int key)
{
// p indicates root
// t used for creating the new node
struct node *t=NULL;

if(p==NULL)
{
   t=(struct node *)malloc(sizeof(struct node));
   if (t == NULL) 
    {
       printf("Memory allocation failed");
       exit(1);
    }
   t->data = key;
   t->lchild = t->rchild = NULL;
   // if one node is added then height of that node is 1
   t->height = 1;
   return t;
}
// Recursive case: Insert key in the correct subtree	
if(key < p->data)
   p->lchild = Insert(p->lchild,key);
	
else if(key > p->data)
   p->rchild = Insert(p->rchild,key);
	
// Update the height of the current node
p->height = NodeHeight(p); 
	
// Check balance and apply rotations if needed
if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
  return LLRotation(p);
else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
   return LRRotation(p);
else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
   return RRRotation(p);
else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
   return RLRotation(p);
return p;
}


//Inorder function
void Inorder(struct node *root)
{
	if(root == NULL)
	{
		return;
	}
	Inorder(root -> lchild);
	printf("%d ",root -> data);
	Inorder(root -> rchild);
	
}

//Preorder function
void Preorder(struct node *root)// The argument can be given any variable name 
{
	if(root == 0)
	{
		return;
	}
	printf("%d ",root -> data);
	Preorder(root -> lchild);
	Preorder(root -> rchild);
}

// MinValueNode function
struct node *minNode(struct node *node)
{
    struct node *current = node;
    while(current->lchild != NULL)
      current = current->lchild;
    return current;
}

//Delete function
// --STEP 1: PERFORM STANDARD BST DELETE
struct node *Delete(struct node *p,int data)
{
    //Find the node and delete it
    if(p == NULL)
      return p;
    if(data < p->data)
      p->lchild = Delete(p->lchild,data);
    else if(data > p->data)
      p->rchild = Delete(p->rchild,data);
    //else refers if data == p->data
    else
    {
        //if both child keys are NULL or atleast one key is present 
        if(p->lchild == NULL || p->rchild == NULL)
        {
            // assigning that one key to temp
            struct node *temp = p->lchild ? p->lchild : p->rchild;
            // if no child keys
            if(temp == NULL)
            {
               temp = p;
               p = NULL;
            }
            // if one child key
            else
            {
              *p = *temp;
            }
          free(temp);
        }
        // if both child keys are present
        else
        {
            // we can take minnode from right subtree or maxnode from left subtree
           struct node *temp = minNode(p->rchild);
           p->data = temp->data;
           p->rchild = Delete(p->rchild,temp->data);
        }
    }
    // If the tree had only one node then return
    if(p == NULL)
      return p;
    // --STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    p->height = NodeHeight(p);
    // --STEP 3: update the balance factor of each node and balance the tree
    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
      return LLRotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
      return LRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
      return RRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
      return RLRotation(p);
    
    return p;
}

// Main function
int main()
{
    /*
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 30);
    root = Insert(root, 40);
    root = Insert(root, 50);
    root = Insert(root, 25);
    */

    root = Insert(root,50);
    root = Insert(root,40);
    root = Insert(root,30);
    root = Insert(root,20);
    root = Insert(root,10);
    root = Insert(root,25);
    printf("\nInorder traversal is:");
    Inorder(root);
    printf("\nPreorder traversal is:");
    Preorder(root);
    root = Delete(root,50);
    printf("\n50 is deleted");
    // root = Delete(root,10);
    // root = Delete(root,50);
    // root = Delete(root,30);
    // root = Delete(root,20);
    // root = Delete(root,40);
    printf("\nInorder traversal is:");
    Inorder(root);
    printf("\nPreorder traversal is:");
    Preorder(root);
    return 0;
}
