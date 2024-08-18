// Binary search tree (using iterative approach)
// Operations insert,inorder,search
#include<stdio.h>
#include<stdlib.h>

// Defining the node structure
struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
} *root = NULL;

// Function to create a newnode
struct node *CreateNode(int key)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->lchild = newnode->rchild = NULL;
    return newnode;
}

// Insert function
void Insert(int key)
{
    // t is for indicating root node
    // r follows the t node
    // p is for creating new node
    struct node *t=root;
    struct node *r=NULL,*p;
    
    // If tree is empty
    if (root == NULL)
    {
        root = CreateNode(key);
        return;
    }
    
    // Traverse the tree to find the right position for the new node
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        // This else is executed when the key == t->data
        else
            return;
    }
    
    // Insert the new node as a child of the leaf node
    p = CreateNode(key);
    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

// Inorder traversal function
void Inorder(struct node *p)
{
    if (p)
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

// Main function
int main()
{
    // temp used for storing return node of Search function
    struct node *temp;
    Insert(50);
    Insert(30);
    Insert(20);
    Insert(40);
    Insert(70);
    Insert(60);
    Insert(80);

    printf("Inorder traversal: ");
    Inorder(root);
    
    temp = Search(40);
    if (temp != NULL)
        printf("\nElement %d found", temp->data);
    else
        printf("\nElement not found");
        
    return 0;
}
