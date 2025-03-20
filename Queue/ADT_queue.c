#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ADT_queue.h"

void initQueue(Queue* q)
{
    q->front = q->last = NULL;
    q->count = 0;
    q->nextQueue = NULL;
}

int isEmpty(Queue* q)
{
    return (q->count == 0 && q->front == NULL);
}

int isFull(Queue* q)
{
    return q->count == MAX_SIZE;
}

void enqueue(Queue* q, char* nama)
{
    address newNode = (address)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf ("Failed malloc!");
        return;
    }

    if (isFull(q))
    {
        printf("Line is full!\n");
        return;
    }  
    strcpy(newNode->nama, nama);
    newNode->lineNumber = q->count + 1;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->last = newNode;
    } else {
        q->last->next = newNode;
        q->last = newNode;
    }
    q->count++;
    printf("%s have been added to line %d\n", nama, newNode->lineNumber);
}

int dequeue(Queue* q)
{
    if (isEmpty(q))
    {
        printf("Line is empty!\n");
        return 1;
    }
    Node* temp = q->front;
    printf ("serve customer name : %s, line number : %d\n", temp->nama, temp->lineNumber);
    q->front = q->front->next;
    free(temp);

    if(q->front == NULL) {
        q->last = NULL;
    }
    q->count--;
    return 0;
}

void displayQueue(Queue* q)
{
    if (isEmpty(q))
    {
        printf("Line is empty!\n");
        return;
    }
    Node* temp = q->front;
    printf("Line List : \n");
    while(temp != NULL) {
        printf("Line Number-%d: %s\n", temp->lineNumber, temp->nama);
        temp = temp->next;
    }
}

void displayAllQueues(Queue* head){
    Queue* tempQueue = head;
    int queueNum = 1;
    while (tempQueue != NULL) {
        printf("Teller table-%d:\n", queueNum++);
        displayQueue(tempQueue);
        printf("\n");
        tempQueue = tempQueue->nextQueue;
    }
}

void inputLineNumber(Queue** head) {
    int number_of_line, i;
    scanf("%d", &number_of_line);
    getchar(); // membersihkan buffer

    if (number_of_line <= 0) {
        printf("Input must bigger than 0!\n");
        return;
    }

    Queue* prev = NULL;

    for (i = 0; i < number_of_line; i++){
        Queue* newQueue = (Queue*)malloc(sizeof(Queue));
        if (!newQueue) {
            printf("Failed malloc!\n");
            return;
        }
        initQueue(newQueue);
        if (*head == NULL) {
            *head = newQueue;
        } else {
            prev->nextQueue = newQueue;
        }
        prev = newQueue;
    }
}

int countQueues(Queue* head) {
    int count = 0;
    Queue* temp = head;

    while (temp) {
        count++;
        temp = temp->nextQueue;
    }

    return count;
}

void freeQueue(Queue* q) {
    if (q == NULL) return;
    
    // Bebaskan semua node dalam queue
    while (!isEmpty(q)) {
        dequeue(q);
    }
    
    // Bebaskan queue itu sendiri
    free(q);
}

void freeAllQueues(Queue* head) {
    Queue* current = head;
    Queue* next;
    
    while (current != NULL) {
        next = current->nextQueue;
        freeQueue(current);
        current = next;
    }
}
