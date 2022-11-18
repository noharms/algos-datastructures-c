/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hashtable.h
 * Author: noh
 *
 * Created on July 29, 2019, 9:30 PM
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#ifdef __cplusplus
extern "C" {
#endif

  #include <stdbool.h>

  #include "standardheaders.h"
  #include "linkedlist_as_nodes_stringkey.h"
#include "queue_as_list.h"
#include "queue_as_array.h"
  
  typedef struct HASHTABLE_TYPE {
    int max_hash; // size of hash-region            
    int n_elems;
    LinkedlistStringKeyT* buffer;
    int (*hash_function)(char*, const int);    
  } HashtableT;
  
  typedef struct ISBNCACHE_TYPE {
    HashtableT ht;
    int capacity;
    LinkedlistStringKeyT prio_queue;
  } ISBNCacheT;
  
  /**
   * Each field can have 13 states. We use the convention
   *  0 = 0b0000  : empty
   *  1 = 0b0001  : white pawn
   *  2 = 0b0010  : white rook
   *  3 = 0b0011  : white knight
   *  4 = 0b0100  : white bishop
   *  5 = 0b0101  : white queen
   *  6 = 0b0110  : white king   
   *  7 = 0b0111  : black pawn
   *  8 = 0b1000  : black rook
   *  9 = 0b1001  : black knight
   * 10 = 0b1011  : black bishop
   * 11 = 0b1100  : black queen
   * 12 = 0b1101  : black king
   * 
   * One row has 8 fields, each needs 4 Bits, i.e. one row needs 32 bit,
   * which is one unsigned int per row.
   */
  typedef struct CHESS_MOVE {
    // bottom left = 0, bottom right = 7, top left = 56, top right = 63
    int old_row; 
    int old_col; 
    int new_row;
    int new_col;
    unsigned char old_figureID; 
    unsigned char new_figureID;
  } ChessMoveT;
  //-----------------------------------------------------------
  void MainHashTable(char* path_to_exe);
    
  void MainHashTable_API();
  void MainHashTable_TestPalindromicity();
  void MainHashTable_LetterInMagazine(char* path_to_exe);
  void MainHashTable_ISBNCache();
  void MainHashTable_LCAOptimizedForCloseAncestors();
  void MainHashTable_MinimalDistanceSameWords();
  void MainHashTable_SearchEngine();
  void MainHashTable_SearchEngineWithOrder();
  void MainHashTable_LongestSubarrayWithDistinctElements();
  void MainHashTable_LargestContiguosIntervalCovered();
  void MainHashTable_SubstringsMatchingCocatenationOfSearchWords();
  void MainHashTable_TestingCollatzConjecture();
  void MainHashTable_HashFunctionForChess();
    
  //-------------------------------------- HashTable APIS
  int HashFunction_String2Int(char* key, const int max_hash_code);
  int HashFunction_String2Int_DumbVersion(char* key, const int max_hash_code);
    
  void HashTable_Insert(HashtableT* ht, char* key, int val);
  void HashTable_Insert_CopyDataNode(HashtableT* hashtable, DataNodeStringKeyIntValT* keyval);
  void HashTable_Erase(HashtableT* hashtable, char* key);  
  DataNodeStringKeyIntValT* HashTable_FindMatch(HashtableT* ht, char* key);
  void HashTable_Init(HashtableT* ht, int (*hashfunc)(char*, const int), int max_hash);
  void HashTable_Destroy(HashtableT* hashtable_ptr);
  void HashTable_Resize(HashtableT* ht);
  
  void HashTable_PrintContent(HashtableT* ht);
  
  //-------------------------------------- ISBN Cache APIS
  
  void ISBNCache_Insert(ISBNCacheT* cache, char* key, int val);
  void ISBNCache_Erase(ISBNCacheT* cache, char* key);
  DataNodeStringKeyIntValT* ISBNCache_FindPrice(ISBNCacheT* cache, char* key);  
  void ISBNCache_Init(ISBNCacheT* cache, int (*hashfunc)(char*, const int), 
          int capacity);
  void ISBNCache_Destroy(ISBNCacheT* cache);
  DataNodeStringKeyIntValT* ISBNCache_LRU(ISBNCacheT* cache);
  
  void ISBNCache_PrintContent(ISBNCacheT* cache);
  
  int HashTable_MinDistanceSameWords(char* sentence[], int n_words);
  
  //-------------------------------------- Algos
  
  bool HashTable_TestPotentialForPalindromicity(char* some_word);
  bool HashTable_LetterConstructibleFromMagazine(char *letter, char *magazine);
  BTNodeWithParentT* HashTable_FindLCAWithHashTable(BTNodeWithParentT* node1, 
        BTNodeWithParentT* node2);
  IntPairT HashTable_FindShortestExtractForKeywordsNoOrder(char** text, int n_text,
        char** search_words, int n_tosearch);
  IntPairT HashTable_FindShortestExtractForKeywordsWithOrder(char** text, int n_text,
        char** search_words, int n_tosearch);
  IntPairT HashTable_LongestSubarrayWithDistinctElements(char** arr_words, int n);
  IntPairT HashTable_LargestContiguosIntervalCovered(int* arr, int n);
  int* HashTable_SubstringsMatchingCocatenationOfSearchWords(char* sentence,
        char** search_words, int n_words, int wordsize);
  bool HashTable_TestCollatzUpToGivenNumber(const ull n);
  
  unsigned int HashTable_ChessHashFunction(unsigned int* board, int max_hash);
  unsigned int HashTable_ChessHashFunctionUpdate(unsigned int* board, 
        unsigned int max_hash, unsigned int old_hash, ChessMoveT move);
  void HashTable_ChessInitialState(unsigned int* board);
  void HashTable_ChessUpdateState(unsigned int* board, ChessMoveT move);
  void HashTable_ChessPrintBoard(unsigned int* board);



#ifdef __cplusplus
}
#endif

#endif /* HASHTABLE_H */

