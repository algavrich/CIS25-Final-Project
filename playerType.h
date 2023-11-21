#ifndef H_playerType
#define H_playerType

#include <string>

class playerType
{
public:
    playerType(std::string = "");
    void trackTrait(std::string);
    void setName(std::string);
    char analyzeTraits() const;

private:
    std::string _name;
    std::string _tracker;
};

#endif