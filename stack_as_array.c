/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "stack_as_array.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MainStackAsArray() {
  printf("\n\n----------------------- MainStackAsArray \n");
  
  //-----------------------------------------
  // preparations:
  
  //-----------------------------------------
  // Exercises  
  
  MainStackAsArray_StackIntpairAPI();
  
  MainStackAsArray_StackIntpairAPIWithMax();
  
  MainStackAsArray_StackChararrayAPI();
    
  MainStackAsArray_ReversePolishNotation();
    
  MainStackAsArray_WellFormedBracketString();
  
  MainStackAsArray_NormalisePathName();
  
  MainStackAsArray_BuildingsWithSunsetView();
  
  return;
}


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void MainStackAsArray_StackIntpairAPI() {  
  printf("\n----------------------------------- MainStackAsArray_StackAPI \n");

  StackIntpairT mystack;
  StackAsArrayOfIntpair_Init(&mystack);
  
  int i;
  for (i = 0; i < 10; ++i) {
    DataNodeIntKeyIntValT new_node= { i, 42 }; // only use first val1 for this example
    StackAsArrayOfIntpair_Push(&mystack, &new_node);    
  }
  
  // see result
  while(StackAsArrayOfIntpair_Top(&mystack)) {
    printf("top-element: %i \n", StackAsArrayOfIntpair_Top(&mystack)->key);
    StackAsArrayOfIntpair_Pop(&mystack);
  }
  
  StackAsArrayOfIntpair_Destroy(&mystack);
  return;
}


void MainStackAsArray_StackIntpairAPIWithMax() {  
  printf("\n----------------------------------- MainStackAsArray_StackAPIWithMax \n");

  StackIntpairWithMaxT mystack;
  StackAsArrayOfIntpair_WithMax_Init(&mystack);
  StackAsArrayOfIntpair_WithMax_Push(&mystack, &((DataNodeIntKeyIntValT) {1, 42}));
  StackAsArrayOfIntpair_WithMax_Push(&mystack, &((DataNodeIntKeyIntValT) {4, 42}));
  StackAsArrayOfIntpair_WithMax_Push(&mystack, &((DataNodeIntKeyIntValT) {3, 42}));
  StackAsArrayOfIntpair_WithMax_Push(&mystack, &((DataNodeIntKeyIntValT) {4, 42}));
  StackAsArrayOfIntpair_WithMax_Push(&mystack, &((DataNodeIntKeyIntValT) {8, 42}));
  StackAsArrayOfIntpair_WithMax_Push(&mystack, &((DataNodeIntKeyIntValT) {2, 42}));
  
  printf("Values pushed to stack (bottom-top): 1, 4, 3, 4, 8, 2 .\n");
  
  // see result
  while(StackAsArrayOfIntpair_WithMax_Top(&mystack)) {
    printf("Current top: %i, current max: %i \n", StackAsArrayOfIntpair_WithMax_Top(&mystack)->key, 
            StackAsArrayOfIntpair_WithMax_Max(&mystack));    
    StackAsArrayOfIntpair_WithMax_Pop(&mystack);
    printf("Popped top-element.\n");
  }
  
  StackAsArrayOfIntpair_WithMax_Destroy(&mystack);
  return;
}


void MainStackAsArray_StackChararrayAPI() {  
  printf("\n----------------------------------- MainStackAsArray_StackChararrayAPI \n");

  StackChararrayT mystack;
  StackAsArrayOfChararray_Init(&mystack);  
  StackAsArrayOfChararray_Push(&mystack, &((DataNodeStringKeyT) {"abc"}));
  StackAsArrayOfChararray_Push(&mystack, &((DataNodeStringKeyT) {"def"}));
  StackAsArrayOfChararray_Push(&mystack, &((DataNodeStringKeyT) {"ghi"}));  
  
  // see result
  while(StackAsArrayOfChararray_Top(&mystack)) {
    printf("top-element: %s \n", StackAsArrayOfChararray_Top(&mystack)->key);
    StackAsArrayOfChararray_Pop(&mystack);
  }
  
  StackAsArrayOfChararray_Destroy(&mystack);
  return;
}


void MainStackAsArray_ReversePolishNotation() {  
  printf("\n----------------------------------- MainStackAsArray_ReversePolishNotation \n");
  char* rpn_str = "3,4,+,2,x,1,+";
  int result = EvaluateRPNString(rpn_str);
  printf("The rpn expression: %s \n", rpn_str);
  printf("evaluates to: %i \n", result);
  return;
}

void MainStackAsArray_WellFormedBracketString() {
  printf("\n----------------------------------- MainStackAsArray_WellFormedBracketString \n");
  // ( "parenthesis"
  // [ "bracket"
  // { "brace}
  char* bracket_str = "[()[]{(()()}]";  // well-formed example: "[()[]{()()}]"
  bool is_wellformed = IsWellFormedBracketString(bracket_str);
  printf("The string %s \n", bracket_str);
  printf("is %swell-formed .\n", is_wellformed ? "" : "not ");
  return;
}

void MainStackAsArray_NormalisePathName() {
  printf("\n----------------------------------- MainStackAsArray_NormalisePathName \n");
  char* filepath = "///subdir//./../subdir/subsubdir/subsubsubdir/../../file.c";
  char* normalised_path = NormalisePathName(filepath);
  printf("The filepath: %s \n", filepath);
  printf("can be normalised to: %s \n", normalised_path);
  free(normalised_path);
  return;
}

void MainStackAsArray_BuildingsWithSunsetView() {
  printf("\n----------------------------------- MainStackAsArray_BuildingsWithSunsetView \n");
  int heights_east_to_west[] = { 1, 2, 3, 3, 7, 7, 3, 5, 5, 4 , 1};
  const int n_buildings = sizeof(heights_east_to_west) / sizeof(int);
  int n_see_sunset = 0;
/*
  NodeIntpairT* sunsetbuildings_idxandheight = BuildingsWithSunsetView(
          heights_east_to_west, n_buildings, &n_see_sunset);
*/
  DataNodeIntKeyIntValT* sunsetbuildings_idxandheight = BuildingsWithSunsetView_StackSolution(
          heights_east_to_west, n_buildings, &n_see_sunset);
  printf("We have buildings arranged from east to west like: \n");
  int i;
  for (i = 0; i < n_buildings; ++i) {
    printf("%2i-th building from east-to-west of height: %i \n", i, heights_east_to_west[i]);
  }
  printf("\n");
  printf("Of these buildings the following see the sunset: \n");
  for (i = 0; i < n_see_sunset; ++i) {
    printf("%2i-th building from east-to-west of height: %i \n", sunsetbuildings_idxandheight[i].key, 
            sunsetbuildings_idxandheight[i].val);
  }          
  free(sunsetbuildings_idxandheight);
  return;
}
  
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
/**
 **  STACK API FOR PLAIN STACK - CHAR
 **/

void StackAsArrayOfChar_Init(StackCharT* stack) {
  stack->capacity = 2;
  stack->i_top = -1;  // -1 means stack is empty
  stack->arr = calloc(stack->capacity, sizeof(DataNodeCharKeyT));
  return;
}

void StackAsArrayOfChar_Destroy(StackCharT* stack) {
  free(stack->arr);  
  return;
}

void StackAsArrayOfChar_Push(StackCharT* stack, DataNodeCharKeyT* new_node) {
  if (stack->i_top == stack->capacity - 1) {
    stack->capacity *= 2;
    stack->arr = realloc(stack->arr, stack->capacity * sizeof(DataNodeCharKeyT));
  }
  stack->arr[++(stack->i_top)] = *new_node;
  return;
}

void StackAsArrayOfChar_Pop(StackCharT* stack) {
  if (stack->i_top >= 0) {
    --(stack->i_top); // i_top can be reduced minimally to -1 here
  } else { 
    printf("Underflow: cannot pop. \n");
  }
}

DataNodeCharKeyT* StackAsArrayOfChar_Top(StackCharT* stack) {
  if (stack->i_top >= 0) {
    return &(stack->arr[stack->i_top]);
  } else {
    return NULL;
  }  
}

//------------------------------------------------------------------------------
/**
 **  STACK API FOR PLAIN STACK - INT
 **/

void StackAsArrayOfInt_Init(StackIntT* stack) {
  stack->capacity = 2;
  stack->i_top = -1;  // -1 means stack is empty
  stack->arr = calloc(stack->capacity, sizeof(DataNodeIntKeyT));
  return;
}

void StackAsArrayOfInt_Destroy(StackIntT* stack) {
  free(stack->arr);  
  return;
}

void StackAsArrayOfInt_Push(StackIntT* stack, DataNodeIntKeyT* new_node) {
  if (stack->i_top == stack->capacity - 1) {
    stack->capacity *= 2;
    stack->arr = realloc(stack->arr, stack->capacity * sizeof(DataNodeIntKeyT));
  }
  stack->arr[++(stack->i_top)] = *new_node;
  return;
}

void StackAsArrayOfInt_Pop(StackIntT* stack) {
  if (stack->i_top >= 0) {
    --(stack->i_top); // i_top can be reduced minimally to -1 here
  } else { 
    printf("Underflow: cannot pop. \n");
  }
}

DataNodeIntKeyT* StackAsArrayOfInt_Top(StackIntT* stack) {
  if (stack->i_top >= 0) {
    return &(stack->arr[stack->i_top]);
  } else {
    return NULL;
  }  
}


//------------------------------------------------------------------------------
/**
 **  STACK API FOR PLAIN STACK - INT-PAIRS
 **/

void StackAsArrayOfIntpair_Init(StackIntpairT* stack) {
  stack->capacity = 2;
  stack->i_top = -1;  // -1 means stack is empty
  stack->arr = calloc(stack->capacity, sizeof(DataNodeIntKeyIntValT));
  return;
}

void StackAsArrayOfIntpair_Destroy(StackIntpairT* stack) {
  free(stack->arr);  
  return;
}

void StackAsArrayOfIntpair_Push(StackIntpairT* stack, DataNodeIntKeyIntValT* new_node) {
  if (stack->i_top == stack->capacity - 1) {
    stack->capacity *= 2;
    stack->arr = realloc(stack->arr, stack->capacity * sizeof(DataNodeIntKeyIntValT));
  }
  stack->arr[++(stack->i_top)] = *new_node;
  return;
}

void StackAsArrayOfIntpair_Pop(StackIntpairT* stack) {
  if (stack->i_top >= 0) {
    --(stack->i_top); // i_top can be reduced minimally to -1 here
  } else { 
    printf("Underflow: cannot pop. \n");
  }
}

DataNodeIntKeyIntValT* StackAsArrayOfIntpair_Top(StackIntpairT* stack) {
  if (stack->i_top >= 0) {
    return &(stack->arr[stack->i_top]);
  } else {
    return NULL;
  }  
}

//------------------------------------------------------------------------------
/**
 **  STACK API FOR INTPAIR-STACK WITH MAX-BOOKKEEPING
 **/

void StackAsArrayOfIntpair_WithMax_Init(StackIntpairWithMaxT* stack) {
  stack->capacity = 2;
  stack->i_top = -1;  // -1 means stack is empty
  stack->arr = calloc(stack->capacity, sizeof(DataNodeIntKeyIntValT));
  // also init max-stack
  stack->max_stack = calloc(1, sizeof(StackIntpairT));
  StackAsArrayOfIntpair_Init(stack->max_stack);
  return;
}

void StackAsArrayOfIntpair_WithMax_Destroy(StackIntpairWithMaxT* stack) {
  StackAsArrayOfIntpair_Destroy(stack->max_stack); // also destroy max-stack
  free(stack->max_stack);
  free(stack->arr);  
  return;
}

void StackAsArrayOfIntpair_WithMax_Push(StackIntpairWithMaxT* stack, DataNodeIntKeyIntValT* new_node) {
  if (stack->i_top == stack->capacity - 1) {
    stack->capacity *= 2;
    stack->arr = realloc(stack->arr, stack->capacity * sizeof(DataNodeIntKeyIntValT));
  }
  stack->arr[++(stack->i_top)] = *new_node;
  // update max-stack if necessary
  if (stack->i_top == 0 || 
          new_node->key > StackAsArrayOfIntpair_Top(stack->max_stack)->key) { // new maximum
    StackAsArrayOfIntpair_Push(stack->max_stack, &((DataNodeIntKeyIntValT) {new_node->key, 1}));
  }
  else if (new_node->key == StackAsArrayOfIntpair_Top(stack->max_stack)->key) {
    ++(StackAsArrayOfIntpair_Top(stack->max_stack)->val); // increment occurences
  }
  return;
}

void StackAsArrayOfIntpair_WithMax_Pop(StackIntpairWithMaxT* stack) {
  if (stack->i_top >= 0) {
    // check if maximum is popped
    if (StackAsArrayOfIntpair_WithMax_Top(stack)->key == StackAsArrayOfIntpair_Top(stack->max_stack)->key) {
      if (StackAsArrayOfIntpair_Top(stack->max_stack)->val > 1) {
        --(StackAsArrayOfIntpair_Top(stack->max_stack)->val);
      } else {
        StackAsArrayOfIntpair_Pop(stack->max_stack);
      }
    }
    --(stack->i_top); // i_top can be reduced minimally to -1 here
  } else { 
    printf("Underflow: cannot pop. \n");
  }
}

DataNodeIntKeyIntValT* StackAsArrayOfIntpair_WithMax_Top(StackIntpairWithMaxT* stack) {
  if (stack->i_top >= 0) {
    return &(stack->arr[stack->i_top]);
  } else {
    return NULL;
  }  
}

int StackAsArrayOfIntpair_WithMax_Max(StackIntpairWithMaxT* stack) {
  if (stack->capacity) {
    return StackAsArrayOfIntpair_Top(stack->max_stack)->key;
  } else {
    return -1;
  }
}

//------------------------------------------------------------------------------
/**
 **  STACK API FOR PLAIN STACK - CHAR-ARRAYS
 **/

void StackAsArrayOfChararray_Init(StackChararrayT* stack) {
  stack->capacity = 2;
  stack->i_top = -1;  // -1 means stack is empty
  stack->arr = calloc(stack->capacity, sizeof(DataNodeStringKeyT));
  return;
}

void StackAsArrayOfChararray_Destroy(StackChararrayT* stack) {
  free(stack->arr);  
  return;
}

void StackAsArrayOfChararray_Push(StackChararrayT* stack, DataNodeStringKeyT* new_node) {
  if (stack->i_top == stack->capacity - 1) {
    stack->capacity *= 2;
    stack->arr = realloc(stack->arr, stack->capacity * sizeof(DataNodeStringKeyT));
  }
  stack->arr[++(stack->i_top)] = *new_node;
  return;
}

void StackAsArrayOfChararray_Pop(StackChararrayT* stack) {
  if (stack->i_top >= 0) {
    --(stack->i_top); // i_top can be reduced minimally to -1 here
  } else { 
    printf("Underflow: cannot pop. \n");
  }
}

DataNodeStringKeyT* StackAsArrayOfChararray_Top(StackChararrayT* stack) {
  if (stack->i_top >= 0) {
    return &(stack->arr[stack->i_top]);
  } else {
    return NULL;
  }  
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

int EvaluateRPNString(char* rpn_str) {
  int result;
  char operand1[32];
  char operand2[32];
  int chars_copied = CpyCharsUntilCommaOrNull(operand1, rpn_str);
  rpn_str += chars_copied;
  result = atoi(operand1);
  while (*rpn_str) {
    if (*rpn_str == ',') {
      ++rpn_str;
      continue;
    }      
    chars_copied = CpyCharsUntilCommaOrNull(operand2, rpn_str);
    rpn_str += chars_copied;
    if (*rpn_str) {
      // if we have not reached the end, we are now on a comma
      ++rpn_str;
      char operation = *rpn_str;    
      if (operation == '+') {
        result = result + atoi(operand2);
      } else if (operation == '-') {
        result = result - atoi(operand2);
      } else if (operation == 'x') {
        result = result * atoi(operand2);
      } else if (operation == '/') {
        result = result / atoi(operand2);
      }
      ++rpn_str;
    }
  }
  return result;
}

/**
 * Copies all chars from src to destination until , is reached or null-terminator.
 * 
 * Returns number of chars written, WITHOUT the null-terminator
 * (though that is also written).
 * 
 * @param dst
 * @param src
 * @return 
 */
int CpyCharsUntilCommaOrNull(char* dst, char* src) {  
  int i = 0;  
  while (*src != ',' && *src) {
    dst[i] = src[i];
    ++i;
    ++src;
  }
  dst[i] = '\0';
  return i;
}

/**
 * Exercise: 
 * 
 * Given a string consisting of opening and closing brackets, it is well-formed
 * if any opening bracket finds a closing bracket of the same kind
 * and the order is such that the first closing bracket follows the corresponding
 * opening bracket, with already matched brackets being ignored.
 * 
 * Idea:
 * 
 * We can deposit all appearing opening brackets on a stack and once we
 * reach a closing bracket, the top bracket on the stack needs to match.
 * If it does, it can be removed from the stack and we continue, if not
 * the string is not well-formed. Once we have parsed the whole string
 * the stack must be empty, otherwise there are still opening brackets.
 * 
 * space-complexity: O(n)  (worst-case, all open-brackets until end)
 * time-complexity: O(n) (need to parse all chars in str)
 * 
 * @param str
 * @return 
 */
bool IsWellFormedBracketString(char* str){  
  StackCharT stack_chars;
  StackAsArrayOfChar_Init(&stack_chars);
  while (*str) {
    char c = *str;
    if (c == '(' || c == '[' || c == '{') {
      StackAsArrayOfChar_Push(&stack_chars, &((DataNodeCharKeyT) { c }));
    } else if (c == ')' || c == ']' || c == '}') {
      DataNodeCharKeyT* top_element = StackAsArrayOfChar_Top(&stack_chars);
      bool match = false;
      if (top_element) {
        if ((c == ')' && top_element->key == '(') ||
              (c == ']' && top_element->key == '[') ||
              (c == '}' && top_element->key == '{')) 
        {
          match = true;
        }
      }
      if (match) {
        StackAsArrayOfChar_Pop(&stack_chars);
      } else {
        return false;
      }
    }
    ++str;
  }
  if (StackAsArrayOfChar_Top(&stack_chars)) {
    StackAsArrayOfChar_Destroy(&stack_chars);
    return false;
  } else {
    StackAsArrayOfChar_Destroy(&stack_chars);
    return true;
  }
}

/**
 * Excercise:
 * 
 * Given a filepath that may contain directory-names, slashes to separate
 * directory names and the special sequences "." meaning "stay in directory"
 * and ".." meaning "go one up" find the shortest possible way of
 * writing the filepath. This is called the normalised path. Note that
 * two consecutive slashes may appear but shall be interpreted as "stay".
 * 
 * Idea:
 * 
 * We have three ways to make the path shorter:
 * 
 *  - replace double slashes by single ones
 *  - remove "/." parts
 *  - resolve "/.." and the last directory specified before that
 *    ( if none comes before, we have to keep the two dots)
 * 
 * Since always the last directory specified must be resolved with the ".."
 * a stack can be efficiently used to keep all parts of the path that
 * will be retained in the result.
 * 
 * Note: algorithm looks verbose to handle special case that filepath
 *       is allowed to start with leading slashes, which are interpreted
 *       as the top-dir if the amount is uneven and ignored if it is even.
 *       since a slash is usually the delimiter of tokens, this requires
 *       some extra case distinctions.
 * 
 * space-complexity: O(n)
 * time-complexity: O(n) 
 * 
 * @param filepath
 * @return 
 */
char* NormalisePathName(char* filepath) {  
  StackChararrayT stack_dirs;
  StackAsArrayOfChararray_Init(&stack_dirs);
  int len_normalised = 0;
  // special case: the path starts at top-dir, i.e. with single '/'
  int leading_slashes = 0;
  if (*filepath == '/') {
    while (filepath[leading_slashes] && filepath[leading_slashes] == '/') {
      ++leading_slashes;
    }
    filepath += leading_slashes;
    leading_slashes %= 2;
    if (*filepath) {     
      if (leading_slashes) { // unequal number of leading slashes, so keep one        
        DataNodeStringKeyT tmp;
        strcpy(tmp.key, "/");
        StackAsArrayOfChararray_Push(&stack_dirs, &tmp);        
      }
    } else {
      return "empty path";
    }
  }
  len_normalised += leading_slashes; // maximally: +1
  // continue after leading slashes
  while (*filepath) {
    char nextpart[32];
    while (*filepath && *filepath == '/') {
      ++filepath;
    }   
    int i = 0;
    while (*filepath && *filepath != '/') {
      nextpart[i] = *filepath;
      ++i;
      ++filepath;
    }
    nextpart[i] = '\0';
    // now decide if we push or pop
    if (strcmp(nextpart, ".") == 0) {
      // do nothing
    } else if (strcmp(nextpart, "..") == 0 && 
            StackAsArrayOfChararray_Top(&stack_dirs) &&
            strcmp(StackAsArrayOfChararray_Top(&stack_dirs)->key, "..") != 0 &&
            strcmp(StackAsArrayOfChararray_Top(&stack_dirs)->key, "/") != 0)
    {
      len_normalised -= strlen(StackAsArrayOfChararray_Top(&stack_dirs)->key) + 1;
      StackAsArrayOfChararray_Pop(&stack_dirs);  
    } else {
      DataNodeStringKeyT tmp;
      strcpy(tmp.key, nextpart);
      StackAsArrayOfChararray_Push(&stack_dirs, &tmp);
      len_normalised += i + 1; // +1 for the slash added before
    }    
  }
  // we have added +1 for each part to put a slash in front
  // --> but the first part does not need a slash in-front
  //     (if there is a slash in front of first-part this is handled already
  //      above as regular part)
  --len_normalised;
  char* normalised_path = calloc(len_normalised + 1, sizeof(char)); // +1 for null  
  normalised_path[len_normalised] = '\0';
  int k = len_normalised - 1;
  // now we have the normalised file-path in reverse order on the stack
  while (StackAsArrayOfChararray_Top(&stack_dirs)) {
    char* nextpart = StackAsArrayOfChararray_Top(&stack_dirs)->key;
    int n_chars = strlen(nextpart);
    int j;
    for (j = n_chars - 1; j >= 0; --j) {
      normalised_path[k] = nextpart[j];      
      --k;
    }
    StackAsArrayOfChararray_Pop(&stack_dirs);
    if (k == -1) { // all written
      break;
    }
    else if (k > 0) {
      normalised_path[k--] = '/';    
    } else if (k == 0) {
      // can only happen if a single / needs to be added from stack
    }
  }
  StackAsArrayOfChararray_Destroy(&stack_dirs);
  return normalised_path;
}

/**
 * Excercise: 
 * 
 * Assume you are given the heights of buildings that are in a row from
 * east to west. Return only those buildings, with their index in the input
 * and their height, that have a view of the sunset. A building has 
 * a view if all buildings coming to the west of it are strictly smaller.
 * 
 * Idea:
 * 
 * If we go through the buildings from west-to-east we can decide right-away
 * if a building can see the sunset.
 * 
 * time complexity: O(n) , each building must be checked of course
 * worst case space complexity: O(n), potentially all buildings view sunset
 * best case space complexity: O(1), none view the sunset
 * 
 * @param heights_east_to_west
 * @param n_buildings
 * @param n_view_sunset
 * @return 
 */
DataNodeIntKeyIntValT* BuildingsWithSunsetView(int* heights_east_to_west, int n_buildings,
        int* n_view_sunset) {  
  *n_view_sunset = 0;
  if (!heights_east_to_west || n_buildings == 0) {
    return NULL;
  }  
  DataNodeIntKeyIntValT* buildings_withview = NULL;
  int i;
  int max_towest = 0;  
  for (i = n_buildings - 1; i >= 0; --i) {
    int curr_height = heights_east_to_west[i];
    if (curr_height > max_towest) {
      ++(*n_view_sunset);
      buildings_withview = realloc(buildings_withview, 
              (*n_view_sunset) * sizeof(DataNodeIntKeyIntValT));
      buildings_withview[(*n_view_sunset) - 1].key = i;
      buildings_withview[(*n_view_sunset) - 1].val = curr_height;
      // update
      max_towest = curr_height;
    }    
  }
  return buildings_withview;
}

/**
 * Exercise: 
 * 
 * Same as above, but now assume we have to traverse the heights
 * from east-to-west, just as they are ordered in the input array
 * (e.g. imagine because the input is coming as a stream).
 * 
 * Idea:
 * 
 * One idea would be to build up a new array in west-to-east order
 * from the input stream and then apply the simple solution.
 * 
 *  time complexity: O(n) , each building must be checked of course
 *  worst case space complexity: O(n), potentially all buildings view sunset
 *  best case space complexity: O(n), we would need the aux array in any case !
 * 
 * --> with this restriction, we can do better if we use a stack to track
 *     only those that see the sunset. if a new building comes we must check
 *     if those currently in the stack must be removed.
 * 
 *  base case space complexity: O(1)
 * 
 * 
 * @param heights_east_to_west
 * @param n_buildings
 * @param n_view_sunset
 * @return 
 */
DataNodeIntKeyIntValT* BuildingsWithSunsetView_StackSolution(int* heights_east_to_west, int n_buildings,
        int* n_view_sunset) {  
  *n_view_sunset = 0;
  if (!heights_east_to_west || n_buildings == 0) {
    return NULL;
  }  
  int i;
  StackIntpairT stack_buildings;
  StackAsArrayOfIntpair_Init(&stack_buildings);
  for (i = 0; i < n_buildings; ++i) {
    int curr_westmost_height = heights_east_to_west[i];
    while (StackAsArrayOfIntpair_Top(&stack_buildings) && 
            StackAsArrayOfIntpair_Top(&stack_buildings)->val <= curr_westmost_height) {
      StackAsArrayOfIntpair_Pop(&stack_buildings);
    }
    StackAsArrayOfIntpair_Push(&stack_buildings, &((DataNodeIntKeyIntValT) { i, curr_westmost_height }));
  }
  // build result array from stack
  DataNodeIntKeyIntValT* buildings_withview = NULL;
  while (StackAsArrayOfIntpair_Top(&stack_buildings)) {
    ++(*n_view_sunset);
    buildings_withview = realloc(buildings_withview, (*n_view_sunset) * sizeof(DataNodeIntKeyIntValT));
    buildings_withview[(*n_view_sunset) - 1].key = StackAsArrayOfIntpair_Top(&stack_buildings)->key;
    buildings_withview[(*n_view_sunset) - 1].val = StackAsArrayOfIntpair_Top(&stack_buildings)->val;
    StackAsArrayOfIntpair_Pop(&stack_buildings);
  }  
  StackAsArrayOfIntpair_Destroy(&stack_buildings);
  return buildings_withview;
}
