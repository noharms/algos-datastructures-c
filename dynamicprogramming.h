/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dynamicprogramming.h
 * Author: noh
 *
 * Created on February 23, 2019, 9:55 AM
 */

#ifndef DYNAMICPROGRAMMING_H
#define DYNAMICPROGRAMMING_H

#ifdef __cplusplus
extern "C" {
#endif


    void MainDynamicProgramming();
    
    void MainDynamicProgramming_ExerciseMaxSumInSubarrays();
    void MainDynamicProgramming_NumberCombinationsOfPlaysForScore();
    void MainDynamicProgramming_MinimumEditsTrafoOfStrings();
    
    
    int FindMaxSumInSubarrays(int* arr, const int arr_size);
    
    int FindNumberCombinationsOfPlaysForScore_Textbook(const int target_score,
        int* scorepertype, const int n_differenttypes);
    void FindNumberCombinationsOfPlaysForScore_EnnoTry(const int target_score,
        int* scoresperplay, const int n_differenttypes,
        int* n_combinations);
    void FindNumberCombinationsOfPlaysForScore_Recursion_notDPapproach(const int target_score,
        int* scoresperplay, 
        const int n_differenttypes,
        int* n_combinations,
        int* playspertype,
        const int last_raised_type);

    int FindMinimumEditsTrafoOfStrings_NotDPapproach(char* string1,
        char* string2,
        int strlen1,
        int strlen2);
    
    

#ifdef __cplusplus
}
#endif

#endif /* DYNAMICPROGRAMMING_H */

