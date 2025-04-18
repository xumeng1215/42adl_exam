#include "Warlock.hpp"

Warlock::Warlock(const std::string &n, const std::string &t) : name(n), title(t)
{
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName() const
{
	return this->name;
}
const std::string &Warlock::getTitle() const
{
	return this->title;
}
void Warlock::setTitle(const std::string &t)
{
	this->title = t;
}

void Warlock::introduce() const
{
	std::cout << this->name << ": I am " << this->name << ", "
			  << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
	for (std::vector<ASpell *>::iterator it = this->spells.begin(); it != this->spells.end(); ++it)
	{
		if ((*it)->getName() == spell->getName())
			return;
	}
	this->spells.push_back(spell->clone());
}

void Warlock::forgetSpell(const std::string &spellName)
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

void Warlock::launchSpell(const std::string &spellName, const ATarget &target)
{
	for (std::vector<ASpell *>::iterator it = this->spells.begin(); it != this->spells.end(); ++it)
	{
		if ((*it)->getName() == spellName)
		{
			(*it)->launch(target);
			return;
		}
	}
	std::cout << this->name << ": I don't know " << spellName << "!" << std::endl;
}