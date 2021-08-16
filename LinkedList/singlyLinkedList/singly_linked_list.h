// singly_linked_list.h
// Singly linked list implementation
// Author: MATSVEI HAURYLIUK, FIT VUT
// Github: @prontx

#include <stdio.h>
#include <stdlib.h>

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

struct Node
{
    int data;
    struct Node* pNext;
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

#endif