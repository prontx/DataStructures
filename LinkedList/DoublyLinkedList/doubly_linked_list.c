// doubly_linked_list.c
// Doubly linked list implementation
// Author: MATSVEI HAURYLIUK, FIT VUT
// Github: @prontx

#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

/**
 *  Creates a linked list and initializes its fields.
 *  The l->head->data field uses a dummy value(333) to make it 
 *  easier to work with the list. 
 *  The dummy value is never used afterwards.
 */
void createList()
{
    l = malloc(sizeof(struct List));
    l->head = malloc(sizeof(struct Node));
    l->head->data = 333;
    l->head->pPrevious = NULL;
    l->head->pNext = NULL;
}

/**
 *  Uses the l->head field to access all list elements
 *  and free the memory allocated for them.
 *  Then frees the entire list structure.
 */
void destroyList()
{
    struct Node* runnerNode = l->head;
    struct Node* toBeFreed  = l->head;
    while(runnerNode != NULL)
    {
        toBeFreed = runnerNode;
        runnerNode = runnerNode->pNext;
        free(toBeFreed);
    }
    free(l);
}

/**
 * Inserts a new linked list node at the beginning
 * of the list. Does so with the help of an intermediary 
 * node.
*/
void insertAtBeginning(int value)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->pNext = NULL;
    newNode->pPrevious = NULL;
    struct Node* auxNode = l->head->pNext;
    l->head->pNext = newNode;
    newNode->pPrevious = l->head;
    newNode->pNext = auxNode;
    if (auxNode)
    {
        auxNode->pPrevious = newNode;
    }
}

/**
 * Inserts a new linked list node at the end
 * of the list. Firstly iterates over the entire list
 * to locate its end. Appends the node afterwards.
*/
void insertAtEnd(int value)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->pNext = NULL;
    newNode->pPrevious = NULL;
    struct Node* runnerNode = l->head;
    struct Node* auxNode    = l->head;
    while(runnerNode != NULL)
    {
        auxNode = runnerNode;
        runnerNode = runnerNode->pNext;
    }
    // Thus when the loop is finished we've located end of the list
    auxNode->pNext = newNode;
    newNode->pPrevious = auxNode;
}

/**
 * Deletes a node off the end
 * of the list. Locates the first to last 
 * element and sets its pNext field to NULL.
 * Frees the memory previously taken by deleted node.
*/
void deleteFromEnd()
{
    struct Node* runnerNode = l->head;
    struct Node* auxNode    = l->head;
    while(runnerNode->pNext != NULL)
    {
        auxNode = runnerNode;
        runnerNode = runnerNode->pNext;
    }    
    // Thus when the loop is finished we've located end of the list
    auxNode->pNext = NULL;
    free(runnerNode);
}

/**
 * Deletes a node off the beginning of the list.
*/
void deleteFromBeginning()
{
    struct Node* auxNode = l->head->pNext;
    l->head->pNext = auxNode->pNext;
    auxNode->pNext->pPrevious = l->head;
    free(auxNode);
}

/**
 * Deletes a node with a given value is such is present
 * in the list.
*/
void deleteByValue(int value)
{
    struct Node* runnerNode = l->head->pNext;
    struct Node* firstAuxNode;
    struct Node* secondAuxNode;
    while(runnerNode != NULL)
    {
        if(runnerNode->data == value)
        {
            firstAuxNode = runnerNode->pPrevious;
            secondAuxNode = runnerNode->pNext;
            runnerNode->pPrevious->pNext = secondAuxNode;
            if(runnerNode->pNext)
            {
                runnerNode->pNext->pPrevious = firstAuxNode;
            }        
            free(runnerNode);
            break;
        }
        runnerNode = runnerNode->pNext;
    }
}


/**
 * Prints the linked list.
*/
void printList()
{
    struct Node* runnerNode = l->head->pNext;
    while(runnerNode != NULL)
    {
        printf("%d", runnerNode->data);
        if(runnerNode->pNext != NULL)
        {
            printf(" -> ");
        }
        else
        {
            printf("\n");
        }
        runnerNode = runnerNode->pNext;
    }
}

int main()
{
    createList();

    insertAtEnd(-1);     
    deleteFromEnd();   
    insertAtBeginning(9);   
    insertAtBeginning(6);   
    insertAtEnd(164);  
    insertAtEnd(420);  
    insertAtBeginning(40);         
    deleteFromEnd();
    deleteFromBeginning();
    deleteByValue(164);

    printList();
    destroyList();

    return 0;
}