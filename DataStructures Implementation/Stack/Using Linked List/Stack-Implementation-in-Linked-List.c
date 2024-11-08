#include <stdio.h>
#include<stdlib.h>

#define INT_MIN -1000000

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct Stack{
    node* top;
    node* head;
}Stack;

node* CreateNode(node* newnode , int data){
    newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

Stack* CreateStack(Stack* stack){
    stack = (Stack*)malloc(sizeof(Stack));
    stack->head = NULL;
    stack->top = NULL;
    return stack;
}

Stack* Push(Stack* stack, int data){
    if(stack->head!=NULL){
        node* newnode = CreateNode(newnode,data);
        stack->top->next = newnode;
        stack->top = newnode;
    }
    else{
        stack->head = (node*)malloc(sizeof(node));
        stack->head->data = data;
        stack->head->next = NULL;
        stack->top = stack->head;
    }
    return stack;
}

Stack* Pop(Stack* stack){
    if(stack->head!=NULL){
        if(stack->head->next == NULL){
            stack->head = NULL;
            return stack;
        }
        else{
            node* curr = stack->head;
            while(curr->next != stack->top){
                curr = curr->next;
            }
            curr->next = NULL;
            stack->top = curr;
            return stack;
        }
    }
}

int isEmpty( Stack* stack){
    if(stack->head == NULL){
        return 1;
    }
    return 0;
}

int Peek(Stack* stack){
    if(stack->head != NULL){
        return stack->top->data;
    }
    else{
        return INT_MIN;
    }
}

void Print(Stack * stack){
    node* curr = stack->head;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }
}

int Size(Stack* stack){
    node* curr = stack->head;
    int len = 0;
    while(curr!=NULL){
        len++;
        curr = curr->next;
    }
    return len;
}

int main(){
    Stack *newstack = CreateStack(newstack);
    newstack = Push(newstack,1);
    newstack = Push(newstack,2);
    newstack = Push(newstack,3);
    newstack = Push(newstack,4);
    newstack = Push(newstack,5);
    newstack = Push(newstack,6);
    newstack = Push(newstack,7);
    Print(newstack);
    newstack  = Pop(newstack);
    newstack  = Pop(newstack);
    newstack  = Pop(newstack);
    printf("\n");
    Print(newstack);
    return 0;
}

 