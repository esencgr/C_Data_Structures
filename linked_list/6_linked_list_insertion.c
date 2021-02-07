#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void printList(){
     struct node *ptr = head;
          printf("  \n");

     printf("n[head] =>");
     while(ptr != NULL){
          printf(" %d =>",ptr->data);
          ptr = ptr->next;
     }
     printf(" [null]n");
     printf("  \n");
     printf("  \n");
}

struct node *insert(int data){
     struct node *link = (struct node*) malloc(sizeof(struct node));
     link->data = data;
     link->next = head;
     head = link;
     return head;
}
 
int main(){
     struct node *root;
     root = insert(600);
     root = insert(600);
     root = insert(600);
     root = insert(600);
     root = insert(600);

     // insert(500);
     // insert(400);
     // insert(300);
     // insert(200);
     // insert(100);
     
     printList();
     return 0;
}
