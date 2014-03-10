/*
* Stephen Drollinger
* CMSC330
* Project 2
* Dev Enironment: Windows 7, Microsoft Visual Studio Express 2013 for Windows Desktop
*/
#include <cctype> 
#include <iostream> 
#include <string> 
#include <strstream>
using namespace std;

#include "parse.h"

string parseName(strstream& in)
{
    char alnum;
    string name = "";

    cin >> ws;
    while (isalnum(cin.peek()))
    {
        cin >> alnum;
        name += alnum;
    }
    return name;
}
