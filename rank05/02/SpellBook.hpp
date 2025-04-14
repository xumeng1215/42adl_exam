#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "ASpell.hpp"
#include "ATarget.hpp"

class SpellBook
{
private:
	std::vector<ASpell *> spells;

public:
	SpellBook();
	~SpellBook();

	void learnSpell(ASpell *);
	void forgetSpell(const std::string &);
	ASpell *createSpell(const std::string &);
};