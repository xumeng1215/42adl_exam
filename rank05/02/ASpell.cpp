#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(const std::string &n, const std::string &e) : name(n), effects(e)
{
}

ASpell::~ASpell()
{
}

const std::string &ASpell::getName() const
{
	return this->name;
}

const std::string &ASpell::getEffects() const
{
	return this->effects;
}

void ASpell::launch(const ATarget &target) const
{
	target.getHitBySpell(*this);
}