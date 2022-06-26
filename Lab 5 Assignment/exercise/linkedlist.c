#include "linkedlist.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int LinkedList_remove_value(LinkedList* l, int value){
    // Finds the first occurrence of value (int) in the LinkedList and removes it from the LinkedList
    // Returns the index of the the first occurance. If not found, returns -1.
    // Indexing starts from 0 (as with arrays)
    // E.g. let l contains [3,2,5,1] and value=2 then the content of l should be changed to [3,5,1] and return 1
    // DO NOT FORGET TO FREE THE UNUSED (REMOVED) SPACE SINCE IT IS DYNAMICALLY ALLOCATED
    
    // TODO: IMPLEMENT LinkedList_remove_value
    // FILL HERE
    // You can use the functions implemented below


	Node* current = l->root;
	Node* previous = current;
	int index=0;
	while(current != NULL){
		if(current->content == value){
			if(l->root->content == value){
				l->root = current->next;
				free(current);
			}
			else {
		 		previous->next = current->next;
				free(current);
			}
			return index;
			break;
		}
		previous = current;
		current = current->next;
		index += 1;
	}
    	return -1;

}

void LinkedList_init(LinkedList* l, int* arr, int len){
    // Initializes the LinkedList with a copy of array arr
    l->root = NULL; // initialize root node to NULL
    int i;
    for(i=0;i<len;i++){
        LinkedList_insert(l, arr[i]);
    }
} 

int LinkedList_length(LinkedList* l){
    // Calculates the length of the LinkedList
    
    if(l->root == NULL){
        return 0;
    }else{
        int count = 1;
        Node* current = l->root;
        while(current->next != NULL){
            current = current->next;
            count++;
        }
        return count;
    }
}

int LinkedList_remove(LinkedList* l){
    // Deletes the last node and returns its value (content)
    // Note: return -1 when there is no value in the list.

    int value = -1;
    if(l->root == NULL){
        return value;
    }else if(l->root->next == NULL){
        // when there is only root node
        value = l->root->content;
        free(l->root);
        l->root = NULL;
        return value;
    }else{
        // when there multiple nodes
        Node* current = l->root;
        while(current->next->next != NULL){
            current = current->next;
        }
        value = current->next->content;
        free(current->next);
        current->next = NULL;
        return value;
    }
}

void LinkedList_insert(LinkedList* l, int value){
    // Appends the value to the end of linked list as a new node
    Node* n = malloc(sizeof(Node)); // create a new node
    n->content = value;
    n->next = NULL;

    if(l->root == NULL){
        l->root = n;
    }else{
        // Iterating through nodes until last node
        Node* current = l->root;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = n;
    }
}

char* LinkedList_to_string(LinkedList* l, char* str){
    // Converts LinkedList to string and puts it into str
    strcat(str, "[ ");
    Node* current = l->root;
    if(current != NULL){
        do{
            char temp[10]  = "";
            sprintf(temp, "%d ", current->content);
            strcat(str, temp);
            current = current->next;
        }while(current != NULL);
    }
    strcat(str, "]");
    return str;
}

