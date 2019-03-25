#ifndef LIBSTACKBYLIST_H
#define LIBSTACKBYLIST_H

#include <fstream>
#include <iostream>

/*
Struktura imitujaca element stosu za pomoca listy jednokierunkowej
*/
struct StackElement
{
	int number;
	StackElement *next;
};

/*
Funkcja wypelniajaca elementami z wczytanego pliku do listy
@param rFile wczytany plik z ktorego pobieramy elementy i zapisujemy do listy
@param amountOfElem liczba wczytanych elementow z pliku
@return liste imitujaca stos z zaladowanymi elementami z pliku
*/
StackElement* loadElementsFromFileToList(std::fstream &rFile, int &amountOfElem);

/*
Funkcja dodajaca liczbe na stos, pod warunkiem, ze nie jest pelny
@param head glowa listy, adres wskaznika glowy listy
@param amountOfElem liczba elementow w liscie w danym momencie
*/
void Lpush(StackElement **head, int &amountOfElem);

/*
Funkcja zdejmujaca liczbe ze stosu, pod warunkiem, ze nie jest pusty
@param head glowa listy, adres wskaznika glowy listy
@param amountOfElem liczba elementow w liscie w danym momencie
*/
void Lpop(StackElement **head, int &amountOfElem);




#endif // !LIBSTACKBYLIST_H

