#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int data;
    struct n * next; 
}node;

node *r = NULL;

node *get_node (){
    node *r = (node*) malloc (sizeof(node));
    return r;
}

void enque (int d){

    node *last;
    if (r == NULL){
        r = get_node ();
        r -> data = d;
        r -> next = NULL;
        last = r;
    }

    else{
        last -> next = get_node();
        last -> next -> data = d;
        last = last -> next;
        last -> next = NULL;
    }

}

int deque (){

    if (r == NULL){
        printf ("\nlinked list empty.\n");
        return -1;          
    }

    int rval = r -> data;
    node *temp = r;
    r = r -> next;
    free (temp);
    return rval;

}

void show (node * r){

    printf ("\n");
    printf ("list -> ");
    while (r != NULL){
        printf ("%d ", r -> data);
        r = r -> next;
    }
    printf ("\n");

}


int main (){

    int val;
    for (int i = 1; i < 5; i++){
        enque (i*2);
    }
    show (r);
    
    for (int i = 1; i < 3; i++){
        val = deque ();
        printf ("%d ", val);
    }
    return 0;

}

