/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stack.h
 * Author: noh
 *
 * Created on March 12, 2018, 11:06 AM
 */

#ifndef STACK_H
#define STACK_H

#ifdef __cplusplus
extern "C" {
#endif

  
  #include "standardheaders.h"
  #include "linkedlist_as_nodes.h"
  
  void MainStackAsList();

  void MainStackAsList_StackAPI();

  void StackAsListOfNodes_Push(const int new_key, LinkedlistT* stack);
  void StackAsListOfNodes_Pop(LinkedlistT* stack);
  int StackAsListOfNodes_Top(LinkedlistT* stack);
  void StackAsListOfNodes_Destroy(LinkedlistT* stack);

#ifdef __cplusplus
}
#endif

#endif /* STACK_H */

