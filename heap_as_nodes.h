/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   heap.h
 * Author: noh
 *
 * Created on March 14, 2018, 2:36 PM
 */

#ifndef HEAP_H
#define HEAP_H

#ifdef __cplusplus
extern "C" {
#endif
  
  
  #include "binarytree_as_nodes.h"

  typedef struct HEAP_TYPE {
    BTNodeT *root;
    int (*compfun_ptr)(const void*, const void*); // void* to allow comparing nodes of complex datatypes
    int n_nodes; // in a heap this allows to easily compute the linear idx of last node
  } HeapType;

  typedef struct PAIR_INDICES {
    int level;
    int idx_in_level;
  } PairIdxType;
  
  
  void MainHeapAsNodes();
  
  void MainHeapAsNodes_API();
  
  // API 
  void BinaryTree_TraversePreorderStoreNodesToArr(BTNodeT* root,
        BTNodeT** arr_nodeptrs, int* idx);  
  int Heap_FindMaxDepth(HeapType* heap);  
  void Heap_FillPathToNodeUsingInlevelidx(const int level, int inlevelidx, 
        int* arr_turns_to_node);
  BTNodeT* Heap_FindParentOfNodeatidx(HeapType* heap, int idx_node);
  PairIdxType Heap_FindPairIdxFromLinearIdx(int linear_idx);  
  void Heap_AddNewNodeToCompleteBT(HeapType* heap, 
        BTNodeT* new_node) ;  
  
  void Heap_Push(HeapType* heap, BTNodeT* new_node, 
        int (*compfun_ptr)(const void*, const void*) );  
  BTNodeT* Heap_Pop(HeapType* heap, int (*compfun_ptr)(const void*, const void*));
  
  BTNodeT* Heap_BubbleDownTopNode(HeapType* heap, 
        BTNodeT* topnode_unordered);
  
  // Exercises    
  void SortCompleteBTToHeap(HeapType* heap);
  void SortCompleteBTToMaxHeap(HeapType* heap);
  void SortCompleteBTToMinHeap(HeapType* heap);  
  void Heap_ConstructFromCompleteBTAndCompareFun(HeapType* heap,
        int (*compFun_if1stargLess2ndargResultLess0)(const void*, const void*));  
    
  void Heap_SortAlmostSortedArray(int (*compFun_if1stargLess2ndargResultLess0)(const void*, const void*),
        const int max_offset, 
        const int len, 
        int* arr);
  
#ifdef __cplusplus
}
#endif

#endif /* HEAP_H */

