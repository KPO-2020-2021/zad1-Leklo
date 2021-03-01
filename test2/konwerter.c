#include <stdio.h>
#include <malloc.h>
#include <string.h>



char Zamien( int KodZnaku, int *TabKodow, char *TabZnakow, int Rozmiar)
{
  int i;

  for (i = 0;  i < Rozmiar; ++i) 
    if (KodZnaku == TabKodow[i]) return TabZnakow[i];

  return KodZnaku;
}


void KonwertujNapis( char *Napis, int *TabKodow, char *TabZnakow, int Rozmiar)
{
  unsigned int i;
 
  for (i = 0;  i < strlen(Napis); ++i)
    Napis[i] = Zamien(Napis[i],TabKodow,TabZnakow,Rozmiar);
}


int main()
{
  int  IloscKodow = 10;
  int  Rozmiar = IloscKodow * sizeof('¶');

  int  *TabKodow = (int*)malloc(Rozmiar);
  char *TabZnakow = (char*)malloc(IloscKodow*sizeof(char)); 
  char *Napis = strdup("Cze¶æ ¦wiecie!!! ¯yczê mi³ego dnia.");

  TabKodow[0] = 'æ';     TabZnakow[0] = 'c';
  TabKodow[1] = 'ê';     TabZnakow[1] = 'e';
  TabKodow[2] = '³';     TabZnakow[2] = 'l';
  TabKodow[3] = '¶';     TabZnakow[3] = 's';
  TabKodow[4] = '¦';     TabZnakow[4] = 'S';
  TabKodow[5] = '¯';     TabZnakow[5] = 'Z';
  TabKodow[6] = '¯';     TabZnakow[6] = 'Z';
  TabKodow[7] = '¯';     TabZnakow[7] = 'Z';
  TabKodow[8] = '¯';     TabZnakow[8] = 'Z';
  TabKodow[9] = '¯';     TabZnakow[9] = 'Z';    
  
  printf("Napis Latin2:  \"%s\"\n",Napis);

  KonwertujNapis(Napis,TabKodow,TabZnakow,IloscKodow);

  printf("Napis ASCII:   \"%s\"\n",Napis);

  return 0;
}
