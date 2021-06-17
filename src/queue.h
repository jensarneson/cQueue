#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#ifndef QUEUE_DATA_T
#define QUEUE_DATA_T int
#endif

typedef QUEUE_DATA_T QData;

typedef struct QResult {
  bool hasData;
  union {
    QData data;
    void *none;
  } u;
} QResult;

typedef struct Queue Queue;

Queue *mkQueue(void);

int qAdd(Queue *q, QData data);

QResult qPeek(Queue *q);

QResult qNext(Queue *q);

void qDestroy(Queue *q, void (*kill)(QData));

#endif // QUEUE_H
