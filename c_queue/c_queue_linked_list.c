#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int data;
    struct n * next; 
}node;
typede
node *get_node (){
    node *r = (node*) malloc (sizeof(node));
    return r;
}

node *enque (node *r, int d){

    if (r == NULL){
        r = get_node (r);
        r -> data = d;
        r -> next = NULL;
        return r;          
    }

    else{
        node *iter = r;
        while (iter -> next !=  NULL)
            iter = iter -> next;
        
        node *temp = get_node();
        iter -> next = temp;
        temp -> data = d;
        temp -> next = NULL;
        return r;
    }

}

node *deque (node *r){

    if (r == NULL){
        printf ("\nlinked list empty.\n");
        return 0;          
    }
    
    int rval = r -> data;
    node *temp = r;
    r = r -> next;
    free (temp);
    return r;

}

void show (node *r){

    printf ("\n");
    printf ("list -> ");
    while (r != NULL){
        printf ("%d ", r -> data);
        r = r -> next;
    }
    printf ("\n");
    
}

int main (){

    node *root = NULL;
    int val;
    
    for (int i = 0; i < 5; i++)
        root = enque (root, i*2);

    show (root);
    
    
    for (int i = 0; i < 3; i++)
        root = deque (root);
    
    show (root);
    
    return 0;

}
