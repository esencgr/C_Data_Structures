#include <stdio.h>
#include <stdlib.h>

typedef struct n{
      int x;
      struct n *next;
}node;

int main(){

    node *root = NULL;
    root = (node*) malloc(sizeof(node));          // node *root = [ x ][ next ] --> [][]

    node *iter = NULL;
    int size, data;
     
    iter = root;
    iter -> x = 10;
    iter -> next = NULL;

    printf("enter list size :");
    scanf("%d", &size);

    for (int i = 0; i < size; i++){
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
