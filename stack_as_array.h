/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stack_as_array.h
 * Author: noh
 *
 * Created on July 14, 2019, 10:20 AM
 */

#ifndef STACK_AS_ARRAY_H
#define STACK_AS_ARRAY_H

#ifdef __cplusplus
extern "C" {
#endif
  
  #include <stdbool.h>

  #include "standardheaders.h"
        
  //----------- standard stack that takes a char  
  typedef struct STACK_CHAR_TYPE {    
    int capacity;
    int i_top;    
    DataNodeCharKeyT* arr;
  } StackCharT;
      
  //----------- standard stack that takes an int    
  typedef struct STACK_INT_TYPE {    
    int capacity;
    int i_top;    
    DataNodeIntKeyT* arr;
  } StackIntT;
    
  //----------- standard stack that takes pairs of integers  
  typedef struct STACK_INTPAIR_TYPE {    
    int capacity;
    int i_top;    
    DataNodeIntKeyIntValT* arr;
  } StackIntpairT;
    
  typedef struct STACK_INTPAIRWITHMAX_TYPE {    
    int capacity;
    int i_top;    
    DataNodeIntKeyIntValT* arr;
    StackIntpairT* max_stack;
  } StackIntpairWithMaxT;
  
  //----------- standard stack that takes char-arrays  
  typedef struct STACK_CHARARRAY_TYPE {    
    int capacity;
    int i_top;    
    DataNodeStringKeyT* arr;
  } StackChararrayT;
  
  //-----------------------------------------------------------
  void MainStackAsArray();
  
  void MainStackAsArray_StackIntpairAPI();
  void MainStackAsArray_StackIntpairAPIWithMax();  
  void MainStackAsArray_StackChararrayAPI();
  
  void MainStackAsArray_ReversePolishNotation();
  void MainStackAsArray_WellFormedBracketString();
  void MainStackAsArray_NormalisePathName();
  void MainStackAsArray_BuildingsWithSunsetView();
  
  //-------------------------------------- STACK APIS
  void StackAsArrayOfChar_Init(StackCharT* stack);
  void StackAsArrayOfChar_Destroy(StackCharT* stack);  
  void StackAsArrayOfChar_Push(StackCharT* stack, DataNodeCharKeyT* new_node);
  void StackAsArrayOfChar_Pop(StackCharT* stack);
  DataNodeCharKeyT* StackAsArrayOfChar_Top(StackCharT* stack);  
  
  void StackAsArrayOfInt_Init(StackIntT* stack);
  void StackAsArrayOfInt_Destroy(StackIntT* stack);  
  void StackAsArrayOfInt_Push(StackIntT* stack, DataNodeIntKeyT* new_node);
  void StackAsArrayOfInt_Pop(StackIntT* stack);
  DataNodeIntKeyT* StackAsArrayOfInt_Top(StackIntT* stack);
  
  void StackAsArrayOfIntpair_Init(StackIntpairT* stack);
  void StackAsArrayOfIntpair_Destroy(StackIntpairT* stack);  
  void StackAsArrayOfIntpair_Push(StackIntpairT* stack, DataNodeIntKeyIntValT* new_node);
  void StackAsArrayOfIntpair_Pop(StackIntpairT* stack);
  DataNodeIntKeyIntValT* StackAsArrayOfIntpair_Top(StackIntpairT* stack);
  
  void StackAsArrayOfIntpair_WithMax_Init(StackIntpairWithMaxT* stack);
  void StackAsArrayOfIntpair_WithMax_Destroy(StackIntpairWithMaxT* stack);  
  void StackAsArrayOfIntpair_WithMax_Push(StackIntpairWithMaxT* stack, DataNodeIntKeyIntValT* new_node);
  void StackAsArrayOfIntpair_WithMax_Pop(StackIntpairWithMaxT* stack);
  DataNodeIntKeyIntValT* StackAsArrayOfIntpair_WithMax_Top(StackIntpairWithMaxT* stack);
  int StackAsArrayOfIntpair_WithMax_Max(StackIntpairWithMaxT* stack);    
  
  void StackAsArrayOfChararray_Init(StackChararrayT* stack);
  void StackAsArrayOfChararray_Destroy(StackChararrayT* stack);  
  void StackAsArrayOfChararray_Push(StackChararrayT* stack, DataNodeStringKeyT* new_node);
  void StackAsArrayOfChararray_Pop(StackChararrayT* stack);
  DataNodeStringKeyT* StackAsArrayOfChararray_Top(StackChararrayT* stack);

  //-------------------------------------- Algorithms
  int EvaluateRPNString(char* rpn_str);
  int CpyCharsUntilCommaOrNull(char* dst, char* src);
  
  bool IsWellFormedBracketString(char* str);
  
  char* NormalisePathName(char* filepath);
  
  DataNodeIntKeyIntValT* BuildingsWithSunsetView(int* heights_east_to_west, int n_buildings,
        int* n_view_sunset);
  DataNodeIntKeyIntValT* BuildingsWithSunsetView_StackSolution(int* heights_east_to_west, int n_buildings,
        int* n_view_sunset);

#ifdef __cplusplus
}
#endif

#endif /* STACK_AS_ARRAY_H */

