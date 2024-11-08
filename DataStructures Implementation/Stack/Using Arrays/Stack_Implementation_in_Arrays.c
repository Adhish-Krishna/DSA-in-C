
#include <stdio.h>
#include<stdlib.h>

#define INT_MIN -100000000

typedef struct Stack{
    int size;
    int *stack;
    int top;
}Stack;

Stack* CreateStack(Stack *Stack , int size){
    Stack->stack = (int*)malloc(size*sizeof(int));
    Stack->size = size;
    Stack->top = -1;
    return Stack;
}

int isEmpty(Stack* Stack){
    if(Stack->top ==-1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(Stack *Stack){
    if(Stack->top == Stack->size-1){
        return 1;
    }else{
        return 0;
    }
}

Stack* Push(Stack* Stack , int data){
    if(isFull(Stack)==0){
        Stack->top ++ ;
        Stack->stack[Stack->top] = data;
    }
    else{
        printf("Stack is full");
    }
    return Stack;
}

Stack* Pop(Stack* Stack){
    if(isEmpty(Stack)==0){
        Stack->top--;
    }else{
        printf("Stack is Empty");
    }
    return Stack;
}

int Peek(Stack* Stack){
    if(isEmpty(Stack)==0){
        return Stack->stack[Stack->top];
    }
    return INT_MIN;
}

void Print(Stack* Stack){
    int index = 0;
    while(index<=Stack->top){
        printf("%d ",Stack->stack[index]);
        index++;
    }
}

void FreeStack(Stack* Stack){
    free(Stack->stack);
    free(Stack);
}

int main() {
    Stack *newstack = (Stack*)malloc(sizeof(Stack));
    newstack = CreateStack(newstack,5);
    newstack = Push(newstack,1);
    newstack = Push(newstack,2);
    Print(newstack);
    printf("\n");
    newstack = Pop(newstack);
    Print(newstack);
    newstack = Push(newstack,5);
    newstack = Push(newstack,7);
    newstack = Push(newstack,9);
    printf("\n");
    Print(newstack);
    int n  = Peek(newstack);
    printf( "\nPeek : %d",n);
    return 0;
}