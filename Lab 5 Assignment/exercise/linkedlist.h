#include "node.h"

typedef struct LinkedList
{
    Node* root; // the first node of the linked list
    // This struct can store more variables depending on the application but we kept it simple.
} LinkedList;

// FUNCTIONS: see linkedlist.c for the implementations

void LinkedList_init(LinkedList* l, int* arr, int len); // Initializes the LinkedList with a copy of array arr

int LinkedList_length(LinkedList* l); // Calculates the length of the LinkedList

int LinkedList_remove(LinkedList* l); // Deletes the last node and returns its value (content)

void LinkedList_insert(LinkedList* l, int value); // Appends the value to the end of linked list as a new node

int LinkedList_remove_value(LinkedList* l, int value);  // Finds the first occurance of value (int) in the LinkedList and removes it from the LinkedList. Returns the index of the the first occurance. If not found, returns -1.

char* LinkedList_to_string(LinkedList* l, char* str); // Converts the LinkedList to a string so that we can print it
