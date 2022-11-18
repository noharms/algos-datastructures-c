/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   exercises_string.h
 * Author: noh
 *
 * Created on March 7, 2018, 3:27 PM
 */

#ifndef EXERCISES_STRING_H
#define EXERCISES_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

  #include <stdbool.h>
  
  void MainStrings();

  void MainStrings_SomeBasicStringTests();
  void MainStrings_StringToInt();
  void MainStrings_IntToString();
  void MainStrings_StringBase1ToStringBase2();
  void MainStrings_LongestSubstringEqualStartEndChar();
  void MainStrings_SquareRotationEncodingDecoding();
  void MainStrings_StrTokSelfImplementation();

  //------------------------------------------------- algos
  
  void Strings_SomeBasicStringTests();
  int Strings_StringToInt(const char* const str);
  void Strings_IntToString(int number, char* str);

  void Strings_StringBase1ToStringBase2(const int base1, const int base2, 
        const int max_num_digits, char str_base1[], char str_base2[]) ;  
  int CharToDecimalNumber(char c);
  int CharToDecimalNumberElegant(char c);
  char DecimalNumberToChar(int decimal_num);
  void ReverseString(char str[]);

  int Strings_LongestSubstringEqualStartEndChar(char* str);


  char* Strings_EncodeBySquaringAndRotating(char* s);
  char* Strings_DecodeSquaredAndRotatedString(char* squared_and_rot);
  int LinIdx(int dim, int i, int j);
  int FindLenAndDimSquareString(char* squared, int* dim);
  char* MakeSquared(char* s);
  char* MakeLinear(char* squared);
  char* RotateSquaredString_90Clockwise(char* squared);
  char* RotateSquaredString_90AntiClockwise(char* squared);
  
  char* Strings_StrTokSelfimplemented(char *src, const char *delims);
  void AdvanceUntilNoMatchOrNull(char** iter, const char* targets);
  void AdvanceUntilMatchOrNull(char** iter, const char* targets);
  bool CharContainedInString(const char* haystack,  char needle);

  
#ifdef __cplusplus
}
#endif

#endif /* EXERCISES_STRING_H */

