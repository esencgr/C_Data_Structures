#include <stdio.h>
#include <stdlib.h>

typedef struct n{
      int x;
      struct n *next;
}node;

int main(){

    node *root = NULL; 
    root = (node*) malloc(sizeof(node));          // node *root = [ x ][ next ] --> [][]
    root -> x = 10;                               // root -> x  = [ x = 10  ][ next ] --> [][]

    root -> next = (node*) malloc(sizeof(node));  // root -> next = [ x = 10 ][ next ] --> [ x ][ next ] --> [][]
    root -> next -> x = 20;                       // root -> next -> x = [ x = 10 ][ next ] --> [ x = 20 ][ next ] --> [][]
    
    root -> next -> next = (node*) malloc(sizeof(node));
    root -> next -> next -> x  = 30;

    node *iter = root;                            
    printf("\n%d", iter -> x);

    iter = iter -> next;
    printf("\n%d", iter -> x);
     
    iter = root;
    for (int i = 0; iter != NULL; i++){
        printf("\n%d", iter -> x);
        iter = iter -> next; 
    }
    printf("\n");
    return 0;
}