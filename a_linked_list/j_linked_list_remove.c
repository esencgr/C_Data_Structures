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

list *add_to_end (list *head, int d){
    if (head == NULL){
        head = get_node();
        head -> data = d;
        head -> next = NULL;
        return head;
    }
    
    list *temp = get_node ();
    temp -> data = d;
    temp -> next = NULL;
    
    list *iter = get_node();
    iter = head;

    while (iter -> next != NULL)
        iter  = iter -> next;
    
    iter -> next = temp;
    return head;
}

void show (list *r){
    printf("\n");
    while (r != NULL){
        printf ("%d ", r -> data);
        r = r -> next;
    }
}

list *remove_element (list *head, int d){
    list *temp = get_node();
    
    if (head -> data == d){
        temp = head;
        head = head -> next;
        free (temp);
        return head;
    }
    
    list *iter = get_node();
    iter = head;

    // if (iter -> data == d){
    //     temp = iter;
    //     iter = iter -> next;
    //     head = iter;
    //     free (temp);
    //     return head;
    // }

    while (iter -> next != NULL && iter -> next -> data != d)
        iter = iter -> next; 

    if (iter -> next == NULL){
        printf ("\ndata not found..");
        return head;
    }
    
    temp = iter -> next;
    iter -> next = iter -> next -> next;
    free(temp);

    return head;
}

int main (){       
    list *lst = NULL;
    lst = add_to_end (lst, 10);
    lst = add_to_end (lst, 20);
    lst = add_to_end (lst, 30);
    show (lst);
    
    lst = remove_element (lst, 99);
    show(lst);
    lst = remove_element (lst, 30);
    show (lst);

    // list *lst1 = (list*) malloc (sizeof(list*));
    // lst1 = remove_element (lst, 10);
    // show (lst1);
    // lst1 = remove_element (lst, 10);

    // list *lst2 = (list*) malloc (sizeof(list*));
    // lst2 = remove_element (lst, 20);
    // show (lst2);

    printf("\n");
    return 0;
}



