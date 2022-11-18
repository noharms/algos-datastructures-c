/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   invariants.h
 * Author: noh
 *
 * Created on March 16, 2019, 11:16 AM
 */

#ifndef INVARIANTS_H
#define INVARIANTS_H

#ifdef __cplusplus
extern "C" {
#endif
  
  
  #include <stdbool.h>

  typedef struct GASUPCITY_TYPE {
    int gasup_litres;
    int distance_to_next;
  } GasupcityType;

  void MainInvariants();

  void MainInvariants_CheckArrayForTwoSumEquallingTargetvalue();
  void MainInvariants_CheckArrayForThreeSumEquallingTargetvalue();
  void MainInvariants_FindAmpleCityInCircleOfCities();
  void MainInvariants_FindMajorityElement();
  void MainInvariants_FindMostTrappedWater();


  bool CheckArrayForTwoSumEquallingTargetvalue(int* arr, const int arr_len, 
      const int target_value);
  bool CheckArrayForThreeSumEquallingTargetvalue(int* arr, const int arr_len, 
      const int target_value);
  
  int FindAmpleCityInCircleOfCities(GasupcityType* circle_of_cities, 
        const int n_cities, const int distance_per_litre);
  
  char FindMajorityElement(char* arr, const int arr_size);
  
  void FindIndicesForBordersTrappingMostWater(int* arr, 
        const int arr_len, int* index_left, int* index_rght);



#ifdef __cplusplus
}
#endif

#endif /* INVARIANTS_H */

