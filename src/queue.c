#include "queue.h"
#include "stack.c"

struct Queue {
    Stack in, out;
};


//implement these functions

Queue *mkQueue(void);
//malloc a queue, then use mkstack for each one

int qAdd(Queue *q, QData data);
//add to the in stack

QResult qPeek(Queue *q);
// look at the node

QResult qNext(Queue *q);
// pop the node

void qDestroy(Queue *q, void (*kill)(QData));
// recursively kill the whole queue
//while (qNext(q).hasData);
// free(q);
