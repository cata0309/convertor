#include "LogicsRomanian.hpp"

void insereaza(LLin *&coada, double element, bool x) {
  LLin *nod_nou = new(LLin);
  nod_nou->info = element;
  nod_nou->is_operat = x;
  nod_nou->next = nullptr;
  if (coada==nullptr) {
    coada = nod_nou;
  } else {
    LLin *curent = coada;
    while (curent->next!=nullptr) {
      curent = curent->next;
    }
    curent->next = nod_nou;
  }
}

double top_citeste_valoare(LLin *stiva) {
  if (stiva==nullptr)
    return -10;
  return stiva->info;
}
bool top_citeste_IsOp(LLin *stiva) {
  if (stiva==nullptr)
    return false;
  return stiva->is_operat;
}

//functia doar_cifre(..) are rolul de a verifica daca un anumit sir de caractere contine numai cifre sau minus(pt nr negative
//in acest caz acesta poate fi convertit direct in numere
bool doar_cifre(char sir[]) {
  for (size_t i = 0; i < strlen(sir); ++i)
    if (!((sir[i] >= '0' && sir[i] <= '9') || (sir[i]=='-')))
      return false;
  return true;
}

bool validare(int *sir, unsigned lungime) {
  int operatii = 0, operanzi = 0;
  for (unsigned i = 0; i < lungime; ++i) {
    if ((i==0 || i==lungime - 1) && (sir[i]==-2 || sir[i]==-3)) {

      return false;

    } else if (i > 0 && sir[i]==sir[i - 1] && (sir[i]==-2 || sir[i]==-3)) {

      return false;

    }
    if (sir[i]!=-1 && sir[i]!=-2 && sir[i]!=-3) {
      if (sir[i] <= -4 || sir[i] <= -44)
        operatii++;
      else
        operanzi++;
    }
  }
  return !(operatii < 1 || operanzi < 2);
}
//functia oper transforma din scrierea sa in litere un numar in cifre , pana la intalnirea unui operator
double oper(int sir[], unsigned lung, int &incep) {
  double op;
  op = 0;

  int i;
  i = incep;
  while (!(sir[i] <= -44 && sir[i] >= -77) && i < lung) {
    if (sir[i] > 0) {
      if (sir[i] > 0 && sir[i] <= 19) {
        if (sir[i + 1]==100)op = op + sir[i++]*100;
        else {
          if (sir[i - 1]==-22 || sir[i - 1]==-2)op = op + sir[i];
          else {
            if (sir[i + 1]==1000 || sir[i + 1]==1000000) {
              if (op==0)op = sir[i];
              op = op*sir[i + 1];
              i = i + 2;
              op = op + oper(sir, lung, i);

              break;
            } else {
              op = op + sir[i];
            }

          }

        }
      } else {

        op = op + sir[i];
      }

    } else {
      if (sir[i]==-3) {
        i = i + 2;

        op = op*sir[i - 1];

        op = op + oper(sir, lung, i);

        break;
      }
    }
    i++;

  }
  incep = i;

  return op;
}
// functia TransformAllInInfixed transforma toate operatiile prefixate in infixate , totodata punand si parantezele necesare in cazul unui operator prefixat
void TransformAllInInfixed(int arrayofanswer[],
                           bool IfIsOp[],
                           unsigned &longofarray,
                           double infixed[],
                           int &longinfixed) {
  int j, i;

  for (i = longofarray - 1; i >= 0; i--) {
    if (arrayofanswer[i] <= -4 && arrayofanswer[i] >= -7) {
      for (j = i + 1; j < longofarray; j++) {
        if (arrayofanswer[j]==-8) {
          arrayofanswer[j] = arrayofanswer[i]*11;
          if (arrayofanswer[j + 1]==-2) {
            for (int k = j + 1; k < longofarray - 1; k++)
              arrayofanswer[k] = arrayofanswer[k + 1];
            longofarray--;
          }
          break;
        } else {
          if (arrayofanswer[j]==-11) {
            arrayofanswer[j] = arrayofanswer[i]*11;
            if (arrayofanswer[j + 1]==-2) {
              for (int k = j + 1; k < longofarray - 1; k++)
                arrayofanswer[k] = arrayofanswer[k + 1];
              longofarray--;
            }
            break;
          } else {
            if (arrayofanswer[j]==-2) {
              if (arrayofanswer[j + 1] >= 10 || (arrayofanswer[j - 1] < 20 && arrayofanswer[j - 1] >= 0)
                  || (arrayofanswer[j + 2]==-11)) {
                arrayofanswer[j] = arrayofanswer[i]*11;
                break;
              } else {

                if (j + 2==longofarray || (arrayofanswer[j + 2] <= -44 && arrayofanswer[j + 2] >= -77)) {
                  arrayofanswer[j] = arrayofanswer[i]*11;
                  break;

                } else {
                  if (arrayofanswer[j + 2]==-3) {
                    arrayofanswer[j] = -22;
                  } else {
                    if (arrayofanswer[j + 1] <= -4 && arrayofanswer[j + 1] >= -7) {
                      arrayofanswer[j] = arrayofanswer[i]*11;
                      break;
                    } else {
                      arrayofanswer[j] = -22;
                    }

                  }
                }
              }
            }

          }
        }

      }

    }
  }

  double op;

  j = 0;
  longinfixed = 0;
  while (j < longofarray) {
    if ((arrayofanswer[j] <= -44 && arrayofanswer[j] >= -77) || (arrayofanswer[j] <= -4 && arrayofanswer[j] >= -7)) {
      infixed[longinfixed++] = arrayofanswer[j++];
    } else {
      op = oper(arrayofanswer, longofarray, j);
      infixed[longinfixed++] = op;
    }
  }

  for (j = 0; j < longinfixed; j++) {
    IfIsOp[j] = false;
    if (infixed[j] <= -44 && infixed[j] >= -77) {
      if (infixed[j]==-55) {
        if (j==0) {
          infixed[j + 1] = (-1)*infixed[j + 1];
          for (i = j; i < longinfixed - 1; i++)infixed[i] = infixed[i + 1];
          longinfixed--;
        } else {
          if (infixed[j - 1] <= -44 && infixed[j - 1] >= -77 && IfIsOp[j - 1]) {
            if (infixed[j - 1]==-44) {
              infixed[j - 1] = -55;

              IfIsOp[j - 1] = true;
              for (i = j; i < longinfixed - 1; i++)infixed[i] = infixed[i + 1];
              longinfixed--;
            } else {
              if (infixed[j - 1]==-55) {
                infixed[j - 1] = -44;
                IfIsOp[j - 1] = true;
                for (i = j; i < longinfixed - 1; i++)infixed[i] = infixed[i + 1];
                longinfixed--;
              } else {
                if (infixed[j - 1]==-66 || infixed[j - 1]==-77) {
                  if (infixed[j + 1] > 0)infixed[j + 1] = (-1)*infixed[j + 1];
                  for (i = j; i < longinfixed - 1; i++)infixed[i] = infixed[i + 1];
                  longinfixed--;
                }
              }
            }

          } else {
            if (infixed[j - 1] <= -4 && infixed[j - 1] >= -7 && IfIsOp[j - 1]) {
              if (infixed[j + 1] > 0)infixed[j + 1] = (-1)*infixed[j + 1];
              for (i = j; i < longinfixed - 1; i++) {
                infixed[i] = infixed[i + 1];

              }
              longinfixed--;

            } else {
              IfIsOp[j] = true;
            }
          }

        }
      } else {
        IfIsOp[j] = true;
      }
    } else {
      if (infixed[j] <= -4 && infixed[j] >= -7) {
        IfIsOp[j] = true;
      }
    }
  }

  int numarpar;
  for (i = longinfixed - 1; i >= 0; i--) {
    numarpar = 0;
    if (infixed[i] <= -4 && infixed[i] >= -7 && IfIsOp[i]) {
      if (infixed[i + 1]==-9) {
        numarpar++;
        j = i + 2;
        while (numarpar!=0) {
          if (infixed[j]==-9)
            numarpar++;
          if (infixed[j]==-10)
            numarpar--;
          j++;

        }
        if (infixed[j + 1]==-9) {

          numarpar = 1;
          j = j + 2;
          while (numarpar!=0) {
            if (infixed[j]==-9)
              numarpar++;
            if (infixed[j]==-10)
              numarpar--;
            j++;

          }
          infixed[i] = -9;
          IfIsOp[i] = true;
          for (int t = longinfixed; t > j; t--) {
            infixed[t] = infixed[t - 1];
            IfIsOp[t] = IfIsOp[t - 1];
          }
          longinfixed++;
          infixed[j] = -10;
          IfIsOp[j] = true;
        } else {
          infixed[i] = -9;
          IfIsOp[i] = true;
          for (int t = longinfixed; t > j + 2; t--) {
            infixed[t] = infixed[t - 1];
            IfIsOp[t] = IfIsOp[t - 1];
          }
          longinfixed++;
          infixed[j + 2] = -10;
          IfIsOp[j + 2] = true;
        }

      } else {
        for (j = i + 1; infixed[j]!=infixed[i]*(11) && !IfIsOp[j]; j++);

        if (infixed[j + 1]==-9) {

          numarpar++;
          j = j + 2;

          while (numarpar!=0) {
            if (infixed[j]==-9)
              numarpar++;
            if (infixed[j]==-10)
              numarpar--;
            j++;
          }
          infixed[i] = -9;
          IfIsOp[i] = true;
          if (j==longinfixed)
            longinfixed++, infixed[j] = -10, IfIsOp[j] = true;
          else {
            for (int t = longinfixed; t > j; t--) {
              infixed[t] = infixed[t - 1];
              IfIsOp[t] = IfIsOp[t - 1];
            }
            longinfixed++;
            infixed[j] = -10;
            IfIsOp[j] = true;
          }

        } else {
          infixed[i] = -9;
          IfIsOp[i] = true;
          for (int t = longinfixed; t > j + 2; t--) {
            infixed[t] = infixed[t - 1];
            IfIsOp[t] = IfIsOp[t - 1];
          }
          longinfixed++;
          infixed[j + 2] = -10;
          IfIsOp[j + 2] = true;

        }
      }

    }

  }

}

double result(int operatorr, double operand1, double operand2) {
  switch (operatorr) {
    case -44:return operand1 + operand2;
    case -55:return operand1 - operand2;
    case -66:return operand1*operand2;
    case -77:return operand1/operand2;
      break;

  }
}

// aceasta functie returneaza prioritatea operatorilor , adunarea si scaderea avand prioritate 1 ,iar inmultirea si impartirea 2
int prioritofoperator(int operatorr) {
  if (operatorr >= -55)return 1;
  return 2;
}
// aceasta functie transforma ecuatia din infixata in postfixata
void TransformFromInfixToPostFix(LLin *&infix, LLin *&postfix) {
  LLin *S;
  S = nullptr;
  double x;
  bool t;
  while (!isEmpty(infix)) {
    x = infix->info;
    t = infix->is_operat;
    pop(infix);
    if (x > 0)insereaza(postfix, x, t);
    else {
      if (!t) {
        insereaza(postfix, x, t);
      } else {
        if (x==-10) {
          while (1) {
            if (top_citeste_valoare(S)==-9 && top_citeste_IsOp(S))break;
            else {
              insereaza(postfix, top_citeste_valoare(S), top_citeste_IsOp(S));
              pop(S);
            }
          }
          pop(S);

        } else {

          while (!isEmpty(S) && top_citeste_IsOp(S)
              && (prioritofoperator(top_citeste_valoare(S)) >= prioritofoperator(x)) && top_citeste_valoare(S)!=-9
              && (x <= -44 && x >= -77)) {
            insereaza(postfix, top_citeste_valoare(S), top_citeste_IsOp(S));
            pop(S);

          }

          push(S, x, t);

        }
      }
    }
  }
  while (!isEmpty(S)) {
    insereaza(postfix, top_citeste_valoare(S), top_citeste_IsOp(S));
    pop(S);

  }
}
// aceasta functie calculeaza valoarea expresiei postfixate
double ValueOfPostfixed(LLin *&postfix) {
  LLin *S;
  S = nullptr;
  double x;
  double resultt = 0;
  double op1, op2;
  bool t;
  bool p = false;
  while (!isEmpty(postfix)) {
    x = postfix->info;
    t = postfix->is_operat;
    pop(postfix);
    if (x > 0)push(S, x, t);
    else {
      if (!t)push(S, x, t);
      else {
        op1 = top_citeste_valoare(S);
        pop(S);
        op2 = top_citeste_valoare(S);
        pop(S);
        resultt = result(x, op2, op1);
        push(S, resultt, p);
      }
    }

  }

  return top_citeste_valoare(S);

}
void processRoInput(char *input, bool &success, double &result, Aliases *aliases, int dimension) {
  bool IfIsOp[200] = {};

  convertToLowerCase(input);
  bool corect = false;

  while (!corect) {

    int trad_inter[MAX_WORDS] = {};
    unsigned lung_inter = 0;

    if (strlen(input)!=0) {
      char *curent = strtok(input, " ?");
      while (curent) {

        if (doar_cifre(curent)) {

          if (atoi(curent) < 0) {

            trad_inter[lung_inter++] = -55;
            trad_inter[lung_inter++] = atoi(curent)*(-1);
            trad_inter[lung_inter++] = -8;
          } else {
            trad_inter[lung_inter++] = atoi(curent);
            trad_inter[lung_inter++] = -8;
          }
        } else {
          int t = getValue(aliases, dimension, curent);
          if (t!=-1 && !(t==-8 && (trad_inter[lung_inter - 1]==-77 || trad_inter[lung_inter - 1]==-66)))
            trad_inter[lung_inter++] = t;
        }
        curent = strtok(nullptr, " ");
      }

      if (lung_inter < 3) {

        corect = false;
      } else
        corect = validare(trad_inter, lung_inter);
    }
    if (corect) {
      if (trad_inter[lung_inter - 1]==-8)lung_inter--;

      double infixed[200];
      int longinfixed = 0;

      TransformAllInInfixed(trad_inter, IfIsOp, lung_inter, infixed, longinfixed);

      LLin *infix;
      infix = nullptr;
      LLin *postfix;
      postfix = nullptr;
      for (int i = 0; i < longinfixed; i++) {

        insereaza(infix, infixed[i], IfIsOp[i]);

      }

      TransformFromInfixToPostFix(infix, postfix);

      double finalresult = ValueOfPostfixed(postfix);
      result = finalresult;

    } else {
      success = false;
      break;
    }
  }

}
