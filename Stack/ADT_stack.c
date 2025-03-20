#ifndef stack_h
#define stack_h

#include <stdlib.h>
#include <stdio.h>

typedef struct stackNode* address;
typedef struct stackNode {
  int info;
  address next;
} stack;

address createstacknode(int data){
  address temp = (address)malloc(sizeof(stack));
  if (temp == NULL){
    perror("stack error!");
    exit(1);
  }
  temp->info = data;
  temp->next = NULL;
  return temp;
}

void push(stack **top, int pushed){
  address pushit = createstacknode(pushed);
  address temp = *top;

  if(*top == NULL){
    *top = pushit;
    return;
  }

  pushit->next = temp->next;
  temp->next = pushit;
}

void remove_top(stack **top){
  stack* temp = *top;
  *top = (*top)->next;
  free(temp);
}

void pop(stack **top){

  if(*top == NULL){
    perror("list kosong");
  }
    printf("Info data paling atas: %d\n", (*top)->info);
    remove_top(top);
}

int peek(stack * print){
  if (print == NULL){
    perror("list kosong...");
  }
  return print->info;
}

void printStack (stack *S) {
    if (S == NULL) {
        printf("list kosong");
        return;
    }
    address temp = NULL;
    temp = S;

    while (temp != NULL) {
            printf ("%d", temp->info);
            temp = temp->next;
    }
}


#endif // !DEBUG
