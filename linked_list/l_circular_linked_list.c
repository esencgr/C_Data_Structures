#include <stdio.h>
#include <stdlib.h>

typedef struct n{
      int x;
      struct n *next;
}node;

void show (node *r){
    node *iter = r;
    do{
        printf("\n%d", iter -> x);
        iter = iter -> next;
    }while (iter != r);
} 

node *create (node *r, int data){
    if (r == NULL){
        r = (node*) malloc(sizeof(node));
        r -> x = data;   
        r -> next = r;
        return r;
    }
    else{
        node *iter = r;
        while ( iter -> next != r )
            iter = iter -> next;
            
        iter -> next = (node*) malloc(sizeof(node));
        iter -> next -> x = data;
        iter -> next -> next = r;
        return r;
    }
}

int main(){
    node *root = NULL;

    root = create (root, 1);    
    root = create (root, 3);   
    root = create (root, 2);   
    root = create (root, 4);   
    root = create (root, 6);   
    root = create (root, 5);   
    root = create (root, 7); 

    show (root);

    printf("\n");
    return 0;
}
