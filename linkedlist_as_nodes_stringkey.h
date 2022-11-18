/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   linkedlist_as_nodes_stringkey.h
 * Author: noh
 *
 * Created on July 29, 2019, 7:29 PM
 */

#ifndef LINKEDLIST_AS_NODES_STRINGKEY_H
#define LINKEDLIST_AS_NODES_STRINGKEY_H

#ifdef __cplusplus
extern "C" {
#endif

  #include "standardheaders.h"
  
  typedef struct LINKEDLIST_STRINGKEY {
    int n_nodes;
    ListNodeStringKeyIntValT* head;    
  } LinkedlistStringKeyT;
  
  
  void MainLinkedlistAsNodesStringKey();
  
  void MainLinkedlistAsNodesStringKey_API();

  //----------------------------------- LinkedList API: StringKey  
  void LinkedListStringKey_PushFront(LinkedlistStringKeyT* l_ptr, char* key, int val);
  void LinkedListStringKey_PushFront_CopyDataNode(LinkedlistStringKeyT* l_ptr, 
          DataNodeStringKeyIntValT* new_datanode);
  void LinkedListStringKey_PopFront(LinkedlistStringKeyT* list);  
  void LinkedListStringKey_InsertAfterNode(LinkedlistStringKeyT* l_ptr, 
          ListNodeStringKeyIntValT* predecessor, DataNodeStringKeyIntValT* new_datanode);
  void LinkedListStringKey_DeleteAfterNode(LinkedlistStringKeyT* l_ptr, 
          ListNodeStringKeyIntValT* predecessor);
  void LinkedListStringKey_DeleteNodeInO1(ListNodeStringKeyIntValT* node);  
  
  ListNodeStringKeyIntValT* LinkedListStringKey_FindMatch(
    LinkedlistStringKeyT* l_ptr, char* key);
  void LinkedListStringKey_UpdateElement(ListNodeStringKeyIntValT* elem, int new_val);
  int LinkedListStringKey_UpdateValueOfKey(LinkedlistStringKeyT* l_ptr, 
        char* key, int new_val);
  
  ListNodeStringKeyIntValT* LinkedListStringKey_GetTail(LinkedlistStringKeyT* list);
  void LinkedlistStringKey_DeleteKey(LinkedlistStringKeyT* list, char* key);
  void LinkedlistStringKey_DeleteTail(LinkedlistStringKeyT* list);
  ListNodeStringKeyIntValT* LinkedListStringKey_FindMatchPredecessor(
    LinkedlistStringKeyT* l_ptr, char* key);
  
  void LinkedListStringKey_Init(LinkedlistStringKeyT* list);
  void LinkedListStringKey_Destroy(LinkedlistStringKeyT* list);
  
  void LinkedListStringKey_PrintData(LinkedlistStringKeyT* list);

#ifdef __cplusplus
}
#endif

#endif /* LINKEDLIST_AS_NODES_STRINGKEY_H */

