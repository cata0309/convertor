#include "LogicsFunctions.hpp"

//################################################ Input, definitions related ##########################################

void convertToLowerCase(char *input) {
  for (size_t i = 0; i < strlen(input); ++i) {
    if (input[i] >= 'A' && input[i] <= 'Z') {
      input[i] += 32;
    }
  }
}

int getValue(Aliases *aliases, int dimension, char *key) {
  for (int i = 0; i < dimension; ++i) {
    if (strcmp(aliases[i].letters.c_str(), key)==0) {
      return aliases[i].digits;
    }
  }
  return -1;
}


//######################################################################################################################


//####################################### Stack(characters) operations related ##########################################

inline bool isStackCharEmpty(ElStackChar *head) {
  return (head==nullptr);
}

void popStackChar(ElStackChar *&head) {
  //if the stack is not empty already that means we can still eliminate elements from it
  if (head) {
    //we move the top of the stack to one level below the current one and we delete the element that was on the
    // top of the stack
    ElStackChar *toBeDeleted = head;
    head = head->next;
    delete (toBeDeleted);
  }
}

void pushStackChar(ElStackChar *&head, char value) {
  //a new element is created
  ElStackChar *element = new(ElStackChar);
  //the value of parameter `value` is assigned to the value of `element->value`
  element->value = value;
  element->next = head;
  //changes the head, the topNumberStack of the stack
  head = element;

}

inline bool isStackDoubleEmpty(ElStackDouble *head) {
  return (head==nullptr);
}

void popStackDouble(ElStackDouble *&head) {
  //if the stack is not empty already that means we can still eliminate elements from it
  if (head) {
    //we move the top of the stack to one level below the current one and we delete the element that was on the
    // top of the stack
    ElStackDouble *toBeDeleted = head;
    head = head->next;
    delete (toBeDeleted);
  }
}

void pushStackDouble(ElStackDouble *&head, double value) {
  //a new element is created
  ElStackDouble *element = new(ElStackDouble);
  //the value of parameter `value` is assigned to the value of `element->value`
  element->value = value;
  element->next = head;
  //changes the head, the topNumberStack of the stack
  head = element;
}

//######################################################################################################################


//####################################### Queue(characters) operations related #########################################

void insertQueueChar(ElQueueChar *&head, char *value) {
  //a new element is created
  ElQueueChar *element = new(ElQueueChar);
  //the value of parameter `value` is assigned to the value of `element->value`
  strcpy(element->value, value);
  element->next = nullptr;
  //if the queue is empty we change the front of it
  if (head==nullptr) {
    head = element;
  } else {
    //otherwise we iterate to the last element of the queue and make its successor the element that was early created
    ElQueueChar *iter = head;
    while (iter->next!=nullptr) {
      iter = iter->next;
    }
    iter->next = element;
  }
}

inline bool isQueueCharEmpty(ElQueueChar *head) {
  return (head==nullptr);
}

void insertQueueDouble(ElQueueDouble *&head, double value) {
  //a new element is created
  ElQueueDouble *element = new(ElQueueDouble);
  //the value of parameter `value` is assigned to the value of `element->value`
  element->value = value;
  element->next = nullptr;
  //if the queue is empty we change the front of it
  if (head==nullptr) {
    head = element;
  } else {
    //otherwise we iterate to the last element of the queue and make its successor the element that was early created
    ElQueueDouble *iter = head;
    while (iter->next!=nullptr) {
      iter = iter->next;
    }
    iter->next = element;
  }
}

inline bool isQueueDoubleEmpty(ElQueueDouble *head) {
  return (head==nullptr);
}

//######################################################################################################################


//################################ Priority, checking in fixated, translator, conversions ##############################

void infixatedInPlaceTranslator(char *value, double *array, int &dimension) {
  //the separation of the expression into numbers and symbols, all of them are C type strings with a size of at least 1
  // unit, they are stores in an array of C type strings.
  char infix[MAX_WORDS][MAX_KEY_DIM];
  int infix_dim = 0;
  for (int index = 0; index < strlen(value); ++index) {
    if (strchr("+-*/()", value[index])) {
      infix[infix_dim][0] = value[index];
      infix[infix_dim++][1] = '\0';
    } else {
      int aux = 0;
      while (index < strlen(value) && strchr("0123456789", value[index])) {
        infix[infix_dim][aux++] = value[index++];
      }
      index--;
      infix[infix_dim++][aux] = '\0';
    }
  }
  //The conversion from in fixated notation to post fixated notation using a queue, a stack and an array(it behaves as a
  //queue)
  ElQueueChar *postfixate = nullptr;
  ElStackChar *stack = nullptr;

  for (int index = 0; index < infix_dim; ++index) {
    if (!strchr("+-*/()", infix[index][0])) { //if it's a number(written with characters) it gets inserted to the queue
      insertQueueChar(postfixate, infix[index]);
    } else {
      if (infix[index][0]==')') {//otherwise if it matched a closing round bracket it means that it must have been
        //finished `()` expression
        while (stack->value!='(') {
          char aux[2];
          aux[0] = stack->value;
          aux[1] = '\0';
          insertQueueChar(postfixate, aux);
          popStackChar(stack);
        }
        popStackChar(stack);

      } else {
        while (!isStackCharEmpty(stack) && stack->value!='('
            && prioritiesChar(stack->value) >= prioritiesChar(infix[index][0])) {
          char aux[2];
          aux[0] = stack->value;
          aux[1] = '\0';

          insertQueueChar(postfixate, aux);
          popStackChar(stack);
        }
        pushStackChar(stack, infix[index][0]);
      }
    }
  }
  while (!isStackCharEmpty(stack)) {
    char aux[2];
    aux[0] = stack->value;
    aux[1] = '\0';
    insertQueueChar(postfixate, aux);
    popStackChar(stack);
  }
  //while the queue is not empty we insertChar all the elements into the post fixated notation array but also
  //updating its size
  //The actual check of the validity of this notation is made with the last form of expression
  while (!isQueueCharEmpty(postfixate)) {
    if (postfixate->value[0]=='+') {
      array[dimension++] = -3;
    } else if (postfixate->value[0]=='-') {
      array[dimension++] = -4;
    } else if (postfixate->value[0]=='*') {
      array[dimension++] = -5;
    } else if (postfixate->value[0]=='/') {
      array[dimension++] = -6;
    } else {
      array[dimension++] = atoi(postfixate->value);
    }
    postfixate = postfixate->next;
  }
}
//TODO array is operator !!!
void infixatedDoubleTranslator(double *infix, int &infix_dim) {

  ElQueueDouble *postfixate = nullptr;
  ElStackDouble *stack = nullptr;

  for (int index = 0; index < infix_dim; ++index) {
    if (infix[index] >= 0) { //if it's a number(written with characters) it gets inserted to the queue
      insertQueueDouble(postfixate, infix[index]);
    } else {
      if (infix[index]==-8) {//otherwise if it matched a closing round bracket it means that it must have been
        //finished `()` expression
        while (stack->value!=-7) {
          insertQueueDouble(postfixate, stack->value);
          popStackDouble(stack);
        }
        popStackDouble(stack);
      } else {
        while (!isStackDoubleEmpty(stack) && stack->value!=-7
            && prioritiesDouble(stack->value) >= prioritiesDouble(infix[index])) {

          insertQueueDouble(postfixate, stack->value);
          popStackDouble(stack);
        }
        pushStackDouble(stack, infix[index]);
      }
    }
  }
  while (!isStackDoubleEmpty(stack)) {
    insertQueueDouble(postfixate, stack->value);
    popStackDouble(stack);
  }
  //while the queue is not empty we insertDouble all the elements into the post fixated notation array but also
  //updating its size
  //The actual check of the validity of this notation is made with the last form of expression
  infix_dim = 0;
  while (!isQueueDoubleEmpty(postfixate)) {
    infix[infix_dim++] = postfixate->value;
    postfixate = postfixate->next;
  }
  std::cout << "coaie";
}
bool isInfixatedNotation(char *str) {
  bool numbers = false;
  for (size_t index = 0; index < strlen(str); ++index) {
    if (!strchr("+-/*()0123456789", str[index])) {
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
    if ((power_ten==1000 && (digit_binding==100)) || (power_ten==1000000 && (digit_binding==100)))
      power_ten *= digit_binding;
    else if (digit_binding > power_ten)
      power_ten = digit_binding;
  } else if (digit_binding > 9 && digit_binding < 100 && power_ten < 100) { number += digit_binding; }
  else { number += digit_binding*power_ten; }
}

bool onlyDigits(char *str) {
  for (size_t index = 0; str[index]; ++index)
    if (!strchr("0123456789", str[index])) {
      return false;
    }
  return true;
}

int prioritiesChar(char symbol) {
  if (symbol=='(' || symbol==')')//the '(' and ')' have the biggest priority
    return 3;
  if (symbol=='*' || symbol=='/')//the '*' and '/' have the second biggest priority
    return 2;
  //default symbol=='+' || symbol=='-' //they have the smallest priority
  return 1;
}
int prioritiesDouble(double symbol) {
  if (symbol==-7 || symbol==-8)//the '(' and ')' have the biggest priority
    return 3;
  if (symbol==-5 || symbol==-6)//the '*' and '/' have the second biggest priority
    return 2;
  //default symbol=='+' || symbol=='-' //they have the smallest priority
  return 1;
}

//######################################################################################################################


//###################################### Stack(integers), operations, calculating final result #########################

void calculateFinalResult(bool &valid_entry,
                          double &final_result,
                          double *final_translation,
                          int final_dimension,
                          bool expression) {

  std::cout << "*** ";
  for (int i = 0; i < final_dimension; ++i)
    if (final_translation[i]==-3)
      std::cout << '+';
    else if (final_translation[i]==-4)
      std::cout << '-';
    else if (final_translation[i]==-5)
      std::cout << '*';
    else if (final_translation[i]==-6)
      std::cout << '/';
    else
      std::cout << final_translation[i] << " ";
  std::cout << "##\n";
  if (final_dimension==0) {
    valid_entry = false;
    return;
  }
  LLin *postfix = nullptr;
  for (int i = final_dimension - 1; i >= 0; --i)
    pushNumberStack(postfix, final_translation[i]);
  LLin *operations_stack = nullptr;
  while (!isNumberStackEmpty(postfix) && valid_entry) {
    double x = topNumberStack(postfix);
    popNumberStack(postfix);
    if (operand(x)) {
      pushNumberStack(operations_stack, x);
    } else {
      if (isNumberStackEmpty(operations_stack)) {
        valid_entry = false;
        return;
      }
      double drp = topNumberStack(operations_stack);
      popNumberStack(operations_stack);
      if (isNumberStackEmpty(operations_stack)) {
        valid_entry = false;
        return;
      }
      double stg = topNumberStack(operations_stack);
      popNumberStack(operations_stack);

      if (x==-6) {
        if ((expression && drp==0) || (!expression && stg==0)) {
          valid_entry = false;
          return;
        }
      }
      double val = executeOperation(stg, x, drp, expression);
      pushNumberStack(operations_stack, val);

    }

  }
  if (!valid_entry) { return; }
  double final_value = topNumberStack(operations_stack);
  popNumberStack(operations_stack);
  if (!isNumberStackEmpty(operations_stack)) {
    valid_entry = false;
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

bool isNumberStackEmpty(LLin *stack_queue) { return (stack_queue==nullptr); }

bool operand(double op) { return (op >= 0); }

void popNumberStack(LLin *&stack) {
  LLin *toBeDeleted = stack;
  stack = stack->urm;
  delete (toBeDeleted);
}

void processingInput(char *input, bool &success, double &result, Aliases *aliases, int dimension) {
  //conversion of the input to lowercase!
  convertToLowerCase(input);
  result = 0;
  success = true;
  bool prefixated = true;
  //`words` is an array of C type strings that hold only one world independently
  char words[MAX_WORDS][MAX_KEY_DIM];

  //`nr_words` is the dimension of this array
  int nr_words = 0;

  //Phase two of input manipulation: Separating input into words
  char *p = strtok(input, " ?");
  while (p) {
    //we ignore all the words that are not in the `dictionary` file(it's not treating all the misleading inputs !!)
    bool ver = false;
    if (isInfixatedNotation(p)) {
      strcpy(words[nr_words++], p);
      ver = true;
    } else {
      int value = getValue(aliases, dimension, p);
      if (value!=-1) {
        if (value!=-10)
          strcpy(words[nr_words++], p);
        ver = true;
      }
    }
    if (!ver) {
      success = false;
      return;
    }
    p = strtok(nullptr, " ?");
  }
//  int k = 0;
//  for (int i = 0; i < strlen(input); ++i) {
//      words[nr_words][k++] = input[i];
//      if(((strchr("+-/*()",input[i])&&!strchr("0123456789",input[i+1]))||(strchr("0123456789",input[i])&&!strchr("0123456789+-*/()",input[i+1]))||(!strchr("0123456789+-/*()",input[i])&&strchr("0123456789+-/*()",input[i+1]))||input[i+1]==' ')&&i+1<strlen(input))
//      {words[nr_words][k]='\0';
//        k = 0;
//        nr_words++;
//        }
//  }
//  for(int i=0;i<nr_words;++i)
//  {
//    std::cout<<"cuv:"<<i+1<<" "<<words[i]<<"\n";
//  }
//we ignore all the words that are not in the `dictionary` file(it's not treating all the misleading inputs !!)
//    bool ver = false;
//    if (isInfixatedNotation(p)) {
//      strcpy(words[nr_words++], p);
//      ver = true;
//    } else {
//      int value = getValue(aliases, dimension, p);
//      if (value!=-1) {
//        if (value!=-10)
//          strcpy(words[nr_words++], p);
//        ver = true;
//      }
//    }
//    if (!ver) {
//      success = false;
//      return;
//    }
//    p = strtok(nullptr, " ?");
//  }


  double postfix_array[MAX_WORDS];

  int post_numbers = 0;

//`power_ten` has the role of being a helper scale factor when building the base 10 numbers
  int power_ten = 1;
//`number` is a temporary storage for the number that is going to be formed
  int number = 0;
  bool forming_number = false;
  int predecessor = -10;
  bool only_expression = true;
  bool one_expression = false;

  int number_of_ands = 0;
  int number_of_postorder_operations = 0;

  for (
      int i = nr_words - 1;
      i >= 0; --i) {
    if (
        onlyDigits(words[i])
        ) {
      only_expression = false;
      postfix_array[post_numbers++] =
          atoi(words[i]);
    } else if (
        isInfixatedNotation(words[i])
        ) {
      one_expression = true;
      double auxiliar[MAX_WORDS];
      int dim_aux = 0;
      infixatedInPlaceTranslator(words[i], auxiliar, dim_aux
      );
      double res = 0;
      calculateFinalResult(success, res, auxiliar, dim_aux,
                           true);

      if (success) {
        postfix_array[post_numbers++] =
            res;
      }

    } else {
      only_expression = false;
      int digit_binding = getValue(aliases, dimension, words[i]);

      if (digit_binding >= 0) {
        if (predecessor==-10) {
          predecessor = digit_binding;
        } else {
          if (
              (digit_binding < 100 && predecessor < 100 && digit_binding >= 10 && predecessor >= 10)
                  || (digit_binding==100 && predecessor==100)
                  || (digit_binding==1000 && predecessor==1000) || (digit_binding==1000000 && predecessor==1000000)) {
            success = false;
            return;
          }
          predecessor = digit_binding;
        }
        forming_number = true;
        numberBuilder(number, digit_binding, power_ten
        );
      }
      if (digit_binding < 0 || i==0) {
        if (forming_number)
          postfix_array[post_numbers++] =
              number;
        number = 0;
        predecessor = -10;
        power_ten = 1;
        forming_number = false;
        if (digit_binding <= -2) {
          if (digit_binding <= -33)
            prefixated = false;
          if (digit_binding <= -77)
            only_expression = false;
          if (digit_binding==-2)
            number_of_ands++;
          if (digit_binding <= -3 && digit_binding >= -6)
            number_of_postorder_operations++;
          postfix_array[post_numbers++] =
              digit_binding;
        }
      }
    }
  }
  if (number_of_ands!=
      number_of_postorder_operations && prefixated
      ) {
    success = false;
    return;
  }
  if (!only_expression) {
    if (prefixated) {
      for (
          int i = 0;
          i < post_numbers;
          i++) {
        if (postfix_array[i]==-2 || postfix_array[i]==-77 || postfix_array[i]==-88) {
          for (
              int j = i;
              j < post_numbers - 1; j++)
            postfix_array[j] = postfix_array[j + 1];
          post_numbers--;
        }
      }
      calculateFinalResult(success, result, postfix_array, post_numbers,
                           false);
    } else {
      std::cout << "coaie";
      double infix_array[MAX_WORDS];
      int infix_numbers = post_numbers;
      for (
          int i = post_numbers - 1;
          i >= 0; i--)
        infix_array[i] = postfix_array[(post_numbers - 1) - i];

      for (
          int i = 0;
          i < infix_numbers - 1; i++) {
        if (infix_array[i] <= -33 && infix_array[i + 1]==-2) {
          for (
              int j = i + 1;
              j < post_numbers - 1; j++)
            infix_array[j] = infix_array[j + 1];
          infix_numbers--;
          number_of_ands--;
        }
      }
      if (number_of_ands!=number_of_postorder_operations) {
        success = false;
        return;
      }

      for (
          int i = 0;
          i < infix_numbers;
          i++) {
        std::cout << infix_array[i] << ' ';
      }
      std::cout << "tras:\n";
      for (
          int i = infix_numbers - 1;
          i >= 0; --i) {
        if (infix_array[i] <= -3 && infix_array[i] >= -6) {
          int j = i + 1;
          while (j < infix_numbers) {
            if (infix_array[j]==-2)
              break;
            j++;
          }
          infix_array[j] = infix_array[i];

          for (
              int k = i;
              k < infix_numbers - 1; k++)
            infix_array[k] = infix_array[k + 1];
          infix_numbers--;
        } else if (infix_array[i] <= -33) {
          infix_array[i] = infix_array[i]/11;
        }
      }
      for (
          int i = 0;
          i < infix_numbers;
          i++) {
        if (infix_array[i]==-3)
          std::cout << '+';
        else if (infix_array[i]==-4)
          std::cout << '-';
        else if (infix_array[i]==-5)
          std::cout << '*';
        else if (infix_array[i]==-6)
          std::cout << '/';
        else if (infix_array[i]==-7)
          std::cout << '(';
        else if (infix_array[i]==-8)
          std::cout << ')';
        else
          std::cout << infix_array[i];
      }
      infixatedDoubleTranslator(infix_array, infix_numbers
      );
      calculateFinalResult(success, result, infix_array, infix_numbers,
                           true);

    }
  } else {
    if (one_expression) {
      result = postfix_array[0];
    }
  }
}

void pushNumberStack(LLin *&stack, double element) {
  LLin *toBeInserted = new (LLin);
  toBeInserted->info = element;
  toBeInserted->urm = stack;
  stack = toBeInserted;
}

double topNumberStack(LLin *stack) {
  if (stack==nullptr)
    return -10;
  return stack->info;
}

//#######################################(###############################################################################

/*
 what is the sum of the division of three by seven and the product of three divided by seven and four plus three
 TODO ADD OPERATOR to solve this `what is the sum of 1-4 and three` it must be added in almost all functions related to processing input
 the sum of 1-4 and three
 */