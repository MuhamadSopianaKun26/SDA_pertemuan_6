#ifndef SLOT_H
#define SLOT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "singleList.h"
#include "queue.h"
#include "stacked.h"
#include "boolean.h"

Fruit getRandomFruit ();
boolean isSameFruit(SlotStack *s, Fruit keyFruit);
void playSlot(linkedlist *Q, linkedlist *Riwayat, SlotStack *Stack);

#endif