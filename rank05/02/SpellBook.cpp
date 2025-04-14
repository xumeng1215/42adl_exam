#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}
SpellBook::~SpellBook()
{
	for (std::vector<ASpell *>::iterator it = this->spells.begin(); it != this->spells.end(); ++it)
	{
		delete *it;
	}
	this->spells.clear();
}

void SpellBook::learnSpell(ASpell *spell)
{
	for (std::vector<ASpell *>::iterator it = this->spells.begin(); it != this->spells.end(); ++it)
	{
		if ((*it)->getName() == spell->getName())
			return;
	}
	this->spells.push_back(spell->clone());
}

void SpellBook::forgetSpell(const std::string &spellName)
{
	for (std::vector<ASpell *>::iterator it = this->spells.begin(); it != this->spells.end(); ++it)
	{
		if ((*it)->getName() == spellName)
		{
			delete *it;
			this->spells.erase(it);
			return;
		}
	}
}
ASpell *SpellBook::createSpell(const std::string &spellName)
{
	for (std::vector<ASpell *>::iterator it = this->spells.begin(); it != this->spells.end(); ++it)
	{
		if ((*it)->getName() == spellName)
			return (*it)->clone();
	}
	return nullptr;
}