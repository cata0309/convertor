#include <iostream>
#include<fstream>
using namespace std;
ifstream fin("possible.txt");
ofstream fout("results.txt");
struct LLin {
  int info;
  LLin *urm;
};
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
bool pop(LLin *&stiva) {
  if (stiva == nullptr) {
    return false;
  }
  LLin *deSters = stiva;
  stiva = stiva->urm;
  delete (deSters);
  return true;
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

int main() {

   int numarare=0;
   int n;
  while(fin>>n){
  	fout<<"PENTRU INPUT NR: "<<numarare<<": ";
  	numarare++;
  	LLin *postfix = nullptr;
  int v[100];
  for (int i = 0; i < n; ++i)
    {fin >> v[i];
    push(postfix, v[i]);}
  bool intrare_valida = true;

  LLin *stiva_operatii = nullptr;

  while (!esteVida(postfix) && intrare_valida) {

    int x = top(postfix);
    pop(postfix);

    if (operand(x)) {
      push(stiva_operatii, x);
    } else {
      if (esteVida(stiva_operatii))
        intrare_valida = false,cout<<"1";
      int drp = top(stiva_operatii);
      pop(stiva_operatii);
      if (esteVida(stiva_operatii))
        intrare_valida = false,cout<<"2";
      int stg = top(stiva_operatii);
      pop(stiva_operatii);

      if (x == -7 && drp == 0)
        intrare_valida = false,cout<<"3";
      if (intrare_valida) {
        int val = rezultat(stg, x, drp);
        push(stiva_operatii, val);
      }
    }
  }

  int valoare_finala = top(stiva_operatii);
  pop(stiva_operatii);
  if (!esteVida(stiva_operatii))
    intrare_valida = false,cout<<"4";

  if (intrare_valida) {
    fout << "Notatia postfixata in reverse este corect scrisa si rezultatul "
            "final este"
         << valoare_finala;
  } else {
    fout << "Intrarea este incorecta ! Greseala";
  }
fout<<"\n";
}
  return 0;
}