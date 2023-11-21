#ifndef H_nodeType
#define H_nodeType

#include <string>

class nodeType
{
public:
    nodeType *_choice1;
    nodeType *_choice2;
    // better solution that making these public?
    // method to return address?
    nodeType(std::string = "", std::string = "");
    void print() const;
    std::string getTrait() const;
    bool isLeaf() const;
    void setText(std::string);
    void setChoice(int, nodeType *);

private:
    std::string _text;
    std::string _trait;
};

#endif