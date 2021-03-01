#include <iostream>
#include <cmath>

using namespace std;




struct TrojmianKw {
  double  a;
  double  b;
  double  c;
};




void WprowadzWspTrojmianu( TrojmianKw *wTKw )
{
  cout << "Podaj wspolczynnik a:\n";
  cin >> wTKw->a;
  /*
   * Tu uzupelnij
   */
}


void WyswietlTrojmian( TrojmianKw TKw )
{
  /*
   * Tu uzupelnij
   */
}


/*!
 * Oblicza delte oraz wartosci pierwiastkow. Wartosci wyliczonych
 * pierwiastkow podstawiane sa do zmiennych odstepnych poprzez
 * wskazniki wX1 oraz wX2.
 * Interpretacja wynikow zalezy od zwroconej wartosci calkowitej
 * i jest ona nastepujaca:
 *  2 - wyznaczono dwa pierwiastki rzeczywiste, kolejne pierwiastki
 *      wpisane sa do zmiennych dostenych poprzez wskazniki wX1 i wX2.
 *  1 - rownanie ma tylko jeden pierwiastek rzeczywisty, wynik 
 *      zostaje wpisany do zmiennej przekazanej poprzez wskaznik wX1.
 *  0 - brak rozwiazan w zbirze liczb rzeczywistych.
 */
int WyliczPierwiastki(TrojmianKw   TKw, double *wX1, double *wX2)
{
  double   Delta, Delta_2;

  Delta_2  = (TKw.b*TKw.b) - (4.0*TKw.a*TKw.c);

  if (Delta_2 > 0) {

      Delta = sqrt( Delta_2 );
      *wX1 = (-TKw.b - Delta) / (2*TKw.a);
      /*
       * Tu uzupelnic
       */

  } else if  (Delta_2 == 0) {

      *wX1 = -TKw.b/(2*TKw.a);
      return 1;

  }
  /* czyli d <= 0 */
  return 0;
}




int main() {
  TrojmianKw   TKw;
  double       X1, X2;
  

  cout << "Program wylicza rozwiazania trojmianu kwadratowego.\n";  

  WprowadzWspTrojmianu(&TKw);

  if (TKw.a == 0) {
    /*
     * Tu uzupelnic
     */
    return 1;
  }

  WyswietlTrojmian(TKw);
  
  switch (WyliczPierwiastki(TKw,&X1,&X2)) {
    case 2:
      cout << "Istnieja dwa rozwiazania rzeczywiste:\n";
      cout << "  x1 = " << X1 << endl;
      /*
       * Tu uzupelnic
       */
      break;

    case 1:
      /*
       * Tu uzupelnic
       */
      break;

    case 0:
      /*
       * Tu uzupelnic
       */
      break;
  }

  return 0;
}

