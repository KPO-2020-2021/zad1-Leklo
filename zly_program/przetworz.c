#include <stdio.h>
#include <ctype.h>



/*
 *  Liczy ilosc wystapien znaku "spacja"
 *
 *  Warunki wstepne:
 *   Wskaznik 'Tekst' nie moze miec wartosc NULL i musi byc
 *   poprawnym (zakonczonym znakiem 0) tekstem. 
 *
 *  Parametry:
 *    Tekst - wskaznik na tekst, dla ktorego ma byc wyznaczona
 *            ilosc spacji.
 */
int PoliczSpacje(char* Tekst)
{
  int Ilosc = 0;
  
  for (; *Tekst; ++Tekst)
      if (*Tekst == ' ') ++Ilosc;
  return Ilosc;
}


/*
 * Wyznacza dlugosc najdluzszego slowa w tekscie.
 *
 *  Warunki wstepne:
 *   Wskaznik 'Tekst' nie moze miec wartosc NULL i musi byc
 *   poprawnym (zakonczonym znakiem 0) tekstem. 
 *
 *  Parametry:
 *    Tekst - wskaznik na tekst, dla ktorego ma byc wyznaczona
 *            dlugosc najdluzszego slowa, ktore w nim sie znajduje.
 */
int RozmiarNajdluzszegoSlowa(char* Tekst)
{
  int DlugoscMaks = 0, DlugoscRob;
  char *Slowo = NULL;

  for (; *Tekst; ++Tekst) {
    if (isspace(*Tekst)) {
      if (!Slowo) continue;
      DlugoscRob = Tekst - Slowo;
      if (DlugoscMaks < DlugoscRob) DlugoscMaks = DlugoscRob;
      Slowo = 0L;
      continue;
    }
    if (!Slowo) Slowo = Tekst;
  }
  return DlugoscMaks;
}



/*
 * Zamienia wszystkie spacje znajdujace sie w tekscie na znak podkreslenia.
 *
 *  Warunki wstepne:
 *   Wskaznik 'Tekst' nie moze miec wartosc NULL i musi byc
 *   poprawnym (zakonczonym znakiem 0) oraz modyfikowalnym tekstem.
 *
 *  Parametry:
 *    Tekst - wskaznik na tekst, dla ktorego ma byc wyznaczona
 *            dlugosc najdluzszego slowa, ktore w nim sie znajduje.
 */
void ZamienNaPodkreslenie(char* Tekst)
{
  for (; *Tekst; ++Tekst)
      if (*Tekst == ' ') *Tekst = '_';
}



/*
 * Oblicza ilosc wystapien malych liter.
 *
 *  Warunki wstepne:
 *   Wskaznik 'Tekst' nie moze miec wartosc NULL i musi byc
 *   poprawnym (zakonczonym znakiem 0) oraz modyfikowalnym tekstem.
 *
 *  Parametry:
 *    Tekst - wskaznik na tekst, dla ktorego ma byc wyznaczona
 *            dlugosc najdluzszego slowa, ktore w nim sie znajduje.
 *
 *  Wartosc zwracana:
 *    Ilosc malych liter.
 */
int IloscMalychLiter(char *Tekst)
{
  int Ilosc = 0;
  
  for (; *Tekst; ++Tekst)
      if (islower(*Tekst)) ++Ilosc;
  return Ilosc;
}


/*
 * Oblicza ilosc wystapien wielkich liter.
 *
 *  Warunki wstepne:
 *   Wskaznik 'Tekst' nie moze miec wartosc NULL i musi byc
 *   poprawnym (zakonczonym znakiem 0) oraz modyfikowalnym tekstem.
 *
 *  Parametry:
 *    Tekst - wskaznik na tekst, dla ktorego ma byc wyznaczona
 *            dlugosc najdluzszego slowa, ktore w nim sie znajduje.
 *
 *  Wartosc zwracana:
 *    Ilosc wielkich liter.
 */
int IloscWielkichLiter(char *Tekst)
{
  int Ilosc = 0;
  
  for (; *Tekst; ++Tekst)
      if (isupper(*Tekst)) ++Ilosc;
  return Ilosc;
}



int main()
{
  char *Napis = "Jak dobrze jest wstac skoro swit. Jutrzenki blask ...";
  int IloscSpacji;
  int DlugoscSlowaXXX;
  int IloscMaLiter = 0;
  int IloscWiLiter = 0;

  printf("\n------------------------------\n");
  printf(" Statystyka dla tekstu: '%s'\n\n",Napis);



  IloscSpacji = PoliczSpacje(Napis);
  DlugoscSlowaXXX = RozmiarNajdluzszegoSlowa(Napis);
  ZamienNaPodkreslenie(Napis);
  IloscMaLiter = IloscMalychLiter(Napis);
  IloscWiLiter = IloscWielkichLiter(Napis);

  printf("               Ilosc spacji: %i\n",IloscSpacji);
  printf("         Ilosc malych liter: %i\n",IloscMaLiter);
  printf("       Ilosc wielkich liter: %i\n",IloscWiLiter);
  printf(" Rozmiar najdluzszego slowa: %i\n",DlugoscSlowaXXX);
  printf(" Tekst z podkresleniami: '%s'\n",Napis);
  printf("\n");
  return 0;
}
