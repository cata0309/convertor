#include <cstring>
#include <fstream>
#include <iostream>
std::ifstream dict("dictionar.in");
// DIM_MAX este dimensiunea maxima a inputului ce poate fi luat de la tastatura
#define DIM_MAX 2000
// DIM_DIC este dimensiunea maxima a mini dictionarului trad
#define DIM_DIC 60
// MAX_CHEIE este dimensiunea maxima a unui sir de caractere ce contine o
// definitie in litere
#define MAX_CHEIE 15

struct LLin {
  int info;
  LLin *urm;
};

bool esteVida(LLin*);
void push(LLin*&,int);
int top(LLin*);
void pop(LLin*&);
// structura are rolul de a retine legaturile dintre numerele scrise cu ajutorul
// literelor si numerele scrise cu ajutorul cifrelor campul cheie contine
// reprezentarea in litere a numarului in cauza campul valoare contine
// reprezentarea in baza 10 a numarului in cauza
struct {
  char cheie[MAX_CHEIE];
  int valoare;
} trad[DIM_DIC];
// vectorul trad are rolul unui mic dictionar cu definitii in litere legate de
// definitii in numere variabila lung este folosita pentru initializarea
// vectorului de traduceri si in cautarea in acesta
unsigned lung;
// functia insereaza(.., ..) are rolul de a insera o noua intrare in mini
// dictionarul trad
void adauga_intrare(char *alias_car, int alias_int) {
  strcpy(trad[lung].cheie, alias_car);
  trad[lung++].valoare = alias_int;
}
// functia init_trad() are rolul de a initializa dictionarul la fiecare rulare
// pentru a nu fi hard-coded si, desigur, pentru a putea fi facute modificari
// mai usor la dictionar
void init_trad();
// functia doar_cifre(..) are rolul de a verifica daca un anumit sir de
// caractere contine numai cifre in acest caz acesta poate fi convertit direct
// in numere
bool doar_cifre(char *sir);
// functia cautare(..) are rolul de a cauta in mini dictionarul trad dupa
// reprezentarea in litere si de a returna valoarea intreaga legata daca exista
// sau -1 in caz contrar
int cautare(char*sir);
// cautare_urmatorul_si(.., .., ..) are rolul de a cauta urmatoarea aparitie a
// lui si pentru a putea preveni bug-urile de tipul suma dintre saptezeci si
// patru <- sa nu se transforme direct in 74 pentru ca atunci nu ar mai exista
// un al doilea operand
bool cautare_urmatorul_si(int *,int,int);
bool operand(int);
int rezultat(int,int,int);
void calculare(bool&,int&,int*,int);
int main() {
  if (!dict.is_open()) {
    std::cerr << "Nu a putut fi deschis fisierul cu definitii!";
    std::exit(1);
  }
  init_trad();
  char input[DIM_MAX] = {};
  int trad_inter[DIM_MAX] = {};
  unsigned lung_inter = 0;
  std::cin.getline(input, DIM_MAX);
  if (strlen(input) != 0) {
    char *curent = strtok(input, " ,?");
    if (doar_cifre(curent)) {
      trad_inter[lung_inter++] = atoi(curent);
    } else {
      int t = cautare(curent);
      if (t != -1)
        trad_inter[lung_inter++] = t;
    }
    curent = strtok(nullptr, " ,?");
  }
bool intrare_valida=true;
int rezultat_final=0;
int traduceri_finale[DIM_MAX]={};
int lung_final=3;
traduceri_finale[0]=-4;
traduceri_finale[1]=0;
traduceri_finale[2]=6;
calculare(intrare_valida,rezultat_final,traduceri_finale,lung_final);
 if (intrare_valida) {
    std::cout << "Notatia postfixata in reverse este corect scrisa si rezultatul final este "
         << rezultat_final;
  } else {
    std::cout << "Intrarea este incorecta ! Greseala";
  }
  return 0;
}
void calculare(bool&intrare_valida,int&rezultat_final,int*traduceri_finale,int lung_final){
   LLin *postfix = nullptr;
 for (int i = 0; i < lung_final; ++i)
    push(postfix, traduceri_finale[i]);
 LLin *stiva_operatii = nullptr;
  while (!esteVida(postfix) && intrare_valida) {
    int x = top(postfix);
    pop(postfix);
    if (operand(x)) {
      push(stiva_operatii, x);
    } else {
      if (esteVida(stiva_operatii))
       { intrare_valida = false;
        return;}
      int drp = top(stiva_operatii);
      pop(stiva_operatii);
      if (esteVida(stiva_operatii))
        {intrare_valida = false;
          return;}
      int stg = top(stiva_operatii);
      pop(stiva_operatii);

      if (x == -7 && drp == 0)
        {intrare_valida = false;
          return;}
      if (intrare_valida) {
        int val = rezultat(stg, x, drp);
        push(stiva_operatii, val);
      }
    }
  }
 if (!intrare_valida) {return;}
  int valoare_finala = top(stiva_operatii);
  pop(stiva_operatii);
  if (!esteVida(stiva_operatii))
   {  intrare_valida = false;
    return;}
  rezultat_final=valoare_finala;
}
bool esteVida(LLin *stiva_coada) { return (stiva_coada == nullptr); }
void push(LLin *&stiva, int element) {
  LLin *deInserat = new (LLin);
  deInserat->info = element;
  deInserat->urm = stiva;
  stiva = deInserat;
}
int top(LLin *stiva) {
  if (stiva == nullptr)
    return -10;
  return stiva->info;
}
void pop(LLin *&stiva) {
  LLin *deSters = stiva;
  stiva = stiva->urm;
  delete (deSters);
}
bool operand(int op) { return (op >= 0); }
int rezultat(int st, int op, int dr) {
  switch (op) {
  case -4:
    return (st + dr);
    break;
  case -5:
    return (st - dr);
    break;
  case -6:
    return (st * dr);
  default:
    return (st / dr);
    break;
  }
}
bool cautare_urmatorul_si(int *a, int lungime, int index_curent) {
  for (int i = index_curent + 1; i < lungime; ++i)
    if (a[i] == -2)
      return true;
  return false;
}
int cautare(char *sir) {
  for (int i = 0; i < lung; ++i)
    if (strcmp(sir, trad[i].cheie) == 0)
      return trad[i].valoare;
  return -1;
}
bool doar_cifre(char *sir) {
  for (size_t i = 0; i < strlen(sir); ++i)
    if (!(sir[i] >= '0' && sir[i] <= '9'))
      return false;
  return true;
}
void init_trad() {
  // primele 37 de intrari operanzi
  // urmatoarele 2 intrari cuvinte de legatura
  // urmatoarele 13 intrari operatii:
  // primele 4 adunare
  // urmatoarele 4 scadere
  // urmatoarele 4 inmultire
  // urmatoarele 2 impartire
  char sir[MAX_CHEIE];
  int valoare;
  while (dict >> sir && dict >> valoare) {
    adauga_intrare(sir, valoare);
  }
}