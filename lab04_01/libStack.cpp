#include "pch.h"
#include "libStack.h"
using namespace std;

void loadElementsFromFileToStack(std::fstream &rFile, std::stack<int> &stack)
{
	int begSize;
	rFile >> begSize;
	int tmp;

	for (int i = 0; i < begSize; i++)
	{
		rFile >> tmp;
		stack.push(tmp);
	}
}
