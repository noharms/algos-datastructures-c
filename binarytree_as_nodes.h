/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinarytreeType* bt.h
 * Author: noh
 *
 * Created on March 13, 2018, 11:48 AM
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H

#ifdef __cplusplus
extern "C" {
#endif
    
  #include <stdbool.h>

  #include "standardheaders.h"

  typedef unsigned long long ull;
  
    
  // at the moment a BT is just a pointer to the root
  // --> elaborate on that later if needed 
  typedef struct BINARYTREE {
    BTNodeT* root;
    int n_nodes;
  } BTType;
    
  typedef struct BINARYTREE_WITHPARENTS {
    BTNodeWithParentT* root;
    int n_nodes;
  } BTWithParentsType;
  
  struct RETURN_STATUS_LCA {
    int num_targets_in_tree;
    BTNodeT* ptr_to_LCA;
  };  
  typedef struct RETURN_STATUS_LCA ReturnStatusLCAType;
    
  void MainBinaryTreeAsNodes();
  
  void MainBinaryTree_API();
  void MainBinaryTree_InsertNodeSmallestFreeIndex();
  void MainBinaryTree_FindPathToNode();
  void MainBinaryTree_CheckHeightBalanced();
  void MainBinaryTree_CheckSymmetric();  
  void MainBinaryTree_FindLCA();
  void MainBinaryTree_SumUpRootToLeafPaths();
  void MainBinaryTree_LeafWithGivenPathWeightExists();
  void MainBinaryTree_InOrderTraversalWithoutRecursion();
  void MainBinaryTree_PreOrderTraversalWithoutRecursion();
  void MainBinaryTree_InOrderSuccessorNodesWithParent();
  void MainBinaryTree_InOrderTraversalNodesWithParentWithoutRecursion();
  void MainBinaryTree_ConstructBTFromInAndPreOrderSequences();  
  void MainBinaryTree_ConstructBTFromPreOrderSequenceWithNulls();
  void MainBinaryTree_GetLeaves();
  void MainBinaryTree_GetExterior();
  void MainBinaryTree_NodesWithNextInLevelPointerFill();
  
  // API-functions
  void BinaryTree_PrintInOrder(BTType* bt);
  void BinaryTree_PrintInOrderRecursion(BTNodeT* bt_node);    
  int* BinaryTree_GetSequenceInOrder(BTNodeT* node, int* sequence, int* n_nodes);
  void BinaryTree_GetSequenceInOrder_VOID(BTNodeT* node, BTNodeT*** sequence, int* n_nodes);
  void BinaryTree_PrintPreOrder(BTType* bt);
  void BinaryTree_PrintPreOrderRecursion(BTNodeT*   bt_node);  
  int* BinaryTree_GetSequencePreOrder(BTNodeT* node, int* sequence, int* n_nodes);
  int* BinaryTree_GetSequencePreOrderWithNulls(BTNodeT* node, 
        int* sequence, int* n_nodes);
  void BinaryTree_PrintPostOrder(BTType* bt);
  void BinaryTree_PrintPostOrderRecursion(BTNodeT* bt_node);
  int* BinaryTree_GetSequencePostOrder(BTNodeT* node, int* sequence, int* n_nodes);
  int BinaryTree_Height(BTNodeT* bt_node);  
  int BinaryTree_CompFunNodePtr_Ascending(const void* ptr1, const void* ptr2);  
  int BinaryTree_CompFunNodePtr_Descending(const void* ptr1, const void* ptr2);  
  int BinaryTree_CompFunPtrToNodePtr_Ascending(const void* ptr1, const void* ptr2);
  int BinaryTree_CompFunPtrToNodePtr_Descending(const void* ptr1, const void* ptr2); 
  
  BTNodeT* BinaryTree_Init(BTType* bt, int key, int val);  
  void BinaryTree_Destroy(BTType* bt);
  void BinaryTree_DestroyRecursive(BTNodeT* curr);  
  BTNodeT* BinaryTree_InsertBelowNode(BTType* bt, BTNodeT* parent, int key, int val);
  BTNodeT* BinaryTree_InsertAtNodeAsLeft(BTType* bt, BTNodeT* parent, int key, int val);  
  BTNodeT* BinaryTree_InsertAtNodeAsRght(BTType* bt, BTNodeT* parent, int key, int val);  
  BTNodeT* BinaryTree_AllocateNewNode(int key, int val);
  
  // API-functions WithParent
  void BinaryTree_WithParent_PrintSequenceInOrder(BTNodeWithParentT* node);
  void BinaryTree_WithParent_GetSequenceInOrder(BTNodeWithParentT* node,
        BTNodeWithParentT** sequence, int* n_nodes);
  void BinaryTree_WithParent_GetSequencePreOrder(BTNodeWithParentT* node,
        BTNodeWithParentT** sequence, int* n_nodes);
  void BinaryTree_WithParent_GetSequencePostOrder(BTNodeWithParentT* node,
        BTNodeWithParentT** sequence, int* n_nodes);
  
  BTNodeWithParentT* BinaryTree_WithParent_Init(BTWithParentsType* bt, int key, int val);
  void BinaryTree_WithParent_Destroy(BTWithParentsType* bt);
  void BinaryTree_WithParent_DestroyRecursive(BTNodeWithParentT* curr);
  BTNodeWithParentT* BinaryTree_WithParent_InsertAtNode(BTNodeWithParentT* parent, 
          int key, int val);
  BTNodeWithParentT* BinaryTree_WithParent_InsertAtNodeAsLeft(BTNodeWithParentT* parent, 
          int key, int val);
  BTNodeWithParentT* BinaryTree_WithParent_InsertAtNodeAsRght(BTNodeWithParentT* parent, 
          int key, int val);  
    
  
  //---------------------------- Excercises  
  
  BTNodeT* BinaryTree_InsertNodeAtSmallestFreeIndex(BTType* bt, int key, int val);
  void BinaryTree_GetSmallestIndexNodeWithFreeChild(BTNodeT* bt_node, int rec_depth, 
        int* mindepth_notfullnode,
        BTNodeT** notfull_node);  
  
  void BinaryTree_PathToNode(BTNodeT* root, 
        BTNodeT* node, 
        int path_to_node[],
        int* flag_node_was_found,
        int rec_depth);
  
  int BinaryTree_ComputeHeightAndCheckBalance(BTNodeT* node, bool *isbalanced);
  
  bool BinaryTree_IsSymmetric_Wrapper(BTNodeT* node);
  bool BinaryTree_AreNodesSymmetric(BTNodeT* n1, BTNodeT* n2);
     
  int BinaryTree_FindLCA(BTNodeT* root, BTNodeT* node1, 
        BTNodeT* node2, BTNodeT** ptr_toLCA);
  ReturnStatusLCAType BinaryTree_FindLCA_textbookalgo(BTNodeT* root, 
        BTNodeT* node1, 
        BTNodeT* node2);
  
  ull BinaryTree_SumUpRootToLeafPaths_Wrapper(BTNodeT* root);
  ull BinaryTree_SumUpRootToLeafPaths(BTNodeT* node, ull prev_sum);
  void BinaryTree_SumUpRootToLeafPaths_WithBuffer(BTNodeT* node, ull *sum,
        ull *buffer, int depth);
  
  bool BinaryTree_LeafWithGivenPathWeightExists(BTNodeT* root, int target_weight);
    
  void BinaryTree_InOrderTraversalWithoutRecursion(BTNodeT* root);
  void BinaryTree_PreOrderTraversalWithoutRecursion(BTNodeT* node);
  
  BTNodeWithParentT* BinaryTree_GetInOrderSuccessor_NodesWithParent(BTNodeWithParentT* target);
  BTNodeWithParentT* FirstInOrderNode(BTNodeWithParentT* node);  
  BTNodeWithParentT* FirstUnprocessedInOrderParent(BTNodeWithParentT* node);
  
  void BinaryTree_PrintInOrderNodesWithParentWithoutRecursion(BTNodeWithParentT* node);
  
  BTType BinaryTree_ConstructFromInAndPreOrderSequences_Wrapper(int* inorder,
        int* preorder, int n);
  void BinaryTree_ConstructFromInAndPreOrderSequences(BTType* bt, BTNodeT* parent,
        int* inorder, int* preorder, int n);
  int FindIdxInSequence(int* keys, int target, int n);
  
  BTType BinaryTree_ConstructFromPreOrderSequenceWithNulls_Wrapper(int* preorder);
  void BinaryTree_ConstructFromPreOrderSequenceWithNulls(BTType* bt, BTNodeT* parent,
        int* preorder, int* i_curr);
  
  BTNodeT** BinaryTree_GetLeaves(BTNodeT* node, BTNodeT** leaves, int* n_leaves);
  
  BTNodeT** BinaryTree_GetExterior(BTNodeT* node, int* n_nodes);
  BTNodeT** BinaryTree_GetLeftBoundary(BTNodeT* node, int* n_nodes);
  BTNodeT** BinaryTree_GetRghtBoundary(BTNodeT* node, int* n_nodes);
  
  void BinaryTree_NodesWithNextInLevelPointerFill_Wrapper(BTNodeWithParentT* root);
  void BinaryTree_NodesWithNextInLevelPointerFill(BTNodeWithParentT* left, 
        BTNodeWithParentT* rght, BTNodeWithParentT* siblings_left);
  
  
#ifdef __cplusplus
}
#endif

#endif /* BINARYTREE_H */

