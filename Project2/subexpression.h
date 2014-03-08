/*
* Stephen Drollinger
* CMSC330
* Project 2
* Dev Enironment: Windows 7, Microsoft Visual Studio Express 2013 for Windows Desktop
*/
class SubExpression : public Expression
{
public:
    SubExpression(Expression* left, Expression* right);
    static Expression* parse();
protected: 
    Expression* left;
    Expression* right;
};
