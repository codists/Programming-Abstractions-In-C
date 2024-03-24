/*
 * File: stack.c
 * -------------
 * This file implements the stack.h interface. Note that the
 * implementations is independent of the type of value stored
 * in the stack. That type is defined by  the interface as
 * the type name stackElementT.
 */

#include <stdio.h>
#include "genlib.h"
#include "stack.h"

/*
 * Constant: MaxStackSize
 * ----------------------
 * This constant specifies the amount of space to allocate for
 * the array that holds the stack elements. Attempt to push
 * more than this many values will result in an error.
 */

#define MaxStackSize 100

/*
 * Type: stackCDT
 * --------------
 * The type stackCDT is the concrete representation of the type
 * stackADT defined by the interface. In this implementation,
 * the elements are stored in an array. Because this type
 * definition appears only in the implementation and not in the
 * interface, the definition can be changed as long as the
 * abstract behavior of the type remains the same.
 */

struct stackCDT {
    stackElementT elements[MaxStackSize];
    int count;
};

/* Exported entries */

stackADT NewStack(void) {
    stackADT stack;

    stack = New(stackADT);
    stack->count = 0;
    return stack;
}

void FreeStack(stackADT stack) {
    FreeStack(stack);
}

void Push(stackADT stack, stackElementT element) {
    if (StackIsFull(stack)) {
        Error("Stack size exceeded");
    }
    stack->elements[stack->count++] = element;
}

stackElementT Pop(stackADT stack) {
    if (StackIsEmpty(stack)) {
        Error("Pop of an empty stack");
    }
    return stack->elements[--stack->count];
}

bool StackIsEmpty(stackADT stack) {
    return stack->count == 0;
}

bool StackIsFull(stackADT stack) {
    return stack->count == MaxStackSize;
}

int StackDepth(stackADT stack) {
    return stack->count;
}

stackElementT GetStackElement(stackADT stack, int index) {
    if (index < 0 || index >= stack->count) {
        Error("Non-existent stack element");
    }
    return stack->elements[stack->count - index - 1];
}










































