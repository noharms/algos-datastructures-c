/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   queue.h
 * Author: noh
 *
 * Created on March 12, 2018, 11:53 AM
 */

#ifndef QUEUE_H
#define QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif
  
  #include <stdbool.h>

  
  #include "standardheaders.h"
  #include "deque_as_array.h"
  
  // queue as linked list of nodes with some data and pointer to next
  // Note: using BTNodeT here in order to allow solving a special exercise,
  // see BinaryTreeNodesAtSameLevel
  typedef struct QUEUE_NODE_TYPE {
    BTNodeT* data;
    struct QUEUE_NODE_TYPE* next;    
  } QueueNodeT;
  
  //------------------------------- standard queue
  typedef struct QUEUE_ASLIST_TYPE {
    QueueNodeT* head;
    QueueNodeT* tail;
    int n_nodes;
  } QueueAsListT;
  
  //------------------------------- queue with max-bookkeeping
  typedef struct QUEUE_ASLIST_WITHMAX_TYPE {
    QueueNodeT* head;
    QueueNodeT* tail;
    DequeIntAsArrayT max_bookkeeping;
    int n_nodes;
  } QueueAsListWithMaxT;
  
  
  void MainQueueAsList();
  
  void MainQueueAsList_API();
  void MainQueueAsList_APIWithMax();
  void MainQueueAsList_BinaryTreeNodesAtSameLevel();
  
  void QueueAsListOfNodes_Enqueue(QueueAsListT* q, QueueNodeT* new_node);
  void QueueAsListOfNodes_Dequeue(QueueAsListT* q);
  QueueNodeT* QueueAsListOfNodes_Front(QueueAsListT* q);  
  QueueNodeT* QueueAsListOfNodes_Back(QueueAsListT* q);  
  int QueueAsListOfNodes_Empty(QueueAsListT* q);  
  
  // allow separate API to not clutter up other functions  
  void QueueAsListOfNodesWithMax_Enqueue(QueueAsListWithMaxT* q, QueueNodeT* new_node);
  void QueueAsListOfNodesWithMax_Dequeue(QueueAsListWithMaxT* q);
  QueueNodeT* QueueAsListOfNodesWithMax_Front(QueueAsListWithMaxT* q);
  QueueNodeT* QueueAsListOfNodesWithMax_Back(QueueAsListWithMaxT* q);
  bool QueueAsListOfNodesWithMax_Empty(QueueAsListWithMaxT* q);
  void QueueAsListOfNodesWithMax_Init(QueueAsListWithMaxT* q);
  void QueueAsListOfNodesWithMax_Destroy(QueueAsListWithMaxT* q);  
  int QueueAsListOfNodesWithMax_Max(QueueAsListWithMaxT* q);
  
  // Exercises
  void BinaryTreeNodesAtSameLevel(BTNodeT*** BTnodes_per_level, BTNodeT* root);
  
  

#ifdef __cplusplus
}
#endif

#endif /* QUEUE_H */

