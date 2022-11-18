/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: noh
 *
 * Created on February 24, 2018, 2:36 PM
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "standardheaders.h"
#include "bitwiseoperators.h"
#include "arrays.h"
#include "strings.h"
#include "linkedlist_as_nodes.h"
#include "linkedlist_as_nodes_stringkey.h"
#include "stack_as_array.h"
#include "stack_as_list.h"
#include "queue_as_array.h"
#include "queue_as_list.h"
#include "queue_as_2stacks.h"
#include "deque_as_array.h"
#include "binarytree_as_nodes.h"
#include "heap_as_array.h"
#include "heap_as_nodes.h"
#include "searching.h"
#include "hashtable_multi.h"
#include "hashtable.h"
#include "sorting_algos.h"
#include "sorting.h"
#include "binarysearchtree.h"
#include "recursion.h"
#include "dynamicprogramming.h"
#include "greedyalgos.h"
#include "invariants.h"

#define STRING_BUFFER_SIZE 512

#define N_ARGUMENTS_EXPECTED 1

/*
 * 
 */
int main (int argc, char** argv) {
    
  char path_to_exe[STRING_BUFFER_SIZE] = "";
  if (argc != N_ARGUMENTS_EXPECTED) {
      printf("Expecting %i argument. You gave %i\n", N_ARGUMENTS_EXPECTED, argc);
      int i = 0;
      for( i = 0; i < argc; ++i) {
        printf("argument[%i] = %s \n", i, argv[i]);
      }
      exit(EXIT_FAILURE);
  } else {
      strncpy(path_to_exe, argv[0], STRING_BUFFER_SIZE);
  }	
  
  //-----------------------
  //MainBitwiseOperators();  
    
  //-----------------------  
  //MainArrays();  
  
  //-----------------------
  //MainStrings();
  
  //-----------------------
  //MainLinkedlistAsNodes();
  
  //-----------------------
  //MainLinkedlistAsNodesStringKey();
  
  //-----------------------
  //MainStackAsArray();
  
  //-----------------------
  //MainStackAsList();
  
  //-----------------------
  //MainQueueAsArray();
  
  //-----------------------
  //MainQueueAsList();
  
  //-----------------------
  //MainQueueAs2Stacks();
    
  //-----------------------
  //MainDequeAsArray();
  
  //-----------------------
  //MainBinaryTreeAsNodes();
  
  //-----------------------
  //MainHeapAsNodes();
  
  //-----------------------
  //MainHeapAsArray();
  
  //-----------------------
  //MainSearching();
  
  //-----------------------
  //MainHashTable(path_to_exe);
    
  //-----------------------
  //MainHashTableMulti(path_to_exe);
    
  //-----------------------
  //MainSortingAlgos();
  
  //-----------------------
  MainSorting();
  
  //-----------------------
  //MainBST();
  
  //-----------------------
  //MainRecursion();
  
  //-----------------------
  //MainDynamicProgramming();
    
  //-----------------------
  //MainGreedyAlgorithms();
  
  //-----------------------
  //MainInvariants();
  
  
  printf("\n..Exiting Main...\n");    
  // getchar(); 
  // --------------> STRANGE !? NEEDED FOR CORRECT OUTPUT IN INTERNAL TERMINAL   
  return 0;
}

