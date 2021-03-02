#include <stdio.h>

/* w c++ program nie odczytuje danych z pliku modul.c przy uzyciu komendy extern "zmienna" */
extern const double PI;
extern const double E;


int main()
{
  printf("  PI: %f\n",PI);
  printf("   E: %f\n",E);
  return 0;
}
