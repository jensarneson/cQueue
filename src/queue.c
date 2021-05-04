#include "queue.h"

#include <stdlib.h>

typedef struct QNode {
  struct QNode *next;
  QData data;
} QNode;

struct Queue {
  QNode *front;
  QNode *back;
};

Queue *mkQueue()
{
  return calloc(1, sizeof(Queue));
}

static QNode *mkNode(QData data)
{
  QNode *qn = calloc(1, sizeof(*qn));
  if (qn) {
    qn->data = data;
  }
  return qn;
}

int qAdd(Queue *q, QData data)
{
  if (!q) {
    return -1;
  }
  QNode *new = mkNode(data);
  // The queue is empty.
  if (!q->front)
  {
    q->front = new;
  }
  else if (!q->back)
  {
    q->front->next = new;
    q->back = new;
  }
  else
  {
    q->back->next = new;
    q->back = new;
  }
  return 0;
}

QResult qPeek(Queue *q)
{
  if (!q || !q->front) {
    return (QResult){ false, { 0 } };
  }
  return (QResult){ true, { q->front->data } };
}

QResult qNext(Queue *q)
{
  if (!q || !q->front) {
    return (QResult){ false, { 0 } };
  }
  QNode *qn = q->front;
  q->front = qn->next;
  if (q->front == q->back) {
    q->back = NULL;
  }
  QResult result = { true, { qn->data } };
  free(qn);
  return result;
}

void qDestroy(Queue *q, void (*kill)(QData))
{
  QResult result;
  while ((result = qNext(q)).hasData) {
    kill(result.payload.data);
  }
}
