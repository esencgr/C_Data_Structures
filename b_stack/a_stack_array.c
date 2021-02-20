#include <stdio.h>
#include <stdlib.h>

int *array = NULL;
int size = 2;
int top = 0;

void push (int data){

    if (array == NULL){
        array = (int*) malloc (sizeof(int) * 2);
    }

    if (top >= size){
        int *temp = (int*) malloc (sizeof(int) * size * 2);
        
        for (int i = 0; i < top; i++)
            temp[i] = array[i];
        
        free(array);
        array = temp; 
        size *= 2 ;
    }

    array[top++] = data;
    printf ("\nsize of array : %d", size);
}

int pop (void){

    if (top == 0){
        printf ("underflow");
        size = 0;
        return size;
    }

    if (top <= size / 2){
        int *temp = (int*) malloc (sizeof(int) * size / 2);
        
        for (int i = 0; i < top; i++)
            temp[i] = array[i];
        
        free(array);
        array = temp; 
        size /= 2 ;
        printf ("size of array : %d\n", size);

    }
    
    return array[--top];
}


void show (){    
    printf ("\n");

    for (int i = 0; i < top; i++)
        printf ("%d ", array[i]);
    
    printf ("\n");
}

int main (){

    for (int i = 1; i < 4; i++){
        push (i*10);
        show ();
    }

    printf ("\n"); 
    
    for (int i = 1; i < 5; i++){
        printf ("\n%d popped ", pop());
        show ();
    }
  
    return 0;
}