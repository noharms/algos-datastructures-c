/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "queue_as_2stacks.h"

#include <stdio.h>

void MainQueueAs2Stacks() {
  printf("\n\n----------------------- MainQueueAs2Stacks \n");
  
  //-----------------------------------------
  // preparations:
  
  //-----------------------------------------
  // Exercises  
  
  MainQueueAs2Stacks_API();
  
  return;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void MainQueueAs2Stacks_API() {
  printf("\n----------------------------------- MainQueueAs2Stacks_API \n"); 
  printf("\n");
  
  QueueIntAs2StacksT myq;
  QueueAs2StacksOfInt_Init(&myq);  
  printf("Queue is initialised.\n");
  if (QueueAs2StacksOfInt_Front(&myq)) {
    printf("-> front of queue: %i .\n", QueueAs2StacksOfInt_Front(&myq)->key);
  }
  if (QueueAs2StacksOfInt_Back(&myq)) {
    printf("-> back of queue: %i .\n", QueueAs2StacksOfInt_Back(&myq)->key);
  }  
  
     
  // Enqueue some elements
  int i;
  int sample[] = {1, 2, 5, 8, 10, 12, 13};
  int n_elems = sizeof(sample) / sizeof(int);
  printf("\nEnqueue the data: \n");
  for (i = 0; i < n_elems; ++i) {
    DataNodeIntKeyT tmp = { sample[i] };
    QueueAs2StacksOfInt_Enqueue(&myq, &tmp);
    printf("%i: %i \n", i, tmp.key);
  }  
  printf("-> front of queue: %i .\n", QueueAs2StacksOfInt_Front(&myq)->key);
  printf("-> back of queue: %i .\n", QueueAs2StacksOfInt_Back(&myq)->key);
  
  // Dequeue some elements
  int n_dequeue_test = 4;
  printf("\n Dequeue %i elements. \n", n_dequeue_test);
  while (n_dequeue_test--) {
    QueueAs2StacksOfInt_Dequeue(&myq);
  }
  printf("-> front of queue: %i .\n", QueueAs2StacksOfInt_Front(&myq)->key);
  printf("-> back of queue: %i .\n", QueueAs2StacksOfInt_Back(&myq)->key);
    
  // Enqueue some more elements
  int sample2[] = {3, 4, 7, 11, 21, 31, 41};
  int n_elems2 = sizeof(sample) / sizeof(int);
  printf("\nEnque the data: \n");
  for (i = 0; i < n_elems2; ++i) {
    DataNodeIntKeyT tmp = { sample2[i] };
    QueueAs2StacksOfInt_Enqueue(&myq, &tmp);
    printf("%i: %i \n", i, tmp.key);
  }
  printf("-> front of queue: %i .\n", QueueAs2StacksOfInt_Front(&myq)->key);
  printf("-> back of queue: %i .\n", QueueAs2StacksOfInt_Back(&myq)->key);
    
  QueueAs2StacksOfInt_Destroy(&myq);
  return;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void QueueAs2StacksOfInt_Init(QueueIntAs2StacksT* q) {
  StackAsArrayOfInt_Init(&(q->stack_enqueue));
  StackAsArrayOfInt_Init(&(q->stack_dequeue));
  return;
}

void QueueAs2StacksOfInt_Destroy(QueueIntAs2StacksT* q) {
  StackAsArrayOfInt_Destroy(&(q->stack_enqueue));
  StackAsArrayOfInt_Destroy(&(q->stack_dequeue));
  return;
}

/**
 * Assuming unlimited stack size.
 * 
 * @param q
 * @param new_node
 */
void QueueAs2StacksOfInt_Enqueue(QueueIntAs2StacksT* q, DataNodeIntKeyT* new_node) {
  StackAsArrayOfInt_Push(&(q->stack_enqueue), new_node);
  return;
}

void QueueAs2StacksOfInt_Dequeue(QueueIntAs2StacksT* q) {
  if (!StackAsArrayOfInt_Top(&(q->stack_dequeue))) { // dequeue-stack empty
    if (!StackAsArrayOfInt_Top(&(q->stack_enqueue))) { // enqueue-stack empty as well
      printf("Underflow Error: cannot dequeue. \n");
      return;
    } else { // transfer enqueue stack until empty
      QueueAs2StacksOfInt_StackTransfer(&(q->stack_dequeue), &(q->stack_enqueue));
    }
  }
  StackAsArrayOfInt_Pop(&(q->stack_dequeue));
  return;
}

void QueueAs2StacksOfInt_StackTransfer(StackIntT* dst, StackIntT* src) {
  while (StackAsArrayOfInt_Top(src)) {
    StackAsArrayOfInt_Push(dst, StackAsArrayOfInt_Top(src));
    StackAsArrayOfInt_Pop(src);
  }
  return;
}

/**
 * average time complexity: O(1)
 * worst-case time complexity: O(n) 
 * 
 * @param q
 * @return 
 */
DataNodeIntKeyT* QueueAs2StacksOfInt_Front(QueueIntAs2StacksT* q) {  
  if (!StackAsArrayOfInt_Top(&(q->stack_dequeue))) { // dequeue-stack empty
    if (!StackAsArrayOfInt_Top(&(q->stack_enqueue))) { // enqueue-stack empty as well
      printf("Queue is empty: no front element. \n");
      return NULL;
    } else { // transfer enqueue stack until empty
      QueueAs2StacksOfInt_StackTransfer(&(q->stack_dequeue), &(q->stack_enqueue));
    }
  }
  return StackAsArrayOfInt_Top(&(q->stack_dequeue));
}

/**
 * 
 * average time complexity: O(1)
 * worst-case time complexity: twice O(n) for 2 transfers
 * 
 * @param q
 * @return 
 */
DataNodeIntKeyT* QueueAs2StacksOfInt_Back(QueueIntAs2StacksT* q) {  
  if (!StackAsArrayOfInt_Top(&(q->stack_enqueue))) { // enqueue-stack empty
    if (!StackAsArrayOfInt_Top(&(q->stack_dequeue))) { // dequeue-stack empty as well
      printf("Queue is empty: no back element. \n");
      return NULL;
    } else { // back node is at bottom of dequeue: need transfer all elems to find it
      QueueAs2StacksOfInt_StackTransfer(&(q->stack_enqueue), &(q->stack_dequeue));
      DataNodeIntKeyT* back_node = StackAsArrayOfInt_Top(&(q->stack_enqueue));
      QueueAs2StacksOfInt_StackTransfer(&(q->stack_dequeue), &(q->stack_enqueue));
      return back_node;      
    }
  }
  return StackAsArrayOfInt_Top(&(q->stack_enqueue));
}