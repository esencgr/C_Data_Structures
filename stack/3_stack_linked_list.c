#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int data;
    struct n * next; 
}node;

node *get_node (){
    node *r = (node*) malloc (sizeof(node));
    return r;
}

node *push (node *r, int d ){
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

int pop (node *r){
    if (r == NULL || r -> data == 0){
        printf ("\nstack empty.\n");
        return 0;          
    }

    if (r -> next == NULL){
        int rval = r -> data;
        r -> data = 0;
        r = NULL;
        free (r);

        return rval;
    }
    
    node *iter = r;
    while (iter -> next -> next !=  NULL)
        iter = iter -> next;
    
    node *temp = iter -> next;
    int rval = temp -> data ;
    iter -> next = NULL;
    free (temp);

    return rval;
}

void show (node * r){
    printf ("\n");
    
    printf ("stack -> ");
    while (r != NULL && r -> data != 0){
        printf ("%d ", r -> data);
        r = r -> next;
    }

    printf ("\n");
}

int main (){
    node * stack = NULL;

    printf ("%d popped\n", pop(stack));
    show (stack);

    stack = push (stack, 10);
    stack = push (stack, 20);
    show (stack);
    
    printf ("%d popped\n", pop(stack));
    show (stack);

    stack = push (stack, 30);
    show (stack);
    
    printf ("%d popped\n", pop(stack));
    show (stack);

    printf ("%d popped\n", pop(stack));
    show (stack);
    printf ("%d popped\n", pop(stack));
    show (stack);

    printf ("%d popped\n", pop(stack));
    show (stack);


    
    return 0;
}

