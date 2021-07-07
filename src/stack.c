#include "stack.h"
#include <stdlib.h>



Stack mkStack()
{
  return NULL;
}

struct Node {
  SData data;
  Stack next;
};

int stPush(Stack *st, SData data)
{
  // make sure st is a valid location in memory. i/e not zero and therefore true
  if (!st) {
    return -1;
  }
  Stack node = malloc(sizeof(*node));
  // making sure malloc didnt fuck up
  if (!node) {
    return -1;
  }

  //  (*node).data = data;
  node->data = data;
  node->next = *st;
  *st = node;
  return 1;
}

// Non-destructive inspection.
int stPeek(Stack *st, SData *dest)
{
  if (!st || !(*st) || !dest) {
    return -1;
  }
  // other option to combine 42 and 43: *dest = (*st)->data;
  Stack toPop = *st;
  *dest = toPop->data;
  return 1;
}

// traverses the list as long as st and the value stored at st are not zero
size_t stLength(Stack *st)
{
  if (st && *st) {
    Stack rest = (*st)->next;
    return 1 + stLength(&rest);
  } else {
    return 0;
  }
}



// Destroys the head of the list.
int stPop(Stack *st, SData *dest)
{
  if (!st || !(*st) || !dest) {
    return -1;
  }
  Stack toPop = *st;
  *dest = toPop->data;
  *st = toPop->next;
  free(toPop);
  return 1;
}



void stDestroy(Stack *st, void (*kill)(SData))
{
  // I want to store the "next" from the node, erase the node using free, I think.
  // then use the "next" address to get to the next node and repeat until the value
  // of next is NULL, but I cant' remember the syntax for doing that.
  if (!st) {
    return;
  }
  if (*st) {
    stDestroy((&(*st)->next), (kill));

    if (kill) {
      kill((*st)->data);
    }
    free(*st);
    *st = NULL;

  }
}
