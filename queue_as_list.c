/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "queue_as_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist_as_nodes.h"


void MainQueueAsList() {
  printf("\n\n----------------------- MainQueueAsList \n");
  
  //-----------------------------------------
  // preparations:
  
  //-----------------------------------------
  // Exercises  
  
  MainQueueAsList_API();
    
  MainQueueAsList_APIWithMax();
    
  MainQueueAsList_BinaryTreeNodesAtSameLevel();
  
  return;
}




//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void MainQueueAsList_API() {  
  printf("\n----------------------------------- MainQueueAsList_API \n");  
  
  QueueAsListT queue_aslist = { NULL, NULL, 0};
  
  BTNodeT data_nodes[5] = { 0 };  
  data_nodes[0].key = 9;
  data_nodes[1].key = 2;
  data_nodes[2].key = 5;
  data_nodes[3].key = 4;
  data_nodes[4].key = 1;
  QueueNodeT q_nodes[5] = { 0 };
  int n_nodes = sizeof(q_nodes)/sizeof(QueueNodeT);
  int i;
  for (i = 0; i < n_nodes; ++i) {    
    q_nodes[i].data = &(data_nodes[i]);
  }
     
  // enqueue some nodes
  printf("\nWe insert nodes with data: 9, 2, 5, 1, 4 into the queue.\n");
  QueueAsListOfNodes_Enqueue(&queue_aslist, &q_nodes[0]); 
  QueueAsListOfNodes_Enqueue(&queue_aslist, &q_nodes[1]);
  QueueAsListOfNodes_Enqueue(&queue_aslist, &q_nodes[2]);
  QueueAsListOfNodes_Enqueue(&queue_aslist, &q_nodes[3]);
  QueueAsListOfNodes_Enqueue(&queue_aslist, &q_nodes[4]);
  printf("-> peek front of queue: %i .\n", 
          QueueAsListOfNodes_Front(&queue_aslist)->data->key);  
  
  // dequeue some nodes
  printf("\nWe dequeue three nodes.\n");
  QueueAsListOfNodes_Dequeue(&queue_aslist);
  QueueAsListOfNodes_Dequeue(&queue_aslist);
  QueueAsListOfNodes_Dequeue(&queue_aslist);    
  printf("-> peek front of queue: %i .\n", 
          QueueAsListOfNodes_Front(&queue_aslist)->data->key);
  
  return;
}

void MainQueueAsList_APIWithMax() {  
  printf("\n----------------------------------- MainQueueAsList_APIWithMax \n");  
  
  QueueAsListWithMaxT myq_withmax = { NULL, NULL, 0};
  
  QueueNodeT q_nodes[10] = { 0 };
  BTNodeT data_nodes[10] = { 0 };
  int n_nodes = sizeof(q_nodes)/sizeof(QueueNodeT);
  int i;
  for (i = 0; i < n_nodes; ++i) {
    data_nodes[i].key = i;
    q_nodes[i].data = &(data_nodes[i]);    
  }
  
  QueueNodeT q_nodes2[4] = { 0 };
  BTNodeT data_nodes2[4] = { 0 };
  int n_nodes2 = sizeof(q_nodes2)/sizeof(QueueNodeT);
  data_nodes2[0].key = 6;  
  data_nodes2[1].key = 7;
  data_nodes2[2].key = 8;
  data_nodes2[3].key = 3;
  for (i = 0; i < n_nodes2; ++i) {
    q_nodes2[i].data = &(data_nodes2[i]);    
  }
  
  // enqueue some nodes
  for (i = 0; i < n_nodes; ++i) {
    QueueAsListOfNodesWithMax_Enqueue(&myq_withmax, &(q_nodes[i])); 
    printf("Enqueued %i. New maximum in queue is: %i \n", q_nodes[i].data->key, 
          QueueAsListOfNodesWithMax_Max(&myq_withmax));
  }  
  for (i = 0; i < n_nodes2; ++i) {
    QueueAsListOfNodesWithMax_Enqueue(&myq_withmax, &(q_nodes2[i])); 
    printf("Enqueued %i. New maximum in queue is: %i \n", q_nodes2[i].data->key, 
          QueueAsListOfNodesWithMax_Max(&myq_withmax));
  }  
  printf("-> front of queue: %i .\n", 
          QueueAsListOfNodesWithMax_Front(&myq_withmax)->data->key);  
  printf("-> back of queue: %i .\n", 
          QueueAsListOfNodesWithMax_Back(&myq_withmax)->data->key);  
  
  // dequeue some nodes
  int n_dequeue_test = n_nodes + n_nodes2 - 1;  
  while (n_dequeue_test--) {    
    QueueAsListOfNodesWithMax_Dequeue(&myq_withmax);
    printf("Deque. New Max: %i \n", QueueAsListOfNodesWithMax_Max(&myq_withmax));    
  }
  if (!QueueAsListOfNodesWithMax_Empty(&myq_withmax)) {
    printf("-> front of queue: %i .\n",
          QueueAsListOfNodesWithMax_Front(&myq_withmax)->data->key);  
    printf("-> back of queue: %i .\n", 
          QueueAsListOfNodesWithMax_Back(&myq_withmax)->data->key);  
  }  
  
  return;
}

void MainQueueAsList_BinaryTreeNodesAtSameLevel() {  
  printf("\n----------------------------------- MainQueueAsList_BinaryTreeNodesAtSameLevel \n");  
  
  // construct a binary tree
  BTNodeT BTnode0 = { 0, -42, NULL, NULL };
  BTNodeT BTnode1 = { 1, -42, NULL, NULL };
  BTNodeT BTnode2 = { 2, -42, NULL, NULL };
  BTNodeT BTnode3 = { 3, -42, NULL, NULL };
  BTNodeT BTnode4 = { 4, -42, NULL, NULL };
  BTNodeT BTnode5 = { 5, -42, NULL, NULL };
  BTNodeT BTnode6 = { 6, -42, NULL, NULL };
  BTNodeT BTnode7 = { 7, -42, NULL, NULL };
  BTNodeT BTnode8 = { 8, -42, NULL, NULL };
  BTNodeT BTnode9 = { 9, -42, NULL, NULL };
  /*
   * test example:
   *                      0
   *                1          2
   *            3           4    5
   *        6              7
   *      8   9   
   */
  BTnode0.left = &BTnode1;
  BTnode0.rght = &BTnode2;
  BTnode1.left = &BTnode3;
  BTnode2.left = &BTnode4;
  BTnode2.rght = &BTnode5;
  BTnode3.left = &BTnode6;
  BTnode4.left = &BTnode7;
  BTnode6.left = &BTnode8;
  BTnode6.rght = &BTnode9;
  const int n_level_occupied = 5;
  
  BTNodeT*** BTnodes_per_level = calloc(n_level_occupied, sizeof(BTNodeT**));
  int i; 
  for (i = 0; i < n_level_occupied; ++i) {
    BTnodes_per_level[i] = calloc(1, sizeof(BTNodeT*));
  }
  
  // compute
  BinaryTreeNodesAtSameLevel(BTnodes_per_level, &BTnode0);
    
  // print result
  int j;
  for (i = 0; i < n_level_occupied; ++i) {
    printf("At level %i found following nodes: \n", i);
    j = 0;
    while (BTnodes_per_level[i][j]) {
      printf("node with data: %i \n", BTnodes_per_level[i][j]->key);
      ++j;
    }
  }
  printf("\n");
  
  // free  
  for (i = 0; i < n_level_occupied; ++i) {
    free(BTnodes_per_level[i]);
  }
  free(BTnodes_per_level);
  return;
}



//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//----------------------------------------- QUEUE AS LIST FUNCTIONS

/**
 * time complexity dequeue: O(1)
 * 
 * @param queue
 */
void QueueAsListOfNodes_Dequeue(QueueAsListT* q) {
  if (!QueueAsListOfNodes_Empty(q)) {    
    q->head = q->head->next; 
    --(q->n_nodes);
    // if no node is left, also tail must be unset
    if (q->n_nodes == 0) {
      q->tail = NULL;
    }
  }  
  return;
}

/**
 * To avoid having trouble of allocating memory dynamically for new_node without 
 * securing that it be freed again, we demand that the memory is
 * already allocated when calling this function.
 * 
 * Note: in a linked list implementation we have
 * 
 * time complexity enqueue: O(n)
 *  
 * @param data
 * @param queue
 * @param new_node
 */
void QueueAsListOfNodes_Enqueue(QueueAsListT* q, QueueNodeT* new_node) {
  if (QueueAsListOfNodes_Empty(q)) {
    q->head = new_node;
    q->tail = new_node;
    new_node->next = NULL;
  } else {    
    new_node->next = NULL;
    QueueNodeT* old_tail = q->tail;    
    old_tail->next = new_node;
    q->tail = new_node;
  }  
  ++(q->n_nodes);
  return;
}

QueueNodeT* QueueAsListOfNodes_Front(QueueAsListT* q) { 
  return (QueueAsListOfNodes_Empty(q) ? NULL : q->head);
}

QueueNodeT* QueueAsListOfNodes_Back(QueueAsListT* q) { 
  return (QueueAsListOfNodes_Empty(q) ? NULL : q->tail);
}

int QueueAsListOfNodes_Empty(QueueAsListT* q) {
  return (q->head == NULL ? true : false);
}


//------------------------ QUEUE AS LIST FUNCTIONS - WITH MAX BOOKKEEPING

void QueueAsListOfNodesWithMax_Init(QueueAsListWithMaxT* q) {
  DequeAsArrayOfInt_Init(&(q->max_bookkeeping));
  return;
}

void QueueAsListOfNodesWithMax_Destroy(QueueAsListWithMaxT* q) {
  DequeAsArrayOfInt_Destroy(&(q->max_bookkeeping));
  return;
}

int QueueAsListOfNodesWithMax_Max(QueueAsListWithMaxT* q) {
  return DequeAsArrayOfInt_Front(&(q->max_bookkeeping));
}

void QueueAsListOfNodesWithMax_Dequeue(QueueAsListWithMaxT* q) {
  if (!QueueAsListOfNodesWithMax_Empty(q)) {
    // update the max-bookkeeping first
    if (q->head->data->key == DequeAsArrayOfInt_Front(&(q->max_bookkeeping))) {
      DequeAsArrayOfInt_Dequeue(&(q->max_bookkeeping));
    }      
    // now the actual dequeue
    q->head = q->head->next; 
    --(q->n_nodes);
    // if no node is left, also tail must be unset
    if (q->n_nodes == 0) {
      q->tail = NULL;
    }
  }
  return;
}

void QueueAsListOfNodesWithMax_Enqueue(QueueAsListWithMaxT* q, QueueNodeT* new_node) {
  if (QueueAsListOfNodesWithMax_Empty(q)) {
    q->head = new_node;
    q->tail = new_node;
    new_node->next = NULL;
  } else {    
    new_node->next = NULL;
    QueueNodeT* old_tail = q->tail;    
    old_tail->next = new_node;
    q->tail = new_node;
  }
  ++(q->n_nodes);
  // update the max-bookkeeping
  while ( !DequeAsArrayOfInt_Empty(&(q->max_bookkeeping)) && 
          new_node->data->key > DequeAsArrayOfInt_Back(&(q->max_bookkeeping)) ) {
    DequeAsArrayOfInt_Eject(&(q->max_bookkeeping));
  }
  DequeAsArrayOfInt_Enqueue(&(q->max_bookkeeping), new_node->data->key);
  return;
}

QueueNodeT* QueueAsListOfNodesWithMax_Front(QueueAsListWithMaxT* q) { 
  return (QueueAsListOfNodesWithMax_Empty(q) ? NULL : q->head);
}

QueueNodeT* QueueAsListOfNodesWithMax_Back(QueueAsListWithMaxT* q) { 
  return (QueueAsListOfNodesWithMax_Empty(q) ? NULL : q->tail);
}

bool QueueAsListOfNodesWithMax_Empty(QueueAsListWithMaxT* q) {
  return (q->head == NULL ? true : false);
}


//------------------------------------------------------------------------------


#define MAX_NODES_ALLOWED 32
// ACHTUNG: assume not more than MAX_NODES_ALLOWED in level
// --> we have implemented the queue such that caller has to provide space
//     for queue nodes that he wants to enque
// --> this makes it difficult if an unknown number of queue-nodes can
//     be added to the queue
void BinaryTreeNodesAtSameLevel(BTNodeT*** BTnodes_per_level, BTNodeT* root) {
  
  // in our queue-list implementation the caller has to provide space for q-nodes
  QueueNodeT* q_nodes_curr_level = calloc(MAX_NODES_ALLOWED, sizeof(QueueNodeT));
  QueueNodeT* q_nodes_next_level = calloc(MAX_NODES_ALLOWED, sizeof(QueueNodeT));
  
  // set up queue
  QueueAsListT q_curr_level = { NULL, NULL, 0};
  QueueAsListT q_next_level = { NULL, NULL, 0};  
  // build initial prev_queue by enqueuing only root
  q_nodes_curr_level[0].data = root;
  QueueAsListOfNodes_Enqueue(&q_curr_level, &q_nodes_curr_level[0]);
  
  int count_node_curr_level = 0;
  int n_nodes_next_level = 0;
  int level = 0;
  while (!QueueAsListOfNodes_Empty(&q_curr_level)) {
    // queue of previous level is filled:
    // --> process all nodes in queue of previous level
    while (!QueueAsListOfNodes_Empty(&q_curr_level)) {
      // 0. cache front-node of prev_queue and dequeue it
      QueueNodeT tmp = *(QueueAsListOfNodes_Front(&q_curr_level)); // create local copy
      QueueAsListOfNodes_Dequeue(&q_curr_level);
      // 1. now store the nodes of prev_queue to result vector
      ++count_node_curr_level;
      BTnodes_per_level[level] = realloc(BTnodes_per_level[level], 
              (count_node_curr_level + 1) * sizeof(BTNodeT**));
      BTnodes_per_level[level][count_node_curr_level - 1] = tmp.data;
      BTnodes_per_level[level][count_node_curr_level] = NULL; // used as NULL-terminator signal by caller
      // 2. enqueue the children of nodes of prev_queue to curr_queue
      if (tmp.data->left) {
        ++n_nodes_next_level;
        q_nodes_next_level[n_nodes_next_level - 1].data = tmp.data->left;
        QueueAsListOfNodes_Enqueue(&q_next_level, &(q_nodes_next_level[n_nodes_next_level - 1]));
      }
      if (tmp.data->rght) {
        ++n_nodes_next_level;
        q_nodes_next_level[n_nodes_next_level - 1].data = tmp.data->rght;
        QueueAsListOfNodes_Enqueue(&q_next_level, &(q_nodes_next_level[n_nodes_next_level - 1]));
      }    
    }    
    // update
    ++level;
    q_curr_level = (QueueAsListT){ NULL, NULL, 0 };
    q_nodes_curr_level = calloc(n_nodes_next_level, sizeof(QueueNodeT));
    int i; 
    for (i = 0; i < n_nodes_next_level; ++i) {
      q_nodes_curr_level[i] = *QueueAsListOfNodes_Front(&q_next_level);
      QueueAsListOfNodes_Enqueue(&q_curr_level, &q_nodes_curr_level[i]);
      QueueAsListOfNodes_Dequeue(&q_next_level);              
    }
    count_node_curr_level = 0;
    n_nodes_next_level = 0;
    q_next_level = (QueueAsListT){ NULL, NULL, 0 };
  }

  // free
  free(q_nodes_curr_level);
  free(q_nodes_next_level);
  return;
}