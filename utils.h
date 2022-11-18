/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   utils.h
 * Author: noh
 *
 * Created on January 13, 2019, 1:30 PM
 */

#ifndef UTILS_H
#define UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

  
#include <stdbool.h>
  
  
  
  typedef struct CLOSED_INTERVAL_TYPE {      
    int left;
    int rght;
    int len;
    bool covered; // -> this field is used for one of the exercises
  } ClosedIntervalT;
  
  typedef struct BORDERPOINT_TYPE {
    int x;
    bool left_border; // false means it is a right border
  } BorderPointT;
    
  typedef struct OPENORCLOSED_INTERVAL_TYPE {      
    int left;
    int rght;
    int len;
    bool left_closed;
    bool rght_closed;
  } OpenOrClosedIntervalT;  
  
  int Min(int x, int y);
  int Max(int x, int y);
  
  bool EqualToPrec(double x, double y, double prec);
  
  bool isPrime(const int num);

  bool IsPowerOf(int n, int m);
  bool IsPowerOf_Recursion(int n, int m);
  bool IsPowerOf_RecursionMult(int n, int m, int base);

  int FindMedian(int* array, const int len, int (*compfun)(const void*, const void*));
 
  void PrintArray1d(int* arr, const int dim1);
  void PrintArray2D(int** arr, const int dim1, const int dim2);

  void FreePointer2D(int** ptr, const int dim1);
  
  ClosedIntervalT FindIntersection(ClosedIntervalT interval1, ClosedIntervalT interval2);
    
  void SwapInts(int* a, int* b);
  
  int CompFunInt_Ascending(const int x1, const int x2);
  int CompFunInt_Descending(const int x2, const int x1);
  int CompFunIntptr_Ascending(const void* ptr1, const void* ptr2);  
  int CompFunIntptr_Descending(const void* ptr1, const void* ptr2); 
  int CompFunBorderpointPtr_Ascending(const void* ptr1, const void* ptr2);
  int CompFunClosedIntervalPtr_Ascending(const void* ptr1, const void* ptr2) ;
  int CompFunOpenClosedIntervalPtr_Ascending(const void* ptr1, const void* ptr2) ;

#ifdef __cplusplus
}
#endif

#endif /* UTILS_H */

