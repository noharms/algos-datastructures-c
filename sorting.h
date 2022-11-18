/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sorting.h
 * Author: noh
 *
 * Created on March 31, 2018, 3:21 PM
 */

#ifndef SORTING_H
#define SORTING_H

#ifdef __cplusplus
extern "C" {
#endif

  #include "standardheaders.h"  
  #include "utils.h"
  #include "linkedlist_as_nodes.h"
  
  void MainSorting();
  
  void MainSorting_FindIntersectionOfTwoSortedArrays();
  void MainSorting_MergeTwoSortedArraysIntoOne();  
  void MainSorting_RemoveDuplicatesFromArray();
  void MainSorting_SmallestSumNotConstructibleFromArray();
  void MainSorting_MaxNumberSimultaneousEvents();
  void MainSorting_IntegrateIntervalInSortedDisjointIntervals();
  void MainSorting_DisjointUnionOfIntervals();
  void MainSorting_CountSortStudentsAge();
  void MainSorting_TwoTeamPhotoPlacementPossible();
  void MainSorting_MergeSortLinkedLists();
  void MainSorting_SalaryCapTargetPayroll();
     
  //------------------------------------------ algos
  
  void Sorting_FindIntersectionOfTwoSortedArrays(int* arr1, int n, int *arr2, int m,
        int** intersection, int* n_intersection);
  
  void Sorting_MergeTwoSortedArraysIntoFirstArray(int (*compfun_int)(const int, const int), 
        const int len1, const int len2, 
        int* arr1, int* arr2);  
  
  int Sorting_RemoveDuplicatesFromArray(int *arr, int n);
  
  int Sorting_SmallestSumNotConstructibleFromArray(int *arr, int n) ;
  
  int Sorting_MaxNumberSimultaneousEvents(ClosedIntervalT* events, int n);
  
  ClosedIntervalT* Sorting_IntegrateIntervalInSortedDisjointIntervals(ClosedIntervalT*
        intervals, int n, ClosedIntervalT new_interval, int* n_result);

  OpenOrClosedIntervalT* Sorting_DisjointUnionOfIntervals(OpenOrClosedIntervalT*
        intervals, int n, int* n_result);
  
  void Sorting_CountSortStudents(StudentT* students, int n);
  void SwapStudents(StudentT* x, StudentT* y);
  
  bool Sorting_CheckTwoTeamPhotoPlacementPossible(int* heights1, int* heights2, int n);
  
  void Sorting_MergeSortLinkedList(LinkedlistT* l_ptr);
  
  float Sorting_SalaryCapForTargetPayroll(int* salaries, int n, int target_payroll);


#ifdef __cplusplus
}
#endif

#endif /* SORTING_H */

