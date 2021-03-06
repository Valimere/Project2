/*
* Stephen Drollinger
* CMSC330
* Project 2
* Dev Enironment: Windows 7, Microsoft Visual Studio Express 2013 for Windows Desktop
*/
#include <iostream>
#include <strstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "greaterthan.h"
#include "lessthan.h"
#include "equals.h"
#include "and.h"
#include "or.h"
#include "not.h"

SubExpression::SubExpression(Expression* left, Expression* right)
{
    this->left = left;
    this->right = right;
}

Expression* SubExpression::parse(strstream& in)
{
    Expression* left;
    Expression* right;
    char operation, paren;
    
	cout << "Step 2.2" << endl;
    left = Operand::parse(in);
    in >> operation;
    right = Operand::parse(in);
    in >> paren;
	cout << "Step 2.3" << endl;
    switch (operation)
    {
        case '+':
            return new Plus(left, right);
        case '-':
            return new Minus(left, right);
        case '*':
            return new Times(left, right);
        case '/':
            return new Divide(left, right);
		case '<':
			return new Lessthan(left, right);
		case '>':
			return new Greaterthan(left, right);
		case '=':
			return new Equals(left, right);
		case '&':
			return new And(left, right);
		case '|':
			return new Or(left, right);
		case '!':
			return new Or(left, right);
		//default: //If above not selected throw error
			//throw exception("Error: Syntax Error");
    }
    return 0;
}
