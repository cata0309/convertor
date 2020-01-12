#include "LogicsDataStructures.hpp"
//######################################################################################################################

//####################################### Stack(characters) operations related
//##########################################

bool isStackCharEmpty(ElStackChar *head) { return (head==nullptr); }
bool isQueueCharEmpty(ElQueueChar *head) { return (head==nullptr); }
bool isQueueDoubleEmpty(ElQueueDouble *head) {
  return (head==nullptr);
}

void convertToLowerCase(char *input) {
  for (size_t i = 0; i < strlen(input); ++i) {
    if (input[i] >= 'A' && input[i] <= 'Z') {
      input[i] += 32;
    }
  }
}

bool isEmpty(LLin *stack) { return (stack==nullptr); }

void popStackChar(ElStackChar *&head) {
  // if the stack is not empty already that means we can still eliminate
  // elements from it
  if (head) {
    // we move the top of the stack to one level below the current one and we
    // delete the element that was on the
    // top of the stack
    ElStackChar *toBeDeleted = head;
    head = head->next;
    delete (toBeDeleted);
  }
}

void pushStackChar(ElStackChar *&head, char value, bool is_operat) {
  // a new element is created
  ElStackChar *element = new (ElStackChar);
  // the info of parameter `info` is assigned to the info of `element->info`
  element->value = value;
  element->is_operat = is_operat;
  element->next = head;
  // changes the head, the topNumberStack of the stack
  head = element;
}

//######################################################################################################################

//####################################### Queue(characters) operations related
//#########################################

void insertQueueChar(ElQueueChar *&head, char *value, bool is_operat) {
  // a new element is created
  ElQueueChar *element = new (ElQueueChar);
  // the info of parameter `info` is assigned to the info of `element->info`
  strcpy(element->value, value);
  element->is_operat = is_operat;
  element->next = nullptr;
  // if the queue is empty we change the front of it
  if (head==nullptr) {
    head = element;
  } else {
    // otherwise we iterate to the last element of the queue and make its
    // successor the element that was early created
    ElQueueChar *iter = head;
    while (iter->next!=nullptr) {
      iter = iter->next;
    }
    iter->next = element;
  }
}

void insertQueueDouble(ElQueueDouble *&head, double value, bool is_operat) {
  // a new element is created
  ElQueueDouble *element = new (ElQueueDouble);
  // the info of parameter `info` is assigned to the info of `element->info`
  element->value = value;
  element->is_operat = is_operat;
  element->next = nullptr;
  // if the queue is empty we change the front of it
  if (head==nullptr) {
    head = element;
  } else {
    // otherwise we iterate to the last element of the queue and make its
    // successor the element that was early created
    ElQueueDouble *iter = head;
    while (iter->next!=nullptr) {
      iter = iter->next;
    }
    iter->next = element;
  }
}

void push(LLin *&stack, double element, bool is_operat) {
  LLin *toBeInserted = new (LLin);
  toBeInserted->info = element;
  toBeInserted->is_operat = is_operat;
  toBeInserted->next = stack;
  stack = toBeInserted;
}

LLin *top(LLin *stack) { return stack; }
void pop(LLin *&stack) {
  LLin *toBeDeleted = stack;
  stack = stack->next;
  delete (toBeDeleted);
}

int getValue(Aliases *aliases, int dimension, char *key) {
  for (int i = 0; i < dimension; ++i) {
    if (strcmp(aliases[i].letters.c_str(), key)==0) {
      return aliases[i].digits;
    }
  }
  return -1;
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

//######################################################################################################################
