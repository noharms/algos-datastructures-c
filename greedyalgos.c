/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


// corresponding h file
#include "greedyalgos.h"

// system files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// other c-files' headers and project-wide headers
#include "sorting.h"
#include "utils.h"
#include "binarytree_as_nodes.h"

void MainGreedyAlgorithms() {    
  
  
  printf("\n\n----------------------- Main GreedyAlgorithms \n");
  
  
  //-----------------------------------------
  // Exercises
  MainGreedyAlgorithms_ExerciseOptimumAssignmentOfTasks();
  
  MainGreedyAlgorithms_ExerciseMinimalTotalWaitingTime();
    
  MainGreedyAlgorithms_ExerciseMinimalSetOfNumbersCoveringGivenIntervals();
  
 
  return;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

      
void MainGreedyAlgorithms_ExerciseOptimumAssignmentOfTasks() {
  int i = 0;
    
  printf("\n----------------------------------- MainGreedyAlgorithms_ExerciseOptimumAssignmentOfTasks \n");
  
  srand(time(NULL));
  
  /*  
   * 
   * random setting:   
   
  const int max_workers_allowed = 10; // each worker can take two tasks
  const int n_workers = rand() % max_workers_allowed + 1; // at least one worker
  const int n_tasks = n_workers * 2;
  
  const int max_time_per_task = 10;
  int* time_per_task = calloc(n_tasks, sizeof(int));
  printf("Set of tasks to be distributed: \n");
  for (i = 0; i < n_tasks; ++i) {
    time_per_task[i] = rand() % max_time_per_task;  // note: 0's allowed
    printf("task-id %i: %i hours \n", i, time_per_task[i]);
  }  
  */
  
  // debug: fixed test setting
  const int n_workers = 9;
  const int n_tasks = n_workers * 2;  
  printf("Set of tasks to be distributed: \n");
  int* time_per_task = calloc(n_tasks, sizeof(int));
  time_per_task[0] = 5;
  time_per_task[1] = 4;
  time_per_task[2] = 7;
  time_per_task[3] = 7;
  time_per_task[4] = 2;
  time_per_task[5] = 6;
  time_per_task[6] = 8;
  time_per_task[7] = 4;
  time_per_task[8] = 8;
  time_per_task[9] = 4;
  time_per_task[10] = 7;
  time_per_task[11] = 9;
  time_per_task[12] = 5;
  time_per_task[13] = 3;
  time_per_task[14] = 7;
  time_per_task[15] = 2;
  time_per_task[16] = 1;
  time_per_task[17] = 4;
  for (i = 0; i < n_tasks; ++i) {
    printf("task-id %i: %i hours \n", i, time_per_task[i]);
  }  
  printf("\n");
  
  PairOfTasksType* assignments_per_worker = calloc(n_workers, sizeof(PairOfTasksType));
  
  //----------------------------- ENNO solution
  printf("ENNO SOLUTION: \n");
  FindAssignmentOfTasks_EnnoTry(time_per_task, n_tasks, assignments_per_worker);  
  for (i = 0; i < n_workers; ++i) {
    PairOfTasksType assignment = assignments_per_worker[i];
    int task_id1 = assignment.task1_id;
    int task_id2 = assignment.task2_id;
    int time_task1 = assignment.task1_time;
    int time_task2 = assignment.task2_time;    
    printf("Worker %i works tasks %i (%i hours) and %i (%i hours), totalling %i hours. \n",
            i, task_id1, time_task1, task_id2, time_task2, time_task1 + time_task2);    
  }
  printf("----\n");  
  printf("\n");
  
  //----------------------------- TEXTBOOK solution
  memset(assignments_per_worker, 0, n_workers*sizeof(PairOfTasksType));
  printf("TEXTBOOK SOLUTION:\n");  
  FindOptimumAssignmentOfTasks(time_per_task, n_tasks, assignments_per_worker);    
  for (i = 0; i < n_workers; ++i) {
    PairOfTasksType assignment = assignments_per_worker[i];
    int task_id1 = assignment.task1_id;
    int task_id2 = assignment.task2_id;
    int time_task1 = assignment.task1_time;
    int time_task2 = assignment.task2_time;    
    printf("Worker %i works tasks %i (%i hours) and %i (%i hours), totalling %i hours. \n",
            i, task_id1, time_task1, task_id2, time_task2, time_task1 + time_task2);    
  }
  printf("----\n");  
  printf("\n");
          
  // Free
  free(time_per_task);
  free(assignments_per_worker);
  
  return;
}


      
void MainGreedyAlgorithms_ExerciseMinimalTotalWaitingTime() {
  int i = 0;
    
  printf("\n----------------------------------- MainGreedyAlgorithms_ExerciseMinimalTotalWaitingTime \n");
  
  srand(time(NULL));
  
  // create a random set of tasks and times they would need
/*
  const int max_tasks;
  const int n_tasks = rand() % max_tasks + 1;  
  const int max_time_per_task = 10;
  int* time_per_task = calloc(n_tasks, sizeof(int));
  printf("Set of tasks: \n");
  for (i = 0; i < n_tasks; ++i) {
    time_per_task[i] = rand() % max_time_per_task;  // note: 0's allowed
    printf("task-id %i: %i hours \n", i, time_per_task[i]);
  }
  printf("\n");
*/
  
  
  // debug: fixed test setting  
  const int n_tasks = 4;
  int* time_per_task = calloc(n_tasks, sizeof(int));
  time_per_task[0] = 2;
  time_per_task[1] = 5;
  time_per_task[2] = 1;
  time_per_task[3] = 3;
  for (i = 0; i < n_tasks; ++i) {
    printf("task-id %i: %i hours \n", i, time_per_task[i]);
  }
  printf("\n");
  
  int minimal_total_waiting_time = FindMinimalTotalWaitingTime(time_per_task, n_tasks);
  
  printf("The minimal total waiting time is achieved by ordering tasks in order of ascending time:\n");  
  qsort(time_per_task, n_tasks, sizeof(int), CompFunIntptr_Ascending);
  for (i = 0; i < n_tasks; ++i) {
    printf("%i ", time_per_task[i]);
  }
  printf("--> the minimal total waiting time is: %i \n\n", minimal_total_waiting_time);
  
  return; 
}

      
void MainGreedyAlgorithms_ExerciseMinimalSetOfNumbersCoveringGivenIntervals() {
  int i = 0;
    
  printf("\n----------------------------------- MainGreedyAlgorithms_ExerciseMinimalSetOfNumbersCoveringGivenIntervals \n");
  
  srand(time(NULL));

  // create a random set of intervals  
/*
  const int n_intervals = 5;
  const int max_time = 10;
  IntervalType* intervals = calloc(n_intervals, sizeof(IntervalType));
  for (i = 0; i < n_intervals; ++i) {
    int start = rand() % max_time;
    int stop  = start + rand() % (max_time - start);
    intervals[i].left = start;
    intervals[i].rght = stop;
    intervals[i].len = stop - start;
    intervals[i].covered = false;
    printf("Interval %i = [%i, %i] \n", i, start, stop);    
  }
  printf("\n");   
*/
    
  // Debug: using a fixed set of intervals    
  const int n_intervals = 5;
  ClosedIntervalT* intervals = calloc(n_intervals, sizeof(ClosedIntervalT));
  intervals[0] = (ClosedIntervalT) { 0, 8, 8-0, false };
  intervals[1] = (ClosedIntervalT) { 3, 8, 8-3, false };
  intervals[2] = (ClosedIntervalT) { 4, 9, 9-4, false };
  intervals[3] = (ClosedIntervalT) { 8, 9, 9-8, false };
  intervals[4] = (ClosedIntervalT) { 2, 3, 3-2, false };  

  
  // textbook solution
  printf("TEXTBOOK SOLUTION:\n\n");
  int n_covers = FindMinimalSetNumbersCoveringIntervals(intervals, n_intervals);
  
  // Enno try
  // Note: that the sorting by length is not unique since equal length can appear!   
  printf("ENNO SOLUTION (failing algorithm):\n\n");
  intervals[0] = (ClosedIntervalT) { 0, 8, 8-0, false };
  intervals[1] = (ClosedIntervalT) { 3, 8, 8-3, false };
  intervals[2] = (ClosedIntervalT) { 4, 9, 9-4, false };
  intervals[3] = (ClosedIntervalT) { 8, 9, 9-8, false };
  intervals[4] = (ClosedIntervalT) { 2, 3, 3-2, false };  
  n_covers = FindSmallSetNumbersCoveringIntervals_EnnoTry(intervals, n_intervals);  
  
  printf("ENNO SOLUTION (other sorting leads to working algorithm):\n\n");  
  intervals[0] = (ClosedIntervalT) { 2, 3, 3-2, false };  
  intervals[1] = (ClosedIntervalT) { 0, 8, 8-0, false };
  intervals[2] = (ClosedIntervalT) { 3, 8, 8-3, false };
  intervals[3] = (ClosedIntervalT) { 4, 9, 9-4, false };
  intervals[4] = (ClosedIntervalT) { 8, 9, 9-8, false };
  n_covers = FindSmallSetNumbersCoveringIntervals_EnnoTry(intervals, n_intervals); 
  
  // Free
  free(intervals);
  
  return;  
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------



/**
 * Imagine you are an instructor who assigns a given set of tasks (each having
 * a certain time to complete) to his workers, where each of the workers can do two tasks.
 * 
 * -> find an optimal assignment of tasks in the sense that alls tasks are finished
 *    as soon as possible
 *     
 * @param time_per_task
 * @param n_tasks
 * @param assignments_per_worker
 */
void FindOptimumAssignmentOfTasks(int* time_per_task, 
         const int n_tasks, 
         PairOfTasksType* assignments_per_worker) {
  
  int i = 0, j = 0;
  
  // lets sort the assignments and assign the tasks in pairs (longest_unassigned, shortest_unassigned)
  qsort(time_per_task, n_tasks, sizeof(int), CompFunIntptr_Ascending);
  
  for (i = 0, j = n_tasks - 1; i < j; ++i, --j) {
    assignments_per_worker[i].task1_id = i;
    assignments_per_worker[i].task2_id = j;
    assignments_per_worker[i].task1_time = time_per_task[i];
    assignments_per_worker[i].task2_time = time_per_task[j];
  }
  
  return;
}

/**
 * 
 *   Imagine you are an instructor, who knows the median of all tasks that are gonna
 *   show up this day. Find an algorithm that helps him to assign incoming tasks
 *   for the next day immediately to a worker.
 *   More precisely, given n workers who each can work 2 tasks and a set of 2*n tasks together
 *   with the respective time expenses a task requires, the instructor wants to assign
 *   the new task to the workers such that the tasks will be done in the fastest
 *   possible way. 
 * 
 *   -> the idea is basically, that if a worker does one long task
 *      his second task needs to be a short one
 * 
 *  Note: if the instructor would wait until the end of the day when he has an
 *        overview about all the tasks for tomorrow he could find of course
 *        a much better distribution of the tasks. But in this problem we 
 *        assume that he wants to assign the tasks the moment they come in.
 *  
 */
// this function could be called: FindOptimumAssignmentOfTasksWhenNotKnowingAllTasksOnlyMedian
void FindAssignmentOfTasks_EnnoTry(int* time_per_task, 
         const int n_tasks, 
         PairOfTasksType* assignments_per_worker) {
  int i = 0;
  
  // find median in times (note if even number of times, this function 
  // defines the median such that there is one more element left of the median than right)
  int median_time = FindMedian(time_per_task, n_tasks, CompFunIntptr_Ascending);
  printf("Median value in the set of tasks is: %i \n", median_time);
  
  // now go through the times per task and decide locally whether this is a "large" or a "small" task
  int workers_with_small_task = 0;
  int workers_with_large_task = 0;
  bool equalmedianistreatedaslarger = false; 
  for (i = 0; i < n_tasks; ++i) {
    int time = time_per_task[i];
    
    bool task_larger_than_median = false;    
    if (time > median_time) {      
      task_larger_than_median = 1;
    } else if (time == median_time) {
      // the first task equalling median shall go to the large side:
      // --> so initialize it outside the loop to false and here it will go true for the first occasion
      equalmedianistreatedaslarger = !equalmedianistreatedaslarger; 
    } else {
      //bool task_larger_than_median = false;      
    }

    // distribute the task
    if (task_larger_than_median || (time == median_time && equalmedianistreatedaslarger) ) {      
      assignments_per_worker[workers_with_large_task].task2_id = i;
      assignments_per_worker[workers_with_large_task].task2_time = time;
      ++workers_with_large_task;        
    } else {
      assignments_per_worker[workers_with_small_task].task1_id = i;
      assignments_per_worker[workers_with_small_task].task1_time = time;
      ++workers_with_small_task;
    }    
  }
  
  return;
}

int CompFunIntervalTypePtrFromVoidptrSmallLenFirst(const void* interval1, const void* interval2) {
  return (*((ClosedIntervalT*) interval1)).len - (*((ClosedIntervalT*) interval2)).len;
}


/**
 * Imagine you have a set of tasks and the times it takes to do the tasks.
 * The tasks can only be performed sequentially.
 * 
 * The total waiting time is the time that each task waits before one
 * starts to perform it.
 * 
 * -> Find a order of processing the tasks such that the total waiting time
 *    is minimal
 * 
 * Algorithm: it is very easy! short tasks should go first because the
 *            while the first task is processed all others have to wait !
 * 
 *            one only needs to order the tasks by their time, small ones go first
 * 
 * @param time_per_task
 * @param n_tasks
 * @return 
 */
int FindMinimalTotalWaitingTime(int* time_per_task, const int n_tasks) {
  int i = 0;
  int total_waiting_time = 0;
  
  qsort(time_per_task, n_tasks, sizeof(int), CompFunIntptr_Ascending);
  
  for (i = 0; i < n_tasks; ++i) {
    total_waiting_time += (n_tasks - i - 1) * time_per_task[i];
  }
  
  return total_waiting_time;
}



/**
 * Imagine we have a timeline and time intervals
 * 
 *      |-----------------------------------i----------| 
 *                          |-h--|
 *                          |-g---|
 *                 |--f---|
 *                   |-e---|
 *                       |-d-|
 *          |-c-------|
 *                              |--b-----|
 * |-----a-----|
 * |---------|----------|----------------------------------|------------>
 * 0        x10        20 x     x                x           100
 * 
 * 
 *  => here we need at least 5 numbers to have all the intervals covered
 * 
 *  We want to find the minimal set of numbers that covers
 *  all intervals, or actually we are ok with knowning how many numbers this set contains.
 * 
 * The idea of the textbook algorith is to order the intervals by their right
 * border:  
 *      |-----------------------------------i----------|
 *                              |--b-----|
 *                         |-g---|
 *                         |-h--|
 *                       |-d-|
 *                   |-e---|
 *                 |--f---|
 *          |-c-------|       
 * |-----a-----|
 * |---------|----------|----------------------------------|------------>
 * 0         10        20                                    100
 * 
 * 
 * Algorithm: 
 * 
 *  Go through all intervals and make the right boundary a candidate (in the worst
 *  case, when all intervals are separate, we would cover each interval by choosing
 *  the rght boundary of the interval). Now since the intervals are ordered we
 *  can skip some of the intervals because the previous right boundary covers them
 *  already.
 * 
 *  So, go through the right borders, starting with the first right border, in our
 *  case the one of interval a, check how many of the next intervals can be
 *  covered when this border is chosen, in our case only c, and once the next
 *  interval is not covered by the border, we know that we need another number.
 *  Therefore we now repeat the process, i.e. we choose the next right border
 *  not yet covered, that would be the right border of f, and check how many
 *  of the next intervals would be covered.
 * 
 * @param intervals
 * @param n_intervals
 * @return 
 */
int FindMinimalSetNumbersCoveringIntervals(ClosedIntervalT* intervals, const int n_intervals) {
  
  int i = 0;
  
  qsort(intervals, n_intervals, sizeof(ClosedIntervalT), CompFunIntervalTypePtrFromVoidptrSmallRghtFirst);
    
  // debug  
  printf("After sorting with respect to small rght boundary: \n");
  for (i = 0; i < n_intervals; ++i) {
    printf("Interval %i = [%i, %i] \n", i, intervals[i].left, intervals[i].rght);    
  }
  printf("\n");
  
  int current_rght_boundary = intervals[0].rght;
  int n_numbers_needed = 1;
  printf("We choose number %i for the minimal set that covers the intervals.\n", 
          current_rght_boundary);
  for (i = 1; i < n_intervals; ++i) {
    ClosedIntervalT* interval = intervals + i;
    if (interval->left <= current_rght_boundary) { 
      // no need to check that interval->rght >= current_rght_boundary, because we sorted like that 
      // -> so interval->left <= current_right_boundary <= interval->rght 
      // which means the interval would be covered by current_right_boundary
      interval->covered = true;
    } else {
      // in this case the current boundary can not cover this interval, we need another number
      current_rght_boundary = interval->rght;
      ++n_numbers_needed;
      printf("We choose number %i for the minimal set that covers the intervals.\n", 
          current_rght_boundary);
    }    
  }
    
  printf("\nRESULT: \n");
  printf("We have needed %i numbers to cover the intervals. \n", n_numbers_needed);  
  printf("--------\n");
  printf("\n");
  
  
  return n_numbers_needed;
}


int CompFunIntervalTypePtrFromVoidptrSmallRghtFirst(const void* interval1, const void* interval2) {
  return ((ClosedIntervalT*) interval1)->rght - ((ClosedIntervalT*) interval2)->rght;          
}




/**
 *    ENNO try version
 *    
 *    (is not finding the optimal solution)
 * 
 * The idea of the following algorithm is to find the shortest interval because this puts the hardest
 * restriction on the numbers. We know that we definitely need a number in 
 * there, so we check if we can place it beneficially such that we cover
 * another interval. 
 *  
 * -> For example looking at interval d above, which is the shortest we could choose
 *    the time at the beginning of d, already covering e,f as well, or we
 *    could choose the end of d, already covering g,h. The question how can we
 *    decide which choice would be better ?
 * 
 * PROBLEM: EXPONENTIAL COMPLEXITY
 * 
 *    As we can see, if we take into account b, it would be better
 *    to choose the beginning of d, because this 
 *    allows to cover d, e, f and then h, g, b with one addtional number. On the contrary putting
 *    it to the end of d would cover d, g, h but require an additional number for e, f and one more
 *    for b.
 * 
 *    Then taking into account also c, the choice is again unclear because both,
 *    choosing the beginning and the end of d will result in a set with equally many numbers.
 *    
 * 
 * -> So the answer is: To decide which is best choice for a number
 *    need to know all intervals that exist and play through all possible choices
 *    that are locally equivalent by checking what choices they allow for the
 *    other interval.
 * 
 * ==> this is potentially a very slow algorithm (exponential) because for each
 *     stage of neighboring choices the number of possibilities is multiplied.
 *     Imagine for d we had not too equivalent choices but 1000 and then again around 1000
 *     for each intersected interval like g, h  and e, f..
 * 
 * GREEDY ALGORITHM SOLUTION
 * 
 *   The solution that we want to pursue here is to neglect the global knowledge
 *   and always only look at the local environment. This means we start with the
 *   smallest interval and will put a number to cover it, no matter what:
 *   First, we try to find an intersection with another interval.  If we find one,
 *   we will use the intersection to see if yet another interval can be covered.
 *   And so on, until we have checked all other intervals. If not yet all are
 *   covered we continue with the now smallest_uncovered interval.
 * 
 * 
 * ==> ACHTUNG: this algorithm is O(n*n) and not even guaranteed to find the optimal solution
 *
 * 
 * @param intervals
 * @param n_intervals
 * @return 
 */
int FindSmallSetNumbersCoveringIntervals_EnnoTry(ClosedIntervalT* intervals, const int n_intervals) {
  
  int i, j;
  
  // first order the intervals by length
  qsort(intervals, n_intervals, sizeof(ClosedIntervalT), CompFunIntervalTypePtrFromVoidptrSmallLenFirst);
  
  // debug  
  printf("After sorting with respect to length: \n");
  for (i = 0; i < n_intervals; ++i) {
    printf("Interval %i = [%i, %i], len=%i, covered=%i \n", 
            i, intervals[i].left, intervals[i].rght, intervals[i].len, intervals[i].covered);    
  }
  printf("\n");
  
  // go through the intervals and check the intersection with each other interval
  int n_numbers_needed = 0;
  for (i = 0; i < n_intervals; ++i) {    
    ClosedIntervalT interval = intervals[i];
    int number_to_cover_interval = -1; // --> wlog, assuming intervals start at 0.
    if (interval.covered) {
      continue;
    } else {
      number_to_cover_interval = interval.left;
      // find intersections
      for (j = 0; j < n_intervals; ++j) {
        if (j == i) {
          continue;
        } else {
          ClosedIntervalT cmp_interval = intervals[j];
          if (cmp_interval.covered) {
            continue;
          } else {
            ClosedIntervalT intersection = FindIntersection(interval, cmp_interval);
            if (intersection.len >= 0) { // this means an intersection was found
              intervals[i].covered = true;
              intervals[j].covered = true;
              printf("Found intersection between interval %i=[%i,%i] and interval %i=[%i,%i] \n", 
                      i, interval.left, interval.rght, j, cmp_interval.left, cmp_interval.rght);
              printf("intersection: [%i, %i] \n", intersection.left, intersection.rght);
              interval = intersection;
              number_to_cover_interval = intersection.left;
            }
          }          
        }
      }
      // now we have chekcked all intervals for intersection with interval i
      printf("We choose number %i for the set to cover the intervals.\n",
              number_to_cover_interval);
      ++n_numbers_needed;
    }
  }
  printf("\nRESULT: \n");
  printf("We have needed %i numbers to cover the intervals. \n", n_numbers_needed);  
  printf("--------\n");
  printf("\n");
  
  return n_numbers_needed;
}
