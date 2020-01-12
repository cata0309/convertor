#include "LogicsEnglish.hpp"
//#include"LogicsDataStructures.hpp"
//################################################ Input, definitions related
//##########################################

//################################ Priority, checking in fixated, translator,
// conversions ##############################

void infixatedInPlaceTranslator(char *value, double *array, bool *is_operator,
                                int &dimension) {
  // the separation of the expression into numbers and symbols, all of them are
  // C type strings with a size of at least 1
  // unit, they are stores in an array of C type strings.
  char infix[MAX_WORDS][MAX_KEY_DIM];
  int infix_dim = 0;
  for (int index = 0; index < strlen(value); ++index) {
    if (strchr("+-*/()", value[index])) {
      infix[infix_dim][0] = value[index];
      infix[infix_dim++][1] = '\0';
    } else {
      int aux = 0;
      while (index < strlen(value) && strchr("0123456789.", value[index])) {
        infix[infix_dim][aux++] = value[index++];
      }
      index--;
      infix[infix_dim++][aux] = '\0';
    }
  }
  for (int i = 0; i < infix_dim; ++i) {
    if ((i==0 || (i > 0 && strstr("+*-+/()", infix[i - 1])))
        && strcmp(infix[i], "-")==0 && onlyDigits(infix[i + 1])) {
      char chei[MAX_KEY_DIM];
      chei[0] = '\0';
      strcat(chei, "-");
      strcat(chei, infix[i + 1]);
      strcpy(infix[i + 1], chei);
      for (int j = i; j < infix_dim - 1; j++) {
        strcpy(infix[j], infix[j + 1]);
      }
      infix_dim--;
    }
  }
  for (int i = 0; i < infix_dim; ++i) {
  }

  // The conversion from in fixated notation to post fixated notation using a
  // queue, a stack and an array(it behaves as a queue)
  ElQueueChar *postfixate = nullptr;
  ElStackChar *stack = nullptr;

  for (int index = 0; index < infix_dim; ++index) {
    if (onlyDigits(infix[index])) { // if it's a number(written with characters)
      // it gets inserted to the queue
      insertQueueChar(postfixate, infix[index], true);
    } else {
      if (infix[index][0]==')') { // otherwise if it matched a closing round
        // bracket it means that it must have been
        // finished `()` expression
        while (stack->value!='(') {
          char aux[2];
          aux[0] = stack->value;
          aux[1] = '\0';
          insertQueueChar(postfixate, aux, true);
          popStackChar(stack);
        }
        popStackChar(stack);

      } else {
        while (!isStackCharEmpty(stack) && stack->value!='(' &&
            prioritiesChar(stack->value) >=
                prioritiesChar(infix[index][0])) {
          char aux[2];
          aux[0] = stack->value;
          aux[1] = '\0';
          insertQueueChar(postfixate, aux, true);
          popStackChar(stack);
        }
        pushStackChar(stack, infix[index][0], is_operator[index]);
      }
    }
  }
  while (!isStackCharEmpty(stack)) {
    char aux[2];
    aux[0] = stack->value;
    aux[1] = '\0';
    insertQueueChar(postfixate, aux, true);
    popStackChar(stack);
  }
  // while the queue is not empty we insertChar all the elements into the post
  // fixated notation array but also updating its size The actual check of the
  // validity of this notation is made with the last form of expression
  while (!isQueueCharEmpty(postfixate)) {
    if (postfixate->value[0]=='+') {
      is_operator[dimension] = true;
      array[dimension++] = -3;
    } else if (postfixate->value[0]=='-' && !onlyDigits(postfixate->value)) {
      is_operator[dimension] = true;
      array[dimension++] = -4;
    } else if (postfixate->value[0]=='*') {
      is_operator[dimension] = true;
      array[dimension++] = -5;
    } else if (postfixate->value[0]=='/') {
      is_operator[dimension] = true;
      array[dimension++] = -6;
    } else {
      is_operator[dimension] = false;
      array[dimension++] = atof(postfixate->value);
    }
    postfixate = postfixate->next;
  }
}
void infixatedDoubleTranslator(double *infix, bool *is_ope, int &infix_dim) {
  ElQueueDouble *postfixate = nullptr;
  LLin *stack = nullptr;

  for (int index = 0; index < infix_dim; ++index) {
    if (!is_ope[index]) { // if it's a number(written with characters) it
      // gets inserted to the queue
      insertQueueDouble(postfixate, infix[index], false);
    } else {
      if (infix[index]==-8) { // otherwise if it matched a closing round
        // bracket it means that it must have been
        // finished `()` expression
        while (stack->info!=-7 || !stack->is_operat) {
          insertQueueDouble(postfixate, stack->info, stack->is_operat);
          pop(stack);
        }
        pop(stack);
      } else {
        while (!isEmpty(stack) && stack->info!=-7 &&
            prioritiesDouble(stack->info) >=
                prioritiesDouble(infix[index])) {
          insertQueueDouble(postfixate, stack->info, stack->is_operat);
          pop(stack);
        }
        push(stack, infix[index], is_ope[index]);
      }
    }
  }
  while (!isEmpty(stack)) {
    insertQueueDouble(postfixate, stack->info, stack->is_operat);
    pop(stack);
  }
  // while the queue is not empty we insertDouble all the elements into the post
  // fixated notation array but also updating its size The actual check of the
  // validity of this notation is made with the last form of expression
  infix_dim = 0;
  while (!isQueueDoubleEmpty(postfixate)) {
    is_ope[infix_dim] = postfixate->is_operat;
    infix[infix_dim++] = postfixate->value;
    postfixate = postfixate->next;
  }
}

bool isInfixatedNotation(char *str) {
  bool numbers = false;
  for (size_t index = 0; index < strlen(str); ++index) {
    if (!strchr("+-/*()0123456789.", str[index])) {
      return false;
    }
    if (strchr("0123456789", str[index])) {
      numbers = true;
    }
  }
  return numbers;
}
void numberBuilder(int &number, int &digit_binding, int &power_ten) {
  if (digit_binding > 90) {
    if ((power_ten==1000 && (digit_binding==100)) ||
        (power_ten==1000000 && (digit_binding==100)))
      power_ten *= digit_binding;
    else if (digit_binding > power_ten)
      power_ten = digit_binding;
  } else if (digit_binding > 9 && digit_binding < 100 && power_ten < 100) {
    number += digit_binding;
  } else {
    number += digit_binding*power_ten;
  }
}

bool onlyDigits(char *str) {
  bool condition = true;
  int nr_of_dots = 0;
  int numbers = 0;
  for (size_t index = 0; str[index] && condition; ++index) {
    if (!strchr("0123456789.-", str[index])) {
      condition = false;
    }
    if (str[index]=='-' && index!=0)
      condition = false;
    if (str[index]=='.') {
      nr_of_dots++;
      if (nr_of_dots > 1)
        condition = false;
    }
    if (strchr("0123456789", str[index])) {
      numbers++;
    }
  }
  if (numbers==0)
    condition = false;
  return condition;
}

int prioritiesChar(char symbol) {
  if (symbol=='(' ||
      symbol==')') // the '(' and ')' have the biggest priority
    return 3;
  if (symbol=='*' ||
      symbol=='/') // the '*' and '/' have the second biggest priority
    return 2;
  // default symbol=='+' || symbol=='-' //they have the smallest priority
  return 1;
}
int prioritiesDouble(double symbol) {
  if (symbol==-7 || symbol==-8) // the '(' and ')' have the biggest priority
    return 3;
  if (symbol==-5 ||
      symbol==-6) // the '*' and '/' have the second biggest priority
    return 2;
  // default symbol=='+' || symbol=='-' //they have the smallest priority
  return 1;
}

//######################################################################################################################

//###################################### Stack(integers), operations,
// calculating final result #########################

void calculateFinalResult(bool &success,
                          double &final_result,
                          double *final_translation,
                          bool *is_operator,
                          int final_dimension,
                          bool expression) {

  if (final_dimension==0) {
    success = false;
    return;
  }
  LLin *postfix = nullptr;
  for (int i = final_dimension - 1; i >= 0; --i)
    push(postfix, final_translation[i], is_operator[i]);
  LLin *operations_stack = nullptr;
  while (!isEmpty(postfix)) {
    LLin *head = top(postfix);
    double x = head->info;
    bool opera = head->is_operat;
    pop(postfix);
    if (!opera) {
      push(operations_stack, x, false);
    } else {
      if (isEmpty(operations_stack)) {
        success = false;
        return;
      }

      LLin *drphe = top(operations_stack);
      if (drphe->is_operat) {
        success = false;
        return;
      }
      double drp = drphe->info;
      pop(operations_stack);

      if (isEmpty(operations_stack)) {
        success = false;
        return;
      }
      LLin *stghe = top(operations_stack);
      if (stghe->is_operat) {
        success = false;
        return;
      }
      double stg = stghe->info;
      pop(operations_stack);

      if (x==-6) {
        if ((expression && drp==0) || (!expression && stg==0)) {
          success = false;
          return;
        }
      }
      double val = executeOperation(stg, x, drp, expression);
      push(operations_stack, val, false);
    }
  }
  LLin *fin = top(operations_stack);
  if (fin->is_operat) {
    success = false;
    return;
  }
  double final_value = fin->info;
  pop(operations_stack);
  if (!isEmpty(operations_stack)) {
    success = false;
    return;
  }
  final_result = final_value;
}

double executeOperation(double left, double op, double right, bool expression) {
  switch (int(op)) {
    case -3:return (left + right);
    case -4:
      if (expression)
        return (left - right);
      else
        return (right - left);
    case -5:return (left*right);
    default:
      if (expression)
        return (left/right);
      else
        return (right/left);
  }
}

bool twoOperatorsTogether(double infix[], int infix_numbers) {
  for (int i = 0; i < infix_numbers - 1; i++)
    if (infix[i] < 0 && infix[i + 1] < 0)
      return true;
  return false;
}

void deleteAtPosition(double infix_array[], bool is_ope[], int &infix_numbers, int i) {
  for (int k = i; k < infix_numbers - 1; k++)
    infix_array[k] = infix_array[k + 1], is_ope[k] = is_ope[k + 1];
  infix_numbers--;
}
void processEnInput(char *input,
                    bool &success,

                    double &result,
                    Aliases *aliases,
                    int dimension) {
  // conversion of the input to lowercase!
  convertToLowerCase(input);
  result = 0;
  bool prefixated = true;
  //`words` is an array of C type strings that hold only one world independently
  char words[MAX_WORDS][MAX_KEY_DIM];

  //`nr_words` is the dimension of this array
  int nr_words = 0;

  // Phase two of input manipulation: Separating input into words
  char *p = strtok(input, " ?");
  while (p) {
    // we ignore all the words that are not in the `dictionary` file(it's not
    // treating all the misleading inputs !!)
    bool ver = false;
    if (isInfixatedNotation(p) || onlyDigits(p)) {
      strcpy(words[nr_words++], p);
      ver = true;
    } else {
      int value = getValue(aliases, dimension, p);
      if (value!=-1) {
        if (value!=-10)
          strcpy(words[nr_words++], p);
        ver = true;
      } else
        success = false;
    }
    if (!ver) {
      success = false;
      return;
    }
    p = strtok(nullptr, " ?");
  }
  double postfix_array[MAX_WORDS];
  bool is_operator[MAX_WORDS] = {};
  int post_numbers = 0;

  //`power_ten` has the role of being a helper scale factor when building the
  // base 10 numbers
  int power_ten = 1;
  //`number` is a temporary storage for the number that is going to be formed
  int number = 0;
  bool forming_number = false;
  int predecessor = -10;
  bool only_expression = true;
  bool one_expression = false;

  int number_of_ands = 0;
  int number_of_postorder_operations = 0;

  for (int i = nr_words - 1; i >= 0; --i) {
    if (onlyDigits(words[i])) {
      only_expression = false;
      is_operator[post_numbers] = false;
      postfix_array[post_numbers++] = atof(words[i]);
    } else if (isInfixatedNotation(words[i])) {
      one_expression = true;
      double auxiliar[MAX_WORDS];
      int dim_aux = 0;
      bool is_operat_aux[MAX_WORDS];
      infixatedInPlaceTranslator(words[i], auxiliar, is_operat_aux, dim_aux);
      double res = 0;

      int right_brace = 0, left_brace = 0;
      for (int i1 = 0; i1 < dim_aux; ++i1) {
        if (is_operat_aux[i1]) {
          if (auxiliar[i1]==-7)
            right_brace++;
          if (auxiliar[i1]==-8)
            left_brace++;
        }
      }
      if (right_brace!=left_brace) {
        success = false;
        return;
      }

      calculateFinalResult(success, res, auxiliar, is_operat_aux, dim_aux,
                           true);

      if (success) {
        is_operator[post_numbers] = false;
        postfix_array[post_numbers++] = res;
      }
    } else {
      only_expression = false;
      int digit_binding = getValue(aliases, dimension, words[i]);

      if (digit_binding >= 0) {
        if (predecessor==-10) {
          predecessor = digit_binding;
        } else {
          if ((digit_binding < 100 && predecessor < 100 &&
              digit_binding >= 10 && predecessor >= 10) ||
              (digit_binding==100 && predecessor==100) ||
              (digit_binding==1000 && predecessor==1000) ||
              (digit_binding==1000000 && predecessor==1000000)) {
            success = false;
            return;
          }
          predecessor = digit_binding;
        }
        forming_number = true;
        numberBuilder(number, digit_binding, power_ten);
      }
      if (digit_binding < 0 || i==0) {
        if (forming_number)
          postfix_array[post_numbers++] = number;
        number = 0;
        predecessor = -10;
        power_ten = 1;
        forming_number = false;
        if (digit_binding <= -2) {
          if (digit_binding <= -33 && digit_binding >= -66)
            prefixated = false;
          if (digit_binding <= -77 && !prefixated)
            only_expression = false;
          if (digit_binding==-2)
            number_of_ands++;
          if (digit_binding <= -3 && digit_binding >= -6)
            number_of_postorder_operations++;
          is_operator[post_numbers] = true;
          postfix_array[post_numbers++] = digit_binding;
        }
      }
    }
  }
  //sum ( one plus one ) and one

  if (number_of_ands!=number_of_postorder_operations && prefixated) {
    success = false;
    return;
  }
  if (!only_expression) {
    if (prefixated) {
      for (int i = 0; i < post_numbers; i++) {
        if ((postfix_array[i]==-2 || postfix_array[i]==-77 ||
            postfix_array[i]==-88) &&
            is_operator[i]) {
          for (int j = i; j < post_numbers - 1; j++) {
            postfix_array[j] = postfix_array[j + 1];
            is_operator[j] = is_operator[j + 1];
          }
          i--;
          post_numbers--;
        }
      }
      calculateFinalResult(success, result, postfix_array, is_operator,
                           post_numbers, false);
    } else {
      double infix_array[MAX_WORDS];
      bool is_ope[MAX_WORDS];
      int infix_numbers = post_numbers;
      for (int i = post_numbers - 1; i >= 0; i--) {
        infix_array[i] = postfix_array[(post_numbers - 1) - i];
        is_ope[i] = is_operator[(post_numbers - 1) - i];

      }
      for (int i = 0; i < infix_numbers - 1; i++) {
        if (infix_array[i] <= -33 && is_ope[i] && infix_array[i] >= -66 && is_ope[i + 1] &&
            infix_array[i + 1]==-2) {
          for (int j = i + 1; j < post_numbers - 1; j++) {
            infix_array[j] = infix_array[j + 1];
            is_ope[j] = is_ope[j + 1];
          }
          infix_numbers--;
          number_of_ands--;
        }
      }
      if (number_of_ands!=number_of_postorder_operations) {
        success = false;
        return;
      }

      for (int i = infix_numbers - 1; i >= 0; --i) {
        if (infix_array[i] <= -3 && infix_array[i] >= -6 && is_ope[i]) {
          int j = i + 1;
          while (j < infix_numbers) {
            if (infix_array[j]==-2 && is_ope[j])
              break;
            j++;
          }
          infix_array[j] = infix_array[i];
          is_ope[j] = is_ope[i];
          for (int k = i; k < infix_numbers - 1; k++) {

            infix_array[k] = infix_array[k + 1];
            is_ope[k] = is_ope[k + 1];
          }
          infix_numbers--;
        } else if (infix_array[i] <= -33 && is_ope[i]) {
          infix_array[i] = infix_array[i]/11;
        }
      }
      int right_brace = 0, left_brace = 0;
      for (int i = 0; i < infix_numbers; ++i) {
        if (is_ope[i]) {
          if (infix_array[i]==-7)
            right_brace++;
          if (infix_array[i]==-8)
            left_brace++;
        }
      }
      if (right_brace!=left_brace) {
        success = false;
        return;
      }
      int enters = 0;
      while (twoOperatorsTogether(infix_array, infix_numbers) && enters
          < 2) {
        enters++;
        // eliminates all the copys of pluses from the beginning and
        //only two
        // minuses at a time
        bool minuses;
        for (int i = 0; i < infix_numbers - 2; ++i) {
          if (i==0 && is_ope[i] && is_ope[i + 1] && ((infix_array[i]==-4 && infix_array[i + 1]==
              -4) ||
              (infix_array[i]==-3 && infix_array[i + 1]==
                  -3))) {
            minuses = infix_array[i + 1]!=-3;

            int j = i;
            if (minuses) {
              int t = 1;
              while (t >= 0) {
                deleteAtPosition(infix_array, is_ope, infix_numbers, j);
                t--;
              }
            } else {
              while (infix_array[j]==-3 && is_ope[j]) {
                deleteAtPosition(infix_array, is_ope, infix_numbers, j);
              }
            }
            i--;
          }
        }

        // eliminates two minuses at a time or all the following pluses
        for (int i = 0; i < infix_numbers - 2; ++i) {
          if (infix_array[i] < 0 && is_ope[i + 1] && is_ope[i + 2] &&
              ((infix_array[i + 1]==-4 && infix_array[i + 2]==-4) ||
                  (infix_array[i + 1]==-3 && infix_array[i + 2]==-3))) {
            minuses = infix_array[i + 1]!=-3;
            int j = i + 1;
            if (minuses) {
              int t = 1;
              while (t >= 0) {
                deleteAtPosition(infix_array, is_ope, infix_numbers, j);
                t--;
              }
            } else {
              while (infix_array[j]==-3 && is_ope[j]) {
                deleteAtPosition(infix_array, is_ope, infix_numbers, j);
              }
            }
            i--;
          }
        }
      }
      for (int i = 0; i < infix_numbers - 2; ++i) {
        if (infix_array[i] < 0 && is_ope[i + 1] && is_ope[i + 2] &&
            ((infix_array[i + 1]==-4 && infix_array[i + 2]==-3) ||
                (infix_array[i + 1]==-3 && infix_array[i + 2]==-4))) {
          int j;
          if (infix_array[i + 1]==-3 && is_ope[i + 1])
            j = i + 1;
          else
            j = i + 2;
          deleteAtPosition(infix_array, is_ope, infix_numbers, j);
        }
      }
      for (int i = 0; i < infix_numbers - 1; ++i) {
        if (infix_array[i] < 0 && infix_array[i + 1]==-4 && is_ope[i] && is_ope[i + 1]) {
          if (i + 2 < infix_numbers) {
            if (infix_array[i + 2] > 0) {
              infix_array[i + 2] *= (-1);
              deleteAtPosition(infix_array, is_ope, infix_numbers, i + 1);
            }
          }
        }
      }
      infixatedDoubleTranslator(infix_array, is_ope, infix_numbers);
      calculateFinalResult(success, result, infix_array, is_ope, infix_numbers,
                           true);
    }
  } else {
    if (one_expression) {
      result = postfix_array[0];
    }
  }
}


//#######################################(###############################################################################

/*
 what is the sum of the division of three by seven and the product of three divided by seven and four plus three =5.142857
 what is the sum of the division of three by seven and the product of three divided by seven and ( four plus three )= 3.428571
 4+-3/-54= 4.055556
 one + one = 2.000000
 ( one + 32/-3 ) / -6=1.611111
 one divided by 0.00032=3125.000000
 one divided by -4.5=-0.222222
 sum of one plus one and three =5.000000
 sum of ( one plus one ) and three=5.000000
 division of ( three ) by ten=0.300000
  what is the sum of the division of three by seven and the product of three by five=15.428571429
 one + minus three = 2.00000
 */