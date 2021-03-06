// Podwika_Grzegorz_Program_01 : Poniedzialek 11:00
//

#include "pch.h"
#include "libStackByArray.h"
#include "libStack.h"
#include "libStackByList.h"
#include <iostream>
#include <Windows.h>
#include <stack>

using namespace std;

void showMainMenu();				//funkcja pomocnicza wyswietlajaca glowne menu programu
void showStackMenu();				//funkcja pomocnicza wyswietlajaca menu stosu

void showTableStack();				//funkcja obslugujaca tablice imitujaca stos
void showAdapterStack();			//funkcja obslugujaca adapter stosu
void showListStack();				//funkcja obslugujaca liste imitujaca stos

int main()
{
	int mainChoise{};
	showMainMenu();
	cin >> mainChoise;
	
	switch (mainChoise)
	{
	case 1: {
		showTableStack();
	}
		break;

	case 2: {
		showAdapterStack();
	}
		break;

	case 3: {
		showListStack();
	}
		break;

	case 4: {
		exit(0);
	}
		break;

	default: {
		cout << "Nie ma takiej opcji, nastapi zamkniecie programu!";
		Sleep(2000);
	}
		break;
	}


	cin.ignore();
	return 0;
}

void showMainMenu()
{
	cout << "MENU GLOWNE\n"
		"1. Stos tablicowy\n"
		"2. Stos za pomoca adaptera stosu std::stack\n"
		"3. Stos za pomoca listy jednokierunkowej\n"
		"4. Wyjscie z programu\n"
		"Ktora opcje wybierasz?  ";
}

void showStackMenu() {
	cout << "MENU\n"
		"1. push\n"
		"2. pop\n"
		"3. size\n"
		"4. empty\n"
		"5. top\n"
		"6. Koniec pracy\n"
		"Ktora opcje wybierasz?  ";
}

void showTableStack()
{
	fstream file = createReadFile();							//odczyt pliku z dysku wraz z obsluga bledu

	int stackSize{};
	int *tab = loadElementsFromFileToTable(file, stackSize);
	int amountOfElem = stackSize - 1;
	file.close();

	int choice{};

	while (choice != 6)
	{
		showStack(tab, amountOfElem);							//funkcja pokazujaca wszystkie elementy stosu w danej chwili
		showStackMenu();
		cin >> choice;

		switch (choice)
		{
		case 1:
			Tpush(tab, stackSize, amountOfElem);
			break;
		case 2:
			Tpop(tab, amountOfElem);
			break;
		case 3:
			Tsize(amountOfElem);
			break;
		case 4:
			Tempty(amountOfElem);
			break;
		case 5:
			Ttop(tab, amountOfElem);
			break;
		case 6: {
			delete[] tab;
			exit(0);
		}
			break;
		default: {
			cout << "Nie ma takiej opcji!";
			Sleep(2000);
		}
			break;
		}
	}
}

void showAdapterStack()
{
	fstream rFile = createReadFile();							//odczyt pliku z dysku wraz z obsluga bledu		
	stack <int> userStack;										//utworzenie stopsu za pomoca adaptera stosu
	
	loadElementsFromFileToStack(rFile, userStack);
	rFile.close();

	int choice{};

	while (choice != 6)
	{
		Sleep(2000);
		system("cls");

		showStackMenu();
		cin >> choice;

		switch (choice)
		{
		case 1: {
			int tmpNumber{};
			cout << "Podaj liczbe, ktora chcesz umiescic na gorze stosu:  ";
			cin >> tmpNumber;
			userStack.push(tmpNumber);
		}
			break;

		case 2: {
			if (userStack.empty() != true) {
				cout << "Z wierzcholka stosu usuwamy liczbe " << userStack.top() << endl;
				userStack.pop();
			}
			else
			{
				cout << "Stos jest pusty!" << endl;
			}
		}
			break;

		case 3: {
			cout << "W tej chwilii jest na stosie " << userStack.size() << " elementow." << endl ;
		}
			break;

		case 4: {
			if (userStack.empty())
			{
				cout << "Stos jest pusty!" << endl;
			} else
				cout << "Stos nie jest pusty!" << endl;
		}
			break;

		case 5: {
			if (userStack.empty() == false) {
				int tmp = userStack.top();
				cout << "Na gorze stosu jest liczba " << tmp << endl;
			}
			else
			{
				cout << "Stos jest pusty!" << endl;
			}
		}
			break;

		case 6: {
			exit(0);
		}
				break;

		default: {
			cout << "Nie ma takiej opcji!" << endl;
		}
				 break;
		}
	}
}

void showListStack()
{
	int amountOfElem{};
	fstream rFile = createReadFile();
	StackElement *head = loadElementsFromFileToList(rFile, amountOfElem);
	rFile.close();

	int choice{};

	while (choice != 6)
	{
		Sleep(2000);
		system("cls");

		showStackMenu();
		cin >> choice;

		switch (choice)
		{
		case 1: {
			Lpush(&head, amountOfElem);
		}
				break;

		case 2: {
			if (head != nullptr) {
				cout << "Z wierzcholka stosu usuwamy liczbe " << head ->number << endl;
				Lpop(&head, amountOfElem);
			}
			else
			{
				cout << "Stos jest pusty!" << endl;
			}
		}
				break;

		case 3: {
			cout << "W tej chwilii jest na stosie " << amountOfElem << " elementow." << endl;
		}
				break;

		case 4: {
			if (head == nullptr)
			{
				cout << "Stos jest pusty!" << endl;
			}
			else
				cout << "Stos nie jest pusty!" << endl;
		}
				break;

		case 5: {
			if (head != nullptr) {
				cout << "Na gorze stosu jest liczba " << head ->number << endl;
			}
			else
			{
				cout << "Stos jest pusty!" << endl;
			}
		}
				break;

		case 6: {
			exit(0);
		}
				break;

		default: {
			cout << "Nie ma takiej opcji!" << endl;
		}
				 break;
		}
	}
}
