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

list *sequantial (list *r, int d){

    // if root is empty --> add head
    if (r == NULL){          
        r = get_node();
        r -> data = d;
        r -> next = r;
        return r;
    }
    
    // if root is not empty --> add before or after
    else{
        list *temp = get_node();
        list *iter = get_node();   
        iter = r;
        
        // if new data smaller than current --> add before      
        if (r -> data > d){       
            while (iter -> next != r)
                iter = iter -> next;

            temp -> data = d;
            temp -> next = r;
            iter -> next = temp;
            r = temp;
            return r;
        }
        
        // if new data greater than cureent data --> add after 
        else{
            while (iter -> next != r && iter -> next -> data < d)
                iter = iter -> next;
            
            temp -> data = d;
            temp -> next = iter -> next;
            iter -> next = temp;
            return r;
        } 
    }
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

    root = sequantial (root, 2);    
    root = sequantial (root, 1);  
    root = sequantial (root, 5);  
    root = sequantial (root, 3);  
    // root = sequantial (root, 4);  

    
    printf("\nlist added");
    show (root);
    printf("\n");

    root = remove_element (root, 1);  
    root = remove_element (root, 3);
    root = remove_element (root, 5);


    printf("\nlist updated");
    show (root);
    printf("\n");

    return 0;
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

