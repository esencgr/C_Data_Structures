#include <stdio.h>
#include <stdlib.h>

typedef struct n{
      int x;
      struct n *next;
}node;

void show (node *r){
    while (r != NULL){
        printf("\n%d", r -> x);
        r = r -> next; 
    }
} 

void add_end (node *r, int size){
    for (int i = 1; i <= size; i++){
        while (r -> next != NULL)
            r = r -> next;     
        r -> next = (node*) malloc(sizeof(node));
        r -> next -> x = i*3;
        r -> next -> next = NULL;
    }
}

int main(){
    node *root = NULL;
    root = (node*) malloc(sizeof(node));     
    root -> x = 100;
    root -> next = NULL;

    int adds;
    printf ("\nnumber of added elements : ");
    scanf ("%d", &adds);

    add_end (root, adds);
    show (root);

    printf("\n");
    return 0;
}
