/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

// corresponding h file
#include "arrays.h"

// system files
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// other c-files' headers and project-wide headers
#include "sorting_algos.h"
#include "utils.h"

/*** VLA's 
 * variable-length arrays were introduced in C99.
 * Only allowed inside functions, not globally !
 */
/*
 * Example: this global declaration will not compile
 */
//const int len = 10;
//int vla[len];  
/*
 * Example: this global declaration will compile
 */
#define LEN 10
int VLA[LEN];

#define ARR_LEN 6

typedef enum {
  kTrue,
  kFalse    
} BoolT;

const int kDim = 9;  // for Sudoku

void MainArrays() {
  printf("\n\n----------------------- MainArrays \n");
    
  //-----------------------------------------
  // preparations:
  
  //-----------------------------------------
  // Exercises  
  
  MainArray_KthSmallest_RandomizedSelection();
    
  MainArray_PartitionEvenOdd();  
    
  MainArray_Partition2ValuedArray();
    
  MainArray_Quicksort();
  
  MainArray_IncrementDigitSequence();
  
  MainArray_CheckAdvanceThroughBoardGame();
  
  MainArray_RemoveDuplicatesFromSortedArray();
    
  MainArray_NextSmallerNumberWithSameDigits();  
  
  MainArray_NextLargerNumberWithSameDigits();
  
  // 2d
  MainArray_TestSudokuFilling();
    
  return;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void MainArray_KthSmallest_RandomizedSelection() {
  printf("\n----------------------------------- MainArray_KthSmallest_RandomizedSelection \n");  
    
  // get an array filled with random numbers
  int n = ARR_LEN;
  int arr[n];
  Array_FillWithRandomNumbers(MAX_RAND_NUM, n, arr);
  
  // for debug
/*
  arr[0]=8 ;
  arr[1]=29; 
  arr[2]=33; 
  arr[3]=24; 
  arr[4]=39; 
  arr[5]=33; 
  arr[6]=7 ;
  arr[7]=1 ;
  arr[8]=39; 
  arr[9]=28;
*/

  // print input
  printf("Working on array with elements: \n");
  PrintArray1d(arr, n);
  
  int k = 3;
  int kth_smallest = Array_KthSmallest_RandomizedSelection(arr, 0, n -1, k);
  
  // print result
  printf("Found %ith-smallest to be: %i \n", k, kth_smallest);  
  
  return;
}

void MainArray_PartitionEvenOdd() {
  printf("\n----------------------------------- MainArray_PartitionEvenOdd \n"); 
  
  // get an array filled with random numbers  
  int n = ARR_LEN;
  int arr[n];
  Array_FillWithRandomNumbers(MAX_RAND_NUM, n, arr);  
  // debug case
/*
  arr[0]=29; 
  arr[1]=35;
  arr[2]=3; 
  arr[3]=17; 
  arr[4]=31;
  arr[5]=7; 
*/
  
  // print input
  printf("Working on array with elements: \n");
  PrintArray1d(arr, n);
  
  // partition | even | odd |
  Array_PartitionEvenOdd(arr, n);
  
  // print result
  printf("After partitioning the array reads: \n");
  PrintArray1d(arr, n);
   
  return;
}


void MainArray_Partition2ValuedArray() {
  printf("\n----------------------------------- MainArray_Partition2ValuedArray \n"); 
  
  // array with only two possible values
  int n = ARR_LEN;
  int arr[n];
  Array_FillWithRandomNumbers(MAX_RAND_NUM, n, arr);
  int i;
  int arr_bool[n];  
  for (i = 0; i < n; ++i) {
      arr_bool[i] = arr[i] % 2;
  }
  
  // print input
  printf("Working on array with elements: \n");
  PrintArray1d(arr_bool, n);  
  
  // partition
  Array_Partition2ValuedArray(arr_bool, n);
    
  // print result
  printf("After partitioning the array reads: \n");
  PrintArray1d(arr_bool, n); 
  
  return;
}


void MainArray_Quicksort() {
  printf("\n----------------------------------- MainArray_Quicksort \n"); 
  
  // get an array filled with random numbers
  int n = ARR_LEN;
  int arr[n], arr_bckp[n];
  Array_FillWithRandomNumbers(MAX_RAND_NUM, n, arr);
  memcpy(arr_bckp, arr, n * sizeof(int));
    
  // print input
  printf("Working on array with elements: \n");
  PrintArray1d(arr, n);
  
  // QuickSort the array using simple partitioning
  QuicksortArray_UsingOofNMemory(arr, n);  
  printf("Result using simple quicksort (O(n) space): \n");
  PrintArray1d(arr, n);
  
  // QuickSort the array using partitioning
  memcpy(arr, arr_bckp, n * sizeof(int));
  QuicksortArray(arr, 0, n - 1);  
  printf("Result using quicksort with inplace partitioning: \n");
  PrintArray1d(arr, n);
  
  // QuickSort the array using Dutch Flag
  memcpy(arr, arr_bckp, n * sizeof(int));
  QuicksortArrayDutchFlag(arr, 0, n - 1);  
  printf("Result using quicksort with dutch-flag partitioning: \n");
  PrintArray1d(arr, n);
 
  return;
}

void MainArray_CheckAdvanceThroughBoardGame() {
  printf("\n----------------------------------- MainArray_CheckAdvanceThroughBoardGame \n"); 
  
  // build boardgame: array with each entry smaller than max moves
#define MAX_MOVES_PER_TURN 5
  int n = ARR_LEN;
  int arr[n], board_game[n];
  Array_FillWithRandomNumbers(MAX_RAND_NUM, n, arr);
  int i;  
  for (i = 0; i < n; ++i) {
      board_game[i] = arr[i] % MAX_MOVES_PER_TURN;
  }
  
  // print input
  printf("Working on array with elements: \n");
  PrintArray1d(board_game, n);  
  
  // check if advance to end is possible
  Array_CheckAdvanceToEndPossible(arr, n);  // TODO: clean up
  
  return;
}

void MainArray_RemoveDuplicatesFromSortedArray() {
  printf("\n----------------------------------- MainArray_RemoveDuplicatesFromSortedArray \n"); 
  
  // create sorted array
  int n = ARR_LEN;
  int arr[n];
  int max_rand = 5;
  Array_FillWithRandomNumbers(max_rand, n, arr);
  qsort(arr, n, sizeof(int), CompFunIntptr_Ascending);
  
  // print input
  printf("Working on array with elements: \n");
  PrintArray1d(arr, n);
  
  // remove duplicates
  int n_distinct = Array_RemoveDuplicatesFromSortedArray(arr, n);
    
  // print result
  printf("After removing duplicates \n");
  PrintArray1d(arr, n_distinct);
    
  return;
}

void MainArray_IncrementDigitSequence() {
  printf("\n----------------------------------- MainArray_IncrementDigitSequence \n"); 
    
  // build array of decimal digits
  int n = ARR_LEN;
  int arr[n];
  Array_FillWithRandomNumbers(MAX_RAND_NUM, n, arr);
  int i;  
  int digit_sequence[n];  
  for (i = 0; i < n; ++i) {
      digit_sequence[i] = arr[i] % 10;
  }
  digit_sequence[n - 1] = 9;
  digit_sequence[n - 2] = 9;
  
  // print input
  printf("Working on array with elements: \n");
  PrintArray1d(digit_sequence, n);  
  
  // increment by 1
  Array_IncrementArrayRepresentingDecimal(digit_sequence, n);
  
  // print result
  printf("After incrementing the digit sequence we have: \n");
  PrintArray1d(digit_sequence, n); 
  
  return;
}

void MainArray_NextSmallerNumberWithSameDigits() {
  printf("\n----------------------------------- MainArray_NextSmallerNumberWithSameDigits \n"); 
  unsigned long long n = 12312315;
  unsigned long long next = Array_NextSmallerNumberWithSameDigits(n);
  printf("Given\n%llu, the next smaller number with same digits is: \n", n);
  printf("%llu \n", next);
  return;
}
  
void MainArray_NextLargerNumberWithSameDigits() {
  printf("\n----------------------------------- MainArray_NextLargerNumberWithSameDigits \n"); 
  unsigned long long n = 12312315;
  unsigned long long next = Array_NextLargerNumberWithSameDigits(n);
  printf("Given\n%llu, the next larger number with same digits is: \n", n);
  printf("%llu \n", next);
  return;
}

void MainArray_TestSudokuFilling() {
  printf("\n----------------------------------- MainArray_TestSudokuFilling \n"); 
  unsigned int correct_board[9][9] = {
    {5,7,6,8,4,1,3,9,2},
    {1,8,3,9,7,2,4,5,6},
    {9,4,2,5,3,6,8,7,1},
    {3,1,7,6,2,4,5,8,9},
    {6,2,8,7,9,5,1,3,4},
    {4,5,9,1,8,3,6,2,7},
    {7,9,4,3,6,8,2,1,5},
    {8,6,5,2,1,9,7,4,3},
    {2,3,1,4,5,7,9,6,8}
  };
  unsigned int incorrect_board[9][9] = {
    {5,7,6,8,4,1,3,9,2},
    {1,8,3,9,7,2,4,5,6},
    {9,4,2,5,3,6,8,7,1},
    {3,1,7,6,2,4,5,8,9},
    {6,2,8,7,9,5,1,3,4},
    {4,5,9,1,8,3,6,2,7},
    {7,9,4,3,6,8,2,1,5},
    {8,6,5,2,1,9,7,4,3},
    {2,3,1,4,5,7,9,6,1}  // error: introduced in last slot
  };
  printf("The test of the first board is: %s \n", (IsSudokuFillingCorrect(correct_board) ? 
    "positive " : "negative "));
  printf("The test of the second board is: %s \n", (IsSudokuFillingCorrect(incorrect_board) ? 
    "positive " : "negative "));
  return;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//---------------------------------- ARRAY HELPER FUNCTIONS

/**
 * 
 * @param max_val
 * @param len
 * @param arr
 */
void Array_FillWithRandomNumbers(const int max_val, 
        const int len, int* arr) {      
  int i; 
  for( i = 0; i < len; ++i) {
    arr[i] = rand() % max_val;
  }  
  return;
}
void Array_FillWithDistinctRandomNumbers(const int max_val, 
        const int len, int* arr) {  
  int i; 
  for (i = 0; i < len; ++i) {
    int new_pick;
    do {
      new_pick = rand() % max_val;
    }
    while (Array_IsNumberContained(arr, 0, i - 1, new_pick));
    arr[i] = new_pick;
  }  
  return;
}
bool Array_IsNumberContained(int* arr, int l, int r, int num) {
  while (l <= r) {
    if (arr[l++] == num) {
      return true;
    }
  }
  return false;
}

/**
 * 
 * time-complexity: O(n)
 * 
 * @param compfun_ints
 * @param len
 * @param arr
 * @return 
 */
int Array_FindExtremum(int (*compfun_ints)(int, int), const int len, int* arr) {
  int i = 0;
  int extremum = arr[0];
  int i_extremum = 0;
  for (i = 1; i < len; ++i) {
    int candidate_extremum = arr[i];
    if (compfun_ints(extremum, candidate_extremum) > 0) { // > 0 means, candidate_extremum should come before extremum 
      extremum = candidate_extremum;
      i_extremum = i;
    }
  }  
  //printf("Found extremum at arr[%i] = %i \n", i_extremum, extremum);  
  return i_extremum;  
}


void Array_SwapElements(int* arr,  const int i, const int j) {
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
  return;
}

int Array_ReduceToSum(const int len, int* arr) {
  int i = 0;
  int sum_arr_elements = 0;
  for (i = 0; i < len; ++i) {
    sum_arr_elements += arr[i];
  }
  return sum_arr_elements;
}

//--------------------------------------------------- EXERCISES


/**
 * 
 * Exercise: 
 * 
 * Given an array and a number k, find the kth smallest element.
 * 
 * Idea:
 * 
 * Randomly pick a pivot, partition around the pivot, and depending
 * on which index the pivot is moved to, we can discard a lot of elements:
 * 
 *  if the pivot is such that there are more than k elements still smaller,
 *  we can already discard all largerequal than that pivot
 * 
 *  if the pivot is such that there are m elements smaller with m < k,
 *  we continue to search the k-m-th element on the larger-equal part.
 * 
 *  if the pivot is at index k - 1, we have by chance already found the kth
 *  smallest element.
 *
 * Time Complexity:  O(n) + ~O(n/2) + ~O(n/4) + .. ~ O(n)
 * 
 * 
 * @param arr
 * @param n
 * @param k
 * @return 
 */
int Array_KthSmallest_RandomizedSelection(int* arr, int l, int r, int k) {    
  int idx_pivot, l_orig = l;
  while (1) {    
    idx_pivot = Array_PartitionAroundRandomPivot_InplaceOptimised(arr, l, r);
    if (idx_pivot == l_orig + (k - 1)) {
      break;
    } else if (idx_pivot > l_orig + (k - 1)) {
      r = idx_pivot - 1; // discard pivot and right of it 
    } else { // idx_pivot < l_orig + (k - 1)
      l = idx_pivot + 1; // discard pivot and left of it      
    }
  }  
  return arr[idx_pivot];
}



/**
 * 
 * @param len
 * @param arr
 */
void Array_PartitionEvenOdd(int* const arr, const int n) {    
  int n_left = 0, n_right = 0;  
  while (n_left + n_right < n) {
    bool category1 = (arr[n_left] % 2 == 0 ? true : false);
    if (category1) {
      ++n_left;
    } else { // value_at_i == false
      Array_SwapElements(arr, n - n_right - 1, n_left);
      ++n_right;
    }    
  }  
  return;
}


/**
 * Order all true elements first, then all false.
 * 
 * @param len
 * @param arr
 */
void Array_Partition2ValuedArray(int* arr, const int n) {  
  int n_left = 0, n_right = 0;  
  while (n_left + n_right < n) {
    bool category1 = (arr[n_left] ? true : false);
    if (category1) {
      ++n_left;
    } else { // value_at_i == false
      Array_SwapElements(arr, n - n_right - 1, n_left);
      ++n_right;
    }    
  }  
  return;
}



/**
 * Partition in the following way:
 * 
 * | smaller | pivot | largerequal | 
 * 
 * Idea:
 * 
 *  try-and-error until success: tentatively put pivot to the back and swap
 *  it forward, whenever a new largerequal is found 
 * 
 *  we build up largerequal and smaller parts iteratively:
 *  look at element left of pivot:
 *    if, it is largerequal swap pivot one to the left 
 *      -> largerequals have one more
 *    else swap element with the next element after the smaller part
 *      -> smaller ones have one more
 * 
 *  stop, when n_smaller + 1 + n_larger = n
 * 
 * 
 * @param arr
 * @param n
 */
int Array_PartitionAroundRandomPivot_Inplace(int* const arr, int l, int r) {    
  while (l < r) {    
    bool category1 = (arr[r - 1] <  arr[r] ? true : false);
    if (category1) {      
      Array_SwapElements(arr, r - 1, l);
      ++l;
    } else {
      Array_SwapElements(arr, r - 1, r);      
      --r;
    }
  }  
  return l;  // note: if l==r, l will be returned
}
int Array_PartitionAroundRandomPivot_InplaceOptimised(int* const arr, int l, int r) {  
  if (r == l) { return r;}    
  int sign = 1; // +1, means use r as pivot and l as i_process, -1 vice versa
  while (l < r) {
    if (sign > 0) { // pivot is at r, i_process at l
      while (l < r && arr[l] < arr[r]) ++l;            
    } else {
      while (l < r && arr[r] >= arr[l]) --r;
    }
    if (l == r) {
      break;
    } else {
      Array_SwapElements(arr,l, r);
      sign *= -1;
    }
  }  
  return l;
}

// with extra memory: just to see the simple solution
int Array_PartitionAroundRandomPivot_UsingOofNMemory(int* const arr, int l, int r) {  
  int n = r - l + 1;
  int arr_buffer[n]; // O(n) extra      
  int i;
  for (i = 0; i < n; ++i) {
    if (arr[i] < arr[n - 1]) {
      arr_buffer[l++] = arr[i];
    } else {
      arr_buffer[r--] = arr[i];
    }
  }  
  memcpy(arr, arr_buffer, sizeof(arr_buffer));  
  return l;
}


/**
 * Partition bigger elements than pivot left of pivot
 * equal ones directly to the right
 * and smaller ones right of the equal ones.
 * 
 * @param len
 * @param idx_pivot
 * @param arr
 * @param num_bigger
 * @param num_smaller
 */
int Array_PartioningDutchFlag(int *arr, int l, int r) {
  int piv_val = arr[r];
  int n_less = 0, n_eq = 0, n_gtr = 0;
  while (n_less + n_eq + n_gtr < (r - l)) {
    int curr = arr[l + n_less + n_eq];
    if (curr < piv_val) {
      SwapInts(&arr[l + n_less + n_eq], &arr[l + n_less]);
      ++n_less;
    } else if (curr == piv_val) {
      ++n_eq;
    } else { // curr > piv_val
      SwapInts(&arr[l + n_less + n_eq], &arr[r - 1 - n_gtr]);
      ++n_gtr;
    }
  }  
  SwapInts(&arr[r], &arr[l + n_less + n_eq]);  
  return l + n_less;
}



/**
 * Assume that the least significant bit is at the end.
 * --> 
 * 
 * @param len
 * @param arr
 */
void Array_IncrementArrayRepresentingDecimal(int* arr, const int len) {
#define MAX_VAL_DIGIT 9
  int value_lsb = arr[len-1];
  
  if (value_lsb < MAX_VAL_DIGIT) {
    ++arr[len-1];
    return;
  } else { // value_lsb == MAX_VAL_DIGIT
    int i = 0;
    while (arr[len - 1 - i] == MAX_VAL_DIGIT && i <= len - 1) {
      arr[len - 1 - i] = 0;
      ++i;
    }
    if ( i<= len - 1) {
      ++arr[len - 1 - i];      
    } else {
      printf("Overflow Error \n");
      exit(EXIT_FAILURE);
    }
    
  }
  
  return;
}


/**
 * Expecting input array of integers, which represents the positions
 * of a board game. The value at position i represents the maximum
 * number of moves a player might take from there (though he can take also less).
 * Check if it is possible to reach to the end !
 * @param len
 * @param arr
 */
void Array_CheckAdvanceToEndPossible(int* arr, const int len) {
  
  int moves_made_per_turn[len];
  memset(moves_made_per_turn, 0, sizeof(moves_made_per_turn));
  
  int num_moves_made = 0;
    
  // +1, to store main info at the beginning for quicker lookup
  int matrix_potentialmoves_at_pos[len][MAX_MOVES_PER_TURN + 1];
  memset(matrix_potentialmoves_at_pos, 0, sizeof(matrix_potentialmoves_at_pos));
  int i = 0, j = 0;
  for (i = 0; i < len; ++i) {
    for (j = 0; j <= arr[i]; ++j) {
      matrix_potentialmoves_at_pos[i][j] = 1;
    }
  } 
  
  // strategy: try and error
  int current_position = 0;
  int max_moves_from_here = 0;
  while (current_position < len - 1) {
    printf("Current pos = %i \n", current_position);
    max_moves_from_here = arr[current_position];
    // lookup in data structure, to see if we have any chance from current_pos
    int flag_chance_exists_from_curr_pos = matrix_potentialmoves_at_pos[current_position][0];
    if (max_moves_from_here == 0 || 
           flag_chance_exists_from_curr_pos == 0) {
      printf("All moves failed from pos %i. \n", current_position);
      if (current_position == 0) {
        printf("Not possible to win. Returning \n");
        return;        
      }
      // revert last move and store info that it does not have a chance      
      int num_moves_made_last = moves_made_per_turn[num_moves_made - 1];
      num_moves_made--;
      current_position -= num_moves_made_last;       
      matrix_potentialmoves_at_pos[current_position][num_moves_made_last] = 0;
      if (Array_ReduceToSum(len, matrix_potentialmoves_at_pos[current_position]) == 1) {
        matrix_potentialmoves_at_pos[current_position][0] = 0;
      }      
      printf("Stepped back by %i .\n", num_moves_made_last);
      continue;              
    } else { // there is still a chance from curr_position
      // check what moves can be made and try the maximum one that has a chance
      printf("Checking what moves are still possible from pos = %i.\n", current_position);
      for (i = max_moves_from_here; i > 0; --i) {
        if (matrix_potentialmoves_at_pos[current_position][i] == 1 ) {
          if (current_position + i >= len) {
            printf("Move by %i would be out of board.\n", i);
            matrix_potentialmoves_at_pos[current_position][i] = 0;
            if (Array_ReduceToSum(len, matrix_potentialmoves_at_pos[current_position]) == 1) {
              matrix_potentialmoves_at_pos[current_position][0] = 0;
            }
          } else {            
            printf("Moving forward by %i \n", i);            
            printf("---------------------\n");
            current_position += i;
            moves_made_per_turn[num_moves_made++] = i;
            break;            
          }
        }
      }
    }    
  }
  
  printf("\n :) You have reached the end: WIN \n");
  printf("History of your game: \n");
  for (i = 0; i < num_moves_made; ++i) {
    printf("Moves made in turn %i: %i \n", i, moves_made_per_turn[i]);
  }
  return;
}

int Array_RemoveDuplicatesFromSortedArray(int *arr, int n) {  
  int i, write_i = 0;
  for (i = 0; i < n; ++i) {
    if (i == 0 || arr[i] != arr[i - 1]) {
      
      arr[write_i++] = arr[i];
    }
  }
  return write_i;
}

/**
 *  from codewars
 * 
 * @param n
 * @return 
 */
unsigned long long Array_NextSmallerNumberWithSameDigits(unsigned long long n) {  
  // convert unsigned long long to digit array  
  int n_digits;
  int* digit_arr = UllToDigitArray(n, &n_digits);  
  // inversion point: going from rght to left first digit that is larger than rght neighbor 
  int i = n_digits - 1;
  while (i - 1 >= 0 && digit_arr[i - 1] <= digit_arr[i]) {--i;}
  if (i == -1) return -1;  
  int inversion_i = i - 1;    
  // search subarray rght of inversion_i for next smaller number
  i = n_digits - 1;
  while (i > inversion_i && (digit_arr[i] >= digit_arr[inversion_i] ||
         (digit_arr[i] == 0 && inversion_i == 0))) {
    --i;
  }
  if (i == inversion_i) return -1;
  Array_SwapElements(digit_arr, i, inversion_i);  
  // reverse rght subarray
  ReverseArray(digit_arr, inversion_i + 1, n_digits - 1);
  // convert array of digits to unsigned long long
  ull result = DigitArrToUnsignedLongLong(digit_arr, n_digits);
  free(digit_arr);
  return result;
}

unsigned long long Array_NextLargerNumberWithSameDigits(unsigned long long n) {  
  // convert unsigned long long to digit array  
  int n_digits;
  int* digit_arr = UllToDigitArray(n, &n_digits);  
  // inversion point: going from rght to left first digit that is smaller than rght neighbor 
  int i = n_digits - 1;
  while (i - 1 >= 0 && digit_arr[i - 1] >= digit_arr[i]) {--i;}
  if (i == -1) return -1;  
  int inversion_i = i - 1;    
  // search subarray rght of inversion_i for next larger number
  i = n_digits - 1;
  while (i > inversion_i && (digit_arr[i] <= digit_arr[inversion_i])) {
    --i;
  }
  Array_SwapElements(digit_arr, i, inversion_i);  
  // reverse rght subarray
  ReverseArray(digit_arr, inversion_i + 1, n_digits - 1);
  // convert array of digits to unsigned long long
  ull result = DigitArrToUnsignedLongLong(digit_arr, n_digits);
  free(digit_arr);
  return result;
}
//---------------------- Helper
int* UllToDigitArray(ull num, int* n_digits) {
  *n_digits = (int)log10(num) + 1;
  int* digit_arr = calloc(*n_digits, sizeof(int));
  int i = *n_digits - 1;
  while (num) {
    digit_arr[i--] = num % 10;
    num /= 10;
  }
  return digit_arr;
}
ull DigitArrToUnsignedLongLong(int* arr, int n) {
  int i = 0;
  ull result = 0;  
  while (i < n) {
    result = result * 10 + arr[i];
    ++i;
  }
  return result;
}
void ReverseArray(int* arr, int l, int r) {
  while (l < r) Array_SwapElements(arr, l++, r--);
  return;
}

bool IsSudokuFillingCorrect(unsigned int board[9][9]) {
  int i, j;
  // test rows
  for (i = 0; i < kDim; ++i) {
    if (RowHasDuplicatesOrZeros(board, kDim, i)) {
      return false;
    }
  }  
  // test columns
  for (i = 0; i < kDim; ++i) {
    if (ColHasDuplicates(board, kDim, i)) {
      return false;
    }
  }  
  // test regions  
  for (i = 0; i < (int)sqrt(kDim); ++i) {
    for (j = 0; j < (int)sqrt(kDim); ++j) {
      if (SubregionHasDuplicates(board, kDim, i, j)) {
        return false;
      }
    }
  }  
  return true;
}
//----------------- Helpers
bool RowHasDuplicatesOrZeros(unsigned int (*board)[9], int n, int i) {  
  int j, count[n + 1];
  memset(count, 0, (n + 1) * sizeof(int));
  for (j = 0; j < n; ++j) {
    unsigned int val = board[i][j];
    ++count[val];
    if (count[val] > 1 || val == 0) {return true;}
  }
  return false;
}
bool ColHasDuplicates(unsigned int (*board)[9], int n, int i) {  
  int j, count[n + 1];  
  memset(count, 0, (n + 1) * sizeof(int));
  for (j = 0; j < n; ++j) {
    int val = board[j][i];
    ++count[val];
    if (count[val] > 1) {return true;}
  }
  return false;
}
bool SubregionHasDuplicates(unsigned int (*board)[9], int n, int i, int j) {  
  int k, l, count[n + 1];
  memset(count, 0, (n + 1) * sizeof(int));
  int subdim = (int)sqrt(n);
  for (k = 0; k < subdim; ++k) {
    for (l = 0; l < subdim; ++l) {
      int val = board[i * subdim + k][j * subdim + l];
      ++count[val];
      if (count[val] > 1) {return true;}
    }
  }  
  return false;
}