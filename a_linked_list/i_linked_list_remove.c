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

list *remove_ind (list *head, int indice){
    list *temp = get_node();
    list *iter = get_node();
    iter = head;

    if (indice == 0){
        temp = iter;
        iter = iter -> next;
        free(temp);
        return iter;
    }

    else{
        for (int i = 1; i < indice; i++)
            iter = iter -> next;
        
        temp = iter -> next;
        iter -> next = iter -> next -> next;
        free(temp);

        return head;
    }
}

int main (){       
    list *lst = NULL;

    lst = add_to_end (lst, 10);
    lst = add_to_end (lst, 20);
    lst = add_to_end (lst, 30);
    lst = add_to_end (lst, 40);
    lst = add_to_end (lst, 50);

    show (lst);
    lst = remove_ind (lst, 0);
    show(lst);
    lst = remove_ind (lst, 1);
    show(lst);
    lst = remove_ind (lst, 2);
    show (lst);
    
    printf("\n");
    return 0;
}



