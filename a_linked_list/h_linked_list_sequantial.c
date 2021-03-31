#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}list;

list *get_node (){
    list *node = (list*) malloc(sizeof(list));
    return node;
}

list *sequantial (list *r, int d){
    if (r == NULL){           // if root is empty --> add first
        r = get_node();
        r -> data = d;
        r -> next = NULL;
        return r;
    }

    list *temp = get_node();
    if (r -> data > d){       // if new data smaller than current --> add frst
        temp -> data = d;
        temp -> next = r;
        r = temp;
        return r;
    }

    list *iter = get_node();   // if new data greater than before data --> add last 
    iter = r;

    while (iter -> next != NULL && iter -> next -> data < d)
        iter = iter -> next;
    
    temp -> data = d;
    temp -> next = iter -> next;
    iter -> next = temp;
    return r; 
}

void show (list *r){
    printf("\n");
    while (r != NULL){
        printf ("%d ", r -> data);
        r = r -> next;
    }
}

void show_rec (list *r){
    if (r == NULL)
        return;
    printf("%d ", r -> data);
    show_rec (r -> next);
}

int main(){       
    list *root = NULL;

    root = sequantial(root, 4);
    root = sequantial(root, 2);
    root = sequantial(root, 5);
    root = sequantial(root, 3);
    root = sequantial(root, 1);

    show_rec (root);
    printf("\n");

    return 0;
}



