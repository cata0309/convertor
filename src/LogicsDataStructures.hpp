//
// Created by rustyboy on 1/11/20.
//
#include<string>
#include<cstring>
#ifndef CONVERTOR_SRC_LOGICSCOMMON_HPP_
#define CONVERTOR_SRC_LOGICSCOMMON_HPP_

//######################################################################################################################

//############################################### Defines for logics ###################################################

//MAX_ENTRIES = the maximum of definitions from the dictionary file
#define MAX_ENTRIES 200

//MAX_KEY_DIM = the maximum length of the word that represents an entry in the dictionary
#define MAX_KEY_DIM 15


//MAX_WORDS = the maximum number of words that can be putted in an operation
#define MAX_WORDS 500

//############################################### Data Structures ######################################################
//The queue is used for keeping the post fixated notation that is produced after the in fixated notation was analysed
//`info` has the role of storing the number/operator as a C type string
//`*urm` is a pointer to the urm element from the list/queue in this case
struct ElQueueChar {
  char value[MAX_KEY_DIM];
  bool is_operat;
  ElQueueChar *next;
};
struct ElQueueDouble {
  double value;
  bool is_operat;
  ElQueueDouble *next;
};
//The stack is used just for keeping the operators in order and build the post fixated notation of an expression
//`info` has the role of storing the operator interpreted as a character '+' || '-' || '*' || '/' || '(' || ')'
//`*urm` is a pointer to the urm element from the list/stack in this case
struct ElStackChar {
  char value;
  bool is_operat;
  ElStackChar *next;
};
//an instance of the Aliases struct stores an all `letter` entry and an all `digit` entry that
//represent the same number
//example `letters[]="fifty"` and `digits=50'
struct Aliases {
  std::string letters;
  int digits;
};
//The LLin is used for stack implementation(there is no use of a queue because we use insert the elements in reverse order
//in a stack to simulate a queue
struct LLin {
  double info;
  bool is_operat;
  LLin *next;
};

//######################################################################################################################
//######################################## STACK IMPLEMENTATION FOR OPERATORS ##########################################

//`isStackEmpty()` function checks if the stack is empty, if its empty the returned info is
// `true` otherwise it's `false`
bool isStackCharEmpty(ElStackChar *head);

//`popNumberStack()` function helps at removing elements if any from the stack
void popStackChar(ElStackChar *&head);

//`pushNumberStack()` function helps at inserting new elements on the stack
void pushStackChar(ElStackChar *&head, char value, bool is_operat);


//######################################################################################################################


//################################### QUEUE IMPLEMENTATION FOR NOTATIONS ###############################################

//`insertChar()`function helps at inserting new elements in the queue
void insertQueueChar(ElQueueChar *&head, char *value, bool is_operat);

//`isQueueEmpty()` function checks if the queue is empty, if its empty the returned info is
// `true` otherwise is `false`
bool isQueueCharEmpty(ElQueueChar *head);

void insertQueueDouble(ElQueueDouble *&head, double value, bool is_operat);

//`isQueueEmpty()` function checks if the queue is empty, if its empty the returned info is
// `true` otherwise is `false`
bool isQueueDoubleEmpty(ElQueueDouble *head);

//######################################################################################################################

//`isNumberStackEmpty()` function helps at checking if the stack is empty or not
bool isEmpty(LLin *stack);

//`popNumberStack()` function helps at removing numbers from the stack if any
void pop(LLin *&stack);
//`push()` function helps at inserting numbers to the stack
void push(LLin *&stack, double element, bool is_operat);

//`top()` function returns the info stored in the `info` field of the top element of the stack if any
LLin *top(LLin *stack);
//`getValue()` function has the role of searching a word through the array of entries and returning
//-1 if the info was not found otherwise the correspondent integer info of the C type string if it was found
int getValue(Aliases *aliases, int dimension, char *key);

//`convertToLowerCase()` function has the role of converting the input to lowercase, this is necessary because:
//1.all the entries are lowercase
//2.helps not writing a lot of boilerplate code
void convertToLowerCase(char *input);
//######################################################################################################################
#endif //CONVERTOR_SRC_LOGICSCOMMON_HPP_
