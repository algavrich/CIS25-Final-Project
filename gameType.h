#ifndef H_gameType
#define H_gameType

#include "playerType.h"
#include "nodeType.h"
#include <string>

class gameType
{
public:
    gameType();
    void play();
    void makeGame();
    void setPlayerName(std::string);
    nodeType *makeNode(const std::string, const std::string);
    int ask();

private:
    playerType _player;
    nodeType *_root;
};

#endif