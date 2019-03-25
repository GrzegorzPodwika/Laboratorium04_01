#ifndef LIBSTACKBYARRAY_H
#define LIBSTACKBYARRAY_H

#include <fstream>

/*
Funkcja pomocnicza wczytujaca poprawna nazwe pliku
@param fileName nazwa pliku do wczytania
*/
void loadCorrectFileName(char *fileName);

/*
Funkcja tworzaca strumien do wczytywania wlasciwego pliku
@return wczytany plik z dysku
*/
std::fstream createReadFile();

/*
Funkcja pokazujaca aktualny stan stosu
@param tab tablica imitujaca stos
@param amountOfElem ilosc elementow na stosie w danej chwili
*/
void showStack(int *tab, int amountOfElem);

/*
Funkcja dodajaca liczbe na stos, pod warunkiem, ze nie jest pelny
@param tab tablica imitujaca stos
@param Tsize rozmiar stosu
@param amountOfElem ilosc elementow na stosie w danej chwili
*/
void Tpush(int *tab, int Tsize, int &amountOfElem);

/*
Funkcja zdejmujaca liczbe ze stosu, pod warunkiem, ze nie jest pusty
@param tab tablica imitujaca stos
@param amountOfElem ilosc elementow na stosie w danej chwili
*/
void Tpop(int *tab, int &amountOfElem);

/*
Funkcja pokazujaca ile jest w danym momencie wartosci na stosie
@param amountOfElem liczba elementow
*/
void Tsize(int amountOfElem);

/*
Funkcja pokazujaca czy stos jest pusty
@param amountOfElem liczba elementow
*/
void Tempty(int amountOfElem);

/*
Funkcja pokazujaca wartosc szczytowego elementu na stosie
@param tab tablica imitujaca stos
@param amountOfElem liczba elementow
*/
void Ttop(int *tab, int amountOfElem);

/*
Funkcja zapelniajaca tablice elementami z pliku
@param rFile wczytywany plik
@param Tsize rozmiar tablicy dynamicznej
@return tablice dynamiczna jednowymiarowa zapelniona wartosciami
*/
int* loadElementsFromFileToTable(std::fstream &rFile, int &Tsize);

#endif // LIBSTACKBYARRAY_H
