/*
* Stephen Drollinger
* CMSC330
* Project 2
* Dev Enironment: Windows 7, Microsoft Visual Studio Express 2013 for Windows Desktop
*/
class Operand : public Expression
{
public:
	static Expression* parse(strstream& in);
};
