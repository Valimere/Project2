/*
* Stephen Drollinger
* CMSC330
* Project 2
* Dev Enironment: Windows 7, Microsoft Visual Studio Express 2013 for Windows Desktop
*/
class Divide : public SubExpression
{
public:
    Divide(Expression* left, Expression* right):
        SubExpression(left, right)
	{
    }
    double evaluate()
    {
		if (right->evaluate() != 0)
			return left->evaluate() / right->evaluate();
		else
			throw exception("Error: Cannot Divide by zero");
    }
};