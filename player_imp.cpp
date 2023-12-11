// Implementation file for Player type

#include "player.h"

#include <iostream>
#include <string>

using namespace std;

Player::Player(string name) {
    // Constructor
        // Initialize name to value of argument and tracker to "ABCD"

    name_ = name;
    tracker_ = "ABCD";
}

void Player::SetName(string name) {

    name_ = name;
}

string Player::GetName() const {

    return name_;
}

void Player::RemoveTrait(char trait) {
    // Remove a trait
        // Utilize 'erase' and 'find' string methods to locate and erase a
        //trait character from tracker_

    tracker_.erase(tracker_.find(trait), 1);
}

char Player::GetFinalTrait() const {
    // Return the remaining trait character in tracker_

    return static_cast<char>(tracker_[0]);
}