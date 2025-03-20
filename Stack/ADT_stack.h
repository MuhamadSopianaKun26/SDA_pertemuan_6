#ifndef stack_h
#define stack_h

typedef struct stackNode* address;
typedef struct stackNode {
  int info;
  address next;
} stack;


struct node * createstacknode(int data);
struct node * push(stack **top, int pushed);
void pop(stack **top);
int peek(stack * print);
void printStack(stack *S);

#endif
