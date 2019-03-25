#ifndef LIBSTACK_H
#define LIBSTACK_H

#include <stack>
#include <fstream>

/*
Funkcja wypelniajaca elementami z pliku adapter stosu  
@param rFile wczytany plik z ktorego pobieramy elementy i zapisujemy do stosu
@param stack stos imitowany adapterem stosu
*/
void loadElementsFromFileToStack(std::fstream &rFile, std::stack <int> &stack);


#endif // !LIBSTACK_H

