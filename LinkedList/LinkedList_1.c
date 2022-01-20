#include <stdio.h>
#include <stdlib.h>

#define N 5

struct node
  {
    int data;
    struct node *next;
  };

int main(void)
  {
    int i;
    struct node *temp,*head,*p;
    
    temp=malloc(sizeof(struct node));
    temp->next=NULL;
    head=temp;
    
    printf("Number of nodes: %d\n",N);

    for (i=0;i<N;i++)
      {
        p=malloc(sizeof(struct node));
        scanf("%d", &p->data);
        temp->next=p;
        temp=p;
      }
    p->next=NULL;

    for (p=head->next;p!=NULL;p=p->next)
      {
        printf("%d ",p->data);
      }

    return 0;
  }
