// singly_linked_list.c
// Singly linked list implementation
// Author: MATSVEI HAURYLIUK, FIT VUT
// Github: @prontx

#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"

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
    struct Node* auxNode = l->head->pNext;
    l->head->pNext = newNode;
    newNode->pNext = auxNode;
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
    struct Node* runnerNode = l->head;
    struct Node* auxNode    = l->head;
    while(runnerNode != NULL)
    {
        auxNode = runnerNode;
        runnerNode = runnerNode->pNext;
    }
    // Thus when the loop is finished we've located end of the list
    auxNode->pNext = newNode;
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
    free(auxNode);
}

int main()
{
    createList();

    insertAtBeginning(55);
    insertAtBeginning(8);
    insertAtEnd(2);
    insertAtEnd(7);
    deleteFromBeginning();
    deleteFromEnd();
    insertAtBeginning(44);

    printList();
    destroyList();

    return 0;
}