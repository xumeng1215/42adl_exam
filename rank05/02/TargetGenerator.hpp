#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"

class TargetGenerator
{
private:
	std::vector<ATarget *> targets;

public:
	TargetGenerator();
	~TargetGenerator();
	void learnTargetType(ATarget *);
	void forgetTargetType(const std::string &);
	ATarget *createTarget(const std::string &);
};