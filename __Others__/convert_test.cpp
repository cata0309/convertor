#include<iostream>
#include<cstring>
using namespace std;


void convertIToC(int nr,char*c) {
  char sir[4];
  int lung = 0;

  do {
    sir[lung++] = char(48+nr%10);
    nr /= 10;
  } while (nr!=0);


  sir[lung] = '\0';

  for (size_t i = 0; sir[i]; ++i) {
    c[strlen(sir) - 1 - i] = sir[i];
  }
  c[strlen(sir)] = '\0';
}
int main(){
int n;
cin>>n;
char t[4];
convertIToC(n,t);
cout<<t;
  return 0;
}