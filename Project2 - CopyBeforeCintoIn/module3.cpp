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
#include <strstream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

#define inputFileName	"input.txt"
#define maximumLineSize	128

SymbolTable symbolTable;

void parseAssignments(strstream& in);

int main()
{
	Expression* expression;
	char paren, comma, line[maximumLineSize];

	// Opening file to be read.
	ifstream input(inputFileName);

	while (true) {
		input.getline(line, maximumLineSize); // Getting each line
		if (!input) // until there are no more lines.
			break;
		strstream in(line, maximumLineSize);

		cout << line << " "; // Displaying current line
		cout << "After current line" << endl;
		in >> paren; // removing parenthesis
		cout << "Step 2" << endl;

		symbolTable.initalize(); // Clears all data in our symbol table.  

		//cout << expression << endl;
		expression = SubExpression::parse(in);
		cout << "Step 3" << endl;
		in >> comma;
		if (comma != ';') // No variables in this one.
			if (comma == ',')  // Check to make sure we have a comma if we 
				parseAssignments(in);


		int result = expression->evaluate();
		cout << "Value = " << result << endl;
		cout << endl;
	}

	cin>>comma; // to wait for user input; allows the user to see what was printed before the window closes
	cin.get();
	return 0;

}


void parseAssignments(strstream& in)
{
    char assignop, delimiter;
    string variable;
    double value;
    do
    {
        variable = parseName(in);
        cin >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
    }
    while (delimiter == ',');
}