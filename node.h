// Node of decision tree

#ifndef PROJECT_NODE_H_
#define PROJECT_NODE_H_

#include <string>

class Node {
public:
    Node(std::string = "", char = ' ');
    ~Node(){};
    std::string GetText() const;
    char GetTrait() const;
    bool IsLeaf() const;
    void SetChoice(int, Node*);
    Node *GetChoice1() const;
    Node *GetChoice2() const;

private:
    std::string text_;
    char trait_;
    Node *choice1_;
    Node *choice2_;
};

#endif