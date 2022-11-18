/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "stack_as_list.h"

#include <stdio.h>
#include <stdlib.h>


void MainStackAsList() {
  printf("\n\n----------------------- MainStackAsList \n");
  
  //-----------------------------------------
  // preparations:
  
  //-----------------------------------------
  // Exercises  
  
  MainStackAsList_StackAPI();
  
  
  return;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void MainStackAsList_StackAPI() {  
  printf("\n----------------------------------- MainStackAsList_StackAPI \n");  
    
  LinkedlistT stack_aslist = { 0, NULL};
    
  printf("\nWe add nodes with data: 9, 2, 5, 1, 4 to list. \n");
  StackAsListOfNodes_Push(9, &stack_aslist);
  StackAsListOfNodes_Push(2, &stack_aslist);
  StackAsListOfNodes_Push(5, &stack_aslist);
  StackAsListOfNodes_Push(1, &stack_aslist);
  StackAsListOfNodes_Push(4, &stack_aslist);
  printf("-> peek on stack: %i .\n", StackAsListOfNodes_Top(&stack_aslist));
  
  printf("\nWe pop three nodes.\n");
  StackAsListOfNodes_Pop(&stack_aslist);
  StackAsListOfNodes_Pop(&stack_aslist);
  StackAsListOfNodes_Pop(&stack_aslist);    
  printf("-> peek on stack: %i .\n", StackAsListOfNodes_Top(&stack_aslist));
  
  StackAsListOfNodes_Destroy(&stack_aslist);
  return;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


/**
 * To avoid having trouble of allocating memory dynamically without 
 * securing that it be freed again, we demand that the memory is
 * already allocated when calling this function.
 * 
 * Note: implemented stack using list-head as top of stack
 *       --> is advantageous over using list-tail for push/pop operations
 * 
 * @param data_item
 * @param stack
 * @param new_node
 */
void StackAsListOfNodes_Push(const int new_key, LinkedlistT* stack) {  
  ListNodeT* new_mem = calloc(1, sizeof(ListNodeT));
  new_mem->data.key = new_key;
  new_mem->next = stack->head;
  stack->head = new_mem;
  ++(stack->n_nodes);  
  return;
}

int StackAsListOfNodes_Top(LinkedlistT* stack) {  
  return stack->head->data.key;
}

/**
 * Note: since we are using list-head as top of stack the removal
 *       is O(1) 
 *       --> when using list-tail the removal would be O(n) !!!
 * 
 * @param stack
 */
void StackAsListOfNodes_Pop(LinkedlistT* stack) {
  stack->head = stack->head->next;
  stack->n_nodes--;
  return;          
}

void StackAsListOfNodes_Destroy(LinkedlistT* stack) {  
  ListNodeT* curr = stack->head;  
  while (curr) {
    ListNodeT* next = curr->next;
    free(curr);
    curr = next;
    --(stack->n_nodes);
  }
}