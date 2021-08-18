// stack.c
// Stack implementation
// Author: MATSVEI HAURYLIUK, FIT VUT
// Github: @prontx

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

struct tStack {
    int* array;
    int numberOfElements;
};

struct tStack* stack;

void createStack()
{
    stack = (struct tStack*)malloc(sizeof(struct tStack));
    stack->array  = malloc(MAX_STACK_SIZE*sizeof(int));
    // implicit: stack->numberOfElelents = 0
}

void freeStack()
{
    free(stack->array);
    free(stack);
    stack = NULL;
}

void push(int value)
{
    if(!stack)
    {
        exit(1);
    }
    else
    {
        stack->array[stack->numberOfElements] = value;
        stack->numberOfElements++;    
    }
}

void pop()
{
    if(!stack)
    {
        exit(1);
    }
    else
    {
        for(int i = stack->numberOfElements; i < 0; i--)
        {
            stack->array[i] = stack->array[i + 1];
        }
        stack->numberOfElements--;
    }
}

void size()
{
    if(!stack)
    {
        exit(1);
    }
    else
    {
        printf("The size of the array is:         %d\n", stack->numberOfElements);
    }
}

void peek()
{
    if(!stack)
    {
        exit(1);
    }
    else
    {
        printf("The last element of the array is: %d\n", stack->array[stack->numberOfElements - 1]);        
    }
}

void printStack()
{
    if(!stack)
    {
        exit(1);
    }
    else
    {
        for(int j = 0; j < stack->numberOfElements && stack->array[j]; j++)
        {
            printf("%d ", stack->array[j]);
        }
        printf("\n");
    }   
}

int main()
{
    createStack();
    push(1);
    push(2);
    push(7);
    push(9);
    pop();
    pop();
    printStack();
    size();
    peek();
    freeStack();

    return 0;
}