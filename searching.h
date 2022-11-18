/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   searching.h
 * Author: noh
 *
 * Created on March 17, 2018, 8:41 PM
 */

#ifndef SEARCHING_H
#define SEARCHING_H

#ifdef __cplusplus
extern "C" {
#endif
  
  #include <stdbool.h>

  #include "standardheaders.h"

  typedef struct MINMAX_TYPE {
    int min;
    int max;
  } MinMaxT;

  void MainSearching();
  
  void MainSearching_BinarySearch();
  void MainSearching_BinarySearch_IndexEqualsKey();
  void MainSearching_BinarySearch_CyclicShiftSortedArray();
  void MainSearching_BinarySearch_RoundedDownSquareRoot();
  void MainSearching_BinarySearch_SquareRoot();
  void MainSearching_BinarySearch_Quotient();
  void MainSearching_KeyExistenceInSorted2dArray();
  void MainSearching_FindAMissingIPaddress();
  void MainSearching_FindMinMaxTogether();
  void MainSearching_NNumbersSmallerNBut1Missing1Twice();
  
  int Searching_BinarySearchKey_Recursive(int* arr, int l, int r, const int key);
  int Searching_BinarySearchKey_Iterative(int* arr, int l, int r, const int key);
  
  int Searching_BinarySearchKey_LastLess(int* arr, int l, int r, const int key);
  int Searching_BinarySearchKey_1stEq(int* arr, int l, int r, const int key);
  int Searching_BinarySearchKey_1stGtr(int* arr, int l, int r, const int key);
  int Searching_BinarySearchKey_LastEq(int* arr, int l, int r, const int key);
  
  int Searching_BinarySearchKey_1stGtrOrEq(int* arr, int l, int r, const int key);
  
  int Searching_BinarySearchKey_1stEq_Alternative(int* arr, int l, int r, const int key);
  int Searching_BinarySearchKey_LastEq_Alternative(int* arr, int l, int r, const int key);
  int Searching_BinarySearchKey_1stEq_Alternative2(int* arr, int l, int r, const int key);
  int Searching_BinarySearchKey_LastEq_Alternative2(int* arr, int l, int r, const int key);
    
  int Searching_BinarySearch_InsertPosition(int (*OrderFulfilled)(const int, const int),
        const int new_elem, const int len, int* arr);
  
  int Searching_BinarySearch_IndexEqualsKey(int *arr, int l, int r);
  
  int Searching_BinarySearch_IdxOfMinimum(int *arr, int l, int r);
  
  int Searching_IntegerSquareRoot(const int k);
  float Searching_FloatSquareRoot(const float x, const float precision);
  float Searching_FloatSquareRoot_old(const float x, const float precision);
  
  float Searching_FloatQuotient(float x, float y, const float prec);
  
  bool KeyExistenceInSorted2dArray(int **mat, int n, int m, int key);
  
  unsigned int FindAMissingIPaddress(char* path_to_file);
  void Turn32bitToIpString(char* dst, unsigned int ip);
  
  MinMaxT FindMinMaxTogether(int* arr, int n);
  
  IntPairT FindMissAndDuplInNNumbersFrom0ToN(int* arr, int n);


#ifdef __cplusplus
}
#endif

#endif /* SEARCHING_H */

