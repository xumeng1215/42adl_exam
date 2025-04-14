#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
private:
	std::string name;
	std::string title;
	// std::vector<ASpell *> spells;

	SpellBook book;

	Warlock();
	Warlock(const Warlock &);
	Warlock &operator=(const Warlock &);

public:
	Warlock(const std::string &, const std::string &);
	~Warlock();

	const std::string &getName() const;
	const std::string &getTitle() const;

	void setTitle(const std::string &);
	void introduce() const;

	void learnSpell(ASpell *);
	void forgetSpell(const std::string &);
	void launchSpell(const std::string &, const ATarget &);
};