#include "gameType.h"
#include <iostream>
#include <string>

using namespace std;

gameType::gameType()
{
    _root = nullptr;
}

void gameType::play()
{
    // get player
    cout << "Welcome to The Medieval Choose Your Own Adventure Game!"
         << endl
         << endl;
    cout << "What is your name? > ";
    string playerName;
    cin >> playerName;
    _player.setName(playerName);
    // set up game context
    makeGame();
    // do gameplay
    nodeType *curr = _root;
    while (!curr->isLeaf())
    {
        _player.trackTrait(curr->getTrait());
        curr->print();
        cout << endl;
        if (ask() == 1)
        {
            curr = curr->_choice1;
        }
        else
        {
            curr = curr->_choice2;
        }
    }
    // traverse tree based on user input
    cout << "You are the " << _player.analyzeTraits() << endl;
}
void gameType::makeGame()
{
    _root = new nodeType("question 0", "");

    _root->setChoice(1, makeNode("question 1", "AB"));
    _root->setChoice(2, makeNode("question 2", "CD"));

    _root->_choice1->setChoice(1, makeNode("question 3", "AC"));
    _root->_choice1->setChoice(2, makeNode("question 4", "BD"));

    _root->_choice2->setChoice(1, makeNode("question 5", "AC"));
    _root->_choice2->setChoice(2, makeNode("question 6", "BD"));

    _root->_choice1->_choice1->setChoice(1, makeNode("question 7", "AD"));
    _root->_choice1->_choice1->setChoice(2, makeNode("question 8", "BC"));

    _root->_choice1->_choice2->setChoice(1, makeNode("question 9", "AD"));
    _root->_choice1->_choice2->setChoice(2, makeNode("question 10", "BC"));

    _root->_choice2->_choice1->setChoice(1, makeNode("question 11", "AD"));
    _root->_choice2->_choice1->setChoice(2, makeNode("question 12", "BC"));

    _root->_choice2->_choice2->setChoice(1, makeNode("question 13", "AD"));
    _root->_choice2->_choice2->setChoice(2, makeNode("question 14", "BC"));
}

nodeType *gameType::makeNode(string text, string trait)
{
    nodeType *temp = new nodeType(text, trait);
    return temp;
}

void gameType::setPlayerName(string name)
{
    _player.setName(name);
}

int gameType::ask()
{
    bool valid = false;
    int num;
    do
    {
        string input;
        cout << "Which do you choose? > ";
        cin >> input;
        try
        {
            num = stoi(input);
            if (num == 1 || num == 2)
            {
                valid = true;
            }
            else
            {
                cout << "Enter either 1 or 2" << endl;
            }
        }
        catch (invalid_argument)
        {
            cout << "Enter either 1 or 2" << endl;
        }
        // not the most efficient way to output this prompt?

    } while (!valid);

    return num;
}