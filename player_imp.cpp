#include "player.h"

#include <iostream>
#include <string>

using namespace std;

Player::Player(string name) {
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
  tracker_.erase(tracker_.find(trait), 1);
}

char Player::GetFinalTrait() const {
  return static_cast<char>(tracker_[0]);
}