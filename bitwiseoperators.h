/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   binaryoperators.h
 * Author: noh
 *
 * Created on February 25, 2018, 4:05 PM
 */

#ifndef BINARYOPERATORS_H
#define BINARYOPERATORS_H

#ifdef __cplusplus
extern "C" {
#endif

  typedef unsigned char uint8;

  void MainBitwiseOperators();  
  
  void MainBitwiseOperators_Warmup();
  void MainBitwiseOperators_UnsetLowestSetBit();
  void MainBitwiseOperators_IndexLowestSetBit();
  void MainBitwiseOperators_SwapByBitwise();
  void MainBitwiseOperators_IsPowerOfTwo();
  
  //------------------------------------------------- Algos
  
  uint8 UnsetLowestSetBit(uint8 x);
  uint8 IdxLowestSetBit(uint8 x);
  uint8 IsPowerOf2(const uint8 x);
  void SwapByBitwiseOps(uint8* const A, uint8* const B);
  
  


#ifdef __cplusplus
}
#endif

#endif /* BINARYOPERATORS_H */

