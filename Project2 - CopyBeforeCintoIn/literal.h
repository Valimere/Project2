/*
* Stephen Drollinger
* CMSC330
* Project 2
* Dev Enironment: Windows 7, Microsoft Visual Studio Express 2013 for Windows Desktop
*/
class Literal : public Operand
{
public:
    Literal(int value)
    {
        this->value = value;
    }
    double evaluate()
    {
        return value;
    }
private:
    int value;
};
