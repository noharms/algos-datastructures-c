/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

// corresponding h-file
#include "invariants.h"

// standard libraries
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// project wide h-files
#include "utils.h"


void MainInvariants() {  
  
  printf("\n\n----------------------- Main Invariants \n");  
  
  //-----------------------------------------
  // Exercises
  
  MainInvariants_CheckArrayForTwoSumEquallingTargetvalue();
  
  MainInvariants_CheckArrayForThreeSumEquallingTargetvalue();
  
  MainInvariants_FindAmpleCityInCircleOfCities();
    
  MainInvariants_FindMajorityElement();
  
  MainInvariants_FindMostTrappedWater();
  
  return;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


void MainInvariants_CheckArrayForTwoSumEquallingTargetvalue() {
  int i = 0;
    
  printf("\n----------------------------------- MainInvariants_CheckArrayForTwoSumEquallingTargetvalue \n");  
  srand(time(NULL));
  
  // create a random array
  const int arr_size = 20;
  const int max_val = 30;
  const int target_val = rand() % (max_val*2);
  int* arr = calloc(arr_size, sizeof(int));
  printf("Created random array: \n");
  for (i = 0; i < arr_size; ++i) {
    arr[i] = rand() % max_val;
    printf("arr[%i] = %i\n", i, arr[i]);
  }  
  printf("\n\n");
  
  bool twosum_fortarget_exists = CheckArrayForTwoSumEquallingTargetvalue(
          arr, arr_size, target_val);
  
  if (twosum_fortarget_exists) {
    printf("-> RESULT: two elements adding up to the target value %i exist in array.\n", 
            target_val);
  } else {
    printf("-> RESULT: NO two elements adding up to the target value %i exist in array.\n", 
            target_val);
  }
  
  // FREE
  free(arr);
  
  return;
}



void MainInvariants_CheckArrayForThreeSumEquallingTargetvalue() {
  int i = 0;
    
  printf("\n----------------------------------- MainInvariants_CheckArrayForThreeSumEquallingTargetvalue \n");  
  srand(time(NULL));
  
  // create a random array
  const int arr_size = 20;
  const int max_val = 30;
  const int target_val = rand() % (max_val*2);
  int* arr = calloc(arr_size, sizeof(int));
  printf("Created random array: \n");
  for (i = 0; i < arr_size; ++i) {
    arr[i] = rand() % max_val;
    printf("arr[%i] = %i\n", i, arr[i]);
  }  
  printf("\n\n");
  
  bool threesum_fortarget_exists = CheckArrayForThreeSumEquallingTargetvalue(
          arr, arr_size, target_val);
  
  if (threesum_fortarget_exists) {
    printf("-> RESULT: three elements adding up to the target value %i exist in array.\n", 
            target_val);
  } else {
    printf("-> RESULT: NO three elements adding up to the target value %i exist in array.\n", 
            target_val);
  }
  
  // FREE
  free(arr);
  
  return;
}



void MainInvariants_FindAmpleCityInCircleOfCities() {
  int i = 0;
    
  printf("\n----------------------------------- MainInvariants_FindAmpleCityInCircleOfCities \n");  
  srand(time(NULL));
  
  // create a circle of cities: a city has two properties that are of interest
  // to us, i.e. 1. how much can be gased up 2. how far is the next city in the circle
  // -> since it is not trivial to find a good example, use the one from the textbook
  const int n_cities = 7;  
  GasupcityType* circle_of_cities = calloc(n_cities, sizeof(GasupcityType));
  circle_of_cities[0].distance_to_next = 900;
  circle_of_cities[0].gasup_litres = 50;
  circle_of_cities[1].distance_to_next = 20;
  circle_of_cities[1].gasup_litres = 600;
  circle_of_cities[2].distance_to_next = 200;
  circle_of_cities[2].gasup_litres = 5;
  circle_of_cities[3].distance_to_next = 400;
  circle_of_cities[3].gasup_litres = 30;
  circle_of_cities[4].distance_to_next = 600;
  circle_of_cities[4].gasup_litres = 25;
  circle_of_cities[5].distance_to_next = 200;
  circle_of_cities[5].gasup_litres = 10;
  circle_of_cities[6].distance_to_next = 100;
  circle_of_cities[6].gasup_litres = 10;
  
  const int distance_per_litre = 20;
  
  int pos_amplecity = FindAmpleCityInCircleOfCities(circle_of_cities, n_cities, 
          distance_per_litre);
  
  // result
  printf("-> found ample city at position: %i \n\n", pos_amplecity);
    
  // FREE
  free(circle_of_cities);
  
  return;
}


void MainInvariants_FindMajorityElement() {
  int i = 0;
    
  printf("\n----------------------------------- MainInvariants_FindMajorityElement \n");  
  srand(time(NULL));
 
  // randomized array of chars, with one char appearing more than half the the times
  const int arr_size = 20;
  const int n_letters_alphabet = 26;
  const char majority_element = 'a' + rand() % n_letters_alphabet;
  const int wanted_appearances_majority_element = (arr_size/2 + 1);
  char* arr = calloc(arr_size, sizeof(char));  
  int count_majority_element = 0;
  for (i = 0; i < arr_size; ++i) {
    char letter = 'a' + rand() % n_letters_alphabet;
    arr[i] = letter;
    if (letter == majority_element) {
      ++count_majority_element;
    }
  }
  i = 0;
  while (count_majority_element < wanted_appearances_majority_element) {
    i %= arr_size;
    if (arr[i] != majority_element) {
      bool coin = rand() % 2;
      if (coin) {
        arr[i] = majority_element;
        ++count_majority_element;
      }
    } else {
      // leave the letter and continue to the next
    }
    ++i;
  }
  
  // fixed debug case
/*
  const int arr_size = 10;
  const char majority_element = 'x';
  char* arr = calloc(arr_size, sizeof(char));
  arr[0] = 't';
  arr[1] = 'x';
  arr[2] = 'x';
  arr[3] = 'x';
  arr[4] = 'd';
  arr[5] = 'x';
  arr[6] = 'x';
  arr[7] = 'x';
  arr[8] = 't';
  arr[9] = 'y';
*/
  
  // print the resulting array of chars
  printf("Created the following array of chars for the exercise: \n");
  for (i = 0; i < arr_size; ++i) {
    printf("Pos %i: %c \n", i, arr[i]);
  }
  printf("\n\n");
  
  char found_majority_element = FindMajorityElement(arr, arr_size);
  
  printf("--> Result: we found that %c is the majority element of the array.\n", 
          found_majority_element);
  
  // FREE
  free(arr);
  
  return;
}


void MainInvariants_FindMostTrappedWater() {
  int i = 0;
    
  printf("\n----------------------------------- MainInvariants_FindMostTrappedWater \n");  
  srand(time(NULL));
  
  // create a randomly filled array
  const int arr_len = 8;
  const int max_val = 20;
  int* arr = calloc(arr_len, sizeof(int));
  printf("Array of length %i filled with random numbers: \n", arr_len);
  for (i = 0; i < arr_len; ++i) {
    int val = rand() % max_val; 
    arr[i] = val;
    printf("%02i:", i);
    int j = 0;
    while(j < val) {
      printf("-");
      ++j;
    }
    printf("\n");
  }
  
  int l_i = 0;
  int r_i = arr_len - 1;  
  FindIndicesForBordersTrappingMostWater(arr, arr_len, &l_i, &r_i);
  
  printf("-> Found that the most water is trapped between indices %i and %i \n",
          l_i, r_i);
  
  // FREE
  free(arr);
  
  return;
  
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


/**
 * Idea of the algorithm is the following:
 * 
 * Sort the array first -> takes O(n log n)
 * 
 * then start with two indices at the leftmost and rightmost index, and check
 * if the two hit the target value:
 *  if yes, we are done
 *  if no because the sum of the two is too large: reduce rightmost index
 *  if no because the sum of the two is too small: increase leftmost index
 *
 * -> this can be repeated n-times until the two indices meet and we either
 *    find two suitable elements on the way or not
 *    
 * -> after sorting, we only need O(n) operations
 * 
 * => the overall complexity is O(n log n)
 * 
 * 
 * Note: with additional space complexity allowed, we could create ourselves 
 *       a hash table of O(n) filled with the values "target-arr[j]"
 * 
 *       -> afterwards traverse the array and always check if arr[i] exists
 *          in the hash table; since lookup is O(1), this algorithm would be
 *          only O(n)
 * 
 * 
 * @param arr
 * @param arr_len
 * @param target_value
 * @return 
 */
bool CheckArrayForTwoSumEquallingTargetvalue(int* arr, const int arr_len, 
        const int target_value) {
  
  int i, j;
  bool suitable_elements_exist = false;
  
  qsort(arr, arr_len, sizeof(int), CompFunIntptr_Ascending);
  
  // for debug
  printf("Array after sorting: \n");
  for (i = 0; i < arr_len; ++i) {    
    printf("arr[%i] = %i\n", i, arr[i]);
  }  
  printf("\n\n");
  
  // algorithm
  i = 0;
  j = arr_len - 1;
  while (i < j) {
    int two_sum = arr[i] + arr[j];
    if (two_sum == target_value) {
      suitable_elements_exist = true;
      break;
    } else if (two_sum > target_value) {
      --j;
    } else if (two_sum < target_value) {
      ++i;
    } else {
      // should not reach here unless something is overlooked
    }
  }
  
  // print result
  if (suitable_elements_exist) {
    printf("Elements arr[%i]=%i and arr[%i]=%i add up to target=%i .\n\n", 
          i, arr[i], j, arr[j], target_value);
  }
  
  return suitable_elements_exist;
}


/**
 * 
 * Idea of the algorithm:
 * 
 *  go through the array once and check for each element i if there exist any
 *  two other elements in the array whose two_sum would yield target-arr[i]
 *  
 *  -> the traversal is O(n) and the check for the two_sum is O(n) if 
 *     the array is already sorted
 *  -> this makes O(n*n)
 * 
 * @param arr
 * @param arr_len
 * @param target_value
 * @return 
 */
bool CheckArrayForThreeSumEquallingTargetvalue(int* arr, const int arr_len, 
        const int target_value) {
  
  int i, j, k;
  bool suitable_elements_exist = false;
  
  qsort(arr, arr_len, sizeof(int), CompFunIntptr_Ascending);
  
  // for debug
  printf("Array after sorting: \n");
  for (i = 0; i < arr_len; ++i) {    
    printf("arr[%i] = %i\n", i, arr[i]);
  }  
  printf("\n\n");
  
  // algorithm
  for (i = 0; i < arr_len; ++i) {
    int target_minus_element = target_value - arr[i];
    // now we need to check whether there exists a two sum in the array
    // that yields target_minus_element
    j = 0;
    k = arr_len - 1;
    while (j <= k) {  // the same array element may be taken thrice in the three sum
      int two_sum = arr[j] + arr[k];
      if (two_sum == target_minus_element) {
        suitable_elements_exist = true;
        break;
      } else if (two_sum > target_minus_element) {
        --k;
      } else if (two_sum < target_minus_element) {
        ++j;
      } else {
        // should not reach here unless something is overlooked
      }
    }
    // stop traversing the array because values were already found
    if (suitable_elements_exist) {
      break;
    }
  }
    
  // print result
  if (suitable_elements_exist) {
    printf("Elements arr[%i]=%i, arr[%i]=%i and arr[%i]=%i add up to target=%i .\n\n", 
          i, arr[i], j, arr[j], k, arr[k], target_value);
  }
  
  return suitable_elements_exist;
}

/**
 * Problem: given a circle of cities with gas-stations that each provide only
 *          a limited amount of gas, the distances between the neighboring cities,
 *          and the gas-consumption rate, find an ample city in the circle, 
 *          i.e. a city that you can start at and get around the circle once !
 * 
 * Example: 
 * 
 * A(50, 900)
 * B(20, 600)
 * C(5, 200)
 * D(30, 400)
 * E(25, 600)
 * F(10, 200)
 * G(10, 100)
 * 
 * The idea of the algorithm is the following:
 * 
 * If we start at city A and fail to reach the next city at some point, say
 * at city X, then none of the cities between A and X can possibly be an
 * ample city.
 * 
 * -> the reason is that starting at any city between A and X could only make
 *    it worse but never better ! the more trips you had before a city, the better !
 * -> in other words: 
 *    the hardest way to get from city X to X+1 is to start from
 *    city X because you do not have any spare gas, only the gas available in
 *    city X. Instead if you start at X-1 or earlier, you could have spare gas from
 *    the trips before. 
 * 
 * The only way things can get better is to start earlier. So we start one city
 * earlier and see if this gives us enough spare gas to get further than where
 * we got now. Basically we have to indices: one for the current ample candidate and
 * one for the farthest city we can reach from the current candidate. if we cannot 
 * reach the next city, we go back to the earlier ample candidate until the ample
 * candidate is also the farthest city we can reach.
 *  
 * => this algorithm would be O(n) 
 *
 * 
 * Note: a brute force way would be to try each city and check if you get around.
 *       this would be O(n*n)
 *
 * Note: if additionally one assumes that the fuel distributed over all cities is just enough
 *       to finish the circle, i.e. at the end the tank is empty, one can use
 *       another algorithm of O(n) to find an ample city. since the tank can never go below
 *       0 on a ride that closes the circle and, on the other hand,
 *       since the tank has to reach 0 at the ample city, we know that the minimum
 *       of the tank-curve is positioned at the ample city
 *       -> we can start at a random city and track the tank-curve (negatives allowed now)
 *          to find the minimum of the tank-curve and then we know that there
 *          is the ample city
 * 
 * @param circle_of_cities
 * @param n_cities
 * @param distance_per_litre
 * @return 
 */
int FindAmpleCityInCircleOfCities(GasupcityType* circle_of_cities, 
        const int n_cities, const int distance_per_litre) {
    
  // start a tour
  int i = n_cities - 1; // index for the ample candidate
  int j = n_cities - 1; // index for the farthres reachable city so far
  int spare_gas = circle_of_cities[i].gasup_litres;
  do {
    j %= n_cities;    
    int distance_next_city = circle_of_cities[j].distance_to_next;
    int achievable_distance = spare_gas * distance_per_litre;
    if (distance_next_city > achievable_distance) {
      // we have to go back and gas up
      --i;
      spare_gas += circle_of_cities[i].gasup_litres;
      if (i == -1) {
        printf("We cannot go back further to gather extra fuel.. Circel cannot be traversed.\n");
        break;
      }
    } else {
      ++j;
      // check how much of the spare gas we have actually needed to get to the next city
      int consumed_gas = distance_next_city / distance_per_litre;
      if (distance_next_city % distance_per_litre) {
        printf("Should not happen. The example should be doable with integers. \n");
      }
      spare_gas -= consumed_gas;
    }
  } while (i != j);
  
  // if we are not sure that an ample city exists at all we would need one
  // round after i and j collide to see if the last reduction of i that 
  // led to the collision with j has given us enough gas for the last step
  // --> we do not check here because we assume there is an ample city for sure
    
  printf("Ample city at: %i \n", i);
  
  return i;
}


/**
 * 
 * Exercise: given a sequence of chars and the info that a given char appears
 *           at more than half of the slots of the sequence (this is called
 *           the majority element of the sequence).
 *           -> find the majority element
 * 
 * The idea of the algorithm is as follows:
 * 
 *    We can see the sequence as being separated into two groups of chars:
 *      1. the group made up by the majority element
 *      2. the remaining chars not being the majority element
 * 
 *    We know that the first group contains more members than the second group.
 *    Thus the idea is to go through the array, start with the first element
 *    as the candidate for the majority element and compare with the next element.
 *   
 *      If they are the same we increase the surplus of the candidate by one.
 *        
 *      If the candidate and the next char are different from each other we do
 *      not have an decrease of the surplus.
 *      If the surplus is 0 after comparison with the next element,
 *      we can ignore everything that happened so far and set the element after
 *      to the new candidate.
 *      In the worst case one of the compared chars was the majority element but since
 *      we also throw away one char from the other group, we can still find the surplus
 *      in the remaining chars, so we can ignore the past.
 * 
 * --> this algorithm only passes the array once, so O(n)
 * 
 * Note: brute force would be to go through the array for each element and
 *       count the appearances, tracking the element with maximum appearances
 *       -> would be O(n*n)
 * 
 * Note: with additional storage of O(n) one could use a hash table to store
 *       for each different element the number of appearances and then find the
 *       maximum in the hashtable, this would be time complexity O(n) (going
 *       through the hashtable afterwards is O(n) and going through the array as well).
 * 
 * @param arr
 * @param arr_size
 * @return 
 */
char FindMajorityElement(char* arr, const int arr_size) {
  
  int i; 
  char majority_candidate = arr[0];
  
  int surplus = 0;
  
  for (i = 1; i < arr_size; ++i) {
    char letter = arr[i];
    if (majority_candidate == letter) {
      ++surplus;
    } else {      
      if (surplus == 0) {
        majority_candidate = arr[i + 1];
        ++i; // one additional increment needed to go forward two steps in total
      } else {
        --surplus;
      }
    }
  }
  
  return majority_candidate;
}


/**
 * Imagine you have an array with numbers >= 0. Viewing these numbers as the 
 * heights of walls, if you were two pick to of these walls, find those two
 * between the largest amount of water can be stored !
 * 
 * The first inside is that if you move further to the middle of the array,
 * you need to have the wall be much higher to compensate. One could for example
 * imagine that the most water can be stored in the middle of the array, e.g.
 *       | |
 *       | |
 *       | |
 *       | |
 *       | |
 *       | |
 *       | |
 * |   | | | 
 * |_|_|_|_|_|_|
 * 
 * Idea of the algorithm is to calculate the amount of water trapped by the
 * two outermost boundaries and then shift move the smaller of the two 
 * boundaries inside, check if it grows, if no, move on, if yes tentatively
 * check if it has grown so much that we could store more water using this boundary
 * even though it is further to the middle. If yes we have a new candidate
 * for the optimum, and then continue to shrink the boundaries until they meet.
 * 
 * @param arr
 * @param arr_len
 * @param index_left
 * @param index_rght
 */
void FindIndicesForBordersTrappingMostWater(int* arr, 
        const int arr_len, int* index_left, int* index_rght) {
  
  int li = 0;
  int ri = arr_len - 1;  
  int max_water_volume = 0; 
  while (li != ri) {
    // we could actually save some computations here:
    // now we compute the water for each iteration, but
    // actually we know that nothing can improve if the moved boundary
    // got smaller... so we could simply continue in that case
    int width = ri - li;
    int val_li = arr[li];
    int val_ri = arr[ri];
    bool left_is_smallerequal = true;
    if (val_li > val_ri) {
      left_is_smallerequal = false;
    }
    int height = left_is_smallerequal ? val_li : val_ri;    
    int water_volume = width * height; 
    if (water_volume > max_water_volume) {
      max_water_volume = water_volume;
      *index_left = li;
      *index_rght = ri;
    }
    if (left_is_smallerequal) {
      ++li;
    } else {
      --ri;
    }    
  }
  
  return;
}