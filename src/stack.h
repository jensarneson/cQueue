#ifndef STACK_H
#define STACK_H

#include <stddef.h>

// A Stack is a type alias for a pointer to the Node type.
// Define the type struct Node in the implementation file.
//
// Most functions in the API will take a pointer to a Stack.
// That will let them allocate new nodes and link them with
// the existing ones before. This is one layer of indirection
// which is obviously the solution to every problem in CS.
typedef struct Node* Stack;

// Redefine the enclosed datatype with the following alias.
// Don't redefine it for simple testing though.
typedef int SData;

// Initially we will test with `mkStack', `stLength', and `stDestroy'.
// So, implement those first and then start with `stPop'.
// These initial tests wont check that the values are right until
// we start testing `stPop'.

// This should really just return `NULL'
Stack mkStack();

int stPush(Stack *st, SData data);

// Non-destructive inspection.
int stPeek(Stack *st, SData *dest);

size_t stLength(Stack *st);

// Destroys the head of the list.
int stPop(Stack *st, SData *dest);

// kill is a function pointer that will destroy SData
// values if they need to be freed. It is user supplied.
// If you are using a scalar type for SData, then pass NULL.
void stDestroy(Stack *st, void (*kill)(SData));

#endif // STACK_H
