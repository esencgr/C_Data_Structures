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
    }while (iter -> next != r);
} 

node *create_v1 (node *r, int data){
    if (r == NULL){
        r = (node*) malloc(sizeof(node));
        r -> x = data;   
        r -> next = r;
        return;
    }
    node *iter = r;
    iter -> next = NULL;
    iter -> next = (node*) malloc(sizeof(node));
    iter -> next -> x = data;
    iter -> next -> next = r;

}

int main(){
    node *root = NULL;

    create_v1 (root, 2);    
    create_v1 (root, 1);    

    printf("\n");
    return 0;
}
