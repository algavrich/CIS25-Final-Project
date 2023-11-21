#include "nodeType.h"
#include <iostream>

using namespace std;

nodeType::nodeType(string text, string trait)
{
    _text = text;
    _trait = trait;
    _choice1 = nullptr;
    _choice2 = nullptr;
}

void nodeType::print() const
{
    cout << _text;
}

string nodeType::getTrait() const
{
    return _trait;
}

bool nodeType::isLeaf() const
{
    if (_choice1 == nullptr)
    {
        return true;
    }
    return false;
}

void nodeType::setText(string text)
{

    _text = text;
}

void nodeType::setChoice(int pos, nodeType *choice)
{
    if (pos == 1)
    {
        _choice1 = choice;
    }
    else if (pos == 2)
    {
        _choice2 = choice;
    }
    else
    {
        cout << "invalid child position";
    }
}