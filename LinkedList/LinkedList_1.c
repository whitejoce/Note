#include <stdio.h>
#include <malloc.h>

#define N 5
 
struct node {
    int d;
    struct node *next;
};

int main(void)
  {
    int i;
    struct node *p,*end,*head;
    
    end=malloc(sizeof(struct node));
    end->next=NULL;
    head=end;
    
    printf("Number of nodes: %d\n",N);

    for (i=0;i<N;i++)
      {
        p=malloc(sizeof(struct node));
        scanf("%d", &p->d);
        p->next=NULL;
        end->next=p;
        end=p;
      }

    for (p=head->next;p!=NULL;p=p->next)
      {
        printf("%d ",p->d);
      }
    
    return 0;
    
  }
