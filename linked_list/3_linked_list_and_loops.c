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

int main(){

    node *root = NULL;
    root = (node*) malloc(sizeof(node));          // node *root = [ x ][ next ] --> [][]

    node *iter = NULL;    
    iter = root;
    
    for (int i = 0; i < 5; i++){
        iter -> x = i * 2;
        iter -> next = NULL;
        iter -> next = (node*) malloc(sizeof(node));
        iter = iter -> next; 
    }
    
    iter = root;
    show(iter);

    printf("\n");
    return 0;
}
