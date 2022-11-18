/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sorting_algos.h
 * Author: noh
 *
 * Created on August 28, 2019, 11:10 AM
 */

#ifndef SORTING_ALGOS_H
#define SORTING_ALGOS_H

#ifdef __cplusplus
extern "C" {
#endif

  void MainSortingAlgos();
  
  //------------------------- sorting algos
  void BubbleSortArrayInt(int (*compfun_int)(const int, const int),
        const int len, int* arr);
  
  void SelectionSortArrayInt(int (*compfun_int)(const int, const int),
        const int len, int* arr);
  
  void HeapSortArrayInt(int (*compfun_int)(const int, const int),
        const int len, int* arr);
  
  void InsertionSortArrayInt(int (*compfun_int)(const int, const int),
        const int len, int* arr);    
  void InsertionSortArrayIntWithBS(int (*compfun_int)(const int, const int),
        const int len, int* arr);
  
  void CountingSortArrayInt(const int len, int* arr,
        const int max_val, const int min_val);
  
  void BucketSortArrayInt(const int len, int* arr, 
        const int max_val, const int min_val);
  
  void LSDRadixSortArrayInt(const int len, int* arr);  
  
  void QuicksortArray(int* arr, int l, int r);
  void QuicksortArray_UsingOofNMemory(int* const arr, const int len);
  void QuicksortArrayDutchFlag(int *arr, int l, int r);
    
  void MergeSortArrayInt(int *arr, int l, int r);
  void MergeTwoSortedHalves(int *arr, int l, int m, int r);
 


#ifdef __cplusplus
}
#endif

#endif /* SORTING_ALGOS_H */

