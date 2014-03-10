/*
* Stephen Drollinger
* CMSC330
* Project 2
* Dev Enironment: Windows 7, Microsoft Visual Studio Express 2013 for Windows Desktop
*/
#include <cctype>
#include <iostream>
#include <list>
#include <string>
#include <strstream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h"
#include "parse.h"

Expression* Operand::parse(strstream& in)
{
    char paren;
    double value;

    cin >> ws;
    if (isdigit(cin.peek()))
    {
        cin >> value;
        Expression* literal = new Literal(value);
        return literal;
    }
    if (cin.peek() == '(')
    {
        cin >> paren;
        return SubExpression::parse(in);
    }
    else
        return new Variable(parseName(in));
    return 0;
}
