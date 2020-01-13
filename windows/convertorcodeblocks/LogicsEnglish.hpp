#include"LogicsDataStructures.hpp"
#include <iostream>
#include<fstream>
#include<cstring>
#ifndef CONVERTOR_SRC_LOGICS_HPP_
#define CONVERTOR_SRC_LOGICS_HPP_


//######################################################################################################################

//######################################## Input related ###############################################################


//######################################################################################################################



//#################################### Helpers/Checkers functions ######################################################

//`infixatedInPlaceTranslator()` function takes as parameters an in fixated notation expression as a word,
//a boolean array that stores the `quality` of being an operator '+','-' etc., an array of elements, the post fixated
//terminal array and its dimension, besides these it also takes the word that can be converted
void infixatedInPlaceTranslator(char *value,
                                double *array,
                                bool *is_operator,
                                int &dimension);
//`isInfixatedNotation()` function checks if a word contains only some `allowed` characters that could make the
//conversion possible
//`numberBuilder()` function constructs a number from the consecutive words that represent numbers
void numberBuilder(int &number, int &digit_binding, int &power_ten);

//`onlyDigits()` function checks if a word can be the ASCII representation of a number
bool onlyDigits(char *str);

//`prioritiesChar()` and `prioritiesDouble()` functions return what priorities operators have, this is important when we are converting
// from in fixated notation to post fixated notation as it could be some operators on the stack that must wait before
// they are inserted in the queue
int prioritiesChar(char symbol);
int prioritiesDouble(double symbol);

//######################################################################################################################


//################################### LIST IMPLEMENTATION FOR CALCULUS #################################################

//`calculateFinalResult()` function calculates the final result from a post fixated notation array and changes the
//status of the bool variable from `true` to `false` if it didn't succeeded
void calculateFinalResult(bool &success,
                          double &final_result,
                          double *final_translation,
                          bool *is_operator,
                          int final_dimension,
                          bool expression);
//`executeOperation()` function takes three arguments, left operand, the operation and the right operand
double executeOperation(double left, double op, double right, bool expression);

//`operand()` function helps at checking if a number is operand or not
bool operand(double);
//`processingInput()` function takes the input as a C type string
//converts it to lower case
//searches all the definition that are written in the definition file
//converts them to numbers
//makes a post fixated notation and also translates in fixated notation to post fixated notation
//solves the post fixated notation expression
void processEnInput(char *input,
                    bool &success,
                    double &result,
                    Aliases *aliases,
                    int dimension);
//######################################################################################################################
#endif