// AVL Trees
// Operations -- NodeHeight,
                 BalanceFactor,
                 Insert,
                 Main  
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
     int hl,hr;
     hl = p && p->lchild ? p->lchild->height : 0;
     hr = p && p->rchild ? p->rchild->height : 0;
     return hl > hr ? hl+1 : hr+1;
}

// BalanceFactor function
int BalanceFactor(struct node *p)
{
    int hl,hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl-hr;
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
   t->data = key;
   // if one node is added then height of that node is 0 
   t->height = 0;
   t->lchild = t->rchild = NULL;
   return t;
}
	
if(key < p->data)
   p->lchild = Insert(p->lchild,key);
	
else if(key > p->data)
   p->rchild = Insert(p->rchild,key);
	
p->height = NodeHeight(p); 
// Now we have to perform the rotations.
// To perform rotations we have to check the balance factor
// After updating the height we have to know the balance factor
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
    return 0;
}
