// doubly_linked_list.h
// Doubly linked list implementation
// Author: MATSVEI HAURYLIUK, FIT VUT
// Github: @prontx

#include <stdio.h>
#include <stdlib.h>

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct Node
{
    int data;
    struct Node* pNext;
    struct Node* pPrevious;
};

struct List
{
    struct Node* head;
};

struct List* l;

void insertAtBeginning(int value);

void insertAtEnd(int value);

void printList();

void deleteFromEnd();

void deleteFromBeginning();

void deleteByValue(int value);

#endif