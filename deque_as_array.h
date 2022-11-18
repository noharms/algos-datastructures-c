/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   deque.h
 * Author: noh
 *
 * Created on July 17, 2019, 7:54 AM
 */

#ifndef DEQUE_H
#define DEQUE_H

#ifdef __cplusplus
extern "C" {
#endif
  
  #include <stdbool.h>
  
  typedef struct DEQUE_INT_ASARRAY_TYPE {
    int *arr;
    int capacity;
    int i_front;
    int i_back;
    int n_elems;
  } DequeIntAsArrayT;
  
  void MainDequeAsArray();
  
  void MainDequeAsArray_API();

  
  void DequeAsArrayOfInt_Enqueue(DequeIntAsArrayT* dq, int data);  
  void DequeAsArrayOfInt_Dequeue(DequeIntAsArrayT* dq);
  int DequeAsArrayOfInt_Front(DequeIntAsArrayT* dq);
  int DequeAsArrayOfInt_Back(DequeIntAsArrayT* dq);
  void DequeAsArrayOfInt_Inject(DequeIntAsArrayT* dq, const int data);
  void DequeAsArrayOfInt_Eject(DequeIntAsArrayT* dq);
  
  void DequeAsArrayOfInt_Init(DequeIntAsArrayT* dq);
  void DequeAsArrayOfInt_Destroy(DequeIntAsArrayT* dq);
  bool DequeAsArrayOfInt_Empty(DequeIntAsArrayT* dq);
  bool DequeAsArrayOfInt_Full(DequeIntAsArrayT* dq);
  void DequeAsArrayOfInt_Resize(DequeIntAsArrayT* dq);
  int DequeAsArrayOfInt_Length(DequeIntAsArrayT* dq);
  void DequeAsArrayOfInt_Print(DequeIntAsArrayT* dq);


#ifdef __cplusplus
}
#endif

#endif /* DEQUE_H */

