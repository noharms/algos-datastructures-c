/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "linkedlist_as_nodes.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "arrays.h"
#include "sorting_algos.h"


static DataNodeIntKeyIntValT node1 = { 4, -42 };
static DataNodeIntKeyIntValT node2 = { 1, -42 };
static DataNodeIntKeyIntValT node3 = { 6, -42 };
static DataNodeIntKeyIntValT node4 = { 11, -42 };
static DataNodeIntKeyIntValT node5 = { 2, -42 };
static DataNodeIntKeyIntValT node6 = { 3, -42 };
static DataNodeIntKeyIntValT node7 = { 13, -42 };
static DataNodeIntKeyIntValT node8 = { 14, -42 };

// helper to allow to start fresh with nodes in different excercises
static void ResetAllNodes() {
  node1 = (DataNodeIntKeyIntValT) { 4, -42 };
  node2 = (DataNodeIntKeyIntValT) { 1, -42 };
  node3 = (DataNodeIntKeyIntValT) { 6, -42 };
  node4 = (DataNodeIntKeyIntValT) { 11, -42 };
  node5 = (DataNodeIntKeyIntValT) { 2, -42 };
  node6 = (DataNodeIntKeyIntValT) { 3, -42 };
  node7 = (DataNodeIntKeyIntValT) { 13, -42 };
  node8 = (DataNodeIntKeyIntValT) { 14, -42 };
}  


void MainLinkedlistAsNodes() {  
  printf("\n\n----------------------- MainLinkedlist \n");
  
  //-----------------------------------------
  // preparations:
  
  srand(time(NULL)); // seed for random numbers
  
  //-----------------------------------------
  // Exercises  
  
  MainLinkedlist_LinkedListAPI();
    
  MainLinkedlist_MergeTwoSortedLists();
  
/*
  MainLinkedlist_ReverseList();
  
  MainLinkedlist_ReverseSubList();
    
  MainLinkedlist_TestForOverlapNoCyclesAllowed();
    
  MainLinkedlist_TestForOverlap();
  
  MainLinkedlist_RemoveDuplicates();
  
  MainLinkedlist_CyclicRightShiftByK();
  
  MainLinkedlist_EvenOddSort();
  
  MainLinkedlist_CheckPalindromic();
  
  MainLinkedList_PivotPartitioning();
*/
  
  // ACHTUNG: commented out because currently leads to memory leak !
  // ---> BUGFIX needed to properly merge the lists for clean destroy
  //MainLinkedList_ListAdditionAsIntegers();
      
  return;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


void MainLinkedlist_LinkedListAPI() {  
  printf("\n----------------------------------- MainLinkedlist_LinkedListAPI \n");
  // create a linked list
  LinkedlistT l;  
  LinkedlistT *l_ptr = &l;
  LinkedList_Init(l_ptr);
  
  // Insert 3 nodes at the front
  printf("Check list: use Push-API to insert 4 nodes: \n");
  LinkedList_PushFront(l_ptr, &node1);
  LinkedList_PushFront(l_ptr, &node2);
  LinkedList_PushFront(l_ptr, &node3);
  LinkedList_PushFront(l_ptr, &node4);
  LinkedList_PushFront(l_ptr, &node5);
  LinkedList_PrintData(l_ptr);
    
  // Delete given node
  int delete_idx = 1;
  printf("Check list: delete node at index %i \n", delete_idx);
  LinkedList_DeleteAtIndex(l_ptr, delete_idx); 
  LinkedList_PrintData(l_ptr);
  
  // Delete node after head
  LinkedList_DeleteAfterNode(l_ptr, l_ptr->head);  
  printf("Check list: deleted node after head \n");  
  LinkedList_PrintData(l_ptr);
  
  // delete k-th last node
  int k = 3;
  printf("Check list: delete %i-th last node \n", k);
  LinkedList_DeleteKthLast(l_ptr, k);  
  LinkedList_PrintData(l_ptr);
      
  // add nodes to the list at the end
  printf("Check list: after 3 times InsertAfterTail: \n");  
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node5);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node6);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node3);
  LinkedList_PrintData(l_ptr);
  
  // make list cyclic
  const int tail_to_node = 3;
  printf("Check list: make list cyclic from tail to index %i: \n", tail_to_node); 
  LinkedList_MakeCyclicFromTailToIdx(tail_to_node, l_ptr);
  printf("List is %s cyclic.\n\n", (IsCyclic(l_ptr->head) ? "" : "not"));
  LinkedList_PrintData(l_ptr);
    
  // find first node of cyclic sublist
  printf("Check method to find first node of cycle: \n");    
  int len_noncyclic = 0;
  ListNodeT* CyclicSubListStartNode = FindFirstNodeOfCycle( 
          l.head, &len_noncyclic);
  printf("The cycle starts at node with value %i \n", CyclicSubListStartNode->data.key);
  
  ResetAllNodes();
  LinkedList_Destroy(l_ptr);
  return;  
}


void MainLinkedlist_MergeTwoSortedLists() {
  printf("\n----------------------------------- MainLinkedlist_MergeTwoSortedLists \n");
  //--- create 2 linked lists
  // create an array of nodes, and array of data, and create linked list
#define ARR_LEN 5
  int i;
  int arr1[ARR_LEN];
  int arr2[ARR_LEN];
  for( i = 0; i<ARR_LEN; ++i) {
    arr1[i] = rand() % MAX_RAND_NUM;
    arr2[i] = rand() % MAX_RAND_NUM;
  }
  //PrintAllElements(ARR_LEN, arr1);
  //PrintAllElements(ARR_LEN, arr2);  
  LinkedlistT sortedList1 = {0}; 
  LinkedList_Init(&sortedList1);  
  LinkedlistT sortedList2 = {0}; 
  LinkedList_Init(&sortedList2);    
  ConvertArrayToList(arr1, ARR_LEN, &sortedList1);
  ConvertArrayToList(arr2, ARR_LEN, &sortedList2);
  
  // print all elements
  //PrintAllDataInList(&sortedList1);
  //PrintAllDataInList(&sortedList2);
  
  //----- sort the lists
  SortLinkedlist(&sortedList1); // note: old mem is freed, new allocated
  SortLinkedlist(&sortedList2);
  LinkedList_PrintData(&sortedList1);
  LinkedList_PrintData(&sortedList2);
    
  //----- Merge two sorted lists to one
  ListNodeT* new_head = 
          LinkedList_MergeTwoSortedListsIntoFirst(sortedList1.head, 
          sortedList2.head);  
  // update lists  
  sortedList1.head = new_head;
  sortedList1.n_nodes = sortedList1.n_nodes + sortedList2.n_nodes;  
  sortedList2.head = NULL;    
  sortedList2.n_nodes = 0;    
  
  printf("Data in list1 after merge: \n");
  LinkedList_PrintData(&sortedList1);
  printf("Data in list2 after merge: \n");
  LinkedList_PrintData(&sortedList2);
 
  LinkedList_Destroy(&sortedList1);
  LinkedList_Destroy(&sortedList2);
  return;
}

void MainLinkedlist_ReverseList() {  
  printf("\n----------------------------------- MainLinkedlist_ReverseList \n");
  
  // create a linked list
  LinkedlistT ll;
  LinkedlistT *l_ptr = &ll;
  LinkedList_Init(l_ptr);
  LinkedList_PushFront(l_ptr, &node1);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node2);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node3);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node4);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node5);
  LinkedList_PrintData(l_ptr);
  
  // Reverse List
  ListNodeT* new_head = ReverseLinkedList(l_ptr->head);
  PrintDataStartingFromNode(new_head); 
    
  ResetAllNodes();
  LinkedList_Destroy(l_ptr);
  return;
}
  
void MainLinkedlist_ReverseSubList() { 
  printf("\n----------------------------------- MainLinkedlist_ReverseSubList \n");
  
  // create a linked list
  LinkedlistT ll;
  LinkedlistT *l_ptr = &ll;
  LinkedList_Init(l_ptr);
  LinkedList_PushFront(l_ptr, &node1);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node2);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node3);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node4);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node5);
  LinkedList_PrintData(l_ptr);
  
  // Reverse Sub List
  //ReverseSubList_FirstTry(2, 4, list_ptr->head); 
  //PrintAllDataInList(list_ptr);
  const int idx_from = 0;
  const int idx_to = 3;
  printf("Reversing sublist from idx = %i to %i \n", idx_from, idx_to);
  ListNodeT* new_head = ReverseSubList(idx_from, idx_to, l_ptr->head);
  PrintDataStartingFromNode(new_head); 
  
  ResetAllNodes();
  LinkedList_Destroy(l_ptr);
  return;
}

void MainLinkedlist_TestForOverlapNoCyclesAllowed() {  
  printf("\n----------------------------------- MainLinkedlist_TestForOverlapNoCyclesAllowed \n");
  
  // create 2 linked lists  
  LinkedlistT ll;
  LinkedlistT *l_ptr = &ll;
  LinkedList_Init(l_ptr);
  LinkedList_PushFront(l_ptr, &node1);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node2);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node3);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node4);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node5);
  printf("List1: \n");
  LinkedList_PrintData(l_ptr);
    
  LinkedlistT ll2;
  LinkedlistT *l_ptr2 = &ll2;
  LinkedList_Init(l_ptr2);
  LinkedList_PushFront(l_ptr2, &node6);
  LinkedList_InsertAfterNode(l_ptr2, LinkedList_GetTail(l_ptr2), &node7);
  LinkedList_InsertAfterNode(l_ptr2, LinkedList_GetTail(l_ptr2), &node8);
  LinkedList_InsertAfterNode(l_ptr2, LinkedList_GetTail(l_ptr2), &node3);
  printf("List2: \n");
  LinkedList_PrintData(l_ptr2);
  
  // check for overlap
  ListNodeT* overlap_node = GetMergeNodeNonCyclicLists(l_ptr->head, l_ptr2->head);
  //ListListNodeType* overlap_node = FirstOverlapNodeNonCyclicLists_FirstTry(list_ptr->head, list_ptr2->head);
  printf("Overlap sublist: \n");
  PrintDataStartingFromNode(overlap_node);
  
  ResetAllNodes();
  LinkedList_Destroy(l_ptr);
  LinkedList_Destroy(l_ptr2);
  return;
}


void MainLinkedlist_TestForOverlap() {  
  printf("\n----------------------------------- MainLinkedlist_TestForOverlap \n");
    
  // create 2 linked lists    
  LinkedlistT ll;
  LinkedlistT *l_ptr = &ll;
  LinkedList_Init(l_ptr);
  LinkedList_PushFront(l_ptr, &node1);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node2);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node3);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node4);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node5);
  const int cycle_start_idx = 3; 
  LinkedList_MakeCyclicFromTailToIdx(cycle_start_idx, &ll);
  printf("List1: \n");
  LinkedList_PrintData(l_ptr);
  
  LinkedlistT ll2;
  LinkedlistT *l_ptr2 = &ll2;
  LinkedList_Init(l_ptr2);
  LinkedList_PushFront(l_ptr2, &node6);
  LinkedList_InsertAfterNode(l_ptr2, LinkedList_GetTail(l_ptr2), &node7);
  LinkedList_InsertAfterNode(l_ptr2, LinkedList_GetTail(l_ptr2), &node8);
  LinkedList_InsertAfterNode(l_ptr2, LinkedList_GetTail(l_ptr2), &node3);
  printf("List2: \n");
  LinkedList_PrintData(l_ptr2);
  
  // check for overlap
  ListNodeT* overlap_node = GetMergeNode(l_ptr->head, l_ptr2->head);  
  printf("Overlap sublist: \n");
  PrintDataStartingFromNode(overlap_node);
  
  ResetAllNodes();
  LinkedList_Destroy(l_ptr);
  LinkedList_Destroy(l_ptr2);
  return;
}

void MainLinkedlist_RemoveDuplicates() {
  printf("\n----------------------------------- MainLinkedlist_RemoveDuplicates \n");
  
  // create linked list
  LinkedlistT ll;
  LinkedlistT *l_ptr = &ll;
  LinkedList_Init(l_ptr);  
  LinkedList_PushFront(l_ptr, &node1);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node2);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node3);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node4);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node5);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node6);
  node2.key = node1.key;
  node4.key = node3.key;
  node5.key = node3.key;
  LinkedList_PrintData(l_ptr);
  
  // remove duplicates
  RemoveDuplicates(l_ptr);
  LinkedList_PrintData(l_ptr);
  
  ResetAllNodes();
  LinkedList_Destroy(l_ptr);
  return;
}


void MainLinkedlist_CyclicRightShiftByK() {
  printf("\n----------------------------------- MainLinkedlist_CyclicRightShiftByK \n");
  
  // create linked list
  LinkedlistT ll;
  LinkedlistT *l_ptr = &ll;
  LinkedList_Init(l_ptr);  
  LinkedList_PushFront(l_ptr, &node1);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node2);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node3);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node4);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node5);
  LinkedList_PrintData(l_ptr);
  
  // Cyclic right shift  
  const int k = 5;
  ListNodeT* new_head = CyclicRightShiftByK(l_ptr->head, k);
  l_ptr->head = new_head;
  printf("List after shift by k = %i \n", k);
  LinkedList_PrintData(l_ptr);
  
  ResetAllNodes();
  LinkedList_Destroy(l_ptr);
  return;
}

void MainLinkedlist_EvenOddSort() {
  printf("\n----------------------------------- MainLinkedlist_EvenOddSort \n");
  
  // create linked list
  LinkedlistT ll;
  LinkedlistT *l_ptr = &ll;
  LinkedList_Init(l_ptr);
  LinkedList_PushFront(l_ptr, &node1);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node2);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node3);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node4);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node5);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node6);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node7);
  LinkedList_PrintData(l_ptr);
  
  // EvenOddSort
  EvenOddSort(l_ptr);
  LinkedList_PrintData(l_ptr);
  
  ResetAllNodes();
  LinkedList_Destroy(l_ptr);
  return;
}

void MainLinkedlist_CheckPalindromic() {
  printf("\n----------------------------------- MainLinkedlist_CheckPalindromic \n");

  // create linked list
  LinkedlistT ll;
  LinkedlistT *l_ptr = &ll;
  LinkedList_Init(l_ptr);
  LinkedList_PushFront(l_ptr, &node1);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node2);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node3);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node4);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node5);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node6);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node7);
  node5.key = node3.key;
  node6.key = node2.key;
  node7.key = node1.key;
  LinkedList_PrintData(l_ptr);
  
  // Check palindromic
  bool is_palindromic = CheckPalindromic(l_ptr->head);
  printf("List was tested to be%s palindromic \n", (is_palindromic ? "" : " not"));
  
  ResetAllNodes();  
  LinkedList_Destroy(l_ptr);
  return;
}

void MainLinkedList_PivotPartitioning() {
  printf("\n----------------------------------- MainLinkedList_PivotPartitioning \n");

  // create linked list
  LinkedlistT ll;
  LinkedlistT *l_ptr = &ll;
  LinkedList_Init(l_ptr);
  LinkedList_PushFront(l_ptr, &node1);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node2);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node3);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node4);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node5);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node6);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node7);
  LinkedList_PrintData(l_ptr);
  
  // Partition around pivot  
  const int k_pivot = 5;
  printf("List after partitioning around k = %i \n", k_pivot);
  ListNodeT* new_head = PivotPartitioning(l_ptr->head, k_pivot);
  l_ptr->head = new_head;
  PrintDataStartingFromNode(l_ptr->head);  
  
  ResetAllNodes();  
  LinkedList_Destroy(l_ptr);
  return;
}

void MainLinkedList_ListAdditionAsIntegers() {
  printf("\n----------------------------------- MainLinkedList_ListAdditionAsIntegers \n");
  
  // create 2 linked lists
  LinkedlistT ll;
  LinkedlistT *l_ptr = &ll;
  LinkedList_Init(l_ptr);
  LinkedList_PushFront(l_ptr, &node1);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node2);
  LinkedList_InsertAfterNode(l_ptr, LinkedList_GetTail(l_ptr), &node3);
  node1.key = 9;
  node2.key = 9;
  node3.key = 9;
  printf("List1: \n");
  LinkedList_PrintData(l_ptr);
    
  LinkedlistT ll2;
  LinkedlistT *l_ptr2 = &ll2;
  LinkedList_Init(l_ptr2);
  LinkedList_PushFront(l_ptr2, &node6);
  LinkedList_InsertAfterNode(l_ptr2, LinkedList_GetTail(l_ptr2), &node7);
  LinkedList_InsertAfterNode(l_ptr2, LinkedList_GetTail(l_ptr2), &node8);
  LinkedList_InsertAfterNode(l_ptr2, LinkedList_GetTail(l_ptr2), &node4);
  LinkedList_InsertAfterNode(l_ptr2, LinkedList_GetTail(l_ptr2), &node5);
  node6.key = 9;
  node7.key = 9;
  node8.key = 9;
  node4.key = 9;
  node5.key = 9;
  printf("List2: \n");
  LinkedList_PrintData(l_ptr2);
  
  // add lists
  ListNodeT* head_sum = ListAdditionAsIntegers_InPlace(l_ptr->head, l_ptr2->head);  
  printf("Sum (LSD first): \n");
  PrintDataStartingFromNode(head_sum);
  
  ResetAllNodes();
  
  // ACHTUNG: cleanup ... current memory leak because the lists are merged
  // manually without keeping the list objects clean so that all objects
  // are freed by destroy  
  LinkedList_Destroy(l_ptr);
  LinkedList_Destroy(l_ptr2);
  return;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void LinkedList_PushFront(LinkedlistT* l_ptr, DataNodeIntKeyIntValT* new_datanode) {
  ListNodeT* new_mem = calloc(1, sizeof(ListNodeT));
  new_mem->data = *new_datanode;
  new_mem->next = l_ptr->head;
  l_ptr->head = new_mem;
  ++(l_ptr->n_nodes);
  return;
}

void LinkedList_PopFront(LinkedlistT* l_ptr) {
  if (l_ptr->head) {
    ListNodeT* mem_to_delete = l_ptr->head;
    l_ptr->head = l_ptr->head->next;
    free(mem_to_delete);
    --(l_ptr->n_nodes);
  } else {
    printf("Underflow Error: List is Empty. Cannot pop. \n");    
  }
  return;
}


// note: we do not check that given node is actually part of the list
void LinkedList_InsertAfterNode(LinkedlistT* l_ptr, ListNodeT* predecessor, 
        DataNodeIntKeyIntValT* new_datanode) {
  ListNodeT* new_mem = calloc(1, sizeof(ListNodeT));
  new_mem->data = *new_datanode;
  new_mem->next = predecessor->next;
  predecessor->next = new_mem;  
  ++(l_ptr->n_nodes);
  return;
}

void LinkedList_DeleteAfterNode(LinkedlistT* l_ptr, ListNodeT* predecessor) {
  if (!predecessor) {
    return;
  }
  ListNodeT* to_delete = predecessor->next;
  if (to_delete) {
    predecessor->next = predecessor->next->next;
    free(to_delete);
    --(l_ptr->n_nodes);
  }
  return;
}


ListNodeT* LinkedList_GetTail(LinkedlistT* l_ptr) {
  ListNodeT* node = l_ptr->head;
  while (node->next) {
    node = node->next;
  }
  return node;
}


void LinkedList_Init(LinkedlistT* l_ptr) {
  l_ptr->head = NULL;  
  l_ptr->n_nodes = 0;
  return;
}

void LinkedList_Destroy(LinkedlistT* l_ptr) {
  ListNodeT* curr = l_ptr->head;  
  while (curr && l_ptr->n_nodes) { // note: both conditions needed to avoid cycle
    ListNodeT* next = curr->next;
    free(curr);
    curr = next;
    --(l_ptr->n_nodes);
  }
  return;
}

void LinkedList_DeleteAtIndex(LinkedlistT* l_ptr, int i) {
  if (i == 0) {
      LinkedList_PopFront(l_ptr);
  } else {
    ListNodeT* itr = l_ptr->head;
    int count = i - 2;
    while(itr && count-- >= 0) {
      itr = itr->next;
    }  
    if (itr) { // itr is now at predecessor
      ListNodeT* to_delete;     
      to_delete = itr->next;      
      if (to_delete) {
        itr->next = to_delete->next;
        free(to_delete);
        --(l_ptr->n_nodes);
      }    
    } else {
      printf("Index %i is out of bounds. Cannot delete.\n", i);
    }
  }
  return;
}

void LinkedList_DeleteKthLast(LinkedlistT* l_ptr, int k) {
  if (k <= 0) {
    return;
  }
  ListNodeT* slow = l_ptr->head;
  ListNodeT* fast = l_ptr->head;
  ++k; // we want to advance (k+1) steps because we need previous of kth-last node
  while (k && fast) {
    fast = fast->next;
    --k;
  }
  if (fast == NULL && k > 0) { // list does not have k nodes
    printf("List does not have %i nodes. Cannot delete %ith last.", k, k);
  } else if (fast == NULL && k == 0) { // kth-last is the head
    LinkedList_PopFront(l_ptr);
  } else { // fast is k+1 steps ahead of slow
    while (fast) {
      slow = slow->next;
      fast = fast->next;
    }
    ListNodeT* to_delete = slow->next;
    if (to_delete) { // should always be, by construction, but to be sure
      slow->next = slow->next->next;
      free(to_delete);
      --(l_ptr->n_nodes);
    }    
  }  
  return;
}


/**
 * Assume list not cyclic already !
 * 
 * @param restart_node_idx
 * @param list
 */
void LinkedList_MakeCyclicFromTailToIdx(const int restart_node_idx, 
        LinkedlistT* l_ptr) {  
  // find restart node
  ListNodeT* restart_node = l_ptr->head;
  int i = 0;
  while (restart_node != NULL && i < restart_node_idx) {
    restart_node = restart_node->next;
    ++i;
  }  
  // connect tail to restart node
  if (restart_node == NULL) {
    printf("List has %i nodes, but restart_node was %i. \n", i, 
            restart_node_idx);
    printf("\n");
  } else {
    GetTail(l_ptr->head)->next = restart_node;    
  }  
  return;
}

// TODO: simplify cyclic case handling by using number of nodes stored in listptr
int LinkedList_PrintData(LinkedlistT* list) {  
  if (LinkedList_IsEmpty(list)) {
    printf("PrintMethod: No data to print. list is empty.\n");      
  } else {
    // printf("PrintMethod: %i nodes registered in list \n", list->n_nodes);
  }
  int cycle_len = FindCycleLength(list);
  int print_len = 10;
  ListNodeT* current_node = list->head;
  int idx = 0;
  if (cycle_len != 0) {    
    printf("ATTENTION: print method found that list is cyclic with length: %i \n", 
            cycle_len);
    printf("--> printing only first %i nodes \n", print_len);            
    while (current_node != NULL) {
      printf("Data at node with idx = %i : %i \n", idx, current_node->data.key);
      current_node = current_node->next;
      ++idx;
      if (idx > print_len) {        
        break;
      }
    }
  } else {
    while (current_node != NULL) {
      printf("Data at node with idx = %i : %i \n", idx, current_node->data.key);
      current_node = current_node->next;
      ++idx;
    }
  }  
  printf("\n");    
  return EXIT_SUCCESS;
}

bool LinkedList_IsEmpty(LinkedlistT* list) {  
  return (list->head ? false : true);
}

int LinkedList_ComputeLength(ListNodeT* node) {
  int len = 0;
  while (node) {
    ++len;
    node = node->next;
  }
  return len;
}

ListNodeT* LinkedList_MergeSort(ListNodeT* head) {
  if (!head) return NULL;
  else if (!(head->next)) return head;
  ListNodeT* middle_node = LinkedList_FindMiddleNode(head);
  // if length of list == 2, function returns head node as middle node
  ListNodeT* head_2ndhalf = middle_node->next;
  // temporarily cut connection after middle node
  middle_node->next = NULL;
  head = LinkedList_MergeSort(head);
  head_2ndhalf = LinkedList_MergeSort(head_2ndhalf);
  ListNodeT* new_head = LinkedList_MergeTwoSortedListsIntoFirst(head, 
          head_2ndhalf);
  return new_head;
}
ListNodeT* LinkedList_FindMiddleNode(ListNodeT* head) {
  ListNodeT *slow = head, *fast = head;
  while (fast && fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}
/**
 * always append the smaller one, until one list is empty.
 * then append the rest of the non-empty list
 * 
 * @param sortedList1
 * @param sortedList2
 */
ListNodeT* LinkedList_MergeTwoSortedListsIntoFirst(ListNodeT* head1, 
        ListNodeT* head2) {
  ListNodeT* iter1 = head1;
  ListNodeT* iter2 = head2;
  ListNodeT dummy_head = {{-42,-42}, NULL};
  ListNodeT* prev = &dummy_head;
  while (iter1 && iter2) {
    if (iter1->data.key < iter2->data.key) {
      prev->next = iter1;
      iter1 = iter1->next;
    } else {
      prev->next = iter2;
      iter2 = iter2->next;
    }
    prev = prev->next;
  }
  while (iter1) {
    prev->next = iter1;    
    iter1 = iter1->next;
    prev = prev->next;
  }
  while (iter2) {
    prev->next = iter2;    
    iter2 = iter2->next;
    prev = prev->next;
  }
  prev->next = NULL; // prev is now the tail
  return dummy_head.next;
}

//-------------------------------------------------------------------



/**
 * Assume list is non-cyclic !
 * 
 * @param node
 * @return 
 */
ListNodeT* GetTail(ListNodeT* node) {
  while (node->next) {
    node = node->next;
  }
  return node;
}

/**
 * Assume that node is already part of the list..
 * 
 * @param node
 * @param new_node
 * @return 
 */
int InsertAfterNode(ListNodeT* node, ListNodeT* new_node) {
  new_node->next = node->next;
  node->next = new_node;  
}

int InsertAfterNodeWithKey(const int key, LinkedlistT* list, 
        ListNodeT* new_node) {
  int retVal = 0;
  ListNodeT* curr_node = list->head;
  int idx = 0;
  while (curr_node->data.key != key && curr_node->next != NULL) {
    curr_node = curr_node->next;
    ++idx;
  }
  if (curr_node->data.key == key) {
    printf("Key %i was found at idx %i. New node inserted at %i.\n", key, idx,
            idx + 1);
    new_node->next = curr_node->next;
    curr_node->next = new_node;
    retVal = 0;    
    ++(list->n_nodes);
  } else {
    printf("Key %i was not found in list. New node not inserted.\n", key);
    retVal = 1;
  }
  return retVal;
}

int InsertAtIndex(const int idx, ListNodeT* const new_node,
        LinkedlistT* linkedlist) {
  int retVal = EXIT_SUCCESS;
  if (idx >= linkedlist->n_nodes) {
    retVal = EXIT_FAILURE;
  } else {
    int i = 0;
    ListNodeT* current_node = linkedlist->head;
    // stop at one node before the node that is at index idx at the moment
    while (i < idx - 2) {
      current_node = current_node->next;
    }
    ListNodeT* node_before_idx = current_node;
    ListNodeT* node_previously_at_idx = current_node->next;
    node_before_idx->next = new_node;
    new_node->next = node_previously_at_idx;    
  }  
  ++(linkedlist->n_nodes);
  return retVal;
}

int InsertAtEnd(ListNodeT* new_node,
        LinkedlistT* linkedlist) {
  int retVal = EXIT_SUCCESS;
  bool is_cyclic = IsCyclic(linkedlist->head);
  ListNodeT* prev_tail = NULL;
  if (is_cyclic) {
    // no end exists
    return EXIT_FAILURE;
  } else {    
    prev_tail = GetTail(linkedlist->head);
    prev_tail->next = new_node;
    // list now cyclic ?
    if (IsCyclic(new_node)) {
      linkedlist->n_nodes += FindCycleLength(linkedlist);
    } else { // count new_node and all its successors 
      while (new_node) {
        ++(linkedlist->n_nodes);
        new_node = new_node->next;
      }
    }
  }  
  return retVal;
}

void DeletKthLastNode(LinkedlistT* list_ptr, int k) {
  ListNodeT* slow = list_ptr->head;
  ListNodeT* fast = list_ptr->head;
  ++k; // we want to advance (k+1) steps because we need previous of kth-last node
  while (k-- && fast) {
    fast = fast->next;
  }
  while (fast) {
    slow = slow->next;
    fast = fast->next;
  }
  if (k != -1) { // fast has reached NULL before getting k steps ahead
    // do nothing
  } else { // slow is one before the k-th last
    slow->next = slow->next->next;
    --(list_ptr->n_nodes);
  }
  return;
}

/**
 * Exercise: 
 * 
 * Delete given node in O(1).
 * 
 * Idea:
 * 
 *  a -> b -> c -> d -> e
 * 
 * Instead of deleting the node just make it a copy of its next
 * and then jump over the next.
 * 
 * E.g. delete c :
 * 
 * a -> b -> c = copy_data(d) -> e 
 * 
 * 
 * !!!!!!!!!!!!Attention: node must NOT be tail !!!!!!!!!!
 * 
 * @param node
 */
void LinkedList_DeleteNodeFromList(ListNodeT* node) { 
  ListNodeT* tmp = node->next;
  node->data = node->next->data;
  node->next = node->next->next;
  if (tmp) { free(tmp); }
  return;
}


/**
 * 
 * time complexity: O(n)
 * ACHTUNG: is not cheap ! have to traverse until second but last node found
 * 
 * @param linkedlist
 * @return 
 */
int DeleteTail(LinkedlistT* linkedlist) {
  if (IsCyclic(linkedlist->head)) {
    return EXIT_FAILURE;
  } else {
    int bool_nextnode_is_last = false;
    ListNodeT* curr_node = linkedlist->head;
    if (curr_node->next == NULL) {
      // only one node contained
    } else {
      if (curr_node->next->next == NULL) {
        bool_nextnode_is_last = true;
      }
    }
    while (!bool_nextnode_is_last) {
      curr_node = curr_node->next;
      bool_nextnode_is_last = curr_node->next->next == NULL ? true : false;
    }
    // unless the list is circularly linked, curr_node should now be
    // the last but one node in the list
    curr_node->next = NULL;
    --(linkedlist->n_nodes);
    return EXIT_SUCCESS;
  }  
}

int SortLinkedlist(LinkedlistT* list) {
  int retVal = 0;    
  int len_list = list->n_nodes;
  int arr_data[len_list];
  CopyDataFromListToArray(list, arr_data);
  QuicksortArray(arr_data, 0, len_list - 1);
  LinkedList_Destroy(list);  
  ConvertArrayToList(arr_data, len_list, list);  
  return retVal;
}


/**
 * Assume that arr is allocated for at least the length of the list.
 * 
 * @param list
 * @param arr
 * @param len
 * @return 
 */
int CopyDataFromListToArray(LinkedlistT* list, int arr[]) {
  int retVal = 0;
  if (LinkedList_IsEmpty(list)) {
    printf("Passed list is empty. \n");
    retVal = 1;
  } else {
    ListNodeT* curr_node = list->head;
    int i = 0;
    while (curr_node != NULL) {
      arr[i] = curr_node->data.key;
      curr_node = curr_node->next;
      ++i;
    }
  }
  return retVal;
}

/**
 * We pass here an array of nodes becasue we need to make sure that
 * nodes exist already in the caller-scope for each data-element.
 * --> otherwise, if we were to create nodes here we would either only see them 
 *     within the local scope, which is useless then, or ewe would
 *     have to do allocate the nodes dynamically
 *     on the heap, with the potential that the
 *     caller forgets to free the memory..
 * ==> therefore, lets assume the nodes have been created in the
 *     callers scope
 * 
 * ACHTUNG: caller also has to destroy the created list !
 * 
 * @param arr
 * @param len
 * @param arr_nodes
 * @return 
 */
int ConvertArrayToList(int arr[], const int len, LinkedlistT* list) {
  int retVal = 0;
  int i = 0;
  LinkedList_Destroy(list);
  LinkedList_Init(list);    
  for (i = 0; i < len; ++i) {
    LinkedList_PushFront(list, &((DataNodeIntKeyIntValT){arr[i], -42}));
  }
  list->head = ReverseLinkedList(list->head); // necessary since we use pushfront not pushback
  return retVal;
}


/**
 * Excercise: 
 * 
 * Test if a linked list contains a cycle.
 * 
 * Idea:
 * 
 * Use a fast and a slow pointer. The fast pointer can only ever 
 * be equal to slow pointer, if a cycle traps them.
 * 
 * @param node_ptr
 * @return 
 */
bool IsCyclic(ListNodeT* node_ptr) {  
  ListNodeT* fast = node_ptr;
  while(fast && node_ptr) {    
    node_ptr = node_ptr->next;
    if (fast->next) {
      fast = fast->next->next;
    } else {
      break;
    }
    if (fast == node_ptr) { // only possible if cyclic
      return true;
    }
  }
  return false;
}

/**
 * Cycle length is the number of nodes in the cycle.
 * 
 * @param list
 * @return 
 */
int FindCycleLength(LinkedlistT* list) {
  int cyclic_len = 0;
  ListNodeT* slow = list->head;
  ListNodeT* fast = list->head;  
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;    
    // this condition only becomes true, if the list is cyclic
    if (slow == fast) {
      cyclic_len = 1;
      // now that we found a node inside the cycle, get cycle length
      fast = fast->next;
      while (slow != fast) {
        ++cyclic_len;
        fast = fast->next;
      }      
      break;
    }    
  }
  printf("Found cycle length %i.\n", cyclic_len);
  return cyclic_len;  
}

/**
 * Use cycle-length-advanced node to find first node of cycle.
 * 
 * @param cycle_len
 * @param list
 * @return 
 */
ListNodeT* FindFirstNodeOfCycle(ListNodeT* head, 
        int* len_noncyclic) {
  ListNodeT* slow = head;
  ListNodeT* fast = head;  
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    // this condition only becomes true, if the list is cyclic
    // -> now that we found a node inside the cycle, get cycle length    
    if (slow == fast) {
      int len_cycle = 1;      
      fast = fast->next;
      while (slow != fast) {
        ++len_cycle;
        fast = fast->next;
      }
      // find first node of cycle
      slow = head;
      fast = head;
      while (len_cycle--) {
        fast = fast->next;
      }      
      *len_noncyclic = 0;
      while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
        ++(*len_noncyclic);
      }
      return slow;
    }
  }
  // reach here only, if fast or fast->next is NULL
  return NULL;
}



void PrintDataStartingFromNode(ListNodeT* node_ptr) {
  const int print_max = 10;
  int count = 0;
  while (node_ptr && count < print_max) {
      printf("Data at node with idx = %i : %i \n", count, node_ptr->data.key);
      node_ptr = node_ptr->next;
      ++count;
  }
  return;
}

/**
 * Excercise:
 * 
 * given a singly linked list, reverse the list.
 * 
 * Idea:
 * 
 * Traverse the list, keeping track of prev, curr, next
 * and redirect curr->next to curr->previous.
 * 
 * O(n) time, O(1) space
 * 
 * @param node_ptr
 */
ListNodeT* ReverseLinkedList(ListNodeT* node_ptr) {  
  ListNodeT* prev = node_ptr;
  ListNodeT* curr = node_ptr->next;
  node_ptr->next = NULL; // node_ptr is the new tail
  ListNodeT* next_cached = NULL;  
  while (curr) {
    next_cached = curr->next;
    curr->next = prev;
    // update
    prev = curr;
    curr = next_cached;    
  }  
  return prev;
}

/**
 * Excercise: 
 * 
 * Given a linked list and two indices of nodes in the list, reverse the
 * sublist spanned from index i0 to index i1.
 * 
 * Idea:
 * 
 * Reverse is an O(n) operation. We can temporarily consider the sublist
 * as a separate list by redirecting sublist_tail to NULL (storing
 * the nodes that come before and after the sublist), then reverse the sublist,
 * and reintegrate the reversed sublist.
 * 
 * Note: if i0 = 0, the list will have a new head, so we need to return
 *       that information, e.g. by returning a pointer to the head of the list.
 * 
 * Note: optimisation: instead of using an independent reverse function
 *       and then reintegrating, one could directly traverse the list
 *       and reverse the sub-list in one go. This would save one of the
 *       two traversals through the sublist.
 * 
 * O(i1) time, where i1 is the last of the sublist, O(1) space
 * 
 * @param i0
 * @param i1
 * @param node_ptr
 * @return 
 */
ListNodeT* ReverseSubList(const int i0, const int i1, ListNodeT* node_ptr) {  
  ListNodeT* new_head = node_ptr; // only if i0 = 0, this will change
  int i = 0;
  ListNodeT* before_sublist = NULL;
  if (i0 > 0) {
    while (i < i0 - 1) { // advance i0 - 1 times
      node_ptr = node_ptr->next;
      ++i;
    }    
    before_sublist = node_ptr;
    node_ptr = node_ptr->next;
  } // node_ptr is advanced i0 times
  ListNodeT* old_head_sublist = node_ptr;  
  i = 0;
  while (node_ptr && i < (i1 - i0)) { // move (i1 - i0) steps 
    node_ptr = node_ptr->next;
    ++i;
  } // now node_ptr is at last node of sublist to be reversed  
  ListNodeT* old_tail_sublist = node_ptr;
  ListNodeT* after_sublist = old_tail_sublist->next;  
  old_tail_sublist->next = NULL;
  // Reverse sublist
  ListNodeT* new_head_sublist = ReverseLinkedList(old_head_sublist);
  // Reintegrate front
  if (before_sublist) { // equivalent to i0 > 0
    before_sublist->next = new_head_sublist;
  } else {
    new_head = new_head_sublist;
  }
  // Reintegrate back
  old_head_sublist->next = after_sublist;  
  return new_head;
}



/**
 * 
 * Excercise:
 * 
 * Given two lists that are not cyclic but may or may not coalesce
 * at some node. Find this node or return NULL if they do not coalesce.
 * 
 * Idea:
 * 
 * Find the length difference of the two lists. Then advance the head
 * of the longer list by the length difference, so that both need
 * the same amount of steps until they reach their end. Then let
 * the head pointers traverse simultaneously. If an overlap
 * exists, they will reach it at the same time, and we have detected
 * the first node of the overlap.
 * 
 * @param node1
 * @param node2
 * @return 
 */
ListNodeT* GetMergeNodeNonCyclicLists(ListNodeT* node1, ListNodeT* node2) {  
  int len1 = LinkedList_ComputeLength(node1);
  int len2 = LinkedList_ComputeLength(node2);
  AdvanceNodeBySteps(abs(len1-len2), (len1 > len2 ? &node1 : &node2));
  // now both node_ptrs need the same number of steps to reach overlap
  while (node1 && node2 && node1 != node2) {
    node1 = node1->next;
    node2 = node2->next;
  }    
  return node1;
}


void AdvanceNodeBySteps(int n_steps, ListNodeT** node) {
  while (n_steps-- && *node) {
    *node = (*node)->next;
  }
  return;
}

/**
 * Excercise:
 * 
 * Given two lists that are not cyclic but may or may not coalesce
 * at some node. Find this node or return NULL if they do not coalesce.
 * 
 * Idea:
 * 
 * One can find the length of both lists len1, len2.
 * In order to find the first node, we need to know len_overlap, so
 * that we can calculate
 * 
 *    len1_unique = len1 - len_overlap
 * 
 * and then simply advance list1->head by len1_unique + 1
 * (or the same with length 2, take which is shorter).
 * 
 * So the question is how to obtain len_overlap:
 * 
 *    len_overlap = len1 - len1_unique
 * 
 * By reversing list2 and the recalculating length of list1, we get
 * 
 *    len1_2reversed = len1_unique + len2_unique + 1
 * 
 * So we have
 * 
 *    len1_2reversed - len2_unique - 1 = len1 - len_overlap
 * 
 * Exploiting that len2_unique = len2 - len_overlap
 * 
 *    len1_2reversed - len2 + len_overlap - 1 = len1 - len_overlap
 * 
 * ==> len_overlap = 1/2 * (len1 + len2 + 1 - len1_2reversed)
 * 
 * @param node1
 * @param node2
 * @return 
 */
ListNodeT* GetMergeNodeNonCyclicLists_FirstTry(ListNodeT* node1, ListNodeT* node2) {
  ListNodeT *overlap_node = NULL;
  ListNodeT *node1_cpy = node1;
  ListNodeT *node2_cpy = node2;
  ListNodeT *tail1 = node1;
  bool overlap_found = false;
  // find out len1 and len2 and whether they overlap
  int len1 = 0;
  while (node1) { 
    ++len1;    
    tail1 = node1;
    node1 = node1->next;
  }
  int len2 = 0;
  while (node2) {
    ++len2;
    if (node2 == tail1 && !overlap_found) {
      overlap_found = true;
    }
    node2 = node2->next;    
  }
  // if overlap was found, find the first node
  if (overlap_found) {
    ListNodeT* new_head = ReverseLinkedList(node2_cpy);
    int len1_2reversed = 0;
    node1 = node1_cpy;
    while (node1->next) {
      node1 = node1->next;
      ++len1_2reversed;
    }
    int len_overlap = (len1 + len2 + 1 - len1_2reversed) / 2;
    int len1_unique = len1 - len_overlap;
    // cleanup: reverse back list 2 (and thus also overlap part of list1)    
    new_head = ReverseLinkedList(new_head);
    // finally advance node1
    overlap_node = node1_cpy;
    while (len1_unique--) {
      overlap_node = overlap_node->next;
    }
  }
  return overlap_node;
}


/**
 * Excercise:
 * 
 * Given two lists, that may or may not be cyclic, find
 * the first node of the overlap. If no overlap exists return NULL.
 * If they overlap and are cyclic the first node may be either
 * of the entry points to the cycle.
 * If they overlap and are not cyclic return the unique first node
 * of the overlap region.
 * 
 * Idea:
 * 
 * 1. find out if the lists are cyclic.
 * 2. if not, use algorithm for non-cyclic lists to find overlap_node
 * 3. if yes, check if they overlap:
 *      advance both lists until you are in the cyclic region
 *      then only advance one of them one round through its cycle 
 * 4.   if not, there is no overlap
 * 5.   if on the way the other one is met, they overlap
 *        find length of both lists, substract cycle length
 *        -> take the lengths difference of the non-cyclic parts and advance
 *           a ptr from the start of the longer by that difference
 *        -> then advance in tandem on the other list until both meet
 * 
 * 
 * @param node1
 * @param node2
 * @return 
 */
ListNodeT* GetMergeNode(ListNodeT* node1, ListNodeT* node2) {  
  ListNodeT* node1_cpy = node1;
  ListNodeT* node2_cpy = node2;
  
  int len_noncyclic1 = 0;
  int len_noncyclic2 = 0;
  ListNodeT* cycleentry1 = FindFirstNodeOfCycle(node1, &len_noncyclic1);
  ListNodeT* cycleentry2 = FindFirstNodeOfCycle(node2, &len_noncyclic2);  
  
  
  if (!cycleentry1 && !cycleentry2) { //----------------- case: none of the two cyclic
    return GetMergeNodeNonCyclicLists(node1_cpy, node2_cpy);
  }
  
  if ((cycleentry1 && !cycleentry2) || 
          (!cycleentry1 && cycleentry2)) { //------------- case: only one cyclic
    return NULL;    
  }
  
  //------------------------ case: both cyclic
  
  // check if cycles overlap
  node1 = cycleentry1->next;    
  while (node1 != cycleentry1 && node1 != cycleentry2) {      
    node1 = node1->next;
  };  
  if (node1 != cycleentry2) { // non-overlapping cycles
    return NULL;
  } else { // cycles overlap
    ListNodeT* merge_node = NULL;    
    node1 = node1_cpy;
    node2 = node2_cpy;
    // advance one of the nodes by length diff in non-cyclic part
    AdvanceNodeBySteps(abs(len_noncyclic1 - len_noncyclic2), 
          (len_noncyclic1 > len_noncyclic2 ? &node1 : &node2));
    while (node1 != node2 && node1 != cycleentry1 && node2 != cycleentry2) {
      node1 = node1->next;
      node2 = node2->next; 
    }
    // one of the two reached cycle alone or they have merged already
    return (node1 == node2 ? node1 : cycleentry1);
  }
}

/**
 * Excercise:
 * 
 * Given a list, remove the duplicates from it.
 * 
 * E.g. 1 --> 4 --> 4 --> 4 -> 2 -> 2
 * 
 * should become
 *    
 *      1 --> 4 --> 2
 * 
 * @param list_ptr
 */
void RemoveDuplicates(LinkedlistT* list_ptr) {
  ListNodeT* curr = list_ptr->head;  
  while (curr->next) {
    if (curr->next->data.key == curr->data.key) {
      ListNodeT* next_to_check = curr->next->next;
      // find next different
      while (next_to_check && next_to_check->data.key == curr->data.key) {
        next_to_check = next_to_check->next;        
      }
      if (next_to_check) {
        curr->next = next_to_check;
      } else {
        // reached end without findin a different one
        curr->next = NULL;
        return;
      }      
    }
    curr = curr->next;
  }
  return;
}

/**
 * Excercise: 
 * 
 * Given a list, cyclically shift the nodes to the right by k.
 * 
 * Idea:
 * 
 *  Only 3 steps are necessary
 *    1. new head = kth-last node
 *    2. (previous to k-th last node)->next = NULL;
 *    3. old tail->next = old head
 *     
 * 
 * @param head
 * @param shift
 * @return 
 */
ListNodeT* CyclicRightShiftByK(ListNodeT* head, int k) {
  if (!head->next) {
    return head; // list only contains one node
  }
  ListNodeT* iter = head;
  // find (k+1)th last node
  ListNodeT* advanced = head->next;  
  while (k--) { 
    if (advanced->next) {
      advanced = advanced->next;
    } else {
      advanced = head;
    }
  }
  // move advanced to tail (not until NULL, in order to have handle on tail)
  while (advanced->next) {
    iter = iter->next;
    advanced = advanced->next;
  } // advanced is now at old tail  
  iter = iter->next; // increment one to have iter at k+1 steps from NULL, i.e. at the new tail
  ListNodeT* new_head = iter->next ? iter->next : head;
  iter->next = NULL;
  advanced->next = (new_head == head ? NULL : head);
  return new_head;
}

/**
 * Excercise:
 * 
 * Given a list, sort the list such that all nodes with even indices
 * come first, i.e. 0, 2, 4, 6, .., and then all nodes with odd indices
 * i.e. 1, 3, 5, 7, ..
 * 
 * Idea:
 * 
 * Traverse through list and redirect nodes such that even always
 * points to next even and odd always to next odd. At the end
 * let tail of even-list point to head of odd list.
 * 
 * time: O(n) , space O(1)
 * 
 * @param list_ptr
 */
void EvenOddSort(LinkedlistT* list_ptr) {
  ListNodeT* prev_even = list_ptr->head;  
  ListNodeT* head_odd = list_ptr->head->next;
  ListNodeT* prev_odd = head_odd;
  if (!prev_odd) {
    return;
  }
  ListNodeT* curr = prev_odd->next;
  int i = 0;
  while (curr) {
    prev_even->next = curr;    
    prev_odd->next = curr->next;
    // update
    prev_even = prev_even->next;
    prev_odd = prev_odd->next;
    if (curr->next) {
      curr = curr->next->next;
    } else {
      break;
    }    
  }
  prev_odd = NULL;
  prev_even->next = head_odd;  
  return;
}

/**
 * Excercise:
 * 
 * Check if the data in the list is palindromic.
 * 
 * Idea:
 * 
 * Reverse the second half and then traverse both halves in tandem to compare.
 * 
 * O(n) in time, O(1) in space
 * 
 * @param node
 * @return 
 */
bool CheckPalindromic(ListNodeT* node) {
  int i;
  int len = LinkedList_ComputeLength(node);
  ListNodeT* notused = ReverseSubList((len % 2 ? len/2 + 1 : len/2), len - 1, node);
  ListNodeT* node2ndhalf = node;  
  for (i = 0; i < len / 2; ++i) {
    node2ndhalf = node2ndhalf->next;
  }
  node2ndhalf = node2ndhalf->next;
  for (i = 0; i < len / 2; ++i) {
    if (node->data.key != node2ndhalf->data.key) {
      return false;
    }
  }
  return true;
}

/**
 * Excercise:
 * 
 * Given a linked list and a value k, partition the list such that
 * we have three partitions:
 * 
 *      nodes < k | nodes = k | nodes > k
 * 
 * Idea:
 * 
 * Traverse all nodes and distribute nodes to three distinct
 * lists, smaller, equal, bigger, by making the inspected node
 * the new head of the current list 
 * and in the end merge the lists together.
 * 
 * @param head
 * @param pivot
 * @return 
 */
ListNodeT* PivotPartitioning(ListNodeT* node, const int pivot) {  
  ListNodeT* head_smaller = NULL;
  ListNodeT* head_equal = NULL;
  ListNodeT* head_bigger = NULL;
  ListNodeT* tail_smaller = NULL;
  ListNodeT* tail_equal = NULL;
  while (node) {
    ListNodeT* cached_next = node->next;
    if (node->data.key < pivot) {
      if (!head_smaller) { // the first node added here will be the tail
        tail_smaller = node;
      }
      node->next = head_smaller;
      head_smaller = node;
    } else if (node->data.key == pivot) {
      if (!head_equal) { // the first node added here will be the tail
        tail_equal = node;
      }
      node->next = head_equal;
      head_equal = node;
    } else {
      node->next = head_bigger;
      head_bigger = node;
    }
    node = cached_next;
  }
  // merge lists
  if (tail_smaller) {
    tail_smaller->next = (head_equal ? head_equal : head_bigger);
  }
  if (head_equal) {
    tail_equal->next = head_bigger;
  }    
  return (head_smaller ? head_smaller : (head_equal ? head_equal : head_bigger));
}

/**
 * Excercise: 
 * 
 * Given two lists, view each as an integer with the head being the LSD. 
 * Perform addition and return the head of a list that represents the sum.
 *
 * Idea:
 * 
 * we have n + m nodes. The question is how many nodes do we need to represent
 * the result. We know that the number of digits in the sum of two numbers,
 * n > m, is maximally n+1. So we can theoretically work in-place on the
 * given nodes.
 * 
 * One could compute length of both lists and then use the longer one for
 * the result. However, this would be an additional O(n+m) cost, which
 * can be avoided by always using nodes of list1 until they are empty, 
 * then continue to use as many nodes of list2 as needed. And in the end merge.
 *  
 * @param node1
 * @param node2
 * @return 
 */
ListNodeT* ListAdditionAsIntegers_InPlace(ListNodeT* node1, ListNodeT* node2) {
  ListNodeT* head_sum = node1;
  ListNodeT* sum_iter = node1;
  ListNodeT* head_buffer = node2;
  ListNodeT* buffer_iter = node2;
  ListNodeT* tail_list1 = NULL;
  
  int carry_over = 0;
  while (node1 || node2) {
    int sum = 0;
    if (node1 && node2) {
      sum = node1->data.key + node2->data.key + carry_over;
      if (node1->next == NULL) {
        tail_list1 = node1;        
      }
      node1 = node1->next;
      node2 = node2->next;
    } else if (node1) {
      sum = node1->data.key + carry_over;     
      if (node1->next == NULL) {
        tail_list1 = node1;        
      }
      node1 = node1->next;      
    } else if (node2) {
      sum = node2->data.key + carry_over;
      node2 = node2->next;
    }   
    sum_iter->data.key = sum % 10;
    carry_over = sum / 10;      
    if (node1) {
      sum_iter = node1;
    } else if (node2) {
      sum_iter = buffer_iter;
      buffer_iter = buffer_iter->next;
    }
  }
  // take care of possible last node for carry_over
  if (carry_over) {
    sum_iter->next = buffer_iter;
    buffer_iter->data.key = carry_over;
    buffer_iter->next = NULL;
  } else {
    sum_iter->next = NULL;
  }
  // connect the two lists
  tail_list1->next = head_buffer;
  return head_sum;
}