/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hashtable.h
 * Author: noh
 *
 * Created on March 30, 2018, 3:45 PM
 */

#ifndef HASHTABLE_MULTI_H
#define HASHTABLE_MULTI_H

#ifdef __cplusplus
extern "C" {
#endif
    
  #include <stdbool.h>

  #include "standardheaders.h"
  #include "hashtable.h"
  
  //-----------------------------------------------------------
  void MainHashTableMulti(char* path_to_exe);
    
  void MainHashTableMulti_API();
  void MainHashTableMulti_TestPalindromicity();
  void MainHashTableMulti_LetterInMagazine(char* path_to_exe);  
    
  //-------------------------------------- HashTableMulti APIS    
  void HashTableMulti_Insert(HashtableT* ht, char* key, int val);
  void HashTableMulti_Insert_CopyDataNode(HashtableT* hashtable, DataNodeStringKeyIntValT* keyval);
  void HashTableMulti_Erase(HashtableT* hashtable, char* key);  
  DataNodeStringKeyIntValT* HashTableMulti_FindMatch(HashtableT* ht, char* key);
  void HashTableMulti_Init(HashtableT* ht, int (*hashfunc)(char*, const int), int max_hash);
  void HashTableMulti_Destroy(HashtableT* hashtable_ptr);
  void HashTableMulti_Resize(HashtableT* ht);
  
  
  //-------------------------------------- Algos
    
  
#ifdef __cplusplus
}
#endif

#endif /* HASHTABLE_H */

