#include "playerType.h"
#include <iostream>
#include <string>

using namespace std;

playerType::playerType(string name)
{
    _name = name;
    _tracker = "";
}

void playerType::trackTrait(string trait)
{
    _tracker += trait;
}

void playerType::setName(string name)
{
    _name = name;
}

char playerType::analyzeTraits() const
{
    char traits[4] = {'A', 'B', 'C', 'D'};
    int counts[4] = {0};
    int i, j;
    for (i = 0; i < _tracker.length(); i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (_tracker[i] == traits[j])
            {
                counts[j]++;
                break;
            }
        }
    }

    int maxIdx = 0;
    for (j = 1; j < 4; j++)
    {
        if (counts[j] > counts[maxIdx])
        {
            maxIdx = j;
        }
    }

    return traits[maxIdx];
}