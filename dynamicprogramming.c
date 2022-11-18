/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


// corresponding h file
#include "dynamicprogramming.h"

// system files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// other c-files' headers and project-wide headers
#include "utils.h"

void MainDynamicProgramming() {      
  
  printf("\n\n----------------------- Main DynamicProgramming \n");
  
  //-----------------------------------------
  // Exercises
  MainDynamicProgramming_ExerciseMaxSumInSubarrays(); 
  
  MainDynamicProgramming_NumberCombinationsOfPlaysForScore(); 
    
  MainDynamicProgramming_MinimumEditsTrafoOfStrings(); 
  
  return;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

      
void MainDynamicProgramming_ExerciseMaxSumInSubarrays(){
  int i = 0;
    
  printf("\n----------------------------------- MainRecursion_ExerciseMaxSumInSubarrays \n");
  
  // create an array of random length and with random vals
  /*
  srand(time(NULL));
  const int max_arr_size = 100;
  const int max_absval_inarr = 100;
  const int arr_size = rand() % max_arr_size;
  int* arr = calloc(arr_size, sizeof(int));
  printf("Created random size and random filled array:\n");
  for (i = 0; i < arr_size; ++i) {
    int arr_val = (-1)*max_absval_inarr + rand() % (2*max_absval_inarr);
    arr[i] = arr_val;
    printf("arr[%i] = %i \n", i, arr_val);
  }
  printf("----------\n");
  */
  
  // create a fixed array for debugging
  const int arr_size = 20;
  int* arr = calloc(arr_size, sizeof(int));
  arr[0] = 87;
  arr[1] = 95;
  arr[2] = -76;
  arr[3] = 46;
  arr[4] = -30;
  arr[5] = 50;
  arr[6] = 55;
  arr[7] = 92;
  arr[8] = 12;
  arr[9] = -2;
  arr[10] = 85;
  arr[11] = 61;
  arr[12] = 70; 
  arr[13] = 83; 
  arr[14] = 0 ;
  arr[15] = -8; 
  arr[16] = 94; 
  arr[17] = 17; 
  arr[18] = -23; 
  arr[19] = -75 ;
  for (i = 0; i < arr_size; ++i) {
    printf("arr[%i] = %i \n", i, arr[i]);
  }
  printf("----------\n");
  
  // Find the maximum of the sums over all possible subarrays 
  // (any continuous block of numbers within the array is a subarray)
  int max_sum_subarrays = FindMaxSumInSubarrays(arr, arr_size);
  
  printf("-> The maximum sum over a subarray yields: %i \n", max_sum_subarrays);
  
  //Free
  free(arr);
  
  return;
}



      
void MainDynamicProgramming_NumberCombinationsOfPlaysForScore() {
  int i = 0;
  
  srand(time(NULL));    
  printf("\n----------------------------------- MainDynamicProgramming_NumberCombinationsOfPlaysForScore \n");
  
  // random number of different types, random scores per type
  /*
  const int max_numbertypes = 4;
  const int n_types = rand() % max_numbertypes + 1;
  int* scorepertype = calloc(n_types, sizeof(int));  
  const int max_scorepertype = 10;
  for (i = 0; i < n_types; ++i) {
    // doing plus 1 in the random number to avoid 0
    // -> a zero score play does not make sense (can occur infinite times in any target)
    scorepertype[i] = rand() % max_scorepertype + 1;
    printf("Score for play %i is: %i \n", i, scorepertype[i]);
  }
  printf("\n");  
  const int max_gamescore = 200;
  const int gamescore = rand() % max_gamescore + 1; 
  */
  
  // for debugging fix types to 3 and 
  const int n_types = 3;
  int* scorepertype = calloc(n_types, sizeof(int)); 
  scorepertype[0] = 2;
  scorepertype[1] = 3;
  scorepertype[2] = 7;
  for (i = 0; i < n_types; ++i) {
    printf("Score for play %i is: %i \n", i, scorepertype[i]);
  }
  printf("\n");
  const int gamescore = 9; 
  
  
  // ENNO SOLUTION
  // find out how many combinations of scores can lead to a given result
/*
  int n_combinations = 0;
  FindNumberCombinationsOfPlaysForScore_EnnoTry(gamescore, scorepertype, n_types, &n_combinations);
  printf("-> number of combinations that can lead to the total score: %i \n", n_combinations);
*/
  
  // TEXTBOOK SOLUTION
  int n_combinations = FindNumberCombinationsOfPlaysForScore_Textbook(gamescore, scorepertype, n_types);
  printf("-> number of combinations that can lead to the total score: %i \n", n_combinations);
    
  // FREE
  free(scorepertype);
  
  return;
}


void MainDynamicProgramming_MinimumEditsTrafoOfStrings(){
  int i = 0;
    
  printf("\n----------------------------------- MainDynamicProgramming_MinimalEditsTrafoOfStrings \n");  
  srand(time(NULL));    
  
  char string1[] = "hoeor";
  char string2[] = "herr";
  
  int strlen1 = strlen(string1);
  int strlen2 = strlen(string2);
  
  int min_edits = FindMinimumEditsTrafoOfStrings_NotDPapproach(string1, string2, strlen1, strlen2);
  
  printf("Found minimum edits for trafo between \n");
  printf("(%s, %s)\n", string1, string2);
  printf("--> %i edits \n", min_edits);
  
  return;  
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


// strategy to find the maximum of the sums over the subarrays
//
// 1. brute force: check the sum over all subarrays and then find the
//                 maximum
//
// 2. dynamic programming algorithm: use what has been computed and memorized before !
//
//   |  
//   |  x        
//   | xx        x            x                    |
//   |xxx xx    xx         x  xx                   |
//   |xxxxxx   xxxx       xxxxxx x                 |
//   --------------------------------------------  |
//   |      xxx    xxxxxxx      x                  | maximum climb of global sum
//   |       xx    xxxx x                          | = maximum of sum over a subarray
//   |       x     xxx                             |
//   |             xxx                             |
//   |              x                              |
//   |
//   0123456789abcdefghijklmnopqrs
//                  |---------| 
//
//   -> in the above example: the maximum sum is found in the subarray that
//      starts at index f and reaches up to index p
//
//   -> the maximum sum over continuous blocks in the array is identified
//      by going from left to right, tracking the global sum
//      over the values in the arr as well as minimum of the global sum FOUND SO
//      FAR and the maximum of the global sum FOUND SO FAR,
//      and then check how large a climb we can get from the current minimum.
//      the largest climb we can make over the whole course indicates where
//      the largest sum over a subarray can be found
//     
//   -> whenever a new minimum of the global sum is found the search
//      for the maximum climb starts all over from there; otherwise, obviously,
//      any climb still has to be seen as starting from the old minimum found some time before 
//      (note that having reached a new global
//      minimum means the latest value was negative so for sure it did not 
//      result in a new maximum of the global sum that we would have to record;
//      note also that in order to find 
//      a new maximum climb we have to climb from this new minimum at least
//      until we are higher than this_minimum + old_maximum_climb
//
//
int FindMaxSumInSubarrays(int* arr, const int arr_size) {
  
  int i = 0;
  
  int glob_sum = 0;
  int min_globsum_sofar = 0;
  int max_climbfromcurrmin = 0;
  int max_climb = 0;
  
  int startindex_subarr_maxclimb = 0;
  
  for (i = 0; i < arr_size; ++i) {
    glob_sum += arr[i];
    if (glob_sum < min_globsum_sofar) {
      min_globsum_sofar = glob_sum;
      printf("New minimum of global sum is at index %i: %i \n", i, glob_sum);
      startindex_subarr_maxclimb = i;
    }
    max_climbfromcurrmin = glob_sum - min_globsum_sofar;    
    if (max_climbfromcurrmin > max_climb) {
      max_climb = max_climbfromcurrmin;
      printf("New largest climb is found from index %i to index %i: %i \n", 
              startindex_subarr_maxclimb, i, max_climbfromcurrmin);
    }
  }  
  
  return max_climb;
}




/**
 * The textbook algorithm makes use of the following idea:
 * 
 * if there exists only one score-type, it is very easy to find the possible
 * number of combinations for a given gamescore: there is either one number
 * of plays that results in the gamescore or the gamescore is unreachable.
 * 
 * if there exist two score-types, one exploits the insight that the gamescore
 * can still be achieved using only the old single score type (so if there
 * existed a number of plays leading to the game score that possibility remains),
 * and in addition it can be reached by having a number of plays with the new score,
 * i.e. either 1, ..., m plays of the new scoretype,
 * where m*new_score_type <= game_score. So one additionally needs to compute 
 * how many combinations are there to reach gamescore-1*new_score, gamescore - 2*new_score, ...
 *  
 * so basically one reduces the problem to smaller and smaller subproblems:
 * find the number of combinations excluding the new score-type and from this
 * knowledge find the number of combinations where the new score-type is present 1, 2, ..., m times.
 * 
 * --> this algorithm leads to the matrix giving the number-of-combinations per
 *     gamescore and available score_types, e.g. for 2,3,7 as score_types
 *            
 * gamescore:   0    1    2     3     4    5    6     7     8    9    10   ...
 * ----------------------------------------------------------------------------
 * 3         |  1    0    0     1     0    0    1     0     0    1     0
 * 3,2       |  1    0    1     1     1    1    2     1     2    2     2
 * 3,2,7     |  1    0    1     1     1    1    2     2     2    3     3
 * 3,2,1     |  1    1    2     3     4    5    7     8    10   12    14
 * 
 *
 * ==> Having computed one line in this matrix
 *     we are able to compute the entries of the next line easily !
 * 
 * For example:
 *  
 * n( 6, <3,2>) = n(6, <3>) + n( 1 play with 2) + n( 2 plays with 2) + n( 3 plays with 2)
 *              = n(6, <3>) + n(6-1*2=4, <3>) + n(6-2*2=2, <3>) + n(6-3*2, <3>)
 *              =     1     +      0          +      0         +      1 
 *              =     2
 *  
 * 
 * NOTE: this algorithm is a (bottom-up) DP algorithm because it memorizes the results and
 *       does not recompute them. Without memorizing
 *       the results in a matrix, one would have to go top-down and on the
 *       way recompute many results over and over again.
 * 
 * @param target_score
 * @param scorepertype
 * @param n_differenttypes
 * @return 
 */
int FindNumberCombinationsOfPlaysForScore_Textbook(const int target_score,
        int* scorepertype, const int n_differenttypes) {
  
  int i, j, k;
  
  // compute the matrix of combinations
  int** n_combinations = calloc(n_differenttypes, sizeof(int));
  for (i = 0; i < n_differenttypes; ++i) {
    n_combinations[i] = calloc(target_score + 1, sizeof(int));
  }
    
  // fill the first row
  int score_1sttype = scorepertype[0];
  for (j = 0; j <= target_score; ++j) {
    if (j % score_1sttype == 0) {
      n_combinations[0][j] = 1;
    } else {
      n_combinations[0][j] = 0;
    }
  }
  n_combinations[0][0] = 1;  // 0 % anything = 0 in C, but we want a 1 there
  
  // fill all other rows: i runs through the growing set of allowed play-types
  for (i = 1; i < n_differenttypes; ++i) {
    int new_allowed_score = scorepertype[i];
    n_combinations[i][0] = 1; // target score of 0 is always 1 combination
    for (j = 1; j <= target_score; ++j) {
      int sum_combinations_old_row = 0;
      // check how many times we can maximally play the new play to get to a gamescore j
      int max_plays_new_score = 0;
      while (max_plays_new_score*new_allowed_score < j) {
        ++max_plays_new_score;
      }
      if (max_plays_new_score*new_allowed_score > j) { // if we went too far, reduce..
        --max_plays_new_score;
      }
      for (k = 0; k <= max_plays_new_score; ++k) {
        sum_combinations_old_row += n_combinations[i - 1][j - k*new_allowed_score];
      }
      n_combinations[i][j] = sum_combinations_old_row;
    }
  }
  int result = n_combinations[n_differenttypes - 1][target_score];
  
  // debug: print the computed matrix
  printf("Found Matrix giving n_combinations (columns=game_scores, rows=allowed playtypes): \n");
  for (j = 0; j <= target_score; ++j) {
    printf("%2i ", j);
  }
  printf("\n-----------------------\n");
  for (i = 0; i < n_differenttypes; ++i) {
    for (j = 0; j <= target_score; ++j) {
      printf("%2i ", n_combinations[i][j]);
    }    
    printf("  | allowed scoretypes ("); 
    for (k = 0; k <= i; ++k) {
      printf("%i ", scorepertype[k]);
    }
    printf(")");    
    printf("\n");
  }
  printf("\n\n");
  
  // FREE
  for (i = 0; i < n_differenttypes; ++i) {
    free(n_combinations[i]);
  }
  free(n_combinations);
  
  return result;
}


void FindNumberCombinationsOfPlaysForScore_EnnoTry(const int target_score,
        int* scorepertype, const int n_differenttypes,
        int* n_combinations) {
  
  int i = 0;
  
  // just for info:  (not needed for algorithm)
  // find out first how many times each of the scorepertype could
  // appear if the score was only achieved by one type of plays
  int* maxplayspertype = calloc(n_differenttypes, sizeof(int));
  for (i = 0; i < n_differenttypes; ++i) {
    int scoreforthistype = scorepertype[i];    
    int maxscoreforthistype = scoreforthistype;
    int maxplays = 0;
    while (maxscoreforthistype <= target_score) {      
      ++maxplays;
      maxscoreforthistype += scoreforthistype;
    }
    maxplayspertype[i] = maxplays;
    // for debug
    printf("The play with %i points can maximally occur %i times in total score of %i \n",
            scoreforthistype, maxplays, target_score);
  }
  
  // now for each type go through until the maximum number of types
  // this play can occur for the score
  int* playspertype = calloc(n_differenttypes, sizeof(int));
  FindNumberCombinationsOfPlaysForScore_Recursion_notDPapproach(target_score,
        scorepertype, 
        n_differenttypes,
        n_combinations,
        playspertype,
        0);  // start with 0 as last raised type and trust the function will not decrease plays of type 0 below 0
    
  // FREE
  free(maxplayspertype);
  free(playspertype);
    
  return;
}

/*
 * The idea of the algorithm is the following:
 * 
 * Start with an array that tracks the number of times a play was made, and 
 * for three a game that has three types of plays, start all zero but the first
 * type,
 * 
 *  [0, 0, 0]
 * 
 * This would mean each of the plays has been played 0 times.
 * 
 * Now let the recursive algorithm check if the target score was reached. If
 * the current number of plays leads to a score less than the target score
 * go through the array, raise a play, and check again if the target is met then.
 * 
 * This will traverse a tree-like structure. E.g. for scorespertype = [2,3,7]
 * and a total score of 6 we would start to raise the the plays of type 1 and 
 * then recursively check the following combinations
 * 
 * 
 *                                                                                     [0,0,0]
 *                                 [1,0,0]                                             [0,1,0]                                  [0,0,1]
 *          [2,0,0]                [1,1,0]           [1,0,1]         [1,1,0]           [0,2,0]       [0,1,1]
 *   [3,0,0][2,1,0][2,0,1]  [2,1,0][1,2,0][1,1,1]             [2,1,0][1,2,0][1,1,1]  [..][..][..]
 *                                                            ACHTUNG: this subtree
 *                                                            has been checked already!
 * 
 * So considering the subtree starting from [1,0,0] e.g.:
 * 
 * [3,0,0] will match and return
 * [2,1,0] will be to big, therefore decrement plays of type 2 to 0 again and return
 * [2,0,1] will be to big, therefore decrement plays of type 3 to 0 again and return
 * 
 * [2,1,0] will be to big, therefore decrement plays of type 1 to 1 again and return
 * [1,2,0] will be to big, therefore decrement plays of type 2 to 1 again and return
 * [1,1,1] will be to big, therefore decrement plays of type 3 to 0 again and return
 * 
 * [1,0,1] will be to big, therefore decrement plays of type 3 to 0 again and return
 * 
 * 
 * 
 *  NOTE: the implemented algorithm is not using "dynamic programming" approach 
 *        because it does not make use of memorizing results of subproblems
 *        and instead always recomputes the solution for each subproblem
 * 
 * 
 */
void FindNumberCombinationsOfPlaysForScore_Recursion_notDPapproach(const int target_score,
        int* scorepertype, 
        const int n_differenttypes,
        int* n_combinations,
        int* playspertype,
        const int last_raised_type) {
  
  int i = 0;
  
  int current_score = 0;  
  for (i = 0; i < n_differenttypes; ++i) {    
    current_score += playspertype[i]*scorepertype[i];    
  }
  // for debug  
  printf("Checking combination: [");
  for (i = 0; i < n_differenttypes; ++i) {    
    printf("%i ", playspertype[i]);
  }
  printf("]\n");
  printf("Current score = %i \n", current_score);
  
  if (current_score == target_score) {
    ++(*n_combinations);
    printf("-> found match ! \n");
  } else if (current_score > target_score) {
    // safety check
    if (last_raised_type < 0) {
      printf("Last raised type is %i even though it should never be negative. Returning.\n",
              last_raised_type);
      return;
    }
  } else { // current_score < target_score 
    
    // try to raise by one the number of plays for each play and check
    // if this leads to a matching score
    //
    //  NOTE: it is the most subtle part of the algorithm to raise
    //        here only the plays of a type larger than or equal to the type
    //        that had just been raised
    //        --> otherwise completely identical subtrees are checked twice
    //            and combinations can be found again that have already been 
    //            found
    //        --> if we only raise the types that had not been raised to the 
    //            maximum we are safe to only check each combination once
    // 
    for (i = last_raised_type; i < n_differenttypes; ++i) {
      ++(playspertype[i]);
      FindNumberCombinationsOfPlaysForScore_Recursion_notDPapproach(target_score,
        scorepertype, 
        n_differenttypes,
        n_combinations,
        playspertype,
        i); 
    }
  }
  
  
  // in any of the three cases we need to decrement the last raise again
  //  1. if we had a match, we need to check if reverting the last raise we
  //     can get the match using a raise of another play
  //  2. if we are too high, we need to revert the last raise for sure
  //  3. if we are too low, we have triggered the next recursion to 
  //     raise one by one all other plays -> we might have found some matches 
  //     in the new recursion tree or not, but now we need to continue to 
  //     check if we can find matches without the last raise of this type
  if (last_raised_type >= 0 && playspertype[last_raised_type] > 0) {
    --(playspertype[last_raised_type]);
  }
  return;
}


/*
 Task: Find minimal number of edits to transform one string to another
 * 
 *    Edit:
 * 
 *      - insertion
 *      - deletion
 *      - update of a character
 * 
 * Examples:
 * 
 *      house, horse          -> 2 edits
 *      house, hours          -> 2 edits
 *      house, hoe            -> 2 edits
 *      house, he             -> 3 edits
 *      housekeeper, her      -> 9 edits
 *      haeraer, hear         -> 3 edits  (remove a, r, e)
 *      harer, hemarr         -> 
 * 
 * 
 *  NOTE: the implemented algorithm is not using "dynamic programming" approach 
 *        because it does not make use of memorizing results of subproblems
 *        and instead always recomputes the solution for each subproblem
 * 
 */
int FindMinimumEditsTrafoOfStrings_NotDPapproach(char* string1,
        char* string2,
        int strlen1,
        int strlen2) {
      
  int minimum_edits = 0;
  
  // if one string has 0 length we need as many inserts as the other is long
  if (strlen1 == 0) {
    return strlen2;  
  }
  if (strlen2 == 0) {
    return strlen1;
  }
  
  // check if the last character is the same  
  char last_str1 = string1[strlen1 - 1];
  char last_str2 = string2[strlen2 - 1];
  if (last_str1 == last_str2) { // yes -> the last character requires no edits 
    int minimum_edits_prefixes = FindMinimumEditsTrafoOfStrings_NotDPapproach(string1,
        string2,
        strlen1 - 1,
        strlen2 - 1);
    minimum_edits = minimum_edits_prefixes;
  } else {
  /* 
   * If last char is not the same, we have three cases that could lead to minimum edits
   * 
   * 1. case:  distance of (string1 minus last char , string2) is the minimum
   * 
   * Example:  acvd, acv --> last chars are different, but no further edits needed since acv==acv
   * 
   * 2. case:  distance of (string1, string2 minus last char)
   * 
   * Example:  acv, acvd --> like above
   * 
   * 3. case:  distance of (string1 minus last char, string 2 minus last char)
   * 
   * Example:  abcd, xycz --> last chars are different, and cannot be used so continue without them
   * 
   */   
    int minimum_edits_reduce_str1 = FindMinimumEditsTrafoOfStrings_NotDPapproach(string1,
        string2,
        strlen1 - 1,
        strlen2);
    int minimum_edits_reduce_str2 = FindMinimumEditsTrafoOfStrings_NotDPapproach(string1,
        string2,
        strlen1,
        strlen2 - 1);
    int minimum_edits_reduce_both = FindMinimumEditsTrafoOfStrings_NotDPapproach(string1,
        string2,
        strlen1 - 1,
        strlen2 - 1);
    
    // get minimum of the three 
    minimum_edits = 1;
    minimum_edits += minimum_edits_reduce_str1 <= minimum_edits_reduce_str2 ? 
      minimum_edits_reduce_str1 <= minimum_edits_reduce_both ? minimum_edits_reduce_str1 : minimum_edits_reduce_both :
        minimum_edits_reduce_str2 <= minimum_edits_reduce_both ? minimum_edits_reduce_str2 : minimum_edits_reduce_both;    
  }
  
  return minimum_edits;  
}
