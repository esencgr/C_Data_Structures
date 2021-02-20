#include <stdio.h>
#include <stdlib.h>

typedef struct n{
      int x;
      struct n *next;
}node;

void show (node *r){
    while (r -> next != NULL){
        printf("\n%d", r -> x);
        r = r -> next; 
    }
} 

void create (node *r, int size){
    for (int i = 1; i <= size; i++){
        while (r -> next != NULL)
            r = r -> next;     
        r -> x = i*3;
        r -> next = NULL;
        r -> next = (node*) malloc(sizeof(node));
    }
}

int main(){
    node *root = NULL;
    root = (node*) malloc(sizeof(node));     

    create (root, 3);    
    show (root);
    // free (root);
    
    // root = NULL;
    // root = (node*) malloc(sizeof(node));     

    // create (root, 5);    
    // show (root);

    printf("\n");
    return 0;
}
