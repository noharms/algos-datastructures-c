/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "hashtable.h"
#include "hashtable_multi.h"

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


void MainHashTableMulti(char* path_to_exe) {  
  printf("\n\n----------------------- MainHashTableMulti \n");
  
  //-----------------------------------------
  // preparations:
  
  //-----------------------------------------
  // Exercises  
  
  MainHashTableMulti_API();
  
  return;
}



//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void MainHashTableMulti_API() {
  printf("\n----------------------------------- MainHashTableMulti_API \n");
  
  // start a hashtable
  HashtableT myht;
  const int kMaxHash = 1; // to debug with collisions, use 1
  HashTableMulti_Init(&myht, HashFunction_String2Int, kMaxHash); 
  
  // add some data
  char* key1 = "Enno";
  char* key2 = "Elli";
  char* key3 = "Felix";
  HashTableMulti_Insert(&myht, key1, 32);
  HashTableMulti_Insert(&myht, key2, 29);
  HashTableMulti_Insert(&myht, key3, 30);
  HashTableMulti_Insert(&myht, key1, 15);
  
  // check some values
  printf("Key %s has value %i \n", key1, HashTableMulti_FindMatch(&myht, key1)->val);
  printf("Key %s has value %i \n", key2, HashTableMulti_FindMatch(&myht, key2)->val);
  printf("Key %s has value %i \n", key3, HashTableMulti_FindMatch(&myht, key3)->val);
  
  // check if things work after a resize
  HashTableMulti_Resize(&myht);
  
  HashTableMulti_Insert(&myht, key2, 11);
  HashTableMulti_Insert(&myht, key3, 14);
  HashTableMulti_Insert(&myht, key1, 15);
  
  // Erase some keys that have multiple
  printf("Check that erase removes all elements with key. \n");
  printf("Before erase: %i elems in table.\n", myht.n_elems);
  HashTableMulti_Erase(&myht, key1);
  printf("After erase of key %s: %i elems in table.\n", key1, myht.n_elems);
  
  HashTableMulti_Destroy(&myht);
  return;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//-------------------------------------------------------------- API
    
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
void HashTableMulti_Insert(HashtableT* ht, char* key, int val) {
  int i_bucket = ht->hash_function(key, ht->max_hash);
  LinkedlistStringKeyT* bucket = &(ht->buffer[i_bucket]);  
  LinkedListStringKey_PushFront(bucket, key, val);
  ++(ht->n_elems);
  return;
}

void HashTableMulti_Insert_CopyDataNode(HashtableT* ht, DataNodeStringKeyIntValT* keyval) {
  int i_bucket = ht->hash_function(keyval->key, ht->max_hash);
  LinkedlistStringKeyT* bucket = &(ht->buffer[i_bucket]);
  LinkedListStringKey_PushFront(bucket, keyval->key, keyval->val);
  ++(ht->n_elems);
  return;
}



/**
 * Erases ALL elements with the key
 *  
 * @param hashtable
 * @param key
 * @return 
 */
void HashTableMulti_Erase(HashtableT* ht, char* key) {
  int i_bucket = ht->hash_function(key, ht->max_hash);
  LinkedlistStringKeyT* bucket = &(ht->buffer[i_bucket]);
  while (HashTableMulti_FindMatch(ht, key)) { // loop until all are erased
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
DataNodeStringKeyIntValT* HashTableMulti_FindMatch(HashtableT* ht, char* key) {
  int i_bucket = ht->hash_function(key, ht->max_hash);
  LinkedlistStringKeyT* bucket = &(ht->buffer[i_bucket]);
  return &(LinkedListStringKey_FindMatch(bucket, key)->data);  
}

void HashTableMulti_Init(HashtableT* ht, int (*hashfunc)(char*, const int), int max_hash) {    
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

void HashTableMulti_Destroy(HashtableT* ht) {
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


 void HashTableMulti_Resize(HashtableT* ht) {
  HashtableT new_ht;
  HashTableMulti_Init(&new_ht, ht->hash_function, 2 * ht->max_hash);
  int i;
  for (i = 0; i < ht->max_hash; ++i) { // re-insert all elems from all buckets
    LinkedlistStringKeyT* bucket = &(ht->buffer[i]);        
    ListNodeStringKeyIntValT* curr = bucket->head;
    while (curr) {      
      HashTableMulti_Insert(&new_ht, curr->data.key, curr->data.val);
      curr = curr->next;
    }
  }  
  HashTableMulti_Destroy(ht);
  *ht = new_ht;
  return;
}
 
 
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//-------------------------------------------------------------- Algos