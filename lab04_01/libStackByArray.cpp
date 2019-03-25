#include "pch.h"
#include "libTables.h"
#include "libStackByArray.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

void loadCorrectFileName(char *fileName)
{
	cout << "Podaj nazwe pliku do odczytu z rozszerzeniem .txt  ";
	cin >> fileName;
	int nameLength = strlen(fileName);
	bool flag = false;

	for (int i = 1; i <= 3; i++)
	{
		if (i == 3) {
			cout << "Przekroczono limit prob wprowadzenia wlasciwej nazwy.";
			cin.ignore();
			exit(0);
		}

		for (int j = 0; j < nameLength; j++)
		{
			if (j <= nameLength - 4 && fileName[j] == '.' && fileName[j + 1] == 't' && fileName[j + 2] == 'x' && fileName[j + 3] == 't') {
				flag = true;
				break;
			}
		}

		if (flag)
			break;
		else {
			cout << "Bledna nazwa pliku! Podaj nazwe z rozszerzeniem .txt!" << endl;
			cin >> fileName;
			nameLength = strlen(fileName);
		}
	}
}

fstream createReadFile()
{
	char fileName[50];
	loadCorrectFileName(fileName);
	bool flag = false;

	while (!flag) {

		fstream rFile(fileName, ios::in);

		if (rFile) {
			flag = true;
			cout << "Poprawnie wczytano plik...";
			Sleep(1500);
			return rFile;
		}
		else {
			cout << "Nie ma pliku z taka nazwa, sprobuj ponownie!" << endl;
			loadCorrectFileName(fileName);
		}
	}
}

void showStack(int * tab, int amountOfElem)
{
	system("cls");
	cout << "--------------------------------\n"
		"Zawartosc stosu:\n"
		"--------------------------------\n";

	for (int i = amountOfElem; i >= 1; i--) {
		cout << tab[i] << endl;
	}

	if (amountOfElem == 0)
		cout << "Stos jest pusty!" << endl;

	cout << "--------------------------------\n\n";
}

void Tpush(int *tab, int Tsize, int &amountOfElem) {

	if (amountOfElem >= (Tsize - 1)) {
		cout << "Stos jest pelny, musisz cos zdjac ze stosu!" << endl;
		Sleep(2000);
	}
	else {
		++amountOfElem;
		cout << "Podaj element do polozenia na gorze stosu: ";
		cin >> tab[amountOfElem];
	}
}

void Tpop(int * tab, int &amountOfElem)
{
	if (amountOfElem >= 1) {
		cout << "Nastapi zdjecie ze stosu liczby " << tab[amountOfElem] << endl;
		--amountOfElem;
		Sleep(2000);
	}
	else
	{
		cout << "Stos jest pusty!" << endl;
		Sleep(2000);
	}
}

void Tsize(int amountOfElem) {
	cout << "W tej chwilii jest na stosie " << amountOfElem << " elementow." << endl;
	Sleep(2000);
}

void Tempty(int amountOfElem)
{
	if (amountOfElem == 0)
	{
		cout << "Stos jest pusty!" << endl;
		Sleep(2000);
	}
	else {
		cout << "Stos nie jest pusty!" << endl;
		Sleep(2000);
	}
}

void Ttop(int * tab, int amountOfElem)
{
	if (amountOfElem != 0) {
		cout << "Na gorze stosu jest liczba " << tab[amountOfElem] << endl;
		Sleep(2000);
	}
	else
	{
		cout << "Brak elementow na stosie!";
		Sleep(2000);
	}
}

int* loadElementsFromFileToTable(std::fstream &rFile, int &Tsize)
{
	rFile >> Tsize;
	Tsize++;

	int *tab = createTable(Tsize);
	tab[0] = 0;

	for (int i = 1; i < Tsize; i++) {
		rFile >> tab[i];
	}

	return tab;
}


