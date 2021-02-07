#include <stdio.h>
#include <stdlib.h>

typedef struct n{
      int x;
      struct n *next;
}node;

int main(){

    node *root = NULL;
    root = (node*) malloc(sizeof(node));          // node *root = [ x ][ next ] --> [][]
    
    root -> x = 10;
    root -> next = NULL;

    root -> next = (node*) malloc(sizeof(node));
    root -> next -> x = 20;
    root -> next -> next = NULL;

    node * iter;
    iter = root -> next;
    for (int i = 0; i < 5; i++){
        iter -> next = (node*) malloc(sizeof(node));
        iter = iter -> next; 
        iter -> x = i * 2;
        iter -> next = NULL;
    }
    
    iter = root;
    for (int i = 0; iter != NULL ; i++){
        printf("\n%d", iter -> x);
        iter = iter -> next; 
    }
    
    printf("\n");
    return 0;
}
