/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


// corresponding header
#include "utils.h"

// system headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// other c-files' headers and project-wide headers


int Min(int x, int y) {
  return (x <= y ? x : y);
}

int Max(int x, int y) {
  return (x >= y ? x : y);
}
  

/**
 * equality of doubles
 * 
 * @param x
 * @param y
 * @param prec
 * @return 
 */
bool EqualToPrec(double x, double y, double prec) {
  return fabs(x - y) <= prec ? true : false;
}

// to check whether a candidate is a prime we go try and error
// through all numbers smaller than the candidate and see if
// the candidate is dividable by that number
//
// -> note: in fact we only need to run until we reach the half of the number
//          because the greatest divisor of any number is half the number
//          ( and this is the case whenever the number is even )
//
// Corner cases: num == 0 --> returns true
//               num == 1 --> returns true
bool isPrime(const int num) {  
  
  int i;
  
  // no worries about rounding here: rounding down is just fine. rounded up number
  //                                 would be larger than half the number, so never possible
  const int num_half = num / 2;
  
  for (i = 2; i <= num_half; ++i) {
    if (num % i == 0) {
      return false;
    }
  }

  // if we reach here, no divisor was found for the number
  return true;
}

/**
 * Function to find the median value in an array according to the order given
 * by the comparison function, i.e. 
 * there are equally many numbers left and right of the median in the array once it is sorted.
 * 
 * If the array has an even number of elements, we define the median to
 * be on the right side, i.e. there is one element less right from than the median
 * than there is to the left
 * 
 * @param array
 * @param len
 * @return 
 */
int FindMedian(int* array, const int len, int (*compfun)(const void*, const void*)) {
  
  int median_val;
  
  int* copy_for_sort = malloc(len * sizeof(int));
  memcpy(copy_for_sort, array, len * sizeof(int));
  
  qsort(copy_for_sort, len, sizeof(int), compfun);
  
  // debug
  printf("Sorted array: \n");
  int i = 0;
  for (i = 0; i < len; ++i) {
    printf("%i ", copy_for_sort[i]);    
  }
  printf("\n");
  
  // pick the middle element of the sorted array
  // -> recall: 3/2 = 1 since C uses truncation towards 0
  median_val = copy_for_sort[len/2];
  
  // debug
  printf("-> Median value is at idx %i and has value %i \n", len/2, median_val);
  
  // Free
  free(copy_for_sort);
  
  return median_val;
}

void PrintArray1d(int* arr, const int dim1) {  
  int i; 
  for (i = 0; i < dim1; ++i) {
    printf("arr[%i]=%i \n", i, arr[i]);
  }
  printf("\n");
  return;
}

void PrintArray2D(int** arr, const int dim1, const int dim2) {
  
  int i = 0, j = 0;
  
  for (i = 0; i < dim1; ++i) {
    printf("row i = %i:  ", i);
    for (j = 0; j < dim2; ++j) {
      printf("%+03i ", arr[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  
  return;
}

void FreePointer2D(int** ptr, const int dim1) {
  int i = 0;
  
  for (i = 0; i < dim1; ++i) {
    free(ptr[i]);
  }
  free(ptr);
  
  return;
}


// check if n = pow(m, k) for some k > 0
// --> repeatedly divide n by m and check that the remainder is 0 until
//     n is 1
//
// Note: also works for negative numbers , e.g. (-8, 2)
//       -8 / 2 = -4
//       -4 / 2 = -2
//       -2 / 2 = -1 
//       -1 / 2 =  0    + (-1)  -> a remainder is found so 8 is not a power of 2
//
//       -8 / -2 = 4
//        4 / -2 = -2
//       -2 / -2 = 1           ->  1 is reached without a remainder, -8 is power of -2
bool IsPowerOf(int n, int m) {
  
  int i = 0;
    
  if (m == 1) {
    if (n == 1) {
      return true;
    } else {
      return false; // pow(1, k) is always 1 
    }
  }
  
  if (m == -1) {    
    if (n == 1 || n == -1) {
      return true;
    } else {
      return false; // pow(-1, k) is 1 or -1 
    }
  }
    
  bool is_power_of = true;
  
  while (n != 1) {
    // if n is a power of m, the remainder of a division must be 0
    if (n % m != 0) {
      is_power_of = false;
      break;
    }    
    n = n / m;    
  }
  
  return is_power_of;  
}


bool IsPowerOf_Recursion(int n, int m) {
  // check corner cases:  
  if (m == 1) {
    if (n == 1) {
      return true;
    } else {
      return false; // pow(1, k) is 1 for all k >= 0
    }
  }  
  if (m == -1) {    
    if (n == 1 || n == -1) {
      return true;
    } else {
      return false; // pow(-1, k) is 1 or -1 
    }
  }
  
  // actual algorithm
  int div = n / m;
  int mod = n % m;
  if (mod != 0) {
    return false;
  } else {
    if (div == 1) {  // base case: div==1 and mod==0
      return true;  
    } else { // recursion case: div!=1 and mod==0
      return IsPowerOf_Recursion(n / m, m);    
    }  
  }
       
}

bool IsPowerOf_RecursionMult(int n, int m, int base) {  
  if (n == m) {
    return true;
  } else if (abs(m) > abs(n)) {
    return false;
  } else {  
    return IsPowerOf_RecursionMult(n, m*base, base);
  }
}


/**
 * 
 *  Find the intersection of two intervals.
 * 
 *  Whether an intersection exists or not, can be found out 
 *  checking if one of the borders of the second interval is inside the first interval.
 * 
 *  a.)  Check left border of 2 is inside 1
 * 
 *                      |---------------------|
 *                      l1                   r1
 *                                         |--------------------|
 *                                        l2                   r2
 * 
 *   --> intersection [l2, r1]
 *  
 * 
 *                      |---------------------|
 *                      l1                   r1
 *                                    |----|
 *                                    l2  r2
 * 
 *   --> intersection [l2, r2]
 * 
 *  b.) Check right border of 2 is inside 1
 * 
 *                      |---------------------|
 *                      l1                   r1
 *    |--------------------|
 *    l2                   r2
 * 
 *   --> intersection [l1, r2]
 * 
 *                      |---------------------|
 *                      l1                   r1
 *                         |-------|
 *                         l2     r2
 * 
 *   --> intersection [l2, r2] 
 *
 * 
 * We have an intersection if one of the borders of interval 2 is inside 
 * interval 1.
 * 
 *        l2 >= l1 && l2<= r1
 *   ||   r2 >= l1 && r2<= r1
 * 
 * @param interval1
 * @param interval2
 * @return 
 */
ClosedIntervalT FindIntersection(ClosedIntervalT interval1, ClosedIntervalT interval2) {
  
  ClosedIntervalT intersection = { -1, -1, -1, false };
  
  int l1 = interval1.left;
  int r1 = interval1.rght;
  int l2 = interval2.left;
  int r2 = interval2.rght;
  
  if (l2 >= l1 && l2 <= r1) {
    intersection.left = l2;
    intersection.rght = r1 < r2 ? r1 : r2;    
    intersection.len = intersection.rght - intersection.left;
  } else if (r2 >= l1 && r2 <= r1) {
    intersection.left = l1 > l2 ? l1 : l2;
    intersection.rght = r2;
    intersection.len = intersection.rght - intersection.left;
  }
  
  return intersection;
}

/**
 * Swap two integers.
 * 
 * @param a
 * @param b
 */
void SwapInts(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
  return;
}


/******************************** COMPARSION FUNCS *********/

int CompFunInt_Ascending(const int x1, const int x2) {    
  return x1 - x2;  
}
int CompFunInt_Descending(const int x1, const int x2) {    
  return x2 - x1;  
}

/**
 * Note: the usage of void* allows to have all compare methods 
 *       have the same signature !!!
 *       (no matter what the complex datatypes they compare are!)
 * 
 * @param ptr1
 * @param ptr2
 * @return 
 */
int CompFunIntptr_Ascending(const void* ptr1, const void* ptr2) {  
  // retrieve the correct types that we want to use
  int* int_ptr1 = (int*) ptr1;
  int* int_ptr2 = (int*) ptr2;
  return *int_ptr1 - *int_ptr2;  
}
  
int CompFunIntptr_Descending(const void* ptr1, const void* ptr2) {  
  // retrieve the correct types that we want to use
  int* int_ptr1 = (int*) ptr1;
  int* int_ptr2 = (int*) ptr2;
  return *int_ptr2 - *int_ptr1;  
}

int CompFunBorderpointPtr_Ascending(const void* ptr1, const void* ptr2) {
  BorderPointT* cast_ptr1 = (BorderPointT*) ptr1;
  BorderPointT* cast_ptr2 = (BorderPointT*) ptr2;
  int diff = cast_ptr1->x - cast_ptr2->x;
  if (diff == 0) {
    if (cast_ptr1->left_border && !cast_ptr2->left_border) {
      diff = -1;
    } else if (!cast_ptr1->left_border && cast_ptr2->left_border) {
      diff = +1;
    }
  }
  return diff;
}

int CompFunClosedIntervalPtr_Ascending(const void* ptr1, const void* ptr2) {
  ClosedIntervalT* cast_ptr1 = (ClosedIntervalT*) ptr1;
  ClosedIntervalT* cast_ptr2 = (ClosedIntervalT*) ptr2;
  int diff = cast_ptr1->left - cast_ptr2->left;
  if (diff == 0) {
    diff = cast_ptr1->rght - cast_ptr2->rght;
  }
  return diff;
}

int CompFunOpenClosedIntervalPtr_Ascending(const void* ptr1, const void* ptr2) {  
  OpenOrClosedIntervalT* cast_ptr1 = (OpenOrClosedIntervalT*) ptr1;
  OpenOrClosedIntervalT* cast_ptr2 = (OpenOrClosedIntervalT*) ptr2;
  int diff = cast_ptr1->left - cast_ptr2->left;
  if (diff == 0) { // let left_closed come before left_open
    diff = (cast_ptr1->left_closed ? -1 : (cast_ptr2->left_closed ? 1 : 0));
  }
  return diff;
}