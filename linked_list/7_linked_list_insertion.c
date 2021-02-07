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

list *insert (list *head, int indice, int d){
    list *temp = get_node();
    if (indice == 0){
       temp -> data = d;
       temp -> next = head;
       head = temp;
       return head;
    }

    list *iter = get_node();
    iter = head;
    
    for (int i = 1; i <= indice; i++)
        iter = iter -> next;

    // while (indice--)
    //     iter = iter -> next;

    temp -> data = d;
    temp -> next = iter -> next;
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

int main (){       
    list *lst = NULL;

    lst = add_to_end (lst, 10);
    lst = add_to_end (lst, 20);
    lst = add_to_end (lst, 30);
    lst = add_to_end (lst, 40);
    
    lst = insert (lst, 0, 100);  // add 100 head 0 and 1 
    lst = insert (lst, 1, 200);  // add 200 between 1 and 2 
    lst = insert (lst, 2, 300);  // add 250 between 2 and 3 
    lst = insert (lst, 6, 800);  // add 300 between 3 and 4

    show (lst);
        
    printf("\n");
    return 0;
}



