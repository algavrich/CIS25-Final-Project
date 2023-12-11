// Game structure

#ifndef PROJECT_GAME_H_
#define PROJECT_GAME_H_

#include <string>

#include "node.h"
#include "player.h"

class Game {
public:
    Game();
    ~Game();
    void Play();

private:
    Player player_;
    Node *root_;
    void MakeGame();
    Node *MakeNode(const std::string, const char);
    void DeleteNode(Node *);
    int Ask();
    std::string GetTraitName() const;
};

#endif