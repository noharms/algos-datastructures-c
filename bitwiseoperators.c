/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

// corresponding h file
#include "bitwiseoperators.h"

// system files
#include <math.h>
#include <stdio.h>

// other c-files' headers and project-wide headers
#include "standardheaders.h"


void MainBitwiseOperators(){
  printf("\n\n----------------------- MainBitwiseOperators \n");
  
  //-----------------------------------------
  // preparations:
  
  //-----------------------------------------
  // Exercises  
      
  MainBitwiseOperators_Warmup();
    
  MainBitwiseOperators_UnsetLowestSetBit();
  
  MainBitwiseOperators_IndexLowestSetBit();
  
  MainBitwiseOperators_SwapByBitwise();  
  
  MainBitwiseOperators_IsPowerOfTwo();  
    
  return;
}



//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void MainBitwiseOperators_Warmup(){
  printf("\n----------------------------------- MainBitwiseOperators_Warmup \n");
  
  // checking bitwise operators
  unsigned int x = 1;
  unsigned int y = 1;
  
  // negation of 0 yields the maximum value !
  y = ~0;
  printf("Negation of 0 yields: %u \n",y);
  
  y = ~((unsigned)0);
  printf("Negation of (unsigned) 0 yields: %u \n",y);
  
  y = ~(0u);
  printf("Negation of 0u yields: %u \n",y);
  
  y = ~(0b00000000);
  printf("Negation of 0b00000000 yields: %u \n",~(0b00000000u));
  
  printf("sizeof(unsigned int) = %lu \n", sizeof(unsigned int) );
    
  printf("1|2 = %u \n", (unsigned)(1|2));
  
  return;
}


void MainBitwiseOperators_UnsetLowestSetBit(){
  printf("\n----------------------------------- MainBitwiseOperators_UnsetLowestSetBit \n");
    
  uint8 A = 0b01010000u;
  printf("A = %u becomes %u after unsetting lowest set bit. \n", A, 
          UnsetLowestSetBit(A));
  return;
}
  
  

void MainBitwiseOperators_IndexLowestSetBit(){
  printf("\n----------------------------------- MainBitwiseOperators_IndexLowestSetBit \n");
  
  // lowermost set bit
  uint8 A = 0b01010000u;
  uint8 B = 0b00011000u;
  uint8 C = 0b00011001u;
  const uint8 idx_low_A = IdxLowestSetBit(A);
  const uint8 idx_low_B = IdxLowestSetBit(B);
  const uint8 idx_low_C = IdxLowestSetBit(C);
  printf("lowermost set bit in A=%u is at idx %u \n", A, idx_low_A);
  printf("lowermost set bit in B=%u is at idx %u \n", B, idx_low_B);
  printf("lowermost set bit in B=%u is at idx %u \n", C, idx_low_C);
  
  
  return;
}


void MainBitwiseOperators_SwapByBitwise(){
  printf("\n----------------------------------- MainBitwiseOperators_SwapByBitwise \n");
    
  // swapping
  uint8 A = 0b01010000u;
  uint8 B = 0b00011000u;
  uint8 C = 0b00011001u;
  printf("A=%u and B=%u \n",A,B);
  SwapByBitwiseOps(&A,&B);
  printf("After Swap: A=%u and B=%u \n", A,B);
  
  return;
}


void MainBitwiseOperators_IsPowerOfTwo(){
  printf("\n----------------------------------- MainBitwiseOperators_IsPowerOfTwo \n");
    
  uint8 z;
  z = pow(2,4);
  printf("Is %u a power of 2 ? --> %u \n",z, IsPowerOf2(z));
  z = pow(2,4) + 1;
  printf("Is %u a power of 2 ? --> %u \n",z, IsPowerOf2(z));  
  
  return;
}

  
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

//-------------------------------------------------------------- API


//-------------------------------------------------------------- Algos

/**
 * e.g.:  x= 1100    x-1= 1011
 *      -> x & (x-1) = 1000
 * 
 * @param x
 * @return 
 */
uint8 UnsetLowestSetBit(uint8 x) {
  return x & (x - 1);
}

/**
 * Index of the lowest set bit, with the LSB being at index 0
 * and counting up from right to left.
 * 
 * @param x
 * @return 
 */
uint8 IdxLowestSetBit(uint8 x){
  return (x == 0 ? -1 : (uint8)(log(x & (~(x - 1)))/log(2))); 
}


/**
 * if x is 2^k , there is only one bit = 1, other = 0
 * 
 * -> unset lowest set bit and check result
 * 
 * @param x
 * @return 
 */
uint8 IsPowerOf2(const uint8 x){
  
  // 
  const uint8 y = x-1u;
  
  // if x was 2^k then,  x&y should be a all 0's !
  // if x was not 2^k then x&y should be unequal 0 because the
  // highest bit will stay in place
  const uint8 z = x & y;
  
  return !z; 
  
}
/**
 * Note: spares the additional variable
 * 
 * @param x
 * @param y
 */
void SwapByBitwiseOps(uint8* const x, uint8* const y){  
  *x = *x ^ *y;  
  *y = *x ^ *y;          
  *x = *x ^ *y;  
  return;  
}
