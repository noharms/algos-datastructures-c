/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

// corresponding h file
#include "recursion.h"

// system files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


// other c-files' headers and project-wide headers
#include "utils.h"


#define N_TOWERS 3


void MainRecursion() {    
  
  
  printf("\n\n----------------------- Main Recursion \n");
  
  
  //-----------------------------------------
  // Exercises
  MainRecursion_ExerciseGCD();
  
  MainRecursion_ExerciseMxMBoardTrimino();
  
  MainRecursion_ExerciseTowersOfHanoiTransfer();
  
  MainRecursion_ExerciseNonattackingQueens();
  
  
  
 
  return;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


void MainRecursion_ExerciseGCD(){
  int i = 0;
    
  printf("\n----------------------------------- MainRecursion_ExerciseGCD \n");  
    
  // seed for random numbers
  srand(time(NULL));
  const int max_rand_num = 1000;
  
  int number1 = 1;
  int number2 = 1;
  
  while (isPrime(number1)) {    
    number1 = rand() % max_rand_num;
  }
  while (isPrime(number2)) {
    number2 = rand() % max_rand_num;
  }
  
  // use these options to test special cases
  // number1 = 3;
  // number2 = 0;
  
  // Use Brute force algorithm
  int gcd = FindGCD_BruteForceRecursion(number1, number2, 1);  
  printf("For %i and %i the greatest common divisor is: %i  (Brute force algo)\n",
          number1,
          number2,
          gcd);
  
  // Use Euclid algorithm
  gcd = FindGCD_EuclideRecursion(number1, number2);
  printf("For %i and %i the greatest common divisor is: %i  (euclide algo)\n",
          number1,
          number2,
          gcd);
 
  return;
}

void MainRecursion_ExerciseMxMBoardTrimino() {  
  int i =  0;
  
  printf("\n----------------------------------- MainRecursion_ExerciseGCD \n");  
  
  // let first dim be "row-index and second dim be "column"-index
  const int dim = 8; // needs to be a nth power of 2 (otherwise board cannot be covered)
  if (!IsPowerOf(dim, 2)) {
    printf("The dimension you have set for the Mboard is not a power of 2.\n");
    return;
  }
  if (!IsPowerOf_Recursion(dim, 2)) {
    printf("The dimension you have set for the Mboard is not a power of 2.\n");
    return;
  }
  if (!IsPowerOf_RecursionMult(dim, 2, 2)) {
    printf("The dimension you have set for the Mboard is not a power of 2.\n");
    return;
  }
  int **board;
  board = malloc(dim * sizeof(int*));
  for (i = 0; i < dim; ++i) {
    board[i] = malloc(dim * sizeof(int));
  }
  
  //------------- create a new MxMBoard 
  const int miss_corner = InitializeMxMBoard(board, dim);  
  printf("Initial state of the board\n");
  PrintArray2D(board, dim, dim);
  
  //------------- fill the board
  const int n_triminoes_set = FillMxMBoardTriminoRecursion(board, 0, 0, dim, miss_corner, 0);
  printf("Final state of the board: %i triminoes have been set \n", n_triminoes_set);
  PrintArray2D(board, dim, dim);
  
  FreePointer2D(board, dim);
  return;
}

void MainRecursion_ExerciseTowersOfHanoiTransfer() {
  
  srand(time(NULL));
  int i = 0;
  
  printf("\n----------------------------------- MainRecursion_ExerciseTowerOfHanoiTransfer \n");  
  
  // Let us represent the 3 towers of Hanoi by three arrays
  // of a fixed length (assuming a tower cannot have more rings than that)
  // no ring in a slot of the array is represented by a 0
  // the smallest ring has size 1
  // the next larger ring has size 2, and so forth
  const int max_tower_height = 10;
  int **towers_of_hanoi = calloc(N_TOWERS, sizeof(int*));
  for (i = 0; i < N_TOWERS; ++i) {
    towers_of_hanoi[i] = calloc(max_tower_height, sizeof(int));
  }
  
  // fill wlog some tower
  const int source_tower = rand() % 3;
  const int target_tower = (source_tower + 1) % 3;
  const int n_rings = max_tower_height - 2;
  for (i = 0; i < n_rings; ++i) {
    towers_of_hanoi[source_tower][i] = n_rings - i;
  }
  
  // get a snapshot of the starting position
  PrintTowersOfHanoi(towers_of_hanoi, max_tower_height);
  
  // transfer a certain number of rings from stack source to stack target
  const int max_rand_num = n_rings;  
  const int n_transfer = n_rings - (rand() % max_rand_num);
  TransferNRings_Recursion(towers_of_hanoi, max_tower_height, n_transfer,
          source_tower, target_tower);  
  
  // get a snapshot of the end position
  PrintTowersOfHanoi(towers_of_hanoi, max_tower_height);
    
  // Free  
  for (i = 0; i < N_TOWERS; ++i) {
    free(towers_of_hanoi[i]);
  }
  free(towers_of_hanoi);
  return;
}


void MainRecursion_ExerciseNonattackingQueens() {
  
  int i = 0;
  
  // the brute force method would be to go through all possible
  // placements of n queens on an nxn board, which would be
  //
  //       (n*n) * (n*n-1) * (n*n-2) * ... * (n*n-n) = (n*n)!/(n! (n*n-n)!)
  //
  // possible placements. But since several constellations are equivalent,
  // actually only 
  //
  //        n*n choose n = (n*n)!/(n! (n*n-n)!)
  // 
  // different placements and then check
  // if it is a non-attacking placement
  //
  // a little bit more effective would be a modified brute force method
  // that given the placement of one figure only checks those possibilities
  // for the next figure that are not in the same row, column for
  // non-attacking property over the diagonals
  
  
  printf("\n----------------------------------- MainRecursion_ExerciseNonattackingQueens \n");
  
  const int n = 6;
  int* columnpos_in_row = malloc(n*sizeof(int));
  memset(columnpos_in_row, -1, n*sizeof(int));
  // check initialisation
  for( i = 0; i < n; ++i) {
    printf("columnpos_in_row[%i] = %i \n", i, columnpos_in_row[i]);    
  }
  
  // seed the column for the 0th row
  int* n_placements_found = calloc(1, sizeof(int));
  for( i = 0; i < n; ++i) {
    columnpos_in_row[0] = i;
    FillRemainingRows_Recursion(columnpos_in_row, n, 1, n_placements_found);
  }
  printf("-----\n");
  printf("Found %i placements of n=%i queens on nxn board.\n", *n_placements_found, n);
  
  // FREE
  free(columnpos_in_row);
  free(n_placements_found);
  return;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

int FindGCD_BruteForceRecursion(int num1, int num2, int common_divisor) {
  
  // special cases:
  // we make the convention that 0 is dividable by all numbers
  if (num1 == 0 && num2 != 0) return num2;
  if (num1 != 0 && num2 == 0) return num1;
  if (num1 == 0 && num2 == 0) return 0;
  
  int i = 0;
  int smaller_num = num1 < num2 ? num1 : num2;
  
  int smallest_common_divisor = 1;
  
  // find the smallest_common_divisor of num1 and num2
  for (i = 2; i <= smaller_num ; ++i) {
    if ((num1 % i == 0) && (num2 % i == 0)) {
      smallest_common_divisor = i;
      break;
    }    
  }
  
  // BASE CASE
  // if we reach here and smallest_divisor is still 1 the two numbers do not share
  // any common divisor but 1
  if (smallest_common_divisor == 1) {
    return common_divisor;
  } else { // RECURSION CASE
    int num1_divided = num1 / smallest_common_divisor;
    int num2_divided = num2 / smallest_common_divisor;
    return FindGCD_BruteForceRecursion(num1_divided, num2_divided, common_divisor*smallest_common_divisor);
  }
  
}

// GCD(x, y) = GCD(x, y % x)
//
// Note: 
//         FindGCD_EuclideRecursion(num1, num2 % num1) would lead to 
//         an infinite recursion for num2 == 0
//         --> therefore, FindGCD_EuclideRecursion(num2 % num1, num1)
int FindGCD_EuclideRecursion(int num1, int num2) {
  return num1 == 0 ? num2 : FindGCD_EuclideRecursion(num2 % num1 , num1);
}


// return value is the corner that was set to -1
// 0: top-left
// 1: top-right
// 2: bottom-left
// 3: bottom-right
int InitializeMxMBoard(int **board, const int dim) {  
  int i = 0;
  
  // start with all 0's 
  for (i = 0; i < dim; ++i) {
    memset(board[i], 0, dim * sizeof(int));
  }   
  
  // rip one corner off the board:
  // 0   1
  // 2   3  
  srand(time(NULL));
  const int max_rand_num = 4;  
  const int corner = rand() % max_rand_num;  
  switch(corner) {
    case 0 : 
      board[0][0] = -1;
      break;
    case 1 : 
      board[0][dim-1] = -1; 
      break;
    case 2 : 
      board[dim-1][0] = -1;
      break;
    case 3 : 
      board[dim-1][dim-1] = -1;
      break;
    default:
      printf("Random corner picking in MxMBoard creation did not work \n");
      return -1;
  }
    
  return corner;
}

// corner is 0, 1, 2, 3 depending on which corner is missing/occupied of the board
int FillMxMBoardTriminoRecursion(int **board, 
        const int offset_top,
        const int offset_left,
        const int dim, 
        const int corner, 
        int triminoes_placed) {
  
  const int dim_half = dim/2;
  
  // place a trimino
  // --> depending on the missing corner, we need to find the 4 central fields
  //     1  2  3  4
  //   1 o  o  o  o
  //   2 o  a  b  o
  //   3 o  c  d  o
  //   4 o  o  o  o
  // --> turns out the left corner of the central 4 fields is always at 
  //     (dim/2, dim/2) if starting to count at 1
  // ==> one of the x's 
  const int i_a = dim_half - 1;
  const int j_a = i_a;
  int i, j;
  ++triminoes_placed;
  if (corner != 0) {
    i = offset_top + i_a;
    j = offset_left + j_a;
    board[i][j] = triminoes_placed;
  }    
  if (corner != 1) {
    i = offset_top + i_a;
    j = offset_left + j_a +1;
    board[i][j] = triminoes_placed;
  }
  if (corner != 2) {
    i = offset_top + i_a + 1;
    j = offset_left + j_a;
    board[i][j] = triminoes_placed;
  }
  if (corner != 3) {
    i = offset_top + i_a + 1;
    j = offset_left + j_a + 1;
    board[i][j] = triminoes_placed;
  }
  
  
  // base case
  if (dim_half == 1) {
    return triminoes_placed;
  } else { // recursion case
    // top-left sub-board
    triminoes_placed = FillMxMBoardTriminoRecursion(board, 
            offset_top, offset_left, dim_half, corner == 0 ? 0 : 3, triminoes_placed);
    // top-right sub-board
    triminoes_placed = FillMxMBoardTriminoRecursion(board, 
            offset_top, offset_left + dim_half, dim_half, corner == 1 ? 1 : 2, triminoes_placed);
    // bottom-left sub-board
    triminoes_placed = FillMxMBoardTriminoRecursion(board, 
            offset_top + dim_half, offset_left, dim_half, corner == 2 ? 2 : 1, triminoes_placed);
    // bottom-right sub-board
    triminoes_placed = FillMxMBoardTriminoRecursion(board, 
            offset_top + dim_half, offset_left + dim_half, dim_half, corner == 3 ? 3 : 0, triminoes_placed);
  } 
  
  return triminoes_placed;
}



// idea: print top to bottom, e.g.
//
// ----|----|----|----
//     5
//     4
//     3
//     2
//     1
//
// -> do not print 0s, stop when all towers have a zero
void PrintTowersOfHanoi(int **towers, const int max_height) {
  
  int i, j = 0;
  int digit_sum = 0;
  
  for (j = 0; j < N_TOWERS; ++j) {
    printf("----|");  
  }
  printf("----\n");
  for (i = 0; i < max_height; ++i) {
    digit_sum = 0;
    for (j = 0; j < N_TOWERS; ++j) {
      int ring_size = towers[j][i];
      printf("----");
      if (ring_size == 0) {
        printf(" ");        
      } else {
        printf("%i", ring_size);
      };
      digit_sum += towers[j][i];
    }
    printf("----\n");
    if (!digit_sum) {
      break;
    }
  }  
      
  return;
}


// idea: if you are able to transfer n-1 rings, the algorithm for the nth ring
//       is easy
//
// e.g. let's say from 5 rings
//
// ----|----|----|----
//     5
//     4
//     3
//     2
//     1
//
// you could transfer 4 to stack 2, if you would be able to transfer (4-1)=3 rings
// between the towers:
//
// ----|----|----|----
//     5         3
//     4         2
//               1
// ----|----|----|----
//     5    4    3
//               2
//               1
// Now you would be able to transfer the three rings from stack 3 to stack 2
// because we assumed you are able to transfer 3 rings from one stack to another.
// 
void TransferNRings_Recursion(int **towers_of_hanoi,         
        const int max_tower_height,
        const int n_transfer,
        const int source_tower,
        const int target_tower) {  
  
  // nothing to do
  if (n_transfer == 0) {
    printf("Note: transferring 0 rings means doing nothing. \n");
    return;
  }
  
  // checking the assumptions the algorithm is based on
  if (source_tower >= N_TOWERS) {
    printf("Error: Function tried to transfer from tower %i but only %i exist. \n",
           source_tower, N_TOWERS);
    return;
  }
  if (target_tower >= N_TOWERS) {
    printf("Error: Function tried to transfer to tower %i but only %i exist. \n",
           target_tower, N_TOWERS);
    return;
  }
  
  // check that source tower is not target tower
  if (source_tower == target_tower) {    
    printf("Error: source_tower = target_tower = %i \n",
           target_tower);
    return;
  }
  
  // check that the source tower is the tower with the smallest rings on top ?
  
  // find the first free index on each of three towers
  // -> expect that free slots are represented by a 0-size ring
  int i_target = -1, i_source = -1, i_third = -1;
  const int third_tower = (target_tower + source_tower) > 1 ? 
    ((target_tower + source_tower) == 3 ? 0 : 1) : 2;
  //printf("source=%i target=%i third=%i\n", source_tower, target_tower, third_tower);
  while (towers_of_hanoi[target_tower][++i_target]) {};
  while (towers_of_hanoi[source_tower][++i_source]) {};
  while (towers_of_hanoi[third_tower][++i_third]) {};
  
  // error check: there needs to be at least one ring on the source tower
  if (i_source == 0) {    
    printf("Error: The first free index on the source is at 0, so no ring there.\n");
    return;
  }
  
  // error check: the target should be free at the found index
  if (towers_of_hanoi[target_tower][i_target] != 0) {
    printf("Error: something went wrong. Expecting index %i to be free in target \n",
            i_target);
    return;
  }
  
  // Base cases: n_transfer == 1
  
  if (n_transfer == 1) {
    towers_of_hanoi[target_tower][i_target] = towers_of_hanoi[source_tower][i_source - 1];
    towers_of_hanoi[source_tower][i_source - 1] = 0;    
  } else if (n_transfer == 2) {
    if (i_source < 2) {
      printf("Error: Tried to transfer two rings but source only has %i rings.\n",
              i_source);
      return;      
    }
    // put the first ring from source tower to the "third" tower (not target)  
    towers_of_hanoi[third_tower][i_third++] = towers_of_hanoi[source_tower][i_source - 1];
    towers_of_hanoi[source_tower][--i_source] = 0;
    // put the second ring from source tower to the target
    towers_of_hanoi[target_tower][i_target++] = towers_of_hanoi[source_tower][i_source - 1];
    towers_of_hanoi[source_tower][--i_source] = 0;
    // put the first ring from the "third" tower to the target    
    towers_of_hanoi[target_tower][i_target++] = towers_of_hanoi[third_tower][i_third - 1];
    towers_of_hanoi[third_tower][--i_third] = 0;
  } else {
    // transfer n-1 rings from source to the third tower
    TransferNRings_Recursion(towers_of_hanoi, 
            max_tower_height,
            n_transfer - 1,
            source_tower,
            third_tower
            );
    // transfer the nth ring
    i_source = i_source - (n_transfer -1);
    towers_of_hanoi[target_tower][i_target++] = towers_of_hanoi[source_tower][i_source - 1];
    towers_of_hanoi[source_tower][--i_source] = 0;    
    // transfer n-1 rings back from the third tower to the target
    TransferNRings_Recursion(towers_of_hanoi, 
            max_tower_height,
            n_transfer - 1,
            third_tower,
            target_tower
            );
  }  
  
  return;
}








void FillRemainingRows_Recursion(int* columnpos_in_row, 
        const int n, 
        int n_rows_covered,
        int* n_placements_found) {
  
  int i, j;  
  
  if (n_rows_covered == n) {  // last row has already been filled
    
    printf("Non-attacking placement of n=%i queens on nxn board: \n", n);
    for(i = 0; i < n; ++i) {
      printf("Columnpos_in_row[%i] = %i \n", i, columnpos_in_row[i]);
    }
    ++(*n_placements_found);
    return;
    
  } else {  // fill the next row, i.e. row with index n_rows_covered
    
    // go through all candidate column positions i for the next row
    for (i = 0; i < n; ++i) {
      bool i_covered = false;
      bool i_updiagonal_covered = false;
      bool i_downdiagonal_covered = false;
      
      // check what columns and diagonals previous figures are covering:
      //  1. column is already covered ?
      //  2. rising diagonal  through (n_set, i) covered ?
      //  3. falling diagonal through (n_set, i) covered ?
      for (j = 0; j < n_rows_covered; ++j) {
        const int column_in_row_j = columnpos_in_row[j];
        // 1. 
        if (i == column_in_row_j) {          
          i_covered = true;
          break;
        }
        // 2. calculate:  column - row
        const int updiagonal_if_i_in_nextrow = i - n_rows_covered;
        const int updiagonal_in_row_j = columnpos_in_row[j] - j;        
        if (updiagonal_if_i_in_nextrow == updiagonal_in_row_j)  {
          i_updiagonal_covered = true;
          break;
        }
        // 3. calculate:  column + row
        const int downdiagonal_if_i_in_nextrow = i + n_rows_covered;
        const int downdiagonal_in_row_j = columnpos_in_row[j] + j;              
        if (downdiagonal_if_i_in_nextrow == downdiagonal_in_row_j)  {
          i_downdiagonal_covered = true;
          break;
        }
      }
      
      // check if diagonal through i is already covered
      
      if (i_covered || i_updiagonal_covered || i_downdiagonal_covered) {
        continue;
      } else {
        columnpos_in_row[n_rows_covered] = i;
        FillRemainingRows_Recursion(columnpos_in_row, n, n_rows_covered + 1, n_placements_found);
      }      
    }
  }  
  
  return;
}