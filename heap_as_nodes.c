/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Note: 
 * 
 *  Using the generical comparison function allover the file
 * 
 *        int (*compFun_if1stargLess2ndargResultLess0)(const void*, const void*)
 * 
 *  allows to easily general all procedures for other comparison functions
 *  that may be evaluating attributes of more complex nodes than simply
 *  an integer data content.
 * 
 *  We follow the convention used in C-library functions 
 *  that comparator(x,y) returns < 0
 *  if in the wanted order x should appear first, then y,   and
 *  that comparator(x,y) returns > 0
 *  if in the wanted order y should appear first, then x.
 * 
 */

#include "heap_as_nodes.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "binarytree_as_nodes.h"

// create a pool of nodes
static BTNodeT node0 = { 0, -42, NULL, NULL};
static BTNodeT node1 = { 1, -42, NULL, NULL};
static BTNodeT node2 = { 2, -42, NULL, NULL};
static BTNodeT node3 = { 3, -42, NULL, NULL};
static BTNodeT node4 = { 4, -42, NULL, NULL};
static BTNodeT node5 = { 5, -42, NULL, NULL};
static BTNodeT node6 = { 6, -42, NULL, NULL};
static BTNodeT node7 = { 7, -42, NULL, NULL};
static BTNodeT node8 = { 8, -42, NULL, NULL};
static BTNodeT node9 = { 9, -42, NULL, NULL};
static BTNodeT node10 = { 10, -42, NULL, NULL};
static BTNodeT node11 = { 11, -42, NULL, NULL};
static BTNodeT node12 = { 12, -42, NULL, NULL};
static BTNodeT node13 = { 13, -42, NULL, NULL};
static BTNodeT node14 = { 14, -42, NULL, NULL};

void MainHeapAsNodes() {  
  printf("\n\n----------------------- MainHeapAsNodes \n");
  
  //-----------------------------------------
  // preparations:
  
  //-----------------------------------------
  // Exercises  
  
  MainHeapAsNodes_API();
   
  return;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
  

void MainHeapAsNodes_API() {
  printf("\n----------------------------------- MainHeapAsNodes_API \n");  
   
  // Build up a heap from the pool of nodes
  printf("\n\n----------------------- BUILDING UP A BT\n");
  HeapType heap = { NULL, NULL, 0 };
  heap.compfun_ptr = BinaryTree_CompFunPtrToNodePtr_Descending;
  Heap_AddNewNodeToCompleteBT(&heap, &node0);
  Heap_AddNewNodeToCompleteBT(&heap, &node1);
  Heap_AddNewNodeToCompleteBT(&heap, &node2);
  Heap_AddNewNodeToCompleteBT(&heap, &node3);
  Heap_AddNewNodeToCompleteBT(&heap, &node4);
  Heap_AddNewNodeToCompleteBT(&heap, &node5);
  Heap_AddNewNodeToCompleteBT(&heap, &node6);
  Heap_AddNewNodeToCompleteBT(&heap, &node7);
  Heap_AddNewNodeToCompleteBT(&heap, &node8);
  Heap_AddNewNodeToCompleteBT(&heap, &node9);
  Heap_AddNewNodeToCompleteBT(&heap, &node10);
  Heap_AddNewNodeToCompleteBT(&heap, &node11);
  
  // Checking the height function
  printf("\n\n----------------------- EXERCISE HEIGHT\n");
  const int height = Heap_FindMaxDepth(&heap);
  printf("Found height = %i \n", height);
  
  // Check if the storing in an array of nodeptrs works 
/*
  printf("\n\n-----------------------\n");
  printf("Checking the heap -> array conversion function. \n");
  BinarytreeNodeType* arr_nodeptrs[heap.n_nodes];
  memset(arr_nodeptrs, 0, sizeof(arr_nodeptrs));
  int arr_idx = 0;
  TraversePreorderAndStoreToArr(heap.root, arr_nodeptrs, &arr_idx);
  for (arr_idx = 0; arr_idx < heap.n_nodes; ++arr_idx) {
    printf("In array of nodeptrs at %i is node with data: %i \n",
            arr_idx, arr_nodeptrs[arr_idx]->data);
  }
*/
  
  // Sort the tree into a maxHeap
/*
  printf("\n\n----------------------- Max Heap Sort \n");
  SortCompleteBTToMaxHeap(&heap);
  TraversePreorderRecursion(heap.root, 0);
*/
    
  // Sort the tree into a minHeap
  printf("\n\n----------------------- Min Heap Sort \n");
  SortCompleteBTToMinHeap(&heap);
  BinaryTree_PrintPreOrderRecursion(heap.root);
  
  // Insert a new element and sort the tree afterwards !
  printf("\n-----------------------  EXERCISE AddNewNode\n");  
  Heap_Push(&heap, &node12, heap.compfun_ptr);
  BinaryTree_PrintPreOrderRecursion(heap.root);
  
  // Pop Root
  printf("\n-----------------------  EXERCISE Pop Root\n");  
  Heap_Pop(&heap, heap.compfun_ptr);
  BinaryTree_PrintPreOrderRecursion(heap.root);
  Heap_Pop(&heap, heap.compfun_ptr);
  BinaryTree_PrintPreOrderRecursion(heap.root);
    
  // Sort almos
  printf("\n-----------------------  EXERCISE Sort using heap\n");  
  int almost_sorted_array[] = {0, 4, 2, 6, 1, 7, 3, 5, 9, 10, 8 };
  const int len_arr = 11;
  const int max_offset = 3;
  // Note: the comparator function you pass here, needs to match the order
  //       in the almost sorted array !
  Heap_SortAlmostSortedArray(BinaryTree_CompFunPtrToNodePtr_Ascending, 
          max_offset, len_arr, almost_sorted_array);
  int i = 0;
  for (i = 0; i < len_arr; ++i) {
    printf("arr[%i] = %i \n", i, almost_sorted_array[i]);
  }
  
  
}



//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
  

/**
 * This function traverses the tree and stores all visited nodes
 * in the passed pointer "arr_nodeptrs", which is expected
 * to be allocated for enough memory.
 * 
 * @param root
 * @param arr_nodeptrs
 * @param idx
 */
void BinaryTree_TraversePreorderStoreNodesToArr(BTNodeT* root,
        BTNodeT** arr_nodeptrs, int* idx) {
  if (root == NULL) {
    return;
  }
  arr_nodeptrs[*idx] = root;
  (*idx)++;
  BinaryTree_TraversePreorderStoreNodesToArr(root->left, arr_nodeptrs, idx);
  BinaryTree_TraversePreorderStoreNodesToArr(root->rght, arr_nodeptrs, idx);
  return;
}

/**
 * The height (or maxDepth) of a complete tree is easily
 * found in log(n) steps by running left as far as possible.
 * 
 * @param heap
 * @return 
 */
int Heap_FindMaxDepth(HeapType* heap) {
  BTNodeT* curr_node = heap->root;
  if (curr_node == NULL) {
    return -1;
  }
  int maxdepth = 0;
  while (curr_node->left) {
/*
    printf("Searching for the maximum height, traversed node with data %i \n", 
            curr_node->data);
*/
    curr_node = curr_node->left;
    ++maxdepth;
  }
/*
  printf("Searching for the maximum height, traversed node with data %i \n", 
            curr_node->data);
*/
/*
  printf("Found height = %i \n", maxdepth);
*/
  return maxdepth;
}

int Heap_LinearIdxOfFirstNodeInLevel(int level) {  
  return pow(2, level) - 1;
}

/*
 * This function converts the linear indices
 *   
 *                          0                                 Level 0
 *             1                          2                   Level 1
 *       3            4            5             6            Level 2
 *    7     8       9   10      11   12      13     14        Level 3
 * 
 * to the pair of (level, idx_in_level)
 * 
 *                                (0,0)                                Level 0
 *                (1,0)                            (1,1)               Level 1
 *       (2,0)             (2,1)           (2,2)           (2,3)       Level 2
 *  (3,0)     (3,1)   (3,2)    (3,3)   (3,4)   (3,5)   (3,6)    (3,7)  Level 3
 * 
 * 
*/
PairIdxType Heap_FindPairIdxFromLinearIdx(int linear_idx) {
  PairIdxType pair_idx;
  // Compute level of the parent node
  int level = 0;
  int idx_max_level = 0;
  while (idx_max_level < linear_idx) {
    ++level;
    idx_max_level = pow(2, level + 1) - 2;
  }
/*
  printf("Parent will be at level %i \n", level);  
*/
  
  // Compute running_number of new_node inside the level
  const int linear_idx_1stnodeinsidelevel = 
    Heap_LinearIdxOfFirstNodeInLevel(level);
  int idx_inside_level = linear_idx - linear_idx_1stnodeinsidelevel;
/*
  printf("The parent will be at idx %i inside that level.\n", 
          idx_inside_level);
*/
  
  pair_idx.level = level;
  pair_idx.idx_in_level = idx_inside_level;          
  return pair_idx;
}
/**
 * Deduce the path from the running number
 * --> we know how many turns the path will make from the level
 *     left-turn : 0
 *     rght-turn : 1
 * 
 * Note: we assume that arr_turns_to_node is allocated in the
 *       caller scope to store at least "level" entries
 * 
 * @param level
 * @param inlevelidx
 * @param arr_turns_to_node
 */
void Heap_FillPathToNodeUsingInlevelidx(const int level, int inlevelidx, 
        int* arr_turns_to_node) {  
  //int path[level];
  memset(arr_turns_to_node, -1, sizeof(arr_turns_to_node));
  int curr_level;
  for (curr_level =  level - 1; curr_level >= 0; --curr_level) {
    arr_turns_to_node[curr_level] = (inlevelidx % 2 == 0) ? 0 : 1;
    inlevelidx /= 2;
  }
  int k = 0;
  for (k = 0; k < level; k++) {
    printf("Path to get to parent: at level %i, turn %i \n", k, arr_turns_to_node[k]);
  }
  
  return;
}

/**
 * Given the absolute index of a node, finde the pointer to the 
 * belonging parent node in the heap.
 * 
 * @param heap
 * @param idx_node
 * @return 
 */
BTNodeT* Heap_FindParentOfNodeatidx(HeapType* heap, int idx_node) {
  
  // TODO: handle case that index is so far off, that there is no
  //       valid parent in the heap yet
  
  const int idx_parent = (idx_node - 2 + (idx_node % 2)) / 2;
  //printf("The absolute index of the parent node is %i. \n", idx_parent);
    
  PairIdxType pair_idx = Heap_FindPairIdxFromLinearIdx(idx_parent);
  const int level_parent = pair_idx.level;
  int idx_inlevel_parent = pair_idx.idx_in_level;
  
  int path[level_parent];
  Heap_FillPathToNodeUsingInlevelidx(level_parent, idx_inlevel_parent, path);
  
  // follow the path to the node and insert
  int k = 0;
  BTNodeT* parent_node = heap->root;
  for (k = 0; k < level_parent; k++) {
    if (path[k]) parent_node = parent_node->rght;
    else parent_node = parent_node->left;
  }
  
/*
  printf("We have reached the supposed parent! It has data %i.\n", 
          parent_node->data);
*/
  
  return parent_node;
}


void SortCompleteBTToHeap(HeapType* heap) {
  Heap_ConstructFromCompleteBTAndCompareFun(heap, heap->compfun_ptr);
  return;
}

void SortCompleteBTToMaxHeap(HeapType* heap) {
  Heap_ConstructFromCompleteBTAndCompareFun(heap, BinaryTree_CompFunPtrToNodePtr_Descending);
  return;
}

void SortCompleteBTToMinHeap(HeapType* heap) {
  Heap_ConstructFromCompleteBTAndCompareFun(heap, BinaryTree_CompFunPtrToNodePtr_Ascending);
  return;
}

void Heap_ConstructFromCompleteBTAndCompareFun(HeapType* heap,
        int (*compFun_if1stargLess2ndargResultLess0)(const void*, const void*)) {
/*
  printf("Entering Sorting routine for the heap.\n");
*/
  const int height = Heap_FindMaxDepth(heap);
  
  // store each node of the heap in an array  
  //printf("Storing all heap nodes in an array:\n");
  BTNodeT* arr_nodeptrs[heap->n_nodes];
  memset(arr_nodeptrs, 0, sizeof(arr_nodeptrs));
  int arr_idx = 0;
  BinaryTree_TraversePreorderStoreNodesToArr(heap->root, arr_nodeptrs, &arr_idx);
  
  // sort the array
/*
  for (arr_idx = 0; arr_idx < heap->n_nodes; ++arr_idx) {
    printf("Before sort: arr_nodes[%i], data=%i \n",
            arr_idx, arr_nodeptrs[arr_idx]->data);
  }
*/
  qsort(arr_nodeptrs, heap->n_nodes, sizeof(BTNodeT*), 
          compFun_if1stargLess2ndargResultLess0);  
/*
  for (arr_idx = 0; arr_idx < heap->n_nodes; ++arr_idx) {
    printf("After  sort: arr_nodes[%i], data=%i \n",
            arr_idx, arr_nodeptrs[arr_idx]->data);
  }  
*/
  
  // build up the heap from the array, by finding for each node
  // the parent and then inserting the node as a child to the parent
  //printf("-----\n");
  //printf("Arrange nodes from array to form a heap \n");
  heap->root = arr_nodeptrs[0];
  heap->root->left = NULL;
  heap->root->rght = NULL;
  
  BTNodeT* parent_node = NULL;
  BTNodeT* new_child = NULL;
  const int linear_idx_1stnodeMaxLevel = 
    Heap_LinearIdxOfFirstNodeInLevel(height);
  for (arr_idx = 1; arr_idx < heap->n_nodes; ++arr_idx) {
    new_child = arr_nodeptrs[arr_idx];
    parent_node = Heap_FindParentOfNodeatidx(heap, arr_idx);
    if (arr_idx % 2 == 1) {
      parent_node->left = new_child;
    } else {
      parent_node->rght = new_child;
    }
    
    
    new_child->left = NULL;
    new_child->rght = NULL;
    
    // set leaves to have no children  // TODO: remove ! redundant
    if (arr_idx >= linear_idx_1stnodeMaxLevel) {
      new_child->left = NULL;
      new_child->rght = NULL;
    }
  }
  
  return;
}

/**
 * Check whether a node is a leaf by looking at the linear index.
 * 
 * @param lin_idx
 * @param height
 * @return 
 */
bool Heap_IsNodeInLastLevelUsingLinearIdx(const int lin_idx, const int height) {
  const int lin_idx_1stnodeMaxLevel = 
    Heap_LinearIdxOfFirstNodeInLevel(height);
  return lin_idx >= lin_idx_1stnodeMaxLevel ? true : false;
}

/**
 * This function differs from  "InsertNewNodeIntoCompleteBT",
 * which is a helper below, in that after inserting the new node
 * into the tree it ensures that the tree is a heap, i.e.
 * fullfills the ordering.
 * 
 * @param heap
 * @param new_node
 */
void Heap_Push(HeapType* heap, 
        BTNodeT* new_node, 
        int (*compfun_ptr)(const void*, const void*) ) {
  if (new_node == NULL) {
    printf("Cannot add NULL to the heap. \n");
    return;
  }
  
/*
  printf("ADD: Node with data %i will be added to heap such that heap ordering is fulfilled. \n", 
          new_node->data);
*/
    
  // Insert the new element , thus destroying the order
  Heap_AddNewNodeToCompleteBT(heap, new_node);
  
  // sort the new node:
  // TODO: at the moment we are reordering the whole heap
  //       --> actually one would only need to have the
  //           new node inserted somewhere and let the 
  //           old node at that position sink down
  Heap_ConstructFromCompleteBTAndCompareFun(heap, compfun_ptr);
    
  return ;
}

/**
 * This function inserts a new node into a heap.
 * 
 * --> note: the function works for any complete binary tree !
 *           
 * Note: it can be used to insert into a heap
 *       by sorting the heap after using this function 
 *       for inserting the new node.
 * 
 * @param heap
 * @param new_node
 */
void Heap_AddNewNodeToCompleteBT(HeapType* heap, 
        BTNodeT* new_node) {
  if (new_node == NULL) {
    return;
  }
  
  // make sure the new node is a leaf
  new_node->left = NULL;
  new_node->rght = NULL;
  
  // corner case: heap is empty
  if (heap->root == NULL) {
  printf("--------- ADD node with data %i to empty tree. \n", new_node->key);
    heap->root = new_node;
    heap->n_nodes = 1;
    return;
  }
  
  // Compute linear index of the parent node
  const int idx_new_node = heap->n_nodes; // play here to see if algo for path works
  printf("--------- ADD node with data %i (temporarily at idx %i) \n", new_node->key, idx_new_node);
  
  // Find parent node over that index
  BTNodeT* parent_node = Heap_FindParentOfNodeatidx(heap, idx_new_node);
  
  // Insert new_node  
  if (idx_new_node % 2 == 1) {
    parent_node->left = new_node;
  } else {
    parent_node->rght = new_node;    
  }
  ++(heap->n_nodes);
  return;
}

/**
 * Popping from heap is implemented here in 3 steps:
 * 
 *   - remove last node from bottom of heap and make it the new root
 *   - sink down the new node at the top by recursively swapping
 *     it with the bigges/smallest child if necessary for 
 *     fullfilling the ordering relation
 * 
 * @param heap
 * @return 
 */
BTNodeT* Heap_Pop(HeapType* heap, 
        int (*compfun_ptr)(const void*, const void*)) {
  if (heap->root == NULL) {
    printf("Heap is empty. Not popping anything. \n");
    return NULL;
  }
  // remove last node from bottom of heap and make it the new root
  BTNodeT* old_root = heap->root;
  printf("%i nodes in heap. popping top node. It had data %i .\n", heap->n_nodes,
          old_root->key);
  const int lin_idx_last_node = heap->n_nodes - 1;
  if (lin_idx_last_node == 0) {
    printf(" --> heap only contained this node and is empty now \n");
    heap->root = NULL;  
  } else {
/*
    printf("Find previously last node to make it the new root.\n");
*/
    BTNodeT* parent_last_node = Heap_FindParentOfNodeatidx(heap, 
            lin_idx_last_node);
    bool last_node_is_leftchild = (lin_idx_last_node % 2) ? 1 : 0;
    BTNodeT* last_node = last_node_is_leftchild ?
      parent_last_node->left : parent_last_node->rght;     
/*
    printf("Last node has data = %i. Its parent has data = %i \n", 
            last_node->data, 
            parent_last_node->data); 
*/
    // make the last node the new root of the heap
    // by taking over its children
    // --> not only switching data but really switching nodes because
    //     in practice the data at each node could be huge
    heap->root = last_node;
    if (last_node == old_root->rght) {
      heap->root->left = old_root->left;
      heap->root->rght = NULL;      
    } else if  (last_node == old_root->left) {
      heap->root->left = NULL;
      heap->root->rght = NULL;      
    } else {
      heap->root->left = old_root->left;
      heap->root->rght = old_root->rght;
    }
    old_root->left = NULL;
    old_root->rght = NULL;
    // Remove from the heap
    if (last_node_is_leftchild) {
      parent_last_node->left = NULL;
    } else {
      parent_last_node->rght = NULL;
    }    
  }
  --(heap->n_nodes);    
  
  // sinking down the new root as far as needed to have heap order satisfied
  Heap_BubbleDownTopNode(heap, heap->root);
  
  return old_root;
}

/**
 * After popping the old root, we expect to have temporarily a node
 * at the root which violates the ordering relation
 * 
 * --> here we check whether it fulfills the ordering relation
 *     and recursively swap it until it reaches the bottom of the heap
 *     if necessary
 * 
 * @param heap
 */
BTNodeT* Heap_BubbleDownTopNode(HeapType* heap, 
        BTNodeT* topnode) {
  if (heap == NULL || topnode == NULL) {
    return NULL;
  }  
  // three nodes
  BTNodeT* oldtop = topnode;
  BTNodeT* oldleft = oldtop->left;
  BTNodeT* oldrght = oldtop->rght;  
  // three values to compare: root, left, rght
  BTNodeT* max_node = oldtop; // max in the sense of the heap ordering
  if (oldleft) {
   max_node = heap->compfun_ptr((const void*)&max_node, (const void*)&oldleft) < 0 ?
     max_node : oldleft;  
  }
  if (oldrght) {
   max_node = heap->compfun_ptr((const void*)&max_node, (const void*)&oldrght) < 0 ? 
     max_node : oldrght;
  }
/*
  printf("Of the nodes with data l=%i, c=%i, r=%i \n", 
          oldleft ? oldleft->data : -1, 
          oldtop->data, 
          oldrght ? oldrght->data : -1);
  printf("--> the node which *should* be on top is with data %i \n", 
          max_node->data);
*/
  if (max_node == oldtop) {
    // everything fine, root can stay in place and we can return without swapping
    return oldtop;
  } else if (max_node == oldleft) {
/*
    printf("Swapping nodes with data %i and %i \n", 
            oldtop->data, max_node->data);
*/
    // swap oldtop <-> oldleft
    oldtop->left = max_node->left;
    oldtop->rght = max_node->rght;
    if (oldtop == heap->root) {
      heap->root = max_node;
    }
    // Recurse to find the new left child:
    // --> the oldtop could sink in further, so we have
    max_node->rght = oldrght;
    max_node->left = Heap_BubbleDownTopNode(heap, oldtop);
  } else if (max_node == oldrght) {
/*
    printf("Swapping nodes with data %i and %i \n", 
            oldtop->data, max_node->data);
*/
    // swap oldtop <-> oldrght
    oldtop->left = max_node->left;
    oldtop->rght = max_node->rght;
    if (oldtop == heap->root) {
      heap->root = max_node;
    }
    max_node->left = oldleft;
    max_node->rght = Heap_BubbleDownTopNode(heap, oldtop);
  } else {
    printf("Implementation error. Check. \n");
  }
  return max_node;
}

/**
 * We expect an input that is almost sorted, which means
 * each element is only off from its correct position 
 * by <= max_offset positions.
 * 
 * @param max_offset
 * @param len
 * @param arr
 */
void Heap_SortAlmostSortedArray(int (*compFun_if1stargLess2ndargResultLess0)(const void*, const void*),
        const int max_offset, 
        const int len, 
        int* arr) {
  
  // create a max heap
  HeapType heap = { NULL, compFun_if1stargLess2ndargResultLess0, 0 };
  const int max_elems_heap = max_offset + 1;  
  BTNodeT arr_nodes[max_elems_heap];  
  int i = 0;
  for (i = 0; i < max_elems_heap; ++i) {
    arr_nodes[i].key = arr[i];
    Heap_Push(&heap, arr_nodes + i, heap.compfun_ptr); // O(log(max_offset + 1))
  }
  
  // pop a node and reinsert it with changed data
  BTNodeT* popped_node = NULL;
  i = 0;
  while (heap.n_nodes > 0 ) {
    popped_node = Heap_Pop(&heap, heap.compfun_ptr);
    arr[i] = popped_node->key;
    if (i < len - max_elems_heap) {
      popped_node->key = arr[i + max_elems_heap];
      Heap_Push(&heap, popped_node, heap.compfun_ptr);
    }
    ++i;
  }
  
  return;
}



/**
 * ACHTUNG: unfinished... need a more general heap 
 *          that stores two ints instead of one...
 * 
 * We are given an array in which each block of k-elements
 * is ordered such that after the first element the next
 * k/2 elements are each bigger than the previous and then
 * the next k/2 -1 elements are each smaller than the 
 * previous one (actually even the next k/2 elements are smaller
 * than the previous one, but the last element is 
 * counted to the next block)
 * 
 * E.g. for k = 6: 
 * 2, 4, 6, 9, 7, 3 | 1, 3, 5, 6, 5, 2 | 0, 4, 10, 12, 6, 1 |
 * 
 * E.g. for k = 5: 
 * 2, 4, 6, 5, 2 | 1, 3, 11, 4, 3 | 1, 6, 7, 4, 3 |
 * 
 * For sorting it is better to divide each block in two such that 
 * in each block the elements are fully sorted:
 * E.g. for k = 6: 
 * 2, 4, 6, 9 | 7, 3 | 1, 3, 5, 6 | 5, 2 | 0, 4, 10, 12 | 6, 1 |
 * 
 * E.g. for k = 5: 
 * 2, 4, 6 | 5, 2 | 1, 3, 11 | 4, 3 | 1, 6, 7 | 4, 3 |
 * 
 * --> then one can track the index of the current maximum
 *     in each of the blocks ( there exist n/(k/2) blocks )
 *     and insert all these current maxima into a heap
 *     from which the new sorted array is filled step by step
 * 
 * To do this, one needs to have the information for each
 * maximum in the heap which array it was taken from so that
 * from there we can pick the next value if this maximum
 * is transferred from the heap to the sorted array.
 * 
 * Note: we count the very first element to the first block.
 * 
 * @param arr
 * @param len
 */
/*
void SortKIncreasingArrWithAHeap(const int period, 
        const int len,int* arr) {
  if (len % period != 0) {
    printf("Array does not have a valid format \n");
    return;
  }  
  
  const int n_blocks = len / period;
  const int n_sorted_blocks = 2 * n_blocks;
  
  // array to track max_idx in each sorted block
  int curr_max_idx[n_sorted_blocks];
  int i_block = 0;
  const int offset_max_to_1stelem = period/2 + (period + 1) % 2;
  int idx_1stelem_inblock;  
  for (i_block = 0; i_block < n_blocks; ++i_block) {
    idx_1stelem_inblock = i_block*period;
    curr_max_idx[i_block] = idx_1stelem_inblock + offset_max_to_1stelem;
    curr_max_idx[i_block] = curr_max_idx[i_block] + 1;
  }
  
  // initial filling of heap
  for (i_block = 0; i_block < n_blocks; ++i_block) {
    // TODO: we need to have nodes that store not only
    //       integer, but another integer which gives 
    //       the block from which the max was taken
  }    
  return; 
}
*/