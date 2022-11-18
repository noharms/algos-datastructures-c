/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   heap_as_array.h
 * Author: noh
 *
 * Created on July 21, 2019, 5:11 PM
 */

#ifndef HEAP_AS_ARRAY_H
#define HEAP_AS_ARRAY_H

#ifdef __cplusplus
extern "C" {
#endif
  
  
  #include "standardheaders.h"
  #include "utils.h"
  
  typedef struct HEAP_ASARRAY_TYPE {
    DataNodeIntKeyIntValT* arr;
    int capacity;
    int n_elems;
    int (*comp)(const int, const int);
  } HeapAsArrayT;
  
  void MainHeapAsArray();
  
  void MainHeapAsArray_API();
  void MainHeapAsArray_UnionOfSortedSequences();
  void MainHeapAsArray_SortIncreasingDecreasingArray();
  void MainHeapAsArray_SortAlmostSortedArray();
  void MainHeapAsArray_FindKSmallestElementsInArray();
  void MainHeapAsArray_UpdateMedianInStreamInputOofnSpace();
  void MainHeapAsArray_FindKSmallestElementsMinHeap();
  
  // API
  void HeapAsArray_Push(HeapAsArrayT* h, DataNodeIntKeyIntValT* new_node);
  void HeapAsArray_PushArrayOfInt(HeapAsArrayT* h, int* arr, int k);
  void HeapAsArray_Pop(HeapAsArrayT* h);
  DataNodeIntKeyIntValT* HeapAsArray_Top(HeapAsArrayT* h);
  void HeapAsArray_Init(HeapAsArrayT* h, int (*comp)(const int, const int));
  void HeapAsArray_Destroy(HeapAsArrayT* h);
  void HeapAsArray_Resize(HeapAsArrayT* h);
  void HeapAsArray_PrintInOrder(HeapAsArrayT* h);
  
  void HeapAsArray_SwapContent(DataNodeIntKeyIntValT* n, DataNodeIntKeyIntValT* m);
  int HeapAsArray_IdxOfParent(int idx);
  int HeapAsArray_IdxLeftChild(int idx);
  int HeapAsArray_IdxRghtChild(int idx);  
  int HeapAsArray_IdxPrioChild(HeapAsArrayT* h, int idx);
  
  // Exercises
  int* HeapAsArray_UnionOfSortedSequences(int** sorted_sequences, int n_sequences);
  int* HeapAsArray_SortIncreasingDecreasingArray(int* inc_dec, int n);
  void HeapAsArray_SortAlmostSortedArray(int* almost_sorted, int n, int k);
  void HeapAsArray_KSmallestElementsInArray(int* input, int n, int* smallest, int k);
  void HeapAsArray_UpdateMedianInStreamInputOofnSpace(int* stream, int n, float* medians);
  void HeapAsArray_KSmallestElementsInMinHeap(HeapAsArrayT* minh, int k, 
        int* smallest);


#ifdef __cplusplus
}
#endif

#endif /* HEAP_AS_ARRAY_H */

