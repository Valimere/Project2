/*
* Stephen Drollinger
* CMSC330
* Project 2
* Dev Enironment: Windows 7, Microsoft Visual Studio Express 2013 for Windows Desktop
*/
class Equals : public SubExpression
{
public:
	Equals(Expression* left, Expression* right) :
		SubExpression(left, right)
	{
	}
	double evaluate()
	{
		if ((left->evaluate() - right->evaluate()) == 0)
			return 1;
		else
			return 0;
	}
};