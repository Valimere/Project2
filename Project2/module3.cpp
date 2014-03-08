#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

void parseAssignments();

int main()
{
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
