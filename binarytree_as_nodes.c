/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * The basic idea for many algorithms is that each position in a binary tree
 * is uniquely specified by an index.
 *   
 *                          0                                 Level 0
 *             1                          2                   Level 1
 *       3            4            5             6            Level 2
 *    7     8       9   10      11   12      13     14        Level 3
 * 
 * A height k BT has slots for  2^(k+1)-1 nodes, e.g. height 3: 2^4-1 = 15 slots.
 * 
 * --> this indexing gives a unique adress to every node
 *     in a tree
 * 
 * Alternativelly, one could specify the position of a node uniquely
 * by two numbers, i.e. the level and the distance from the leftmost node
 * in that level.
 * 
 *                                (0,0)                                Level 0
 *                (1,0)                            (1,1)               Level 1
 *       (2,0)             (2,1)           (2,2)           (2,3)       Level 2
 *  (3,0)     (3,1)   (3,2)    (3,3)   (3,4)   (3,5)   (3,6)    (3,7)  Level 3
 * 
 * 
*/


#include "binarytree_as_nodes.h"

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <math.h>

#include "standardheaders.h"
#include "arrays.h"
#include "utils.h"

void MainBinaryTreeAsNodes() {
  printf("\n\n----------------------- MainBinaryTree \n");
    
  //-----------------------------------------
  // preparations:
  
  //-----------------------------------------
  // Exercises    

  MainBinaryTree_API();  
  
  MainBinaryTree_InsertNodeSmallestFreeIndex();
  
  MainBinaryTree_FindPathToNode();
  
  MainBinaryTree_CheckHeightBalanced();  
  
  MainBinaryTree_CheckSymmetric();  
  
  MainBinaryTree_FindLCA();
  
  MainBinaryTree_SumUpRootToLeafPaths();
  
  MainBinaryTree_LeafWithGivenPathWeightExists();
  
  MainBinaryTree_InOrderTraversalWithoutRecursion();
  
  MainBinaryTree_PreOrderTraversalWithoutRecursion();  
  
  MainBinaryTree_InOrderSuccessorNodesWithParent();
  
  MainBinaryTree_InOrderTraversalNodesWithParentWithoutRecursion();
  
  MainBinaryTree_ConstructBTFromInAndPreOrderSequences();

  MainBinaryTree_ConstructBTFromPreOrderSequenceWithNulls();

  MainBinaryTree_GetLeaves();
  
  MainBinaryTree_GetExterior();
  
  MainBinaryTree_NodesWithNextInLevelPointerFill();
  
  return;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
  
void MainBinaryTree_API() {
  printf("\n----------------------------------- MainBinaryTree_API \n"); 
      
  // create a binary tree from the pool of nodes  
  BTType bt = { 0 };
  BTNodeT* node0 = BinaryTree_Init(&bt, 0, -42);
  BTNodeT* node1 = BinaryTree_InsertAtNodeAsLeft(&bt, node0, 1, -42);
  BTNodeT* node2 = BinaryTree_InsertAtNodeAsRght(&bt, node0, 2, -42);
  BTNodeT* node3 = BinaryTree_InsertAtNodeAsLeft(&bt, node1, 3, -42);
  BTNodeT* node4 = BinaryTree_InsertAtNodeAsRght(&bt, node1, 4, -42);  
  BTNodeT* node5 = BinaryTree_InsertAtNodeAsLeft(&bt, node2, 5, -42);
  BTNodeT* node6 = BinaryTree_InsertAtNodeAsRght(&bt, node2, 6, -42);
  BTNodeT* node7 = BinaryTree_InsertAtNodeAsLeft(&bt, node3, 7, -42);  
  
  // Traversals
  printf("Traversal Tests: \n\n");
  
  printf("Inorder traversal gives: \n");
  BinaryTree_PrintInOrder(&bt);
  printf("\n");
  
  printf("Preorder traversal gives: \n");
  BinaryTree_PrintPreOrder(&bt);
  printf("\n");
  
  printf("Postorder traversal gives: \n");
  BinaryTree_PrintPostOrder(&bt);
  printf("\n");
  
  // Get height of the tree  
  printf("\n");
  printf("Height of the tree\n");
  int height_of_tree = BinaryTree_Height(bt.root);
  printf("The algorithm found height = %i \n", height_of_tree);
  
  BinaryTree_Destroy(&bt);
  return;
}

void MainBinaryTree_InsertNodeSmallestFreeIndex() {
  printf("\n----------------------------------- MainBinaryTree_InsertNodeSmallestFreeIndex \n");
    
  // create a binary tree from the pool of nodes  
  BTType bt = { 0 };
  BTNodeT* node0 = BinaryTree_Init(&bt, 0, -42);
  BTNodeT* node1 = BinaryTree_InsertAtNodeAsLeft(&bt, node0, 1, -42);
  BTNodeT* node2 = BinaryTree_InsertAtNodeAsRght(&bt, node0, 2, -42);
  BTNodeT* node3 = BinaryTree_InsertAtNodeAsLeft(&bt, node1, 3, -42);
  BTNodeT* node4 = BinaryTree_InsertAtNodeAsRght(&bt, node1, 4, -42);  
  BTNodeT* node5 = BinaryTree_InsertAtNodeAsLeft(&bt, node2, 5, -42);
  BTNodeT* node6 = BinaryTree_InsertAtNodeAsRght(&bt, node2, 6, -42);
  
  // Print constructed tree
  printf("Doing excercise on a tree that reads in-order \n");  
  BinaryTree_PrintInOrder(&bt);
  
  // test insertion
  BinaryTree_InsertNodeAtSmallestFreeIndex(&bt, 7, -42);
  
  // Print constructed tree
  printf("After insertion at smallest free index the tree reads in in-order \n");  
  BinaryTree_PrintInOrder(&bt);
  printf("\n");
  
  BinaryTree_Destroy(&bt);
  return;
}


void MainBinaryTree_FindPathToNode() {
  printf("\n----------------------------------- MainBinaryTree_FindPathToNode \n"); 
  
  // create a binary tree from the pool of nodes 
  BTType bt = { 0 };
  BTNodeT* node0 = BinaryTree_Init(&bt, 0, -42);
  BTNodeT* node1 = BinaryTree_InsertAtNodeAsLeft(&bt, node0, 1, -42);
  BTNodeT* node2 = BinaryTree_InsertAtNodeAsRght(&bt, node0, 2, -42);
  BTNodeT* node3 = BinaryTree_InsertAtNodeAsLeft(&bt, node1, 3, -42);
  BTNodeT* node4 = BinaryTree_InsertAtNodeAsRght(&bt, node1, 4, -42);  
  BTNodeT* node5 = BinaryTree_InsertAtNodeAsLeft(&bt, node2, 5, -42);
  BTNodeT* node6 = BinaryTree_InsertAtNodeAsRght(&bt, node2, 6, -42);
  BTNodeT* node13 = BinaryTree_InsertAtNodeAsLeft(&bt, node6, 13, -42);  
  
  // Print constructed tree
  printf("Doing excercise on a tree that reads in-order \n");  
  BinaryTree_PrintInOrder(&bt);
  printf("\n");

  // find path to a node  
  printf("Find path to node with data %i: \n", node6->key);
  int height_of_tree = BinaryTree_Height(bt.root);
  int rightturns[height_of_tree]; // --> 0: for left turn, 1: for right turn
  memset(rightturns, -1, sizeof(rightturns));
  int flag_node_was_found = false;
  BinaryTree_PathToNode(bt.root, node6, rightturns, &flag_node_was_found, 0);    
  PrintArray1d(rightturns, height_of_tree);
  
  // find path to a node
  printf("Find path to node with data %i: \n", node13->key);
  flag_node_was_found = false;
  memset(rightturns, -1, sizeof(rightturns));
  BinaryTree_PathToNode(bt.root, node13, rightturns, &flag_node_was_found, 0);  
  PrintArray1d(rightturns, height_of_tree);    
  
  BinaryTree_Destroy(&bt);
  return;
}

void MainBinaryTree_CheckHeightBalanced() {
  printf("\n----------------------------------- MainBinaryTree_CheckHeightBalanced \n"); 
  
  // create a binary tree from the pool of nodes  
  BTType bt = { 0 };
  BTNodeT* node0 = BinaryTree_Init(&bt, 0, -42);
  BTNodeT* node1 = BinaryTree_InsertAtNodeAsLeft(&bt, node0, 1, -42);
  BTNodeT* node2 = BinaryTree_InsertAtNodeAsRght(&bt, node0, 2, -42);
  BTNodeT* node3 = BinaryTree_InsertAtNodeAsLeft(&bt, node1, 3, -42);
  BTNodeT* node4 = BinaryTree_InsertAtNodeAsRght(&bt, node1, 4, -42);  
  BTNodeT* node5 = BinaryTree_InsertAtNodeAsLeft(&bt, node2, 5, -42);
  BTNodeT* node6 = BinaryTree_InsertAtNodeAsRght(&bt, node2, 6, -42);
  
  // Print constructed tree
  printf("Doing excercise on a tree that reads in-order \n");  
  BinaryTree_PrintInOrder(&bt);
  printf("\n");
  
  // Check Tree is height balanced
  bool isbalanced = true;
  int height = BinaryTree_ComputeHeightAndCheckBalance(bt.root, &isbalanced);  
  printf("Binary tree was found to be%s height balanced.\n\n", (isbalanced ? "" : " not"));
  
  // modify tree
  BTNodeT* node7 = BinaryTree_InsertAtNodeAsLeft(&bt, node3, 7, -42);
  BTNodeT* node16 = BinaryTree_InsertAtNodeAsRght(&bt, node7, 16, -42);
  printf("Inserted two other nodes that should destroy balance.\n");
  isbalanced = false;
  height = BinaryTree_ComputeHeightAndCheckBalance(bt.root, &isbalanced);  
  printf("Binary tree was found to be%s height balanced.\n", 
          (isbalanced ? "" : " not"));
  
  BinaryTree_Destroy(&bt);
  return;
}

void MainBinaryTree_CheckSymmetric() {
  printf("\n----------------------------------- MainBinaryTree_CheckSymmetric \n");  
  
  // create a binary tree from the pool of nodes  
  BTType bt = { 0 };
  BTNodeT* node0 = BinaryTree_Init(&bt, 0, -42);
  BTNodeT* node1 = BinaryTree_InsertAtNodeAsLeft(&bt, node0, 1, -42);
  BTNodeT* node2 = BinaryTree_InsertAtNodeAsRght(&bt, node0, 1, -42);
  BTNodeT* node3 = BinaryTree_InsertAtNodeAsLeft(&bt, node1, 3, -42);
  BTNodeT* node4 = BinaryTree_InsertAtNodeAsRght(&bt, node1, 4, -42);  
  BTNodeT* node5 = BinaryTree_InsertAtNodeAsLeft(&bt, node2, 4, -42);
  BTNodeT* node6 = BinaryTree_InsertAtNodeAsRght(&bt, node2, 3, -42);
  
  // Print constructed tree
  printf("Doing excercise on a tree that reads in-order \n");  
  BinaryTree_PrintInOrder(&bt);
  printf("\n");
  
  // Check Tree is height balanced
  bool is_symmetric = BinaryTree_IsSymmetric_Wrapper(bt.root);  
  printf("Binary tree was found to be%s mirror-symmetric.\n\n", 
          (is_symmetric ? "" : " not"));
  
  BinaryTree_Destroy(&bt);
  return;
}


void MainBinaryTree_FindLCA() {
  printf("\n----------------------------------- MainBinaryTree_FindLCA \n"); 
  
  // create a binary tree from the pool of nodes  
  BTType bt = { 0 };
  BTNodeT* node0 = BinaryTree_Init(&bt, 0, -42);
  BTNodeT* node1 = BinaryTree_InsertAtNodeAsLeft(&bt, node0, 1, -42);
  BTNodeT* node2 = BinaryTree_InsertAtNodeAsRght(&bt, node0, 2, -42);
  BTNodeT* node3 = BinaryTree_InsertAtNodeAsLeft(&bt, node1, 3, -42);
  BTNodeT* node4 = BinaryTree_InsertAtNodeAsRght(&bt, node1, 4, -42);  
  BTNodeT* node5 = BinaryTree_InsertAtNodeAsLeft(&bt, node2, 5, -42);
  BTNodeT* node6 = BinaryTree_InsertAtNodeAsRght(&bt, node2, 6, -42);
  BTNodeT* node13 = BinaryTree_InsertAtNodeAsLeft(&bt, node6, 13, -42);
    
  // Print constructed tree
  printf("Doing excercise on a tree that reads in-order \n");  
  BinaryTree_PrintInOrder(&bt);
  printf("\n");
  
  // Find LCA of two nodes  
  printf("Find LCA of nodes with data %i and %i \n", node5->key, node6->key);  
  BTNodeT* LCA_ptr = NULL;
  BinaryTree_FindLCA(bt.root, node5, node6, &LCA_ptr);  
  printf("LCA is node with data %i \n", LCA_ptr->key);
  printf("\n");
  
  // Find LCA using different algo
  ReturnStatusLCAType status = BinaryTree_FindLCA_textbookalgo(bt.root, 
          node5, node6);
  printf("Alternative method found LCA at node with %i \n", 
          status.ptr_to_LCA->key);  
  
  BinaryTree_Destroy(&bt);
  return;
}

void MainBinaryTree_SumUpRootToLeafPaths() {
  printf("\n----------------------------------- MainBinaryTree_SumUpRootToLeafPaths \n"); 
  
  // create a binary tree from the pool of nodes: with only 0, 1 data  
  BTType bt = { 0 };
  BTNodeT* node0 = BinaryTree_Init(&bt, 1, -42);  // MSB
  BTNodeT* node1 = BinaryTree_InsertAtNodeAsLeft(&bt, node0, 0, -42);
  BTNodeT* node2 = BinaryTree_InsertAtNodeAsRght(&bt, node0, 1, -42);
  BTNodeT* node3 = BinaryTree_InsertAtNodeAsLeft(&bt, node1, 1, -42);
  BTNodeT* node4 = BinaryTree_InsertAtNodeAsRght(&bt, node1, 1, -42);  
  BTNodeT* node5 = BinaryTree_InsertAtNodeAsLeft(&bt, node2, 0, -42);
  BTNodeT* node6 = BinaryTree_InsertAtNodeAsRght(&bt, node2, 1, -42);
  BTNodeT* node13 = BinaryTree_InsertAtNodeAsLeft(&bt, node6, 0, -42);
  /*
   *                            1
   *                  0                    1
   *            1         1            0       1
   *                                         0
   * 
   *  so we have leaves representing the following summands:
   *  5
   *  5
   *  6
   *  14
   *  sum = 30
   */
  
  // Print constructed tree
  printf("Doing excercise on a tree that reads in-order \n");  
  BinaryTree_PrintInOrder(&bt);
  printf("\n");
  
  // Compute Sums of the digit-sequences from root to leaves and add them up
  ull sum = BinaryTree_SumUpRootToLeafPaths_Wrapper(bt.root);
  printf("Found sum of root-leaf paths: %llu \n", sum);
  
  BinaryTree_Destroy(&bt);
  return;
}

void MainBinaryTree_LeafWithGivenPathWeightExists() {
  printf("\n----------------------------------- MainBinaryTree_FindLeafWithGivenPathWeight \n"); 
    
  // create a binary tree from the pool of nodes  
  BTType bt = { 0 };
  BTNodeT* node0 = BinaryTree_Init(&bt, 0, -42);
  BTNodeT* node1 = BinaryTree_InsertAtNodeAsLeft(&bt, node0, 1, -42);
  BTNodeT* node2 = BinaryTree_InsertAtNodeAsRght(&bt, node0, 2, -42);
  BTNodeT* node3 = BinaryTree_InsertAtNodeAsLeft(&bt, node1, 3, -42);
  BTNodeT* node4 = BinaryTree_InsertAtNodeAsRght(&bt, node1, 4, -42);  
  BTNodeT* node5 = BinaryTree_InsertAtNodeAsLeft(&bt, node2, 5, -42);
  BTNodeT* node6 = BinaryTree_InsertAtNodeAsRght(&bt, node2, 6, -42);
  BTNodeT* node7 = BinaryTree_InsertAtNodeAsLeft(&bt, node3, 7, -42);
  
  // Print constructed tree
  printf("Doing excercise on a tree that reads in-order \n");  
  BinaryTree_PrintInOrder(&bt);
  printf("\n");
  
  // check if a leaf with given path-weight exists
  int target_pathweight = 6; // 5 exists
  bool leaf_exists = BinaryTree_LeafWithGivenPathWeightExists(bt.root, 
          target_pathweight);
  printf("Leaf with path-weight %i does%s exist in tree.\n\n", target_pathweight,
          (leaf_exists ? "" : " not"));  
  
  BinaryTree_Destroy(&bt);
  return;
}

void MainBinaryTree_InOrderTraversalWithoutRecursion() {
  printf("\n----------------------------------- MainBinaryTree_InOrderTraversalWithoutRecursion \n"); 
    
  // create a binary tree from the pool of nodes  
  BTType bt = { 0 };
  BTNodeT* node0 = BinaryTree_Init(&bt, 0, -42);
  BTNodeT* node1 = BinaryTree_InsertAtNodeAsLeft(&bt, node0, 1, -42);
  BTNodeT* node2 = BinaryTree_InsertAtNodeAsRght(&bt, node0, 2, -42);
  BTNodeT* node3 = BinaryTree_InsertAtNodeAsLeft(&bt, node1, 3, -42);
  BTNodeT* node4 = BinaryTree_InsertAtNodeAsRght(&bt, node1, 4, -42);  
  BTNodeT* node5 = BinaryTree_InsertAtNodeAsLeft(&bt, node2, 5, -42);
  BTNodeT* node6 = BinaryTree_InsertAtNodeAsRght(&bt, node2, 6, -42);
  BTNodeT* node7 = BinaryTree_InsertAtNodeAsLeft(&bt, node3, 7, -42);
    
  // Print constructed tree
  printf("Doing excercise on a tree that reads in-order \n");  
  BinaryTree_PrintInOrder(&bt);
  printf("\n");
  
  // Print traversal without recursion
  printf("In-Order traversal without recursion reads \n");  
  BinaryTree_InOrderTraversalWithoutRecursion(bt.root);
  printf("\n");

  BinaryTree_Destroy(&bt);
  return;
}

void MainBinaryTree_PreOrderTraversalWithoutRecursion() {  
  printf("\n----------------------------------- MainBinaryTree_PreOrderTraversalWithoutRecursion \n"); 
    
  // create a binary tree from the pool of nodes  
  BTType bt = { 0 };
  BTNodeT* node0 = BinaryTree_Init(&bt, 0, -42);
  BTNodeT* node1 = BinaryTree_InsertAtNodeAsLeft(&bt, node0, 1, -42);
  BTNodeT* node2 = BinaryTree_InsertAtNodeAsRght(&bt, node0, 2, -42);
  BTNodeT* node3 = BinaryTree_InsertAtNodeAsLeft(&bt, node1, 3, -42);
  BTNodeT* node4 = BinaryTree_InsertAtNodeAsRght(&bt, node1, 4, -42);  
  BTNodeT* node5 = BinaryTree_InsertAtNodeAsLeft(&bt, node2, 5, -42);
  BTNodeT* node6 = BinaryTree_InsertAtNodeAsRght(&bt, node2, 6, -42);
  BTNodeT* node7 = BinaryTree_InsertAtNodeAsLeft(&bt, node3, 7, -42);
    
  // Print constructed tree
  printf("Doing excercise on a tree that reads pre-order \n");  
  BinaryTree_PrintPreOrder(&bt);
  printf("\n");
  
  // Print traversal without recursion
  printf("Pre-Order traversal without recursion reads \n");  
  BinaryTree_PreOrderTraversalWithoutRecursion(bt.root);
  printf("\n");

  BinaryTree_Destroy(&bt);
  return;
}

void MainBinaryTree_InOrderSuccessorNodesWithParent() {
  printf("\n----------------------------------- MainBinaryTree_InOrderSuccessorNodesWithParent \n");
    
  // create a binary tree from the pool of nodes  
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
  BinaryTree_WithParent_PrintSequenceInOrder(node0);
  printf("\n");
  
  // Find the inorder successor of a node
  BTNodeWithParentT* target = node2;
  BTNodeWithParentT* successor = BinaryTree_GetInOrderSuccessor_NodesWithParent(target);
  printf("Found that successor of %i is %i \n", target->key, 
          (successor ? successor->key : -42));
  
  BinaryTree_WithParent_Destroy(&bt);
  return;
}

void MainBinaryTree_InOrderTraversalNodesWithParentWithoutRecursion() {  
  printf("\n----------------------------------- MainBinaryTree_InOrderTraversalNodesWithParentWithoutRecursion \n");
    
  // create a binary tree from the pool of nodes  
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
  BinaryTree_WithParent_PrintSequenceInOrder(node0);
  printf("\n");
  
  // Print In-order without recursion using parent pointer
  printf("Non-recursive Algorithm for inorder that uses parent-pointer:\n");
  BinaryTree_PrintInOrderNodesWithParentWithoutRecursion(node0);
  printf("\n");
  
  BinaryTree_WithParent_Destroy(&bt);
  return;
}

void MainBinaryTree_ConstructBTFromInAndPreOrderSequences() {
  printf("\n----------------------------------- MainBinaryTree_ConstructBTFromInAndPreOrderSequences \n");
  
  // create a binary tree from the pool of nodes    
  BTType bt = { 0 };
  BTNodeT* node0 = BinaryTree_Init(&bt, 0, -42);
  BTNodeT* node1 = BinaryTree_InsertAtNodeAsLeft(&bt, node0, 1, -42);
  BTNodeT* node2 = BinaryTree_InsertAtNodeAsRght(&bt, node0, 2, -42);
  BTNodeT* node3 = BinaryTree_InsertAtNodeAsLeft(&bt, node1, 3, -42);
  BTNodeT* node4 = BinaryTree_InsertAtNodeAsRght(&bt, node1, 4, -42);  
  BTNodeT* node5 = BinaryTree_InsertAtNodeAsLeft(&bt, node2, 5, -42);
  BTNodeT* node6 = BinaryTree_InsertAtNodeAsRght(&bt, node2, 6, -42);
  BTNodeT* node13 = BinaryTree_InsertAtNodeAsLeft(&bt, node6, 13, -42);
    
/*
 * // equivalent old version: passing the global by reference instead of
 * // resetting by return value. just kept it here to remember that here was
 * // a lot of fight with a memory leak
  BTNodeT** nodes_inorder = NULL;
  BinaryTree_GetSequenceInOrder_VOID(&node0, &nodes_inorder, &n_nodes_in);
*/
  
  int n_nodes_in = 0;
  int* keys_inorder = BinaryTree_GetSequenceInOrder(node0, NULL, &n_nodes_in); 
  
  int n_nodes_pre = 0;
  int* keys_preorder = BinaryTree_GetSequencePreOrder(node0, NULL, &n_nodes_pre);  
  
  // Print sequences
  printf("Doing excercise on a tree that reads in-order \n");  
  int i;
  for (i = 0; i < n_nodes_in; ++i) {
    printf("InOrder[%i] = %i \n", i, keys_inorder[i]);
  }
  printf("\n");
  printf("Doing excercise on a tree that reads pre-order \n");  
  for (i = 0; i < n_nodes_pre; ++i) {
    printf("InOrder[%i] = %i \n", i, keys_preorder[i]);
  }
  printf("\n");
  
  // Now dissemble the tree and reconstruct it from the traversal data
  printf(".. re-constructing the BT from the sequences.\n\n");  
  BinaryTree_Destroy(&bt);
  bt = BinaryTree_ConstructFromInAndPreOrderSequences_Wrapper(keys_inorder, 
          keys_preorder, n_nodes_in);
  
  // check result
  printf("InOrder Result after reconstruction: \n");
  BinaryTree_PrintInOrder(&bt);
  
  // free and reset
  free(keys_inorder);
  free(keys_preorder);  
  BinaryTree_Destroy(&bt);
  return;
}

void MainBinaryTree_ConstructBTFromPreOrderSequenceWithNulls() {  
  printf("\n----------------------------------- MainBinaryTree_ConstructBTFromPreOrderSequenceWithNulls \n");
  
  // create a binary tree from the pool of nodes   
  BTType bt = { 0 };
  BTNodeT* node0 = BinaryTree_Init(&bt, 0, -42);
  BTNodeT* node1 = BinaryTree_InsertAtNodeAsLeft(&bt, node0, 1, -42);
  BTNodeT* node2 = BinaryTree_InsertAtNodeAsRght(&bt, node0, 2, -42);
  BTNodeT* node3 = BinaryTree_InsertAtNodeAsLeft(&bt, node1, 3, -42);
  BTNodeT* node4 = BinaryTree_InsertAtNodeAsRght(&bt, node1, 4, -42);  
  BTNodeT* node5 = BinaryTree_InsertAtNodeAsLeft(&bt, node2, 5, -42);
  BTNodeT* node6 = BinaryTree_InsertAtNodeAsRght(&bt, node2, 6, -42);
  BTNodeT* node13 = BinaryTree_InsertAtNodeAsLeft(&bt, node6, 13, -42);
  
  int n_slots = 0;
  int* keys_preorder_withnulls = BinaryTree_GetSequencePreOrderWithNulls(
          node0, NULL, &n_slots);  
  
  // print sequence
  int i = 0;
  printf("Doing excercise on a tree that reads pre-order \n");  
  for (i = 0; i < n_slots; ++i) {
    printf("InOrder[%i] = %i \n", i, keys_preorder_withnulls[i]);
  }
  printf("\n");
  
  // Now dissemble the tree and reconstruct it from the traversal data
  printf(".. re-constructing the BT from the sequence.\n\n");
  BinaryTree_Destroy(&bt);    
  bt = BinaryTree_ConstructFromPreOrderSequenceWithNulls_Wrapper(
          keys_preorder_withnulls);
  
  // check result
  printf("InOrder Result after reconstruction: \n");
  BinaryTree_PrintInOrder(&bt);
  
  // free and reset  
  free(keys_preorder_withnulls);  
  BinaryTree_Destroy(&bt);
  return;
}

void MainBinaryTree_GetLeaves() {
  printf("\n----------------------------------- MainBinaryTree_GetLeaves \n");
  
  // create a binary tree from the pool of nodes      
  BTType bt = { 0 };
  BTNodeT* node0 = BinaryTree_Init(&bt, 0, -42);
  BTNodeT* node1 = BinaryTree_InsertAtNodeAsLeft(&bt, node0, 1, -42);
  BTNodeT* node2 = BinaryTree_InsertAtNodeAsRght(&bt, node0, 2, -42);
  BTNodeT* node3 = BinaryTree_InsertAtNodeAsLeft(&bt, node1, 3, -42);
  BTNodeT* node4 = BinaryTree_InsertAtNodeAsRght(&bt, node1, 4, -42);  
  BTNodeT* node5 = BinaryTree_InsertAtNodeAsLeft(&bt, node2, 5, -42);
  BTNodeT* node6 = BinaryTree_InsertAtNodeAsRght(&bt, node2, 6, -42);
  BTNodeT* node13 = BinaryTree_InsertAtNodeAsLeft(&bt, node6, 13, -42);
  
  // Print constructed tree
  printf("Doing excercise on a tree that reads in-order \n");  
  BinaryTree_PrintInOrder(&bt);
  printf("\n");
  
  // compute leaves
  BTNodeT** leaves = calloc(0, sizeof(BTNodeT*));
  int n_leaves = 0;
  leaves = BinaryTree_GetLeaves(node0, leaves, &n_leaves);
  
  // print result
  printf("BT has leaves from left-to-right:\n");
  int i;
  for (i = 0; i < n_leaves; ++i) {    
    printf("Leaf: %i \n", leaves[i]->key);
  }
  
  // free
  free(leaves);
  BinaryTree_Destroy(&bt);
  return;
}

void MainBinaryTree_GetExterior() {
  printf("\n----------------------------------- MainBinaryTree_GetExterior \n");
  
  // create a binary tree from the pool of nodes
  /**
   * 
   *                                    0
   *                        1                         2
   *             3                4             5           6
   *                  8         9     10           12
   */  
  BTType bt = { 0 };
  BTNodeT* node0 = BinaryTree_Init(&bt, 0, -42);
  BTNodeT* node1 = BinaryTree_InsertAtNodeAsLeft(&bt, node0, 1, -42);
  BTNodeT* node2 = BinaryTree_InsertAtNodeAsRght(&bt, node0, 2, -42);
  BTNodeT* node3 = BinaryTree_InsertAtNodeAsLeft(&bt, node1, 3, -42);
  BTNodeT* node4 = BinaryTree_InsertAtNodeAsRght(&bt, node1, 4, -42);  
  BTNodeT* node5 = BinaryTree_InsertAtNodeAsLeft(&bt, node2, 5, -42);
  BTNodeT* node6 = BinaryTree_InsertAtNodeAsRght(&bt, node2, 6, -42);
  BTNodeT* node8 = BinaryTree_InsertAtNodeAsRght(&bt, node3, 8, -42);
  BTNodeT* node9 = BinaryTree_InsertAtNodeAsLeft(&bt, node4, 9, -42);
  BTNodeT* node10 = BinaryTree_InsertAtNodeAsRght(&bt, node4, 10, -42);
  BTNodeT* node12 = BinaryTree_InsertAtNodeAsRght(&bt, node5, 12, -42);
  
  // Print constructed tree
  printf("Doing excercise on a tree that reads in-order \n");  
  BinaryTree_PrintInOrder(&bt);
  printf("\n");
  
  // compute exterior
  int n_nodes = 0;
  BTNodeT** exterior = BinaryTree_GetExterior(node0, &n_nodes);
  
  // print result
  printf("BT has exterior (top-to-left-bottom to right-bottom to top):\n");
  int i;
  for (i = 0; i < n_nodes; ++i) {    
    printf("Exterior-node: %i \n", exterior[i]->key);
  }
  
  // free
  free(exterior);
  BinaryTree_Destroy(&bt);
  return;
}

void MainBinaryTree_NodesWithNextInLevelPointerFill() {
  printf("\n----------------------------------- MainBinaryTree_NodesWithNextInLevelPointerFill \n");
  
  // create PERFECT binary tree
  // ACHTUNG: MISUSE parent pointer as next in level pointer here  
  BTWithParentsType bt = { 0 };
  BTNodeWithParentT* node0 = BinaryTree_WithParent_Init(&bt, 0, -42);
  BTNodeWithParentT* node1 = BinaryTree_WithParent_InsertAtNodeAsLeft(node0, 1, -42);
  BTNodeWithParentT* node2 = BinaryTree_WithParent_InsertAtNodeAsRght(node0, 2, -42);
  BTNodeWithParentT* node3 = BinaryTree_WithParent_InsertAtNodeAsLeft(node1, 3, -42);
  BTNodeWithParentT* node4 = BinaryTree_WithParent_InsertAtNodeAsRght(node1, 4, -42);  
  BTNodeWithParentT* node5 = BinaryTree_WithParent_InsertAtNodeAsLeft(node2, 5, -42);
  BTNodeWithParentT* node6 = BinaryTree_WithParent_InsertAtNodeAsRght(node2, 6, -42);  
  BTNodeWithParentT* node7 = BinaryTree_WithParent_InsertAtNodeAsLeft(node3, 7, -42);
  BTNodeWithParentT* node8 = BinaryTree_WithParent_InsertAtNodeAsRght(node3, 8, -42);  
  BTNodeWithParentT* node9 = BinaryTree_WithParent_InsertAtNodeAsLeft(node4, 9, -42);
  BTNodeWithParentT* node10 = BinaryTree_WithParent_InsertAtNodeAsRght(node4, 10, -42);  
  BTNodeWithParentT* node11 = BinaryTree_WithParent_InsertAtNodeAsLeft(node5, 11, -42);
  BTNodeWithParentT* node12 = BinaryTree_WithParent_InsertAtNodeAsRght(node5, 12, -42);  
  BTNodeWithParentT* node13 = BinaryTree_WithParent_InsertAtNodeAsLeft(node6, 13, -42);
  BTNodeWithParentT* node14 = BinaryTree_WithParent_InsertAtNodeAsRght(node6, 14, -42);
  
  // Print constructed tree
  printf("Doing excercise on a tree that reads in-order \n");  
  BinaryTree_WithParent_PrintSequenceInOrder(node0);
  printf("\n");
  
  // fill next in level pointer
  BinaryTree_NodesWithNextInLevelPointerFill_Wrapper(node0);
  
  // print result
  printf("After filling next in level pointer \n");  
  BinaryTree_WithParent_PrintSequenceInOrder(node0);
  printf("\n");
  
  // free
  BinaryTree_WithParent_Destroy(&bt);
  return;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//------------------------------- Binary Tree API

// wrapper for the recursion 
void BinaryTree_PrintInOrder(BTType* bt) {
  BinaryTree_PrintInOrderRecursion(bt->root);  
  return;
}
void BinaryTree_PrintInOrderRecursion(BTNodeT* node) {   
  if (node->left) {
    BinaryTree_PrintInOrderRecursion(node->left);  
  }  
  printf("Node-data: %i \n", node->key);
  if (node->rght) {
    BinaryTree_PrintInOrderRecursion(node->rght);  
  }
  return;
}
int* BinaryTree_GetSequenceInOrder(BTNodeT* node, int* sequence, int* n_nodes) {
  if (node) {
    sequence = BinaryTree_GetSequenceInOrder(node->left, sequence, n_nodes);
    ++(*n_nodes);
    sequence = realloc(sequence, (*n_nodes) * sizeof(int));
    sequence[(*n_nodes) - 1] = node->key;  
    sequence = BinaryTree_GetSequenceInOrder(node->rght, sequence, n_nodes);
  }
  return sequence;
}
// Equivalent old version that works directly on the global
// --> kept here as a reminder how that works
void BinaryTree_GetSequenceInOrder_VOID(BTNodeT* node, BTNodeT*** sequence, int* n_nodes) {
  if (node) {
    BinaryTree_GetSequenceInOrder_VOID(node->left, sequence, n_nodes);
    ++(*n_nodes);
    *sequence = realloc(*sequence, (*n_nodes) * sizeof(BTNodeT*));
    (*sequence)[(*n_nodes) - 1] = node;  
    BinaryTree_GetSequenceInOrder_VOID(node->rght, sequence, n_nodes);
  }
}

// wrapper for the recursion 
void BinaryTree_PrintPreOrder(BTType* bt) {    
  BinaryTree_PrintPreOrderRecursion(bt->root);  
  return;
}
void BinaryTree_PrintPreOrderRecursion(BTNodeT* bt_node) { 
  // root
  printf("Node-data: %i \n", bt_node->key);  
  // traverse left tree
  if (bt_node->left) {
    BinaryTree_PrintPreOrderRecursion(bt_node->left);  
  }
  // traverse rght tree
  if (bt_node->rght) {
    BinaryTree_PrintPreOrderRecursion(bt_node->rght);  
  }
  return;
}
int* BinaryTree_GetSequencePreOrder(BTNodeT* node, int* sequence, int* n_nodes) {
  if (node) {
    ++(*n_nodes);
    sequence = realloc(sequence, (*n_nodes) * sizeof(int));
    sequence[(*n_nodes) - 1] = node->key;    
    sequence = BinaryTree_GetSequencePreOrder(node->left, sequence, n_nodes);  
    sequence = BinaryTree_GetSequencePreOrder(node->rght, sequence, n_nodes); 
  }
  return sequence;
}
int* BinaryTree_GetSequencePreOrderWithNulls(BTNodeT* node, 
        int* sequence, int* n_nodes) {
  ++(*n_nodes);
  sequence = realloc(sequence, (*n_nodes) * sizeof(int));
  sequence[(*n_nodes) - 1] = (node ? node->key : -1);
  if (node) {    
    sequence = BinaryTree_GetSequencePreOrderWithNulls(node->left, sequence, n_nodes);  
    sequence = BinaryTree_GetSequencePreOrderWithNulls(node->rght, sequence, n_nodes); 
  }
  return sequence;
}


// wrapper for the recursion 
void BinaryTree_PrintPostOrder(BTType* bt) {    
  BinaryTree_PrintPostOrderRecursion(bt->root);  
  return;
}
void BinaryTree_PrintPostOrderRecursion(BTNodeT* bt_node) { 
  // traverse left tree
  if (bt_node->left) {
    BinaryTree_PrintPostOrderRecursion(bt_node->left);  
  }
  // traverse rght tree
  if (bt_node->rght) {
    BinaryTree_PrintPostOrderRecursion(bt_node->rght);  
  }
  // root
  printf("Node-data: %i \n", bt_node->key);  
  return;
}
int* BinaryTree_GetSequencePostOrder(BTNodeT* node, int* sequence, int* n_nodes) {
  if (node) {
    sequence = BinaryTree_GetSequencePostOrder(node->left, sequence, n_nodes);  
    sequence = BinaryTree_GetSequencePostOrder(node->rght, sequence, n_nodes); 
    ++(*n_nodes);
    sequence = realloc(sequence, (*n_nodes) * sizeof(int));
    sequence[(*n_nodes) - 1] = node->key;    
  }
  return sequence;
}


/**
 * BT comparison function: compares BinaryTreeNodes
 * 
 * @param ptr1
 * @param ptr2
 * @return 
 */
int BinaryTree_CompFunNodePtr_Descending(const void* ptr1, const void* ptr2) {
  // retrieve the correct types that we want to use
  BTNodeT* node_ptr1 = (BTNodeT*) ptr1;
  BTNodeT* node_ptr2 = (BTNodeT*) ptr2;
  return (node_ptr2)->key - (node_ptr1)->key;
}
int BinaryTree_CompFunNodePtr_Ascending(const void* ptr1, const void* ptr2) {
  // retrieve the correct types that we want to use
  BTNodeT* node_ptr1 = (BTNodeT*) ptr1;
  BTNodeT* node_ptr2 = (BTNodeT*) ptr2;
  return (node_ptr1)->key - (node_ptr2)->key;
}


/**
 * This function is constructed such that the each node adds
 * up one to the height except the leaves, which will return 0
 * --> if we only have a root, which then is also a leave, the
 *     height is 0 as expected 
 * 
 * @param bt_node
 * @return 
 */
int BinaryTree_Height(BTNodeT* bt_node) {  
  int height = 0;
  if (bt_node == NULL) {
    height = -1;
  } else {    
    const int height_left = BinaryTree_Height(bt_node->left);
    const int height_rght = BinaryTree_Height(bt_node->rght);
    height += height_left > height_rght ? height_left : height_rght;
    ++height;
  }
  return height;
}

/**
 * Note: the usage of void* allows to have all compare methods 
 *       have the same signature !!!
 *       (no matter what the complex datatypes they compare are!)
 * 
 * Note: to be compatible with qsort one needs to give to the 
 * comparing function a pointer that points to elements of the type
 * that the to-be-sorted array contains
 * 
 * --> in our case, we want to use it for an array 
 *     whose elements are of type (BinarytreeNodeType*)
 * 
 * ==> so we need a comparator function that takes (BinarytreeNodeType**)
 *     as arguments
 * 
 * negative: first value should come before secnd in order specified by this comparator
 * equal   : ..
 * positive: secnd value should come before first in order specified by this comparator
 * 
 * @param ptr1
 * @param ptr2
 * @return 
 */
int BinaryTree_CompFunPtrToNodePtr_Descending(const void* ptr1, const void* ptr2) {
  // retrieve the correct types that we want to use
  BTNodeT** node_ptr1 = (BTNodeT**) ptr1;
  BTNodeT** node_ptr2 = (BTNodeT**) ptr2;
  return (*node_ptr2)->key - (*node_ptr1)->key;
}

/**
 * 
 * @param ptr1
 * @param ptr2
 * @return 
 */
int BinaryTree_CompFunPtrToNodePtr_Ascending(const void* ptr1, const void* ptr2) {
  // retrieve the correct types that we want to use
  BTNodeT** node_ptr1 = (BTNodeT**) ptr1;
  BTNodeT** node_ptr2 = (BTNodeT**) ptr2;
  return (*node_ptr1)->key - (*node_ptr2)->key;
}


// memory management
BTNodeT* BinaryTree_AllocateNewNode(int key, int val) {
  BTNodeT* new_node = calloc(1, sizeof(BTNodeT));
  new_node->key = key;
  new_node->val = val;
  new_node->left = NULL;
  new_node->rght = NULL;
  return new_node;
}

// ACHTUNG, TODO: maybe better let init set root to zero and use 
//                case distinction in insert that sets root if it is empty ?
//                probably not because disadvantage:
//                always have to check at each insertion...
BTNodeT* BinaryTree_Init(BTType* bt, int key, int val) {
  bt->root = BinaryTree_AllocateNewNode(key, val);
  bt->n_nodes = 1;
  return bt->root;
}
void BinaryTree_Destroy(BTType* bt) {
  BinaryTree_DestroyRecursive(bt->root);
  bt->root = NULL;
  bt->n_nodes = 0;
  return;
}
void BinaryTree_DestroyRecursive(BTNodeT* curr) {
  if (curr) {
    BinaryTree_DestroyRecursive(curr->left);
    BinaryTree_DestroyRecursive(curr->rght);
    free(curr);
  }
  return;
}
BTNodeT* BinaryTree_InsertBelowNode(BTType* bt, BTNodeT* parent, int key, int val) {
  if (!parent->left) {    
    parent->left = BinaryTree_AllocateNewNode(key, val);
    ++bt->n_nodes;
    return parent->left;
  } else if (!parent->rght) {
    parent->rght = BinaryTree_AllocateNewNode(key, val);
    ++bt->n_nodes;
    return parent->rght;
  } else {
    printf("Parent already has left and child. Will not overwrite them. \n");
    return NULL;
  }
}
BTNodeT* BinaryTree_InsertAtNodeAsLeft(BTType* bt, BTNodeT* parent, int key, int val) {
  if (!parent->left) {
    parent->left = BinaryTree_AllocateNewNode(key, val);
    ++bt->n_nodes;
    return parent->left;
  } else {
    printf("Parent already has left child. Will not overwrite it. \n");
    return NULL;
  }  
}
BTNodeT* BinaryTree_InsertAtNodeAsRght(BTType* bt, BTNodeT* parent, int key, int val) {
  if (!parent->rght) {
    parent->rght = BinaryTree_AllocateNewNode(key, val);
    ++bt->n_nodes;
    return parent->rght;
  } else {
    printf("Parent already has rght child. Will not overwrite it. \n");
    return NULL;
  }
}


//------------------------------- Binary Tree With Parent API


void BinaryTree_WithParent_PrintSequenceInOrder(BTNodeWithParentT* node) {
  if (node) {
    BinaryTree_WithParent_PrintSequenceInOrder(node->left);
    printf("Inorder sequence: %i (parent = %i) \n", node->key, node->parent ?
      node->parent->key : -42);
    BinaryTree_WithParent_PrintSequenceInOrder(node->rght); 
  }
}

void BinaryTree_WithParent_GetSequenceInOrder(BTNodeWithParentT* node,
        BTNodeWithParentT** sequence, int* n_nodes) {
  if (node) {
    BinaryTree_WithParent_GetSequenceInOrder(node->left, sequence, n_nodes);  
    ++(*n_nodes);
    sequence = realloc(sequence, (*n_nodes) * sizeof(BTNodeWithParentT*));
    sequence[(*n_nodes) - 1] = node;
    //printf("Added to inorder sequence: %i \n", node->data);
    BinaryTree_WithParent_GetSequenceInOrder(node->rght, sequence, n_nodes); 
  }
}

void BinaryTree_WithParent_GetSequencePreOrder(BTNodeWithParentT* node,
        BTNodeWithParentT** sequence, int* n_nodes) {
  if (node) {
    ++(*n_nodes);
    sequence = realloc(sequence, (*n_nodes) * sizeof(BTNodeWithParentT*));
    sequence[(*n_nodes) - 1] = node;
    //printf("Added to preorder sequence: %i \n", node->data);
    BinaryTree_WithParent_GetSequencePreOrder(node->left, sequence, n_nodes);    
    BinaryTree_WithParent_GetSequencePreOrder(node->rght, sequence, n_nodes); 
  }
}

void BinaryTree_WithParent_GetSequencePostOrder(BTNodeWithParentT* node,
        BTNodeWithParentT** sequence, int* n_nodes) {
  if (node) {
    BinaryTree_WithParent_GetSequencePostOrder(node->left, sequence, n_nodes);    
    BinaryTree_WithParent_GetSequencePostOrder(node->rght, sequence, n_nodes); 
    ++(*n_nodes);
    sequence = realloc(sequence, (*n_nodes) * sizeof(BTNodeWithParentT*));
    sequence[(*n_nodes) - 1] = node;
    //printf("Added to postorder sequence: %i \n", node->data);
  }
}


BTNodeWithParentT* BinaryTree_WithParent_Init(BTWithParentsType* bt, int key, 
        int val) {  
  BTNodeWithParentT* new_mem = calloc(1, sizeof(BTNodeWithParentT));
  new_mem->key = key;
  new_mem->val = val;
  new_mem->parent = NULL;
  bt->root = new_mem;
  return new_mem;
}
void BinaryTree_WithParent_Destroy(BTWithParentsType* bt) {
  BinaryTree_WithParent_DestroyRecursive(bt->root);
  bt->root = NULL;
  return;
}
void BinaryTree_WithParent_DestroyRecursive(BTNodeWithParentT* curr) {  
  if (curr) {
    BinaryTree_WithParent_DestroyRecursive(curr->left);
    BinaryTree_WithParent_DestroyRecursive(curr->rght);
    free(curr);
  }
  return;
}
BTNodeWithParentT* BinaryTree_WithParent_InsertAtNode(BTNodeWithParentT* parent,
        int key, int val) {  
  if (!parent->left) {
    BTNodeWithParentT* new_mem = calloc(1, sizeof(BTNodeWithParentT));
    new_mem->key = key;
    new_mem->val = val;
    new_mem->parent = parent;
    parent->left = new_mem;
    return new_mem;
  } else if (!parent->rght) {
    BTNodeWithParentT* new_mem = calloc(1, sizeof(BTNodeWithParentT));
    new_mem->key = key;    
    new_mem->val = val;
    new_mem->parent = parent;
    parent->rght = new_mem;    
    return new_mem;
  } else {
    printf("Parent already has left and child. Will not overwrite them. \n");
    return NULL;
  }
}
BTNodeWithParentT* BinaryTree_WithParent_InsertAtNodeAsLeft(BTNodeWithParentT* parent,
        int key, int val) {  
  if (!parent->left) {
    BTNodeWithParentT* new_mem = calloc(1, sizeof(BTNodeWithParentT));
    new_mem->key = key;
    new_mem->val = val;
    new_mem->parent = parent;
    parent->left = new_mem;
    return new_mem;
  } else {
    printf("Parent already has left child. Will not overwrite it. \n");
    return NULL;
  }  
}
BTNodeWithParentT* BinaryTree_WithParent_InsertAtNodeAsRght(BTNodeWithParentT* parent, 
        int key, int val) {
  if (!parent->rght) {
    BTNodeWithParentT* new_mem = calloc(1, sizeof(BTNodeWithParentT));
    new_mem->key = key;
    new_mem->val = val;
    new_mem->parent = parent;
    parent->rght = new_mem;
    return new_mem;
  } else {
    printf("Parent already has rght child. Will not overwrite it. \n");
    return NULL;
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//-------------------------- Excercises

/**
 * This method is to find the smallest-depth, farthest-left 
 * free position in the BT and insert the new node there.
 * 
 * Strategy: 
 * The idea is to traverse the whole tree and track 
 * the current min-depth position that is free.
 * --> if another position if found at the same depth, 
 *     we do not swap, so we take the first min at a
 *     given depth  (not the farthes left first)
 * 
 * 
 * @param bt_node
 */
BTNodeT* BinaryTree_InsertNodeAtSmallestFreeIndex(BTType* bt, int key, int val) {   
  int mindepth_notfullnode = INT_MAX;
  BTNodeT* smallest_withfreechild = NULL;  
  BinaryTree_GetSmallestIndexNodeWithFreeChild(bt->root, 0, &mindepth_notfullnode, 
          &smallest_withfreechild);  
  if (smallest_withfreechild) {
    printf("Smallest-index node with a free child-slot has data = %i \n", 
          smallest_withfreechild->key);
    printf("Inserting new node as %s child of that node.\n\n", 
            (!smallest_withfreechild->left ? "left" : "right"));
    BTNodeT* new_node = BinaryTree_InsertBelowNode(bt, smallest_withfreechild, key, val);
    return new_node;
/*
    if (smallest_withfreechild->left == NULL) {      
      smallest_withfreechild->left = new_node;
    } else {
      smallest_withfreechild->rght = new_node;
    }
*/
  } else {
    printf("Implementation error. Something went wrong. \n")    ;
    return NULL;
  }
}

void BinaryTree_GetSmallestIndexNodeWithFreeChild(BTNodeT* bt_node, int rec_depth, 
        int* mindepth_notfullnode,
        BTNodeT** notfull_node) {
  // case: the search may still find a new mindepth_notfullnode
  if (rec_depth <= *mindepth_notfullnode - 1) { 
    
    if (bt_node->left && bt_node->rght) {
      int* mindepth_candidate_left = mindepth_notfullnode;
      int* mindepth_candidate_rght = mindepth_notfullnode;
      BTNodeT* candidate_leftsubtree = NULL;
      BTNodeT* candidate_rghtsubtree = NULL;
      ++rec_depth;
      //printf("-- Checking left candidate of node with data %i for insertion. \n", bt_node->data);
      BinaryTree_GetSmallestIndexNodeWithFreeChild(bt_node->left, rec_depth, 
              mindepth_candidate_left, &candidate_leftsubtree);
      //printf("-- Checking rght candidate of node with data %i for insertion. \n", bt_node->data);
      BinaryTree_GetSmallestIndexNodeWithFreeChild(bt_node->rght, rec_depth, 
              mindepth_candidate_rght, &candidate_rghtsubtree);
      if (candidate_leftsubtree && candidate_rghtsubtree) {
        *mindepth_notfullnode = MIN(*mindepth_candidate_left, *mindepth_candidate_rght);
        *notfull_node = *mindepth_candidate_left < *mindepth_candidate_rght ? 
          candidate_leftsubtree : candidate_rghtsubtree;        
        //printf("At node with data=%i found the following mindepths for insertion:\n ", 
        //        bt_node->data);
        //printf("Left subtree: mindepth = %i \n", *mindepth_candidate_left);
        //printf("Rght subtree: mindepth = %i \n", *mindepth_candidate_rght);
      } else {
        // Imageine, if positions up to 4 are filled in the BT,
        // then at node 1 we may enter here, with left_candidate being set
        // while right_candidate was not set because when right_candidate
        // is being set, the mindepth_notfullnode was already dereferenced
        // by the finding of node 3 as a free node and set to 2
        if (candidate_leftsubtree) {
          *mindepth_notfullnode = *mindepth_candidate_left;
          *notfull_node = candidate_leftsubtree;
        }
        if (candidate_rghtsubtree) {
          *mindepth_notfullnode = *mindepth_candidate_left;
          *notfull_node = candidate_leftsubtree;
        }
      }
    } else { // !NodeIsFull
      // recursion base case:
      *notfull_node = bt_node;
      *mindepth_notfullnode = rec_depth;
      //printf("Found temporary notfullnode at depth = %i. \n", rec_depth);      
    }    
    
  } else { // recursion base case: no need to dig deeper
    // do nothing
    //printf("Recursion depth %i is too large to find candidates. \n", rec_depth);
  }  
  //printf("------- Return from node with data %i. \n", bt_node->data);
  return;
}


void BinaryTree_PathToNode(BTNodeT* root, 
        BTNodeT* node, 
        int path_to_node[],
        int* flag_node_was_found,
        int rec_depth) {
  if (!node) printf("Wrong input. No node specified to search for. \n");
  if (root == node || *flag_node_was_found) {
    // we are done, path_to_node should be filled now correctly
    *flag_node_was_found = true;
  } else {
    if (root->left) {
      path_to_node[rec_depth] = 0;
      BinaryTree_PathToNode(root->left, node, path_to_node, flag_node_was_found, 
              rec_depth + 1);
    }
    if (*flag_node_was_found == false) {      
      if (root->rght) {
        path_to_node[rec_depth] = 1;
        BinaryTree_PathToNode(root->rght, node, path_to_node, flag_node_was_found,
                rec_depth + 1);        
      }      
      // reset the path if we did not find it starting from this node
      if (*flag_node_was_found == false) {          
        path_to_node[rec_depth] = -1;
      }
    } else {  // *flag_node_was_found == true
      // in this case we leave the 0 set to the path track
    }      
  }
  return;
}

/**
 * Exercise:
 * 
 *  check if a tree is height balanced
 * 
 * Algo: 
 * 
 *  compute height of each node once and compare with other child to
 *  see if at some node we detect a violation of the height-balance.
 * 
 *  Note: if we are not interested in the height of the tree but only
 *  in the check whether it is height balanced or not then we could
 *  save some computations by computing the height of the right
 *  subtree only, if isbalanced is still true. otherwise directly return
 *  height == -1
 * 
 * @param node
 * @param isbalanced
 * @return 
 */
int BinaryTree_ComputeHeightAndCheckBalance(BTNodeT* node, bool *isbalanced) {
  if (!node) {
    return -1;
  } else {
    int height_left = BinaryTree_ComputeHeightAndCheckBalance(node->left, isbalanced);
    int height_rght = BinaryTree_ComputeHeightAndCheckBalance(node->rght, isbalanced);
    *isbalanced = (abs(height_left - height_rght) <= 1 ? true : false);
    return 1 + (height_left > height_rght ? height_left : height_rght);
  }
}

bool BinaryTree_IsSymmetric_Wrapper(BTNodeT* node) {  
  return BinaryTree_AreNodesSymmetric(node->left, node->rght);
}

bool BinaryTree_AreNodesSymmetric(BTNodeT* n1, BTNodeT* n2) {  
  if ((n1 && !n2) || (n2 && !n1)) {
    return false;
  } else if (!n1 && !n2) {
    return true;
  } else { // n1 != NULL && n2 != NULL
    bool data_isequal = (n1->key == n2->key ? true : false);
    bool left_left_rght_rght = BinaryTree_AreNodesSymmetric(n1->left, n2->rght);
    bool left_rght_rght_left = BinaryTree_AreNodesSymmetric(n1->rght, n2->left);
    return (data_isequal && left_left_rght_rght && left_rght_rght_left) ;
  }
}



/**
 * Idea: one can write a neat algorithm if the LCA is tracked by a global
 * 
 * 
 * @param bt
 * @param node1
 * @param node2
 * @return 
 */
int BinaryTree_FindLCA(BTNodeT* node, BTNodeT* node1, 
        BTNodeT* node2, BTNodeT** LCA) {  
  if (node == NULL) { return 0; } // base-case
  int matches_l = BinaryTree_FindLCA(node->left, node1, node2, LCA);    
  if (matches_l == 2) {
    return matches_l; // LCA was set already in earlier recursion, return
  }
  int matches_r = BinaryTree_FindLCA(node->rght, node1, node2, LCA);   
  if (matches_r == 2) {
    return matches_r; // LCA was set already in earlier recursion, return
  }
  int matches = matches_l + matches_r + (node == node1) + (node == node2);
  if (matches == 2) { // time to set the LCA !
    *LCA = node;
  }      
  return matches;
}

ReturnStatusLCAType BinaryTree_FindLCA_textbookalgo(BTNodeT* root, 
        BTNodeT* node1, 
        BTNodeT* node2) {   
   ReturnStatusLCAType status = { 0, NULL };
  if (root == NULL) {
    return status;
  }
   
  // always continue a next recursion to the left
  // --> we will always reach the leftmost bottom-node of the tree
  ReturnStatusLCAType status_left = 
          BinaryTree_FindLCA_textbookalgo(root->left, node1, node2);
  if (status_left.num_targets_in_tree == 2) {
    return status_left;
  }
  // continue a next recursion to the rght
  // note: only reach here if not both nodes found left
  ReturnStatusLCAType status_rght = 
          BinaryTree_FindLCA_textbookalgo(root->rght, node1, node2);
  if (status_rght.num_targets_in_tree == 2) {
    return status_rght;
  }

  status.num_targets_in_tree += status_left.num_targets_in_tree;
  status.num_targets_in_tree += status_rght.num_targets_in_tree;
  status.num_targets_in_tree += (root == node1) + (root == node2);
  // possible cases now:
  // i) we actually are on the LCA node right now
  // ii) we are at a node that does not contain any of the two
  // iii) we are at a node which contains one node in the subtree
  //     and is itself the other node   
  if (status_left.num_targets_in_tree == 1 && 
          status_rght.num_targets_in_tree ==1) {     
    status.ptr_to_LCA = root;
  } else {
   if (status.num_targets_in_tree == 0) {
      // return status as it is, { 0, NULL }
    } else if (status.num_targets_in_tree == 2) {
      if (root == node1)  {
        status.ptr_to_LCA = node1; 
      } else if (root == node2) {
        status.ptr_to_LCA = node2;
      }
    } else { // status.num_targets_in_tree == 1
      // return status as it is, { 1, NULL }
    }
  }
  
  return status;
}

/**
 * Exercise: 
 * 
 * Assume we have a binary tree whose data is only 0 or 1. 
 * Then each leave represents a number, namely the digit-sequence of the 
 * root-to-leaf path that can be interpreted as a binary number.
 * We define the root to represent the MSB of the number.
 * 
 * --> add up all leaves
 * 
 * Idea:
 * 
 * We compute the height first. O(n)
 * Then we give a buffer of length height+1 to a recursive pre-order traversal that
 * is filled with the digit at each level until a leaf is reached, in which
 * case the buffer is evaluated and added to the sum.
 * 
 * time complexity: O(n)
 * space complexity: O(h)
 * 
 * @param root
 * @return 
 */
ull BinaryTree_SumUpRootToLeafPaths_Wrapper(BTNodeT* root) {  
/*
 * // first try: using additional buffer, this can be spared 
  ull sum = 0;  
  int height = BinaryTree_Height(root);
  ull buffer[height + 1];
  BinaryTree_SumUpRootToLeafPaths_WithBuffer(root, &sum, buffer, 0);
*/
  return BinaryTree_SumUpRootToLeafPaths(root, 0);
}

ull BinaryTree_SumUpRootToLeafPaths(BTNodeT* node, ull prev_sum) {
  if (!node) { return 0lu; }
  ull curr_sum = prev_sum * 2 + node->key;
  if (node->left == NULL && node->rght == NULL) { // node is a leaf
    return curr_sum;
  } else { // node is not a leaf
    ull left_sum = BinaryTree_SumUpRootToLeafPaths(node->left, curr_sum);
    ull rght_sum = BinaryTree_SumUpRootToLeafPaths(node->rght, curr_sum);
    return left_sum + rght_sum;
  }  
}

void BinaryTree_SumUpRootToLeafPaths_WithBuffer(BTNodeT* node, ull *sum,
        ull *buffer, int depth) {
  if (!node) {
    return;
  }
  buffer[depth] = node->key;
  if (node->left == NULL && node->rght == NULL) {
    int i;
    ull root_to_leaf = 0;
    for (i = 0; i < depth + 1; ++i) {
      root_to_leaf += buffer[depth - i] * pow(2, i); // MSB is the last
    }
    *sum += root_to_leaf;
  } else { // not both children are NULL  
    BinaryTree_SumUpRootToLeafPaths_WithBuffer(node->left, sum, buffer, depth + 1);
    BinaryTree_SumUpRootToLeafPaths_WithBuffer(node->rght, sum, buffer, depth + 1);
  }
  buffer[depth] = -1;    
  return;
}


/**
 * Exercise:
 * 
 * Given a binary tree of integers, the path-weight of a node is the sum
 * of the integers on the path from root to the node.
 * 
 * -> given a target_weight, check if the binary tree contains a leaf with that
 * weight
 * 
 * Note: multiple nodes can have the same weight.
 * 
 * Idea:
 * 
 * We traverse all nodes in pre-order manner, keeping track of the path-weight
 * at the current node and check at the leaves if the target is hit. in that
 * case we do not need to recurse further.
 * 
 * time complexity: O(n)
 * space complexity: O(h) 
 * 
 * @param root
 * @param target_weight
 * @return 
 */
bool BinaryTree_LeafWithGivenPathWeightExists(BTNodeT* node, int target_weight) {
  if (!node) { return false; }
  target_weight -= node->key;
  if (node->left || node->rght) {
    bool exists_in_left = BinaryTree_LeafWithGivenPathWeightExists(node->left, target_weight);    
    bool exists_in_rght = (exists_in_left ? true : 
      BinaryTree_LeafWithGivenPathWeightExists(node->rght, target_weight));
    return (exists_in_left || exists_in_rght);
  } else {
    return (target_weight == 0 ? true : false);
  }
}

/**
 * Exercise:
 * 
 * Do an in-order traversal without recursion.
 * 
 * Idea:
 * 
 * Since we need to descend first to the bottom left, i see no way how
 * we could spare the O(h) space for the parents that the recursion
 * provides implicitly on the recursion stack.
 * 
 * Therefore, we first compute the height and then mimic the recursion
 * stack by an array of h+1 entries. It is not enough to store the parents
 * in the stack though because whenever we are done with a subtree and
 * come back to a parent we need to have the information whether its
 * left subtree has been processed, whether itself has been processed
 * and whether the right subtree has been processed.
 * once all three are processed we can remove it from the stack and continue
 * with the next one.
 * 
 * @param root
 */
void BinaryTree_InOrderTraversalWithoutRecursion(BTNodeT* node) {  
  int h = BinaryTree_Height(node);    
  BTNodeT* stack[h + 1]; // to cache nodes, if going left
  int i_top = -1;
  while(node || i_top >= 0) {
    if (!node) { // base case: take from the stack, if empty: quit
      node = stack[i_top--];
      printf("Node has data: %i \n", node->key);      
      node = node->rght;
    } else {
      stack[++i_top] = node;
      node = node->left; 
    }    
  }  
  return;
}


/**
 * Exercise: 
 * 
 * Traverse a binary tree in pre-order manner without using recursion.
 * 
 * Idea:
 * 
 * like in-order, we mimic the recursion stack with a stack of nodes
 * that are not yet processed - only that this time it will be the
 * right child nodes instead of the current node.
 * 
 * @param node
 */
void BinaryTree_PreOrderTraversalWithoutRecursion(BTNodeT* node) {
  int h = BinaryTree_Height(node);
  BTNodeT* stack[h + 1];
  int i_top = -1; 
  while (node || i_top >= 0) {
    if (!node) {
      node = stack[i_top--];
    }
    printf("Node has data %i \n", node->key);
    if (node->rght) {
      stack[++i_top] = node->rght;
    }
    node = node->left;
  }  
  return;
}

/**
 * Exercise: 
 * 
 * Given a node in a binary tree, in which the nodes have a parent pointer.
 * 
 * --> Find the inorder successor of the node
 * 
 * Idea:
 * 
 * There are two cases: 
 *    i)  the target node has a right child.
 *        in that case we need to find the first inorder node of the subtree
 *        spanned by that right child.
 * 
 *    ii) the garget node does not have a right child.
 *        in that case we need to step up the hierarchy.
 *        while the current node is a right child of its parent, 
 *        the parent comes before the current node so we need to step up further.
 *        when the current node is a left child of its parent, the parent
 *        is the successor of the node we started at. 
 *        if we reach back up to the root before having found a successor,
 *        then there is no successor of the target.
 * 
 * time complexity: best case O(1), worst-case O(h)
 * space complexity: O(1)
 * 
 * @param target
 * @return 
 */
BTNodeWithParentT* BinaryTree_GetInOrderSuccessor_NodesWithParent(BTNodeWithParentT* node) {  
  if (!node) return NULL;
  return (node->rght ? FirstInOrderNode(node->rght) : FirstUnprocessedInOrderParent(node));
}
BTNodeWithParentT* FirstInOrderNode(BTNodeWithParentT* node) {  
  while (node->left) {
    node = node->left;
  }
  return node;
}
BTNodeWithParentT* FirstUnprocessedInOrderParent(BTNodeWithParentT* node) {
  if (!node) return NULL;
  while (node->parent && node->parent->rght == node) {
    node = node->parent;
  }
  return node->parent; // note: can be NULL
}

/**
 * Exercise:
 * 
 * Given the root of a binary tree, in which nodes have parent pointers.
 * Construct a non-recursive algorithm that exploits the parent pointers.
 * 
 * Idea:
 * 
 * We do not need the recursion because we can step-up until we find
 * a node whose right subtree has not yet been processed.
 * 
 * In each iteration we first descend to the 1st inorder node in the
 * current subtree. we print it. then there are two cases
 *    i)  if the current node has a right subtree
 *        --> we go there and start the next iteration. 
 *    ii) if the current node does not have a right subtree
 *        --> we need to step up until a parent is reached that is not
 *            fully processed: a parent is fully processed, if we are
 *            coming back to it from its right child. instead, 
 *            it is not fully processed, if we are coming back from
 *            its left child. 
 *            In that case we check if a right child exists.
 *            a) yes: go to the right child and start next iteration
 *            b) no: continue to step up
 * 
 * @param node
 */
void BinaryTree_PrintInOrderNodesWithParentWithoutRecursion(BTNodeWithParentT* node) {  
  BTNodeWithParentT* itr = FirstInOrderNode(node);
  while (itr) {
    printf("Non-recursive inorder using parent: %i \n", itr->key);
    itr = BinaryTree_GetInOrderSuccessor_NodesWithParent(itr);    
  }  
  return;
}

/**
 * Exercise:
 * 
 * Given the sequences of nodes of a binary tree inorder and preorder,
 * construct the unique binary tree that gives these sequences.
 * 
 * Idea:
 * 
 *    We can recursively divide and conquer this task. 
 * 
 *    First note that the in-order sequence can be divided into elements
 *    of left-subtree of root, the root, and elements of the rght subtree from root.
 * 
 *    Thus, given the root, we can find its index in the inorder-sequence to
 *    determine how many nodes are in its left subtree and how many are in its
 *    right subtree.
 * 
 *    This allows to pick the left and the right child of the root from the
 *    given pre-order-sequence: in pre-order, the root is the first, then 
 *    comes the root of its left-subtree and all nodes of the left-subtree,
 *    if a left-subtree exists,
 *    then comes the root of the right-subtree and all the nodes of the
 *    right-subtree.
 * 
 *    So, given a root and its preorder-sequence, we use the inorder sequence
 *    to determine the root of its left subtree and the restricted
 *    sequences of that subtree, and also the root of its right-subtree
 *    and the restricted sequences of that subtree
 *    
 * @param inorder
 * @param preorder
 * @param n
 * @return 
 */
BTType BinaryTree_ConstructFromInAndPreOrderSequences_Wrapper(int* inorder,
        int* preorder, int n) {
  BTType new_bt = { 0 };
  BTNodeT* root = BinaryTree_Init(&new_bt, preorder[0], -42);
  int n_left = FindIdxInSequence(inorder, root->key, n);
  int n_rght = n - 1 - n_left;
  BTNodeT* new_left = NULL;
  BTNodeT* new_rght = NULL;
  if (n_left > 0) {
    new_left = BinaryTree_InsertAtNodeAsLeft(&new_bt, root, preorder[1], -42);
  }
  if (n_rght > 0) {
    new_rght = BinaryTree_InsertAtNodeAsRght(&new_bt, root, preorder[n_left + 1], -42);
  } 
  BinaryTree_ConstructFromInAndPreOrderSequences(&new_bt, new_left, 
          inorder, preorder + 1, n_left);
  BinaryTree_ConstructFromInAndPreOrderSequences(&new_bt, new_rght, 
          inorder + n_left + 1, preorder + n_left + 1, n_rght);
  return new_bt;
}
void BinaryTree_ConstructFromInAndPreOrderSequences(BTType* bt, BTNodeT* parent,
        int* inorder, int* preorder, int n) {  
  if (n == 0 || parent == NULL) return;
  int key_to_insert = preorder[0];
  int n_left = FindIdxInSequence(inorder, key_to_insert, n);
  int n_rght = n - 1 - n_left;
  BTNodeT* new_left = NULL;
  BTNodeT* new_rght = NULL;
  if (n_left > 0) {
    new_left = BinaryTree_InsertAtNodeAsLeft(bt, parent, preorder[1], -42);
  }
  if (n_rght > 0) {
    new_rght = BinaryTree_InsertAtNodeAsRght(bt, parent, preorder[n_left + 1], -42);
  } 
  BinaryTree_ConstructFromInAndPreOrderSequences(bt, new_left, 
          inorder, preorder + 1, n_left);
  BinaryTree_ConstructFromInAndPreOrderSequences(bt, new_rght,
          inorder + n_left + 1, preorder + n_left + 1, n_rght);
  return;
}
// ACHTUNG: assume keys are unique here !
int FindIdxInSequence(int* keys, int target, int n) {
  int idx = 0;
  while (idx < n && keys[idx] != target) {
    ++idx;
  }
  return (idx == n ? -1 : idx);
}


/**
 * Exercise:
 * 
 * Given a preorder sequence of nodes, which also includes NULL
 * fields if reached, construct a binary tree from the given nodes
 * by setting their left and right pointers according to the given order.
 * 
 * Idea:
 * 
 * Starting from the root, we know that the next value in the sequence
 * is the left child of the root, no matter if it is an actual node or
 * just NULL. So we can in any-case fill the left-child of the root. 
 * For the values that follow afterwards we need a case distinction: 
 * if the currently set left child is NULL, it follows directly the value for
 * the right child and then all of its sub children, which means we 
 * can set the right child and recurse with its subtree;
 * if the currently set left child is not NULL, we will have values
 * in for its children in the sequence before we come to the value 
 * for the right child of the current node, so we first have to recurse a level
 * and process all nodes of the subtree before we continue with the right child
 * and its subtree.
 * 
 * We use a global counter in the recursion to track
 * how many nodes of the sequence we already have processed, 
 * so that once we return from the
 * recursion the caller can continue at the next unprocessed value in the
 * sequence. 
 * 
 * @param preorder
 * @param i_curr
 * @return 
 */
BTType BinaryTree_ConstructFromPreOrderSequenceWithNulls_Wrapper(int* preorder) {
  BTType new_bt = {0};  
  BTNodeT* root = BinaryTree_Init(&new_bt, preorder[0], -42);
  int i_curr = 1;  
  BTNodeT* new_left = NULL;
  if (preorder[i_curr] != -1) {
    new_left = BinaryTree_InsertAtNodeAsLeft(&new_bt, root, preorder[i_curr], -42);
  }
  BinaryTree_ConstructFromPreOrderSequenceWithNulls(&new_bt, new_left, preorder, &i_curr);  
  ++i_curr;
  BTNodeT* new_rght = NULL;
  if (preorder[i_curr] != -1) {
    new_rght = BinaryTree_InsertAtNodeAsRght(&new_bt, root, preorder[i_curr], -42);
  }  
  BinaryTree_ConstructFromPreOrderSequenceWithNulls(&new_bt, new_rght, preorder, &i_curr);  
  return new_bt;
}
void BinaryTree_ConstructFromPreOrderSequenceWithNulls(BTType* bt, BTNodeT* parent,
        int* preorder, int* i_curr) {
  if (!parent) return;
  ++(*i_curr);
  BTNodeT* new_left = NULL;
  if (preorder[*i_curr] != -1) {
    new_left = BinaryTree_InsertAtNodeAsLeft(bt, parent, preorder[*i_curr], -42);
  }
  BinaryTree_ConstructFromPreOrderSequenceWithNulls(bt, new_left, preorder, i_curr);  
  ++(*i_curr);
  BTNodeT* new_rght = NULL;
  if (preorder[*i_curr] != -1) {
    new_rght = BinaryTree_InsertAtNodeAsRght(bt, parent, preorder[*i_curr], -42);
  }
  BinaryTree_ConstructFromPreOrderSequenceWithNulls(bt, new_rght, preorder, i_curr); 
  return;
}

/**
 * Exercise:
 * 
 * Find the leaves of the tree in left-to-right order.
 * 
 * Idea:
 * 
 * In a normal pre-order traversal, we reach the leaves in left-to-right order.
 * 
 * time-complexity: O(n) 
 * space-complexity: O(h) (recursion stack)
 * 
 * Note that we cannot do better than O(n) because we need to check every node
 * for being a leaf or not.
 * 
 * @param node
 * @param leaves
 * @param n_leaves
 */
BTNodeT** BinaryTree_GetLeaves(BTNodeT* node, BTNodeT** leaves, int* n_leaves) {
  if (!node) return leaves;
  if (!node->left && !node->rght) {
    leaves = realloc(leaves, (++(*n_leaves)) * sizeof(BTNodeT*));
    leaves[(*n_leaves) - 1] = node;
  } else {
    leaves = BinaryTree_GetLeaves(node->left, leaves, n_leaves);
    leaves = BinaryTree_GetLeaves(node->rght, leaves, n_leaves);
  }  
  return leaves;
}

/**
 * Exercise: 
 * 
 * The exterior of a binary tree is the union of the left-boundary, the leaves,
 * and the right-boundary. The left(right)-boundary is the sequence of nodes
 * from the root to the first(last)-inorder-leaf.
 * 
 * Idea:
 * 
 * Computing each of them separately is easy, so we do that and combine.
 * We only need to check if the leftmost(rightmost)-node is a leaf 
 * to not take it twice: 
 * 
 * convention:  take root from left boundary, take leftmost leaf from leaves,
 *              take rightmost leaf from right boundary
 * 
 *                                    0
 *                        1                         2
 *              3                4             5           6
 *                  8         9     10           12
 * 
 * left-boundary: 0, 1, 3, 8
 * right-boundary: 0, 2, 6
 * leaves: 8, 9, 10, 12, 6
 * 
 * Note: this means in worst-case 3 traversals with O(h), O(n), O(h). 
 * One could optimize by combining the search for the left(right)-boundary
 * and the leaves in the left(right)-subtree in one traversal, so we would
 * have only O(n/2) + O(n/2).
 * 
 * 
 * 
 * @param node
 * @param leaves
 * @param n_leaves
 */
BTNodeT** BinaryTree_GetExterior(BTNodeT* node, int* n_nodes) {  
  // left-boundary, leaves, right-boundary
  int n_left_boundary = 0;
  BTNodeT** left_boundary = BinaryTree_GetLeftBoundary(node, &n_left_boundary);    
  int n_rgth_boundary = 0;
  BTNodeT** rght_boundary = BinaryTree_GetRghtBoundary(node, &n_rgth_boundary);
  int n_leaves = 0;  
  BTNodeT** leaves = BinaryTree_GetLeaves(node, NULL, &n_leaves);
  
  // reduce limits to avoid duplicates
  int n_use_left_boundary = left_boundary[n_left_boundary - 1] == leaves[0] ? 
    n_left_boundary - 1 : n_left_boundary;
  int n_use_leaves = leaves[n_leaves - 1] == rght_boundary[n_rgth_boundary - 1] ?
    n_leaves - 1 : n_leaves;
  int n_use_rght_boundary = n_rgth_boundary - 1;  
  *n_nodes = n_use_left_boundary + n_use_leaves + n_use_rght_boundary;
  
  // fill output
  BTNodeT** exterior = calloc(*n_nodes, sizeof(BTNodeT*));  
  memcpy(exterior, left_boundary, n_use_left_boundary * sizeof(BTNodeT*));
  memcpy(exterior + n_use_left_boundary, leaves, n_use_leaves * sizeof(BTNodeT*));
  int i;
  for (i = 0; i < n_use_rght_boundary; ++i) {
    exterior[n_use_left_boundary + n_use_leaves + i] = 
            rght_boundary[n_rgth_boundary - 1 - i];
  }  
  
  // free
  free(leaves);
  free(left_boundary);
  free(rght_boundary);
  return exterior;
}
// ACHTUNG: TODO this is wrong. left boundary must reach leftmost LEAF
BTNodeT** BinaryTree_GetLeftBoundary(BTNodeT* node, int* n_nodes) {
  BTNodeT** boundary = NULL;
  while (node) {
    boundary = realloc(boundary, (++(*n_nodes)) * sizeof(BTNodeT*));
    boundary[(*n_nodes) - 1] = node;    
    node = node->left;
  }
  return boundary;
}
// ACHTUNG: TODO this is wrong. left boundary must reach rghtmost LEAF
BTNodeT** BinaryTree_GetRghtBoundary(BTNodeT* node, int* n_nodes) {
  BTNodeT** boundary = NULL;
  while (node) {
    boundary = realloc(boundary, (++(*n_nodes)) * sizeof(BTNodeT*));
    boundary[(*n_nodes) - 1] = node;    
    node = node->rght;
  }
  return boundary;
}

/**
 * Exercise:
 * 
 * Assume given a perfect binary tree, in which nodes have next-in-level-ptrs
 * but unset, set these pointers.
 * 
 * Idea:
 * 
 * Setting the next-in-level pointer for the left child of a node is easy:
 * it is the right child. 
 * However, the next-in-level pointer for the right child of a node comes
 * from another subtree:
 * node->parent->rght->left
 * 
 *                           node
 *                      l            r
 *                ll       lr    rl      rr
 * 
 * So to set the next-in-level pointer of the children of a node,
 * we need the additional information, who is the sibling of the current node,
 * so that we can reference the left-child of the sibling.
 * 
 * ACHTUNG: misuse datatype BTNodeWithParent here. We take parent pointer
 *          as next in level pointer.
 * 
 */
void BinaryTree_NodesWithNextInLevelPointerFill_Wrapper(BTNodeWithParentT* root) {
  BinaryTree_NodesWithNextInLevelPointerFill(root->left, root->rght, NULL);
  return;
}

void BinaryTree_NodesWithNextInLevelPointerFill(BTNodeWithParentT* left, 
        BTNodeWithParentT* rght, BTNodeWithParentT* siblings_left) {
  if (!left) return;
  left->parent = rght;
  rght->parent = siblings_left;
  BinaryTree_NodesWithNextInLevelPointerFill(left->left, left->rght, rght->left);
  BinaryTree_NodesWithNextInLevelPointerFill(rght->left, rght->rght, 
          siblings_left ? siblings_left->left : NULL);  
  return;
}