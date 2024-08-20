// AVL Trees
/* Operations -- NodeHeight,
                 BalanceFactor,
                 Insert,
                 Main
*/
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
     hl = p && p->lchild ? p->lchild->height : 1;
     hr = p && p->rchild ? p->rchild->height : 1;
     return hl > hr ? hl+1 : hr+1;
}

// BalanceFactor function
int BalanceFactor(struct node *p)
{
    if(root == NULL)
       return 0;
    int hl,hr;
    hl = p && p->lchild ? p->lchild->height : 1;
    hr = p && p->rchild ? p->rchild->height : 1;
    return hl-hr;
}

// Right rotation
struct node *LLrotation(struct node *p)
{
    struct node *pl=p->lchild;
    struct node *plr=pl->rchild;
    
    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    
    if(root == p)
      root=pl;
      
     return pl;
}

// Left rotation
struct node *RRrotation(struct node *p)
{
    struct node *pr=p->rchild;
    struct node *prl=pr->lchild;
    
    pr->lchild = p;
    p->rchild = prl;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    
    if(root == p)
      root=pr;
      
     return pr;
}

// Left-Right rotation
struct node *LRrotation(struct node *p)
{
    node->lchild = RRrotation(node->lchild);
        return LLrotation(node);
}

// Right-Left rotation
struct node *RLrotation(struct node *p)
{
    node->rchild = LLrotation(node->rchild);
        return RRrotation(node);
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
   // if one node is added then height of that node is 1
   t->height = 1;
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
