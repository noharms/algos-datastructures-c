/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arrays.h
 * Author: noh
 *
 * Created on March 4, 2018, 12:09 PM
 */

#ifndef ARRAYS_H
#define ARRAYS_H

#ifdef __cplusplus
extern "C" {
#endif
  
  #include <stdbool.h>

  #include "standardheaders.h"

  #define MAX_RAND_NUM 40

  void MainArrays();

  void MainArray_KthSmallest_RandomizedSelection();
  void MainArray_PartitionEvenOdd();
  void MainArray_Partition2ValuedArray();
  void MainArray_Quicksort();
  void MainArray_IncrementDigitSequence();
  void MainArray_CheckAdvanceThroughBoardGame();
  void MainArray_RemoveDuplicatesFromSortedArray();
  void MainArray_NextSmallerNumberWithSameDigits();
  void MainArray_NextLargerNumberWithSameDigits();
  void MainArray_TestSudokuFilling();

  // array helpers
  void Array_FillWithRandomNumbers(const int max_val, 
          const int len, int* arr);  
  void Array_FillWithDistinctRandomNumbers(const int max_val, 
        const int len, int* arr);
  bool Array_IsNumberContained(int* arr, int l, int r, int num);
  void Array_SwapElements(int* arr,  const int i, const int j);
  int Array_FindExtremum(int (*compfun_ints)(int, int), const int len, int* arr);
  int Array_ReduceToSum(const int len, int* arr);

  //------------------------------------------ algos
  int Array_KthSmallest_RandomizedSelection(int* arr, int l, int r, int k);
  
  void Array_PartitionEvenOdd(int* const arr, const int len);
  
  void Array_Partition2ValuedArray(int* arr, const int len);
  
  int Array_PartitionAroundRandomPivot_Inplace(int* const arr, int l, int r);
  int Array_PartitionAroundRandomPivot_InplaceOptimised(int* const arr, int l, int r);
  int Array_PartitionAroundRandomPivot_UsingOofNMemory(int* const arr, int l, int r);
  
  int Array_PartioningDutchFlag(int *arr, int l, int r);

  void Array_IncrementArrayRepresentingDecimal(int* arr, const int len);

  void Array_CheckAdvanceToEndPossible(int* arr, const int len);
  
  int Array_RemoveDuplicatesFromSortedArray(int *arr, int n);
  
  unsigned long long Array_NextSmallerNumberWithSameDigits(unsigned long long n);
  unsigned long long Array_NextLargerNumberWithSameDigits(unsigned long long n);
  int* UllToDigitArray(ull num, int* n_digits);
  ull DigitArrToUnsignedLongLong(int* arr, int n);
  void ReverseArray(int* arr, int l, int r);
  
  bool IsSudokuFillingCorrect(unsigned int board[9][9]);
  bool RowHasDuplicatesOrZeros(unsigned int (*board)[9], int n, int i);
  bool ColHasDuplicates(unsigned int (*board)[9], int n, int i);
  bool SubregionHasDuplicates(unsigned int (*board)[9], int n, int i, int j);



#ifdef __cplusplus
}
#endif

#endif /* ARRAYS_H */

