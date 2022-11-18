/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Note: 
 * 
 *  We using the function pointer 
 * 
 *        int (*compfun_int)(const int, const int)
 * 
 *  allover here as a first step indicating how one would do sorting
 *  in a more general setup, not restricting to arrays of integers
 *  but allowing complex datatypes that need their custom comparator functions.
 * 
 *  --> to allow for generic datatypes, one should write everything 
 *      in terms of void pointers:
 * 
 *        int (*compFun)(const void*, const void*)
 * 
 *      and then construct compFun according to the convention
 *        
 *        compFun(x,y) should return < 0
 *        if x is less than y,
 *        
 *        compFun(x,y) should return > 0
 *        if y is less than x.
 * 
 *      and in C-library functions will always sort from least to highest.
 * 
 */

/**
 * NOTE: the terms smaller and larger are very misleading when it 
 *       comes to discussing "sorting".
 * 
 *       --> we define them in the following way here:
 * 
 *       smaller: node A is smaller than node B if with respect to a 
 *                given ordering A comes before B 
 *                (if in a sorted array of all nodes A is before B)
 * 
 *       larger: node A is smaller than node B if with respect to a 
 *               given ordering A comes after B 
 * 
 */

#include "sorting_algos.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "arrays.h"
#include "searching.h"
#include "heap_as_nodes.h"
#include "utils.h"


void MainSortingAlgos() {    
  printf("\n\n----------------------- MainSortingAlgos \n");
    
  //-----------------------------------------
  // preparations:  
  int n = 5;
  int arr_randomized[n];
  int arr[n];
  
  printf("\n\n-- preparation: array with random numbers \n");
  Array_FillWithRandomNumbers(MAX_RAND_NUM, n, arr_randomized);  
  memcpy(arr, arr_randomized, sizeof(int)*n);  
  PrintArray1d(arr, n);
  
  // print min, max of array
  int i_min = Array_FindExtremum(CompFunInt_Descending, n, arr);
  int i_max = Array_FindExtremum(CompFunInt_Ascending, n, arr);
  printf("Min found at arr[%i] = %i \n", i_min, arr[i_min]);
  printf("Max found at arr[%i] = %i \n", i_max, arr[i_max]);  
  
  //-----------------------------------------
  // Test sorting algorithms  
    
  // array bubble sort
  printf("\n\n----------------------- Bubble Sort \n");
  memcpy(arr, arr_randomized, sizeof(int)*n);
  BubbleSortArrayInt(CompFunInt_Ascending, n, arr);
  PrintArray1d(arr, n);
    
  // selection sort
  printf("\n\n----------------------- Selection Sort \n");
  memcpy(arr, arr_randomized, sizeof(int)*n);
  SelectionSortArrayInt(CompFunInt_Ascending, n, arr);
  PrintArray1d(arr, n);
    
  // heap sort
  printf("\n\n----------------------- Heap Sort \n");
  memcpy(arr, arr_randomized, sizeof(int)*n);
  HeapSortArrayInt(CompFunInt_Ascending, n, arr);
  PrintArray1d(arr, n);
    
  // insertion sort
  printf("\n\n----------------------- Insertion Sort \n");
  memcpy(arr, arr_randomized, sizeof(int)*n);
  InsertionSortArrayInt(CompFunInt_Ascending, n, arr);
  PrintArray1d(arr, n);
    
  // insertion sort with binary search for insert idx
  printf("\n\n----------------------- Insertion Sort with BS\n");  
  memcpy(arr, arr_randomized, sizeof(int)*n);
  InsertionSortArrayIntWithBS(CompFunInt_Ascending, n, arr);
  PrintArray1d(arr, n);
  
  // count sort 
  printf("\n\n----------------------- Count Sort \n");  
  memcpy(arr, arr_randomized, sizeof(int)*n);
  CountingSortArrayInt(n, arr, MAX_RAND_NUM, 0);
  PrintArray1d(arr, n);
    
  // bucket sort 
  printf("\n\n----------------------- Bucket Sort \n");  
  memcpy(arr, arr_randomized, sizeof(int)*n);
  BucketSortArrayInt(n, arr, MAX_RAND_NUM, 0);
  PrintArray1d(arr, n);
  
  // radix sort 
  printf("\n\n----------------------- Radix Sort \n");  
  memcpy(arr, arr_randomized, sizeof(int)*n);
  LSDRadixSortArrayInt(n, arr);
  PrintArray1d(arr, n);  
  
  // Quick sort
  printf("\n\n----------------------- Quick Sort \n");
  memcpy(arr, arr_randomized, sizeof(int)*n);
  QuicksortArray(arr, 0, n - 1);
  PrintArray1d(arr, n);
  
  // Quick sort Dutch Flag
  printf("\n\n----------------------- Quick Sort Dutch flag \n");
  memcpy(arr, arr_randomized, sizeof(int)*n);
  QuicksortArrayDutchFlag(arr, 0, n - 1);
  PrintArray1d(arr, n);  
      
  // merge sort
  printf("\n\n----------------------- Merge Sort \n");
  memcpy(arr, arr_randomized, sizeof(int)*n);
  MergeSortArrayInt(arr, 0, n - 1);
  PrintArray1d(arr, n);
    
  return;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

/**
 * Make n rounds through the array, 
 * and in each round check the element and its neighbor
 *   -> swap if they do not fulfill the order
 *   => similar to selection sort, 
 *      the idea is that in each round we get at least one element in order,
 *      namely the opposite extremum (at least additional ordering is done
 *      for all elements reached before the one element that will be ordered). 
 *      
 *      This is implemented by swapping neighbors until
 *      the end. This guarantess that once the opposite extremum is reached
 *      it will be swapped until it reaches the opposite end:
 * 
 *      e.g.   in   1, 5, 9, 4, 2, 8, 3
 * 
 *      when sorting for minimum-first, in the first round, 9 will reach
 *      its correct position at the end. 
 *    
 * time-complexity: average O(n*n), best-case (already sorted): O(n)
 * 
 * @param len
 * @param arr
 */
void BubbleSortArrayInt(int (*compfun_int)(const int, const int),
        const int len, int* arr) {  
  int i;  
  int n_swaps = -1;
  int round = 0;
  while (n_swaps != 0) {
    n_swaps = 0;
    for (i = 0; i < len - 1 - round; ++i) {
      int l = arr[i];
      int r = arr[i+1];
      if (compfun_int(l,r) > 0) {  // > 0 means r should come before l
        ++n_swaps;
        SwapInts(arr + i, arr + i + 1);
      }
    }    
    ++round; // not needed, but more efficient, by sparing already sorted elements
  }  
  return;
}

/**
 * Select extremum of a step by step shrinking array.
 * in the first run, we find the global extremum and put it to the front.
 * then we work on the subarray excluding the front-element and repeat the step. 
 * 
 * Note: is very similar to bubble-sort, but does precisely sort 
 *       only one element per round, 
 * 
 * time-complexity: O(n*n), always, even if arr is actually sorted already
 * 
 * @param len
 * @param arr
 */
void SelectionSortArrayInt(int (*compfun_int)(const int, const int),
        const int len, int* arr) {
  
  int i, j;
  int val_rghtmost_sorted;
  int idx_local, idx_global;
    
  for (i = 0; i < len; ++i) {
    // i is the length of the sorted subarray
    val_rghtmost_sorted = arr[i];
    idx_local = Array_FindExtremum(compfun_int, len - i, arr + i);
    int idx_global = i + idx_local;
    int extremum_of_rest = arr[idx_global];
    //printf("Found extremum of the rest is arr[%i] = %i \n",
    //        idx_global, extremum_of_rest);
    if (compfun_int(val_rghtmost_sorted, extremum_of_rest) > 0) {   // > 0 means extremum_of_rest should come before val_rghtmost_sorted
      SwapInts(arr + i, arr + idx_global);
      val_rghtmost_sorted = arr[i];
    }
  }  
  
  // --> inefficient version: swapping too many times
  /*
  int candidate;
  for (i = 0; i < len; ++i) {
    for (j = i + 1; j < len; ++j) {
      curr_extremum = arr[i];
      candidate = arr[j];
      if (compfun_int(curr_extremum, candidate) > 0) { // > 0 means, candidate should come before curr_extremum
        SwapInts(arr + i, arr + j);
      }
    }
  }
  */
  
  return;
}


/**
 * A modified selection sort that stores the unsorted elements in a
 * heap which allows O(1) finding of the max/min. However, 
 * the build-up of the heap means to insert n elements,
 * so that the algorithm is
 * 
 *  Time:  O(n log(n))
 *  space: O(n)
 * 
 * @param compfun_int
 * @param len
 * @param arr
 */
void HeapSortArrayInt(int (*compfun_int)(const int, const int),
        const int len, int* arr) {
  
  enum {
    kMinHeap,
    kMaxHeap
  };
  
  // determine the order given by the compfun_int function
  int heap_kind = 0;
  if(compfun_int(1, 2) < 0) {  // < 0 means 1 should come before 2
    heap_kind = kMinHeap;
  } else {
    heap_kind = kMaxHeap;
  }
  
  // build-up the heap
  HeapType heap_unsorted_elems = { 0 };
  if (heap_kind == kMinHeap) {
    heap_unsorted_elems.compfun_ptr = BinaryTree_CompFunPtrToNodePtr_Ascending;
  } else {
    heap_unsorted_elems.compfun_ptr = BinaryTree_CompFunPtrToNodePtr_Descending;
  }
  int i;
  BTNodeT nodes[len];
  for (i = 0; i < len; ++i) {
    nodes[i].key = arr[i];
    Heap_Push(&heap_unsorted_elems, nodes + i, 
            heap_unsorted_elems.compfun_ptr);
  }
  
  // fill up arr from heap in O(n) time  
  for (i = 0; i < len; ++i) {
    BTNodeT* curr_root = Heap_Pop(&heap_unsorted_elems, 
            heap_unsorted_elems.compfun_ptr);
    arr[i] = curr_root->key;
  } 
  
  return;
}


/**
 * Like selection sort, insertion sort just cares about getting one more
 * element in order in each round
 * (however, after k rounds just the first k elements are ordered, 
 *  whereas in selection sort the k extremal elements are ordered to the beginning)
 * 
 * time-complexity: O(n*n) average, O(n) if already sorted.
 * 
 * @param compfun_int
 * @param len
 * @param arr
 */
void InsertionSortArrayInt(int (*compfun_int)(const int, const int),
        const int len, int* arr) {
  
  int i, j;
  
  for (i = 1; i < len; ++i) {
    int* unsorted_arr = arr + i;
    int leftmost_in_unsorted_part = unsorted_arr[0];    
    // Assuming all previous elements are sorted, swap back the new one
    bool swapped;
    j = 0;
    do {
      swapped = false;
      int curr_elem_in_sorted_part = arr[i - j - 1];
      if (compfun_int(curr_elem_in_sorted_part, leftmost_in_unsorted_part) > 0) { // > 0 means leftmost_in_unsorted_part should come before curr_elem_in_sorted_part
        SwapInts(arr + i - j, arr + i - j - 1);
        swapped = true;
      }        
      ++j;
    } while (swapped && i - j - 1 >= 0);      
  }  
  
  return;
}

/**
 * Modified Insertion Sort that uses binary search to find the 
 * index of the elment after that the new element has to be inserted
 * in order to sustain order.
 * 
 * @param compfun_int
 * @param len
 * @param arr
 */
void InsertionSortArrayIntWithBS(int (*compfun_int)(const int, const int),
        const int len, int* arr) {
  
  int i, j;
  
  for (i = 1; i < len; ++i) {
    int len_already_sorted = i;
    int leftmost_in_unsorted_part = arr[i];
    // Search in sorted subarray for highest idx that fulfills order    
    int i_insert_after = Searching_BinarySearch_InsertPosition(
        compfun_int, leftmost_in_unsorted_part, len_already_sorted, arr);
    // insert
    int i_insert = i_insert_after + 1;
    int len_tobeshifted = len_already_sorted - i_insert;
    memmove(arr + i_insert + 1, arr + i_insert , sizeof(int)*len_tobeshifted);      
    arr[i_insert] = leftmost_in_unsorted_part;
    ++len_already_sorted;
  }
    
  return;
}

/**
 * Counting Sort is only efficient, if the range of values
 * in the array is very restricted.
 * 
 * Note: we assume here that the values in the array are between
 * max_val and min_val, including min_val and max_val.
 * 
 * 
 * @param compfun_int
 * @param len
 * @param arr
 * @param max_val
 */
void CountingSortArrayInt(const int len, int* arr,
        const int max_val, const int min_val) {
  
  int n_vals_possible = max_val - min_val + 1;
  int occurrences[n_vals_possible];
  memset(occurrences, 0, sizeof(int)*n_vals_possible);
  
  // count occurrences for each possible value
  int i;
  for (i = 0; i < len; ++i) {
    if (arr[i] < min_val || arr[i] > max_val) {
      printf("Error: counting sort only works for values in (%i, .., %i).\n", 
              min_val, max_val);
      return;
    }
    ++occurrences[arr[i] - min_val]; // arr[i]==maxval raises last elem in occurrences
  }
  
  // use occurrences info to fill array sortedly
  int j;
  int counter = 0;
  for (i = min_val; i <= max_val; ++i) {
    for (j = 0; j < occurrences[i - min_val]; ++j) {
      arr[counter++] = i;
    }
  }
  
  return;
}

/**
 * Is a variant of count sort that tries to make count sort applicable
 * for a arrays in which the values can come from a larger range.
 * 
 * The idea is to define several buckets that represent a part of the
 * whole possible value range, so that the range represented by all
 * buckets is the full range of possible values.
 * 
 * Then the values of the array are distributed to their fitting bucket
 * and each bucket is sorted with countsort. 
 * Finally the array is built from the sorted buckets.
 * 
 * @param compfun_int
 * @param len
 * @param arr
 * @param max_val
 * @param min_val
 */
void BucketSortArrayInt(const int len, int* arr, 
        const int max_val, const int min_val) {
  const int kNBuckets = 4;  
  int n_vals_possible_total = max_val - min_val + 1;
  int n_vals_possible_bucket = n_vals_possible_total / kNBuckets;
  n_vals_possible_bucket += n_vals_possible_total % kNBuckets > 0 ? 1 : 0;
  int buckets[kNBuckets][len];  
  int min_vals[kNBuckets];
  int n_elems_in_bucket[kNBuckets];
  memset(n_elems_in_bucket, 0, sizeof(int)*kNBuckets);
    
  int i, j; 
  
  for (i = 0; i < kNBuckets; ++i) {
    min_vals[i] = i * n_vals_possible_bucket;
  }
  
  // for simplicity, we use for the buckets arrays that potentially stores 
  // the full array and only fill them up as far as needed
  // -> in practice one would use some more efficient data struct for the buckets
  for (i = 0; i < len; ++i) {
    int curr_val = arr[i];
    // find the correct bucket (could be more efficient by binary search)
    j = 0;
    while (curr_val >= min_vals[j]) {
      ++j;
      if (j >= kNBuckets) {
        break;
      }
    }
    // now j-1 is the bucket that curr_val belongs to
    int bucket_id = j - 1;
    buckets[bucket_id][n_elems_in_bucket[bucket_id]++] = curr_val;    
  }
  
  // sort each of the buckets
  int id;
  for (id = 0; id < kNBuckets; ++id) {
    int min_val_bucket = min_vals[id];
    // note: for the last bucket max_val_bucket may be beyond the actual
    //       range of values, but this way each bucket has the same
    //       number of possible values, which can make things simpler
    int max_val_bucket = min_val_bucket + n_vals_possible_bucket - 1;    
    CountingSortArrayInt(n_elems_in_bucket[id], buckets[id], 
            max_val_bucket, min_val_bucket);    
  }
  
  // refill the original array
  int counter = 0;
  for (id = 0; id < kNBuckets; ++id) {
    for (i = 0; i < n_elems_in_bucket[id]; ++i) {
      arr[counter++] = buckets[id][i];
    }    
  }
  
  return;
}


/**
 * There are two key insights needed to understand radix sort:
 * 
 *  1. the number with the most digits in the array determines
 *     the number of rounds needed for sorting, say w for width
 *     --> all numbers with less than w digits need to be 
 *         seen as 0-padded from the left, in order for the 
 *         algorithm to understand that at these higher-significance digits
 *         the number is as small as possible 
 * 
 *  2. the sorting in round 2 relies essentially 
 *     on the fact that the numbers were already sorted in round 1
 *     with respect to the LestSignificantDigit.
 *     --> when in round 2 a number is reached before another one
 *         and both have the same digit at position 2 than 
 *         they need to remain in that order after the new round
 *         (FIFO processing can be used !)
 * 
 *  E.g.:  Given an input like 
 *  
 *          {   4,  15,  11,   1,  10, 102,  32 }
 * 
 *  we need to understand that as
 * 
 *          { 004, 015, 011, 001, 010, 102, 032 }
 * 
 *  Then in round 1 we will get
 * 
 *          { 10, 11, 1, 102, 32, 4, 15 }
 * 
 *  Now in round 2, numbers with the same digit at pos 2 have to sustain
 *  their order, e.g. {1, 102, 4}, { 10, 11, 15 }, {32}, which gives
 * 
 *          { 1, 102, 4, 10, 11, 15, 32 }
 * 
 *  and in the last round the numbers which still have a third digit
 *  float to the back
 *          
 *          { 1, 4, 10, 11, 15, 32, 102 }
 * 
 * @param len
 * @param arr
 */
void LSDRadixSortArrayInt(const int len, int* arr) {
  
  // use a bucket for each digit from 0...9  
  // -> Note: we use a large array for each bucket for simplicity
  //          but in practice one would use some data struct that only
  //          stores the needed number of elemenents, e.g. a list 
  int lsd_bucket[10][len];
  int nelems_in_bucket[10];
      
  int i, j;
  int lsd = 0;
  bool more_significant_digit_found = true;
    
  int nth_digit = 0;
  while (more_significant_digit_found) {
    memset(lsd_bucket, 0, sizeof(lsd_bucket));    
    memset(nelems_in_bucket, 0, sizeof(nelems_in_bucket));
    more_significant_digit_found = false;
    for (i = 0; i < len; ++i) {
      // "rightshift" the number until lsd of this round is reached
      int tmp = arr[i];
      tmp /= pow(10, nth_digit);
      lsd = tmp % 10;
      // if for any element another digit is present, we need a next round
      if (more_significant_digit_found == false && (tmp / 10 > 0)) {
        more_significant_digit_found = true;
      }
      // distribute to buckets
      lsd_bucket[lsd][nelems_in_bucket[lsd]++] = arr[i];            
    }
    // Refill the array such that the lsds are grouped together
    int counter = 0;
    for (lsd = 0; lsd < 10; ++lsd) {
      for (i = 0; i < nelems_in_bucket[lsd]; ++i) {
        arr[counter++] = lsd_bucket[lsd][i];
      }
    }
    ++nth_digit;
  }
  
  return;
}


void QuicksortArray(int* arr, int l, int r) {  
  if (l >= r) {return;}  
  int idx_pivot = Array_PartitionAroundRandomPivot_Inplace(arr, l, r);  
  QuicksortArray(arr, l, idx_pivot - 1);
  QuicksortArray(arr, idx_pivot + 1, r);  
  return;
}


void QuicksortArray_UsingOofNMemory(int* const arr, const int len){  
  // Recursion base case:
  if (len <= 1) { return; }  
  int idx_pivot = Array_PartitionAroundRandomPivot_UsingOofNMemory(arr, 0, len - 1);  
  QuicksortArray_UsingOofNMemory(arr, idx_pivot);
  QuicksortArray_UsingOofNMemory(arr + idx_pivot + 1, len - idx_pivot - 1);  
  return;
}


void QuicksortArrayDutchFlag(int *arr, int l, int r) {
  if (l >= r) {return;}  
  int idx_pivot = Array_PartioningDutchFlag(arr, l, r);  
  QuicksortArray(arr, l, idx_pivot - 1);
  QuicksortArray(arr, idx_pivot + 1, r);  
  return;
}


/**
 * 
 * 
 * time-complexity: O(n log(n)), in all cases
 * space-complexity: O(n)
 * 
 * @param compfun_int
 * @param len
 * @param arr
 */
void MergeSortArrayInt(int* arr, int l, int r) {  
  if (l >= r) return;
  int m = l + (r - l) / 2; // m goes left, if n even
  MergeSortArrayInt(arr, l, m); 
  MergeSortArrayInt(arr, m + 1, r);      
  MergeTwoSortedHalves(arr, l, m, r);  
  return;
}

/**
 * 
 * We assume arr_merged is allocated for length len1 + len2
 * 
 * TODO: bugfix, access arr1 or arr2 only if i1 or i2 within range !
 *       --> they can go beyond the len by one 
 * 
 * @param compfun_int
 * @param len1
 * @param len2
 * @param arr1
 * @param arr2
 * @param arr_merged
 */
void MergeTwoSortedHalves(int *arr, int l, int m, int r) {
  int n_left = m - l + 1;
  int n_rght = r - (m + 1) + 1;
  int left[n_left], rght[n_rght];
  memcpy(left, arr + l, n_left * sizeof(int));
  memcpy(rght, arr + l + n_left, n_rght * sizeof(int));
  int il = 0, ir = 0, write_i = l;
  while (il < n_left && ir < n_rght) {
    if (left[il] < rght[ir]) {
      arr[write_i++] = left[il++];
    } else {
      arr[write_i++] = rght[ir++];
    }
  }  
  // copy remaining elements of one array
  while (il < n_left) {arr[write_i++] = left[il++];}
  while (ir < n_rght) {arr[write_i++] = rght[ir++];}  
  return;
}


