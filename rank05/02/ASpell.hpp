#pragma once

#include <string>
#include <iostream>

class ATarget; // Forward declaration
class ASpell
{
protected:
	std::string name;
	std::string effects;

	ASpell();
	ASpell(ASpell &other);
	ASpell &operator=(const ASpell &other);

public:
	ASpell(const std::string &n, const std::string &e);
	virtual ~ASpell();

	const std::string &getName() const;
	const std::string &getEffects() const;

	virtual ASpell *clone() const = 0;

	void launch(const ATarget &target) const;
};