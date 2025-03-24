#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "singleList.h" // Hanya include singleList.h


/********** PROTOTYPE QUEUE **********/
void CreateQueue(linkedlist *Q);
bool IsQueueEmpty(linkedlist Q);
void Enqueue(linkedlist *Q, const char *nama);
void Dequeue(linkedlist *Q, address *pemain);
void PrintQueue(linkedlist Q);

#endif