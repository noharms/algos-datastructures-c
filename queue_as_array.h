/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   queue_as_array.h
 * Author: noh
 *
 * Created on July 16, 2019, 8:00 AM
 */

#ifndef QUEUE_AS_ARRAY_H
#define QUEUE_AS_ARRAY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
   
  typedef struct QUEUE_AS_ARR {
    int* arr;
    int capacity;    
    int i_front;
    int i_back;
    int n_elems; // essential to allow cyclic usage of arr!
  } QueueIntAsArrayT;
    
  void MainQueueAsArray();
  
  void MainQueueAsArray_API();
  
  void QueueAsArrayOfInt_Enqueue(QueueIntAsArrayT* queue, int data);  
  void QueueAsArrayOfInt_Dequeue(QueueIntAsArrayT* queue);
  int QueueAsArrayOfInt_Front(QueueIntAsArrayT* queue);
  int QueueAsArrayOfInt_Back(QueueIntAsArrayT* queue);
  
  void QueueAsArrayOfInt_Init(QueueIntAsArrayT* q);
  void QueueAsArrayOfInt_Destroy(QueueIntAsArrayT* q);
  bool QueueAsArrayOfInt_Empty(QueueIntAsArrayT* queue);
  bool QueueAsArrayOfInt_Full(QueueIntAsArrayT* queue);
  void QueueAsArrayOfInt_Resize(QueueIntAsArrayT* queue);
  int QueueAsArrayOfInt_Length(QueueIntAsArrayT* queue);
  void QueueAsArrayOfInt_Print(QueueIntAsArrayT* queue);



#ifdef __cplusplus
}
#endif

#endif /* QUEUE_AS_ARRAY_H */

