/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "heap_as_array.h"
#include "heap_as_nodes.h"
#include "sorting.h"

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


void MainHeapAsArray() {
  printf("\n\n----------------------- MainHeapAsArray \n");
    
  //-----------------------------------------
  // preparations:
  
  //-----------------------------------------
  // Exercises  
    
  MainHeapAsArray_API();  
  
  MainHeapAsArray_UnionOfSortedSequences(); 
    
  MainHeapAsArray_SortIncreasingDecreasingArray();  
  
  MainHeapAsArray_SortAlmostSortedArray();
  
  MainHeapAsArray_FindKSmallestElementsInArray();
    
  MainHeapAsArray_UpdateMedianInStreamInputOofnSpace();
  
  MainHeapAsArray_FindKSmallestElementsMinHeap();
    
  return;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
  
void MainHeapAsArray_API() {
  printf("\n----------------------------------- MainHeapAsArray_API \n"); 
  
  // create a heap
  HeapAsArrayT myh;
  HeapAsArray_Init(&myh, CompFunInt_Ascending);
  
  // fill heap
  int i;
  printf("Filling up the heap: \n");
  for (i = 0; i < 11; ++i) {
    printf("adding: %i \n", i);
    HeapAsArray_Push(&myh, &((DataNodeIntKeyIntValT){i, -42}));
    printf("new top-element: %i \n", HeapAsArray_Top(&myh)->key);  
  }
  printf("\n");
  
  // print heap in-order
  printf("InOrder traversal of heap: \n");
  HeapAsArray_PrintInOrder(&myh);
  printf("\n");
  
  // popping some elements
  printf("Popping some elements: \n");
  int n_pop = 10;
  while (n_pop--) {    
    printf("popping element: %i \n", HeapAsArray_Top(&myh)->key);
    HeapAsArray_Pop(&myh);
    printf("new top element: %i \n", HeapAsArray_Top(&myh)->key);
  }
  printf("\n");    
  
  HeapAsArray_Destroy(&myh);
  return;  
}

void MainHeapAsArray_UnionOfSortedSequences() {
  printf("\n----------------------------------- MainHeapAsArray_UnionOfSortedSequences \n"); 

  // create some sorted sequences
  // Note: use first element to store size of the array
  int n_sequences = 5;
  int** sorted_sequences = calloc(n_sequences, sizeof(int*));
  
#define LEN_ARR 13
  sorted_sequences[0] = calloc(LEN_ARR, sizeof(int));
  sorted_sequences[0][0] = LEN_ARR;
  int i;
  for (i = 1; i < LEN_ARR; ++i) { sorted_sequences[0][i] = 2 * i; }
  
  sorted_sequences[1] = calloc(4, sizeof(int));
  sorted_sequences[1][0] = 4;
  sorted_sequences[1][1] = 9;
  sorted_sequences[1][2] = 9;
  sorted_sequences[1][3] = 12;
  
  sorted_sequences[2] = calloc(3, sizeof(int));
  sorted_sequences[2][0] = 3;
  sorted_sequences[2][1] = 13;
  sorted_sequences[2][2] = 33;
    
  sorted_sequences[3] = calloc(6, sizeof(int));
  sorted_sequences[3][0] = 6;
  sorted_sequences[3][1] = 1;
  sorted_sequences[3][2] = 2;
  sorted_sequences[3][3] = 3;
  sorted_sequences[3][4] = 4;
  sorted_sequences[3][5] = 5;
  
  sorted_sequences[4] = calloc(2, sizeof(int));
  sorted_sequences[4][0] = 2;
  sorted_sequences[4][1] = 42;
  
  printf("We want to compute the sorted union of sequences: \n");
  for (i = 0; i < n_sequences; ++i) {
    int j;
    int n_in_seq = sorted_sequences[i][0];
    printf("Sequence %i has %i elements and reads \n", i, n_in_seq);
    for (j = 1; j < n_in_seq; ++j) {
      printf("%i \n", sorted_sequences[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  
  // build the union
  int* union_sorted = HeapAsArray_UnionOfSortedSequences(sorted_sequences, 
          n_sequences);
  
  // print result
  int n_total = union_sorted[0];
  printf("The sorted union contains %i elements and reads: \n", n_total);
  for (i = 1; i < n_total; ++i) {
    printf("union_sorted[%i] = %i \n", i, union_sorted[i]);
  }
  printf("\n");
  
  // free
  for (i = 0; i < n_sequences; ++i) {
    free(sorted_sequences[i]);
  }
  free(sorted_sequences);
  free(union_sorted);  
  return;
}

void MainHeapAsArray_SortIncreasingDecreasingArray() {  
  printf("\n----------------------------------- MainHeapAsArray_SortIncreasingDecreasingArray \n"); 
  
  int inc_dec_arr[] = {1,2,3,4,7,10,3,4,2,1,0,9,10,20,11,10,9,40,1,5,6};
  int n_elems = sizeof(inc_dec_arr) / sizeof(int);
  
  // print
  printf("The input array reads: \n");
  int i;
  for (i = 0; i < n_elems; ++i) {
    printf("%i \n", inc_dec_arr[i]);    
  }
  printf("\n");
  
  // sort the increasing decreasing array
  int* sorted = HeapAsArray_SortIncreasingDecreasingArray(inc_dec_arr, n_elems);
  
  // print result  
  printf("The output after sorting reads: \n");
  for (i = 1; i < sorted[0]; ++i) {
    printf("%i \n", sorted[i]);    
  }
  printf("\n");
  
  // free
  free(sorted);
  return;
}


void MainHeapAsArray_SortAlmostSortedArray() {  
  printf("\n----------------------------------- MainHeapAsArray_SortAlmostSortedArray \n");

  int almost_sorted[] = {2,1,6,7,4,0,3,10,8,11,5,15,9,14,13,12};
  int max_away = 5;  // e.g. 0 is shifted by 5 away from beginning
  int n = sizeof(almost_sorted) / sizeof(int);
  
  // print
  printf("The input array reads: \n");
  int i;
  for (i = 0; i < n; ++i) {
    printf("%i \n", almost_sorted[i]);    
  }
  printf("\n");
  
  // sort the increasing decreasing array
  HeapAsArray_SortAlmostSortedArray(almost_sorted, n, max_away);
  
  // print result  
  printf("The output after sorting reads: \n");
  for (i = 0; i < n; ++i) {
    printf("%i \n", almost_sorted[i]);    
  }
  printf("\n");
  
  return;
}



void MainHeapAsArray_FindKSmallestElementsInArray() {  
  printf("\n----------------------------------- MainHeapAsArray_FindKSmallestElements \n");

  int random_arr[] = {2,1,6,7,4,0,3,10,8,11,5,15,9,14,13,12};
  int n = sizeof(random_arr) / sizeof(int);
  
  // print
  printf("The input array reads: \n");
  int i;
  for (i = 0; i < n; ++i) {
    printf("%i \n", random_arr[i]);    
  }
  printf("\n");
  
  // find the k-smallest elements
  int k = 5;
  int smallest[k];
  HeapAsArray_KSmallestElementsInArray(random_arr, n, smallest, k);
  
  // print result  
  printf("The %i smallest elements in the array are: \n", k);
  for (i = 0; i < k; ++i) {
    printf("%i \n", smallest[i]);    
  }
  printf("\n");
  
  return;
}


void MainHeapAsArray_UpdateMedianInStreamInputOofnSpace() {  
  printf("\n----------------------------------- MainHeapAsArray_UpdateMedianInStreamInputOofnSpace \n");

  //int stream[] = {2,1,6,7,4,0,3,10,8,11,5,15,9,14,13,12};
  int stream[] = {1,0,3,5,2,0,1};
  int n = sizeof(stream) / sizeof(int);
  
  // print
  printf("The input stream reads: \n");
  int i;
  for (i = 0; i < n; ++i) {
    printf("%i \n", stream[i]);    
  }
  printf("\n");
  
  // find the median  
  float medians[n];
  HeapAsArray_UpdateMedianInStreamInputOofnSpace(stream, n, medians);
  
  // print result  
  printf("The medians at each step of the stream read: \n");  
  for (i = 0; i < n; ++i) {
    printf("%.2f \n", medians[i]);    
  }
  printf("\n");
  
  return;
}

void MainHeapAsArray_FindKSmallestElementsMinHeap() {
  printf("\n----------------------------------- MainHeapAsArray_FindKSmallestElementsMinHeap \n");

  // create a heap
  int random_nums[] = {2,1,6,7,4,0,3,10,8,11,5,15,9,14,13,12};
  int n = sizeof(random_nums) / sizeof(int);
  HeapAsArrayT myh;
  HeapAsArray_Init(&myh, CompFunInt_Ascending);
  HeapAsArray_PushArrayOfInt(&myh, random_nums, n);
  
  // print
  printf("Build a heap of numbers: \n");
  int i;
  for (i = 0; i < n; ++i) {
    printf("%i \n", random_nums[i]);    
  }
  printf("\n");
  
  // find k smallest elements
  int k = 6;
  int smallest[k];
  HeapAsArray_KSmallestElementsInMinHeap(&myh, k, smallest);
  
  // print result
  printf("The k smallest elements are: \n");  
  for (i = 0; i < k; ++i) {
    printf("%i \n", smallest[i]);    
  }
  printf("\n");
  
  HeapAsArray_Destroy(&myh);
  return;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

// ------------------------------------------- heap API

/**
 * Algo: Tentatively insert the new element at the next free slot in the heap.
 * 
 *       --> "bubble-up" the element by swapping it with its parent
 *           until a parent is larger than the element or until it is the
 *           new root
 * 
 * Example:  Insert element 9 into
 *              11
 *        5             8           
 *    4       4       7    3
 *   2  1   1  3    5 
 * 
 * Next free slot:  right child of 7
 * 
 *              11
 *        5             8         -> temporarily we violate the heap property
 *    4       4       7    3 
 *   2  1   1  3    5   9 
 *   
 *               11
 *        5             8
 *    4       4       9    3 
 *   2  1   1  3    5   7 
 * 
 *               11
 *        5             9         -> now we have a heap again
 *    4       4       8    3 
 *   2  1   1  3    5   7
 * @param h
 * @param new_node
 */
void HeapAsArray_Push(HeapAsArrayT* h, DataNodeIntKeyIntValT* new_node) {
  if (h->n_elems == h->capacity) {
    HeapAsArray_Resize(h);
  }
  int i_bubble = h->n_elems;
  h->arr[i_bubble] = *new_node; // tentatively insert at last node
  ++(h->n_elems);  
  // bubble-up from bottom
  int i_parent = HeapAsArray_IdxOfParent(i_bubble);
  while (i_bubble > 0 && h->comp(h->arr[i_bubble].key, h->arr[i_parent].key) < 0) {
    HeapAsArray_SwapContent(&h->arr[i_bubble], &h->arr[i_parent]);
    i_bubble = i_parent;
    i_parent = HeapAsArray_IdxOfParent(i_bubble);
  }
  return;  
}
void HeapAsArray_PushArrayOfInt(HeapAsArrayT* h, int* arr, int k) {
  int i;
  for (i = 0; i < k; ++i) {
    HeapAsArray_Push(h, &((DataNodeIntKeyIntValT){arr[i], -42}));
  }
  return;
}

/**
 * Algo:  we tentatively swap the top element with the last element
 *        and then decrease the number of elements.
 * 
 *        --> "bubble-down" the element that is swapped tentatively to the top
 *            until it is bigger than its children or until it has no children
 * 
 * 
 * @param h
 */
void HeapAsArray_Pop(HeapAsArrayT* h) {  
  if (h->n_elems == 0) {return;}
  HeapAsArray_SwapContent(&h->arr[0], &h->arr[h->n_elems - 1]);
  --(h->n_elems);
  // bubble-down tentative top-element until ok, or until it is leaf
  if (h->n_elems > 1) {    
    int i_bubble = 0, i_priochild = HeapAsArray_IdxPrioChild(h, i_bubble);
    // if children exist, we may need to swap further
    while (i_priochild != -1 &&
            h->comp(h->arr[i_bubble].key, h->arr[i_priochild].key) > 0) {
      HeapAsArray_SwapContent(&h->arr[i_bubble], &h->arr[i_priochild]);
      i_bubble = i_priochild;
      i_priochild = HeapAsArray_IdxPrioChild(h, i_bubble);
    }
  }
  return;
}

/**
 * Note: returning pointer to the node here but expecting
 *       caller to dereference and copy content because
 *       the adress is not guaranteed to stay with the node.
 * 
 * @param h
 * @return 
 */
DataNodeIntKeyIntValT* HeapAsArray_Top(HeapAsArrayT* h) {
  return (h->n_elems > 0 ? &(h->arr[0]) : NULL);
}


int HeapAsArray_IdxPrioChild(HeapAsArrayT* h, int idx) {
  int i_left = HeapAsArray_IdxLeftChild(idx);
  int i_rght = HeapAsArray_IdxRghtChild(idx);
   // largest priority = first element in order, i.e. smallest by chosen comp-fun
  int i_maxprio_child = -1; 
  bool has_leftchild = (i_left <= h->n_elems - 1);
  bool has_rghtchild = (i_rght <= h->n_elems - 1);
  if (has_leftchild && has_rghtchild) { // both exist
    i_maxprio_child = (h->comp(h->arr[i_left].key, h->arr[i_rght].key) < 0 ? 
      i_left : i_rght);
  } else if (has_leftchild) { // only left child exists
    i_maxprio_child = i_left;
  }
  return i_maxprio_child;
}

/**
 * Formula: easy to verify with example
 * 
 *                      0
 *              1              2
 *          3       4       5     6
 *      7     8   9  10   11 12 
 * 
 * @param idx
 * @return 
 */
int HeapAsArray_IdxOfParent(int idx) {
  return (idx > 0 ? (idx -1) / 2 : -1);
}
int HeapAsArray_IdxLeftChild(int idx) {
  return 2 * idx + 1;
}
int HeapAsArray_IdxRghtChild(int idx) {
  return 2 * idx + 2;
}

void HeapAsArray_SwapContent(DataNodeIntKeyIntValT* n, DataNodeIntKeyIntValT* m) {
  DataNodeIntKeyIntValT tmp = *n;
  memcpy(n, m, 1 * sizeof(DataNodeIntKeyIntValT)); // *n = *m;
  memcpy(m, &tmp, 1 * sizeof(DataNodeIntKeyIntValT)); // *m = tmp;
  return;
}

void HeapAsArray_Resize(HeapAsArrayT* h) {
  h->capacity *= 2;
  h->arr = realloc(h->arr, h->capacity * sizeof(DataNodeIntKeyIntValT));          
  return;
}

void HeapAsArray_Init(HeapAsArrayT* h, int (*comp)(const int, const int)) {
  h->capacity = 2;
  h->arr = calloc(h->capacity, sizeof(DataNodeIntKeyIntValT));
  h->n_elems = 0;
  h->comp = comp;
  return;
}
void HeapAsArray_Destroy(HeapAsArrayT* h) {
  free(h->arr);
  return;
}

/**
 * Note: using the array indices the algorithm is not as
 * trivial as its recursive counterpart using nodes.
 * 
 * Algo:
 * 
 *    3 actions at each node possible: step down left, print, step down right
 *    
 *    -> what we do depends on which of the three possible edges to the node 
 *       we are coming from ? 
 *       
 *       - if we arrived from a parent at its child
 *         we continue to go the next left child until we 
 *         are beyond the limits set by the number of elements
 * 
 *       - if we arrived from the left child at a parent, we print it,
 *         and then go to its right child
 * 
 *       - if we arrived from the right child at a parent, we continue
 *         to go to the next parent
 * 
 * Note: we also jump to indices outside of the heap
 * 
 * @param h
 */
void HeapAsArray_PrintInOrder(HeapAsArrayT* h) {  
  int i_prev = 0;
  int i_curr = 1;
  int n = h->n_elems;
  while (!(i_curr == 0 && i_prev == (n > 2 ? 2 : 1))) {    
    int i_left = HeapAsArray_IdxLeftChild(i_curr);
    int i_rght = HeapAsArray_IdxRghtChild(i_curr);
    int i_parent = HeapAsArray_IdxOfParent(i_curr);
    if (i_curr > n - 1 || i_prev == i_rght) { // outside heap or on way back up
      i_prev = i_curr;
      i_curr = i_parent;      
    } else { // still inside heap, continue descending if needed
      if (i_prev == i_parent) {
        i_prev = i_curr;
        i_curr = i_left;      
      } else { // by construction: i_prev == i_left
        printf("In-Order: %i \n", h->arr[i_curr].key);
        i_prev = i_curr;
        i_curr = i_rght;          
      }   
    }
  }
  return;
}


// ------------------------------------------------- Exercises

/**
 * Exercise:
 * 
 * Given m sorted sequences, find the sorted union.
 * 
 * Idea:
 * 
 * Simply writing all of them in an array and sorting would be O(n log n),
 * where n is the sum of the number of elements in each different sequence
 * We can, however, improve to O(n log m) by using O(m) additional space in a heap.
 * 
 * We fill the heap with the smallest element of each sequence. Then
 * we take the top element, write it to the result vector, pop it from the heap,
 * and fill up the heap with the next element of the sequence that the just 
 * popped element came from.
 * 
 * 
 * @param sorted_sequences
 * @param n_sequences
 * @return 
 */
int* HeapAsArray_UnionOfSortedSequences(int** sorted_sequences, int n_sequences) {
  int n_output = -n_sequences + 1; // only need one slot for the length
  int seq_id; 
  for (seq_id = 0; seq_id < n_sequences; ++seq_id) {
    n_output += sorted_sequences[seq_id][0];
  }
  int *union_sorted = calloc(n_output, sizeof(int));
  union_sorted[0] = n_output;
  
  // use a heap
  HeapAsArrayT myh;
  HeapAsArray_Init(&myh, CompFunInt_Ascending);
  
  // fill with 1st element of each sequence
  int itr[n_sequences];
  for (seq_id = 0; seq_id < n_sequences; ++seq_id) {    
    HeapAsArray_Push(&myh, &((DataNodeIntKeyIntValT){sorted_sequences[seq_id][1], seq_id}));    
    itr[seq_id] = 1;
  }
  
  // process all elements  
  int i_write = 1;
  while (myh.n_elems > 0) {
    union_sorted[i_write++] = HeapAsArray_Top(&myh)->key;
    seq_id = HeapAsArray_Top(&myh)->val;
    HeapAsArray_Pop(&myh);    
    int k_next = ++(itr[seq_id]);
    int k_max = sorted_sequences[seq_id][0] - 1;
    if (k_next <= k_max) { // not all values from that sequence processed
      HeapAsArray_Push(&myh, 
              &((DataNodeIntKeyIntValT){sorted_sequences[seq_id][k_next], seq_id}));
    }
  }
  
  // free
  HeapAsArray_Destroy(&myh);
  return union_sorted;
}


/**
 * Exercise: 
 * 
 * Given an array that consists of blocks that are increasing and
 * decreasing, sort the array.
 * 
 * Idea:
 * 
 * First, we can revert the decreasing parts to have an array
 * that consists of k increasing blocks. Thus we only
 * need to count k and then we can use the algorithm to merge 
 * k sorted arrays.
 * 
 * -> time complexity: O(n log k)
 * -> space complexity: O(k)  , (since i want to reuse the already implemented
 *    version of the merge algo, i use extra O(n) space to provide
 *    the input in the form the algo can process)
 * 
 * 
 * 
 * @param inc_dec
 * @param n
 * @return 
 */
int* HeapAsArray_SortIncreasingDecreasingArray(int* inc_dec, int n) {
  
  int** sorted_sequences = NULL;
  
  int i = 0, n_blocks = 0, n_inblock = 0;  
  int sign = 1;
  for (i = 0; i < n; i += n_inblock) {
    int i_start = i;
    if (i == 0 || i == n - 1) { ++i;}
    if (sign == 1) {
      while (i < n - 1 && inc_dec[i] >= inc_dec[i - 1]) {
        ++i;
      }
    } else {
      while (i < n - 1 && inc_dec[i] < inc_dec[i - 1]) {
        ++i;
      }      
      // revert decreasing block to increasing
      int k = i_start;
      int j = i - 1;
      while (k < j) {
        SwapInts(&(inc_dec[k++]), &(inc_dec[j--]));
      }
    }
    int n_inblock = i - i_start;
    sign *= -1;
    ++n_blocks;
    // build format that we need for other algo
    sorted_sequences = realloc(sorted_sequences, n_blocks * sizeof(int*));
    sorted_sequences[n_blocks - 1] = calloc(n_inblock + 1, sizeof(int));
    sorted_sequences[n_blocks - 1][0] = n_inblock + 1;
    memcpy(&(sorted_sequences[n_blocks - 1][1]), &inc_dec[i_start],
            n_inblock * sizeof(int));    
  }
  
  // result
  int* sorted = HeapAsArray_UnionOfSortedSequences(sorted_sequences, n_blocks);  
  
  // free
  for (i = 0; i < n_blocks; ++i) {
    free(sorted_sequences[i]);
  }
  free(sorted_sequences);
  return sorted;
}

/**
 * Exercise:
 * 
 * Sort an array, in which each value is maximally k slots away from
 * its sorted position (e.g. k=0 means the array is sorted already).
 * 
 * Idea:
 * 
 * If each value is maximally k-slots away, we can proceed through the
 * array with a heap that contains the current value and the k-next ones
 * and then put the min of the heap to the current position. then move
 * one further and fill the heap with the next appearing element.
 * 
 * Note: assume n > k
 * 
 * time complexity: O(n log k)
 * space complexity: O(k)
 * 
 * @param almost_sorted
 * @param n
 * @param k
 */
void HeapAsArray_SortAlmostSortedArray(int* almost_sorted, int n, int k) {  
  HeapAsArrayT myh;
  HeapAsArray_Init(&myh, CompFunInt_Ascending);
  HeapAsArray_PushArrayOfInt(&myh, almost_sorted, k + 1);
  int i = 0;
  while (myh.n_elems > 0) {
    almost_sorted[i] = HeapAsArray_Top(&myh)->key;
    HeapAsArray_Pop(&myh);    
    ++i;
    if (i + k < n) {
      HeapAsArray_Push(&myh, &((DataNodeIntKeyIntValT){almost_sorted[i + k], -42}));
    }
  }  
  // free
  HeapAsArray_Destroy(&myh);
  return;
}


/**
 * Exercise:
 * 
 * Given an array of random elements, find the k-smallest ones.
 * 
 * Idea:
 * 
 * The brute-force approach would start with the first k elements
 * as the candidates in the list of k-smallest, 
 * then look at the next and, if it is smaller than the max of the current
 * candidates replace the max in the candidates. to find the max among the
 * current candidates if O(k), so in total that would be O(n * k).
 * 
 * We can reduce to O(n * log k) with a max heap that stores the current
 * k smallest elements.
 * 
 * @param input
 * @param n
 * @param smallest
 * @param k
 */
void HeapAsArray_KSmallestElementsInArray(int* input, int n, int* smallest, int k) {  
  HeapAsArrayT myh;
  HeapAsArray_Init(&myh, CompFunInt_Descending);  
  HeapAsArray_PushArrayOfInt(&myh, input, k);  
  int i;
  for (i = k; i < n; ++i) {
    if (input[i] < HeapAsArray_Top(&myh)->key) {
      HeapAsArray_Pop(&myh);
      HeapAsArray_Push(&myh, &((DataNodeIntKeyIntValT){input[i], -42}));
    }
  }
  i = k - 1;
  while (myh.n_elems > 0) {
    smallest[i] = HeapAsArray_Top(&myh)->key;
    HeapAsArray_Pop(&myh);
    --i;
  }
  // free
  HeapAsArray_Destroy(&myh);
  return;
}

/**
 * Exercise:
 * 
 * Given a stream, compute the median, at each time a new element is added.
 * 
 * Note: we mimic the stream as an array and assume that we can store all
 *       elements.
 *       
 * 
 * Idea:
 * 
 *       if we would use the O(n) space for an array of all seen elements
 *       we would at least need O(n) time in each round to find the median,
 *       which would be O(n*n) after n elements.
 * 
 *       instead, we can use the O(n) space for two heaps.
 * 
 *       one for the maximum of the elements smaller than the current median
 *       one for the minimum of the elements larger/equal than the current median
 *    
 *       -> first assume: we had an odd number of elements before the new elem.
 * 
 *          then we have the median being identical with an element, 
 *          that we have stored outside of the heaps, and two heaps of equal size. 
 * 
 *          when a new element arrives, we have to check if it is largerequal or
 *          smaller than the median: depending on the outcome the smaller
 *          one goes to the smaller heap and the bigger to the bigger heap,
 *          the new median is the average of the two top-elements.
 * 
 *       -> now assume: we had an even number of elements before the new.
 * 
 *          check if the new element is smaller than the top of the smaller-heap,
 *          if yes, pop its top element to become the new median, and instead
 *          insert the new element there.
 *          if no, pop the top element of the other heap, and insert
 *          the new element there.
 *          
 *       Thus at each time, the two heaps have the same number of elements,
 *       and only if that sums up to an even number, we additionaly have
 *       the median element outside of the heaps.
 *       
 * 
 * @param stream
 * @param n
 * @return 
 */
void HeapAsArray_UpdateMedianInStreamInputOofnSpace(int* stream, int n, 
        float* medians) {  
  HeapAsArrayT maxh, minh;
  HeapAsArray_Init(&maxh, CompFunInt_Descending);  // contains < median elems
  HeapAsArray_Init(&minh, CompFunInt_Ascending);   // contains >= median elems
  int i;  
  for (i = 0; i < n; ++i) { // let the stream stream
    int new_elem = stream[i];
    HeapAsArray_Push(&maxh, &((DataNodeIntKeyIntValT){new_elem, -42}));
    HeapAsArray_Push(&minh, &((DataNodeIntKeyIntValT){
      HeapAsArray_Top(&maxh)->key, -42}));
    HeapAsArray_Pop(&maxh);        
    if (minh.n_elems > maxh.n_elems) { // with new elem we have n odd, before was even            
      HeapAsArray_Push(&maxh, &((DataNodeIntKeyIntValT){
        HeapAsArray_Top(&minh)->key, -42}));
      HeapAsArray_Pop(&minh);
    }
    medians[i] = (maxh.n_elems == minh.n_elems ?
      (HeapAsArray_Top(&maxh)->key + HeapAsArray_Top(&minh)->key) / 2. : 
      HeapAsArray_Top(&maxh)->key);    
  }
  HeapAsArray_Destroy(&maxh);
  HeapAsArray_Destroy(&minh);    
  return ;
}

/**
 * Exercise:
 * 
 * Given a min heap, find the k smallest elements.
 * 
 * Idea:
 * 
 * The smallest element is the top. The second smallest is its left or
 * right child. If it is the left, the set of candidates for the third smallest
 * contains still the right child of the root, and the left and right child
 * of the left child of the root. And so on and on.
 * 
 * -> we track the candidates indices in the heap and whenever a node is
 *    picked, we add its children to the heap for the next round
 * 
 * @param h
 * @param k
 * @param smallest
 */
void HeapAsArray_KSmallestElementsInMinHeap(HeapAsArrayT* minh, int k, 
        int* smallest) {  
  HeapAsArrayT minh_aux;
  HeapAsArray_Init(&minh_aux, CompFunInt_Ascending);
  HeapAsArray_Push(&minh_aux, &((DataNodeIntKeyIntValT){minh->arr[0].key, 0}));
  int i = 0;
  while (i < k && minh_aux.n_elems > 0) {
    int idx = HeapAsArray_Top(&minh_aux)->val;
    HeapAsArray_Pop(&minh_aux);
    smallest[i] = minh->arr[idx].key;
    int idx_left = HeapAsArray_IdxLeftChild(idx);
    int idx_rght = HeapAsArray_IdxRghtChild(idx);
    if (idx_left < minh->n_elems) 
      HeapAsArray_Push(&minh_aux, &((DataNodeIntKeyIntValT){minh->arr[idx_left].key, idx_left}));
    if (idx_rght < minh->n_elems)
      HeapAsArray_Push(&minh_aux, &((DataNodeIntKeyIntValT){minh->arr[idx_rght].key, idx_rght}));
    ++i;
  }  
  HeapAsArray_Destroy(&minh_aux);
  return;
}