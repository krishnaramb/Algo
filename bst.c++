#include <iostream>
#include  <algorithm>

struct node {
  int data;
  struct node * left;
  struct node * right;
};

enum condition {falsee, truee} ;
/* Given a binary tree, return true if a node with the targent data is found*/

static int lookup(struct node* node, int target)
{
  if(node == NULL)
    return falsee;
  else
  {
    if (target == node->data)
      return truee;
    else {
      if (target < node->data)
         return lookup(node->left, target);
      else{
         return lookup(node->right,target);
      }

    }
  }
}

/* function to create a new node and insert that data at that node */
struct node *newNode(int data)
{
  struct node*  Node = new(struct node);
  Node->data = data;
  Node->left = NULL;
  Node->right = NULL;
  return Node;
}

struct node * insert(struct node* Node, int data)
{
  if (Node == NULL)
  {
    struct node * mynode = newNode(data);
    return mynode;

  }

  if(data < Node->data)
  {
    struct node* pnode =  insert(Node->left, data);
    Node->left = pnode;
  }
  else
  {
    struct node* pnode =  insert(Node->right, data);
    Node->right = pnode;
  }
  return Node;
}

struct node * build123version1()
{
  struct node * ptr1 = newNode(1);
  struct node * ptr2 = newNode(2);
  struct node * ptr3 = newNode(3);
  ptr2->left = ptr1;
  ptr2->right = ptr3;
  return ptr2;
}

struct node * build123version2()
{
  struct node * ptr = newNode(2);
  ptr->left = newNode(1);
  ptr->right = newNode(3);
  return ptr;
}

struct node * build123version3()
{
  struct node * root = insert(NULL,2);
  insert(root, 1);
  insert(root, 3);
  return root;
}

/* simple binary tree traversal*/
int size(struct node * node)
{
  if (node == NULL) return 0;
  else
  {
    return (1+size(node->left) + size(node->right));
  }
}
/*max depth*/
int maxDepth(struct node *node)
{
  if(node == NULL) return 0;
  else{
    return (1 + std::max(maxDepth(node->left),maxDepth(node->right)));
  }
}

/*minval 1. assume a non-emmpty tree 2. assume it could be emply as well*/
/*further improvement; use exceptional handling*/
int minValue(struct node* node)
{
  if (node->left == NULL) return node->data;
  else{
    return(minValue(node->left));
  }
}


/*inorder traversal of the tree */
void printTree(struct node *node)
{
  if (node->left == NULL) std::cout<<node->data<<"-";
  else{
    printTree(node->left);
    std::cout<<node->data<<"-";
  }
  if(node->right != NULL)
  {
    printTree(node->right);
  }
}

/*postorder traversal */
/*both subtrees of a node are printed out completely before the node itself is printed*/
void printPostoder(struct node* node)
{
  if(node->left != NULL)
    printPostoder(node->left);
  if(node->right != NULL)
    printPostoder(node->right);
  std::cout<<node->data;
}

int hasPathSum(struct node * node,int sum)
{
  if (node == NULL) return (sum == 0);
  else{
    sum = sum -node->data;
    return (hasPathSum(node->left,sum) || hasPathSum(node->right,sum));
  }
}

void mirror(struct node* node) {
  if (node == NULL) return;
  else{
    struct node * tmp = node->left;
    node->left = node->right;
    node->right = tmp;
  }
  mirror(node->left);
  mirror(node->right);
}

int sameTree(struct node *a, struct node *b)
{
  if (a == NULL && b == NULL) return truee;
  else if((a == NULL && b != NULL) || (a != NULL && b ==NULL) ){
    return falsee;
  }
  else{
    if (a->data != b->data) return falsee;
    else
      return (sameTree(a->left,b->left) && sameTree(a->right,b->right));
  }

}

int isBSTRecur(struct node * node, int min, int max)
{
  if (node == NULL) return truee;
  if (node->data > min || node->data <= max) return falsee;
  return (isBSTRecur(node->left,min,node->data) && isBSTRecur(node->right,node->data,max));
}





int isBST(struct node * node)
{
  int min = INT_MIN;
  int max = INT_MAX;
  return isBSTRecur(node, min, max);
}
int main()
{
//  struct node * ptr = build123version3();
struct node * ptr = insert(NULL, 20);
insert(ptr, 50);
insert(ptr,200);
insert(ptr,75);
insert(ptr,300);
insert(ptr,25);
  printTree(ptr);
  std::cout<<"\n";
  printPostoder(ptr);
 std::cout<<"\n"<<hasPathSum(ptr,6);
 mirror(ptr);
 std::cout<<"\n";
 printTree(ptr);

}
