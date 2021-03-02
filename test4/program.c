#include <stdio.h>

/* w c++ funkcja Wynik nie jest poprawna poniewaz Dodaj odnosi sie do wiecej niz jednej zmiennej co powoduje blad */
double Dodaj();


int main( )
{
  double  Skl1 = 2.0,  Skl2 = 2.0;
  double  Wynik = Dodaj(Skl1,Skl2);

  printf("  Wynik dodawania:  %f + %f = %f\n",Skl1,Skl2,Wynik);

  return 0;
}
