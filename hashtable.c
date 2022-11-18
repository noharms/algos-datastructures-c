/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "hashtable.h"

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#include "binarytree_as_nodes.h"

void MainHashTable(char* path_to_exe) {  
  printf("\n\n----------------------- MainHashTable \n");
  
  //-----------------------------------------
  // preparations:
  
  //-----------------------------------------
  // Exercises  
  
  MainHashTable_API();
  
  MainHashTable_TestPalindromicity();
  
  MainHashTable_LetterInMagazine(path_to_exe);
    
  MainHashTable_ISBNCache();
  
  MainHashTable_LCAOptimizedForCloseAncestors();
  
  MainHashTable_MinimalDistanceSameWords();
  
  MainHashTable_SearchEngine();
  
  MainHashTable_SearchEngineWithOrder();
  
  MainHashTable_LongestSubarrayWithDistinctElements();
  
  MainHashTable_LargestContiguosIntervalCovered();
  
  MainHashTable_SubstringsMatchingCocatenationOfSearchWords();
    
  MainHashTable_TestingCollatzConjecture();  
  
  MainHashTable_HashFunctionForChess();
  
  return;
}



//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void MainHashTable_API() {
  printf("\n----------------------------------- MainHashTable_API \n");
  
  // start a hashtable
  HashtableT myht;
  const int kMaxHash = 1; // to debug with collisions, use 1
  HashTable_Init(&myht, HashFunction_String2Int, kMaxHash); 
  
  // add some data
  char* key1 = "Enno";
  char* key2 = "Elli";
  char* key3 = "Felix";
  char* key4 = "Prince";
  char* key5 = "Agape";
  char* key6 = "Max";
  char* key7 = "Aaron";
  char* key8 = "Christoph";
  HashTable_Insert(&myht, key1, 32);
  HashTable_Insert(&myht, key2, 29);
  HashTable_Insert(&myht, key3, 30);
  HashTable_Insert(&myht, key4, 1);
  HashTable_Insert(&myht, key1, 15);
  
  // Check hash table
  printf("Check the whole content of the hashtable after the inserts. \n");
  HashTable_PrintContent(&myht);
  printf("\n");
  
  // check Find function
  printf("Check the FindMatch-API \n");
  printf("Key %s has value %i \n", key1, HashTable_FindMatch(&myht, key1)->val);
  printf("Key %s has value %i \n", key2, HashTable_FindMatch(&myht, key2)->val);
  printf("Key %s has value %i \n", key3, HashTable_FindMatch(&myht, key3)->val);
  printf("Key %s has value %i \n", key4, HashTable_FindMatch(&myht, key4)->val);
  printf("\n");
  
  // check if things work after a resize
  HashTable_Resize(&myht);  
  HashTable_Insert(&myht, key5, 11);
  HashTable_Insert(&myht, key6, 13);
  HashTable_Insert(&myht, key7, 15);  
  HashTable_Erase(&myht, key1);  
  HashTable_Erase(&myht, key2);  
  printf("Check content of hashtable after resize, more inserts, and erases. \n");
  HashTable_PrintContent(&myht);
  printf("\n");
  
  // check Find function
  printf("Check the Find function again \n");
  printf("Key %s has value %i \n", key5, HashTable_FindMatch(&myht, key5)->val);
  printf("Key %s has value %i \n", key6, HashTable_FindMatch(&myht, key6)->val);
  printf("Key %s has value %i \n", key7, HashTable_FindMatch(&myht, key7)->val);
  
  HashTable_Destroy(&myht);
  return;
}


void MainHashTable_TestPalindromicity() {
  printf("\n----------------------------------- MainHashTableMulti_TestPalindromicity \n");  
    
  char some_word[] = "ahighhigh";
  bool ispalindromic = HashTable_TestPotentialForPalindromicity(some_word);
  printf("The word %s can %sbe permuted to be palindromic.\n", some_word, 
          (ispalindromic ? "" : "not "));
          
  char some_word2[] = "ahighchigh";
  ispalindromic = HashTable_TestPotentialForPalindromicity(some_word2);
  printf("The word %s can %sbe permuted to be palindromic.\n", some_word2, 
          (ispalindromic ? "" : "not "));
  
  return;
}

void MainHashTable_LetterInMagazine(char* path_to_exe) {
  printf("\n----------------------------------- MainHashTableMulti_LetterInMagazine \n");  
    
  // Read in a letter
  char letter[] = "Dear Angela Merkel "
                  "how are you today ?"
                  "Many Greetings"; 
  
  // construct the path to the magazine 
  const int len_path_to_exe = strlen(path_to_exe);
  int len_exe_name = 0;
  int i = len_path_to_exe - 1;
  while (i > 0 && path_to_exe[i] != '/') {
    --i;
    ++len_exe_name;
  }  
  char relative_path_to_magazine[] = "/../../../input_files/magazine_example.txt";
  const int len_relative_path = strlen(relative_path_to_magazine);  
  char path_to_magazine[1024] = "";
  strncpy(path_to_magazine, path_to_exe, len_path_to_exe - len_exe_name);  
  strncat(path_to_magazine, relative_path_to_magazine, len_relative_path);
  
  // read the magazine
#define MAX_MAGAZINE_SIZE 2048
  char c; 
  FILE *fp;
  fp = fopen(path_to_magazine, "r");
  char magazine[MAX_MAGAZINE_SIZE] = "";
  if (fp == NULL) {
    printf("Could not open file %s. \n", path_to_magazine);
  } else {
    i = 0;
    do {
      c = fgetc(fp); // read char by char until the EOF is returned   
      if (feof(fp)) {
        break;
      }
      // printf("%c \n", c);
      magazine[i++] = c;
    } while (i < MAX_MAGAZINE_SIZE);
    fclose(fp);
  }
  
  // algorithm
  bool isconstructible = HashTable_LetterConstructibleFromMagazine(letter, magazine);
  
  // result
  printf("The letter \n\n");
  printf("%s \n\n", letter);
  printf("can %sbe constructed from the magazine under \n\n", (isconstructible ? 
    "" : "not "));
  printf("%s \n\n.", path_to_magazine);
  
  return;
}



void MainHashTable_ISBNCache() {
  printf("\n----------------------------------- MainHashTable_ISBNCache \n");

  // create ISBN cache
  ISBNCacheT cache;
  ISBNCache_Init(&cache, HashFunction_String2Int, 3);
  
  // put some books with prices in the ISBN cache
  char* ISBN_1 = "0000000000";
  char* ISBN_2 = "0000000011";
  char* ISBN_3 = "1000000012";
  char* ISBN_4 = "0000001102";
  char* ISBN_5 = "100005112X";  // note: last char is checksum -> redundant info, could be spared
  ISBNCache_Insert(&cache, ISBN_1, 20);
  ISBNCache_Insert(&cache, ISBN_2, 5);
  ISBNCache_Insert(&cache, ISBN_3, 2);
  ISBNCache_Insert(&cache, ISBN_4, 12);
  ISBNCache_Insert(&cache, ISBN_5, 10);
  ISBNCache_Insert(&cache, ISBN_5, 20); // Requirement of exercise: price shall not be updated!  
  
  // Check content 
  printf("Check content of ISBN cache after inserts: \n");
  ISBNCache_PrintContent(&cache);
  printf("\n");
  
  // Check cache functionality
  DataNodeStringKeyIntValT* lru = ISBNCache_LRU(&cache);
  if (lru) {
    printf("Least-recently-used ISBN: %s, price: %i \n", lru->key, lru->val);
  } else {
    printf("No least-recently-used ISBN in cache. \n");
  }
  printf("\n");
  
  // lookup prices
  printf("Check the FindPrice API\n");
  printf("ISBN %s has price %i \n", ISBN_5, ISBNCache_FindPrice(&cache, ISBN_5)->val);
  printf("ISBN %s has price %i \n", ISBN_3, ISBNCache_FindPrice(&cache, ISBN_3)->val);
  printf("\n");
  
  // Check cache functionality
  lru = ISBNCache_LRU(&cache);
  if (lru) {
    printf("Least-recently-used ISBN: %s, price: %i \n", lru->key, lru->val);
  } else {
    printf("No least-recently-used ISBN in cache. \n");
  }
  printf("\n");
  
  // remove some books
  ISBNCache_Erase(&cache, ISBN_5);
  ISBNCache_Erase(&cache, ISBN_3);
  printf("Check content of ISBN cache after removals: \n");
  ISBNCache_PrintContent(&cache);
  printf("\n");
  
  // Check cache functionality
  lru = ISBNCache_LRU(&cache);
  if (lru) {
    printf("Least-recently-used ISBN: %s, price: %i \n", lru->key, lru->val);
  } else {
    printf("No least-recently-used ISBN in cache. \n");
  }
  printf("\n");
  
  ISBNCache_Destroy(&cache);
  return;
}

void MainHashTable_LCAOptimizedForCloseAncestors() {
  printf("\n----------------------------------- MainHashTable_FindLCAOptimizedForCloseAncestors \n");
  
  // create a binary tree
  BTWithParentsType bt = { 0 };
  BTNodeWithParentT* node0 = BinaryTree_WithParent_Init(&bt, 0, -42);
  BTNodeWithParentT* node1 = BinaryTree_WithParent_InsertAtNodeAsLeft(node0, 1, -42);
  BTNodeWithParentT* node2 = BinaryTree_WithParent_InsertAtNodeAsRght(node0, 2, -42);
  BTNodeWithParentT* node3 = BinaryTree_WithParent_InsertAtNodeAsLeft(node1, 3, -42);
  BTNodeWithParentT* node4 = BinaryTree_WithParent_InsertAtNodeAsRght(node1, 4, -42);
  BTNodeWithParentT* node5 = BinaryTree_WithParent_InsertAtNodeAsLeft(node2, 5, -42);
  BTNodeWithParentT* node6 = BinaryTree_WithParent_InsertAtNodeAsRght(node2, 6, -42);
  BTNodeWithParentT* node13 = BinaryTree_WithParent_InsertAtNodeAsLeft(node6, 13, -42);
    
  // Print constructed tree
  printf("Doing excercise on a tree that reads in-order \n");  
  BinaryTree_WithParent_PrintSequenceInOrder(bt.root);
  printf("\n");
  
  // find LCA using hashtable
  BTNodeWithParentT* LCA = HashTable_FindLCAWithHashTable(node4, node13);
  printf("Found that LCA of %i and %i is: %i \n", node4->key, node13->key, 
          LCA->key);
  printf("\n");
  
  LCA = HashTable_FindLCAWithHashTable(node5, node13);
  printf("Found that LCA of %i and %i is: %i \n", node5->key, node13->key, 
          LCA->key);
  printf("\n");
  
  BinaryTree_WithParent_Destroy(&bt);
  return;
}

void MainHashTable_MinimalDistanceSameWords() {
  printf("\n----------------------------------- MainHashTable_MinimalDistanceSameWords \n");
  
  // write some sentence
  char* arr_words[] = {"All","work","and","no","play","makes","for","no","work",
    "no","fun","and","no","results"};
  int n_words = sizeof(arr_words) / sizeof(char*);
  
  printf("Working with sentence: \n");
  int i;
  for (i = 0; i < n_words; ++i) {
    printf("%s \n", arr_words[i]);
  }
  printf("\n");
  
  // find min distance of same words
  int min_distance = HashTable_MinDistanceSameWords(arr_words, n_words);
  
  // print result
  printf("The minimal distance between two equal words is: %i \n", min_distance);
  
  return;
}

void MainHashTable_SearchEngine() {
  printf("\n----------------------------------- MainHashTable_SearchEngine \n");
  
  char* text[] = {"My","paramount","object","in","this","struggle","is","to",
    "save","the","Union","and","is","not","either","to","save","or","to",
    "destroy","slavery","If","I","could","save","the","Union","without",
    "freeing","any","slave","I","would","do","it","and","if","I","could",
    "save","it","by","freeing","all","the","slaves","I","would","do","it",
    "and","if","I","could","save","it","by","freeing","some","and",
    "leaving","others","alone","I","would","also","do","that"};
  int n_text = sizeof(text) / sizeof(char*);
  char* search_words[] = {"Union", "save"};
  int n_search = sizeof(search_words) / sizeof(char*);
  
  int i;
  printf("Given the following text: \n\n");
  for (i = 0; i < n_text; ++i) {
    printf("%s\n", text[i]);    
  }
  printf("\n");
  printf("and the following search words \n\n");  
  for (i = 0; i < n_search; ++i) {
    printf("%s\n", search_words[i]);    
  }
  printf("\n");
  
  // result
  IntPairT result = HashTable_FindShortestExtractForKeywordsNoOrder(text, n_text, search_words, n_search);
  printf("the shortest digest that contains the words (in any order) is:\n\n");
  for (i = result.val1; i <= result.val2; ++i) {
    printf("%s\n", text[i]);
  }
  printf("\n");
  
  return;
}


void MainHashTable_SearchEngineWithOrder() {
  printf("\n----------------------------------- MainHashTable_SearchEngineWithOrder \n");
  
  char* text[] = {"My","paramount","object","in","this","struggle","is","to",
    "save","the","Union","and","is","not","either","to","save","or","to",
    "destroy","slavery","If","I","could","save","the","Union","without",
    "freeing","any","slave","I","would","do","it","and","if","I","could",
    "save","it","by","freeing","all","the","slaves","I","would","do","it",
    "and","if","I","could","save","it","by","freeing","some","and",
    "leaving","others","alone","I","would","also","do","that"};
  int n_text = sizeof(text) / sizeof(char*);
  char* search_words[] = {"Union", "save"};
  int n_search = sizeof(search_words) / sizeof(char*);
  
  int i;
  printf("Given the following text: \n\n");
  for (i = 0; i < n_text; ++i) {
    printf("%s\n", text[i]);    
  }
  printf("\n");
  printf("and the following search words \n\n");  
  for (i = 0; i < n_search; ++i) {
    printf("%s\n", search_words[i]);    
  }
  printf("\n");
  
  // result
  IntPairT result = HashTable_FindShortestExtractForKeywordsWithOrder(text, 
          n_text, search_words, n_search);
  printf("the shortest digest that contains the words (in order) is:\n\n");
  for (i = result.val1; i <= result.val2; ++i) {
    printf("%s\n", text[i]);
  }
  printf("\n");
  
  return;
}


void MainHashTable_LongestSubarrayWithDistinctElements() {
  printf("\n----------------------------------- MainHashTable_LongestSubarrayWithDistinctElements \n");
  
  char* arr[] = {"f","s","f","e","t","w","e","n","w","e"};
  int n_elems = sizeof(arr) / sizeof(char*);
  
  printf("Given the array of characters :\n");
  int i;
  for (i = 0; i < n_elems; ++i) {
    printf("%s ", arr[i]);
  }
  printf("\n\n");
  
  printf("The longest subarray of distinct characters is:\n");
  IntPairT result = HashTable_LongestSubarrayWithDistinctElements(arr, n_elems);
  for (i = result.val1; i <= result.val2 ; ++i) {
    printf("%s ", arr[i]);
  }
  printf("\n\n");
  
  return;
}

void MainHashTable_LargestContiguosIntervalCovered() {
  printf("\n----------------------------------- MainHashTable_LargestContiguosIntervalCovered \n");
  
  int arr[] = {3,-2,7,9,8,1,2,0,-1,5,8};
  int n = sizeof(arr) / sizeof(int);
  
  printf("Working on the array of numbers:\n");
  int i;
  for (i = 0; i < n; ++i) {    
    printf("%i\n", arr[i]);
  }
  printf("\n");
  
  // find the largest contiguous interval
  IntPairT lr = HashTable_LargestContiguosIntervalCovered(arr, n);
    
  printf("The largest interval with all elements covered is:\n");
  for (i = lr.val1; i <= lr.val2; ++i) {    
    printf("%i\n", i);
  }
  printf("\n");
  
  return;
}

void MainHashTable_SubstringsMatchingCocatenationOfSearchWords() {
  printf("\n----------------------------------- MainHashTable_SubstringsMatchingCocatenationOfSearchWords \n");
  
  char* sentence = "shitaplanacanaplalshitshatcanaplanaaplaaashit";
  char* search_words[] = {"can","apl","ana","apl"};  
  int n_words = sizeof(search_words) / sizeof(char*);
  int wordsize = strlen(search_words[0]);
    
  printf("Given the sentence string :\n");
  printf("%s \n", sentence);
  printf("\n");
  
  printf("and the search words :\n");
  int i;
  for (i = 0; i < n_words; ++i) {
    printf("%s ", search_words[i]);
  }
  printf("\n\n");
  
  int* matches_i0 =  HashTable_SubstringsMatchingCocatenationOfSearchWords(sentence,
          search_words, n_words, wordsize);
  
  printf("The following substrings of sentence are a cocatentation of \n");
  printf("the search words: \n");
  for (i = 1; i < matches_i0[0]; ++i) {
    char buffer[64];
    strncpy(buffer, sentence + matches_i0[i], n_words * wordsize);
    buffer[n_words * wordsize + 1] = '\0';
    printf("%s \n", buffer);
  }
  
  free(matches_i0);
  return;
}

void MainHashTable_TestingCollatzConjecture() {
  printf("\n----------------------------------- MainHashTable_TestingCollatzConjecture \n");

  const ull test_n = 100;
  bool is_satisfied = HashTable_TestCollatzUpToGivenNumber(test_n);
  
  printf("The Collatz conjecture was %sverified up to %llu \n", (is_satisfied ?
    "" : "not "), test_n);
  
  return;
}

void MainHashTable_HashFunctionForChess() {
  printf("\n----------------------------------- MainHashTable_HashFunctionForChess \n");  
  
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
  unsigned int chess_state[8] = {0};
  int kMaxHash = pow(10, 4);
  
  // initial state: print and show hash
  HashTable_ChessInitialState(chess_state);
  HashTable_ChessPrintBoard(chess_state);  
  unsigned int hash_code_func = HashTable_ChessHashFunction(chess_state, kMaxHash);  
  printf("-> hash_code of: %u \n\n", hash_code_func);
  printf("---\n");
  unsigned int initial_hash = hash_code_func;
  
  // make a move: print and show hash
  ChessMoveT move1 = {0,1,2,2,3,3};
  HashTable_ChessUpdateState(chess_state, move1);
  HashTable_ChessPrintBoard(chess_state);
  int hash_code_upd = HashTable_ChessHashFunctionUpdate(chess_state, kMaxHash, hash_code_func,
          move1);
  hash_code_func  = HashTable_ChessHashFunction(chess_state, kMaxHash);
  printf("-> hash_code of: %u (should be %u) \n\n", hash_code_upd, hash_code_func);
  printf("---\n");
  
  // make three more moves, that lead back to initial state
  ChessMoveT move2 = {7,1,5,2,9,9};
  HashTable_ChessUpdateState(chess_state, move2);
  HashTable_ChessPrintBoard(chess_state);
  hash_code_upd = HashTable_ChessHashFunctionUpdate(chess_state, kMaxHash, hash_code_upd,
          move2);
  hash_code_func  = HashTable_ChessHashFunction(chess_state, kMaxHash);
  printf("-> hash_code of: %u (should be %u) \n\n", hash_code_upd, hash_code_func);
  printf("---\n");
    
  ChessMoveT move3 = {2,2,0,1,3,3};
  HashTable_ChessUpdateState(chess_state, move3);
  HashTable_ChessPrintBoard(chess_state);
  hash_code_upd = HashTable_ChessHashFunctionUpdate(chess_state, kMaxHash, hash_code_upd,
          move3);
  hash_code_func  = HashTable_ChessHashFunction(chess_state, kMaxHash);
  printf("-> hash_code of: %u (should be %u) \n\n", hash_code_upd, hash_code_func);
  printf("---\n");
  
  ChessMoveT move4 = {5,2,7,1,9,9};  
  HashTable_ChessUpdateState(chess_state, move4);
  HashTable_ChessPrintBoard(chess_state);  
  hash_code_upd = HashTable_ChessHashFunctionUpdate(chess_state, kMaxHash, hash_code_upd,
          move4);
  hash_code_func  = HashTable_ChessHashFunction(chess_state, kMaxHash);
  printf("-> hash_code of: %u (should be %u) \n\n", hash_code_upd, hash_code_func);
  printf("---\n");
  
  printf("Hash code is %sback at initial hash_code.\n", (initial_hash == hash_code_upd ?
    "" : "not "));
  
  return;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//-------------------------------------------------------------- Hashtable API

/**
 * idea: 
 * 
 * h(c_0, .., c_m-1; x) = c_0 x^m-1 + c_1 x^m-2 + ... + c_m-1 
 * 
 * @param key
 * @param max_hash_code
 * @return 
 */
int HashFunction_String2Int(char* key, const int max_hash_code) {
  int kMult = 57, hash = 0, m = 0;
  while (key[m]) {hash = (hash * kMult + key[m++]) % max_hash_code;}
  return hash % max_hash_code;
}

/*
 * dumb version:
 * --> go through the string and include info for every char into the
 *     hash_code
 * 
 */
int HashFunction_String2Int_DumbVersion(char* key, const int max_hash_code) {
  int hash_code = 0;
  int len_key = strlen(key);
  int i = 0;
  for (i = 0; i < len_key; ++i) {
    char c = key[i];
    hash_code += c;
  }    
  return (hash_code % max_hash_code);
}

    
/**
 * note: no duplicates allowed. therefore, need to make full-blown
 * comparison of new key with all other keys already in bucket.
 * 
 *    -> if node with same key already in bucket 
 *       overwrite the existing node's value with the new value
 * 
 * returns the new 
 * number of elements in the bucket that the new key was inserted to
 * 
 * @param ht
 * @param keyval
 * @return 
 */
void HashTable_Insert(HashtableT* ht, char* key, int val) {
  int i_bucket = ht->hash_function(key, ht->max_hash);
  LinkedlistStringKeyT* bucket = &(ht->buffer[i_bucket]);  
  ListNodeStringKeyIntValT* match = LinkedListStringKey_FindMatch(bucket, key);
  if (match) { // overwrite old value of existing node with same key
    LinkedListStringKey_UpdateElement(match, val);
  } else { // key not found, put new node to front of bucket
    LinkedListStringKey_PushFront(bucket, key, val);
    ++(ht->n_elems);    
  }
  return;
}

void HashTable_Insert_CopyDataNode(HashtableT* ht, DataNodeStringKeyIntValT* keyval) {
  int i_bucket = ht->hash_function(keyval->key, ht->max_hash);
  LinkedlistStringKeyT* bucket = &(ht->buffer[i_bucket]);  
  ListNodeStringKeyIntValT* match = LinkedListStringKey_FindMatch(bucket, keyval->key);          
  if (match) { // overwrite old value of existing node with same key
    LinkedListStringKey_UpdateElement(match, keyval->val);
  } else { // key not found, put new node to front of bucket
    LinkedListStringKey_PushFront(bucket, keyval->key, keyval->val);
    ++(ht->n_elems);    
  }
  return;
}



/**
 * Erases the first node in the bucket that has the same key
 * 
 * (since we do not allow duplicates here, there should maximally be one
 *  node with matching key already in bucket)
 * 
 * @param hashtable
 * @param key
 * @return 
 */
void HashTable_Erase(HashtableT* ht, char* key) {
  int i_bucket = ht->hash_function(key, ht->max_hash);
  LinkedlistStringKeyT* bucket = &(ht->buffer[i_bucket]);
  ListNodeStringKeyIntValT* predecessor = LinkedListStringKey_FindMatchPredecessor(
          bucket, key);
  if (predecessor) {
    LinkedListStringKey_DeleteAfterNode(bucket, predecessor);
    --(ht->n_elems);
  } else if (strcmp(bucket->head->data.key,key) == 0) { // no predecessor, key at 1st element
    LinkedListStringKey_PopFront(bucket);
    --(ht->n_elems);
  } else {
    // key not found in table. do nothing
  }
  return;
}

/**
 * Basically a wrapper for the list findMatch, O(m), where m is the number
 * of elements in the list, so typically we expect m = 1 here.
 * 
 * @param ht
 * @param key
 * @return 
 */
DataNodeStringKeyIntValT* HashTable_FindMatch(HashtableT* ht, char* key) {
  int i_bucket = ht->hash_function(key, ht->max_hash);
  LinkedlistStringKeyT* bucket = &(ht->buffer[i_bucket]);
  ListNodeStringKeyIntValT *match_in_bucket = LinkedListStringKey_FindMatch(bucket, key);
  return (match_in_bucket ? &(match_in_bucket->data) : NULL);  
}

void HashTable_Init(HashtableT* ht, int (*hashfunc)(char*, const int), int max_hash) {    
  ht->hash_function = hashfunc;
  ht->n_elems = 0;
  ht->max_hash = max_hash;  // reduce to 1 to see that collisions work
  ht->buffer = calloc(ht->max_hash, sizeof(LinkedlistStringKeyT));
  int i;
  for (i = 0; i < ht->max_hash; ++i) {    
    LinkedlistStringKeyT* bucket = &(ht->buffer[i]);
    LinkedListStringKey_Init(bucket);
  }
  return;
}

void HashTable_Destroy(HashtableT* ht) {
  int i = 0;
  for (i = 0; i < ht->max_hash; ++i) {
    LinkedlistStringKeyT* bucket = &(ht->buffer[i]);    
    LinkedListStringKey_Destroy(bucket);    
  }
  ht->n_elems = 0;
  ht->max_hash = 0;
  free(ht->buffer);
  return;
}


 void HashTable_Resize(HashtableT* ht) {
  HashtableT new_ht;
  HashTable_Init(&new_ht, ht->hash_function, 2 * ht->max_hash);
  int i;
  for (i = 0; i < ht->max_hash; ++i) { // re-insert all elems from all buckets
    LinkedlistStringKeyT* bucket = &(ht->buffer[i]);        
    ListNodeStringKeyIntValT* curr = bucket->head;
    while (curr) {      
      HashTable_Insert(&new_ht, curr->data.key, curr->data.val);
      curr = curr->next;
    }
  }  
  HashTable_Destroy(ht);
  *ht = new_ht;
  return;
}

void HashTable_PrintContent(HashtableT* ht) {
  int i;
  for (i = 0; i < ht->max_hash; ++i) {
    LinkedlistStringKeyT* bucket = &(ht->buffer[i]);
    if (bucket->n_nodes > 0) {
      printf("In bucket %i we have the following keys: \n", i);
      ListNodeStringKeyIntValT* curr = bucket->head;
      int count = 0;
      while (curr) {
        printf("bucket[%i] has key: %s \n", count, curr->data.key);
        curr = curr->next;
        ++count;
      }      
    }
  }
  return;
}

//-------------------------------------------------------------- ISBNCache API

void ISBNCache_Insert(ISBNCacheT* cache, char* key, int val) {
  DataNodeStringKeyIntValT* match = HashTable_FindMatch(&(cache->ht), key);
  if (!match) {
    if (cache->ht.n_elems == cache->capacity) { // delete lowest priority elem
      ListNodeStringKeyIntValT* tail = LinkedListStringKey_GetTail(&(cache->prio_queue));
      HashTable_Erase(&(cache->ht), tail->data.key);
      LinkedlistStringKey_DeleteTail(&(cache->prio_queue));      
    }
    HashTable_Insert(&(cache->ht), key, val);    
    LinkedListStringKey_PushFront(&(cache->prio_queue), key, val);    
  } else { // exercise says: no update of price, but of priority
    LinkedlistStringKey_DeleteKey(&(cache->prio_queue), key);
    LinkedListStringKey_PushFront(&(cache->prio_queue), key, match->val);    
  }
  return;
}
void ISBNCache_Erase(ISBNCacheT* cache, char* key) {  
  LinkedlistStringKey_DeleteKey(&(cache->prio_queue), key);
  HashTable_Erase(&(cache->ht), key);
  return;
}
DataNodeStringKeyIntValT* ISBNCache_FindPrice(ISBNCacheT* cache, char* key) {
  DataNodeStringKeyIntValT* match = HashTable_FindMatch(&(cache->ht), key);
  if (match) { // update priority, if key is present: give highest priority
    LinkedlistStringKey_DeleteKey(&(cache->prio_queue), key);
    LinkedListStringKey_PushFront(&(cache->prio_queue), key, match->val);
  }
  return match;
}
void ISBNCache_Init(ISBNCacheT* cache, int (*hashfunc)(char*, const int), 
        int capacity) {
  cache->capacity = capacity;
  HashTable_Init(&(cache->ht), hashfunc, capacity);
  LinkedListStringKey_Init(&(cache->prio_queue));  
  return;
}
void ISBNCache_Destroy(ISBNCacheT* cache) {
  LinkedListStringKey_Destroy(&(cache->prio_queue));
  HashTable_Destroy(&(cache->ht));  
  return;
}
DataNodeStringKeyIntValT* ISBNCache_LRU(ISBNCacheT* cache) {
  return &(cache->prio_queue.head->data);
}
void ISBNCache_PrintContent(ISBNCacheT* cache) {
  HashTable_PrintContent(&(cache->ht));
}
 
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//-------------------------------------------------------------- Algos
 
/*
 * Exercise:
 * 
 * given a string, test if a given word CAN be made a palindrom (in that
 * case we say the word is palindromic).
 * 
 * Idea:
 * 
 * In a palindromic word, each character must appear an even number of times,
 * except one is allowed to appear an odd number of times (the excess occurence
 * goes as the middle character in the palindrome).
 * 
 * We can thus use a hash-set instead of hash-map, remove the entry if
 * it comes for the second time, and check in the end that there is only
 * one entry.
 * 
 * 
 * Note: This exercise does not necessarily need a hashtable,
 * if the input string is restricted to consist of only ascii-characters
 * - the counting could be done with an int array[256]
 *  
 * 
 */
bool HashTable_TestPotentialForPalindromicity(char* word) {
  if (!word) {return false;} 
  HashtableT ht_char2count = { 0 };  
  HashTable_Init(&ht_char2count, HashFunction_String2Int, 256);    
  int i = 0;
  while (word[i]) {
    char char_as_str[2];
    sprintf(char_as_str, "%c", word[i]);
    if (HashTable_FindMatch(&ht_char2count, char_as_str)) {
      HashTable_Erase(&ht_char2count, char_as_str);
    } else {
      HashTable_Insert(&ht_char2count, char_as_str, 1);
    }
    ++i;
  }  
  bool is_palindromic = ht_char2count.n_elems > 1 ? false : true;
  HashTable_Destroy(&ht_char2count);  
  return is_palindromic;
}

/**
 * Exercise: 
 * 
 *    Given a letter and a magazine as two strings, find out whether
 *    the letter can be written from the magazine: each char of the letter
 *    needs to appear at least as many times in the magazine as it appears
 *    in the letter.
 * 
 * Idea:
 * 
 *    Cache the frequency of all characters found in the letter, 
 *    then traverse the magazine and remove character by character that
 *    you find in the magazine.
 * 
 * Complexity:
 * 
 *    time: O(m) + O(n), with m number of chars in letter and n in magazine
 *    space: O(m)
 * 
 * @param letter
 * @param magazine
 * @return 
 */
bool HashTable_LetterConstructibleFromMagazine(char *letter, char *magazine) {  
  HashtableT char2freq = {0};
  HashTable_Init(&char2freq, HashFunction_String2Int, 256);  
  int i = 0;  
  while (letter[i]) {
    char char_as_str[2];
    sprintf(char_as_str, "%c", letter[i]);
    DataNodeStringKeyIntValT* match = HashTable_FindMatch(&char2freq, char_as_str);
    int new_val = (match ? match->val + 1 : 1);    
    HashTable_Insert(&char2freq, char_as_str, new_val);
    ++i;
  }
  i = 0;
  while (magazine[i] && char2freq.n_elems) {
    char char_as_str[2];
    sprintf(char_as_str, "%c", magazine[i]);
    DataNodeStringKeyIntValT* match = HashTable_FindMatch(&char2freq, char_as_str);
    if (match && match->val > 1) {
      HashTable_Insert(&char2freq, char_as_str, match->val - 1);
    } else if (match && match->val == 1) {
      HashTable_Erase(&char2freq, char_as_str);
    }
    ++i;
  }
  bool isconstructible = (char2freq.n_elems == 0 ? true : false);
  HashTable_Destroy(&char2freq);
  return isconstructible;
}

/**
 * Exercise:
 * 
 * Given a binary tree of unique keys and nodes with parent pointers,
 * design an algorithm that is optimised for close ancestors.
 * 
 * Idea:
 * 
 * Allow ourselves extra space in hash table to track upward paths
 * from both nodes until one path reaches a node that was already
 * passed by the other one.
 * 
 * 
 * @param node1
 * @param node2
 * @return 
 */
BTNodeWithParentT* HashTable_FindLCAWithHashTable(BTNodeWithParentT* node1, 
        BTNodeWithParentT* node2) {
  if( !node1 || !node2 ) return NULL;
  BTNodeWithParentT* LCA = NULL;
  HashtableT keys_seen = {0};
  HashTable_Init(&keys_seen, HashFunction_String2Int, 20);
  BTNodeWithParentT* curr1 = node1;  
  BTNodeWithParentT* curr2 = node2;
  while (curr1 || curr2) {
    char key_as_str[5];
    if (curr1) {
      sprintf(key_as_str, "%i", curr1->key);
      if (HashTable_FindMatch(&keys_seen, key_as_str)) {
        LCA = curr1;
        break;
      }
      HashTable_Insert(&keys_seen, key_as_str, curr1->key);
      curr1 = curr1->parent;
    }
    if (curr2) {
      sprintf(key_as_str, "%i", curr2->key);
      if (HashTable_FindMatch(&keys_seen, key_as_str)) {
        LCA = curr2;
        break;
      }
      HashTable_Insert(&keys_seen, key_as_str, curr2->key);
      curr2 = curr2->parent;
    }    
  }
  HashTable_Destroy(&keys_seen);
  return LCA;
}

/**
 * Exercise:
 * 
 * Given a sentence as an array of words, find the minimal distance
 * between the same words. If no words are the same, return -1.
 * 
 * Idea:
 * 
 * Store all seen words together with their latest index
 * and for each new word check if it was already seen before:
 * if yes find the distance by substracting the current index from the
 * index stored for that word earlier.
 * 
 * Complexitites:
 * 
 *  time - O(n), where n is the number of words
 *  space - O(n)
 * 
 * @param sentence
 * @param n_words
 * @return 
 */
int HashTable_MinDistanceSameWords(char* sentence[], int n_words) {
  int min_distance = INT_MAX;
  HashtableT word2latestidx = {0};
  HashTable_Init(&word2latestidx, HashFunction_String2Int, 30);
  int i;
  for (i = 0; i < n_words; ++i) {
    char* word = sentence[i];
    DataNodeStringKeyIntValT* match = HashTable_FindMatch(&word2latestidx, word);
    if (match) {
      int distance = i - match->val;
      min_distance = (distance < min_distance ? distance : min_distance);      
    }
    HashTable_Insert(&word2latestidx, word, i);
  }
  HashTable_Destroy(&word2latestidx);
  return min_distance;
}


/**
 * Exercise: 
 * 
 * Given a text and a number of search words, find the shortest digest/extract
 * of the text that covers all search words, no matter in which order.
 * 
 * Idea:
 * 
 * Use left and rght boundaries that scan through the text, both starting
 * at 0 and spanning a candidate digest.
 * Let the right boundary drift right, checking each word in the
 * text against the search words (use hash-table for search words, so that
 * lookup for keys is O(1)), and use the value as the count of the word.
 * Raise value if the word is found again and keep track of how many
 * search words are still missing in a separate tracker variable.
 * Once the new word reduces the missing words to 0, the drift of the right
 * boundary stops. This gives the first candidates for the digests start
 * and end indices. Then let the left boundary drift to the right,
 * removing word by word from the set of seen words until
 * the search words are no longer covered. then it is time for the
 * right boundary to proceed again until the search words are covered again.
 * 
 * Complexity:
 * 
 * time: O(n) , where n is the number of words in the text
 * space: O(n) (worst-case search words are not contained)
 * 
 * 
 * @param text
 * @param search_words
 * @param n_words
 * @return 
 */
IntPairT HashTable_FindShortestExtractForKeywordsNoOrder(char** text, int n_text,
        char** search_words, int n_tosearch) {
  IntPairT idxpair = {0, INT_MAX};
  HashtableT searchword2count = {0};
  HashTable_Init(&searchword2count, HashFunction_String2Int, 256);
  int i = 0;
  for (i = 0; i < n_tosearch;++i) {
    HashTable_Insert(&searchword2count, search_words[i], 0);
  }  
  int l = 0, r = 0;
  while (r < n_text) {
    char *new_word = text[r];
    DataNodeStringKeyIntValT* match = HashTable_FindMatch(&searchword2count, new_word);
    if (match) {
      if (match->val == 0) {--n_tosearch;}
      HashTable_Insert(&searchword2count, new_word, match->val + 1);
    }
    if (n_tosearch == 0) {
      while (l <= r && n_tosearch == 0) {        
        if (r - l < idxpair.val2 - idxpair.val1) {
          idxpair.val1 = l;
          idxpair.val2 = r;
        }
        char *old_word = text[l];        
        DataNodeStringKeyIntValT* match = HashTable_FindMatch(&searchword2count, old_word);
        if (match) {
          if (match->val == 1) {++n_tosearch;}
          HashTable_Insert(&searchword2count, old_word, match->val - 1);
        }        
        ++l;
      }
    }
    ++r;
  }
  HashTable_Destroy(&searchword2count);
  return (idxpair.val2 == INT_MAX ? (IntPairT){-1, -1} : idxpair);
}

/**
 * Exercise:
 * 
 *  Given a text and a number of search words, find the shortest digest/extract
 *  of the text that covers all search words in the order they were requested.
 * 
 * Idea:
 * 
 *  The restriction to keep the order allows us to ignore many candidate extracts.
 *  On the one hand, a keyword that is at the end of the request but
 *  appears first in the text, can be discarded.
 *  On the other hand, of multiple appearances of the same keyword in the
 *  text, for the search for a shortest extract only the last is
 *  relevant.
 *  E.g.: given the text (a, b, x, a, a, a, c, a, ...) and the search words (a, b, c)
 *  we know when reading the a at i = 7 that 
 *  the resulting extract will never start at i=3, i=4, or i=5.
 * 
 *  It is enough to track for all search words the rightmost index of 
 *  an extract that covers all keywords coming before the search word.
 *  This can be efficiently done with a hash table.
 *  For example, when traversing the above sequence the hash table would
 *  look like 
 *  ({a->0}, {a->0, b->0}, ", {a->3,b->0}, {a->4,b->0},{a->5,b->0},",
 *   {a->5, b->0, c->0},{a->6, b->0,c->0})
 *  Whenever the index for the last keyword is updated it means we found
 *  a new extract that covers all words in order, and thus we should
 *  check if it is a shorter extract than the one found so far.
 * 
 *  Note: we would actually have to map each keyword to its position
 *  and its rightmost index in the text that covers all keywords up to it.
 *  --> since we only have one value in our hashtable datatype, we use two tables
 *  
 * 
 * @param text
 * @param n_text
 * @param search_words
 * @param n_tosearch
 * @return 
 */
IntPairT HashTable_FindShortestExtractForKeywordsWithOrder(char** text, int n_text,
        char** search_words, int n_tosearch) {
  IntPairT idxpair = {0, INT_MAX};
  HashtableT key2pos = {0}, key2i0coversubsearch = {0};
  HashTable_Init(&key2pos, HashFunction_String2Int, 100);
  HashTable_Init(&key2i0coversubsearch, HashFunction_String2Int, 100);
  int i = 0;
  for (i = 0; i < n_tosearch; ++i) {
    HashTable_Insert(&key2pos, search_words[i], i);
  }
  for (i = 0; i < n_text; ++i) {
    DataNodeStringKeyIntValT* match = HashTable_FindMatch(&key2pos, text[i]);    
    if (match) {
      if (match->val == 0) { // first keyword: can always update its i0
        HashTable_Insert(&key2i0coversubsearch, match->key, i);
      } else { // check if previous keyword is already covered        
        DataNodeStringKeyIntValT* pair = HashTable_FindMatch(&key2i0coversubsearch,
                search_words[match->val - 1]);
        if (pair) { // yes! previous keyword already covered
          HashTable_Insert(&key2i0coversubsearch, match->key, pair->val);
          if (match->val == n_tosearch - 1) { // last keyword found
            idxpair = (i - pair->val < idxpair.val2 - idxpair.val1 ? 
              (IntPairT){pair->val, i} : (IntPairT){idxpair.val1,idxpair.val2}); 
          }
        }        
      }      
    }
  }
  HashTable_Destroy(&key2pos);
  HashTable_Destroy(&key2i0coversubsearch);
  return idxpair;
}


/**
 * Exercise:
 * 
 * Given an array of elements with duplicates allowed, say characters,
 * find the longest sequence/subarray that contains distinct elements.
 * 
 * Idea:
 * 
 * Traverse the array and build up a hash-set of unique elements for the
 * current candidate span, which is identified by its left and right
 * boundary index.
 * Start to drift right with the right boundary until a duplicate is found. 
 * Once a duplicate is encountered the length of the current candidate
 * subarray is evaluated and a new candidate is set, by drifting with
 * the left boundary to the right until the first occurence of the duplicate
 * is encountered and removing all characters seen on the way from the
 * hash-set.
 * 
 * @param arr_words
 * @param n
 * @return 
 */
IntPairT HashTable_LongestSubarrayWithDistinctElements(char** arr_words, int n) {
  IntPairT lr = {0,0};
  int l = 0, r = 0;
  HashtableT seen_keys = {0};
  HashTable_Init(&seen_keys, HashFunction_String2Int, 256);
  while (r < n) {
    char* new_word = arr_words[r];
    DataNodeStringKeyIntValT* match = HashTable_FindMatch(&seen_keys, new_word);
    if (match) {
      lr = (r - 1 - l > lr.val2 - lr.val1 ? (IntPairT){l, r - 1} : lr);      
      while (strcmp(arr_words[l], new_word) != 0) {
        HashTable_Erase(&seen_keys, arr_words[l]);
        ++l;
      } // now l is at the duplicate
      HashTable_Erase(&seen_keys, arr_words[l]);
      ++l;
    }
    HashTable_Insert(&seen_keys, new_word, -42);    
    ++r;
  }
  HashTable_Destroy(&seen_keys);
  return lr;
}

/**
 * Exercise:
 * 
 * Given an array of integers (duplicates allowed), find the largest
 * interval for which all its elements are covered by the array.
 * 
 * Idea:
 * 
 * A brute force solution would be to sort the array and then march
 * through it checking if a step larger than 1 is needed to identify
 * when a new interval starts. This would be O(n log n).
 * 
 * We can do better by using O(n) space. Every encountered number
 * is added to a hash-table which maps the number to the length
 * of the interval that can be covered by previously seen numbers
 * together with this one. E.g. the first number will cover a length 1
 * interval. If its left or reight neighbor is added, both will
 * cover a length 2 interval. Thus, the logic is to check upon
 * every new insertion whether left and/or right neighbor are
 * already present. If only one side is present we raise the covered
 * interval by 1 for all of them. If both sides are present, we 
 * add up the length of the intervals left and right and add 1 to
 * get the length that they are covering now. 
 * Thus we have an average O(n) algorithm, which in the worst
 * case is, however, O(n * n): imagine the array is sorted and
 * covers one big interval. then each new insertion requires to
 * update all previous seen elements.
 * 
 * We can remove the problem by going the other way around.
 * We start with a hashset containing all numbers of the array.
 * Then we traverse the array and for each number we check
 * how large an interval we can cover that includes this number
 * by testing for left and right neighbors in the hash table.
 * Once there are no further neighbors, we can remove all
 * entries visited because we know that they are not connected
 * to any other interval present in the hashtable.
 * Thus, we have an O(n) time and O(n) space algorithm.
 * 
 * @param arr
 * @param n
 * @return 
 */
IntPairT HashTable_LargestContiguosIntervalCovered(int* arr, int n) {
  IntPairT lr = {1,0};
  HashtableT unprocessed = {0};
  HashTable_Init(&unprocessed, HashFunction_String2Int, 100);
  int i;
  for (i = 0; i < n; ++i) {
    char num_as_str[5];
    sprintf(num_as_str, "%i", arr[i]);
    HashTable_Insert(&unprocessed, num_as_str, -42);
  }
  char m_as_str[5], l_as_str[5], r_as_str[5];  
  while (unprocessed.n_elems > 0) {
    int m = *arr, l = m - 1, r = m + 1;
    sprintf(m_as_str, "%i", m);    
    if (HashTable_FindMatch(&unprocessed, m_as_str)) {
      HashTable_Erase(&unprocessed, m_as_str);      
      sprintf(l_as_str, "%i", l);
      sprintf(r_as_str, "%i", r);
      while (HashTable_FindMatch(&unprocessed, l_as_str)) {
        HashTable_Erase(&unprocessed, l_as_str);
        sprintf(l_as_str, "%i", --l);
      }
      while (HashTable_FindMatch(&unprocessed, r_as_str)) {        
        HashTable_Erase(&unprocessed, r_as_str);
        sprintf(r_as_str, "%i", ++r);        
      }      
      lr = ((r - 1) - (l + 1) > lr.val2 - lr.val1 ? (IntPairT){l + 1, r - 1} : lr);      
    }
    ++arr;
  }
  HashTable_Destroy(&unprocessed);
  return lr;
}

/**
 * Exercise:
 * 
 * Given a sentence string, find all substrings that are
 * a cocatenation of a given set of m search strings (duplicates allowed),
 * where each search string has the same length k.
 * 
 * Idea:
 * 
 * Every index of the sentence is a potential starting point
 * for a matching substring. So we traverse the sentence char by char
 * and then check if the substring is cocatenation.
 * The cocatenation check goes as follows:
 *  we provide the search words in hash table together with the info
 *  how many times a search word appears. 
 *  in a second hash table we track how many times a search word
 *  was already found in the current substring.  
 *  So, we check if the first k characters of the substring match
 *  a search word. If not, we break.
 *  If yes, we raise the number of times the search word
 *  appeared in the current substring. if the number is smaller than the
 *  number it should appear, as noted in the first hash table, we continue.
 *  if not, we break.
 *  Then continue with the next k characters.
 * 
 * Complexity:
 * 
 *  time: O(n * m * k)
 *  
 * 
 * @param sentence
 * @param search_words
 * @param n_words
 * @return 
 */
int* HashTable_SubstringsMatchingCocatenationOfSearchWords(char* sentence,
        char** search_words, int n_words, int wordsize) {
  int n_sentence = strlen(sentence);
  int* substrings_i0 = calloc(1, sizeof(int));
  int n_results = 0;
  HashtableT word2freqneeded = {0};
  HashTable_Init(&word2freqneeded, HashFunction_String2Int, 100);
  int i, j;
  for (i = 0; i < n_words; ++i) {
    DataNodeStringKeyIntValT* match = HashTable_FindMatch(&word2freqneeded, 
            search_words[i]);    
    HashTable_Insert(&word2freqneeded, search_words[i], (match ? match->val + 1 : 1));
  }
  for (i = 0; i + n_words * wordsize < n_sentence; ++i) {
    HashtableT word2freqfound = {0};
    HashTable_Init(&word2freqfound, HashFunction_String2Int, 100);
    bool iscocatenation = true;
    for (j = 0; j < n_words; ++j) {
      char curr[wordsize + 1];
      strncpy(curr, (sentence + i + j * wordsize), wordsize);
      curr[wordsize] = '\0';
      DataNodeStringKeyIntValT* match = HashTable_FindMatch(&word2freqneeded, curr);
      if (match) { // curr is a search word
        DataNodeStringKeyIntValT* found = HashTable_FindMatch(&word2freqfound,
              curr);
        HashTable_Insert(&word2freqfound, curr, (found ? found->val + 1 : 1));
        if (HashTable_FindMatch(&word2freqfound, curr)->val > match->val) {
          iscocatenation = false;
          break;
        }
      } else {
        iscocatenation = false;
        break;
      }     
    }
    if (iscocatenation) {
      ++n_results;
      substrings_i0 = realloc(substrings_i0, (n_results + 1) * sizeof(int));      
      substrings_i0[0] = n_results + 1;
      substrings_i0[n_results] = i;
    }
    HashTable_Destroy(&word2freqfound);
  }
  HashTable_Destroy(&word2freqneeded);  
  return substrings_i0;
}

/**
 * Collatz conjecture:
 * 
 * every number that is repeatedly: 
 *  if even - divided by 2
 *  if odd - tripled and then +1
 * ends up at 1.
 * 
 * Verify that for all numbers smaller than a given n. Of course, we do not expect
 * to falsify the conjecture (because nobody ever did that) but a fail
 * could theoretically occur as two different cases:
 * 
 *  - either we reach back to a number already visited in the current sequence
 *    (this would mean an infinite loop)
 *  - we get in a loop that is unbound
 * 
 * Since we cannot follow an unbound sequence, we can only possibly detect the first
 * of the two failures, by tracking all numbers encountered in the current sequence
 * in a hash-table and cross-checking against them
 *
 * We use the following ideas for an efficient implementation
 * 
 *  - optimisation 0: 
 *    only perform the test for odd numbers. the idea is that any even number
 *    will be immediately halved and the resulting number is already checked
 *    (this can be proved by induction, e.g. 4 is not needed to be checked
 *     because 2 was already checked, 6 not needed because three was checked,
 *     8 not needed because 4 was checked, 10 not needed because 5 was checked, ..)
 * 
 *  - optimisation 1:    
 *    exploit the fact that if we check a number  k < m < n , we
 *    know that all numbers <= k satisfy the conjecture; so whenever
 *    we reach number below the limit of those already verified, 
 *    we can stop the current test
 * 
 *  - optimisation 2:
 *    track all numbers ever encountered - since we also track the numbers
 *    encountered in the same sequence and use that to make sure we do not
 *    get to the same number twice within the same sequence, we always know
 *    that finding a match in the current check means that we were
 *    at this number in some previous round (but not in the same sequence).
 *    thus, we know that from this number no failure was detected, and 
 *    we can stop to follow the sequence and continue with the next number.
 *    At first sight, one may think that these could be tracked in a vector,
 *    but actually this is not possible: during the sequences
 *    we have no bound on the numbers, so we don't know how far we will
 *    reach.
 *     
 *  - use 64 bit, i.e. ull, to not run into overflow to early
 *    -> datatype limit for unsigned long long  ~ pow(10, 18)
 * 
 * 
 * @param n
 * @return 
 */
bool HashTable_TestCollatzUpToGivenNumber(const ull n) {
  if (n > 2 * (int)pow(10, 6)) {
    printf("Error: we test collatz conjecture with O(n) memory. n = %llu too large. \n",
            n);
    return false;
  }
  HashtableT verified = {0};
  HashTable_Init(&verified, HashFunction_String2Int, pow(10, 4));
  ull i;
  for (i = 3; i <= n; i += 2) {
    HashtableT seen_this_sequence = {0};
    HashTable_Init(&seen_this_sequence, HashFunction_String2Int, pow(10, 4));
    ull processed_i = i;
    while (1) {      
      char num_as_string[24];      
      sprintf(num_as_string, "%llu", processed_i);
      // check if the current num was already verified
      if (HashTable_FindMatch(&verified, num_as_string)) { // already verified
        HashTable_Destroy(&seen_this_sequence);
        break; // continue with next test
      } else {
        HashTable_Insert(&verified, num_as_string, -42);
      }
      // check if the current num was already seen this sequence
      if (HashTable_FindMatch(&seen_this_sequence, num_as_string)) { 
        // failure: never expect to reach here  
        printf("We have reached an infinite loop. Collatz conjecture is wrong.\n");        
        HashTable_Destroy(&seen_this_sequence);
        return false;
      } else { // note current num in sequence and continue with next        
        HashTable_Insert(&seen_this_sequence, num_as_string, -42);        
        if (processed_i % 2) {
          ull tentative_next = processed_i * 3 + 1;
          if (tentative_next < processed_i) { // can only happen due to overflow
            printf("Overflow error. Aborting at test for %llu.\n", processed_i);            
            HashTable_Destroy(&seen_this_sequence);
            return false;
          } else {
            processed_i = tentative_next;
          }
        } else {
          processed_i /= 2;
        }
        if (processed_i < i) {
          HashTable_Destroy(&seen_this_sequence);
          break;
        }
      }      
    }
  }
  HashTable_Destroy(&verified);
  return true; // if we reach here, we did not find a failure for all k <= n
}

/**
 * 
 * @param board
 * @param max_hash
 * @return 
 */
unsigned int HashTable_ChessHashFunction(unsigned int* board, int max_hash) {
  unsigned int hash_code = 0b0u;
  int kMult = 53;
  int i, j;
  // traverse board in decrementing ID manner, so that fieldID matches power of
  // figure at that field
  for (i = 7; i >= 0; --i) { 
    for (j = 7; j >= 0; --j) {      
      unsigned int field_state = board[i] & (0b1111u << (7 - j) * 4);
      int figure_id = field_state >> (7 - j) * 4;
      hash_code = ((hash_code * kMult) % max_hash + figure_id % max_hash) % max_hash;
    }
  }  
  return hash_code;
}
/**
 *     0 1 2 3 4 5 6 7
 * 
 *  7  R N B Q K B N R       black          56 57                63
 *  6  p p p p p p p p                      48 ...               55
 *  5  x x x x x x x x                      40 41 42             47
 *  4  x x x x x x x x                  ->  32 ...               39
 *  3  x x x x x x x x                      24 ...               31
 *  2  x x x x x x x x                      16 17 18 ..          23
 *  1  p p p p p p p p                       8  9 10 11 12 13 14 15
 *  0  R N B Q K B N R       white           0  1  2  3  4  5  6  7 
 * 
 * 
 * Note: modulo is not distributive (a + b) % h != (a % h) + (b % h)
 * 
 *      --> this implies:   (c * (k *... * k)) % h != (c % h * ((k % h) * (k % h) * ... )) % h
 * 
 * @param board
 * @param max_hash
 * @param old_hash
 * @param move
 * @return 
 */
unsigned int HashTable_ChessHashFunctionUpdate(unsigned int* board, 
        unsigned int max_hash, unsigned int old_hash, ChessMoveT move) {  
  int kMult = 53;
  int ID_old = move.old_row * 8 + move.old_col;
  int ID_new = move.new_row * 8 + move.new_col;
  unsigned int contribution_old_field = move.old_figureID;
  unsigned int contribution_new_field = move.new_figureID;
  while (ID_old--) {
    contribution_old_field = (contribution_old_field * kMult) % max_hash;    
  }
  while (ID_new--) {
    contribution_new_field = (contribution_new_field * kMult) % max_hash;
  }
  // avoid getting negative values because C treats mod as remainder
  // e.g.  -4 % 9  = -4, instead of 5 as one might expect (9-4) % 9 = 5
  if (contribution_old_field > old_hash) {
    old_hash += max_hash;
  }
  return ((old_hash - contribution_old_field) % max_hash +
          contribution_new_field % max_hash) % max_hash;
}


/**
 *     a b c d e f g h
 * 
 *  7  R N B Q K B N R       black
 *  6  p p p p p p p p
 *  5  x x x x x x x x
 *  4  x x x x x x x x
 *  3  x x x x x x x x
 *  2  x x x x x x x x
 *  1  p p p p p p p p
 *  0  R N B Q K B N R       white
 * 
 * @param board
 */
void HashTable_ChessInitialState(unsigned int* board) {
  int i, j;
  for (i = 0; i < 8; ++i) {board[i] = 0u;}  
  board[0] |= (0b0010u << 7 * 4) ; // bottom row: white heavy
  board[0] |= (0b0011u << 6 * 4) ;
  board[0] |= (0b0100u << 5 * 4) ;
  board[0] |= (0b0101u << 4 * 4) ;
  board[0] |= (0b0110u << 3 * 4) ;
  board[0] |= (0b0100u << 2 * 4) ;
  board[0] |= (0b0011u << 1 * 4) ;
  board[0] |= (0b0010u << 0 * 4) ;
  board[1] |= (0b0001u << 7 * 4) ; // white pawns
  board[1] |= (0b0001u << 6 * 4) ;
  board[1] |= (0b0001u << 5 * 4) ;
  board[1] |= (0b0001u << 4 * 4) ;
  board[1] |= (0b0001u << 3 * 4) ;
  board[1] |= (0b0001u << 2 * 4) ;
  board[1] |= (0b0001u << 1 * 4) ;
  board[1] |= (0b0001u << 0 * 4) ;
  board[6] |= (0b0111u << 7 * 4) ; // black pawns
  board[6] |= (0b0111u << 6 * 4) ;
  board[6] |= (0b0111u << 5 * 4) ;
  board[6] |= (0b0111u << 4 * 4) ;
  board[6] |= (0b0111u << 3 * 4) ;
  board[6] |= (0b0111u << 2 * 4) ;
  board[6] |= (0b0111u << 1 * 4) ;
  board[6] |= (0b0111u << 0 * 4) ;
  board[7] |= (0b1000u << 7 * 4) ; // top row: black heavy figures
  board[7] |= (0b1001u << 6 * 4) ;
  board[7] |= (0b1011u << 5 * 4) ;
  board[7] |= (0b1100u << 4 * 4) ;
  board[7] |= (0b1101u << 3 * 4) ;
  board[7] |= (0b1011u << 2 * 4) ;
  board[7] |= (0b1001u << 1 * 4) ;
  board[7] |= (0b1000u << 0 * 4) ;
  return;
}

void HashTable_ChessUpdateState(unsigned int* board, ChessMoveT move) {
  unsigned int kMaskEraseBitsOldField = ~(0x000Fu << ((7 - move.old_col) * 4));
  board[move.old_row] &= kMaskEraseBitsOldField;
  unsigned int kMaskEraseBitsNewField = ~(0x000Fu << ((7 - move.new_col) * 4));
  unsigned int kMaskSetBitsNewField = move.new_figureID << ((7 - move.new_col) * 4);
  board[move.new_row] &= kMaskEraseBitsNewField;
  board[move.new_row] |= kMaskSetBitsNewField;
  return;
}

void HashTable_ChessPrintBoard(unsigned int* board) {
  int i, j;
  for (i = 7; i >= 0; --i) {
    for (j = 0; j < 8; ++j) {
      unsigned int field = (board[i] & (0b1111u << (7 - j) * 4)) >> (7 - j) * 4;
      if        (field == 0b0000u) {
        printf(" -");
      } else if (field == 0b0001u) {
        printf("wp");
      } else if (field == 0b0010u) {
        printf("wR");
      } else if (field == 0b0011u) {
        printf("wN");
      } else if (field == 0b0100u) {
        printf("wB");
      } else if (field == 0b0101u) {
        printf("wQ");
      } else if (field == 0b0110u) {
        printf("wK");
      } else if (field == 0b0111u) {
        printf("bp");
      } else if (field == 0b1000u) {
        printf("bR");
      } else if (field == 0b1001u) {
        printf("bN");
      } else if (field == 0b1011u) {
        printf("bB");
      } else if (field == 0b1100u) {
        printf("bQ");
      } else if (field == 0b1101u) {
        printf("bK");
      } else {
        printf("?");
      }
      printf(" ");
    }
    printf("\n");
  }
  printf("\n\n");
}