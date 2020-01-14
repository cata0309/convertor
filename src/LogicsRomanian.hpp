#include "LogicsDataStructures.hpp"
#ifndef CONVERTOR_SRC_LOGICSROMANIAN_HPP_
#define CONVERTOR_SRC_LOGICSROMANIAN_HPP_
// aceasta functie calculeaza valoarea expresiei postfixate
double getValueOfPostfixed(LLin *&postfix);
void insertToQueue(LLin *&coada, double element, bool x);
void infixatedWithSpace(char *sir, double *infixed, int &longinfixed, bool *IfIsOp);
bool onlyDigitsRo(char *sir);
double oper(int sir[], unsigned lung, int &incep);
// aceasta functie returneaza prioritatea operatorilor , adunarea si scaderea avand prioritate 1 ,iar inmultirea si impartirea 2
int priorityOfOperator(int operatorr);
void processRoInput(char *input, bool &success, double &result, Aliases *aliases, int dimension);
double result(int operatorr, double operand1, double operand2);
double topValueRetriever(LLin *stiva);
bool topIsOperatorRetriever(LLin *stiva);
// functia transformAllInInfixed transforma toate operatiile prefixate in infixate , totodata punand si parantezele necesare in cazul unui operator prefixat
void transformAllInInfixed(double *arrayofanswer,
                           bool *IfIsOp,
                           unsigned &longofarray,
                           double *infixed,
                           int &longinfixed);
// aceasta functie transforma ecuatia din infixata in postfixata
void transformFromInfixToPostFix(LLin *&infix, LLin *&postfix);
bool validate(int *sir, unsigned lungime);
#endif //CONVERTOR_SRC_LOGICSROMANIAN_HPP_
