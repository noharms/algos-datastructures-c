/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   greedyalgos.h
 * Author: noh
 *
 * Created on March 3, 2019, 3:07 PM
 */

#ifndef GREEDYALGOS_H
#define GREEDYALGOS_H

#ifdef __cplusplus
extern "C" {
#endif
  
    #include "utils.h"
  
    typedef struct PAIR_OF_TASKS_TYPE {
      
      int task1_id;
      int task2_id;
      
      int task1_time;
      int task2_time;      
      
    } PairOfTasksType;
  
    void MainGreedyAlgorithms();

    void MainGreedyAlgorithms_ExerciseOptimumAssignmentOfTasks();
    void MainGreedyAlgorithms_ExerciseMinimalTotalWaitingTime();
    void MainGreedyAlgorithms_ExerciseMinimalSetOfNumbersCoveringGivenIntervals();
    
    void FindOptimumAssignmentOfTasks(int* time_per_task, 
         const int n_tasks, 
         PairOfTasksType* assignments_per_worker);
    void FindAssignmentOfTasks_EnnoTry(int* time_per_task, 
         const int n_tasks, 
         PairOfTasksType* assignments_per_worker);
    
    int FindMinimalTotalWaitingTime(int* time_per_task, const int n_tasks);
    
    int FindSmallSetNumbersCoveringIntervals_EnnoTry(ClosedIntervalT* intervals, const int n_intervals);
    int CompFunIntervalTypePtrFromVoidptrSmallLenFirst(const void* interval1, const void* interval2);
    
    int FindMinimalSetNumbersCoveringIntervals(ClosedIntervalT* intervals, const int n_intervals);
    int CompFunIntervalTypePtrFromVoidptrSmallRghtFirst(const void* interval1, const void* interval2);

#ifdef __cplusplus
}
#endif

#endif /* GREEDYALGOS_H */

