#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *prev;
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
        r -> prev = NULL; 
        r -> data = d;
        r -> next = NULL;
        return r;
    }

    else {
        list *temp = get_node();
        list *iter = get_node();   // if new data greater than before data --> add last 
        iter = r;
       
        if (r -> data > d){       // if new data smaller than current --> add frst
            temp -> prev = NULL;
            temp -> data = d;
            temp -> next = r;
            r -> prev = temp; 
            r = temp;
            return r;
        }

        else {
            while (iter -> next != NULL && iter -> next -> data < d)
                iter = iter -> next;

            temp -> prev = iter;
            temp -> data = d;
            temp -> next = iter -> next;
            iter -> next = temp;

            if (iter -> next != NULL)
                iter -> next -> prev = iter;
            
            return r;   
        }
    } 
}

list *remove_element (list *r, int d){
    list *temp = get_node();
    
    if (r -> data == d){
        temp = r;
        r = r -> next;
        free (temp);
        r -> prev = NULL;
        return r;
    }

    else{
        list *iter = get_node();
        iter = r;

        while (iter -> next != NULL && iter -> next -> data != d)
            iter = iter -> next; 

        if (iter -> next == NULL){
            printf ("\ndata not found..");
            return r;
        }
        
        temp = iter -> next;
        iter -> next = iter -> next -> next;
        free(temp);
        
        if (iter -> next != NULL)
            iter -> next -> prev = iter;

        return r;
    }
}
void show (list *r){
    printf("\n");
    while (r != NULL){
        printf ("%d ", r -> data);
        r = r -> next;
    }
}

int main(){       
    list *root = NULL;

    root = sequantial(root, 4);
    root = sequantial(root, 2);
    root = sequantial(root, 5);
    root = sequantial(root, 3);
    root = sequantial(root, 1);

    root = remove_element(root, 1);
    root = remove_element(root, 3);

    root = remove_element(root, 5);


    show (root);
    
    printf("\n"); 
    return 0;
}

