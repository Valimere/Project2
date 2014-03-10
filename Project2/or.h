/*
* Stephen Drollinger
* CMSC330
* Project 2
* Dev Enironment: Windows 7, Microsoft Visual Studio Express 2013 for Windows Desktop
*/
class Or : public SubExpression
{
public:
	Or(Expression* left, Expression* right) :
		SubExpression(left, right)
	{
	}
	double evaluate()
	{
		if ((left->evaluate() || right->evaluate()))
			return 1;
		else
			return 0;
	}
};