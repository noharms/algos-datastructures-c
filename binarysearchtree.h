/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   binarysearchtree.h
 * Author: noh
 *
 * Created on April 8, 2018, 11:41 AM
 */

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#ifdef __cplusplus
extern "C" {
#endif

  #include <stdbool.h>

  #include "standardheaders.h"  
  #include "binarytree_as_nodes.h"
  
  /* note: in a more modern language one would have the BSTType be a
  *        child class of the basic BinarytreeType and then 
  *        define the general functions like TraverseInorder
  *        for BinarytreeType objects
  *        --> in C we cannot do that. we have to redefine a new type and
  *            functions for that type
  */
  typedef struct BINARYSEARCHTREE {    
    BTNodeT *root;
    int (*compfun)(const void*, const void*); // void* to allow comparing nodes of complex datatypes
    int n_nodes;    
  } BSTType;
  
  void MainBST();
  
  void MainBST_InOrderTraversal(int* keys, int n);
  void MainBST_SearchMinMax(int* keys, int n);
  void MainBST_SearchKey(int* keys, int n);
  void MainBST_SearchParentOfKey(int* keys, int n);
  void MainBST_InOrderPredecessor(int* keys, int n);
  void MainBST_InOrderSuccessor(int* keys, int n);
  void MainBST_DeleteNode(int* keys, int n);
  void MainBST_MergeBSTs(int* keys, int n, int* keys_random, int m);
  
  void MainBST_CheckIfBTisBST(int* keys, int n);
  void MainBST_NextGreaterNode(int* keys, int n);
  void MainBST_KGreatestKeys(int* keys, int n);
  void MainBST_LCADistinctKeys(int* keys, int n);
  void MainBST_BuildBSTDistinctKeysPreorderData(int* keys, int n);
  void MainBST_ShortestSetContainingValueFromKArrays();
  void MainBST_KSmallestAplusBSqrt2Numbers();
  void MainBST_ConstructHeightBalancedBSTFromSortedArray(int* keys, int n);
  void MainBST_IsMiddleNodeInLineWithPairDistinctKeys(int* keys, int n);
  void MainBST_FindKeysInRange(int* keys, int n);
  
  //--------------------------------------------------------- BST API
  
  void BST_Init(BSTType* bst, int (*compfun)(const void*, const void*));
  void BST_Destroy(BSTType* bst);
  void BST_DestroyHelper(BSTType* bst, BTNodeT* to_delete);
    
  BTNodeT* BST_InsertKeyVal(BSTType* bst, int key, int val);
  BTNodeT* BST_IntegrateNewNodeIntoBST(BSTType* bst, BTNodeT* new_node, BTNodeT* parent);
  bool BST_EraseNode(BSTType* bst, BTNodeT* to_delete);
  void BST_CopyNode(BTNodeT* dst, BTNodeT *src);
  
  int BST_InOrderTraversal(BSTType* bst);
  int BST_InOrderTraversal_Recursion(BTNodeT* node);
  void BST_PrintTreeInOrder(BSTType* bst);
  void BST_PrintTreeInOrderHelper(BTNodeT* node);
  void BST_PrintTreePreOrder(BSTType* bst);
  void BST_PrintTreePreOrderHelper(BTNodeT* node);
    
  void BST_NodesToArrayInOrder(BSTType* bst, BTNodeT* nodes_arr[]);
  void BST_NodesToArrayInOrder_Helper(BTNodeT* node, 
        BTNodeT* nodes_arr[], int* count);  
  void BST_NodesToArrayPreOrder(BSTType* bst, BTNodeT* nodes_arr[]);
  void BST_NodesToArrayPreOrder_Helper(BTNodeT* node, 
        BTNodeT* nodes_arr[], int* count);
    
  BTNodeT* BST_LastNode(BTNodeT* root);
  BTNodeT* BST_FirstNode(BTNodeT* root);  
  
  bool BST_IsLeaf(BTNodeT* node);
    
  BTNodeT* BST_FindKey(BSTType* bst, 
          int target_key);
  BTNodeT* BST_FindKeyHelper(BSTType* bst, 
        int target_key,
        BTNodeT* node);  
  BTNodeT* BST_FindParentOfNode(BSTType* bst, BTNodeT* target);
  BTNodeT* BST_FindParentOfNodeHelper(BSTType* bst, BTNodeT* node, BTNodeT* target);
    
  BTNodeT* BST_Predecessor(BSTType* bst, BTNodeT* target);
  BTNodeT* BST_Successor(BSTType* bst, BTNodeT* target);  
  BTNodeT* BST_ClosestAncestorAfterWhichPathWentRight(BSTType* bst, BTNodeT* node, 
          BTNodeT* target,
        BTNodeT* closest_ancestorafterwhichpathwentrght);
  BTNodeT* BST_ClosestAncestorAfterWhichPathWentLeft(BSTType* bst, BTNodeT* node, 
          BTNodeT* target,
        BTNodeT* closest_ancestorafterwhichpathwentleft); 
  BTNodeT* BST_PredecessorDistinctKeys(BSTType* bst, BTNodeT* target);
  BTNodeT* BST_SuccessorDistinctKeys(BSTType* bst, BTNodeT* target);  
    
  BTNodeT* BST_NextGreaterNode(BSTType* bst, int target_key);
  BTNodeT* BST_NextLesserNode(BSTType* bst, int target_key);
  BTNodeT* BST_NextGreaterNodeRecursive(BSTType* bst, BTNodeT* c, int target_key);
  BTNodeT* BST_NextLesserNodeRecursive(BSTType* bst, BTNodeT* c, int target_key);
      
  BSTType BST_MergeTrees(BSTType* bst1, BSTType* bst2);
    
  //----------------------------------------------- Algos  
    
  bool BST_CheckIfBTisBST(BSTType* bst);
  bool BST_CheckIfBTIsBSTHelper(BTNodeT* node, int lower_limit, int upper_limit);
  
  void BST_FindKGreatestKeys(BSTType* bst, int* result, int k);  
  void BST_FindKGreatestKeys_Helper(BTNodeT* c, int* result, const int k, int* count);
    
  BTNodeT* BST_FindLCADistinctKeys(BTNodeT* c, int key1, int key2);
    
  BSTType BST_FromPreorder(BTNodeT** preorder, int n);
  BTNodeT* BST_FromPreorder_Helper(BTNodeT** preorder, int n, int* idx, 
        int low_limit, int up_limit);
        
  int* BST_ShortestSetContainingValueFromKSortedArrays(int** arrays, int k, int n);
  
  double *KSmallestAplusBSqrt2Numbers(int k);
  
  BSTType BST_HeightBalancedBSTFromSortedKeys(int* sorted_keys, int n);
  BTNodeT* BST_HeightBalancedBSTFromSortedKeys_Helper(int* sorted_keys, int l, int r);
  
  bool BST_IsTobecheckedInLineOfPair(BSTType *bst,
        BTNodeT *node1, BTNodeT *node2, BTNodeT* tocheck) ;
  
  void BST_FindKeysInRange(BTNodeT* c, int lower_limit, int upper_limit, 
        int **result, int *n_result);

#ifdef __cplusplus
}
#endif

#endif /* BINARYSEARCHTREE_H */

