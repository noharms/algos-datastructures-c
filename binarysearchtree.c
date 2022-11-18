/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * NOTE: the terms smaller and larger are very misleading when it 
 *       comes to discussing BSTs.
 * 
 *       --> we define them in the following way here:
 * 
 *       smaller: node A is smaller than node B if with respect to a 
 *                given ordering A comes before B 
 *                (if in a sorted array of all nodes A is before B)
 *                (if A appears before B in an in-order-traversal)
 * 
 *       larger: node A is smaller than node B if with respect to a 
 *               given ordering A comes after B 
 * 
 */


#include "binarysearchtree.h"

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <string.h>
#include <math.h>

#include "arrays.h"
#include "binarytree_as_nodes.h"
#include "sorting.h"
#include "utils.h"
#include "hashtable.h"


void MainBST() {
  printf("\n\n----------------------- MainBST \n");
    
  //-----------------------------------------
  // preparations:    
  srand(time(NULL));
  
  printf("-- For the BST exercises we use two test BSTs\n");
  printf("-- in order to be able to reproduce the results:\n");
  printf("-- one with random numbers, \n");
  printf("-- and another one with fixed given numbers \n");  
  printf("-- Note: in many cases it makes sense to re-run the code several times to test\n");
  printf("--       that a certain exercise works for different random tree configurations.   \n");  
  printf("\n\n");
    
  int keys[] = {12,10,15,12,16,13,17,12,31};
  int n = sizeof(keys) / sizeof(int); 
  printf("Array with fixed test numbers: \n");  
  PrintArray1d(keys, n);
  printf("\n");
  
  // the following tree should come into existence for 
  // nodes1-9: 12, 15, 12, 16, 13, 17, 12, 31
  //
  //                     12
  //             10               15
  //           x    12         12      16
  //          x x  x  x      x   13   x  17
  //         xx xx xx xx    xx   xx  xx  x 31
  
  int keys_distinct[] = {19,7,43,3,11,23,47,2,5,17,37,53,13,29,41,31};
  int n_distinct = sizeof(keys_distinct) / sizeof(int);
  //Array_FillWithDistinctRandomNumbers(MAX_RAND_NUM, n_distinct, keys_distinct);  
  printf("Array with random numbers: \n");  
  PrintArray1d(keys_distinct, n_distinct);    
  printf("\n");
  
  //-----------------------------------------
  // API tests  
  
  MainBST_InOrderTraversal(keys, n);
  
  MainBST_SearchMinMax(keys, n);
  
  MainBST_SearchKey(keys, n);
  
  MainBST_SearchParentOfKey(keys, n);
  
  MainBST_InOrderPredecessor(keys, n);
  
  MainBST_InOrderSuccessor(keys, n);      
  
  MainBST_DeleteNode(keys, n);        
  
  //----------------------------------------
  // Exercises     
      
  MainBST_CheckIfBTisBST(keys, n);
  
  MainBST_NextGreaterNode(keys, n);
    
  MainBST_KGreatestKeys(keys, n);
  
  MainBST_LCADistinctKeys(keys_distinct, n_distinct);
  
  MainBST_BuildBSTDistinctKeysPreorderData(keys_distinct, n_distinct);
  
  MainBST_ShortestSetContainingValueFromKArrays();
  
  MainBST_KSmallestAplusBSqrt2Numbers();

  MainBST_ConstructHeightBalancedBSTFromSortedArray(keys, n);
  
  MainBST_IsMiddleNodeInLineWithPairDistinctKeys(keys_distinct, n_distinct);
  
  MainBST_FindKeysInRange(keys, n);
  
/*  
  MainBST_MergeBSTs(keys, ARR_LEN, keys_random, ARR_LEN);
*/
  return;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


void MainBST_InOrderTraversal(int* keys, int n) {
  printf("\n----------------------------------- MainBST_InOrderTraversal \n");  
  
  int i;
  BSTType myBST = {0};
  BST_Init(&myBST, BinaryTree_CompFunNodePtr_Ascending);  
  for (i = 0; i < n; ++i) {
    BST_InsertKeyVal(&myBST, keys[i], -42);
  }  
  printf("BST reads in preorder: \n");
  BST_PrintTreePreOrder(&myBST);
  
  // traversal: counting number of nodes
  printf("\n");
  printf("Traversing the BST in-order to find number of nodes\n");
  int n_nodes_found = BST_InOrderTraversal(&myBST);
  printf("-> The traversal visited %i nodes. \n\n", n_nodes_found);
  
  // traversal: output visited nodes in order
  BTNodeT* nodeptrs_inorder[n_nodes_found];
  BST_NodesToArrayInOrder(&myBST, nodeptrs_inorder);
  printf("\nFound array is ordered like: \n");
  for (i = 0; i < n_nodes_found; ++i) {
    printf("nodeptrs_inorder[%i] has key = %i \n", i, nodeptrs_inorder[i]->key);
  }
  printf("\n");
  
  // free BST
  BST_Destroy(&myBST);
  return;
}


void MainBST_SearchMinMax(int* keys, int n) {  
  printf("\n----------------------------------- MainBST_SearchMinMax \n");
  
  int i;
  BSTType myBST = { 0 };
  BST_Init(&myBST, BinaryTree_CompFunNodePtr_Ascending);  
  for (i = 0; i < n; ++i) {
    BST_InsertKeyVal(&myBST, keys[i], -42);
  } 
  
  printf("BST reads in preorder: \n");
  BST_PrintTreePreOrder(&myBST);
  
  // Searching for the max 
  BTNodeT* max_ptr = BST_LastNode(myBST.root);
  if (max_ptr) {
    printf("The max node in the tree has data %i. \n", max_ptr->key);
  } else {
    printf("ERROR: Did not find max node. \n");
  }
  
  // Searching for the min   
  BTNodeT* min_ptr = BST_FirstNode(myBST.root);
  if (min_ptr) {
    printf("The min node in the tree has data %i. \n", min_ptr->key);
  } else {
    printf("ERROR: Did not find min node. \n");
  }
  
  // free BST
  BST_Destroy(&myBST); 
  return;
}

void MainBST_SearchKey(int* keys, int n) {  
  printf("\n----------------------------------- MainBST_SearchKey \n");  
    
  int i;
  BSTType myBST = { 0 };
  BST_Init(&myBST, BinaryTree_CompFunNodePtr_Ascending);  
  for (i = 0; i < n; ++i) {
    BST_InsertKeyVal(&myBST, keys[i], -42);
  } 
  
  printf("BST reads in preorder: \n");
  BST_PrintTreePreOrder(&myBST);
  
  // Searching for a node with a given key
  int target = keys[n - 1];
  BTNodeT* targetnode_ptr = BST_FindKey(&myBST, target);
  if (targetnode_ptr) {
    printf("Found the node with key %i in the BST. \n", targetnode_ptr->key);
  }
  
  // Searching for a node that is not in the tree  
  int target_non_existent = -10;
  targetnode_ptr = BST_FindKey(&myBST, target_non_existent);  
  if (targetnode_ptr) {
    printf("ERROR: Found the node with key %i in the BST. \n", targetnode_ptr->key);
  }
  
  // free BST
  BST_Destroy(&myBST);
  return;
}


void MainBST_SearchParentOfKey(int* keys, int n) {  
  printf("\n----------------------------------- MainBST_SearchParentOfKey \n");  
    
  int i;
  BSTType myBST = { 0 };
  BST_Init(&myBST, BinaryTree_CompFunNodePtr_Ascending);  
  for (i = 0; i < n; ++i) {
    BST_InsertKeyVal(&myBST, keys[i], -42);
  } 
  
  printf("BST reads in preorder: \n");
  BST_PrintTreePreOrder(&myBST);
  
  // Searching for the parent of a given key
  BTNodeT* target = BST_FindKey(&myBST, keys[n - 1]);
  BTNodeT* target_parent = BST_FindParentOfNode(&myBST, target);          
  if (target_parent) {
    printf("For key %i found parent %i \n", target->key, target_parent->key);
  } else {
    printf("For key %i did not find a parent.\n", target->key);
  }
   
  // free BST
  BST_Destroy(&myBST);
  return; 
}

void MainBST_InOrderPredecessor(int* keys, int n) {
  printf("\n----------------------------------- MainBST_InOrderPredecessor \n");  
  
  int i;
  BSTType myBST = { 0 };
  BST_Init(&myBST, BinaryTree_CompFunNodePtr_Ascending);  
  for (i = 0; i < n; ++i) {
    BST_InsertKeyVal(&myBST, keys[i], -42);
  }
  
  printf("BST reads in preorder: \n");
  BST_PrintTreePreOrder(&myBST);
  
  // closest anecstor after which path went right
  BTNodeT* target = BST_FindKey(&myBST, keys[n - 1]);
  BTNodeT* ancestor_afterwhichpathwentright =
          BST_ClosestAncestorAfterWhichPathWentRight(&myBST, myBST.root, target,
          NULL);
  if (ancestor_afterwhichpathwentright) {    
    printf("For key %i the closest ancestor after which path went right is %i .\n",
            target->key, ancestor_afterwhichpathwentright->key);
  } else {      
    printf("For key %i the path from root goes always left.\n", target->key);
  }
  
  // find inorder predecessor
  BTNodeT* predecessor = BST_Predecessor(&myBST, target);
  if (predecessor) {
    printf("For key %i found predecessor is %i \n", target->key, predecessor->key);
  } else {
    printf("No predecessor found in tree for key %i\n", target->key);    
  }
  printf("\n");

  // find inorder predecessor - keys distinct  
  printf("Checking algo that works on distinct keys. \n");
  predecessor = BST_PredecessorDistinctKeys(&myBST, target);
  if (predecessor) {
    printf("For key %i found predecessor is %i \n", target->key, predecessor->key);
  } else {
    printf("No predecessor found in tree for key %i\n", target->key);    
  }
    
  // free BST
  BST_Destroy(&myBST);
  return;
}

void MainBST_InOrderSuccessor(int* keys, int n) {
  printf("\n----------------------------------- MainBST_InOrderSuccessor \n");  
  
  int i;
  BSTType myBST = { 0 };
  BST_Init(&myBST, BinaryTree_CompFunNodePtr_Ascending);  
  for (i = 0; i < n; ++i) {
    BST_InsertKeyVal(&myBST, keys[i], -42);
  }
  
  printf("BST reads in preorder: \n");
  BST_PrintTreePreOrder(&myBST);
  
  // closest anecstor after which path went left
  BTNodeT* target = BST_FindKey(&myBST, keys[n - 1]);
  BTNodeT* ancestor_afterwhichpathwentleft = 
          BST_ClosestAncestorAfterWhichPathWentLeft(&myBST, myBST.root, target,
          NULL);
  if (ancestor_afterwhichpathwentleft) {
    printf("For key %i the closest ancestor after which path went right is %i .\n",
            target->key, ancestor_afterwhichpathwentleft->key);
  } else {
    printf("For key %i the path from root goes always left.\n", target->key);
  }    
  
  // find inorder successor
  BTNodeT* successor = BST_Successor(&myBST, target);
  if (successor) {
    printf("For key %i found successor is %i \n", target->key, successor->key);
  } else {
    printf("No successor found in tree for key %i\n", target->key);
  }
  printf("\n");

  // find inorder successor - keys distinct  
  printf("Checking algo that works on distinct keys. \n");
  successor = BST_SuccessorDistinctKeys(&myBST, target);
  if (successor) {
    printf("For key %i found successor is %i \n", target->key, successor->key);
  } else {
    printf("No successor found in tree for key %i\n", target->key);
  }
  
  // free BST
  BST_Destroy(&myBST);  
  return;
}


void MainBST_DeleteNode(int* keys, int n) {
  printf("\n----------------------------------- MainBST_DeleteNode \n");  
  
  int i;
  BSTType myBST = {0};
  BST_Init(&myBST, BinaryTree_CompFunNodePtr_Ascending);  
  for (i = 0; i < n; ++i) {
    BST_InsertKeyVal(&myBST, keys[i], -42);
  }
  
  // print tree
  printf("BST reads in preorder (before deletion): \n");
  BST_PrintTreePreOrder(&myBST);
  
  // delete node with key
  int key_to_delete = keys[n - 4];
  BTNodeT* target = BST_FindKey(&myBST, key_to_delete);  
  bool found_and_deleted = BST_EraseNode(&myBST, target);
  if(found_and_deleted) {
    printf("Node with key %i was deleted.\n", key_to_delete);  
  }
  
  // print tree
  printf("BST reads in preorder (after deletion): \n");
  BST_PrintTreePreOrder(&myBST);
    
  // free BST
  BST_Destroy(&myBST);  
  return;
}

void MainBST_MergeBSTs(int* keys, int n, int* keys_random, int m) {
  printf("\n----------------------------------- MainBST_MergeBSTs \n");  
  
  int i;
  BSTType myBST = {0};
  BST_Init(&myBST, BinaryTree_CompFunNodePtr_Ascending);  
  for (i = 0; i < n; ++i) {
    BST_InsertKeyVal(&myBST, keys[i], -42);
  }
  BSTType myBST_random = {0};
  BST_Init(&myBST_random, BinaryTree_CompFunNodePtr_Ascending);  
  for (i = 0; i < m; ++i) {
    BST_InsertKeyVal(&myBST_random, keys_random[i], -42);
  }
  
  // print trees
  printf("BST 1 reads in preorder: \n");
  BST_PrintTreePreOrder(&myBST);
  printf("\n");
  printf("BST 2 reads in preorder: \n");
  BST_PrintTreePreOrder(&myBST_random);
  printf("\n");
  
  // Merge two trees into one
  BSTType merged_tree = BST_MergeTrees(&myBST, &myBST_random);
    
  // print trees
  printf("BST 1 reads in preorder: \n");
  BST_PrintTreePreOrder(&myBST);
  printf("\n");
  printf("BST 2 reads in preorder: \n");
  BST_PrintTreePreOrder(&myBST_random);
  printf("\n");
  printf("merged BST: \n");
  BST_PrintTreeInOrder(&merged_tree);
  printf("\n");
  
  
  // free BST
  BST_Destroy(&myBST);  
  BST_Destroy(&myBST_random);
  BST_Destroy(&merged_tree);
  return;
}


void MainBST_CheckIfBTisBST(int* keys, int n) {
  printf("\n----------------------------------- MainBST_CheckIfBTisBST \n");  
  
  int i;
  BSTType myBST = {0};
  BST_Init(&myBST, BinaryTree_CompFunNodePtr_Ascending);  
  for (i = 0; i < n; ++i) {
    BST_InsertKeyVal(&myBST, keys[i], -42);
  }
  
  printf("BST reads in preorder: \n");
  BST_PrintTreePreOrder(&myBST);
    
  // check tree
  bool isBST = BST_CheckIfBTisBST(&myBST);
  printf("The tested BT is %sa BST \n\n", (isBST ? "" : "not "));
    
  // Violate the BST !
  BTNodeT* extra_node = calloc(1, sizeof(BTNodeT));
  extra_node->key = 22;
  extra_node->left = NULL;
  extra_node->rght = NULL;
  BTNodeT* insert_at = BST_FindKey(&myBST, 16);
  insert_at->left = extra_node;  
  ++(myBST.n_nodes);
  // result:
  //                     12
  //             10               15
  //           x    12         12        16(=node5)
  //          x x  x  x       x 13    extra  17
  
  printf("BST reads in preorder: \n");
  BST_PrintTreePreOrder(&myBST);
  
  // Check again: now expecting failure
  printf("After manipulation that violates the BST:\n");
  isBST = BST_CheckIfBTisBST(&myBST);  
  printf("The tested BT is %sa BST \n", (isBST ? "" : "not "));
    
  // free BST
  BST_Destroy(&myBST);  
  return;
}

void MainBST_NextGreaterNode(int* keys, int n) {
  printf("\n----------------------------------- MainBST_NextGreaterNode \n");  

  int i;
  BSTType myBST = {0};
  BST_Init(&myBST, BinaryTree_CompFunNodePtr_Ascending);  
  for (i = 0; i < n; ++i) {
    BST_InsertKeyVal(&myBST, keys[i], -42);
  }
  // print tree
  printf("BST reads in preorder: \n");
  BST_PrintTreePreOrder(&myBST);
    
  // find next greater node: test1
  int reference = keys[n - 2];
  BTNodeT* next_greater = BST_NextGreaterNode(&myBST, reference);
  printf("Next greater node than key %i has key %i \n", reference, 
          (next_greater ? next_greater->key : -1));
  // find next greater node: test2
  reference = 31;
  next_greater = BST_NextGreaterNode(&myBST, reference);
  printf("Next greater node than key %i has key %i \n", reference, 
          (next_greater ? next_greater->key : -1));
  
  // free BST
  BST_Destroy(&myBST);  
  return;
}

void MainBST_KGreatestKeys(int* keys, int n) {  
  printf("\n----------------------------------- MainBST_KGreatestKeys \n");  

  int i;
  BSTType myBST = {0};
  BST_Init(&myBST, BinaryTree_CompFunNodePtr_Ascending);  
  for (i = 0; i < n; ++i) {
    BST_InsertKeyVal(&myBST, keys[i], -42);
  }
  // print tree
  printf("BST reads in preorder: \n");
  BST_PrintTreePreOrder(&myBST);
  
  // find k greates keys
  int k = 6;
  int greatest_keys[k];
  BST_FindKGreatestKeys(&myBST, greatest_keys, k);
  
  // print result
  printf("The BST's %d greatest keys are: \n", k);  
  for (i = 0; i < k; ++i) {
    printf("key = %d \n", greatest_keys[i]);
  }
  printf("\n");
  
  // free BST
  BST_Destroy(&myBST);  
  return;
}


void MainBST_LCADistinctKeys(int* keys, int n) {
  printf("\n----------------------------------- MainBST_LCADistinctKeys \n");  
  
  int i;
  BSTType myBST = {0};
  BST_Init(&myBST, BinaryTree_CompFunNodePtr_Ascending);  
  for (i = 0; i < n; ++i) {
    BST_InsertKeyVal(&myBST, keys[i], -42);
  }
  
  // print tree
  printf("BST reads in preorder: \n");
  BST_PrintTreePreOrder(&myBST);
  
  // find LCA     
  int key1 =  keys[n - 5];
  int key2 =  keys[n - 3];
  BTNodeT* LCA = BST_FindLCADistinctKeys(myBST.root, key1, key2);
  if (LCA) {    
    printf("LCA(%i,%i) = %i \n", key1, key2, LCA->key);
  }
  
  // free BST
  BST_Destroy(&myBST);  
  return;
}

void MainBST_BuildBSTDistinctKeysPreorderData(int* keys, int n) {
  printf("\n----------------------------------- MainBST_BuildBSTDistinctKeysPreorderData \n");  
  
  int i;
  BSTType myBST = {0};
  BST_Init(&myBST, BinaryTree_CompFunNodePtr_Ascending);  
  for (i = 0; i < n; ++i) {
    BST_InsertKeyVal(&myBST, keys[i], -42);
  }
  
  // print tree
  printf("Original BST in preorder: \n");
  BST_PrintTreePreOrder(&myBST);
 
  // store traversal data
  BTNodeT* preorder_data[n];
  BST_NodesToArrayPreOrder(&myBST, preorder_data);
  printf("Array of nodes in preorder reads: \n");
  for (i = 0; i < n; ++i) {
    printf("%d \n", preorder_data[i]->key);
  }
  printf("\n");          
  
  // reconstruct a binary tree from it
  BSTType BSTfromtraversal = BST_FromPreorder(preorder_data, n);
  
  // print tree
  printf("Constructed from traversal data: \n");
  BST_PrintTreePreOrder(&BSTfromtraversal);
  
  // free BST
  BST_Destroy(&myBST);  
  BST_Destroy(&BSTfromtraversal);  
  return;
}

void MainBST_ShortestSetContainingValueFromKArrays() {
  printf("\n----------------------------------- MainBST_ShortestSetContainingValueFromKArrays \n");  
  
  int i, j, k = 4, n = 6;
  int **arrays = calloc(k, sizeof(int*));
  for (i = 0; i < k; ++i) {
    arrays[i] = calloc(n, sizeof(int));
    for (j = 0; j < n; ++j) {
      Array_FillWithRandomNumbers(10, n, arrays[i]);
    }
    qsort(arrays[i], n, sizeof(int), CompFunIntptr_Ascending);
    printf("Array %d: \n", i);  
    PrintArray1d(arrays[i], n);
    printf("\n");
  }
  printf("\n");
  
  // compute shortest interval
  int* elems_shortest_interval = BST_ShortestSetContainingValueFromKSortedArrays(arrays,
          k, n);
  
  // print result
  printf("We found that the shortest-interval set contains the elements:\n");
  PrintArray1d(elems_shortest_interval, k);  
  
  // free
  for (i = 0; i < k; ++i) {
    free(arrays[i]);
  }
  free(arrays);
  free(elems_shortest_interval);
  return;
}

void MainBST_KSmallestAplusBSqrt2Numbers() {
  printf("\n----------------------------------- MainBST_KSmallestAplusBSqrt2Numbers \n");
  int k = 15;
  double *ksmallest = KSmallestAplusBSqrt2Numbers(k);
  printf("The %d smallest numbers of the form: a + b sqrt(2) \n", k);
  printf("where a and b are nonnegative integers are the following: \n");
  int i;
  for (i = 0; i < k; ++i) {printf("%.4f \n", ksmallest[i]);}
  // free
  free(ksmallest);
  return;
}

void MainBST_ConstructHeightBalancedBSTFromSortedArray(int* keys, int n) {    
  printf("\n----------------------------------- MainBST_ConstructHeightBalancedBSTFromSortedArray \n");     
  
  int *sorted_keys = calloc(n, sizeof(int));
  memcpy(sorted_keys, keys, n * sizeof(int));
  qsort(sorted_keys, n, sizeof(int), CompFunIntptr_Ascending);
  
  // print keys
  printf("Building a height balanced tree from keys: \n");
  PrintArray1d(sorted_keys, n);  
  
  // build tree
  BSTType myBST = BST_HeightBalancedBSTFromSortedKeys(sorted_keys, n);
  
  // print tree    
  printf("Height balanced BST built from sorted arr reads preorder: \n");
  BST_PrintTreePreOrder(&myBST);
    
  // free BST
  BST_Destroy(&myBST);
  free(sorted_keys);
  return;
}

void MainBST_IsMiddleNodeInLineWithPairDistinctKeys(int* keys, int n) {    
  printf("\n----------------------------------- MainBST_IsMiddleNodeInLineWithPairDistinctKeys \n");     

  int i;
  BSTType myBST = {0};
  BST_Init(&myBST, BinaryTree_CompFunNodePtr_Ascending);  
  for (i = 0; i < n; ++i) {
    BST_InsertKeyVal(&myBST, keys[i], -42);
  }
  
  // print tree
  printf("BST reads in preorder: \n");
  BST_PrintTreePreOrder(&myBST);
  
  // check nodes
  int key1 = keys[0]; // 19
  int key2 = keys[6]; // 47
  int key_tocheck = keys[2]; // 43
  BTNodeT* node1 = BST_FindKey(&myBST, key1);
  BTNodeT* node2 = BST_FindKey(&myBST, key2);
  BTNodeT* tocheck = BST_FindKey(&myBST, key_tocheck);
  
  bool tocheck_isinmiddle = BST_IsTobecheckedInLineOfPair(&myBST, node1, node2,
          tocheck);
  printf("Checking whether %d is on connection path, if existing, between %d and %d \n",
          tocheck->key, node1->key, node2->key);
  printf("-> %s \n", (tocheck_isinmiddle ? "yes it is " : "no it's not"));
  
  // free BST
  BST_Destroy(&myBST);
  return;
}

void MainBST_FindKeysInRange(int* keys, int n) {    
  printf("\n----------------------------------- MainBST_FindKeysInRange \n");
  
  int i;
  BSTType myBST = {0};
  BST_Init(&myBST, BinaryTree_CompFunNodePtr_Ascending);  
  for (i = 0; i < n; ++i) {
    BST_InsertKeyVal(&myBST, keys[i], -42);
  }
  
  // print tree
  printf("BST reads in preorder: \n");
  BST_PrintTreePreOrder(&myBST);
  
  // find keys in range
  int lower_limit = 11;
  int upper_limit = 15;
  int* keys_in_range = NULL;
  int count = 0;
  BST_FindKeysInRange(myBST.root, lower_limit, upper_limit, &keys_in_range, &count);
  
  // print result
  printf("Found that the following keys of the BST are in [%d, %d] : \n", 
          lower_limit, upper_limit);
  if (count) {
    PrintArray1d(keys_in_range, count);  
  } else {
    printf("none.. \n");
  }
  
  // free BST
  BST_Destroy(&myBST);
  free(keys_in_range);
  return;
}
/**---------------------------------------------------------------------------*/
/**---------------------------------------------------------------------------*/
/**---------------------------------------------------------------------------*/



//------------------------------------------------------ BST API

void BST_Init(BSTType* bst, int (*compfun)(const void*, const void*)) {
  bst->root = NULL;
  bst->compfun = compfun;
  bst->n_nodes = 0;
  return;  
}

void BST_Destroy(BSTType* bst) {
  if (bst) {    
    BST_DestroyHelper(bst, bst->root);
  }
  if (bst->n_nodes != 0) {
    printf("Memory leak! Implementation buggy, did not free all nodes. \n");
  }
  return;
}

/**
 * Work bottom to-top.
 * 
 * @param bst
 * @param to_delete
 */
void BST_DestroyHelper(BSTType* bst, BTNodeT* to_delete) {
  if (bst && to_delete) {
    BST_DestroyHelper(bst, to_delete->left);
    BST_DestroyHelper(bst, to_delete->rght);
    free(to_delete);
    --(bst->n_nodes);
  }
  return;
}

/**
 * Note: the structure of a BST for a given set of data is not unique !
 *       --> e.g. the simplest form is always to have a linear chain
 *           without branches so that the height of the tree is n
 *       ==> to have an efficient BST one aims, however, at a height-balanced
 *           tree !
 * 
 * Strategy: For simplicity, we simply go left/right until a node has
 *           a free child that the new_node could be placed in
 *           
 *           -> assuming the input of nodes to the tree
 *           does not happen in a sorted way,
 *             the tree will, on average, build up in a rather balanced way
 *           => if the input is sorted, this strategy is very bad and the
 *              tree will build up without branching
 * 
 * Prospect: To get a height-balanced BST, restructuring of the BST on the basis
 *           of the measured height-diffs of the subtrees would be needed. 
 *           In particular, this would require the setting of an adapted root.
 * 
 * @param bst
 * @param new_node
 */
BTNodeT* BST_InsertKeyVal(BSTType* bst, int key, int val) {  
  if (!bst) {return NULL;}  
  BTNodeT* new_node = calloc(1, sizeof(BTNodeT));
  new_node->key = key;
  new_node->val = val;
  ++(bst->n_nodes);  
  BTNodeT* inserted_at = NULL;  // if new node is root, return NULL
  if (bst->root == NULL) {bst->root = new_node;}
  else {inserted_at = BST_IntegrateNewNodeIntoBST(bst, new_node, bst->root);}
  return inserted_at;
}

/**
 * NOTE: if newnode has equal key, flip a coin to decide whether it will be
 *       inserted left or rght
 * 
 *       if both left and rght are already occupied, descend
 *       according to the ordering relation and check
 *       recursively if child has a free slot
 * 
 * @param bst
 * @param new_node
 * @param parent_node
 */
BTNodeT* BST_IntegrateNewNodeIntoBST(BSTType* bst, BTNodeT* new_node, BTNodeT* parent) {
  BTNodeT* inserted_at = NULL;
  BTNodeT* left = parent->left;
  BTNodeT* rght = parent->rght;  
  bool equalkey_randomturnleft = false;
  bool equalkey_randomturnrght = false;  
  int retval_comparison = bst->compfun(new_node, parent);
  if (retval_comparison == 0) {
    if (rand() % 2) {equalkey_randomturnleft = true;}
    else {equalkey_randomturnrght = true;}
  }  
  if (retval_comparison < 0 || equalkey_randomturnleft) { 
    if (left) {inserted_at = BST_IntegrateNewNodeIntoBST(bst, new_node, left);}
    else {     
      parent->left = new_node;
      inserted_at = parent;
    }    
  } else if (retval_comparison > 0 || equalkey_randomturnrght) {
    if (rght) {inserted_at = BST_IntegrateNewNodeIntoBST(bst, new_node, rght);}
    else {      
      parent->rght = new_node;
      inserted_at = parent;
    }    
  }
  return inserted_at;
}



/**
 *  
 * Easy, if  - to_delete has no children
 *           - to_delete has 1 child
 * 
 * Hibbard's algorithm, if 
 *           - to_delete has 2 children
 * 
 * Hibbard's algorithm: 
 * 
 *    Since deleting a node can be trivially done, if it has only 1 or 0
 *    children, we can try to swap the to_delete node with its 
 *    predecessor or successor. The reasoning is that if the to_delete
 *    node has two children, its predecessor is guaranteed to have
 *    at maximum one child (otherwise another node would be the predecessor),
 *    and the same holds for the succesor. Furthermore, the predecessor
 *    and the successor do not violate the BST ordering when they
 *    are swapped to position of the to_delete node.
 * 
 *    
 * 
 * @param bst
 * @param to_delete
 * @return 
 */
bool BST_EraseNode(BSTType* bst, BTNodeT* to_delete) {
  if (!bst || !to_delete) return false;
  // parent is needed in any case to do the delete (for root will be NULL)
  BTNodeT *parent = BST_FindParentOfNode(bst, to_delete);
  if (parent == NULL && to_delete != bst->root) {return false;}  
  if (!to_delete->left && !to_delete->rght) {          // 0 children case
    if (to_delete == bst->root) {bst->root = NULL;}
    else if (to_delete == parent->left) parent->left = NULL;
    else if (to_delete == parent->rght) parent->rght = NULL;        
    free(to_delete);    
    --bst->n_nodes;
    return true;
  } else if ((!to_delete->left && to_delete->rght) ||  // 1 child case
          (to_delete->left && !to_delete->rght)) {    
    BTNodeT* unique_child = (to_delete->left ? to_delete->left : to_delete->rght);
    if (to_delete == bst->root) {bst->root = unique_child;}    
    else if (to_delete == parent->left) parent->left = unique_child;
    else if (to_delete == parent->rght) parent->rght = unique_child;
    free(to_delete);  
    --bst->n_nodes;
    return true;
  } else {  // 2 children case    
    BTNodeT* predecessor = BST_Predecessor(bst, to_delete);
    BST_CopyNode(to_delete, predecessor);    
    predecessor->left = NULL, predecessor->rght = NULL;
    return BST_EraseNode(bst, predecessor);    
  }
}
void BST_CopyNode(BTNodeT* dst, BTNodeT *src) {
  *dst = *src;
  return;
}


int BST_InOrderTraversal(BSTType* bst) {
  int n_nodes_visited = 0;  
  n_nodes_visited = BST_InOrderTraversal_Recursion(bst->root);
  return n_nodes_visited;
}

int BST_InOrderTraversal_Recursion(BTNodeT* node) {
  int n_nodes_visited = 0;  
  if (node == NULL) {
    return 0;    
  }  
  n_nodes_visited += BST_InOrderTraversal_Recursion(node->left);  
  ++n_nodes_visited;  
  n_nodes_visited += BST_InOrderTraversal_Recursion(node->rght);  
  return n_nodes_visited;
}

void BST_PrintTreeInOrder(BSTType* bst) {
  printf("Inorder traversal of BST reads: \n");
  BST_PrintTreeInOrderHelper(bst->root);
  printf("\n");
  return;
}
void BST_PrintTreeInOrderHelper(BTNodeT* node) {
  if (node) {
    if (node->left) {BST_PrintTreeInOrderHelper(node->left);}
    printf("Key: %i \n", node->key);
    if (node->rght) {BST_PrintTreeInOrderHelper(node->rght);}
  }
  return;
}
/**
 * Note: BST can be uniquely reconstructed from preorder traversal
 * (not from inorder traversal)
 * 
 * @param bst
 */
void BST_PrintTreePreOrder(BSTType* bst) {
  printf("Preorder traversal of BST reads: \n");
  BST_PrintTreePreOrderHelper(bst->root);
  printf("\n");
  return;  
}
void BST_PrintTreePreOrderHelper(BTNodeT* node) {  
  if (node) {
    printf("Key: %i \n", node->key);
    if (node->left) {BST_PrintTreePreOrderHelper(node->left);}
    if (node->rght) {BST_PrintTreePreOrderHelper(node->rght);}
  }
}
    

/**
 * Just another function to track the nodes visited during traversal.
 * 
 * @param bst
 * @param nodes_arr
 * @return 
 */
void BST_NodesToArrayInOrder(BSTType* bst, BTNodeT* nodes_arr[]) {  
  int count = 0; 
  BST_NodesToArrayInOrder_Helper(bst->root, nodes_arr, &count);
  return;
}
void BST_NodesToArrayInOrder_Helper(BTNodeT* node, 
        BTNodeT* nodes_arr[], int* count) {  
  if (!node){return;}
  BST_NodesToArrayInOrder_Helper(node->left, nodes_arr, count);
  nodes_arr[(*count)++] = node;  
  BST_NodesToArrayInOrder_Helper(node->rght, nodes_arr, count);  
  return;
}
  
void BST_NodesToArrayPreOrder(BSTType* bst, BTNodeT* nodes_arr[]) {    
  int count = 0; 
  BST_NodesToArrayPreOrder_Helper(bst->root, nodes_arr, &count);
  return;
}
void BST_NodesToArrayPreOrder_Helper(BTNodeT* node, 
        BTNodeT* nodes_arr[], int* count) {
  if (!node){return;}
  nodes_arr[(*count)++] = node;  
  BST_NodesToArrayPreOrder_Helper(node->left, nodes_arr, count);
  BST_NodesToArrayPreOrder_Helper(node->rght, nodes_arr, count);  
  return;    
}


/**
 * Go to the right until not possible to go further.
 * --> Once we cannot go further to the right we are at the Max.
 * 
 * @param root
 * @return 
 */
BTNodeT* BST_LastNode(BTNodeT* candidate) {
  if (candidate) {
    if(candidate->rght) {
      return BST_LastNode(candidate->rght);
    } else {
      return candidate;
    }  
  } else {
    return NULL;
  }  
}

/**
 * Go to the left until not possible to go further.
 * --> Once we cannot go further to the left we are at the Min
 * 
 * @param root
 * @return 
 */
BTNodeT* BST_FirstNode(BTNodeT* candidate) {
  if (candidate) {
    if(candidate->left) {
      return BST_FirstNode(candidate->left);
    } else {
      return candidate;
    }  
  } else {
    return NULL;
  }  
}


/**
 * 
 * @param node
 * @return 
 */
bool BST_IsLeaf(BTNodeT* node) {
  return ((!node->left && !node->rght ) ? true : false);
}

/**
 * In a BST of nodes that are more sophisticated than just having
 * an integer data content, one would could imagine a search 
 * function that searches for a certain value of some attribute
 * in the node, with the value not being the key after which 
 * the BST is structured 
 * 
 *    --> such searches are expensive, O(n), since the BST
 *        can only search fast for the keys used to determine its order
 * 
 * @param bst
 * @param target_key
 * @return 
 */
BTNodeT* BST_FindKey(BSTType* bst, int target_key) {
  return BST_FindKeyHelper(bst, target_key, bst->root);
}

BTNodeT* BST_FindKeyHelper(BSTType* bst, 
        int target_key,
        BTNodeT* candidate) {
  if (!candidate) {return NULL;}  
  if (candidate->key == target_key) { // key found !      
    return candidate;
  } else if (candidate->key > target_key) { // target must be left of node      
    return BST_FindKeyHelper(bst, target_key, candidate->left);
  } else { // candidate->key < target_key
    return BST_FindKeyHelper(bst, target_key, candidate->rght);
  }  
}

/**
 * 
 * @param bst
 * @param target_key
 * @return 
 */
BTNodeT* BST_FindParentOfNode(BSTType* bst, BTNodeT* target) {
  return BST_FindParentOfNodeHelper(bst, bst->root, target);
}
BTNodeT* BST_FindParentOfNodeHelper(BSTType* bst, BTNodeT* candidate,
        BTNodeT* target) {
  if (!candidate) {return NULL;}    
  if (candidate->left && candidate->left == target) {return candidate;}      
  if (candidate->rght && candidate->rght == target) {return candidate;}        
  // we need to descend deeper  
  if (candidate->key == target->key) { // need to check both subtrees
    BTNodeT* parent_inleftsubtree = BST_FindParentOfNodeHelper(bst, candidate->left, target);
    BTNodeT* parent_inrghtsubtree = BST_FindParentOfNodeHelper(bst, candidate->rght, target);
    return (parent_inleftsubtree ? parent_inleftsubtree : (parent_inrghtsubtree ?
      parent_inrghtsubtree : NULL));
  } else if (target->key < candidate->key) {
    return BST_FindParentOfNodeHelper(bst, candidate->left, target);
  } else {
    return BST_FindParentOfNodeHelper(bst, candidate->rght, target);
  }  
}

/**
 * 
 * Case distinctions:
 * 
 * if target node has a left subtree, its predecessor is
 * the max node in the left subtree.
 * else the predecessor is the closest ancestor after which the path went right
 * 
 * 
 * @param bst
 * @param target
 * @return 
 */
BTNodeT* BST_Predecessor(BSTType* bst, BTNodeT* target) {  
  if (!bst || !target) {return NULL;}
  if (target->left) {
    return BST_LastNode(target->left);
  } else {
    return BST_ClosestAncestorAfterWhichPathWentRight(bst, bst->root, target, NULL);    
  }
}
/**
 * The situation is: we have a path from the root to a specific target node  
 *                   and want to get the ancestor node closest to the target
 *                   after that the path traverses the RIGHT child.
 * 
 * E.g.                               32
 *                    7                                 36
 *             4            30                    34              41
 *          2     5       9     31            33     35       37       50
 * 
 * 
 *  --> if the target node is  5, then the result is  4
 *      if the target node is 37, then the result is 36
 *      if the target node is 33, then the result is 32
 * 
 *  
 * @param compfun_nodeptr
 * @param root
 * @param target
 * @param target_ancestor
 */
BTNodeT* BST_ClosestAncestorAfterWhichPathWentRight(BSTType* bst, BTNodeT* node, 
        BTNodeT* target,
        BTNodeT* closest_ancestorafterwhichpathwentrght) { 
  if (!bst || !node) {return NULL;}    
  if (node->key == target->key) { // success
    return closest_ancestorafterwhichpathwentrght;
  }
  if (BST_IsLeaf(node)) {
    return NULL;
  } else {
    // continue searching the target
    BTNodeT* ancestor_iftargetinleft = 
            BST_ClosestAncestorAfterWhichPathWentRight(bst, node->left, target,
        closest_ancestorafterwhichpathwentrght);
    BTNodeT* ancestor_iftargetinrght =  
            BST_ClosestAncestorAfterWhichPathWentRight(bst, node->rght, target,
        node);
    return (ancestor_iftargetinleft ? ancestor_iftargetinleft : 
      (ancestor_iftargetinrght ? ancestor_iftargetinrght : NULL));
  }  
}

BTNodeT* BST_Successor(BSTType* bst, BTNodeT* target) {  
  if (!bst || !target) {return NULL;}
  if (target->rght) {
    return BST_FirstNode(target->rght);
  } else {
    return BST_ClosestAncestorAfterWhichPathWentLeft(bst, bst->root, target, NULL);    
  }
}

/***
 * The situation is: we have a path from the root to a specific target node  
 *                   and want to get the ancestor node closest to the target
 *                   after that the path traverses the LEFT child.
 * 
 * E.g.                               32
 *                    7                                 36
 *             4            30                    34              41
 *          2     5       9     31            33     35       37       50
 * 
 * 
 *  --> if the target node is  5, then the result is  7
 *      if the target node is 37, then the result is 41
 *      if the target node is 33, then the result is 34
 *  
 * @param compfun_nodeptr
 * @param root
 * @param target
 * @param target_ancestor
 */
BTNodeT* BST_ClosestAncestorAfterWhichPathWentLeft(BSTType* bst, BTNodeT* node,
        BTNodeT* target,
        BTNodeT* closest_ancestorafterwhichpathwentleft) { 
  if (!bst || !node) {return NULL;}    
  if (node->key == target->key) { // success
    return closest_ancestorafterwhichpathwentleft;
  }
  if (BST_IsLeaf(node)) {
    return NULL;
  } else {
    // continue searching the target
    BTNodeT* ancestor_iftargetinleft = 
            BST_ClosestAncestorAfterWhichPathWentLeft(bst, node->left, target,
        node);
    BTNodeT* ancestor_iftargetinrght =  
            BST_ClosestAncestorAfterWhichPathWentLeft(bst, node->rght, target,
        closest_ancestorafterwhichpathwentleft);
    return (ancestor_iftargetinleft ? ancestor_iftargetinleft : 
      (ancestor_iftargetinrght ? ancestor_iftargetinrght : NULL));
  }  
}

/**
 * We have to go left and right again and again, tracking
 * the best seen candidate until we make a turn that leads to failure.
           
 * @param bst
 * @param target
 * @return 
 */
BTNodeT* BST_PredecessorDistinctKeys(BSTType* bst, BTNodeT* target) {
  if (!bst || !bst->root || !target) return NULL;
  BTNodeT* curr = bst->root;  
  BTNodeT* best_sofar = NULL;
  while (curr) {
    if (curr->key < target->key) { // curr is a candidate !
      best_sofar = curr;
      curr = curr->rght; // check if a better candidate exists
    } else { // curr >= target  // curr is not a candidate
      curr = curr->left;
    }
  }
  return best_sofar;
}


/** 
 * We have to go left and right again and again, tracking
 * the best seen candidate until we make a turn that leads to failure.
 * 
 * @param bst
 * @param target
 * @return 
 */
BTNodeT* BST_SuccessorDistinctKeys(BSTType* bst, BTNodeT* target) {
  if (!bst || !bst->root || !target) return NULL;
  BTNodeT* curr = bst->root;  
  BTNodeT* best_sofar = NULL;
  while (curr) {
    if (curr->key > target->key) { // curr is a candidate !
      best_sofar = curr;
      curr = curr->left; // check if a better candidate exists
    } else { // curr <= target  // curr is not a candidate
      curr = curr->rght;
    }
  }
  return best_sofar;
}


BTNodeT* BST_NextGreaterNode(BSTType* bst, int target_key) {
  BTNodeT *c = bst->root, *bestguess_sofar = NULL;
  while (c) {
    if (c->key > target_key) {
      bestguess_sofar = c;
      c = c->left;
    } else {
      c = c->rght;
    }
  }
  return bestguess_sofar;
}
BTNodeT* BST_NextLesserNode(BSTType* bst, int target_key) {
  BTNodeT *c = bst->root, *bestguess_sofar = NULL;
  while (c) {
    if (c->key < target_key) {
      bestguess_sofar = c;
      c = c->rght;
    } else {
      c = c->left;
    }
  }
  return bestguess_sofar;
}

/** 
 * @param bst
 * @param target_key
 * @return 
 */
BTNodeT* BST_NextGreaterNodeRecursive(BSTType* bst, BTNodeT* c, int target_key) {
  if(!bst || !c) {return NULL;}
  if (c->key > target_key) {
    if (!c->left || c->left->key <= target_key) return c;
    else { // c->left is also > target_key
      return BST_NextGreaterNodeRecursive(bst, c->left, target_key);
    }        
  } else { // c <= target_key    
    return BST_NextGreaterNodeRecursive(bst, c->rght, target_key); // may be NULL
  }
}
BTNodeT* BST_NextLesserNodeRecursive(BSTType* bst, BTNodeT* c, int target_key) {
  if(!bst || !c) {return NULL;}
  if (c->key < target_key) {
    if (!c->rght || c->rght->key >= target_key) return c;
    else { // c->rght is also < target_key
      return BST_NextLesserNodeRecursive(bst, c->rght, target_key);
    }        
  } else { // c >= target_key    
    return BST_NextLesserNodeRecursive(bst, c->left, target_key); // may be NULL
  }
}



//-------------------------------------------------------------- Exercises

/**
 * This function checks whether a node and its children have the correct
 * ordering and if the triple in total is in the interval
 * 
 *         lower_limit <= triple <= upper_limit
 * 
 * where these limits come from the fact that
 * a subtree of a BST must conform to the limits imposed by its anchestors !
 * 
 * Example:
 *                        root 
 *                 a                  b
 *            c        d         e          f
 *          g   h    i    j    k   l      m   n
 * 
 * the subtree (e,k,l) must satisfy:  root <= (e,k,l) <= b , so b sets the upper_limit
 * for the subtree and root, sets the lower limit.   
 * 
 * @param node
 * @param lower_limit
 * @param upper_limit
 * @return 
 */
bool BST_CheckIfBTisBST(BSTType* bst) {
  return BST_CheckIfBTIsBSTHelper(bst->root, INT_MIN, INT_MAX);
}

bool BST_CheckIfBTIsBSTHelper(BTNodeT* node, int lower_limit, int upper_limit) {
  if (!node) return true;  
  if (node->key < lower_limit || node->key > upper_limit) {
    return false;    
  } // if passing here: current node is OK
  bool left_OK = BST_CheckIfBTIsBSTHelper(node->left, lower_limit, node->key);
  bool rght_OK = BST_CheckIfBTIsBSTHelper(node->rght, node->key, upper_limit);
  return ((left_OK && rght_OK ) ? true : false);
}

/**
 * reverse in-order traversal with global count
 * 
 * @param bst
 * @param result
 * @param k
 */
void BST_FindKGreatestKeys(BSTType* bst, int* result, int k) {
  int count = 0;
  BST_FindKGreatestKeys_Helper(bst->root, result, k, &count);
  return;
}
void BST_FindKGreatestKeys_Helper(BTNodeT* c, int* result, const int k, int* count) {
  if (!c || *count == k)   {return;}
  BST_FindKGreatestKeys_Helper(c->rght, result, k, count);
  if (*count < k) {
    result[*count] = c->key;
    ++(*count);
    BST_FindKGreatestKeys_Helper(c->left, result, k, count);
  }
  return;
}

/**
 * Assume both keys are in the tree
 * 
 * @param c
 * @param key1
 * @param key2
 * @return 
 */
BTNodeT* BST_FindLCADistinctKeys(BTNodeT* c, int key1, int key2) {
  if (!c) return NULL;
  if (key1 > c->key && key2 > c->key) {
    return BST_FindLCADistinctKeys(c->rght, key1, key2);
  } else if (key1 < c->key && key2 < c->key) {
    return BST_FindLCADistinctKeys(c->left, key1, key2);
  } else {
    return c;
  }
}
/**
 * ACHTUNG: assuming distinct keys !
 * 
 * @param preorder
 * @param n
 * @return 
 */
BSTType BST_FromPreorder(BTNodeT** preorder, int n) {  
  BSTType newBST = {0};
  if (preorder && preorder[0]) {
    int count = 0;
    BTNodeT* new_root = BST_FromPreorder_Helper(preorder,
            n, &count, INT_MIN, INT_MAX);
    newBST.root = new_root;
    newBST.n_nodes = count;            
  }
  return newBST;
}
BTNodeT* BST_FromPreorder_Helper(BTNodeT** preorder, int n, int* i, int low, int up) {
  if (*i == n || preorder[*i]->key < low 
          || preorder[*i]->key > up) {return NULL;}
  BTNodeT* new_node = BinaryTree_AllocateNewNode(preorder[(*i)++]->key, -42);
  new_node->left = BST_FromPreorder_Helper(preorder, n, i, low, new_node->key);
  new_node->rght = BST_FromPreorder_Helper(preorder, n, i, new_node->key, up);  
  return new_node;
}    

/**
 * 
 * @param arrays
 * @param k
 * @param n
 * @return 
 */
int* BST_ShortestSetContainingValueFromKSortedArrays(int** arrays, int k, int n) {  
  int *shortest_set = calloc(k, sizeof(int));
  BSTType candidates2arrID = {0};  
  BST_Init(&candidates2arrID, BinaryTree_CompFunNodePtr_Ascending);  
  int i;
  for (i = 0; i < k; ++i) {BST_InsertKeyVal(&candidates2arrID, arrays[i][0], i);}
  int idx_tracker[k];
  memset(idx_tracker, 0, k * sizeof(int));
  int shortest_length_sofar = INT_MAX;
  while (1) {
    BTNodeT* min_elem = BST_FirstNode(candidates2arrID.root);
    BTNodeT* max_elem = BST_LastNode(candidates2arrID.root);
    int length_candidate_set = max_elem->key - min_elem->key;
    if (length_candidate_set < shortest_length_sofar) {
      shortest_length_sofar = length_candidate_set;
      BTNodeT* current_candidate_set[k];
      BST_NodesToArrayInOrder(&candidates2arrID, current_candidate_set);
      for (i = 0; i < k; ++i) {shortest_set[i] = current_candidate_set[i]->key;}
    }
    int arrID = min_elem->val;    
    if (++(idx_tracker[arrID]) == n) {break;} // idx beyond limit of this array
    BST_EraseNode(&candidates2arrID, min_elem);    
    BST_InsertKeyVal(&candidates2arrID, arrays[arrID][idx_tracker[arrID]], arrID);
  }  
  // free map
  BST_Destroy(&candidates2arrID);  
  return shortest_set;
}

/**
 * Algorithm exploits that given the set of k smallest numbers of the
 * form a + b sqrt(2), the (k + 1 )-th smallest can be computed
 * by one of the k smallest numbers by adding either 1 or 1 * sqrt(2) 
 * 
 * Note: this algorithm does NOT use a BST because in a BST
 * one would need to insert the key a + b sqrt(2) mapped to values (a,b)
 * to either raise a or b (our BST structure does not yet support 2 values).
 * 
 * @param k
 * @return 
 */
double *KSmallestAplusBSqrt2Numbers(int k) {
  double *ksmallest = calloc(k, sizeof(double));
  ksmallest[0] = 0;
  int count = 1;
  int idx_smallest_a = 0;
  int idx_smallest_b = 0;
  while (count < k) {
    double candidate_raised_a = ksmallest[idx_smallest_a] + 1;
    double candidate_raised_b = ksmallest[idx_smallest_b] + sqrt(2);
    ksmallest[count] = candidate_raised_a < candidate_raised_b ? 
      candidate_raised_a : candidate_raised_b;
    if (EqualToPrec(ksmallest[count], candidate_raised_a, PREC)) ++idx_smallest_a;
    if (EqualToPrec(ksmallest[count], candidate_raised_b, PREC)) ++idx_smallest_b;
    ++count;
  }
  return ksmallest;
}

/**
 * The idea is that the best node to become the root is at the center
 * of the sorted array because half of the other nodes are smallerequal
 * and half of the other nodes are largerequal.
 * 
 * --> this prescription can be applied recursively for the left 
 *     and right subtrees of the found root
 * 
 * @param len_subarray
 * @param idx_1st_of_subarray
 * @param sorted_arr_nodeptrs
 * @return 
 */

BSTType BST_HeightBalancedBSTFromSortedKeys(int* sorted_keys, int n) {
  BSTType newbst = {0};
  newbst.root = BST_HeightBalancedBSTFromSortedKeys_Helper(sorted_keys, 0, n - 1);
  newbst.n_nodes = n;
  return newbst;
}
BTNodeT* BST_HeightBalancedBSTFromSortedKeys_Helper(int* sorted_keys,
        int l, int r) {
  if (l > r) return NULL;
  int mid_idx = l + (r - l) / 2; // if r - l odd, mid has one more right than left of it
  BTNodeT* new_node = BinaryTree_AllocateNewNode(sorted_keys[mid_idx], -42);
  if (l < r) {
    new_node->left = BST_HeightBalancedBSTFromSortedKeys_Helper(sorted_keys,
          l, mid_idx - 1);
    new_node->rght = BST_HeightBalancedBSTFromSortedKeys_Helper(sorted_keys,
          mid_idx + 1, r);
  }
  return new_node;
}

/**
 * First, one needs to find out whether node1 and node2 are in a line,
 * i.e. that one is the direct ancestor of another.
 * 
 * Assuming distinct keys
 * 
 * @param node1
 * @param node2
 * @param tocheck
 * @return 
 */
bool BST_IsTobecheckedInLineOfPair(BSTType *bst,
        BTNodeT *node1, BTNodeT *node2, BTNodeT* tocheck) {
  BTNodeT* match_tocheckin1 = BST_FindKeyHelper(bst, tocheck->key, node1);
  if (match_tocheckin1) {
    BTNodeT* match_2intocheck = BST_FindKeyHelper(bst, node2->key, tocheck);
    if (match_2intocheck) return true;
  }
  BTNodeT* match_tocheckin2 = BST_FindKeyHelper(bst, tocheck->key, node2);
  if (match_tocheckin2) {
    BTNodeT* match_1intocheck = BST_FindKeyHelper(bst, node1->key, tocheck);
    if (match_1intocheck) return true;
  }  
  return false;
}

void BST_FindKeysInRange(BTNodeT* c, int lower_limit, int upper_limit, 
        int **result, int *n_result) {
  if (!c) {return;}
  if (c->key >= lower_limit && c->key <= upper_limit) {
    BST_FindKeysInRange(c->left, lower_limit, upper_limit, result, n_result);
    ++(*n_result);
    *result = realloc(*result, (*n_result) * sizeof(int));
    (*result)[(*n_result) - 1] = c->key;
    BST_FindKeysInRange(c->rght, lower_limit, upper_limit, result, n_result);
  } else if (c->key > upper_limit) {
    BST_FindKeysInRange(c->left, lower_limit, upper_limit, result, n_result);
  } else if (c->key < lower_limit) {
    BST_FindKeysInRange(c->rght, lower_limit, upper_limit, result, n_result);
  }
  return;
}

/**
 * Idea: write nodes of both trees to arrays, merge them, sort them,
 * and then use algorithm to construct a new tree from a sorted array.
 * 
 * @param root1
 * @param root2
 * @param compfun
 * @return 
 */
BSTType BST_MergeTrees(BSTType* bst1, BSTType* bst2) {
  BTNodeT* root1 = bst1->root;
  BTNodeT* root2 = bst2->root;   
  if (root1 == NULL || root2 == NULL) {
    printf("Cannot merge the trees. One of them is NULL. \n");
    return (BSTType){NULL, NULL, 0};
  }
  
  // find lengths of the subtrees
  const int len1 = BST_InOrderTraversal_Recursion(root1);
  const int len2 = BST_InOrderTraversal_Recursion(root2);
  
  // parse the two trees with "in-order-traversal" and thus fill a sorted array  
  printf("\nBuild arrays from the bsts: \n");
  BTNodeT* sorted_arr_nodeptrs1[len1];
  BTNodeT* sorted_arr_nodeptrs2[len2];
  int counter = 0; 
  BST_NodesToArrayInOrder_Helper(root1, sorted_arr_nodeptrs1, 
          &counter);
  counter = 0;
  BST_NodesToArrayInOrder_Helper(root2, sorted_arr_nodeptrs2, 
          &counter);
  
  // DEBUG 
  printf("\nFor merging the bst1 becomes the array: \n");
  int j = 0;
  for (j = 0; j < len1; ++j) {
    printf("sorted_arr_nodeptrs1[%i]->data=%i \n", j, 
            sorted_arr_nodeptrs1[j]->key);
  }
  printf("\n");  
  printf("\nFor merging the bst2 becomes the array: \n");
  for (j = 0; j < len2; ++j) {
    printf("sorted_arr_nodeptrs2[%i]->data=%i \n", j, 
            sorted_arr_nodeptrs2[j]->key);
  }
  
  
  // MergeTwoSortedArraysExtraMemory - see sorting.c 
  // -> cannot use the function from there because it was specialised to int comp-func
  const int len = len1 + len2;
  BTNodeT* sorted_arr_merged[len];
  int sorted_keys_merged[len];
  int i1 = 0, i2 = 0, i = 0;    
  while (i < len) {
    i = i1 + i2;
    BTNodeT* l = NULL;
    BTNodeT* r = NULL;
    if (i1 < len1) {
      l = sorted_arr_nodeptrs1[i1];
    }
    if (i2 < len2) {
      r = sorted_arr_nodeptrs2[i2];
    }
    if (l && r) {
      if (bst1->compfun(l, r) < 0) { // < 0 means, l should come before r
        sorted_arr_merged[i1 + i2] = l;
        ++i1;
      } else {
        sorted_arr_merged[i1 + i2] = r;
        ++i2;
      }
    } else if (l) {
      sorted_arr_merged[i1 + i2] = l;
      ++i1;      
    } else if (r) {
        sorted_arr_merged[i1 + i2] = r;
        ++i2;      
    }
    sorted_keys_merged[i] = sorted_arr_merged[i]->key;
  }
  
  // DEBUG 
  printf("\nThe merged array reads: \n");  
  for (j = 0; j < len; ++j) {
    printf("sorted_arr_merged[%i]->data=%i \n", j, 
            sorted_arr_merged[j]->key);
  }
  printf("\n"); 
  
  // Build new BST from the sorted array that contains both BSTs
  printf("\nBuild new tree from the merged two BSTs: \n"); 
  BTNodeT* new_root = 
          BST_HeightBalancedBSTFromSortedKeys_Helper(sorted_keys_merged, 0, len - 1);
  
  BSTType merged_BST = {new_root, bst1->compfun, bst1->n_nodes + bst2->n_nodes};
  bst1->n_nodes = 0;
  bst2->n_nodes = 0;
  return merged_BST; 
}