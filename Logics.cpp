#include "Logics.hpp"

//################################################ Input, definitions related ##########################################

void convertToLowerCase(char *input) {
  for (size_t i = 0; i < strlen(input); ++i) {
    if (input[i] >= 'A' && input[i] <= 'Z') {
      input[i] += 32;
    }
  }
}

int getValue(Aliases *aliases, int dimension, char *key) {
  for (unsigned int i = 0; i < dimension; ++i) {
    if (strcmp(aliases[i].letters, key)==0) {
      return aliases[i].digits;
    }
  }
  return -1;
}

void setupAliases(Aliases *aliases, std::ifstream &fin, int &dimension) {
  char word[MAX_KEY_DIM];
  int value;
  while (fin >> word && fin >> value) {
    strcpy(aliases[dimension].letters, word);
    aliases[dimension++].digits = value;
  }
}

//######################################################################################################################


//####################################### Stack(characters) operations related ##########################################

inline bool isStackEmpty(ElStack *head) {
  return (head==nullptr);
}

void pop(ElStack *&head) {
  //if the stack is not empty already that means we can still eliminate elements from it
  if (head) {
    //we move the top of the stack to one level below the current one and we delete the element that was on the
    // top of the stack
    ElStack *toBeDeleted = head;
    head = head->next;
    delete (toBeDeleted);
  }
}

void push(ElStack *&head, char value) {
  //a new element is created
  ElStack *element = new(ElStack);
  //the value of parameter `value` is assigned to the value of `element->value`
  element->value = value;
  element->next = head;
  //changes the head, the topNumberStack of the stack
  head = element;
}

//######################################################################################################################


//####################################### Queue(characters) operations related #########################################

void insert(ElQueue *&head, char *value) {
  //a new element is created
  ElQueue *element = new(ElQueue);
  //the value of parameter `value` is assigned to the value of `element->value`
  strcpy(element->value, value);
  element->next = nullptr;
  //if the queue is empty we change the front of it
  if (head==nullptr) {
    head = element;
  } else {
    //otherwise we iterate to the last element of the queue and make its successor the element that was early created
    ElQueue *iter = head;
    while (iter->next!=nullptr) {
      iter = iter->next;
    }
    iter->next = element;
  }
}

inline bool isQueueEmpty(ElQueue *head) {
  return (head==nullptr);
}

//######################################################################################################################


//################################ Priority, checking in fixated, translator, conversions ##############################

void infixatedInPlaceTranslator(char *value, int *array, int &dimension) {
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
  ElQueue *postfixate = nullptr;
  ElStack *stack = nullptr;

  for (int index = 0; index < infix_dim; ++index) {
    if (!strchr("+-*/()", infix[index][0])) { //if it's a number(written with characters) it gets inserted to the queue
      insert(postfixate, infix[index]);
    } else {
      if (infix[index][0]==')') {//otherwise if it matched a closing round bracket it means that it must have been
        //finished `()` expression
        while (stack->value!='(') {
          char aux[2];
          aux[0] = stack->value;
          aux[1] = '\0';
          insert(postfixate, aux);
          pop(stack);
        }
        pop(stack);

      } else {
        while (!isStackEmpty(stack) && stack->value!='(' && priorities(stack->value) >= priorities(infix[index][0])) {
          char aux[2];
          aux[0] = stack->value;
          aux[1] = '\0';

          insert(postfixate, aux);
          pop(stack);
        }
        push(stack, infix[index][0]);
      }
    }
  }
  while (!isStackEmpty(stack)) {
    char aux[2];
    aux[0] = stack->value;
    aux[1] = '\0';
    insert(postfixate, aux);
    pop(stack);
  }
  //while the queue is not empty we insert all the elements into the post fixated notation array but also
  //updating its size
  //The actual check of the validity of this notation is made with the last form of expression
  while (!isQueueEmpty(postfixate)) {
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

bool isInfixatedNotation(char *str) {
  char infix_alphabet[] = "0123456789+-/*()";
  for (size_t index = 0; str[index]; ++index) {
    if (!strchr(infix_alphabet, str[index])) {
      return false;
    }
  }
  return true;
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

int priorities(char symbol) {
  if (symbol=='(' || symbol==')')//the '(' and ')' have the biggest priority
    return 3;
  if (symbol=='*' || symbol=='/')//the '*' and '/' have the second biggest priority
    return 2;
  //default symbol=='+' || symbol=='-' //they have the smallest priority
  return 1;
}

//######################################################################################################################


//###################################### Stack(integers), operations, calculating final result #########################

void calculateFinalResult(bool &valid_entry, double &final_result, int *final_translation, int final_dimension) {
  LLin *postfix = nullptr;
  for (int i = final_dimension - 1; i >= 0; --i)
    pushNumberStack(postfix, final_translation[i]);
  LLin *operations_stack = nullptr;
  while (!isNumberStackEmpty(postfix) && valid_entry) {
    int x = topNumberStack(postfix);
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

      if (x==-7 && drp==0) {
        valid_entry = false;
        return;
      }

      if (drp==0 && x==-6) {
        valid_entry = false;
        return;
      }
      double val = executeOperation(stg, x, drp);
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

double executeOperation(double left, double op, double right) {
  switch (int(op)) {
    case -3:return (left + right);
    case -4:return (left - right);
    case -5:return (left*right);
    default:return (left/right);
  }
}

bool isNumberStackEmpty(LLin *stack_queue) { return (stack_queue==nullptr); }

bool operand(int op) { return (op >= 0); }

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
  //`words` is an array of C type strings that hold only one world independently
  char words[MAX_WORDS][MAX_KEY_DIM];

  //`nr_words` is the dimension of this array
  int nr_words = 0;

  //Phase two of input manipulation: Separating input into words
  char *p = strtok(input, " ?");
  while (p) {
    //we ignore all the words that are not in the `dictionary` file(it's not treating all the misleading inputs !!)
    int value = getValue(aliases, dimension, p);
    if (value!=-1 || isInfixatedNotation(p)) {
      if (value!=-10)
        strcpy(words[nr_words++], p);

    } else {
      success = false;
      return;
    }
    p = strtok(nullptr, " ?");
  }
  int postfix_array[MAX_WORDS];

  int post_numbers = 0;

  //`power_ten` has the role of being a helper scale factor when building the base 10 numbers
  int power_ten = 1;
  //`number` is a temporary storage for the number that is going to be formed
  int number = 0;
  bool forming_number = false;
  int predecessor = -10;
  for (int i = nr_words - 1; i >= 0; --i) {
    if (onlyDigits(words[i])) {
      postfix_array[post_numbers++] = atoi(words[i]);
    } else if (isInfixatedNotation(words[i])) {
      infixatedInPlaceTranslator(words[i], postfix_array, post_numbers);
    } else {
      int digit_binding = getValue(aliases, dimension, words[i]);

      if (digit_binding >= 0) {
        if (predecessor==-10) { predecessor = digit_binding; }
        else {
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
        numberBuilder(number, digit_binding, power_ten);
      }
      if (digit_binding < 0 || i==0) {
        if (forming_number)
          postfix_array[post_numbers++] = number;
        number = 0;
        predecessor = -10;
        power_ten = 1;
        forming_number = false;
        if (digit_binding < -2) {
          postfix_array[post_numbers++] = digit_binding;

        }
      }
    }
  }
  for (int index = 0; index < post_numbers; ++index) {
    std::cout << postfix_array[index] << ' ';
  }
  calculateFinalResult(success, result, postfix_array, post_numbers);
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

//######################################################################################################################