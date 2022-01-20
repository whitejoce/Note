#include <stdio.h>
#include <malloc.h>

#define N 5
 
struct node
  {
    int data;
    struct node *next;
  };

int main(void)
  {
    int i;
    struct node *new_node,*head,*p;
    
    new_node=malloc(sizeof(struct node));
    new_node->next=NULL;
    head=new_node;
    
    printf("Number of nodes: %d\n",N);

    for (i=0;i<N;i++)
      {
        p=malloc(sizeof(struct node));
        scanf("%d", &p->data);
        p->next=NULL;
        new_node->next=p;
        new_node=p;
      }

    for (p=head->next;p!=NULL;p=p->next)
      {
        printf("%d ",p->data);
      }

    return 0;
  }
