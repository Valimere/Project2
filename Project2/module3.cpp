/*
* Stephen Drollinger
* CMSC330
* Project 2
* FileModule3.cpp
* Dev Enironment: Windows 7, Microsoft Visual Studio Express 2013 for Windows Desktop
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

#define inputFileName "input.txt"

SymbolTable symbolTable;

void parseAssignments();

int main()
{
	string input[10];
	fstream inputFile(inputFileName, ios::in);
	if (inputFile.is_open())
	{
		getline(inputFile, input[0], '$');
		cout << input[0] << endl;
		inputFile.close();
	}
	
	// test comment extended v3
    Expression* expression;
    char paren, comma;
    cout << "Enter expression: ";
    cin >> paren;
    expression = SubExpression::parse();
    cin >> comma;
    parseAssignments();
    cout << "Value = " << expression->evaluate() << endl;
	cin>>comma; // to wait for user input; allows the user to see what was printed before the window closes
    return 0;
}

void parseAssignments()
{
    char assignop, delimiter;
    string variable;
    double value;
    do
    {
        variable = parseName();
        cin >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
    }
    while (delimiter == ',');
}
