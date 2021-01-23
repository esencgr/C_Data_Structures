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
    int size;
    iter = root;
    for (int i = 0; i < 3; i++){
        iter -> x = i * 2;
        iter -> next = NULL;
        iter -> next = (node*) malloc(sizeof(node));
        iter = iter -> next; 
    }
    
    iter = root;
    show(iter);
    
    // while (iter -> next != NULL){
    //     printf("\n%d", iter -> x);
    //     iter = iter -> next; 
    // } 

    // for (int i = 0; iter -> next != NULL ; i++){
    //     printf("\n%d", iter -> x);
    //     iter = iter -> next; 
    // }
    
    printf("\n");
    return 0;
}
