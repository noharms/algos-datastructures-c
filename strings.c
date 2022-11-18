/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

// corresponding h file
#include "strings.h"

// system files
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// other c-files' headers and project-wide headers
#include "standardheaders.h"

const unsigned char kPadChar = 11;


void MainStrings(){
  printf("\n\n----------------------- MainStrings \n");
  
  //-----------------------------------------
  // preparations:
  
  //-----------------------------------------
  // Exercises  
     
  MainStrings_SomeBasicStringTests();
  
  MainStrings_StringToInt();
  
  MainStrings_IntToString();
  
  MainStrings_StringBase1ToStringBase2();
    
  MainStrings_LongestSubstringEqualStartEndChar();  
  
  MainStrings_SquareRotationEncodingDecoding();  
    
  MainStrings_StrTokSelfImplementation();  
  
  return;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void MainStrings_SomeBasicStringTests() {
  printf("\n----------------------------------- MainStrings_SomeBasicStringTests \n");
  Strings_SomeBasicStringTests();
  return;
}

void MainStrings_StringToInt() {
  printf("\n----------------------------------- MainStrings_StringToInt \n");  
  char num_as_str[] = "412";
  int num = Strings_StringToInt(num_as_str);
  printf("Converted str %s to the number %i .\n", num_as_str, num);
  return;
}

void MainStrings_IntToString() {
  printf("\n----------------------------------- MainStrings_IntToString \n");  
#define MAX_NUMBER_DIGITS 20  
  char num_as_str[MAX_NUMBER_DIGITS];
  int num = 413;  
  Strings_IntToString(num, num_as_str);
  printf("Converted int %i to the string %s .\n", num, num_as_str);  
  return;
}

void MainStrings_StringBase1ToStringBase2() {
  printf("\n----------------------------------- MainStrings_StringBase1ToStringBase2 \n");
  const int base1 = 7;
  const int base2 = 13;
  char str_base1[MAX_NUMBER_DIGITS] = "615";
  char str_base2[MAX_NUMBER_DIGITS];
  Strings_StringBase1ToStringBase2(base1, base2, MAX_NUMBER_DIGITS, str_base1, str_base2);
  printf("The number %s in base %i becomes the number %s in base %i. \n",
          str_base1, base1, str_base2, base2);
  return;
}

void MainStrings_LongestSubstringEqualStartEndChar() {
  printf("\n----------------------------------- MainStrings_LongestSubstringEqualStartEndChar \n");  
  char ascii_string[] = "abfikjrvgkvvkgasdfdfgwfkkkqfv";
  int max_distance_two_equal_chars = 
    Strings_LongestSubstringEqualStartEndChar(ascii_string);
  printf("Found max_distance_two_equal_chars = %i \n", 
          max_distance_two_equal_chars);
  return;
}


void MainStrings_SquareRotationEncodingDecoding() {
  printf("\n----------------------------------- MainStrings_SquareRotationEncodingDecoding \n");    
  //char* input = "I.was.going.fishing.that.morning.at.ten.o'clock";
/*
  char* input = "The panel found that he was loyal and discreet with atomic secrets,"
                "but did not recommend that his security clearance be reinstated."
                "This ended his role in government and policymaking. He became an"
                "academic exile, cut off from his former career and the world he had "
                "helped to create. ";
*/
  //char* input = "n6a UglK49 IUNH1 0 u0 22Q  52TBXct5K  4 79Jchd n9 39  ";
  char* input = "4 IkXA0i 9E7  9dF2oLxpK 7 2f5 R5V Si T 55 G  rqx q  I ";
  printf("Encoding the string: \n");
  printf("%s\n\n", input);
  char* encoded = Strings_EncodeBySquaringAndRotating(input);
  printf("After encoding, the string reads: \n");
  printf("%s \n\n", encoded);
  char* decoded = Strings_DecodeSquaredAndRotatedString(encoded);
  printf("After decoding, the string reads: \n");
  printf("%s \n\n", decoded);
  // Free
  free(encoded);
  free(decoded);
  return;
}

void MainStrings_StrTokSelfImplementation() {
  printf("\n----------------------------------- MainStrings_StrTokSelfImplementation \n");    
  char str[] = "Hello old friend! How are you ? hope alright.";     
  char* delims = " .!?";
  char* token = Strings_StrTokSelfimplemented(str, delims); 
  while (token != NULL) { 
    printf("%s\n", token); 
    token = Strings_StrTokSelfimplemented(NULL, delims); 
  } 
  return;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Strings_SomeBasicStringTests() {  
  // Note: when initialising as array, you need to put the null-character !
  //       --> if you forget it here, it will compile, but you get undefined 
  //           behavior !!! (remove it here, make a run, and see changes..)
  char mystr1[] = {'H', 'e', 'l', 'l', 'o', '\0'};
  char mystr2[] = {'W', 'o', 'r', 'l', 'd', '\0'};

  // Note: if you were to give the length explicitly, remember the null-character
  //       --> if you put 5 here and leave the null-character away
  //           you will have undefined behavior again
  char mystr3[6] = {'A', 'p', 'p', 'l', 'e', '\0'};

  // Note: using string literals makes the compiler add the null-terminator (if possible)
  char mystr4[2] = "ab";   // --> bad ! no compile error, but undefined behavior!
  char mystr5[3] = "ab";   // --> good !
  
  // Note: printf expects a null-terminated char-array ! 
  //       --> if you remove the null-character above, you will see
  //           funny things here
  printf("mystr1 = %s \n", mystr1);
  printf("mystr2 = %s \n", mystr2);
  printf("\n");
  
  int i = 0;
  // note: strlen computes the length excluding the null-character !
  for (i = 0; i < strlen(mystr2) + 1; ++i) {
    printf("Char at %i is %c \n", i, mystr2[i]);
  }
  printf("\n");
    
  // Note: one has to make sure that destination has enough space to store
  //       old value plus the one of src 
  //       --> otherwise undefined behavior for strcpy and strcat !!!
  //       (e.g. might work by chance, if next bits in mem after mystr1
  //        are not occupied otherwise. but highly unsafe !!!)
  strcat(mystr1, mystr2);
  printf("undefined behavior: mystr1 after strcat with mystr2: %s \n",mystr1);
  printf("\n");
    
  printf("mystr3 = %s \n", mystr3);
  printf("\n");
    
  printf("mystr4[2] = %c --> bad! might not end with null-char. \n", mystr4[2]);
  printf("mystr5[2] = %c --> good. ends with null-character (actually null-char cannot be printed..) \n", mystr5[2]);
  printf("\n");
  
  return;
}

/**
 * Assume given char array is ordered reversely, i.e.
 * for a number 4241
 * index 0: 4, index 1: 2, index 2: 4, index 3: 1
 * 
 * @param str
 * @return 
 */
int Strings_StringToInt(const char* const str) {
  
  // TODO: catch invalid input (chars that are no digits)
  // TODO: remove leading whitespaces  
  int converted_int = 0;
  int i = 0;
  int power = 0;
  const int ascii_index_0 = (int) '0';
  for (i = strlen(str) - 1; i >= 0; --i, power++) {    
    char char_at_this_power = str[i];
    // convert char to int
    int ascii_index = (int) char_at_this_power;    
    int corresponding_digit = ascii_index - ascii_index_0;
    converted_int += pow(10, power) * corresponding_digit;
  }   
  return converted_int;
}

/**
 * 
 * @param base1
 * @param base2
 * @param max_num_digits
 * @param str_base1
 * @param str_base2
 */
void Strings_IntToString(int number, char* str) {
  
  // count number of digits
  int number_cpy = number;
  int n_digits = 0;
  while (number_cpy) {
    number_cpy /= 10;
    ++n_digits;
  }  
  printf("The number %i was found to contain %d digits \n.", number, n_digits);

  int i = 0;
  int digit = 0;
  const int ascii_index_0 = (int) '0';
  for (i = 0; i < n_digits; ++i) {
    digit = number % 10;
    number /= 10;
    str[i] =  (char) (ascii_index_0 + digit);
  }
  str[n_digits] = '\0';
  return;
}


/**
 * str1_base and str2_base are arrays allocated for max_num_digits
 * str1_base is already filled, not necessarily until max_num_digits
 * str2_base should be empty and will be filled here.
 * 
 * @param str_base1
 * @param str_base2
 * @param len
 */
void Strings_StringBase1ToStringBase2(const int base1, const int base2, 
        const int max_num_digits, char str_base1[], char str_base2[]) {
  
  // TODO: catch wrong input.. Assuming correct input first
  //       in particular, assuming str_base1/2 are both allocated for
  //       length max_num_digits
  
  // build decimal number
  int n_digits_base1 = strlen(str_base1);
  printf("Found %i digits in str %s. \n.", n_digits_base1, str_base1);
  int dec_num = 0;
  int i = 0;
  char current_char = '\0';
  int current_digit_in_decimal = 0;
  do {
     current_char = str_base1[n_digits_base1 -1 - i];
     if (current_char != '\0') {
      current_digit_in_decimal = CharToDecimalNumberElegant(current_char);
      printf("10 to %i: current_char = %c, current_digit_dec = %i \n",
              i, current_char, current_digit_in_decimal);
      dec_num += pow(base1, i) * current_digit_in_decimal;
      ++i;
     }
  } while (current_char != '\0');
  
  printf("Decimal number found from string %s is %i \n", str_base1, dec_num);
  
  // get base2 digits
  int n_digits_base2 = 0;
  int current_digit_in_base2;
  char current_char_in_base2;
  do {
    current_digit_in_base2 = dec_num % base2; // note can reach up to 15
    current_char_in_base2 = DecimalNumberToChar(current_digit_in_base2);
    str_base2[n_digits_base2] = current_char_in_base2;
    dec_num /= base2;
    ++n_digits_base2;
    if (n_digits_base2 == max_num_digits && dec_num) {
      printf("In base2 the representation of %s would need more than %i digits \n", str_base1, max_num_digits);
    }
  } while (dec_num && n_digits_base2 < max_num_digits);
  str_base2[n_digits_base2] = '\0';
  // we have the least significant digit at the start of the string
  // --> usually one writes it the other way around
  ReverseString(str_base2);
  return;
}

int CharToDecimalNumber(char c) {
  char possible_chars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' \
                         , 'A', 'B', 'C', 'D', 'E', 'F'};
  // TODO: check that c is in possible_chars
  int dec_num = 0;
  switch (c) {
    case '0': 
      dec_num = 0;
      break;
    case '1': 
      dec_num = 1;
      break;
    case '2': 
      dec_num = 2;
      break;
    case '3': 
      dec_num = 3;
      break;
    case '4': 
      dec_num = 4;
      break;
    case '5': 
      dec_num = 5;
      break;
    case '6': 
      dec_num = 6;
      break;
    case '7': 
      dec_num = 7;
      break;
    case '8': 
      dec_num = 8;
      break;
    case '9': 
      dec_num = 9;
      break;
    case 'A': 
      dec_num = 10;
      break;
    case 'B': 
      dec_num = 11;
      break;
    case 'C': 
      dec_num = 12;
      break;
    case 'D': 
      dec_num = 13;      
      break;
    case 'E': 
      dec_num = 14;
      break;
    case 'F': 
      dec_num = 15;
      break;
  }
  return dec_num;
}


int CharToDecimalNumberElegant(char c) {
  int dec_num = 0;
  if (isdigit(c)) {
    dec_num = c - '0';
  } else {  // expecting c is between 'A' - 'F'
    dec_num = c - 'A' + 10;
  }
  return dec_num;
}


char DecimalNumberToChar(int decimal_num) {
  char possible_chars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' \
                         , 'A', 'B', 'C', 'D', 'E', 'F'};
  // TODO: check that decimal_num < 16  
  return possible_chars[decimal_num];
}


void ReverseString(char str[]) {
  int len_str = strlen(str); // Rem: strlen does not include '\0' char
  int i = 0;
  for (i = 0; i < len_str / 2; ++i) {
    char tmp_c = str[i];
    str[i] = str[len_str - 1 - i];
    str[len_str - 1 - i] = tmp_c;
  }
  return;
}


#define N_ASCII_CHARS 256
/**
 * GOOGLE question
 * 
 * @param str
 * @return 
 */
int Strings_LongestSubstringEqualStartEndChar(char* str) {
  
  int len_str = strlen(str);
  
  // count occurences to find candidates
  int occurences[N_ASCII_CHARS] = { 0 };
  int i = 0;
  char curr_char = '\0';
  for (i = 0; i < len_str; ++i) {
    curr_char = str[i];
    ++occurences[curr_char];
  }
  
  // find length of substring for each char that appears at least 2
  int len_substrings[N_ASCII_CHARS] = { 0 };
  int len_substring = 0;
  int l = 0, r = len_str - 1;
  for (i = 0; i < N_ASCII_CHARS; ++i) {    
    if (occurences[i] > 1) {
      while (str[l] != i) {
        ++l;
      }
      while (str[r] != i) {
        --r;
      }
      len_substring = r - l + 1;
      len_substrings[i] = len_substring;
    }
  }
  
  // find max
  int max_len_substring = 0;
  char char_with_max_distance = '\0';
  for (i = 0; i < N_ASCII_CHARS; ++i) {  
    if (len_substrings[i] > max_len_substring) {
      max_len_substring = len_substrings[i];
      char_with_max_distance = i;
    }
  }
  printf("Char with max distance in string is %c \n", char_with_max_distance);
  
  return max_len_substring;
}


/**
 * ACHTUNG: caller must free result
 * 
 * @param s
 * @return 
 */
char* Strings_EncodeBySquaringAndRotating(char* s) {      
  char* s_squared = MakeSquared(s);    
  char* s_squared_rot = RotateSquaredString_90Clockwise(s_squared);  
  free(s_squared);
  return s_squared_rot;
}

/**
 * ACHTUNG: caller must free result
 * 
 * @param squared_and_rot
 * @return 
 */
char* Strings_DecodeSquaredAndRotatedString(char* squared_and_rot) { // assume s is squared string  
  char* s_rot = RotateSquaredString_90AntiClockwise(squared_and_rot);
  char* s_linearized = MakeLinear(s_rot);  
  // remove padding char
  int str_len = strlen(s_linearized);
  int i = str_len - 1;
  while (i >= 0 && s_linearized[i] == kPadChar) {
    s_linearized[i--] = '\0';
  }
  // Free
  free(s_rot);
  return s_linearized;
}
/**
 * ACHTUNG: caller must free result
 * @param s
 * @return 
 */
char* MakeSquared(char* s) {  
  int l = strlen(s);
  int n = ceil(sqrt(l));  
  char* s_squared = calloc(n * n + n, sizeof(char)); // +n - 1 for linebreaks, +1 for null-terminator
  s_squared[n * n + n - 1] = '\0';
  int i, j;    
  // copy filling
  int k;
  for (k = 0; k < l; ++k) {
    i = k / n;
    j = k % n;
    int write_i = LinIdx(n + 1, i, j);    
    s_squared[write_i] = s[k];      
  }
  // pad with padChar
  for (j = LinIdx(n + 1, l / n, l % n); j < n * n + n - 1; ++j) {
    s_squared[j] = kPadChar;    
  }
  // add line-breaks:
  for (i = 0; i < n - 1; ++i) {
    int write_i = LinIdx(n + 1, i, n);
    s_squared[write_i] = '\n';    
  }
  return s_squared;
}
/**
 * ACHTUNG: caller must free result
 * @param squared
 * @return 
 */
char* MakeLinear(char* squared) { // assume s is squared string
  int l = strlen(squared);
  int n = floor(sqrt(l));
  char* s_linearized = calloc(n * n + 1, sizeof(char)); 
  s_linearized[n * n] = '\0';
  int i, j, write_i = 0;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      s_linearized[write_i++] = squared[LinIdx(n + 1, i, j)];
    }
  }  
  return s_linearized;
}
char* RotateSquaredString_90Clockwise(char* squared) { // assume s is squared string
  if (!squared) return NULL;
  int n = 0;
  int n_s = FindLenAndDimSquareString(squared, &n);
  char* modified = calloc(n_s + 1, sizeof(char));
  int i, j;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      modified[LinIdx(n + 1, i, j)] = squared[LinIdx(n + 1, n - 1 - j, i)];
    }
  }
  for (i = 0; i < n - 1; ++i) {  // add line breaks
    modified[LinIdx(n + 1, i, n)] = '\n';
  }
  modified[n_s] = '\0';  
  return modified;
}
char* RotateSquaredString_90AntiClockwise(char* s) {
  if (!s) return NULL;
	int n = 0;
	int n_s = FindLenAndDimSquareString(s, &n);
	char* modified = calloc(n_s + 1, sizeof(char));
	int i, j;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      modified[LinIdx(n + 1, n - 1 - j, i)] = s[LinIdx(n + 1, i, j)];
    }
	}
  for (i = 0; i < n - 1; ++i) {  // add line breaks
    modified[LinIdx(n + 1, i, n)] = '\n';
  }
  modified[n_s] = '\0';  
  return modified;
}
int LinIdx(int dim, int i, int j) {
  return dim * i + j;
}

int FindLenAndDimSquareString(char* squared, int* dim) {
  int n_lbreaks = 0;
  int n_s = 0;
  while (squared[n_s]) {
      if (squared[n_s] == '\n') { ++n_lbreaks;}
      ++n_s;
  }
  *dim = n_lbreaks + 1;
  return n_s;
}


char* Strings_StrTokSelfimplemented(char *src, const char *delims) {
  char* iter = NULL;
  char* start_of_curr_token = NULL;
  static char* end_of_old_token = NULL;
  static bool nullterminator_reached = false;
  if (src) { // tokenize src
    iter = src;
    end_of_old_token = NULL;
    nullterminator_reached = false;
  } else {
    if (!end_of_old_token && !nullterminator_reached) { // first call but src = NULL
      return NULL; 
    } else if (end_of_old_token && !nullterminator_reached) {
      iter = end_of_old_token + 1;
    } else { // nullterminator was already reached for this stirng
      return NULL;  
    }
  }  
  AdvanceUntilNoMatchOrNull(&iter, delims); // iter is now at a char not contained in delims or null-term
  start_of_curr_token = iter;
  if (*iter) {    
    AdvanceUntilMatchOrNull(&iter, delims); // iter is now at some delimiter or null-term
    if (*iter) {  // delimiter reached
      *iter = '\0';
      end_of_old_token = iter;
    } else { // null-terminator reached
      nullterminator_reached = true;
    }
  } else { // src is empty or only contains chars that are also in delims
    nullterminator_reached = true;
    return NULL;
  }  
  return start_of_curr_token;
}
bool CharContainedInString(const char* haystack,  char needle) {
  char needle_str[2] = {0};
  sprintf(needle_str, "%c", needle);
  char* match = strstr(haystack, needle_str);
  return (match ? true : false);
}
void AdvanceUntilNoMatchOrNull(char** iter, const char* targets) {
  while (*iter && **iter && CharContainedInString(targets, **iter)) ++(*iter);
  return;
}
void AdvanceUntilMatchOrNull(char** iter, const char* targets) {  
  while (*iter && **iter && !CharContainedInString(targets, **iter)) ++(*iter);
  return;
}