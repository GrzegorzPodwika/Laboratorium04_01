#include "pch.h"
#include "libStackByList.h"
using namespace std;

StackElement* loadElementsFromFileToList(fstream &rFile, int &amountOfElem)
{
	rFile >> amountOfElem;

	StackElement *head = nullptr;
	StackElement *nElem = nullptr;

	for (int i = 0; i < amountOfElem; i++)
	{
		nElem = new StackElement;
		rFile >> nElem->number;
		nElem->next = head;
		head = nElem;
	}

	return head;
}

void Lpush(StackElement **head, int & amountOfElem)
{
	StackElement *nElem = new StackElement;
	
	cout << "Podaj element do polozenia na gorze stosu: ";
	cin >> nElem->number;
	nElem->next = (*head);
	(*head) = nElem;
	++amountOfElem;
}

void Lpop(StackElement **head, int & amountOfElem)
{
	if (amountOfElem != 0)
	{
		StackElement *tmp = (*head);
		(*head) = tmp->next;
		tmp->next = nullptr;
		--amountOfElem;
	}
	else 
	{
		cout << "Lista jest pusta!" << endl;
	}
}

