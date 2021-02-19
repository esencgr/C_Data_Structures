#include <stdio.h>
#include <stdlib.h>

typedef struct s{
      int *arr;
      int size;
      int top;
}stack;

stack *def (){
    stack * s = (stack*) malloc (sizeof(stack) );
    s -> arr = NULL;
    s -> size = 2;
    s -> top = 0;  
    return s ;
}

void push (stack *s, int val){
    if (s -> top == 0){
        s -> arr = (int*) malloc (sizeof(int) * 2);
    }
    if ( s -> top == s -> size ){
        int *temp = (int*) malloc (sizeof(int) * s->size * 2);

        for (int i = 0; i < s -> top; i++){
            temp[i] = s -> arr[i];
        }
    
        free (s -> arr);
        s -> arr = temp; 
        s -> size *= 2 ;
    }
    printf ("\nsize of array : %d", s -> size);
    s -> arr [ s -> top++ ] = val;
}

void pop (stack *s){  //    int pop (stack *s){
    if (s -> top == 0){
        printf ("underflow\n");
        s -> size = 0;
    }
    if ( s -> top == s -> size/2){
        int *temp = (int*) malloc (sizeof(int) * s->size /2 );

        for (int i = 0; i < s -> top; i++){
            temp[i] = s -> arr[i];
        }
    
        free (s -> arr);
        s -> arr = temp; 
        s -> size /= 2 ;
    }
    printf ("size of array : %d\n", s -> size);
    s -> arr [ --s -> top ];  // return s -> arr [ --s -> top ];
}

void show (stack *s){
    printf ("\n");
    for (int i = 0; i < s -> top; i++){
        printf ("%d ",s -> arr[i]);
    }
    printf ("\n");

}

int main (){
    stack *s1;
    s1 = def(s1);
 
    for (int i = 1; i < 5; i++){
        push (s1,i*2);
        show(s1);
    }
    printf ("\n");

    for (int i = 1; i < 6; i++){
        show (s1);
        pop (s1);

    }
    printf ("\n");
    return 0;
}
