/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "linkedlist_as_nodes_stringkey.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "standardheaders.h"
#include "linkedlist_as_nodes.h"

void MainLinkedlistAsNodesStringKey() {
  printf("\n\n----------------------- MainLinkedlistAsNodesStringKey \n");
  
  //-----------------------------------------
  // preparations:
  
  //-----------------------------------------
  // Exercises
  MainLinkedlistAsNodesStringKey_API();
    
  return;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void MainLinkedlistAsNodesStringKey_API() {  
  printf("\n----------------------------------- MainLinkedlistAsNodesStringKey_API \n");
  
  // create a linked list
  LinkedlistStringKeyT l;  
  LinkedlistStringKeyT *l_ptr = &l;
  LinkedListStringKey_Init(l_ptr);
  
  // Insert 3 nodes at the front
  printf("Check list: use Push-API to insert 3 nodes: \n");
  LinkedListStringKey_PushFront_CopyDataNode(l_ptr, &((DataNodeStringKeyIntValT){"abc", 3 }));
  LinkedListStringKey_PushFront_CopyDataNode(l_ptr, &((DataNodeStringKeyIntValT){"c", 11 }));
  LinkedListStringKey_PushFront_CopyDataNode(l_ptr, &((DataNodeStringKeyIntValT){"xyz", 2 }));
  
  printf("Current list content: \n");
  LinkedListStringKey_PrintData(l_ptr);
  
  // Pop 2 nodes at front
  printf("Check list: use Pop-API to remove 1 node : \n");
  LinkedListStringKey_PopFront(l_ptr);
  
  
  printf("Current list content: \n");
  LinkedListStringKey_PrintData(l_ptr);
  
  return;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//-------------------------------------------------------------- API

void LinkedListStringKey_PushFront(LinkedlistStringKeyT* l_ptr, char* key, int val) {
  ListNodeStringKeyIntValT* new_mem = calloc(1, sizeof(ListNodeStringKeyIntValT));
  strcpy(new_mem->data.key, key);
  new_mem->data.val = val;
  new_mem->next = l_ptr->head;
  l_ptr->head = new_mem;
  ++(l_ptr->n_nodes);
  return;
}

void LinkedListStringKey_PushFront_CopyDataNode(LinkedlistStringKeyT* l_ptr, 
        DataNodeStringKeyIntValT* new_datanode) {
  ListNodeStringKeyIntValT* new_mem = calloc(1, sizeof(ListNodeStringKeyIntValT));
  new_mem->data = *new_datanode;
  new_mem->next = l_ptr->head;
  l_ptr->head = new_mem;
  ++(l_ptr->n_nodes);
  return;
}


void LinkedListStringKey_PopFront(LinkedlistStringKeyT* l_ptr) {
  if (l_ptr->head) {
    ListNodeStringKeyIntValT* mem_to_delete = l_ptr->head;
    l_ptr->head = l_ptr->head->next;
    free(mem_to_delete);
    --(l_ptr->n_nodes);
  } else {
    printf("Underflow Error: List is Empty. Cannot pop. \n");    
  }
  return;
}


// note: we do not check that given node is actually part of the list
void LinkedListStringKey_InsertAfterNode(LinkedlistStringKeyT* l_ptr, 
        ListNodeStringKeyIntValT* predecessor, 
        DataNodeStringKeyIntValT* new_datanode) {
  ListNodeStringKeyIntValT* new_mem = calloc(1, sizeof(ListNodeStringKeyIntValT));
  new_mem->data = *new_datanode;
  new_mem->next = predecessor->next;
  predecessor->next = new_mem;  
  ++(l_ptr->n_nodes);
  return;
}

/**
 * Deletes node in O(1).
 * 
 * @param l_ptr
 * @param predecessor
 */
void LinkedListStringKey_DeleteAfterNode(LinkedlistStringKeyT* l_ptr,
        ListNodeStringKeyIntValT* predecessor) {
  if (predecessor) {
    ListNodeStringKeyIntValT* to_delete = predecessor->next;
    if (to_delete) {
      predecessor->next = predecessor->next->next;
      free(to_delete);
      --(l_ptr->n_nodes);
    }
  }
  return;
}

/**
 * Delete in O(1).
 * 
 * Assume given node is not the tail!
 * 
 * @param node
 */
void LinkedListStringKey_DeleteNodeInO1(ListNodeStringKeyIntValT* node) { 
  ListNodeStringKeyIntValT* tmp = node->next;
  strcpy(node->data.key, node->next->data.key);
  node->data.val = node->next->data.val;
  node->next = node->next->next;
  if (tmp) { free(tmp); }
  return;
}

void LinkedListStringKey_Init(LinkedlistStringKeyT* l_ptr) {  
  l_ptr->head = NULL;  
  l_ptr->n_nodes = 0;
  return;
}

void LinkedListStringKey_Destroy(LinkedlistStringKeyT* l_ptr) {
  ListNodeStringKeyIntValT* curr = l_ptr->head;  
  while (curr && l_ptr->n_nodes) { // note: both conditions needed to avoid cycle
    ListNodeStringKeyIntValT* next = curr->next;
    free(curr);
    curr = next;
    --(l_ptr->n_nodes);
  }
  return;
}

/**
 * if there is a match, 
 * returns the first "index" that matches key and sets value,
 * otherwise returns -1 as index and does not set the value
 * 
 * ACHTUNG: O(n) algorithm
 * 
 * @param l_ptr
 * @param key
 * @return 
 */
ListNodeStringKeyIntValT* LinkedListStringKey_FindMatch(LinkedlistStringKeyT* l_ptr, 
        char* key) {
  ListNodeStringKeyIntValT* curr = l_ptr->head;  
  while (curr) {
    if (strcmp(curr->data.key, key) == 0) {return curr;}    
    curr = curr->next;
  }
  return NULL;
}

/**
 * ACHTUNG: O(n) algorithm
 * 
 * @param list
 * @return 
 */
ListNodeStringKeyIntValT* LinkedListStringKey_GetTail(LinkedlistStringKeyT* list) {
  ListNodeStringKeyIntValT* curr = list->head;
  ListNodeStringKeyIntValT* tail = NULL;
  while (curr) {
    tail = curr;
    curr = curr->next;
  }
  return tail;
}

/**
 * ACHTUNG:  O(n) algorithm 
 * 
 * @param list
 * @param key
 */
void LinkedlistStringKey_DeleteKey(LinkedlistStringKeyT* list, char* key) {
  ListNodeStringKeyIntValT* predecessor = LinkedListStringKey_FindMatchPredecessor(
          list, key);
  if (predecessor) {
    LinkedListStringKey_DeleteAfterNode(list, predecessor);
  } else if (strcmp(list->head->data.key, key) == 0) {
    LinkedListStringKey_PopFront(list);
  } else {
    // key not present in list: do nothing
  }
  return;
}

/**
 * ACHTUNG: O(n) and very inefficient. 
 * 
 * Just added this function to use this linked list type
 * for more complicated tasks as though it was a professional linked list type.
 * 
 * @param list
 */
void LinkedlistStringKey_DeleteTail(LinkedlistStringKeyT* list) {
  LinkedlistStringKey_DeleteKey(list, LinkedListStringKey_GetTail(list)->data.key);
  return;
}

/**
 * Traverses list until the next node matches the given key.
 * 
 * ACHTUNG: O(n) 
 * 
 * @param l_ptr
 * @param key
 * @return 
 */
ListNodeStringKeyIntValT* LinkedListStringKey_FindMatchPredecessor(
    LinkedlistStringKeyT* l_ptr, char* key) {  
  ListNodeStringKeyIntValT* curr = l_ptr->head;  
  while (curr && curr->next) {
    if (strcmp(curr->next->data.key, key) == 0) { return curr; }
    curr = curr->next;    
  }
  return NULL;
}


/**
 * Assuming elem is part of a list.
 * 
 * @param elem
 * @param new_val
 */
void LinkedListStringKey_UpdateElement(ListNodeStringKeyIntValT* elem, int new_val) {
  elem->data.val = new_val;
  return;
}

/**
 * Updates the first node found in the list that matches the key
 * 
 * @param l_ptr
 * @param key
 * @param val
 * @return 
 */
int LinkedListStringKey_UpdateValueOfKey(LinkedlistStringKeyT* l_ptr, 
        char* key, int new_val) {  
  ListNodeStringKeyIntValT* curr = l_ptr->head;
  int i_key = -1, count = 0;
  while (curr) {
    if (strcmp(curr->data.key, key) == 0) {
      i_key = count;
      curr->data.val = new_val;
      break;
    }
    ++count;
    curr = curr->next;
  }
  return i_key;
}

void LinkedListStringKey_PrintData(LinkedlistStringKeyT* list) {
  ListNodeStringKeyIntValT* current_node = list->head;
  int idx = 0;
  while (current_node != NULL && idx < list->n_nodes) {
    printf("Key at node with idx = %i : %s \n", idx, current_node->data.key);
    current_node = current_node->next;
    ++idx;
  }   
  printf("\n");    
  return;
}

//-------------------------------------------------------------- Algos