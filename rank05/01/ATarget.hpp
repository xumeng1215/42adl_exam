#pragma once

#include <string>
#include "ASpell.hpp"

class ATarget
{
    protected:

    std::string type;

    public:

    ATarget(std::string & t);

    const std::string & getType() const ;

    virtual ATarget * clone() const = 0;

    void getHitBySpell(const ASpell & spell) const;

};