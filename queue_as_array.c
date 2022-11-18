/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "queue_as_array.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "standardheaders.h"

void MainQueueAsArray() {
  printf("\n\n----------------------- MainQueueAsArray \n");
  
  //-----------------------------------------
  // preparations:
  
  //-----------------------------------------
  // Exercises  
  
  MainQueueAsArray_API();
  
  return;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void MainQueueAsArray_API() {
  printf("\n----------------------------------- MainQueueAsArray_API \n"); 
  
  QueueIntAsArrayT queue;
  QueueAsArrayOfInt_Init(&queue);
  
  // Enqueue some elements
  int i;
  int sample[] = {1, 2, 5, 8, 10, 12, 13};
  int n_elems = sizeof(sample) / sizeof(int);
  printf("\nEnqueue the data: \n");
  for (i = 0; i < n_elems; ++i) {
    QueueAsArrayOfInt_Enqueue(&queue, sample[i]);
    printf("%i: %i \n", i, sample[i]);
  }  
  printf("-> front of queue: %i .\n", QueueAsArrayOfInt_Front(&queue));
  printf("-> back of queue: %i .\n", QueueAsArrayOfInt_Back(&queue));
  
  // Dequeue some elements
  int n_dequeue_test = 4;
  printf("\n Dequeue %i elements. \n", n_dequeue_test);
  while (n_dequeue_test--) {
    QueueAsArrayOfInt_Dequeue(&queue);
  }
  printf("-> front of queue: %i .\n", QueueAsArrayOfInt_Front(&queue));
  printf("-> back of queue: %i .\n", QueueAsArrayOfInt_Back(&queue));
  
  // Enqueue some elements to test cyclicity  
  int sample2[] = {3, 4, 7, 11, 21, 31, 41};
  int n_elems2 = sizeof(sample) / sizeof(int);
  printf("\nEnque the data: \n");
  for (i = 0; i < n_elems2; ++i) {
    QueueAsArrayOfInt_Enqueue(&queue, sample2[i]);
    printf("%i: %i \n", i, sample2[i]);
  }
  printf("-> front of queue: %i .\n", QueueAsArrayOfInt_Front(&queue));
  printf("-> back of queue: %i .\n", QueueAsArrayOfInt_Back(&queue));
  
  QueueAsArrayOfInt_Destroy(&queue);
  return;
}



//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//----- QUEUE AS ARRAY FUNCTIONS

/**
 * Enforce resize before enqueue, if queue is full.
 * 
 * Very simple. Only need to take care if i_back reaches beyond last element.
 * 
 * @param q
 * @param data
 */
void QueueAsArrayOfInt_Enqueue(QueueIntAsArrayT* q, const int data) {
  if (QueueAsArrayOfInt_Full(q)) { QueueAsArrayOfInt_Resize(q); }
  q->i_back = (q->i_back + 1) % q->capacity;
  q->arr[q->i_back] = data;
  ++(q->n_elems);
  return;
}

/**
 * Very simple. Only need to take care if i_front reaches beyond last element.
 * 
 * @param q
 */
void QueueAsArrayOfInt_Dequeue(QueueIntAsArrayT* q) {
  if (QueueAsArrayOfInt_Empty(q)) { printf("Underflow Error: cannot dequeue. \n"); }
  else {
    q->i_front = (q->i_front + 1) % q->capacity;
    --(q->n_elems);
  }
  return;
}

// assume: checked before that it is not empty
int QueueAsArrayOfInt_Back(QueueIntAsArrayT* q) {
  return q->arr[q->i_back];
}

// assume: checked before that it is not empty
int QueueAsArrayOfInt_Front(QueueIntAsArrayT* q) {
  return q->arr[q->i_front];
}

#define INITIAL_CAPACITY 0
/**
 * Initialize the memory
 * 
 * @param q
 */
void QueueAsArrayOfInt_Init(QueueIntAsArrayT* q) {
  q->capacity = INITIAL_CAPACITY;
  q->arr = calloc(q->capacity, sizeof(int));
  q->i_front = 0;
  q->i_back = -1;
  q->n_elems = 0;
  return;
}

/**
 * free the memory
 * 
 * @param q
 */
void QueueAsArrayOfInt_Destroy(QueueIntAsArrayT* q) {
  free(q->arr);
  return;
}

/**
 * 
 * @param q
 * @return 
 */
int QueueAsArrayOfInt_Length(QueueIntAsArrayT* q) {
  return q->n_elems;
}

/**
 * Note: i_front == i_back means: only one element in queue
 * 
 * @param queue
 * @return 
 */
bool QueueAsArrayOfInt_Empty(QueueIntAsArrayT* q) {
  return (q->n_elems == 0 ? true : false);
}

/**
 * A cyclic queue is full if:
 * 
 *  - case i_front == 0: if i_back == last
 *  - case i_front != 0: if i_back == i_front - 1
 * 
 * @param queue
 * @return 
 */
bool QueueAsArrayOfInt_Full(QueueIntAsArrayT* q) {
  return (q->n_elems == q->capacity ? true : false);
}

/**
 * 
 * Idea: always double amount of allocated space
 * 
 * If i_back is a cycle ahead, we n
 * 
 * @param q
 */
void QueueAsArrayOfInt_Resize(QueueIntAsArrayT* q) {
  const int capacity_new = MAX(2*q->capacity, 1); // note: need 1 if 0 initially
  int* new_memory = calloc(capacity_new, sizeof(int));  
  if (q->i_front + q->n_elems - 1 <= q->capacity - 1) {
    memcpy(new_memory, q->arr + q->i_front, q->n_elems * sizeof(int));        
  } else { // case: so many elements that we have cyclic overlap    
    int n_elems_beforeend = (q->capacity - q->i_front);
    int n_elems_fromstart = (q->i_back + 1);
    memcpy(new_memory, q->arr + q->i_front, n_elems_beforeend * sizeof(int));
    memcpy(new_memory + n_elems_beforeend, q->arr, n_elems_fromstart * sizeof(int));        
  }
  free(q->arr);
  q->arr = new_memory;
  q->i_front = 0;
  q->i_back = q->n_elems - 1;
  q->capacity = capacity_new;  
  return;
}

// for debug
void QueueAsArrayOfInt_Print(QueueIntAsArrayT* q) {
  int i, count;  
  if (q->i_front + q->n_elems > q->capacity) {    
    for (i = q->i_front; i < q->capacity; ++i) {      
      printf("Queue elem %i is: %i \n", count++, q->arr[i]);      
    }
    for (i = 0; i <= q->i_back; ++i) {      
      printf("Queue elem %i is: %i \n", count++, q->arr[i]);      
    }    
  } else {
    for (i = q->i_front; i <= q->i_back; ++i) {
      printf("Queue elem %i is: %i \n", count++, q->arr[i]);
    }
  }
  return;
}