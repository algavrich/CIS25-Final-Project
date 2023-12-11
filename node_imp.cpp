// Implementation file for Node class

#include "node.h"

#include <iostream>

using namespace std;

Node::Node(string text, char trait) {
    // Constructor
        // Initialize text_ and trait_ to values of arguments
        // Initialize choices to null pointers

    text_ = text;
    trait_ = trait;
    choice1_ = nullptr;
    choice2_ = nullptr;
}

string Node::GetText() const {
    return text_;
}

char Node::GetTrait() const {
    return trait_;
}

Node* Node::GetChoice1() const {
    return choice1_;
}

Node* Node::GetChoice2() const {
    return choice2_;
}

bool Node::IsLeaf() const {
    // Return true if a node is a leaf, and false otherwise
        // If a node is a leaf, it is and end piece of the story

    if (choice1_ == nullptr) {
        return true;
    }
    return false;
}

void Node::SetChoice(int pos, Node *choice) {
    // Depending on the value of pos, set either the first or second choice
    // attributes to the value of the Node pointer argument

    if (pos == 1) {
        choice1_ = choice;
    } else if (pos == 2) {
        choice2_ = choice;
    } else {
        cout << "invalid choice position";
    }
}