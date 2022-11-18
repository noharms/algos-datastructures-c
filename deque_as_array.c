/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "deque_as_array.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "standardheaders.h"

void MainDequeAsArray() {
  printf("\n\n----------------------- MainDequeAsArray \n");
  
  //-----------------------------------------
  // preparations:
  
  //-----------------------------------------
  // Exercises  
  
  MainDequeAsArray_API();
    
  return;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void MainDequeAsArray_API() {
  printf("\n----------------------------------- MainDequeAsArray_API \n");
  
  DequeIntAsArrayT deque;
  DequeAsArrayOfInt_Init(&deque);
  
  // Inject some elements
  int i;
  int sample[] = {1, 2, 5, 8, 10, 12, 13};
  int n_elems = sizeof(sample) / sizeof(int);
  printf("\nInject the data: \n");
  for (i = 0; i < n_elems; ++i) {
    DequeAsArrayOfInt_Inject(&deque, sample[i]);
    printf("%i: %i \n", i, sample[i]);
  }  
  printf("-> front of queue: %i .\n", DequeAsArrayOfInt_Front(&deque));
  printf("-> back of queue: %i .\n", DequeAsArrayOfInt_Back(&deque));
  
  // Dequeue some elements
  int n_dequeue_test = 3;
  printf("\n Dequeue %i elements. \n", n_dequeue_test);
  while (n_dequeue_test--) {
    DequeAsArrayOfInt_Dequeue(&deque);
  }
  printf("-> front of queue: %i .\n", DequeAsArrayOfInt_Front(&deque));
  printf("-> back of queue: %i .\n", DequeAsArrayOfInt_Back(&deque));
    
  // Eject some elements
  int n_eject_test = 3;
  printf("\n Eject %i elements. \n", n_eject_test);
  while (n_eject_test--) {
    DequeAsArrayOfInt_Eject(&deque);
  }
  printf("-> front of queue: %i .\n", DequeAsArrayOfInt_Front(&deque));
  printf("-> back of queue: %i .\n", DequeAsArrayOfInt_Back(&deque));
  
  // Enqueue some elements to test cyclicity  
  int sample2[] = {3, 4, 7, 11, 21, 31, 41};
  int n_elems2 = sizeof(sample) / sizeof(int);
  printf("\nEnque the data: \n");
  for (i = 0; i < n_elems2; ++i) {
    DequeAsArrayOfInt_Enqueue(&deque, sample2[i]);
    printf("%i: %i \n", i, sample2[i]);
  }
  printf("-> front of queue: %i .\n", DequeAsArrayOfInt_Front(&deque));
  printf("-> back of queue: %i .\n", DequeAsArrayOfInt_Back(&deque));
  
  DequeAsArrayOfInt_Destroy(&deque);
  return;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//----- DEQUEUE AS ARRAY FUNCTIONS


/**
 * 
 * note: the modulo operation only changes the value if i_front = -1, otherwise
 *       i_front stays unchanged since it is < q->capacity 
 * 
 * @param q
 * @param data
 */
void DequeAsArrayOfInt_Inject(DequeIntAsArrayT* dq, const int data) {
  if (DequeAsArrayOfInt_Full(dq)) { 
    DequeAsArrayOfInt_Resize(dq);
  }
  dq->i_front = (dq->i_front - 1 + dq->capacity) % dq->capacity;
  dq->arr[dq->i_front] = data;
  ++(dq->n_elems);
  return;
}

void DequeAsArrayOfInt_Eject(DequeIntAsArrayT* dq) {
  if (DequeAsArrayOfInt_Empty(dq)) { 
    printf("Underflow Error: Cannot Eject since deque empty.\n");    
  } else {
    dq->i_back = (dq->i_back - 1 + dq->capacity) % dq->capacity;   
    --(dq->n_elems); 
  }
  return;
}



/**
 * Enforce resize before enqueue, if queue is full.
 * 
 * Very simple. Only need to take care if i_back reaches beyond last element.
 * 
 * @param q
 * @param data
 */
void DequeAsArrayOfInt_Enqueue(DequeIntAsArrayT* dq, const int data) {
  if (DequeAsArrayOfInt_Full(dq)) {
    DequeAsArrayOfInt_Resize(dq);
  }
  dq->i_back = (dq->i_back + 1) % dq->capacity;
  dq->arr[dq->i_back] = data;
  ++(dq->n_elems);
  return;
}

/**
 * Very simple. Only need to take care if i_front reaches beyond last element.
 * 
 * @param q
 */
void DequeAsArrayOfInt_Dequeue(DequeIntAsArrayT* dq) {
  if (DequeAsArrayOfInt_Empty(dq)) {
    printf("Underflow Error: cannot dequeue. \n"); 
  }
  else {
    dq->i_front = (dq->i_front + 1) % dq->capacity;
    --(dq->n_elems);
  }
  return;
}

// assume: checked before that it is not empty
int DequeAsArrayOfInt_Back(DequeIntAsArrayT* dq) {
  return dq->arr[dq->i_back];
}

// assume: checked before that it is not empty
int DequeAsArrayOfInt_Front(DequeIntAsArrayT* dq) {
  return dq->arr[dq->i_front];
}

#define INITIAL_CAPACITY 0
/**
 * Initialize the memory
 * 
 * @param q
 */
void DequeAsArrayOfInt_Init(DequeIntAsArrayT* dq) {
  dq->capacity = INITIAL_CAPACITY;
  dq->arr = calloc(dq->capacity, sizeof(int));
  dq->i_front = 0;
  dq->i_back = -1;
  dq->n_elems = 0;
  return;
}

/**
 * free the memory
 * 
 * @param q
 */
void DequeAsArrayOfInt_Destroy(DequeIntAsArrayT* dq) {
  free(dq->arr);
  return;
}

/**
 * 
 * @param q
 * @return 
 */
int DequeAsArrayOfInt_Length(DequeIntAsArrayT* dq) {
  return dq->n_elems;
}

/**
 * Note: i_front == i_back means: only one element in queue
 * 
 * @param queue
 * @return 
 */
bool DequeAsArrayOfInt_Empty(DequeIntAsArrayT* dq) {
  return (dq->n_elems == 0 ? true : false);
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
bool DequeAsArrayOfInt_Full(DequeIntAsArrayT* dq) {
  return (dq->n_elems == dq->capacity ? true : false);
}

/**
 * 
 * Idea: always double amount of allocated space
 * 
 * If i_back is a cycle ahead, we n
 * 
 * @param q
 */
void DequeAsArrayOfInt_Resize(DequeIntAsArrayT* dq) {
  const int capacity_new = MAX(2*dq->capacity, 1); // note: need 1 if 0 initially
  int* new_memory = calloc(capacity_new, sizeof(int));  
  if (dq->i_front + dq->n_elems - 1 <= dq->capacity - 1) {
    memcpy(new_memory, dq->arr + dq->i_front, dq->n_elems * sizeof(int));        
  } else { // case: so many elements that we have cyclic overlap    
    int n_elems_beforeend = (dq->capacity - dq->i_front);
    int n_elems_fromstart = (dq->i_back + 1);
    memcpy(new_memory, dq->arr + dq->i_front, n_elems_beforeend * sizeof(int));
    memcpy(new_memory + n_elems_beforeend, dq->arr, n_elems_fromstart * sizeof(int));        
  }
  free(dq->arr);
  dq->arr = new_memory;
  dq->i_front = 0;
  dq->i_back = dq->n_elems - 1;
  dq->capacity = capacity_new;  
  return;
}

// for debug
void DequeAsArrayOfInt_Print(DequeIntAsArrayT* dq) {
  int i, count;  
  if (dq->i_front + dq->n_elems > dq->capacity) {    
    for (i = dq->i_front; i < dq->capacity; ++i) {      
      printf("Queue elem %i is: %i \n", count++, dq->arr[i]);      
    }
    for (i = 0; i <= dq->i_back; ++i) {      
      printf("Queue elem %i is: %i \n", count++, dq->arr[i]);      
    }    
  } else {
    for (i = dq->i_front; i <= dq->i_back; ++i) {
      printf("Queue elem %i is: %i \n", count++, dq->arr[i]);
    }
  }
  return;
}