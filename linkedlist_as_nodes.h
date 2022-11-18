/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   linkedlist.h
 * Author: noh
 *
 * Created on March 10, 2018, 4:20 PM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#ifdef __cplusplus
extern "C" {
#endif
  
  #include <stdbool.h>

  #include "standardheaders.h"

  /** Note: tracking the tail is not always possible (cyclic lists) so that 
   *        in this general implementation we do not include it.
   *        In special applications like a queue, however, cyclicity is excluded
   *        so that we can define a list with a tail pointer.
   */
  typedef struct LINKEDLIST {
    int n_nodes;
    ListNodeT* head;
    //ListNodeType* tail;
  } LinkedlistT;
  
  void MainLinkedlistAsNodes();
  
  void MainLinkedlist_LinkedListAPI();
  
  void MainLinkedlist_MergeTwoSortedLists();
  void MainLinkedlist_ReverseList();
  void MainLinkedlist_ReverseSubList();
  void MainLinkedlist_TestForOverlapNoCyclesAllowed();
  void MainLinkedlist_TestForOverlap();
  void MainLinkedlist_RemoveDuplicates();
  void MainLinkedlist_CyclicRightShiftByK();
  void MainLinkedlist_EvenOddSort();
  void MainLinkedlist_CheckPalindromic();
  void MainLinkedList_PivotPartitioning();
  void MainLinkedList_ListAdditionAsIntegers();

  //----------------------------------- LinkedList API: IntKey
  void LinkedList_PushFront(LinkedlistT* l_ptr, DataNodeIntKeyIntValT* new_datanode);
  void LinkedList_PopFront(LinkedlistT* list);  
  void LinkedList_InsertAfterNode(LinkedlistT* l_ptr, ListNodeT* predecessor, 
        DataNodeIntKeyIntValT* new_datanode);
  void LinkedList_DeleteAfterNode(LinkedlistT* l_ptr, ListNodeT* predecessor);
  
  ListNodeT* LinkedList_GetTail(LinkedlistT* l_ptr);
  void LinkedList_Init(LinkedlistT* l_ptr);
  void LinkedList_Destroy(LinkedlistT* list);
  void LinkedList_DeleteAtIndex(LinkedlistT* list, int i);
  void LinkedList_DeleteKthLast(LinkedlistT* l_ptr, int k);  
  void LinkedList_DeleteNodeFromList(ListNodeT* node);
  void LinkedList_MakeCyclicFromTailToIdx(const int restart_node_idx, 
          LinkedlistT* list);
  bool LinkedList_IsEmpty(LinkedlistT* list);  
  int LinkedList_PrintData(LinkedlistT* list);
  int LinkedList_ComputeLength(ListNodeT* node);  
  
  ListNodeT* LinkedList_MergeSort(ListNodeT* head);
  ListNodeT* LinkedList_FindMiddleNode(ListNodeT* head);
  ListNodeT* LinkedList_MergeTwoSortedListsIntoFirst(ListNodeT* head1, 
        ListNodeT* head2);
  
  int SortLinkedlist(LinkedlistT* list); // dumb old version 
  
  //--------------------------------------------------------
  // LinkedList API IntKey utilities  
  void PrintDataStartingFromNode(ListNodeT* node_ptr);
  int CopyDataFromListToArray(LinkedlistT* list, int arr[]);
  int ConvertArrayToList(int arr[], const int len, LinkedlistT* list);
  
  // LinkedList API IntKey - deprecated
  int InsertAtIndex(const int idx, ListNodeT* const new_node,
          LinkedlistT* linkedlist);
  int InsertAtEnd(ListNodeT* new_node,
          LinkedlistT* linkedlist);
  int InsertAfterNodeWithKey(const int key, LinkedlistT* list, 
          ListNodeT* new_node);
  ListNodeT* GetTail(ListNodeT* node);
  void DeletKthLastNode(LinkedlistT* list_ptr, int k);
  int DeleteTail(LinkedlistT* linkedlist);
  void AdvanceNodeBySteps(int n_steps, ListNodeT** node);
  bool IsCyclic(ListNodeT* node_ptr);
  int FindCycleLength(LinkedlistT* list);
  ListNodeT* FindFirstNodeOfCycle(ListNodeT* head, int* len_noncyclic);
    
  //----------------------------------------------- Exercises
  ListNodeT* ReverseLinkedList(ListNodeT* node_ptr);
  
  ListNodeT* ReverseSubList(const int i0, const int i1, ListNodeT* node_ptr);

  ListNodeT* GetMergeNodeNonCyclicLists(ListNodeT* node1, ListNodeT* node2);
  ListNodeT* GetMergeNodeNonCyclicLists_FirstTry(ListNodeT* node1, ListNodeT* node2);
  ListNodeT* GetMergeNode(ListNodeT* node1, ListNodeT* node2);

  void RemoveDuplicates(LinkedlistT* list_ptr);
  
  void EvenOddSort(LinkedlistT* list_ptr);
  
  ListNodeT* CyclicRightShiftByK(ListNodeT* head, int k);
  
  bool CheckPalindromic(ListNodeT* node);
  
  ListNodeT* PivotPartitioning(ListNodeT* node, const int pivot);
  
  ListNodeT* ListAdditionAsIntegers_InPlace(ListNodeT* node1, ListNodeT* node2);


#ifdef __cplusplus
}
#endif

#endif /* LINKEDLIST_H */

