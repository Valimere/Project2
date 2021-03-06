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

#define inputFileName	"tempInput.txt"
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
		in >> paren; // removing parenthesis
		cout << "Step 2" << endl;



		//cout << expression << endl;
		expression = SubExpression::parse(in);
		cout << "Step 3" << endl;
		in >> comma;
		if (comma != ';') // No variables in this one.
			if (comma == ',')  // Check to make sure we have a comma if we 
				parseAssignments(in);
			cout << "Value = "<< endl;
			cout << endl;

			cout << "Step 4" << endl;
		int result = expression->evaluate();
		cout << "Step 5" << endl;
		cout << "Value = " << result << endl;
		cout << endl;
		symbolTable.initalize(); // Clears all data in our symbol table.  
	}

	//in >>comma; // to wait for user input; allows the user to see what was printed before the window closes
	//in.get();
	// Keep window open until you press a key.
	cout << endl << "Press any key to quit";
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
        in >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
		if (assignop == '=')
			symbolTable.insert(variable, value);
    }
    while (delimiter == ',');
}