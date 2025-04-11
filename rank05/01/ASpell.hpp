#pragma once

#include <string>

class ASpell
{
    protected:

    std::string name;
    std::string effects;

    ASpell();
    ASpell(ASpell &other);
    ASpell & operator=(const ASpell &other);

    public:
    ASpell(std::string & n, std::string & e);
    virtual ~ASpell();


    const std::string &getName() const;
    const std::string &getEffects() const;

    virtual ASpell * clone() const = 0;



};