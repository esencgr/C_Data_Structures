#include <stdio.h>
#include <stdlib.h>

typedef struct n{
      int data;
      struct n *next;
}list;

void show (list *r){
    list *iter = r;
    do{
        printf("\n%d", iter -> data);
        iter = iter -> next;
    }while (iter != r);
} 

list *get_node (){
    list *node = (list*) malloc(sizeof(list));
    return node;
}




// list *remove_ind (list *r, int indice){
//     list *temp = get_list();
//     list *iter = get_list();
//     iter = r;

//     if (indice == 0){
//         temp = iter;
//         iter = iter -> next;
//         free(temp);
//         return iter;
//     }

//     else{
//         for (int i = 1; i < indice; i++)
//             iter = iter -> next;
        
//         temp = iter -> next;
//         iter -> next = iter -> next -> next;
//         free(temp);

//         return r;
//     }
// }


list *sequantial (list *r, int d){
    if (r == NULL){           // if root is empty --> add first
        r = get_node();
        r -> data = d;
        r -> next = r;
        return r;
    }

    list *temp = get_node();
    list *iter = get_node();   // if new data greater than before data --> add last 
    iter = r;

    if (r -> data > d){       // if new data smaller than current --> add frst
        temp -> data = d;
        temp -> next = r;

        while (iter -> next != r)
            iter = iter -> next;

        iter -> next = temp;
        r = temp;
        return r;
    }

    while (iter -> next != r && iter -> next -> data < d)
        iter = iter -> next;
    
    temp -> data = d;
    temp -> next = iter -> next;
    iter -> next = temp;
    return r; 
}

list *remove_element (list *r, int d){
    list *temp = get_node();
    list *iter = get_node();
    iter = r;

    if (r -> data == d){

        while (iter -> next != r)
            iter = iter -> next;
        
        iter -> next = r -> next;
        free (r);
        r = iter -> next;

        return r;
    }
    
    else {

        while (iter -> next != r && iter -> next -> data != d)
            iter = iter -> next; 

        if (iter -> next == r){
            printf ("\ndata not found..");
            return 0;
        }
        
        temp = iter -> next;
        iter -> next = iter -> next -> next;
        free(temp);

        return r;
    }
}

int main(){
    list *root = NULL;

    root = sequantial (root, 1);    
    root = sequantial (root, 0);  
    root = sequantial (root, 2);  
    root = sequantial (root, 3);  
    
    root = remove_element (root, 1);  
    root = remove_element (root, 3);  

    show (root);

    printf("\n");
    return 0;
}
