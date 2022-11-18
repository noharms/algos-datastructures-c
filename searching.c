/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "searching.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "sorting.h"
#include "utils.h"


void MainSearching() {  
  printf("\n\n----------------------- MainSearching \n");
    
  //-----------------------------------------
  // preparations:
  
  //-----------------------------------------
  // Exercises  
  
  MainSearching_BinarySearch();
    
  MainSearching_BinarySearch_IndexEqualsKey();
  
  MainSearching_BinarySearch_CyclicShiftSortedArray();  
  
  MainSearching_BinarySearch_RoundedDownSquareRoot();
  
  MainSearching_BinarySearch_SquareRoot();
  
  MainSearching_BinarySearch_Quotient();
    
  MainSearching_KeyExistenceInSorted2dArray();
  
  MainSearching_FindAMissingIPaddress();
    
  MainSearching_FindMinMaxTogether();
    
  // wrong: this implementation assumes that input is sorted, except
  //        for the replaced element !
  // --> this assumption is not allowed
  // MainSearching_NNumbersSmallerNBut1Missing1Twice();
  
  return;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void MainSearching_BinarySearch() {
  printf("\n----------------------------------- MainSearching_BinarySearch \n");  
    
  // create some array 
  // good debug cases:
  //int arr[] = { 0, 1, 2, 3, 4, 4, 5, 5, 5, 5, 7, 7, 8, 9 }; 
  //int arr[] = { 0, 1, 2, 3, 4, 4, 5, 5, 5, 5};  
  //int arr[] = { 0, 1, 2, 3, 4, 4, 5};  
  //int arr[] = { 0, 1, 2, 3, 4, 4};  
  int arr[] = {5, 5, 5, 5, 5};
  int n = sizeof(arr) / sizeof(*arr);
  
  // print input
  printf("Working on array with elements: \n");
  PrintArray1d(arr, n);
  
  // setting  
  int target_key = 5;
  int key_idx;
  
  // find some target value: recursive version  
  key_idx = Searching_BinarySearchKey_Recursive(arr, 0, n - 1, target_key);  
  printf("Found key %i at idx = %i (recursive algo)\n", target_key, key_idx); 
  printf("\n");
  
  // find some target value: iterative version
  key_idx = Searching_BinarySearchKey_Iterative(arr, 0, n - 1, target_key);
  printf("Found key %i at idx = %i (iterative algo)\n", target_key, key_idx);
  printf("\n");
  
  // last smaller
  key_idx = Searching_BinarySearchKey_LastLess(arr, 0, n - 1, target_key);
  printf("Last element less key %i is at idx = %i \n", target_key, key_idx);  
  printf("\n");
  
  // 1st equal
  key_idx = Searching_BinarySearchKey_1stEq(arr, 0, n - 1, target_key);
  printf("First element equal to key %i is at idx = %i \n", target_key, key_idx);  
  printf("\n");
      
  // Last equal
  key_idx = Searching_BinarySearchKey_LastEq(arr, 0, n - 1, target_key);
  printf("Last element equal to key %i is at idx = %i \n", target_key, key_idx);  
  printf("\n");
  
  // 1st greater
  key_idx = Searching_BinarySearchKey_1stGtr(arr, 0, n - 1, target_key);
  printf("First element greater key %i is at idx = %i \n", target_key, key_idx);
  printf("\n");
    
    
  
  return;
}

void MainSearching_BinarySearch_IndexEqualsKey() {
  printf("\n----------------------------------- MainSearching_BinarySearch_IndexEqualsKey \n");
    
  // create some sorted array, NO DUPLICATES ALLOWED   
  int arr[] = {-5, -3, 0, 1, 2, 4, 6, 8};
  //int arr[] = {-5, -3, 0, 1, 2, 4, 7, 8};
  int n = sizeof(arr) / sizeof(*arr);
  
  // print input
  printf("Working on array with elements: \n");
  PrintArray1d(arr, n);
    
  // find element that matches index
  int idx_equal_key = Searching_BinarySearch_IndexEqualsKey(arr, 0, n - 1);
  if (idx_equal_key != -1) {
    printf("Found that element at idx %i matches its key %i. \n", idx_equal_key, arr[idx_equal_key]); 
  } else {
    printf("Found no index that matches its key. \n");
  }
  printf("\n");    
  return;
}



void MainSearching_BinarySearch_CyclicShiftSortedArray() {
  printf("\n----------------------------------- MainSearching_BinarySearch_CyclicShiftSortedArray \n");
    
  // create some sorted array, NO DUPLICATES ALLOWED   
  //int arr[] = {-5, -3, 0, 1, 2, 4, 6, 8};
  int arr[] = {4,6,8,-5, -3, 0, 1, 2};
  int n = sizeof(arr) / sizeof(*arr);
  
  // print input
  printf("Working on array with elements: \n");
  PrintArray1d(arr, n);
    
  // find minimum element
  int idx_min = Searching_BinarySearch_IdxOfMinimum(arr, 0, n - 1);
  printf("The minimum is at idx %i \n", idx_min);
  
  printf("\n");    
  return;
}


void MainSearching_BinarySearch_RoundedDownSquareRoot() {
  printf("\n----------------------------------- MainSearching_BinarySearch_RoundedDownSquareRoot \n");
    
  // find integer root
  //const int number = 17;
  //const int number = 16;
  const int number = 2;
  int integer_root = Searching_IntegerSquareRoot(number);
  printf("The integer root of %i is %i \n", number, integer_root);
  printf("For comparison: (int)sqrt(%i)=%i \n", number, (int)sqrt(number*1.));
  
  return;
}


void MainSearching_BinarySearch_SquareRoot() {
  printf("\n----------------------------------- MainSearching_BinarySearch_SquareRoot \n");
    
  // find float root
  //const float fnumber = 1.69;
  const float fnumber = 0.5;
  const float prec = pow(10, -6);
  //float float_root = Searching_FloatSquareRoot_old(fnumber, prec);
  float float_root = Searching_FloatSquareRoot(fnumber, prec);
  printf("The float root of %f, at prec=%.2e, is %f \n", fnumber, prec, float_root);
  
  return;
}

void MainSearching_BinarySearch_Quotient() {
  printf("\n----------------------------------- MainSearching_BinarySearch_Quotient \n");
    
  // find quotient
  const float prec = pow(10, -6);
  float x = 3;
  float y = 0.025;  
  float quotient = Searching_FloatQuotient(x, y, prec);
  printf("The quotient of x=%.2f and y=%.2f is: %.2f\n", x, y, quotient);
  
  return;  
}

void MainSearching_KeyExistenceInSorted2dArray() {  
  printf("\n----------------------------------- MainSearching_KeyExistenceInSorted2dArray \n");
  
  // created sorted 2dmatrix  
  int mat_cpy[6][5] = {
    {-1,2,4,4,6},
    {1,5,5,9,21},
    {3,6,6,9,22},
    {3,6,8,10,24},
    {6,8,9,12,25},
    {8,10,12,13,40}};
  int i, j;
  int n = 6, m = 5;
  int **mat = calloc(n, sizeof(int*));
  for (i = 0; i < n; ++i) {
    mat[i] = calloc(m, sizeof(int));
    for (j = 0; j < m; ++j) {
      mat[i][j] = mat_cpy[i][j];
    }
  }  
  
  // print    
  printf("Working on 2d matrix: \n");
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      printf("%2i ", mat[i][j]);
    }
    printf("\n");
  }
  printf("\n");
          
  // checking existence of keys
  for (i = 0; i < 15; ++i) {
    bool found = KeyExistenceInSorted2dArray(mat, n, m, i);
    printf("The key %i was %sfound.\n", i, (found ? "" : "not "));
  }
  
  // free  
  for (i = 0; i < n; ++i) {
    free(mat[i]);    
  }
  free(mat);
  return;
}

void MainSearching_FindAMissingIPaddress() {
  printf("\n----------------------------------- MainSearching_FindAMissingIPaddress \n");
  
  // write file
  char* abs_path = "/home/noh/NetBeansProjects/ProgrammingExercisesC/NetBeansProjects/ElementsOfProgrammingInterviews/input_files/ip_adresses.txt";
  //char* relative_path = "./../../../input_files/ip_adresses.txt";
  if (0) {        
    FILE* fp;
    fp = fopen(abs_path, "w+");
    int i, j, k, l;
    int kMax8Bit = 256;
    for (i = 0; i < kMax8Bit; i+= 9) {
      for (j = 0; j < kMax8Bit; j += 1) {
        for (k = 0; k < kMax8Bit; k += 21) {
          for (l = 0; l < kMax8Bit; l+= 27) {
            fprintf(fp, "%i.%i.%i.%i \n", i, j, k, l);
          }
        }        
      }      
    }
    fclose(fp);
  }
  
  // find an IP adress that is not in the file
  unsigned int missing_ip = FindAMissingIPaddress(abs_path);
  
  // print result
  char ip[16];
  Turn32bitToIpString(ip, missing_ip);
  printf("The algorithm found that the ip %s (%u) is not in the file. \n", ip, 
          missing_ip);
  
  return;
}

void MainSearching_FindMinMaxTogether() {
  printf("\n----------------------------------- MainSearching_FindMinMaxTogether \n");
  
  // some example array
  int arr[] = {4, 4, 1, -5, -14, 42, 5, 10, 11, 23, 0, 5, 90};
  int n = sizeof(arr) / sizeof(int);
  
  // print input
  printf("Working on array with elements: \n");
  PrintArray1d(arr, n);
  
  // find min and max together
  MinMaxT min_max = FindMinMaxTogether(arr, n);
  
  // print result
  printf("Found min = %i and max = %i \n", min_max.min, min_max.max);
  
  return;
}

void MainSearching_NNumbersSmallerNBut1Missing1Twice() {
  printf("\n----------------------------------- MainSearching_NNumbersSmallerNBut1Missing1Twice \n");
  
  // some example array
  int n = 99;
  int arr[n];
  int i;
  for (i = 0; i < n; ++i) {
    arr[i] = i;
  }
  int missing = 53;
  int duplicate = 4;
  arr[missing] = duplicate;
  
  // printf
  printf("Array from 0 to %i, with %i removed by %i \n", n - 1, missing, duplicate);
  
  // find missing and duplicate
  IntPairT miss_and_dupl = FindMissAndDuplInNNumbersFrom0ToN(arr, n);
  
  // print result
  printf("Algo found %i missing and %i duplicate. \n", miss_and_dupl.val1, 
          miss_and_dupl.val2);  
  
  return;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

/**
 * * We assume the array is sorted in ascending order.
 * 
 * @param target
 * @param len
 * @param arr
 * @return 
 */
int Searching_BinarySearchKey_Recursive(int* arr, int l, int r, const int key) {  
  if (l > r) return -1;
  int m = l + (r - l) / 2;
  if (arr[m] == key)
    return m;
  else if (arr[m] > key)
    return Searching_BinarySearchKey_Recursive(arr, l, m -1, key);
  else // arr[m] < key
    return Searching_BinarySearchKey_Recursive(arr, m + 1, r, key);  
}

int Searching_BinarySearchKey_Iterative(int* arr, int l, int r, const int key) {       
  while (l <= r) {    
    int m = l + (r - l) / 2;    // note: / rounds down, i.e. if r == l+1, m = l    
    if (arr[m] == key)
      return m;
    else if (arr[m] > key)
      r = m - 1;
    else // arr[m] < key
      l = m + 1; 
  }  
  return -1;
}

int Searching_BinarySearchKey_1stEq(int* arr, int l, int r, const int key) {
  int i_1st = -1;
  while (l <= r) {    
    int m = l + (r - l) / 2;   
    if (arr[m] == key) {
      i_1st = m;
      r = m - 1;
    } else if (arr[m] > key)
      r = m - 1;
    else // arr[m] < key
      l = m + 1; 
  }  
  return i_1st;
}

int Searching_BinarySearchKey_LastEq(int* arr, int l, int r, const int key) {
  int i_lasteq = -1;
  while (l <= r) {    
    int m = l + (r - l) / 2;
    if (arr[m] == key) {
      i_lasteq = m;
      l = m + 1;
    } else if (arr[m] > key)
      r = m - 1;
    else // arr[m] < key
      l = m + 1; 
  }  
  return i_lasteq;
}


int Searching_BinarySearchKey_1stEq_Alternative1(int* arr, int l, int r, const int key) {   
  int i_lastless = Searching_BinarySearchKey_LastLess(arr, l, r, key);
  if (i_lastless == -1 || i_lastless == r) {
    return (arr[l] == key ? l : - 1);
  } else {
    return (arr[i_lastless + 1] == key ? i_lastless + 1 : -1);
  }
}

// bad first idea: left for remembering the idea
int Searching_BinarySearchKey_1stEq_Alternative2(int* arr, int l, int r, const int key) {    
  int l_orig = l, r_orig = r;  
  int i_key = r_orig + 1;
  while (l <= r && l_orig < i_key) { // potential occurence within (l_orig, i_key)    
    int m = l;
    while (l <= r) {    
      m = l + (r - l) / 2;    // note: / rounds down, i.e. if r == l+1, m = l    
      if (arr[m] == key) {
        i_key = m;
        l = l_orig; // now try to find key farther left
        r = i_key - 1;
        break;
      } else if (arr[m] > key)
        r = m - 1;
      else // arr[m] < key
        l = m + 1; 
    }
    if (arr[m] != key) { // in this iteration key was not found
      break;
    }
  }
  return (i_key == r_orig + 1 ? -1 : i_key);
}

int Searching_BinarySearchKey_LastEq_Alternative1(int* arr, int l, int r, const int key) {
  int i_firstgtr = Searching_BinarySearchKey_1stGtr(arr, l, r, key);  
  if (i_firstgtr == -1 || i_firstgtr == l) { 
    return (arr[r] == key ? r : - 1);
  } else {
    return (arr[i_firstgtr - 1] == key ? i_firstgtr - 1 : -1);
  }
}

// bad first idea: left for remembering the idea
int Searching_BinarySearchKey_LastEq_Alternative2(int* arr, int l, int r, const int key) {    
  int r_orig = r;  
  int i_key = -1;
  while (l <= r && i_key < r_orig) { // potential duplicate farther right    
    int m = l;
    while (l <= r) {    
      m = l + (r - l) / 2;    // note: / rounds down, i.e. if r == l+1, m = l    
      if (arr[m] == key) {
        i_key = m;
        l = i_key + 1; // try to find it farther right
        r = r_orig;
        break;
      } else if (arr[m] > key)
        r = m - 1;
      else // arr[m] < key
        l = m + 1; 
    }
    if (arr[m] != key) { // in this iteration key was not found
      break;
    }
  }
  return i_key;
}

// 
int Searching_BinarySearchKey_LastLess(int* arr, int l, int r, const int key) {  
  while (l < r) {    
    int m = l + (r - l) / 2;
    if (m == l) ++m;
    if (arr[m] < key)
      l = m; // note: include m, because maybe all right of m are > key
    else if (arr[m] >= key)
      r = m - 1;  
  }
  return (arr[l] < key ? l : -1);
}


/**
 * Raise l to m+1, if up to and including m all are less than k.
 * Shrink r to m, if m is greater than key.
 * 
 * 
 * @param arr
 * @param l
 * @param r
 * @param key
 * @return 
 */
int Searching_BinarySearchKey_1stGtr(int* arr, int l, int r, const int key) {  
  while (l < r) {    
    int m = l + (r - l) / 2;
    if (arr[m] <= key)
      l = m + 1;
    else if (arr[m] > key)
      r = m;  // note: include m, because maybe all left of it are smaller
  }
  return (arr[r] > key ? r : -1);
}


/**
 * Finds first value that is greater than target key.
 * 
 * Idea: try to find key per binary search. 
 *      
 *        if we do not find it, return -1.
 *        if we find it, check if between the key and the rightmost element
 *        is another occurence.
 *          if not, i_key + 1 is the first element larger than key
 *          if yes, the new i_key is for sure farther right than the old,
 *          so repeat to check if we can find the key again farther right
 * 
 * 
 * @param arr
 * @param l
 * @param r
 * @param key
 * @return 
 */
int Searching_BinarySearchKey_1stGtrOrEq(int* arr, int l, int r, const int key) {
  int i_key = Searching_BinarySearchKey_1stEq(arr, l, r, key);
  if (i_key == -1) {
    i_key = Searching_BinarySearchKey_1stGtr(arr, l, r, key);
  }
  return i_key;
}


/**
 * The application in mind is 
 * a sorted array and some element which shall be inserted, so the position
 * for insertion shall be determined.
 * 
 * We start to compare the outside element with the rightmost element
 * of the array and check if the order is fulfilled by the two.
 * If yes, the new element would go right to the end,
 * if no, we continue to compare with the next element until 
 * we find the rightmost element in the array that still fulfills the order
 * with the new element.
 * --> the index of that element is returned
 * 
 * Note: name UpperBound comes from C++ library for searching the first element
 * that is larger than the target - here we search the index of this element
 * instead of its key.
 * 
 * @param OrderFulfilled
 * @param new_elem
 * @param len
 * @param arr
 * @return 
 */
int Searching_BinarySearch_InsertPosition(int (*comp)(const int, const int),
        const int new_elem, const int len, int* arr) {
  
  if (len <= 1) {
    if (comp(arr[0], new_elem) > 0) { // > 0 means true
      return 0;
    } else {
      return -1; // no elem in arr fulfills order! new_elem must be inserted before first elem
    }
  }
  
  int mid_idx = len / 2; // mid_idx >=1 because reaching here means len >= 2
  int val_at_mid_idx = arr[mid_idx];
  
  int len_left_subarray = mid_idx;
  int len_rght_subarray = len - len_left_subarray;
  
  int* subarray_left = arr;
  int* subarray_rght = arr + len_left_subarray;
  
  int hghst_idx_fulfills_order = 0;
  
  //----------------------------------- Recursive trap door !!!!
  if (comp(val_at_mid_idx, new_elem) > 0) {  // > 0 means true    
    hghst_idx_fulfills_order += mid_idx + 
            Searching_BinarySearch_InsertPosition(
              comp, new_elem, len_rght_subarray, subarray_rght);
  } else {
    hghst_idx_fulfills_order +=  
            Searching_BinarySearch_InsertPosition(
              comp, new_elem, len_left_subarray, subarray_left);    
  }
  
  printf("Highest Idx fulfilling order is found: %i \n", 
          hghst_idx_fulfills_order);
  return hghst_idx_fulfills_order;
}

/**
 * Exercise:
 * 
 * Given a sorted array without duplicates, find an index that matches its key.
 * 
 * Idea:
 * 
 * The candidate set can be easily restricted in each round:
 * 
 *    if arr[m] > m, then arr[k] > k for all k > m, because of the non-uniqueness
 *    of the values, will the value at least grow by one, i.e. as fast as the idx
 * 
 *    if arr[m] < m,then arr[k] < k for all k < m, because value will at least
 *    decrement by one, i.e. as fast the idx 
 * 
 * @param arr
 * @param l
 * @param r
 * @return 
 */
int Searching_BinarySearch_IndexEqualsKey(int *arr, int l, int r) {  
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (arr[m] == m) {
      return m;
    } else if (arr[m] > m) {
      r = m - 1;
    } else { // arr[m] < m
      l = m + 1;
    }
  }
  return -1;
}

/**
 * Exercise:
 * 
 * Given a sorted array without duplicates that is shifted by some shift k,
 * find the minimum element and thus the shift.
 * 
 * Idea:
 * 
 * Inspecting l, m, r, the minimum must lie between the maximum of the three
 * and the minimum of the three. 
 * 
 * If we see that arr[m] > arr[r], we know that m is the maximum of the three
 * so the minimum must be between (m + 1, r)
 * 
 * If arr[m] < arr[r] then l is the maximum of the three, so the minimum
 * must be between (l, m)
 * 
 * 
 * @param arr
 * @param l
 * @param r
 * @return 
 */
int Searching_BinarySearch_IdxOfMinimum(int *arr, int l, int r) {  
  while (l < r) {
    int m = l + (r - l) / 2;
    if (arr[m] > arr[r]) {
      l = m + 1;
    } else { // arr[m] < arr[r]
      r = m;
    }
  }
  return r;
}

/**
 * The integer square root of a number k is defined
 * as the biggest integer x among the set of integers
 * that fulfill x*x <= k .
 * 
 * @param number
 * @return 
 */
int Searching_IntegerSquareRoot(const int k) {    
  int l = 1, r = k;    
  while (l <= r){
    int m = l + (r - l)/2;    
    if (m * m > k) {
      r = m - 1;
    } else { // m*m <= k
      l = m + 1;
    }
  }  
  return l - 1;
}


/**
 * Note: for 0 < x < 1 , we have to set the initial right boundary to 1
 *       because 1 > sqrt(x) > x for 0 < x < 1
 * 
 * @param x
 * @param prec
 * @return 
 */
float Searching_FloatSquareRoot(const float x, const float prec) {  
  float l = 0., r = (x >= 1 ? x : 1);
  if (x >= 0) {    
    while (fabs(l*l - x) > prec) {
      float m = l + (r - l) / 2.;
      if (m * m > x) {
        r = m;
      } else { // m*m <= x
        l = m;
      }
    }
  }
  return l;
}
/**
 * 
 * Exercise: self implement division. addition and multiplication is allowed.
 * 
 * Idea: 
 * 
 *  for the divisor y in [1, infty), the candidate set of the result
 *  is (0, x)
 * 
 *  for the divisor y in  (0, 1), however the candidate set of the result
 *  is in (x, infty).
 * 
 *  -> the difficulty lies thus in finding an appropriate restriction
 *  for the candidate region to search in. we can do this by noting
 *  that if 1 < y < x, the candidate region is upper bound by x.
 *  if 0.1 < y < 1, the candidate region is upper bound by 10*x
 *  if 0.01 < y < 0.1, the candidate region is upper bound by 100*x.
 * 
 * @param x
 * @param y
 * @param prec
 * @return 
 */
float Searching_FloatQuotient(float x, float y, const float prec) {
  float l, r;
  if (y < 1) {
    l = x;
    int mult = 10;
    while (y*mult < x) {
      mult *= 10;
    }
    r = mult*x;
  } else {
    l = 0;
    r = x;
  }
  while (fabs(l * y - x) > prec) {
    float m = l + (r - l) / 2.;
    if (m * y > x) {
      r = m;
    } else { // m * y <= x
      l = m;
    }
  }
  return l;
}

/**
 * Exercise: 
 * 
 * Given a 2d sorted matrix, find out if a given key exists or not.
 * 
 * Idea:
 * 
 * One can always look at that corner element which connects its
 * row and column to be one sorted array of n + m - 1 elements.
 * The information if the key is greater or smaller then allows
 * to discard either the n or the m elements. Continue with the 
 * next corner element.
 * 
 * @param mat
 * @param n
 * @param m
 * @param key
 * @return 
 */
bool KeyExistenceInSorted2dArray(int **mat, int n, int m, int key) {  
  int i = 0, j = m - 1;
  while (i <= n -1 && j >= 0) {
    int corner = mat[i][j];
    if (corner == key) { // 
      return true;
    } else if (corner < key) { // discard row
      ++i;
    } else { // m > key   // discard column
      --j;
    }
  }
  return false;
} 


/**
 * Exercise:
 * 
 * Given a file that lists billions of ip-adresses and the info that
 * at least one ip-adress is missing, find a missing ip-adress. Note
 * that there are ~4 billion 4byte adresses, i.e. potentially 16G.
 * Thus, you cannot read all of them into RAM and then work on that.
 * 
 * Idea:
 * 
 * We can count how many ip-adresses we find for each possible value
 * of the first byte. Since we know that one ip is missing,
 * we know that one count will stay below 256*256*256 ~ 1.7*pow(10,9).
 * 
 * In fact, we can directly count for each possible value of the first
 * two bytes because the RAM can well hold 256*256=65536 counts.
 * 
 * @param path_to_file
 * @return 
 */
unsigned int FindAMissingIPaddress(char* path_to_file) {
  
  FILE* fp;
  fp = fopen(path_to_file, "r");
  if (!fp) {
    printf("File: %s was not found. Exercise 'FindAMissingIPaddress' aborted. \n",
            path_to_file);
    return 0;
  }
  
  // make one round to count how many ip-adresses appear for all first 2 bytes
  int count[256*256] = {0}; // 256*256 == 1 << 16
  char buffer[256];
  while (fgets(buffer, 256, fp)) {
    unsigned int byte1, byte2;
    sscanf(buffer, "%u.%u.*u.*u", &byte1, &byte2);
    ++count[256*byte1 + byte2];
  }
  // find one count < 256
  int i;
  unsigned int missing_ip_byte1and2;
  for (i = 0; i < 256*256; ++i) {
    if (count[i] < 256) { // found it
      missing_ip_byte1and2 = i;
      break;
    }
  }
  // make a second round
  rewind(fp);
  memset(count, 0, sizeof(count));
  while (fgets(buffer, 256, fp)) {
    unsigned int byte1, byte2, byte3, byte4;
    sscanf(buffer, "%u.%u.*u.*u", &byte1, &byte2);
    if (256*byte1 + byte2 == missing_ip_byte1and2) {
      sscanf(buffer, "%*u.%*u.%u.%u", &byte3, &byte4);
      ++count[256*byte3 + byte4];
    }    
  }
  // find a number that was not found to be present
  unsigned int missing_ip_byte3and3;
  for (i = 0; i < 256*256; ++i) {
    if (!count[i]) { // found it
      missing_ip_byte3and3 = i;
      break;
    }
  }
  
  // close filestream and return
  fclose(fp);  
  return 256*256*missing_ip_byte1and2 + missing_ip_byte3and3;
}

void Turn32bitToIpString(char* dst, unsigned int ip) {
  unsigned char byte1, byte2, byte3, byte4;
  byte4 = ip % 256;
  ip /= 256;
  byte3 = ip % 256;
  ip /= 256;
  byte2 = ip % 256;
  ip /= 256;
  byte1 = ip % 256;
  ip /= 256;
  sprintf(dst, "%u.%u.%u.%u", byte1, byte2, byte3, byte4);
  return;
}

/**
 * Exercise:
 * 
 * The minimum of an array is found by (n-1) comparisons.
 * The maximum of an array is found by (n-1) comparisons.
 * 
 * -> Design an algorithm that finds min and max together but still needs
 *    less than 2n-2 comparisons (since comparisons may be expensive !)
 * 
 * Idea:
 * 
 *    Work on pairs of numbers and use a firt comparison to find the min/max
 *    of the pair, and then two more comparisons to check if the found min/max
 *    replace the current global min/max.
 * 
 *    -> assuming n is even, 
 *    we have n/2 pairs, so (n/2 -1) * 3 comparisons + 1 for setting the
 *    initial values to global min/max from 1st pair: 3/2 * n - 2
 * 
 *    (if n is odd, we have two more comparisons for the last element)
 * 
 * @param arr
 * @param n
 * @return 
 */
MinMaxT FindMinMaxTogether(int* arr, int n) {
  if (n == 1) { return (MinMaxT){arr[0], arr[0]};}
  MinMaxT minmax = {arr[0], arr[1]};
  if (minmax.min > minmax.max) {
    SwapInts(&(minmax.min), &(minmax.max));
  }
  int i;
  for (i = 2; i < n; i += 2) {
    int min_local, max_local;
    if (arr[i] < arr[i + 1]) {
      min_local = arr[i];
      max_local = arr[i + 1];
    } else {
      min_local = arr[i + 1];
      max_local = arr[i];      
    }    
    minmax.min = (min_local < minmax.min ? min_local : minmax.min);
    minmax.max = (max_local > minmax.max ? max_local : minmax.min);
  }
  if (n % 2) {
    minmax.min = (arr[n - 1] < minmax.min ? arr[n - 1] : minmax.min);
    minmax.max = (arr[n - 1] > minmax.min ? arr[n - 1] : minmax.max);
  }
  return minmax;
}


/**
 * Exercise:
 * 
 * Given an array of n numbers from 0 to n-1, where one number is replaced
 * by another one, so that one number between [0, .., n-1] is missing
 * and one is duplicate, find the missing and the duplicate number.
 * 
 * Idea:
 * 
 *    Gauss(n-1) := Sum(i, 0, n-1)(i) = n * (n - 1) / 2
 * 
 *    So we can sum up all appearing numbers, find the difference to Gauss
 *    and then we know the difference between the removed and the duplicated
 *    number. However, this is not always unique, e.g. removing 0 and replacing
 *    it by n-1 increases Gauss by n-1, and there is no other combination
 *    that increases by that much, however, removing 0 and duplicating
 *    1 increases Gauss by 1, as does removing 1 and duplicating 2.
 * 
 *    -> the found difference indicates how far apart the missing and the
 *    duplicate element are in a sorted array
 *    -> we need a second round checking all pairs that are the distance apart
 *    to find which one is actually duplicated
 * 
 * @param arr
 * @param n
 * @return 
 */
IntPairT FindMissAndDuplInNNumbersFrom0ToN(int* arr, int n) {
  int i;
  int gauss = n * (n-1) / 2;
  int sum = 0;
  for (i = 0; i < n; ++i) {
    sum += arr[i];
  }
  int diff = abs(gauss - sum);
  if (diff == 0) {
    printf("No number missing between 0 and %i .\n", n - 1);
    return (IntPairT){-1, -1};
  }
  int i_diffahead = diff;
  i = 0;
  while (i_diffahead < n && arr[i] != arr[i_diffahead]) {
    ++i;
    ++i_diffahead;
  }
  int duplicate = arr[i];
  int miss = (sum > gauss ? duplicate - diff : duplicate + diff);
  return (IntPairT){miss, duplicate};
}