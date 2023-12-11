// Player of the game

#ifndef PROJECT_PLAYER_H_
#define PROJECT_PLAYER_H_

#include <string>

class Player {
public:
    Player(std::string = "");
    ~Player(){};
    void SetName(std::string);
    std::string GetName() const;
    void RemoveTrait(char);
    char GetFinalTrait() const;

private:
    std::string name_;
    std::string tracker_;
};

#endif