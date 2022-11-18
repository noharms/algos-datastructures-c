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

#include "sorting.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "arrays.h"
#include "searching.h"
#include "heap_as_nodes.h"
#include "utils.h"
#include "binarysearchtree.h"
#include "hashtable.h"
#include "linkedlist_as_nodes.h"


void MainSorting() {    
  printf("\n\n----------------------- MainSorting \n");
    
  //-----------------------------------------
  // preparations:
  srand(time(NULL));
  
  //-----------------------------------------
  // Exercises
  
  MainSorting_FindIntersectionOfTwoSortedArrays();
  
  MainSorting_MergeTwoSortedArraysIntoOne();
  
  MainSorting_RemoveDuplicatesFromArray();
  
  MainSorting_SmallestSumNotConstructibleFromArray();  
  
  MainSorting_MaxNumberSimultaneousEvents();  
  
  MainSorting_IntegrateIntervalInSortedDisjointIntervals();
  
  MainSorting_DisjointUnionOfIntervals();
  
  MainSorting_CountSortStudentsAge();
  
  MainSorting_TwoTeamPhotoPlacementPossible();
  
  MainSorting_MergeSortLinkedLists();
  
  MainSorting_SalaryCapTargetPayroll();
  
  return;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void MainSorting_FindIntersectionOfTwoSortedArrays() {    
  printf("\n----------------------------------- MainSorting_FindIntersectionOfTwoSortedArrays \n");  
    
  // create two sorted arrays with rand values
  int n = 10, m = 7, max_rand = 20;
  int *arr1 = calloc(n, sizeof(int));
  int *arr2 = calloc(m, sizeof(int));
  Array_FillWithRandomNumbers(max_rand, n, arr1);
  Array_FillWithRandomNumbers(max_rand, m, arr2);
  qsort(arr1, n, sizeof(int), CompFunIntptr_Ascending);
  qsort(arr2, n, sizeof(int), CompFunIntptr_Ascending);
  
  // debug
/*
  int test_arr[] = {0,0,1,1,2,4,9,10,10,19};
  int test_arr2[] = {0,0,0,2,4,9,14};
  memcpy(arr1, test_arr, n * sizeof(int));
  memcpy(arr2, test_arr2, m * sizeof(int));
*/
  
  // print arrays
  printf("Random arr1: \n");
  PrintArray1d(arr1, n);
  printf("\n");
  printf("Random arr2: \n");
  PrintArray1d(arr2, m);
  
  // compute intersection
  int* intersection = NULL;
  int n_intersection = 0;
  Sorting_FindIntersectionOfTwoSortedArrays(arr1, n, arr2, m, &intersection, 
          &n_intersection);
  
  // print result
  printf("Intersection: \n");
  PrintArray1d(intersection, n_intersection);
  
  // free arrays
  free(arr1);
  free(arr2);
  free(intersection);
  return;
}


void MainSorting_MergeTwoSortedArraysIntoOne() {    
  printf("\n----------------------------------- MainSorting_MergeTwoSortedArraysIntoOne \n");  

  // create arrays
#define LEN1 12
#define LEN2 9
  int arr1[LEN1] = { 3, 6, 8 };
  const int arr1_n_used = LEN1 - LEN2;
  int arr2[LEN2] = { 1, 3, 4, 5, 7, 8, 9, 10, 14};
  
  printf("Arr1: \n");  
  PrintArray1d(arr1, LEN1);          
  
  printf("Arr2: \n");  
  PrintArray1d(arr2, LEN2);
  
  // merge 
  Sorting_MergeTwoSortedArraysIntoFirstArray(CompFunInt_Ascending, arr1_n_used, LEN2, 
          arr1, arr2);
  
  // print result
  printf("After merge, array1 reads: \n");
  PrintArray1d(arr1, LEN1);
  
  return;
}

void MainSorting_RemoveDuplicatesFromArray() {
  printf("\n----------------------------------- MainSorting_RemoveDuplicatesFromArray \n");  
  
  // create array
  int n = 10, max_rand = 20;
  int *arr1 = calloc(n, sizeof(int));  
  Array_FillWithRandomNumbers(max_rand, n, arr1);
  
  // print array
  printf("Random arr1: \n");
  PrintArray1d(arr1, n);
  printf("\n");
  
  // remove duplicates
  int n_distinct = Sorting_RemoveDuplicatesFromArray(arr1, n);
    
  // print result
  printf("After removing duplicates: \n");
  PrintArray1d(arr1, n_distinct);
  printf("\n");
  
  // free
  free(arr1);  
  return;
}

void MainSorting_SmallestSumNotConstructibleFromArray() {
  printf("\n----------------------------------- MainSorting_SmallestSumNotConstructibleFromArray \n");  
    
  // create array
  int n = 10, max_rand = 15;
  int *arr1 = calloc(n, sizeof(int));  
  Array_FillWithRandomNumbers(max_rand, n, arr1);
  int i;
  for (i = 0; i < n; ++i) {++(arr1[i]);} // remove 0s
  
  // print array
  printf("Random arr1: \n");
  PrintArray1d(arr1, n);
  printf("\n");
  
  // find smallest sum not constructible
  int min_notconstructible = Sorting_SmallestSumNotConstructibleFromArray(arr1, n);
  
  // print result
  printf("The smallest sum not constructible from the array is: \n");
  printf("%d \n", min_notconstructible);
  
  return;
}

void MainSorting_MaxNumberSimultaneousEvents() {  
  printf("\n----------------------------------- MainSorting_MaxNumberSimultaneousEvents \n");  
    
  // create events
  int n = 10;
  int max_time = 20;
  ClosedIntervalT events[n];
  int i;
  for (i = 0; i < n; ++i) {
    int start_time = rand() % max_time;
    int end_time = start_time + rand() % (max_time - start_time);    
    events[i] = (ClosedIntervalT) {start_time, end_time, end_time - start_time, false};  
  }
  
  // debug case
/*
  events[0] = (IntervalType) {13, 16, false}; 
  events[1] = (IntervalType) {11, 16, false};
  events[2] = (IntervalType) {0, 13, false};
  events[3] = (IntervalType) {17, 19, false};
  events[4] = (IntervalType) {12, 15, false};
  events[5] = (IntervalType) {4, 12, false};
  events[6] = (IntervalType) {0, 7, false};
  events[7] = (IntervalType) {12, 13, false};
  events[8] = (IntervalType) {4, 8, false};
  events[9] = (IntervalType) {0, 7, false};
*/
    
  // print events
  qsort(events, n, sizeof(ClosedIntervalT), CompFunClosedIntervalPtr_Ascending);
  printf("We have the following test set of events \n");
  for (i = 0; i < n; ++i) {
    printf("events[%d] = [%d, %d] \n", i, events[i].left, events[i].rght);
  }
  printf("\n");
  
  // find maximum number of events that occur at the same time
  int max_simultaneous = Sorting_MaxNumberSimultaneousEvents(events, n);
    
  // print result
  printf("The algo found that maximally %d events are active at the same time. \n",
          max_simultaneous);
  return;
}

void MainSorting_IntegrateIntervalInSortedDisjointIntervals() {
  printf("\n----------------------------------- MainSorting_IntegrateIntervalInSortedDisjointIntervals \n");  
  
  // create sorted disjoint intervals
  int n = 10;
  int max_gap = 10;
  int max_intervalsize = 10;
  ClosedIntervalT intervals[n];
  int i;
  int left_0 = (rand() % max_gap);
  int rght_0 = left_0 + rand() % max_intervalsize;
  intervals[0] = (ClosedIntervalT) {left_0, rght_0, rght_0 - left_0, false};  
  for (i = 1; i < n; ++i) {
    int gap_to_next = (rand() % max_gap) + 1;
    int size_next = rand() % max_intervalsize;    
    intervals[i] = (ClosedIntervalT) {intervals[i - 1].rght + gap_to_next, 
            intervals[i - 1].rght + gap_to_next + size_next, 
            size_next, false};  
  }
  
  // debug
  intervals[0] = (ClosedIntervalT) {2, 3, 3-2, false}; 
  intervals[1] = (ClosedIntervalT) {10, 12, 12-10, false};
  intervals[2] = (ClosedIntervalT) {13, 14, 14-13, false};
  intervals[3] = (ClosedIntervalT) {21, 28, 28-21, false};
  intervals[4] = (ClosedIntervalT) {29, 38, 38-29, false};
  intervals[5] = (ClosedIntervalT) {40, 47, 47-40, false};
  intervals[6] = (ClosedIntervalT) {56, 57, 57-56, false};
  intervals[7] = (ClosedIntervalT) {61, 63, 63-61, false};
  intervals[8] = (ClosedIntervalT) {72, 79, 79-72, false};
  intervals[9] = (ClosedIntervalT) {87, 92, 92-87, false};
  
  // print intervals
  qsort(intervals, n, sizeof(ClosedIntervalT), CompFunClosedIntervalPtr_Ascending);
  printf("We have the following disjoint intervals (sorted for debugging) \n");
  for (i = 0; i < n; ++i) {
    printf("intervals[%d] = [%d, %d] \n", i, intervals[i].left, intervals[i].rght);
  }
  printf("\n");
  
  // interval to integrate
  int new_left = 27; //rand() % (n * max_intervalsize);
  int new_rght = 44; //new_left + rand() % 3 * max_intervalsize;
  ClosedIntervalT new_interval = (ClosedIntervalT){new_left, new_rght, new_rght - new_left,
          false};
  printf("We want to integrate the interval \n");
  printf("new_interval = [%d, %d] \n\n", new_interval.left, new_interval.rght);
  
  // find maximum number of events that occur at the same time
  int n_withnew = 0;
  ClosedIntervalT* intervals_withnew = Sorting_IntegrateIntervalInSortedDisjointIntervals(
          intervals, n, new_interval, &n_withnew);
  
  // print result after integrating
  printf("After integration the set of intervals is: \n");
  for (i = 0; i < n_withnew; ++i) {
    printf("intervals[%d] = [%d, %d] \n", i, intervals_withnew[i].left, 
            intervals_withnew[i].rght);
  }
  printf("\n");  
  
  // free
  free(intervals_withnew);
  return;
}

void MainSorting_DisjointUnionOfIntervals() {
  printf("\n----------------------------------- MainSorting_DisjointUnionOfIntervals \n");  
    
  // create some OpenOrClosed Intervals
  int n = 10;
  int max_time = 20;
  OpenOrClosedIntervalT intervals[n];
  int i;
  for (i = 0; i < n; ++i) {
    int start_time = rand() % max_time;
    int end_time = start_time + rand() % (max_time - start_time);
    bool left_closed = rand() % 2;
    bool rght_closed = rand() % 2;
    intervals[i] = (OpenOrClosedIntervalT) {start_time, end_time, 
            end_time - start_time, left_closed, rght_closed};  
  }
  
  // debug case
  intervals[0] = (OpenOrClosedIntervalT) {0, 7, 7-0, true, true};
  intervals[1] = (OpenOrClosedIntervalT) {1,16,16-1, false, true};
  intervals[2] = (OpenOrClosedIntervalT) {3,17,17-3, false, true};
  intervals[3] = (OpenOrClosedIntervalT) {3,11,11-3, false, true};
  intervals[4] = (OpenOrClosedIntervalT) {5, 9, 9-5, true, false};
  intervals[5] = (OpenOrClosedIntervalT) {5,15,15-5, true, false};
  intervals[6] = (OpenOrClosedIntervalT) {6,14,14-6, false, false};
  intervals[7] = (OpenOrClosedIntervalT) {7,13,13-7, false, false};
  intervals[8] = (OpenOrClosedIntervalT) {11,19,19-11, false, false};
  intervals[9] = (OpenOrClosedIntervalT) {12,14,14-12, true, false};
  
  // print intervals  
  qsort(intervals, n, sizeof(OpenOrClosedIntervalT), CompFunOpenClosedIntervalPtr_Ascending);
  printf("We have the following intervals (sorted for debugging) \n");
  for (i = 0; i < n; ++i) {
    printf("intervals[%d] = %c%d, %d%c \n", i, (intervals[i].left_closed ? '[' : '('),
            intervals[i].left, intervals[i].rght, (intervals[i].rght_closed ? ']' : ')'));
  }
  printf("\n");
  
  // build union
  int n_union = 0;
  OpenOrClosedIntervalT* disjoint_union = Sorting_DisjointUnionOfIntervals(
          intervals, n, &n_union);
  
  // print result after integrating
  qsort(intervals, n, sizeof(ClosedIntervalT), CompFunClosedIntervalPtr_Ascending);
  printf("The disjoint union of the intervals reads \n");
  for (i = 0; i < n_union; ++i) {
    printf("intervals[%d] = %c%d, %d%c \n", i, (disjoint_union[i].left_closed ? '[' : '('),
            disjoint_union[i].left, disjoint_union[i].rght, 
            (disjoint_union[i].rght_closed ? ']' : ')'));
  }
  printf("\n");  
  
  // free
  free(disjoint_union);
  return;
}

void MainSorting_CountSortStudentsAge() {
  printf("\n----------------------------------- MainSorting_CountSortStudentsAge \n");  
    
  // create some students
  int n = 12;
  StudentT students[n];
  students[0] = (StudentT) {20, "Enno"};
  students[1] = (StudentT) {23, "Enno"};
  students[2] = (StudentT) {24, "Niclas"};
  students[3] = (StudentT) {31, "Moritz"};
  students[4] = (StudentT) {23, "Marcel"};
  students[5] = (StudentT) {22, "Anka"};
  students[6] = (StudentT) {24, "Christian"};
  students[7] = (StudentT) {18, "David"};
  students[8] = (StudentT) {23, "Steffen"};
  students[9] = (StudentT) {20, "Hans-Georg"};
  students[10] = (StudentT) {20, "Martin"};
  students[11] = (StudentT) {31, "Pipe"};
  
  // print
  int i;
  for (i = 0; i < n; ++i) {
    printf("student[%d].age=%d , name=%s. \n", i, students[i].age, 
            students[i].name);
  }
  printf("\n");
  
  // sort students by age by countsort
  Sorting_CountSortStudents(students, n);
  
  // print result
  printf("After sorting: \n");
  for (i = 0; i < n; ++i) {
    printf("student[%d].age=%d , name=%s. \n", i, students[i].age, 
            students[i].name);
  }
  
  return;
}

void MainSorting_TwoTeamPhotoPlacementPossible() {
  printf("\n----------------------------------- MainSorting_TwoTeamPhotoPlacementPossible \n");  
  
  // create two teams
  int n = 11;
  int heights_team1[n], heights_team2[n];
  int max_above_average = 40;
  Array_FillWithRandomNumbers(max_above_average, n, heights_team1);
  Array_FillWithRandomNumbers(max_above_average, n, heights_team2);
  int i;
  for (i = 0; i < n; ++i) {heights_team1[i] += 160; heights_team2[i] += 160;}
  
  // print teams
  qsort(heights_team1, n, sizeof(int), CompFunIntptr_Ascending);
  qsort(heights_team2, n, sizeof(int), CompFunIntptr_Ascending);
  printf("Team1: (sorted for readability): \n");
  PrintArray1d(heights_team1, n);
  printf("\n");
  printf("Team2: (sorted for readability)\n");
  PrintArray1d(heights_team2, n);
  printf("\n");
  
  // check placements
  bool perfect_placement_possible = Sorting_CheckTwoTeamPhotoPlacementPossible(
          heights_team1, heights_team2, n);
  
  // bool
  printf("Algo found that perfect photo placement is %spossible.\n",
          (perfect_placement_possible ? "" : "not "));
  
  return;
}


void MainSorting_MergeSortLinkedLists() {
  printf("\n----------------------------------- MainSorting_MergeSortLinkedLists \n");  
    
  // create two linked lists
  LinkedlistT l1;  
  LinkedlistT *l1_ptr = &l1;
  LinkedList_Init(l1_ptr);
  LinkedList_PushFront(l1_ptr, &((DataNodeIntKeyIntValT){4, -42}));
  LinkedList_PushFront(l1_ptr, &((DataNodeIntKeyIntValT){9, -42}));
  LinkedList_PushFront(l1_ptr, &((DataNodeIntKeyIntValT){2, -42}));
  LinkedList_PushFront(l1_ptr, &((DataNodeIntKeyIntValT){1, -42}));
  LinkedList_PushFront(l1_ptr, &((DataNodeIntKeyIntValT){5, -42}));  
  LinkedList_PushFront(l1_ptr, &((DataNodeIntKeyIntValT){8, -42}));
  LinkedList_PushFront(l1_ptr, &((DataNodeIntKeyIntValT){9, -42}));
  LinkedList_PushFront(l1_ptr, &((DataNodeIntKeyIntValT){0, -42}));
  LinkedList_PushFront(l1_ptr, &((DataNodeIntKeyIntValT){4, -42}));
  LinkedList_PushFront(l1_ptr, &((DataNodeIntKeyIntValT){3, -42}));
  LinkedList_PrintData(l1_ptr);
  
  // sort the list
  Sorting_MergeSortLinkedList(l1_ptr);
  
  // print result
  printf("After sorting the list reads \n");
  LinkedList_PrintData(l1_ptr);
  
  // free
  LinkedList_Destroy(l1_ptr);
  return;
}

void MainSorting_SalaryCapTargetPayroll() {
  printf("\n----------------------------------- MainSorting_SalaryCapTargetPayroll \n");  
  
  // create salaries
  int n = 6;
  int salaries[n];
  int max_salary = 100;
  Array_FillWithRandomNumbers(max_salary, n, salaries);
  
  // debug
/*
  salaries[0]=69; 
  salaries[1]=41; 
  salaries[2]=25; 
  salaries[3]=6 ;
  salaries[4]=52; 
  salaries[5]=49;
  int target_payroll = 223;  
  salaries[0]=20; 
  salaries[1]=15; 
  salaries[2]=79; 
  salaries[3]=91;
  salaries[4]=72; 
  salaries[5]=25;
  int target_payroll = 96;  
 */
  
  // print salaries
  printf("Salaries: \n");
  PrintArray1d(salaries, n);
  
  // compute cap
  int target_payroll = 50 + rand() % ((n - 1) * max_salary);
  float cap = Sorting_SalaryCapForTargetPayroll(salaries, n, target_payroll);
  
  // print result
  printf("To restrict the payroll to %d, a salary cap is needed at \n", target_payroll);
  printf("%.2f \n", cap); 
  
  return;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


/**
 * Work backwards instead of forwards !
 * 
 * @param compfun_int
 * @param len1
 * @param len2
 * @param arr1
 * @param arr2
 */
void Sorting_MergeTwoSortedArraysIntoFirstArray(int (*compfun_int)(const int, const int), 
        const int len1, const int len2, 
        int* arr1, int* arr2) {  
  int il = len1 - 1, ir = len2 - 1;
  int write_i = len1 + len2 - 1;  
  while (il >= 0 && ir >= 0) {    
    if (compfun_int(arr1[il], arr2[ir]) > 0) {
      arr1[write_i--] = arr1[il--];
    } else {
      arr1[write_i--] = arr2[ir--];
    }
  }    
  while (ir >= 0) {arr1[write_i--] = arr2[ir--];}  
  return;
}

void Sorting_FindIntersectionOfTwoSortedArrays(int* arr1, int n, int *arr2, int m,
        int** intersection, int* n_intersection) {
  int i1 = 0, i2 = 0;
  while (i1 < n && i2 < m) {
    if (arr1[i1] < arr2[i2]) {
      while (arr1[i1] < arr2[i2] && i1 < n) {++i1;}
    } else if (arr2[i2] < arr1[i1]) {
      while (arr2[i2] < arr1[i1] && i2 < n) {++i2;} 
    }   
    while (arr1[i1] == arr2[i2] && i1 < n && i2 < m) {
      if (*n_intersection == 0 || arr1[i1] != (*intersection)[*n_intersection - 1]) {
        ++(*n_intersection);
        *intersection = realloc(*intersection, (*n_intersection) * sizeof(int));
        (*intersection)[*n_intersection - 1] = arr1[i1];
      }
      ++i1;
      ++i2;
    }    
  }
  return;
}

int Sorting_RemoveDuplicatesFromArray(int *arr, int n) {
  qsort(arr, n, sizeof(int), CompFunIntptr_Ascending);
  return Array_RemoveDuplicatesFromSortedArray(arr, n);
}

/**
 * sorting helps to systematically check sums starting at 1.
 * 
 * The logic, which next value helps can be deduced from examples
 * 
 * E.g.:  if arr = {1},  if the next value is larger than 2, it does not help
 *        {1,3, ...}  -> smallest_sum = 1
 *        {1,4, ...}  -> smallest_sum = 1
 *        {1,5, ...}  -> smallest_sum = 1
 * 
 *        if arr = {1, 2},  next values (2, 3, 4) would help, larger not
 *        {1, 2, 5} -> smallest_sum = 3
 *        {1, 2, 6} -> smallest_sum = 3
 *        {1, 2, 7} -> smallest_sum = 3
 * 
 * ==> if a subarray reaches the sum x, then the next value must be <= x + 1,
 *     otherwise the sum x + 1 cannot be build  
 * 
 * @param arr
 * @param n
 * @return 
 */
int Sorting_SmallestSumNotConstructibleFromArray(int *arr, int n) {
  int max_constructible = 0;
  qsort(arr, n, sizeof(int), CompFunIntptr_Ascending);
  if (arr[0] != 1) return max_constructible + 1;
  else max_constructible = 1;
  int i; 
  for (i = 1; i < n; ++i) {
    if (arr[i] > max_constructible + 1) {break;}
    else {
      max_constructible += arr[i];      
    }
  }
  return max_constructible + 1;
}

/**
 * Idea: extract border points, sort, raise active counter if left border
 *       encountered, decrease if right border encountered.
 * 
 * @param events
 * @param n
 * @return 
 */
int Sorting_MaxNumberSimultaneousEvents(ClosedIntervalT* events, int n) {
  // extract border points from events and sort
  BorderPointT borders[2 * n];
  int i;
  for (i = 0; i < n; ++i) {
    borders[2 * i + 0] = (BorderPointT) {events[i].left, true};
    borders[2 * i + 1] = (BorderPointT) {events[i].rght, false};
  }
  qsort(borders, 2 * n, sizeof(BorderPointT), CompFunBorderpointPtr_Ascending);
  // traverse border points and count
  int max_simultaneous = 0;
  int curr_simultaneous = 0; // check how many are active at each border point
  for (i = 0; i < 2 * n; ++i) {
    if (borders[i].left_border) {
      ++curr_simultaneous;
      max_simultaneous = (curr_simultaneous > max_simultaneous ? curr_simultaneous :
        max_simultaneous);
    } else {
      --curr_simultaneous;
    }
  }
  return max_simultaneous;
}

/**
 * Work in three stages: 
 * 
 *  1. intervals before new interval without overlap
 *  2. intervals with overlap with new interval
 *  3. intervals after new interval without overlap
 * 
 * Note: requires intervals to be sorted by left starting point !
 * 
 * @param intervals
 * @param n
 * @param new_interval
 * @param n_result
 * @return 
 */
ClosedIntervalT* Sorting_IntegrateIntervalInSortedDisjointIntervals(ClosedIntervalT*
        intervals, int n, ClosedIntervalT new_interval, int* n_result) {  
  qsort(intervals, n, sizeof(ClosedIntervalT), CompFunClosedIntervalPtr_Ascending); // sort first
  ClosedIntervalT* intervals_withnew = NULL;
  int n_withnew = 0;
  int i = 0;
  while (i < n && intervals[i].rght < new_interval.left) {
    ++n_withnew;
    intervals_withnew = realloc(intervals_withnew, n_withnew * sizeof(ClosedIntervalT));
    intervals_withnew[n_withnew - 1] = intervals[i];
    ++i;
  } // now intervals[i].rght >= new_interval.left
  // modify new_interval to be the union with overlap intervals, if existing
  if (intervals[i].left <= new_interval.rght) { // overlap found !
    new_interval.left = Min(new_interval.left, intervals[i].left);
  }  
  while (i < n && intervals[i].left <= new_interval.rght) {
    new_interval.rght = Max(new_interval.rght, intervals[i++].rght);
  }  
  ++n_withnew;
  intervals_withnew = realloc(intervals_withnew, n_withnew * sizeof(ClosedIntervalT));
  intervals_withnew[n_withnew - 1] = new_interval;
  // add remaining intervals
  while (i < n) {    
    ++n_withnew;
    intervals_withnew = realloc(intervals_withnew, n_withnew * sizeof(ClosedIntervalT));
    intervals_withnew[n_withnew - 1] = intervals[i];
    ++i;
  }
  *n_result = n_withnew;
  return intervals_withnew;
}

/**
 * 
 * sort the intervals, in order to be able to traverse from left to right
 * and detect if rght of curr interval overlaps with left of next interval
 * which means they need to be merged to a signle one.
 *   
 * 
 * @param intervals
 * @param n
 * @param n_result
 * @return 
 */
OpenOrClosedIntervalT* Sorting_DisjointUnionOfIntervals(OpenOrClosedIntervalT*
        intervals, int n, int* n_result) {
  OpenOrClosedIntervalT* disjoint_union = NULL;
  qsort(intervals, n, sizeof(OpenOrClosedIntervalT), CompFunOpenClosedIntervalPtr_Ascending);
  int i = 0;
  OpenOrClosedIntervalT new_interval = intervals[0];
  for (i = 1; i < n; ++i) {
    if (new_interval.rght > intervals[i].left || 
            (new_interval.rght == intervals[i].left && 
              (new_interval.rght_closed || intervals[i].left_closed))) {
      // detected overlap of current interval with candidate new_interval!
      // -> need potential update of rght boundary to build union of the two
      if (intervals[i].rght > new_interval.rght) {
        new_interval.rght = intervals[i].rght;
        new_interval.rght_closed = intervals[i].rght_closed;
      } else if (intervals[i].rght == new_interval.rght && intervals[i].rght_closed) {
        new_interval.rght_closed = true;
      }
    } else { // new_interval.rght < intervals[i].left 
      ++(*n_result);
      disjoint_union = realloc(disjoint_union, (*n_result) * 
              sizeof(OpenOrClosedIntervalT));
      disjoint_union[(*n_result) - 1] = new_interval;
      new_interval = intervals[i];
    }
  }
  // check if latest built new_interval was already added
  if (!disjoint_union || 
          disjoint_union[(*n_result) - 1].rght < new_interval.left ||
          (disjoint_union[(*n_result) - 1].rght == new_interval.left &&
            (!disjoint_union[(*n_result) - 1].rght_closed && !new_interval.left_closed))) {    
    ++(*n_result);
    disjoint_union = realloc(disjoint_union, (*n_result) * 
            sizeof(OpenOrClosedIntervalT));
    disjoint_union[(*n_result) - 1] = new_interval;
  }
  return disjoint_union;
}

/**
 *  1. count different ages and store in BST
 *  2. go through students and swap to correct position
 * 
 * @param students
 * @param n
 */
void Sorting_CountSortStudents(StudentT* students, int n) {    
  BSTType age2count = {0};
  BST_Init(&age2count, CompFunIntptr_Ascending);
  int i;
  for (i = 0; i < n; ++i) {
    BTNodeT* match = BST_FindKey(&age2count, students[i].age);
    if (match) {++match->val;}
    else {BST_InsertKeyVal(&age2count, students[i].age, 1);}
  }
  HashtableT age2offset = {0};
  HashTable_Init(&age2offset, HashFunction_String2Int, 100);
  BTNodeT* iter = BST_FirstNode(age2count.root);
  BTNodeT* last = BST_LastNode(age2count.root);
  int total_offset = 0;
  while (iter) {
    char age_as_str[4];
    sprintf(age_as_str, "%d", iter->key);
    HashTable_Insert(&age2offset, age_as_str, total_offset);
    total_offset += iter->val;
    iter = BST_SuccessorDistinctKeys(&age2count, iter);
  }
  // traverse nodes by age: distribute all students of this age to their
  // correct positions; a node for which the count of students has reached
  // zero means that all students of that age have been distributed 
  while (age2count.n_nodes) {
    // 1. get an arbitray unprocessed student: unprocessed students are at all slots
    // that are pointed to as an offset by the nodes in the map
    // -> pick the first one arbitrarily
    iter = BST_FirstNode(age2count.root);
    char unprocessed_age[4];
    sprintf(unprocessed_age, "%d", iter->key);
    // 2. at the unprocessed slot there sits a student
    // -> this is the student that we will swap to its correct position    
    int i_processnow = HashTable_FindMatch(&age2offset, unprocessed_age)->val;
    StudentT* curr_stud = students + i_processnow;
    int age_processnow = curr_stud->age;
    // 3. find the slot where the student should actually go to
    char age_processnow_asstr[4];
    sprintf(age_processnow_asstr, "%d", age_processnow);
    int i_dst = HashTable_FindMatch(&age2offset, age_processnow_asstr)->val;
    // 4. swap student to destination
    SwapStudents(&students[i_processnow],&students[i_dst]);
    // 5. the count for the age of this student can be decreased
    // -> if all students of that age are done now, the node can be erased,
    //    otherwise just increase the offset so that the next student
    //    of that age will go to the correct slot 
    BTNodeT* node_processedage = BST_FindKey(&age2count, age_processnow);    
    --(node_processedage->val);
    if (node_processedage->val == 0) {
      BST_EraseNode(&age2count, node_processedage);
    } else { // increase offset for this age
      ++HashTable_FindMatch(&age2offset, age_processnow_asstr)->val; 
    }
  }
  // free
  BST_Destroy(&age2count);
  HashTable_Destroy(&age2offset);
  return;
}
void SwapStudents(StudentT* x, StudentT* y) {
  StudentT tmp = *x;
  *x = *y;
  *y = tmp;
  return;
}

bool Sorting_CheckTwoTeamPhotoPlacementPossible(int* heights1, int* heights2, int n) {    
  qsort(heights1, n, sizeof(int), CompFunIntptr_Ascending);
  qsort(heights2, n, sizeof(int), CompFunIntptr_Ascending);
  int* back_row = (heights1[n - 1] > heights2[n - 1] ? heights1 : heights2);
  int* front_row = (heights1[n - 1] > heights2[n - 1] ? heights2 : heights1);
  int i = 0;
  for (i = 0; i < n; ++i) {
    if (front_row[i] >= back_row[i]) {return false;}
  }
  return true;;
}

void Sorting_MergeSortLinkedList(LinkedlistT* l_ptr) {
  l_ptr->head = LinkedList_MergeSort(l_ptr->head);
  return;
}

/**
 * Note: we can find the lower and upper limit for the cap by
 * computing the candidate_payroll at each salary as
 * the sum of the previous salaries plus all following summaries
 * capped at the current salary.
 * 
 * E.g. salaries = {10, 20, 50, 60, 90, 100};
 * candidate_payrolls = {6*10, 10 + 20 + 4*20, 10 + 20 + 50 + 3*50, 
 *                       10+20+50+60+2*60, ...}
 * 
 * --> the target payroll will be between two of the candidate payrolls.
 * 
 * We can find the matching cap by testing all caps between the two, i.e.
 * computing  Sum_0^n_normal salaries[i] + n_capped * cap = payroll_thiscap
 * until payroll_thiscap matches target_payroll have a match
 * --> in fact, this search for the right cap can be done by using binary search
 * 
 * Alternatively: we can solve this equation analyitcally
 * 
 *    cap = (target_payroll - Sum_0^n_normal salaries[i]) / n_capped;
 *            
 * 
 * @param salaries
 * @param n
 * @param target_payroll
 */
float Sorting_SalaryCapForTargetPayroll(int* salaries, int n, int target_payroll) {
  qsort(salaries, n, sizeof(int), CompFunIntptr_Ascending);
  int sum_normal_salaries = 0;
  int i = 0;
  for (i = 0; i < n; ++i) {
    int candidate_cap = salaries[i];
    sum_normal_salaries += salaries[i];
    int n_capped = (n - (i + 1));
    int payroll_thiscap = sum_normal_salaries + n_capped * candidate_cap;
    if (payroll_thiscap >= target_payroll) { // paying this cap is too much !
      // subtract current salary
      sum_normal_salaries -= salaries[i];
      ++n_capped;
      return (target_payroll - sum_normal_salaries) / (1. * n_capped);
    }
  }
  return -1;  // don't need a cap because target_payroll > normal_salaries
}