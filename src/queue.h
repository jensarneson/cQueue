#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef int QData;

typedef struct QResult {
  bool hasData;
  union {
    QData data;
    void *none;
  } payload;
} QResult;

typedef struct Queue Queue;

Queue *mkQueue(void);

int qAdd(Queue *q, QData data);

QResult qPeek(Queue *q);

QResult qNext(Queue *q);

void qDestroy(Queue *q, void (*kill)(QData));

#endif // QUEUE_H
