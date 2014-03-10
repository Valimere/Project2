/*
* Stephen Drollinger
* CMSC330
* Project 2
* Dev Enironment: Windows 7, Microsoft Visual Studio Express 2013 for Windows Desktop
*/
class Variable : public Operand
{
public:
    Variable(string name)
    {
        this->name = name;
    }
    double Variable::evaluate();
private:
    string name;
};
