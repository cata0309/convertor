#include "LogicsFunctions.hpp"
#include<fstream>
std::ifstream fin_en("defines_en.txt");
int main() {
////////////////////////////////////////   ////////////////////////////////////////

//
//`input` is a temporary C type string where we store our raw input: First phase of input manipulation: Getting it
  char input[MAX_INPUT];

  Aliases aliases[MAX_ENTRIES];

//the `dimension`(the number of entries that happens to be in the dictionary file)
  int dimension = 0;

//it is initially configured and after this function call it stores all the content of the `fin_en` file
  setupAliases(aliases, fin_en, dimension);
  //the reading process is done via the console(it will be changed by SFML `interpretation of GUI` mimics
  std::cin.get(input, MAX_INPUT);

  bool success = true;
  double result = 0;
  if (strlen(input)==0) {
    success = false;
  } else {
    processingInput(input, success, result, aliases, dimension);
  }
  if (success) {
    std::cout << "Notatia postfixata este corecta iar rezultatul este: " << result;
  } else {
    std::cout << "Wrong input!";
  }
  return 0;
}

/*
 * the product between fifty five millions seven hundred ninety nine thousands three hundreds eighty one and one thousand
 * the product between one million and one million
 * the result of the sum between 4/5 and three
 * */

/*
 *


cincizeci si cinci de milioane sapte sute nouazeci si noua de mii trei sute optzeci si unu

    fifty five millions seven hundred ninety nine thousands three hundreds eighty one
    word: one nr: 1
word: eighty nr: 81
word: hundreds nr: 81
word: three nr: 381
word: thousands nr: 381
word: nine nr: 9381
word: ninety nr: 99381
word: hundred nr: 99381
word: seven nr: 799381
word: millions nr: 799381
word: five nr: 5799381
word: fifty nr: 55799381
*/