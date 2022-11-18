/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   queue_as_2stacks.h
 * Author: noh
 *
 * Created on July 16, 2019, 2:42 PM
 */

#ifndef QUEUE_AS_2STACKS_H
#define QUEUE_AS_2STACKS_H

#ifdef __cplusplus
extern "C" {
#endif
  
  #include "stack_as_array.h"
  
  typedef struct QUEUE_AS_2STACKS {
    StackIntT stack_enqueue;
    StackIntT stack_dequeue;
  } QueueIntAs2StacksT;

  void MainQueueAs2Stacks();
  
  void MainQueueAs2Stacks_API();
    
  void QueueAs2StacksOfInt_Enqueue(QueueIntAs2StacksT* q, DataNodeIntKeyT* new_node);
  void QueueAs2StacksOfInt_Dequeue(QueueIntAs2StacksT* q);
  void QueueAs2StacksOfInt_StackTransfer(StackIntT* dst, StackIntT* src);
  DataNodeIntKeyT* QueueAs2StacksOfInt_Front(QueueIntAs2StacksT* q);
  DataNodeIntKeyT* QueueAs2StacksOfInt_Back(QueueIntAs2StacksT* q);  
  
  void QueueAs2StacksOfInt_Init(QueueIntAs2StacksT* q);
  void QueueAs2StacksOfInt_Destroy(QueueIntAs2StacksT* q);


#ifdef __cplusplus
}
#endif

#endif /* QUEUE_AS_2STACKS_H */

