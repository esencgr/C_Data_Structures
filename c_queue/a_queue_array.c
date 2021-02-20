#include <stdio.h>
#include <stdlib.h>

int *array = NULL;
int size = 2;
int body = 0;
int head = 0 ;

void enque (int data){
    
    if (array == NULL){
        array = (int *) malloc (sizeof(int) * size);
    }

    if (body == size){
        int *temp = (int *) malloc (sizeof(int) * size * 2);
        
        for (int i = 0; i < body; i++){
            temp[i] = array[i];
        }

        free (array);
        array = temp;
        size *= 2;
    }

    // printf ("\nsize : %d", size );
    array[body++] = data;
}


int deque (){

    if (head == body){
        printf ("queue is empty.");
        return -1;
    }

    if (body - head == size / 2){
        int *temp = (int*) malloc (sizeof(int) * size / 2);
        
        for (int i = 0; i < body - head; i++){
            temp[i] = array[head + i];
        }

        body -= head;
        head = 0;
        free (array);                
        size /= 2;
        array = temp;

    }

    return array[head++];
}


void space (){

    if (head == 0){
        return;
    }

    for (int i = 0; i < size; i++){
        array[i] = array[i + head];
    }
    
    body -= head;
    head = 0;
}

void show (){    
    printf ("\n");
    
    printf ("array : ");
    for (int i = 0; i < body; i++)
        printf ("%d ", array[i]);
    
    printf ("\n");
}

int main (){

    for (int i = 0; i < 5; i++){
        enque (i*10);
    }

    space();
    show();
    printf( "\nsize : %d  head : %d  body : %d\n", size, head, body);
    printf ("\n"); 
    
    printf ("deque : ");
    for (int i = 0; i < 3; i++){
        printf ("%d ", deque());
    }   
    
    printf ("\n"); 
    space();
    show();
    printf( "\nsize : %d  head : %d  body : %d\n", size, head, body);
    printf ("\n"); 

    return 0;
}