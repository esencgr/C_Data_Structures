#include <stdio.h>
#include <stdlib.h>

typedef struct n{
      int x;
      struct n *next;
}node;

void show (node *r){
    node *iter = r;
    // printf("\n%d", iter -> x);
    // iter = iter -> next; 
    // while (iter-> next!= r){
    //     printf("\n%d", iter -> x);
    //     iter = iter -> next; 
    // }
    do{
        printf("\n%d", iter -> x);
        iter = iter -> next;
    }while (iter != r);
} 

node *create_v1 (node *r, int data){
    if (r == NULL){
        r = (node*) malloc(sizeof(node));
        r -> x = data;   
        r -> next = r;
        return r;
    }

    node *iter = r;
    while ( iter -> next != r )
        iter = iter -> next;
    iter -> next = NULL;
    iter -> next = (node*) malloc(sizeof(node));
    iter -> next -> x = data;
    iter -> next -> next = r;
    return r;
}

int main(){
    node *root = NULL;

    root = create_v1 (root, 1);    
    root = create_v1 (root, 2);   
    root = create_v1 (root, 3);   
    root = create_v1 (root, 4);   
    root = create_v1 (root, 5);   
    root = create_v1 (root, 6);   
    root = create_v1 (root, 7);   

    // root = create_v1 (root, 2);    


    show (root);

    printf("\n");
    return 0;
}
