/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   standardheaders.h
 * Author: noh
 *
 * Created on February 25, 2018, 4:11 PM
 */

#ifndef STANDARDHEADERS_H
#define STANDARDHEADERS_H

#ifdef __cplusplus
extern "C" {
#endif

  #define SEE_ALL_FILES 1
  #define DEBUG 0

  #define MIN(x, y) (x) >= y ? (y) : (x);  
  #define MAX(x, y) (x) >= y ? (x) : (y);

  #define PREC 1E-10

  //------------------------------- typedefs  
  typedef unsigned long long ull;
  
  typedef struct INTPAIR_TYPE {
    int val1;
    int val2;
  } IntPairT;
  
  typedef struct STUDENT_TYPE {
    int age;
    char name[32];
  } StudentT;
  
  //------------------------------- DataNodes
  typedef struct DATANODE_CHAR {
    char key;    
    // add values below
  } DataNodeCharKeyT;
  
  typedef struct DATANODE_INT {
    int key;    
    // add values below
  } DataNodeIntKeyT;
  
  typedef struct DATANODE_INT_INT {
    int key;    
    // add values below
    int val;    
  } DataNodeIntKeyIntValT;
  
  #define MAX_KEY_LEN 1024

  typedef struct DATANODE_STRING {
    char key[MAX_KEY_LEN];    
    // add values below
  } DataNodeStringKeyT;      

  typedef struct DATANODE_STRING_INT {
    char key[MAX_KEY_LEN];
    // add values below
    int val;
  } DataNodeStringKeyIntValT;
  
  //------------------------------- ContainerNodes
  typedef struct LISTNODE {
    DataNodeIntKeyIntValT data;
    struct LISTNODE* next;  
  } ListNodeT;
  
  typedef struct LISTNODE_STRINGKEY {
    DataNodeStringKeyIntValT data;
    struct LISTNODE_STRINGKEY* next;  
  } ListNodeStringKeyIntValT;
    
  typedef struct BINARYTREE_NODE {
    int key;
    int val;
    struct BINARYTREE_NODE* left;
    struct BINARYTREE_NODE* rght;
  } BTNodeT;  
  
  typedef struct BINARYTREE_NODE_WITHPARENT {
    int key;
    int val;
    struct BINARYTREE_NODE_WITHPARENT* left;
    struct BINARYTREE_NODE_WITHPARENT* rght;
    struct BINARYTREE_NODE_WITHPARENT* parent;
  } BTNodeWithParentT;
    
  //---------------------------------


#ifdef __cplusplus
}
#endif

#endif /* STANDARDHEADERS_H */

