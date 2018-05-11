#include <iostream>
typedef struct nodee{
   int data;
   struct nodee * next;
}node;

/* function to create a new node and insert that data at that node */
node * newNode(int data)
{
  node* Node = new(node);
  Node->data = data;
  Node->next = nullptr;
  return Node;
}

node* insert(node* head, int val)
{
  node * nptr = newNode(val);
  if (head == nullptr)return nptr;
  node *temp = head;
  while(head->next != nullptr)
    head = head->next;
  head->next = nptr;
  return temp;
}

void printLinkList(node* head)
{
  while(head != nullptr)
  {
    std::cout<<head->data<<" ";
    head = head->next;
  }
  std::cout<<"\n";
}
/* Merge Routine to merge two sorted linked list */
node* MERGE_ROUTINE(node* head1, node* head2)
{
  if (head1 == nullptr) return head2;
  if (head2 == nullptr) return head1;
  node * merge_head;
  node *merge_tail;
  if (head1->data < head2->data)
  {
    merge_head = head1;
    head1 = head1->next;
  }
  else
  {
    merge_head = head2;
    head2 = head2->next;
  }

  merge_tail = merge_head;


  while(head1 != nullptr && head2 != nullptr)
  {
    if (head1->data < head2->data)
    {
      merge_tail->next = head1;
      merge_tail = head1;
      head1 = head1->next;

    }else
    {
      merge_tail->next = head2;
      merge_tail = head2;
      head2 = head2->next;

    }
  }

  if (head1 == nullptr)
  {
    merge_tail->next = head2;
  }else{
    merge_tail->next = head1;
  }
  return merge_head;
}

int * MERGE_ROUTINE_Array(int mergeArray[],int a[],  int b[], int size_a, int size_b)
{
  int * p1 = a;
  int * p2 = b;
  int * m= mergeArray;
  if (size_a == 0)
  {
    for(int i = 0; i< size_b; ++i)
      *m++ = *b++;
    return mergeArray;
  }
  if(size_b == 0)
  {
    for(int i = 0; i< size_a; ++i)
      *m++ = *a++;
    return mergeArray;
  }
  while((p1-a) != size_a &&  (p2-b) != size_b)
  {
    if (*p1 < *p2)
      *m++ = *p1++;
    else
      *m++ = *p2++;
  }
  if ((p1-a) == size_a)
  {
    while((p2-b) < size_b)
      *m++ = *p2++;
  }else
  {
    while((p1-a) < size_a)
      *m++ = *p1++;
  }
  return mergeArray;

}

void PrintArray(int array[], int sz)
{
  for(int i =0 ;i < sz; ++i)
    std::cout<<array[i]<<" ";
  std::cout<<"\n";
}
int main()
{

  int a[] = {4,8,15,19,22};
  int b[] = {7,9,10,16};
  int mergeArray[9];
  node *head1 = nullptr;
  node *head2 = nullptr;
  for(int i =0; i<5; ++i)
    head1 = insert(head1,a[i]);

  for(int i =0; i<4; ++i)
   head2 = insert(head2,b[i]);

   printLinkList(head1);
   printLinkList(head2);
   printLinkList(MERGE_ROUTINE(head2,head1));
   PrintArray(b,4);
   std::cout<<"\nMergeArray"<<"\n";
   PrintArray(MERGE_ROUTINE_Array(mergeArray,a,b,5,4),9);
   return 0;
}
