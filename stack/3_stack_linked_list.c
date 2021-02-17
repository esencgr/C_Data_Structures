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
    if (r == NULL || r -> data == 0){
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
    if (r == NULL || r -> data == 0 ){
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

void show_pop (int val){
    if (val == 0){
        printf ("not popped\n");
    }
    else{
        printf ("%d popped\n", val);
    }
}

int main (){
    node * stack = NULL;
    int pop_val;

    stack = push (stack, 10);
    stack = push (stack, 20);
    stack = push (stack, 30);
    show (stack);
    
    pop_val = pop(stack);
    show_pop (pop_val);
    show (stack);

    stack = push (stack, 40);
    show (stack);

    pop_val = pop(stack);
    show_pop (pop_val);
    show (stack);    
    
    pop_val = pop(stack);
    show_pop (pop_val);
    show (stack);
    
    pop_val = pop(stack);
    show_pop (pop_val);
    show (stack);

    stack = push (stack, 10);
    stack = push (stack, 20);
    show (stack);

    pop_val = pop(stack);
    show_pop (pop_val);
    show (stack);

    pop_val = pop(stack);
    show_pop (pop_val);
    show (stack);

    pop_val = pop(stack);
    show_pop (pop_val);
    show (stack);

    return 0;
}

