#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"DataStructures Implementation/Stack/Using Linked List/Stack-Implementation-in-Linked-List.c"


/*
Algorithm:

1) Scan each character of the input expression from left to right

2) If the scanned character is an operand (number or letter):
   - Add it directly to the postfix expression

3) If the scanned character is '(':
   - Push it onto the stack

4) If the scanned character is ')':
   - Pop and append operators from stack to postfix expression until '(' is found
   - Pop and discard the '('
   - If stack becomes empty before finding '(', then expression is invalid

5) If the scanned character is an operator (+, -, *, /, etc.):
   - While stack is not empty AND top of stack is not '(' AND
    precedence of current operator <= precedence of top operator:
     * Pop operator from stack and append to postfix expression
   - Push the current operator onto stack

6) After scanning all characters:
   - Pop and append all remaining operators from stack to postfix expression
   - If '(' is found in stack, expression is invalid
*/


int GetOperatorPriority(char op){
  if(op == '^'){
    return 3;
  }
  else if(op == '*' || op == '/'){
    return 2;
  }
  else if(op == '+' || op == '-'){
    return 1;
  }
  else{
    return -1;
  }
}

char* InfixToPostfix(char* expression){
  Stack* st = CreateStack(st);
  int i=0;
  int len = strlen(expression);
  char* postfix = (char*)malloc(sizeof(char)*len+1);
  int j=0;
  char s = expression[i];
  while(expression[i]!='\0'){
    if((expression[i]>='A' && expression[i]<='Z') || (expression[i]>='a' && expression[i]<='z') || (expression[i] >='0' && expression[i]<='9')){
      postfix[j] = expression[i];
      j++;
    }
    else if(expression[i] == '('){
      st = Push(st, expression[i]);
    }
    else if(expression[i] == ')'){
      while(!isEmpty(st) && Peek(st)!='('){
        postfix[j] = Peek(st);
        j++;
        st = Pop(st);
      }
      st = Pop(st);
    }
    else{
      int priority = GetOperatorPriority(expression[i]);
      if(isEmpty(st)){
        st = Push(st,expression[i]);
      }
      else{
        while(!isEmpty(st) && Peek(st) != '(' && priority <= GetOperatorPriority(Peek(st))){
          postfix[j] = Peek(st);
          j++;
          st = Pop(st);
        }
        st = Push(st, expression[i]);
      }
    }
    i++;
  }
  if(isEmpty(st)==0){
    while(!isEmpty(st)){
      postfix[j] = Peek(st);
      j++;
      st = Pop(st);
    }
  }
  postfix[j] = '\0';
  return postfix;
}

int main(){
  char* exp = "a^(b^c)";
  char* postfix = InfixToPostfix(exp);
  printf("%s",postfix);
  return 0;
}
