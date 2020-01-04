
#include <iostream>
#include<fstream>
#include<cstring>
#ifndef CONVERTOR_SRC_LOGICS_HPP_
#define CONVERTOR_SRC_LOGICS_HPP_

//############################################### Defines for logics ###################################################

//MAX_ENTRIES = the maximum of definitions from the dictionary file
#define MAX_ENTRIES 55

//MAX_KEY_DIM = the maximum length of the word that represents an entry in the dictionary
#define MAX_KEY_DIM 15


//MAX_WORDS = the maximum number of words that can be putted in an operation
#define MAX_WORDS 500

//######################################################################################################################


//############################################### Data Structures ######################################################

//an instance of the Aliases struct stores an all `letter` entry and an all `digit` entry that
//represent the same number
//example `letters[]="fifty"` and `digits=50'
struct Aliases {
  std::string letters;
  int digits;
};

//The queue is used for keeping the post fixated notation that is produced after the in fixated notation was analysed
//`value` has the role of storing the number/operator as a C type string
//`*next` is a pointer to the next element from the list/queue in this case
struct ElQueue {
  char value[MAX_KEY_DIM];
  ElQueue *next;
};

//The stack is used just for keeping the operators in order and build the post fixated notation of an expression
//`value` has the role of storing the operator interpreted as a character '+' || '-' || '*' || '/' || '(' || ')'
//`*next` is a pointer to the next element from the list/stack in this case
struct ElStack {
  char value;
  ElStack *next;
};

struct LLin {
  double info;
  LLin *urm;
};

//######################################################################################################################


//######################################## Input related ###############################################################

//`convertToLowerCase()` function has the role of converting the input to lowercase, this is necessary because:
//1.all the entries are lowercase
//2.helps not writing a lot of boilerplate code
void convertToLowerCase(char *input);

//`getValue()` function has the role of searching a word through the array of entries and returning
//-1 if the value was not found otherwise the correspondent integer value of the C type string if it was found
int getValue(Aliases *aliases, int dimension, char *key);

//`setupAliases()` function has the role of reading the contents of the fin file and make an Aliases array with all
//the entry pairs from the file, it also actualizes the `dimension` of the array
//void setupAliases(Aliases *aliases, std::ifstream &fin, int &dimension);

//######################################################################################################################


//######################################## STACK IMPLEMENTATION FOR OPERATORS ##########################################

//`isStackEmpty()` function checks if the stack is empty, if its empty the returned value is
// `true` otherwise it's `false`
inline bool isStackEmpty(ElStack *head);

//`popNumberStack()` function helps at removing elements if any from the stack
void pop(ElStack *&head);

//`pushNumberStack()` function helps at inserting new elements on the stack
void push(ElStack *&head, char value);

//######################################################################################################################


//################################### QUEUE IMPLEMENTATION FOR NOTATIONS ###############################################

//`insert()`function helps at inserting new elements in the queue
void insert(ElQueue *&head, char *value);

//`isQueueEmpty()` function checks if the queue is empty, if its empty the returned value is
// `true` otherwise is `false`
inline bool isQueueEmpty(ElQueue *head);

//######################################################################################################################


//#################################### Helpers/Checkers functions ######################################################

//`infixatedInPlaceTranslator()` function takes as parameters an in fixated notation expression as a word,
//a boolean array that stores the `quality` of being an operator '+','-' etc., an array of elements, the post fixated
//terminal array and its dimension, besides these it also takes the word that can be converted
void infixatedInPlaceTranslator(char *value, int *array, int &dimension);

//`isInfixatedNotation()` function checks if a word contains only some `allowed` characters that could make the
//conversion possible
bool isInfixatedNotation(char *str);

//`numberBuilder()` function constructs a number from the consecutive words that represent numbers
void numberBuilder(int &number, int &digit_binding, int &power_ten);

//`onlyDigits()` function checks if a word can be the ASCII representation of a number
bool onlyDigits(char *str);

//`priorities()` function returns what priorities operators have, this is important when we are converting
// from in fixated notation to post fixated notation as it could be some operators on the stack that must wait before
// they are inserted in the queue
int priorities(char symbol);

//######################################################################################################################


//################################### LIST IMPLEMENTATION FOR CALCULUS #################################################

//`calculateFinalResult()` function calculates the final result from a post fixated notation array and changes the
//status of the bool variable from `true` to `false` if it didn't succeeded
void calculateFinalResult(bool &, double &, double *, int, bool expression);

//`executeOperation()` function takes three arguments, left operand, the operation and the right operand
double executeOperation(double left, double op, double right, bool expression);

//`isNumberStackEmpty()` function helps at checking if the stack is empty or not
bool isNumberStackEmpty(LLin *stack_queue);

//`operand()` function helps at checking if a number is operand or not
bool operand(int);

//`popNumberStack()` function helps at removing numbers from the stack if any
void popNumberStack(LLin *&stack);

//`processingInput()` function takes the input as a C type string
//converts it to lower case
//searches all the definition that are written in the definition file
//converts them to numbers
//makes a post fixated notation and also translates in fixated notation to post fixated notation
//solves the post fixated notation expression
void processingInput(char *input, bool &success, double &result, Aliases *aliases, int dimension);

//`pushNumberStack()` function helps at inserting numbers to the stack
void pushNumberStack(LLin *&stack, double element);

//`topNumberStack()` function returns the value stored in the `info` field of the top element of the stack if any
double topNumberStack(LLin *stack);

//######################################################################################################################
#endif