/*
* Stephen Drollinger
* CMSC330
* Project 2
* Dev Enironment: Windows 7, Microsoft Visual Studio Express 2013 for Windows Desktop
*/
#include <string> 
#include <vector> 
using namespace std;

#include "symboltable.h"


void SymbolTable::insert(string variable, double value)
{
    const Symbol& symbol = Symbol(variable, value);
    elements.push_back(symbol);
}

double SymbolTable::lookUp(string variable) const
{
    for (int i = 0; i < elements.size(); i++)
        if (elements[i].variable == variable)
             return elements[i].value;
    return -1;
}

void SymbolTable::initalize() {
	//elements.clear;
	for (int i = 0; i < elements.size()-1; i++)
		elements[i].value;
}


