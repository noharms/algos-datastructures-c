/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   recursion.h
 * Author: noh
 *
 * Created on January 13, 2019, 1:08 PM
 */

#ifndef RECURSION_H
#define RECURSION_H

#ifdef __cplusplus
extern "C" {
#endif

  
  void MainRecursion();
  
  void MainRecursion_ExerciseGCD();
  void MainRecursion_ExerciseMxMBoardTrimino();
  void MainRecursion_ExerciseTowersOfHanoiTransfer();
  void MainRecursion_ExerciseNonattackingQueens() ;
  
  int FindGCD_BruteForceRecursion(int num1, int num2, int common_divisor);
  int FindGCD_EuclideRecursion(int num1, int num2);
  
  
  int InitializeMxMBoard(int **board, const int dim);  
  int FillMxMBoardTriminoRecursion(int **board, 
        const int offset_top,
        const int offset_left,
        const int dim, 
        const int corner, 
        int triminoes_placed);
  
  
  
  void PrintTowersOfHanoi(int **towers, const int max_height);
  void TransferNRings_Recursion(int **towers_of_hanoi,         
        const int max_tower_height,
        const int n_transfer,
        const int source_tower,
        const int target_tower);
  
  
  void FillRemainingRows_Recursion(int* columnpos_in_row, 
        const int n, 
        int n_rows_covered,
        int* n_placements_found);
  

#ifdef __cplusplus
}
#endif

#endif /* RECURSION_H */

