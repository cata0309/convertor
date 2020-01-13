#include "LogicsDataStructures.hpp"
#ifndef CONVERTOR_SRC_LOGICSROMANIAN_HPP_
#define CONVERTOR_SRC_LOGICSROMANIAN_HPP_
void insereaza(LLin *&coada, double element, bool x);
double top_citeste_valoare(LLin *stiva);
bool top_citeste_IsOp(LLin *stiva);
bool doar_cifre(char sir[]);
bool validare(int *sir, unsigned lungime);
double oper(int sir[], unsigned lung, int &incep);
// functia TransformAllInInfixed transforma toate operatiile prefixate in infixate , totodata punand si parantezele necesare in cazul unui operator prefixat
void TransformAllInInfixed(int arrayofanswer[],
                           bool IfIsOp[],
                           unsigned &longofarray,
                           double infixed[],
                           int &longinfixed);
double result(int operatorr, double operand1, double operand2);
// aceasta functie returneaza prioritatea operatorilor , adunarea si scaderea avand prioritate 1 ,iar inmultirea si impartirea 2
int prioritofoperator(int operatorr);
// aceasta functie transforma ecuatia din infixata in postfixata
void TransformFromInfixToPostFix(LLin *&infix, LLin *&postfix);
// aceasta functie calculeaza valoarea expresiei postfixate
double ValueOfPostfixed(LLin *&postfix);
void InfixatedWithSpace(char *sir, double infixed[], int &longinfixed, bool IfIsOp[]);
void processRoInput(char *input, bool &success, double &result, Aliases *aliases, int dimension);
#endif //CONVERTOR_SRC_LOGICSROMANIAN_HPP_
