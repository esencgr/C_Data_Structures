#include <stdio.h>
#include <stdlib.h> 

typedef struct n {
    struct n *left;
    int data;
    struct n *right;
}node;

node *get_node(){
    node *t = (node*) malloc (sizeof(node));
    return t;
}

node *insert (node *t, int d){
    if (t == NULL){
        t = get_node ();
        t -> left = NULL;
        t -> data = d;
        t -> right = NULL;
        return t ;
    }
   
    if (t -> data < d){
        t -> right = insert (t -> right, d); 
        return t;
    }

    else {
        t -> left = insert (t -> left, d);
        return t;
    }
}

void travel (node *t){
    if (t == NULL){
        return;
    }

    travel (t -> left);
    printf ("%d ", t -> data );
    travel (t -> right); 
}

int search (node *t, int d){
    if (t == NULL)
        return -1;
    
    if (t -> data == d)
        return 1;
     
    if (search (t->right, d) == 1)
        return 1;
    
    if (search (t -> left, d) == 1)
        return 1;
    
    return -1;   
}

int max (node *t){
    while (t -> right != NULL)
          t = t-> right;
    
    return t -> data;
}

int min (node *t){
    while (t -> left != NULL)
          t = t -> left;
    
    return t -> data;
}

node *delete (node *t, int d){
    if (t == NULL){
        return NULL;
    }

    if (t -> data == d){
        
        if (t -> left == NULL && t -> right == NULL){         // if node has no childs 
            return NULL;
        }

        if (t -> right != NULL){
            t -> data = min (t -> right);
            t -> right = delete (t, min (t -> right));
            return t;
        } 

        t -> data = max (t -> left);
        t -> left = delete (t, max (t -> left));
        return t;
    }

    if (t -> data < d){
            t -> right = delete (t -> right, d);
            return t;
    }
    
    t -> left = delete (t-> left, d);
    return t;
}

int main(){
    node * tree = NULL;

    printf ("\ntree : ");
    tree = insert (tree, 23);
    tree = insert (tree, 12);
    tree = insert (tree, 20);
    tree = insert (tree, 2);
    tree = insert (tree, 1);
    tree = insert (tree, 10);
    travel (tree);
    printf ("\n");
  
    printf ("\ntree : ");
    tree = delete (tree, 1);
    travel (tree);
    printf ("\n");

    printf ("\nsearch state : %d", search(tree, 90));
    printf ("\nmax : %d", max (tree));
    printf ("\nmin : %d", min (tree));
    printf ("\n");

    printf ("\n");
    return 0;
}