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
    // while (iter != r){
    //     printf("\n%d", iter -> x);
    //     iter = iter -> next; 
    // }
    do{
        printf("\n%d", iter -> x);
        iter = iter -> next; 
    } while (iter != r);
    
} 

void add_end_v1 (node *r, int size){
    for (int i = 1; i <= size; i++){
        node *iter = r;
        while (iter -> next != r)
            iter = iter -> next;     

        iter -> next = (node*) malloc(sizeof(node));
        iter -> next -> x = i*3;
        iter -> next -> next = r;
    }
}

void add_end_v2 (node *r, int data){
        node *iter = r;
        while (iter -> next != r)
            iter = iter -> next;    
             
        iter -> next = (node*) malloc(sizeof(node));
        iter -> next -> x = data;
        iter -> next -> next = r;
}

int main(){
    node *root = NULL;
    root = (node*) malloc(sizeof(node));     
    root -> x = 100;
    root -> next = root;
    
    printf("\ncurrent data");
    show (root);
    printf("\n");
    
    printf("\nupdated data");
    add_end_v1 (root, 3);
    show (root);

    printf("\nupdated data");
    add_end_v2 (root, 3);
    show (root);

    printf("\n");
    return 0;
}
